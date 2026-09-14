#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

static void testEmptyArray()
{
    std::cout << "=== EMPTY ARRAY ===" << std::endl;

    Array<int> empty;

    std::cout << "size: " << empty.size() << std::endl;

    try
    {
        std::cout << empty[0] << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }
}

static void testDefaultInitialization()
{
    std::cout << "\n=== DEFAULT INITIALIZATION ===" << std::endl;

    Array<int> numbers(5);

    for (unsigned int i = 0; i < numbers.size(); ++i)
    {
        std::cout << "numbers[" << i << "]: "
                  << numbers[i] << std::endl;
    }
}

static void testReadAndWrite()
{
    std::cout << "\n=== READ AND WRITE ===" << std::endl;

    Array<std::string> words(3);

    words[0] = "class";
    words[1] = "template";
    words[2] = "array";

    for (unsigned int i = 0; i < words.size(); ++i)
        std::cout << words[i] << std::endl;
}

static void testCopyConstructor()
{
    std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;

    Array<int> original(3);

    original[0] = 10;
    original[1] = 20;
    original[2] = 30;

    Array<int> copy(original);

    copy[0] = 999;

    std::cout << "original[0]: " << original[0] << std::endl;
    std::cout << "copy[0]:     " << copy[0] << std::endl;
}

static void testAssignmentOperator()
{
    std::cout << "\n=== ASSIGNMENT OPERATOR ===" << std::endl;

    Array<int> source(2);

    source[0] = 42;
    source[1] = 84;

    Array<int> destination(4);

    destination = source;
    destination[1] = 1000;

    std::cout << "source size:      "
              << source.size() << std::endl;

    std::cout << "destination size: "
              << destination.size() << std::endl;

    std::cout << "source[1]:        "
              << source[1] << std::endl;

    std::cout << "destination[1]:   "
              << destination[1] << std::endl;

    source = source;

    std::cout << "after self-assignment, source[0]: "
              << source[0] << std::endl;
}

static void testConstArray()
{
    std::cout << "\n=== CONST ARRAY ===" << std::endl;

    Array<int> values(2);

    values[0] = 7;
    values[1] = 14;

    Array<int> const constValues(values);

    std::cout << "size: "
              << constValues.size() << std::endl;

    std::cout << "constValues[1]: "
              << constValues[1] << std::endl;
}

static void testOutOfBounds()
{
    std::cout << "\n=== OUT OF BOUNDS ===" << std::endl;

    Array<int> numbers(3);

    try
    {
        numbers[3] = 42;
        std::cout << "ERROR: index 3 was accepted" << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "upper bound exception: "
                  << e.what() << std::endl;
    }

    try
    {
        numbers[-2] = 42;
        std::cout << "ERROR: index -2 was accepted" << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "negative index exception: "
                  << e.what() << std::endl;
    }
}

static bool testSubjectMain()
{
    std::cout << "\n=== SUBJECT MAIN TEST ===" << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    std::srand(std::time(NULL));

    for (int i = 0; i < MAX_VAL; ++i)
    {
        int const value = std::rand();

        numbers[i] = value;
        mirror[i] = value;
    }

    /*
     * Both copies are destroyed when this scope ends.
     * If Array performs a shallow copy, their destruction may corrupt
     * the original numbers array.
     */
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; ++i)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "ERROR: numbers[" << i
                      << "] does not match mirror[" << i << "]"
                      << std::endl;

            delete[] mirror;
            return false;
        }
    }

    try
    {
        numbers[-2] = 0;
        std::cerr << "ERROR: negative index was accepted"
                  << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "negative index exception: "
                  << e.what() << std::endl;
    }

    try
    {
        numbers[MAX_VAL] = 0;
        std::cerr << "ERROR: index MAX_VAL was accepted"
                  << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "upper bound exception: "
                  << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; ++i)
        numbers[i] = std::rand();

    delete[] mirror;

    std::cout << "subject main test: SUCCESS" << std::endl;
    return true;
}

int main()
{
    testEmptyArray();
    testDefaultInitialization();
    testReadAndWrite();
    testCopyConstructor();
    testAssignmentOperator();
    testConstArray();
    testOutOfBounds();

    if (!testSubjectMain())
        return 1;

    return 0;
}

// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }