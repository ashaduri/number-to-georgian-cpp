/**************************************************************************
Copyright: (C) 2022 Alexander Shaduri
License: Zlib
***************************************************************************/

#ifndef NUMBER_TO_GEORGIAN_H
#define NUMBER_TO_GEORGIAN_H

#include <vector>
#include <string>
#include <string_view>
#include <map>
#include <cstdint>
#include <stdexcept>



/**
 * Translate a numeric number to Georgian language.
 */
class NumberToGeorgian {
	public:

		/**
		 * Convert a number to a Georgian string.
		 */
		static inline std::string toWords(std::int64_t number);


		/**
		 * Convert a number to a vector of elements, where each element is a symbolic ASCII
		 * representation of a word in Georgian. This function is useful for creating a library of sound
		 * files (e.g. "0.wav", "minus.wav", ...) to be used in interactive voice applications, etc...
		 *
		 * Each element is a string, one of:
		 * - 0 (ნული).
		 * - minus (მინუს).
		 * - 1, 2, 3, 4, 5, 6, 7, 8, 9 (ერთი, ორი, სამი, ოთხი, ხუთი, ექვსი, შვიდი, რვა, ცხრა).
		 * - 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 (ათი, თერთმეტი, თორმეტი, ცამეტი, თოთხმეტი,
		 * თხუთმეტი, თექვსმეტი, ჩვიდმეტი, თვრამეტი, ცხრამეტი).
		 * - 20, 40, 60, 80 (ოცი, ორმოცი, სამოცი, ოთხმოცი).
		 * - 20_, 40_, 60_, 80_ (ოცდა, ორმოცდა, სამოცდა, ოთხმოცდა).
		 * - 100, 200, 300, 400, 500, 600, 700, 800, 900 (ასი, ორასი, სამასი, ოთხასი,
		 * ხუთასი, ექვსასი, შვიდასი, რვაასი, ცხრაასი).
		 * - 100_, 200_, 300_, 400_, 500_, 600_, 700_, 800_, 900_ (ას, ორას, სამას,
		 * ოთხას, ხუთას, ექვსას, შვიდას, რვაას, ცხრაას).
		 * - 1000, 1000_ (ათასი, ათას).
		 * - 1e6, 1e6_ (მილიონი, მილიონ).
		 * - 1e9, 1e9_ (მილიარდი, მილიარდ).
		 * - 1e12, 1e12_ (ტრილიონი, ტრილიონ).
		 */
		static inline std::vector<std::string> toSymbolic(std::int64_t number);


	private:


		/**
		 * Same as toSymbols(), but with empty elements inserted for space characters, where needed.
		 */
		static inline std::vector<std::string> toSymbolicWithSpaces(std::int64_t number, bool add_spaces);


		/**
		 * A helper for toSymbolicWithSpaces(), high numbers.
		 */
		static inline std::vector<std::string> toSymbolicWithSpacesHelperHighNumbers(std::int64_t number, bool add_spaces,
				std::int64_t divisor, std::string&& symbolic, std::string&& symbolic_ext);


		/**
		 * Move to_append vector to the end of result.
		 * \return result
		 */
		static inline std::vector<std::string>& appendToResult(std::vector<std::string>& result, std::vector<std::string>&& to_append);
		
		
		/**
		 * Return a word corresponding to its symbolic representation.
		 */
		static inline std::string_view symbolicToWord(std::string_view symbolic);


};






// ----- Implementation


std::string NumberToGeorgian::toWords(std::int64_t number)
{
	std::string result;
	for (auto&& symbolic : toSymbolicWithSpaces(number, true)) {
		result.append(symbolicToWord(symbolic));
	}
	return result;
}



std::vector<std::string> NumberToGeorgian::toSymbolic(std::int64_t number)
{
	return toSymbolicWithSpaces(number, false);
}



