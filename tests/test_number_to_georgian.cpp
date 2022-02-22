/**************************************************************************
Copyright: (C) 2022 Alexander Shaduri
License: Zlib
***************************************************************************/

#include "number_to_georgian.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include <vector>


using namespace std::string_literals;



TEST_CASE("NumberToGeorgian", "")
{
	using VS = std::vector<std::string>;

	REQUIRE(NumberToGeorgian::toSymbolic(0L) == VS{"0"s});
	REQUIRE(NumberToGeorgian::toWords(0L) == "ნული"s);

	REQUIRE(NumberToGeorgian::toSymbolic(-6'872'146L)
			== VS{"minus"s, "6"s, "1e6_"s, "800_"s, "60_"s, "12"s, "1000_"s, "100_"s, "40_"s, "6"s});
	REQUIRE(NumberToGeorgian::toWords(-6'872'146L)
			== "მინუს ექვსი მილიონ რვაას სამოცდათორმეტი ათას ას ორმოცდაექვსი"s);

}



/// @}
