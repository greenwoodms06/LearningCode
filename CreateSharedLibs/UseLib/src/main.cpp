#include <iostream>
#include "MathFunctions.h"

int main() {
    double x = 16.0;
    double result = sqrt_custom(x);

    std::cout << "Square root of " << x << " is: " << result << std::endl;

	std::cin.get();

    return 0;
}