std::vector<std::string> NumberToGeorgian::toSymbolicWithSpaces(  // NOLINT(misc-no-recursion)
		std::int64_t number, bool add_spaces)
{
	using namespace std::string_literals;
	std::vector<std::string> result;

	if (number < 0) {
		result = {"minus"s};
		if (add_spaces) {
			result.emplace_back();
		}
		return appendToResult(result, toSymbolicWithSpaces(-number, add_spaces));
	}

	// Directly representable
	if (number <= 20 || number == 40 || number == 60 || number == 80 || number == 100) {
		return {std::to_string(number)};
	}

	// ოცდა[...]
	if (number < 40) {
		result = {"20_"s};
		return appendToResult(result, toSymbolicWithSpaces(number - 20, add_spaces));
	}

	// ორმოცდა[...]
	if (number < 60) {
		result = {"40_"s};
		return appendToResult(result, toSymbolicWithSpaces(number - 40, add_spaces));
	}

	// სამოცდა[...]
	if (number < 80) {
		result = {"60_"s};
		return appendToResult(result, toSymbolicWithSpaces(number - 60, add_spaces));
	}

	// ოთხმოცდა[...]
	if (number < 100) {
		result = {"80_"s};
		return appendToResult(result, toSymbolicWithSpaces(number - 80, add_spaces));
	}


	if (number < 1000) {
		auto first_digit = number / 100;
		auto remainder = number % 100;

		// ასი, ორასი, სამასი, ..., ცხრაასი.
		if (remainder == 0) {
			result.emplace_back(std::to_string(number));
			return result;
		}

		// ას [...], ორას [...], ..., ცხრაას [...] .
		result = {std::to_string(first_digit * 100) + "_"s};
		if (add_spaces) {
			result.emplace_back();
		}

		return appendToResult(result, toSymbolicWithSpaces(remainder, add_spaces));
	}


	// ათასი (not "ერთი ათასი").
	if (number == 1000) {
		return {"1000"s};
	}


	if (number < 1'000'000) {
		auto first_digits = number / 1000;
		auto remainder = number % 1000;

		// [...] ათასი.
		if (remainder == 0) {
			result = toSymbolicWithSpaces(first_digits, add_spaces);
			if (add_spaces) {
				result.emplace_back();
			}
			result.emplace_back("1000"s);
			return result;
		}

		// [...] ათას [...].
		// Also, don't do "ერთი ათას ...".
		if (first_digits != 1) {
			result = toSymbolicWithSpaces(first_digits, add_spaces);
			if (add_spaces) {
				result.emplace_back();
			}
		}
		result.emplace_back("1000_"s);
		if (add_spaces) {
			result.emplace_back();
		}
		return appendToResult(result, toSymbolicWithSpaces(remainder, add_spaces));
	}


	// ერთი მილიონი
	if (number == 1'000'000) {
		result = {"1"s};
		if (add_spaces) {
			result.emplace_back();
		}
		result.emplace_back("1e6"s);
		return result;
	}


	if (number < 1'000'000'000) {
		return toSymbolicWithSpacesHelperHighNumbers(number, add_spaces,
				1'000'000, "1e6"s, "1e6_"s);
	}


	// ერთი მილიარდი.
	if (number == 1'000'000'000) {
		result = {"1"s};
		if (add_spaces) {
			result.emplace_back();
		}
		result.emplace_back("1e9"s);
		return result;
	}


	if (number < 1'000'000'000'000) {
		return toSymbolicWithSpacesHelperHighNumbers(number, add_spaces,
				1'000'000'000, "1e9"s, "1e9_"s);
	}


	// ერთი ტრილიონი.
	if (number == 1'000'000'000'000) {
		result = {"1"s};
		if (add_spaces) {
			result.emplace_back();
		}
		result.emplace_back("1e12"s);
		return result;
	}


	if (number < 1'000'000'000'000'000) {
		return toSymbolicWithSpacesHelperHighNumbers(number, add_spaces,
				1'000'000'000'000, "1e12"s, "1e12_"s);
	}


	// ერთი კვადრილიონი.
	if (number == 1'000'000'000'000'000) {
		result = {"1"s};
		if (add_spaces) {
			result.emplace_back();
		}
		result.emplace_back("1e15"s);
		return result;
	}


	if (number < 1'000'000'000'000'000'000) {
		return toSymbolicWithSpacesHelperHighNumbers(number, add_spaces,
				1'000'000'000'000'000, "1e15"s, "1e15_"s);
	}


	// ერთი კვინტილიონი.
	if (number == 1'000'000'000'000'000'000) {
		result = {"1"s};
		if (add_spaces) {
			result.emplace_back();
		}
		result.emplace_back("1e18"s);
		return result;
	}


	// The limit is ~9 quintillion.
	return toSymbolicWithSpacesHelperHighNumbers(number, add_spaces,
				1'000'000'000'000'000'000, "1e15"s, "1e15_"s);
}



std::vector<std::string> NumberToGeorgian::toSymbolicWithSpacesHelperHighNumbers(std::int64_t number, bool add_spaces,
		std::int64_t divisor, std::string&& symbolic, std::string&& symbolic_ext)
{
	using namespace std::string_literals;

	std::vector<std::string> result;

	auto first_digits = number / divisor;
	auto remainder = number % divisor;

	// [...] მილიონი (მილიარდი, ტრილიონი, ...).
	if (remainder == 0) {
		result = toSymbolicWithSpaces(first_digits, add_spaces);
		if (add_spaces) {
			result.emplace_back();
		}
		result.emplace_back(std::move(symbolic));
		return result;
	}

	// [...] მილიონ (მილიარდ, ტრილიონ, ...) [...].
	result = toSymbolicWithSpaces(first_digits, add_spaces);
	if (add_spaces) {
		result.emplace_back();
	}
	result.emplace_back(std::move(symbolic_ext));
	if (add_spaces) {
		result.emplace_back();
	}

	return appendToResult(result, toSymbolicWithSpaces(remainder, add_spaces));
}



std::vector<std::string>& NumberToGeorgian::appendToResult(std::vector<std::string>& result, std::vector<std::string>&& to_append)
{
	result.insert(result.end(), std::make_move_iterator(to_append.begin()), std::make_move_iterator(to_append.end()));
	return result;
}



std::string_view NumberToGeorgian::symbolicToWord(std::string_view symbolic)
{
	using namespace std::string_view_literals;
	using namespace std::string_literals;

	static const std::map<std::string_view, std::string_view> symbols_to_words = {
		{""sv, " "sv},
		
		{"minus"sv, "მინუს"sv},
		{"0"sv, "ნული"sv},
		{"1"sv, "ერთი"sv},
		{"2"sv, "ორი"sv},
		{"3"sv, "სამი"sv},
		{"4"sv, "ოთხი"sv},
		{"5"sv, "ხუთი"sv},
		{"6"sv, "ექვსი"sv},
		{"7"sv, "შვიდი"sv},
		{"8"sv, "რვა"sv},
		{"9"sv, "ცხრა"sv},
		{"10"sv, "ათი"sv},
		{"11"sv, "თერთმეტი"sv},
		{"12"sv, "თორმეტი"sv},
		{"13"sv, "ცამეტი"sv},
		{"14"sv, "თოთხმეტი"sv},
		{"15"sv, "თხუთმეტი"sv},
		{"16"sv, "თექვსმეტი"sv},
		{"17"sv, "ჩვიდმეტი"sv},
		{"18"sv, "თვრამეტი"sv},
		{"19"sv, "ცხრამეტი"sv},
		{"20"sv, "ოცი"sv},
		{"20_"sv, "ოცდა"sv},
		{"40"sv, "ორმოცი"sv},
		{"40_"sv, "ორმოცდა"sv},
		{"60"sv, "სამოცი"sv},
		{"60_"sv, "სამოცდა"sv},
		{"80"sv, "ოთხმოცი"sv},
		{"80_"sv, "ოთხმოცდა"sv},
		{"100"sv, "ასი"sv},
		{"100_"sv, "ას"sv},
		{"200"sv, "ორასი"sv},
		{"200_"sv, "ორას"sv},
		{"300"sv, "სამასი"sv},
		{"300_"sv, "სამას"sv},
		{"400"sv, "ოთხასი"sv},
		{"400_"sv, "ოთხას"sv},
		{"500"sv, "ხუთასი"sv},
		{"500_"sv, "ხუთას"sv},
		{"600"sv, "ექვსასი"sv},
		{"600_"sv, "ექვსას"sv},
		{"700"sv, "შვიდასი"sv},
		{"700_"sv, "შვიდას"sv},
		{"800"sv, "რვაასი"sv},
		{"800_"sv, "რვაას"sv},
		{"900"sv, "ცხრაასი"sv},
		{"900_"sv, "ცხრაას"sv},
		{"1000"sv, "ათასი"sv},
		{"1000_"sv, "ათას"sv},
		{"1e6"sv, "მილიონი"sv},
		{"1e6_"sv, "მილიონ"sv},
		{"1e9"sv, "მილიარდი"sv},
		{"1e9_"sv, "მილიარდ"sv},

		// The higher numbers may be implemented in short-scale or long-scale styles.
		// We use the short scale, as it is common in Georgia.
		{"1e12"sv, "ტრილიონი"sv},
		{"1e12_"sv, "ტრილიონ"sv},
		{"1e15"sv, "კვადრილიონი"sv},
		{"1e15_"sv, "კვადრილიონ"sv},
		{"1e18"sv, "კვინტილიონი"sv},
		{"1e18_"sv, "კვინტილიონ"sv},
	};

	auto iter = symbols_to_words.find(symbolic);
	if (iter == symbols_to_words.end()) {
		throw std::runtime_error("Internal error: No corresponding Georgian word found for a symbolic representation of a piece of a number \""s
				+ std::string(symbolic) + "\".");
	}

	return iter->second;
}






#endif
