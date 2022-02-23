# Number to Georgian (C++ Version)
***Convert a number to Georgian words, or to a symbolic representation***

![GitHub](https://img.shields.io/github/license/ashaduri/number-to-georgian-cpp)
![Language](https://img.shields.io/badge/language-ISO%20C++17-blue)


## Features
- Header-only.
- Requires only standard C++ (C++17).
- Extensively tested using [Catch2](https://github.com/catchorg/Catch2).
- Supports the whole 64-bit signed integer range.
- Can output a string of Georgian words.
- Can output a vector of strings, where each element is a symbolic (ASCII) representation
of a Georgian word (or part of a word). This is useful for creating a library of sound
files (e.g. `0.wav`, `minus.wav`, ...) to be used in interactive voice applications, etc... 


## Usage Examples

``` C++
#include "number_to_georgian.h"

// ...

assert(NumberToGeorgian::toWords(0) == "ნული");
assert(NumberToGeorgian::toSymbolic(0) == std::vector<std::string>{"0"});

assert(NumberToGeorgian::toWords(-6'872'146)
	== "მინუს ექვსი მილიონ რვაას სამოცდათორმეტი ათას ას ორმოცდაექვსი");
assert(NumberToGeorgian::toSymbolic(-6'872'146)
	== std::vector<std::string>{"minus", "6", "1e6_", "800_", "60_", "12", "1000_", "100_", "40_", "6"});

assert(NumberToGeorgian::toWords(std::numeric_limits<std::int64>::min())
		== "მინუს ცხრა კვინტილიონ "
		"ორას ოცდასამი კვადრილიონ "
		"სამას სამოცდათორმეტი ტრილიონ "
		"ოცდათექვსმეტი მილიარდ "
		"რვაას ორმოცდათოთხმეტი მილიონ "
		"შვიდას სამოცდათხუთმეტი ათას "
		"რვაას რვა");
```

Please see `NumberToGeorgian::toSymbolic` for a list of possible returned values.

## Copyright

Copyright: Alexander Shaduri <ashaduri@gmail.com>   
License: Zlib
