#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printContent(T const& content)
{
    std::cout << content << std::endl;
}

template <typename T>
void increment(T& value)
{
    ++value;
}

template <typename T>
void appendMark(T& value)
{
    value += "!";
}

int main(void)
{
    std::cout << "=== TEST 1: non-const int array ===" << std::endl;

    int numbers[] = {1, 2, 3};
    std::size_t const numbersSize =
        sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Before increment:" << std::endl;
    iter(numbers, numbersSize, printContent<int>);

    iter(numbers, numbersSize, increment<int>);

    std::cout << "After increment:" << std::endl;
    iter(numbers, numbersSize, printContent<int>);


    std::cout << "\n=== TEST 2: const int array ===" << std::endl;

    int const constNumbers[] = {10, 20, 30};
    std::size_t const constNumbersSize =
        sizeof(constNumbers) / sizeof(constNumbers[0]);

    iter(constNumbers, constNumbersSize, printContent<int>);

    // This must not compile because const elements cannot be modified:
    // iter(constNumbers, constNumbersSize, increment<int>);


    std::cout << "\n=== TEST 3: non-const string array ===" << std::endl;

    std::string words[] = {"hello", "template", "world"};
    std::size_t const wordsSize =
        sizeof(words) / sizeof(words[0]);

    std::cout << "Before modification:" << std::endl;
    iter(words, wordsSize, printContent<std::string>);

    iter(words, wordsSize, appendMark<std::string>);

    std::cout << "After modification:" << std::endl;
    iter(words, wordsSize, printContent<std::string>);


    std::cout << "\n=== TEST 4: const string array ===" << std::endl;

    std::string const constWords[] = {
        "const",
        "string",
        "array"
    };
    std::size_t const constWordsSize =
        sizeof(constWords) / sizeof(constWords[0]);

    iter(constWords, constWordsSize, printContent<std::string>);
	// This must not compile because const elements cannot be modified:
	// iter(constWords, constWordsSize, appendMark<std::string>);


    std::cout << "\n=== TEST 5: zero length ===" << std::endl;

    std::cout << "Nothing should be printed below:" << std::endl;
    iter(numbers, 0, printContent<int>);
    std::cout << "End of zero-length test." << std::endl;

    return 0;
}