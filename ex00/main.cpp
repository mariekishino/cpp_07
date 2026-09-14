#include "Whatever.hpp"

#include <iomanip>
#include <iostream>
#include <string>

static void testInt(void)
{
    std::cout << "=== int ===" << std::endl;

    int a = 2;
    int b = 3;

    ::swap(a, b);

    std::cout << "after swap: a = " << a
              << ", b = " << b << std::endl;

    std::cout << "min(a, b) = " << ::min(a, b)
              << " (expected 2)" << std::endl;

    std::cout << "max(a, b) = " << ::max(a, b)
              << " (expected 3)" << std::endl;

    // 逆順も確認
    std::cout << "min(b, a) = " << ::min(b, a)
              << " (expected 2)" << std::endl;

    std::cout << "max(b, a) = " << ::max(b, a)
              << " (expected 3)" << std::endl;

    std::cout << std::endl;
}

static void testEqualValues(void)
{
    std::cout << "=== equal values ===" << std::endl;

    int first = 42;
    int second = 42;

    const int& minResult = ::min(first, second);
    const int& maxResult = ::max(first, second);

    std::cout << "min value = " << minResult << std::endl;
    std::cout << "max value = " << maxResult << std::endl;

    std::cout << "min returns second: "
              << (&minResult == &second ? "OK" : "NG")
              << std::endl;

    std::cout << "max returns second: "
              << (&maxResult == &second ? "OK" : "NG")
              << std::endl;

    std::cout << std::endl;
}

static void testSameObjectSwap(void)
{
    std::cout << "=== same object swap ===" << std::endl;

    int value = 10;

    ::swap(value, value);

    std::cout << "value = " << value
              << " (expected 10)" << std::endl;

    std::cout << std::endl;
}

static void testConstValues(void)
{
    std::cout << "=== const values ===" << std::endl;

    const int a = 10;
    const int b = 20;

    std::cout << "min(a, b) = " << ::min(a, b)
              << " (expected 10)" << std::endl;

    std::cout << "max(a, b) = " << ::max(a, b)
              << " (expected 20)" << std::endl;

    std::cout << std::endl;
}

static void testFloatingPoint(void)
{
    std::cout << "=== double ===" << std::endl;

    double x = 2.0;
    double y = 3.0;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "min(x, y) = " << ::min(x, y)
              << " (expected 2.0)" << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y)
              << " (expected 3.0)" << std::endl;

    std::cout << std::endl;

    std::cout << "=== float ===" << std::endl;

    float f1 = 2.5f;
    float f2 = 3.5f;

    ::swap(f1, f2);

    std::cout << "after swap: f1 = " << f1
              << ", f2 = " << f2 << std::endl;
    std::cout << "min(f1, f2) = " << ::min(f1, f2)
              << " (expected 2.5)" << std::endl;
    std::cout << "max(f1, f2) = " << ::max(f1, f2)
              << " (expected 3.5)" << std::endl;

    std::cout << std::endl;
}

static void testString(void)
{
    std::cout << "=== string ===" << std::endl;

    std::string a = "chaine1";
    std::string b = "chaine2";

    ::swap(a, b);

    std::cout << "after swap: a = " << a
              << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b)
              << " (expected chaine1)" << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b)
              << " (expected chaine2)" << std::endl;

    std::cout << std::endl;
}

int main(void)
{
    testInt();
    testEqualValues();
    testSameObjectSwap();
    testConstValues();
    testFloatingPoint();
    testString();

    return 0;
}


// int main( void ) 
// {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	return 0;
// }