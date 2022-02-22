# Number to Georgian (C++ Version)
***Convert a number to Georgian words, or to a symbolic representation***

![GitHub](https://img.shields.io/github/license/ashaduri/number-to-georgian-cpp)
![Language](https://img.shields.io/badge/language-ISO%20C++17-blue)


## Features
- Header-only.
- Requires only standard C++ (C++17).
- Extensively tested using [Catch2](https://github.com/catchorg/Catch2).
- Can output a string of Georgian words.
- Can output a vector of strings, where each element is a symbolic (ASCII) representation
of a Georgian word (or part of a word). This is useful for creating a library of sound
files (e.g. `0.wav`, `minus.wav`, ...) to be used in interactive voice applications, etc... 


## Usage Examples

``` C++
#include "number_to_georgian.h"

// ...

assert(NumberToGeorgian::toWord(0L) == "ნული"s);
assert(NumberToGeorgian::toSymbolic(0L) == std::vector<std::string>{"0"s});

assert(NumberToGeorgian::toWords(-6'872'146L)
	== "მინუს ექვსი მილიონ რვაას სამოცდათორმეტი ათას ას ორმოცდაექვსი"s);
assert(NumberToGeorgian::toSymbolic(-6'872'146L)
	== std::vector<std::string>{"minus"s, "6"s, "1e6_"s, "800_"s, "60_"s, "12"s, "1000_"s, "100_"s, "40_"s, "6"s});
```

Please see `NumberToGeorgian::toSymbolic` for a list of possible returned values.

## Copyright

Copyright: Alexander Shaduri <ashaduri@gmail.com>   
License: Zlib
