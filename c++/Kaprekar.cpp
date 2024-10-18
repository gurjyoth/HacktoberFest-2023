#include <iostream>
#include <cmath>
#include <string>

bool isKaprekar(int n, int base) {
    if (n < 0) return false; // Negative numbers cannot be Kaprekar numbers

    // Calculate n squared
    long long n_squared = static_cast<long long>(n) * n;

    // Convert n_squared to the specified base and string format
    std::string squared_str = "";
    long long temp = n_squared;
    while (temp > 0) {
        int digit = temp % base;
        squared_str = std::to_string(digit) + squared_str;
        temp /= base;
    }

    // Split the string representation of n_squared
    int len = squared_str.length();
    for (int i = 0; i <= len; ++i) {
        std::string left_part = squared_str.substr(0, i);
        std::string right_part = squared_str.substr(i);

        // Convert parts back to integer in the specified base
        long long left_num = left_part.empty() ? 0 : std::stoll(left_part, nullptr, base);
        long long right_num = right_part.empty() ? 0 : std::stoll(right_part, nullptr, base);

        // Check if the sum equals n
        if (left_num + right_num == n) {
            return true;
        }
    }

    return false;
}

int main() {
    int number, base;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Enter the base: ";
    std::cin >> base;

    if (isKaprekar(number, base)) {
        std::cout << number << " is a Kaprekar number in base " << base << ".\n";
    } else {
        std::cout << number << " is not a Kaprekar number in base " << base << ".\n";
    }

    return 0;
}
