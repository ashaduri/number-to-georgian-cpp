/**************************************************************************
Copyright: (C) 2022 Alexander Shaduri
License: Zlib
***************************************************************************/

#include "number_to_georgian.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include <vector>



TEST_CASE("NumberToGeorgian", "")
{
	using VS = std::vector<std::string>;

	REQUIRE(NumberToGeorgian::toSymbolic(0) == VS{"0"});
	REQUIRE(NumberToGeorgian::toWords(0) == "ნული");

	REQUIRE(NumberToGeorgian::toSymbolic(-1) == VS{"minus", "1"});
	REQUIRE(NumberToGeorgian::toWords(-1) == "მინუს ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(1) == VS{"1"});
	REQUIRE(NumberToGeorgian::toWords(1) == "ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(2) == VS{"2"});
	REQUIRE(NumberToGeorgian::toWords(2) == "ორი");

	REQUIRE(NumberToGeorgian::toSymbolic(3) == VS{"3"});
	REQUIRE(NumberToGeorgian::toWords(3) == "სამი");

	REQUIRE(NumberToGeorgian::toSymbolic(4) == VS{"4"});
	REQUIRE(NumberToGeorgian::toWords(4) == "ოთხი");

	REQUIRE(NumberToGeorgian::toSymbolic(5) == VS{"5"});
	REQUIRE(NumberToGeorgian::toWords(5) == "ხუთი");

	REQUIRE(NumberToGeorgian::toSymbolic(6) == VS{"6"});
	REQUIRE(NumberToGeorgian::toWords(6) == "ექვსი");

	REQUIRE(NumberToGeorgian::toSymbolic(7) == VS{"7"});
	REQUIRE(NumberToGeorgian::toWords(7) == "შვიდი");

	REQUIRE(NumberToGeorgian::toSymbolic(8) == VS{"8"});
	REQUIRE(NumberToGeorgian::toWords(8) == "რვა");

	REQUIRE(NumberToGeorgian::toSymbolic(9) == VS{"9"});
	REQUIRE(NumberToGeorgian::toWords(9) == "ცხრა");

	REQUIRE(NumberToGeorgian::toSymbolic(10) == VS{"10"});
	REQUIRE(NumberToGeorgian::toWords(10) == "ათი");

	REQUIRE(NumberToGeorgian::toSymbolic(11) == VS{"11"});
	REQUIRE(NumberToGeorgian::toWords(11) == "თერთმეტი");

	REQUIRE(NumberToGeorgian::toSymbolic(12) == VS{"12"});
	REQUIRE(NumberToGeorgian::toWords(12) == "თორმეტი");

	REQUIRE(NumberToGeorgian::toSymbolic(13) == VS{"13"});
	REQUIRE(NumberToGeorgian::toWords(13) == "ცამეტი");

	REQUIRE(NumberToGeorgian::toSymbolic(14) == VS{"14"});
	REQUIRE(NumberToGeorgian::toWords(14) == "თოთხმეტი");

	REQUIRE(NumberToGeorgian::toSymbolic(15) == VS{"15"});
	REQUIRE(NumberToGeorgian::toWords(15) == "თხუთმეტი");

	REQUIRE(NumberToGeorgian::toSymbolic(16) == VS{"16"});
	REQUIRE(NumberToGeorgian::toWords(16) == "თექვსმეტი");

	REQUIRE(NumberToGeorgian::toSymbolic(17) == VS{"17"});
	REQUIRE(NumberToGeorgian::toWords(17) == "ჩვიდმეტი");

	REQUIRE(NumberToGeorgian::toSymbolic(18) == VS{"18"});
	REQUIRE(NumberToGeorgian::toWords(18) == "თვრამეტი");

	REQUIRE(NumberToGeorgian::toSymbolic(19) == VS{"19"});
	REQUIRE(NumberToGeorgian::toWords(19) == "ცხრამეტი");


	REQUIRE(NumberToGeorgian::toSymbolic(20) == VS{"20"});
	REQUIRE(NumberToGeorgian::toWords(20) == "ოცი");

	REQUIRE(NumberToGeorgian::toSymbolic(21) == VS{"20_", "1"});
	REQUIRE(NumberToGeorgian::toWords(21) == "ოცდაერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(22) == VS{"20_", "2"});
	REQUIRE(NumberToGeorgian::toWords(22) == "ოცდაორი");

	REQUIRE(NumberToGeorgian::toSymbolic(30) == VS{"20_", "10"});
	REQUIRE(NumberToGeorgian::toWords(30) == "ოცდაათი");

	REQUIRE(NumberToGeorgian::toSymbolic(39) == VS{"20_", "19"});
	REQUIRE(NumberToGeorgian::toWords(39) == "ოცდაცხრამეტი");


	REQUIRE(NumberToGeorgian::toSymbolic(40) == VS{"40"});
	REQUIRE(NumberToGeorgian::toWords(40) == "ორმოცი");

	REQUIRE(NumberToGeorgian::toSymbolic(43) == VS{"40_", "3"});
	REQUIRE(NumberToGeorgian::toWords(43) == "ორმოცდასამი");

	REQUIRE(NumberToGeorgian::toSymbolic(44) == VS{"40_", "4"});
	REQUIRE(NumberToGeorgian::toWords(44) == "ორმოცდაოთხი");

	REQUIRE(NumberToGeorgian::toSymbolic(50) == VS{"40_", "10"});
	REQUIRE(NumberToGeorgian::toWords(50) == "ორმოცდაათი");

	REQUIRE(NumberToGeorgian::toSymbolic(59) == VS{"40_", "19"});
	REQUIRE(NumberToGeorgian::toWords(59) == "ორმოცდაცხრამეტი");


	REQUIRE(NumberToGeorgian::toSymbolic(60) == VS{"60"});
	REQUIRE(NumberToGeorgian::toWords(60) == "სამოცი");

	REQUIRE(NumberToGeorgian::toSymbolic(65) == VS{"60_", "5"});
	REQUIRE(NumberToGeorgian::toWords(65) == "სამოცდახუთი");

	REQUIRE(NumberToGeorgian::toSymbolic(66) == VS{"60_", "6"});
	REQUIRE(NumberToGeorgian::toWords(66) == "სამოცდაექვსი");

	REQUIRE(NumberToGeorgian::toSymbolic(70) == VS{"60_", "10"});
	REQUIRE(NumberToGeorgian::toWords(70) == "სამოცდაათი");

	REQUIRE(NumberToGeorgian::toSymbolic(79) == VS{"60_", "19"});
	REQUIRE(NumberToGeorgian::toWords(79) == "სამოცდაცხრამეტი");


	REQUIRE(NumberToGeorgian::toSymbolic(80) == VS{"80"});
	REQUIRE(NumberToGeorgian::toWords(80) == "ოთხმოცი");

	REQUIRE(NumberToGeorgian::toSymbolic(87) == VS{"80_", "7"});
	REQUIRE(NumberToGeorgian::toWords(87) == "ოთხმოცდაშვიდი");

	REQUIRE(NumberToGeorgian::toSymbolic(88) == VS{"80_", "8"});
	REQUIRE(NumberToGeorgian::toWords(88) == "ოთხმოცდარვა");

	REQUIRE(NumberToGeorgian::toSymbolic(90) == VS{"80_", "10"});
	REQUIRE(NumberToGeorgian::toWords(90) == "ოთხმოცდაათი");

	REQUIRE(NumberToGeorgian::toSymbolic(99) == VS{"80_", "19"});
	REQUIRE(NumberToGeorgian::toWords(99) == "ოთხმოცდაცხრამეტი");


	REQUIRE(NumberToGeorgian::toSymbolic(100) == VS{"100"});
	REQUIRE(NumberToGeorgian::toWords(100) == "ასი");

	REQUIRE(NumberToGeorgian::toSymbolic(101) == VS{"100_", "1"});
	REQUIRE(NumberToGeorgian::toWords(101) == "ას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(131) == VS{"100_", "20_", "11"});
	REQUIRE(NumberToGeorgian::toWords(131) == "ას ოცდათერთმეტი");


	REQUIRE(NumberToGeorgian::toSymbolic(200) == VS{"200"});
	REQUIRE(NumberToGeorgian::toWords(200) == "ორასი");

	REQUIRE(NumberToGeorgian::toSymbolic(201) == VS{"200_", "1"});
	REQUIRE(NumberToGeorgian::toWords(201) == "ორას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(242) == VS{"200_", "40_", "2"});
	REQUIRE(NumberToGeorgian::toWords(242) == "ორას ორმოცდაორი");


	REQUIRE(NumberToGeorgian::toSymbolic(300) == VS{"300"});
	REQUIRE(NumberToGeorgian::toWords(300) == "სამასი");

	REQUIRE(NumberToGeorgian::toSymbolic(301) == VS{"300_", "1"});
	REQUIRE(NumberToGeorgian::toWords(301) == "სამას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(400) == VS{"400"});
	REQUIRE(NumberToGeorgian::toWords(400) == "ოთხასი");

	REQUIRE(NumberToGeorgian::toSymbolic(401) == VS{"400_", "1"});
	REQUIRE(NumberToGeorgian::toWords(401) == "ოთხას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(500) == VS{"500"});
	REQUIRE(NumberToGeorgian::toWords(500) == "ხუთასი");

	REQUIRE(NumberToGeorgian::toSymbolic(501) == VS{"500_", "1"});
	REQUIRE(NumberToGeorgian::toWords(501) == "ხუთას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(600) == VS{"600"});
	REQUIRE(NumberToGeorgian::toWords(600) == "ექვსასი");

	REQUIRE(NumberToGeorgian::toSymbolic(601) == VS{"600_", "1"});
	REQUIRE(NumberToGeorgian::toWords(601) == "ექვსას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(700) == VS{"700"});
	REQUIRE(NumberToGeorgian::toWords(700) == "შვიდასი");

	REQUIRE(NumberToGeorgian::toSymbolic(701) == VS{"700_", "1"});
	REQUIRE(NumberToGeorgian::toWords(701) == "შვიდას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(800) == VS{"800"});
	REQUIRE(NumberToGeorgian::toWords(800) == "რვაასი");

	REQUIRE(NumberToGeorgian::toSymbolic(801) == VS{"800_", "1"});
	REQUIRE(NumberToGeorgian::toWords(801) == "რვაას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(900) == VS{"900"});
	REQUIRE(NumberToGeorgian::toWords(900) == "ცხრაასი");

	REQUIRE(NumberToGeorgian::toSymbolic(901) == VS{"900_", "1"});
	REQUIRE(NumberToGeorgian::toWords(901) == "ცხრაას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(999) == VS{"900_", "80_", "19"});
	REQUIRE(NumberToGeorgian::toWords(999) == "ცხრაას ოთხმოცდაცხრამეტი");


	REQUIRE(NumberToGeorgian::toSymbolic(1000) == VS{"1000"});
	REQUIRE(NumberToGeorgian::toWords(1000) == "ათასი");

	REQUIRE(NumberToGeorgian::toSymbolic(2000) == VS{"2", "1000"});
	REQUIRE(NumberToGeorgian::toWords(2000) == "ორი ათასი");

	REQUIRE(NumberToGeorgian::toSymbolic(9000) == VS{"9", "1000"});
	REQUIRE(NumberToGeorgian::toWords(9000) == "ცხრა ათასი");

	REQUIRE(NumberToGeorgian::toSymbolic(10'000) == VS{"10", "1000"});
	REQUIRE(NumberToGeorgian::toWords(10'000) == "ათი ათასი");

	REQUIRE(NumberToGeorgian::toSymbolic(100'000) == VS{"100", "1000"});
	REQUIRE(NumberToGeorgian::toWords(100'000) == "ასი ათასი");

	REQUIRE(NumberToGeorgian::toSymbolic(201'000) == VS{"200_", "1", "1000"});
	REQUIRE(NumberToGeorgian::toWords(201'000) == "ორას ერთი ათასი");

	REQUIRE(NumberToGeorgian::toSymbolic(999'000) == VS{"900_", "80_", "19", "1000"});
	REQUIRE(NumberToGeorgian::toWords(999'000) == "ცხრაას ოთხმოცდაცხრამეტი ათასი");


	REQUIRE(NumberToGeorgian::toSymbolic(1001) == VS{"1000_", "1"});
	REQUIRE(NumberToGeorgian::toWords(1001) == "ათას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(2002) == VS{"2", "1000_", "2"});
	REQUIRE(NumberToGeorgian::toWords(2002) == "ორი ათას ორი");

	REQUIRE(NumberToGeorgian::toSymbolic(9999) == VS{"9", "1000_", "900_", "80_", "19"});
	REQUIRE(NumberToGeorgian::toWords(9999) == "ცხრა ათას ცხრაას ოთხმოცდაცხრამეტი");

	REQUIRE(NumberToGeorgian::toSymbolic(10'001) == VS{"10", "1000_", "1"});
	REQUIRE(NumberToGeorgian::toWords(10'001) == "ათი ათას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(100'100) == VS{"100", "1000_", "100"});
	REQUIRE(NumberToGeorgian::toWords(100'100) == "ასი ათას ასი");

	REQUIRE(NumberToGeorgian::toSymbolic(201'020) == VS{"200_", "1", "1000_", "20"});
	REQUIRE(NumberToGeorgian::toWords(201'020) == "ორას ერთი ათას ოცი");

	REQUIRE(NumberToGeorgian::toSymbolic(999'999) == VS{"900_", "80_", "19", "1000_", "900_", "80_", "19"});
	REQUIRE(NumberToGeorgian::toWords(999'999) == "ცხრაას ოთხმოცდაცხრამეტი ათას ცხრაას ოთხმოცდაცხრამეტი");


	REQUIRE(NumberToGeorgian::toSymbolic(1'000'000) == VS{"1", "1e6"});
	REQUIRE(NumberToGeorgian::toWords(1'000'000) == "ერთი მილიონი");

	REQUIRE(NumberToGeorgian::toSymbolic(2'000'000) == VS{"2", "1e6"});
	REQUIRE(NumberToGeorgian::toWords(2'000'000) == "ორი მილიონი");

	REQUIRE(NumberToGeorgian::toSymbolic(100'000'000) == VS{"100", "1e6"});
	REQUIRE(NumberToGeorgian::toWords(100'000'000) == "ასი მილიონი");

	REQUIRE(NumberToGeorgian::toSymbolic(990'000'000) == VS{"900_", "80_", "10", "1e6"});
	REQUIRE(NumberToGeorgian::toWords(990'000'000) == "ცხრაას ოთხმოცდაათი მილიონი");


	REQUIRE(NumberToGeorgian::toSymbolic(1'000'001) == VS{"1", "1e6_", "1"});
	REQUIRE(NumberToGeorgian::toWords(1'000'001) == "ერთი მილიონ ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(1'001'000) == VS{"1", "1e6_", "1000"});
	REQUIRE(NumberToGeorgian::toWords(1'001'000) == "ერთი მილიონ ათასი");

	REQUIRE(NumberToGeorgian::toSymbolic(2'002'002) == VS{"2", "1e6_", "2", "1000_", "2"});
	REQUIRE(NumberToGeorgian::toWords(2'002'002) == "ორი მილიონ ორი ათას ორი");

	REQUIRE(NumberToGeorgian::toSymbolic(301'301'301) == VS{"300_", "1", "1e6_", "300_", "1", "1000_", "300_", "1"});
	REQUIRE(NumberToGeorgian::toWords(301'301'301) == "სამას ერთი მილიონ სამას ერთი ათას სამას ერთი");

	REQUIRE(NumberToGeorgian::toSymbolic(999'999'999) == VS{"900_", "80_", "19", "1e6_", "900_", "80_", "19", "1000_", "900_", "80_", "19", });
	REQUIRE(NumberToGeorgian::toWords(999'999'999) == "ცხრაას ოთხმოცდაცხრამეტი მილიონ ცხრაას ოთხმოცდაცხრამეტი ათას ცხრაას ოთხმოცდაცხრამეტი");


	REQUIRE(NumberToGeorgian::toSymbolic(1'000'000'000L) == VS{"1", "1e9"});
	REQUIRE(NumberToGeorgian::toWords(1'000'000'000L) == "ერთი მილიარდი");

	REQUIRE(NumberToGeorgian::toSymbolic(1'000'000'000'000L) == VS{"1", "1e12"});
	REQUIRE(NumberToGeorgian::toWords(1'000'000'000'000L) == "ერთი ტრილიონი");

	REQUIRE(NumberToGeorgian::toSymbolic(1'000'000'000'000'000L) == VS{"1", "1e15"});
	REQUIRE(NumberToGeorgian::toWords(1'000'000'000'000'000L) == "ერთი კვადრილიონი");

	REQUIRE(NumberToGeorgian::toSymbolic(1'000'000'000'000'000'000L) == VS{"1", "1e18"});
	REQUIRE(NumberToGeorgian::toWords(1'000'000'000'000'000'000L) == "ერთი კვინტილიონი");


	// int64 max
	std::numeric_limits<int64_t>::max();
	REQUIRE(NumberToGeorgian::toSymbolic(9'223'372'036'854'775'807)
			== VS{"9", "1e18_", "200_", "20_", "3", "1e15_", "300_", "60_", "12", "1e12_", "20_", "16", "1e9_", "800_", "40_", "14", "1e6_", "700_", "60_", "15", "1000_", "800_", "7"});
	REQUIRE(NumberToGeorgian::toWords(9'223'372'036'854'775'807)
			== "ცხრა კვინტილიონ ორას ოცდასამი კვადრილიონ სამას სამოცდათორმეტი ტრილიონ ოცდათექვსმეტი მილიარდ რვაას ორმოცდათოთხმეტი მილიონ შვიდას სამოცდათხუთმეტი ათას რვაას შვიდი");

	// int64 min. For some reason, the compiler refuses to accept an integral constant "-9'223'372'036'854'775'808".
	// REQUIRE(NumberToGeorgian::toSymbolic(-9'223'372'036'854'775'807 - 1)
	// 		== VS{"minus", "9", "1e18_", "200_", "20_", "3", "1e15_", "300_", "60_", "12", "1e12_", "20_", "16", "1e9_", "800_", "40_", "14", "1e6_", "700_", "60_", "15", "1000_", "800_", "8"});
	// REQUIRE(NumberToGeorgian::toWords(-9'223'372'036'854'775'807 - 1)
	// 		== "მინუს ცხრა კვინტილიონ ორას ოცდასამი კვადრილიონ სამას სამოცდათორმეტი ტრილიონ ოცდათექვსმეტი მილიარდ რვაას ორმოცდათოთხმეტი მილიონ შვიდას სამოცდათხუთმეტი ათას რვაას რვა");


	// A random number from example
	REQUIRE(NumberToGeorgian::toSymbolic(-6'872'146L)
			== VS{"minus", "6", "1e6_", "800_", "60_", "12", "1000_", "100_", "40_", "6"});
	REQUIRE(NumberToGeorgian::toWords(-6'872'146L)
			== "მინუს ექვსი მილიონ რვაას სამოცდათორმეტი ათას ას ორმოცდაექვსი");
}



/// @}
