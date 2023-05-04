#include <iostream>
#include <stdexcept>
char character(char start, int offset);

int main() {
    try {
        std::cout << character('a', 1) << std::endl; // should return 'b'
        std::cout << character('a', -1) << std::endl; // should throw an exception
        std::cout << character('Z', -1) << std::endl; // should return 'Y'
        std::cout << character('?', 5) << std::endl; // should throw an exception
        std::cout << character('A', 32) << std::endl; // should throw an exception
    }
    catch (std::invalid_argument& e) {
        std::cerr << "Invalid character: " << e.what() << std::endl;
    }
    catch (std::out_of_range& e) {
        std::cerr << "Invalid range: " << e.what() << std::endl;
    }
}


char character(char start, int offset) {
    // Convert start to upper case
    if (start >= 'a' && start <= 'z') {
        start -= 'a' - 'A';
    }

    // Check if start is a letter
    if (start < 'A' || start > 'Z') {
        throw std::invalid_argument("Invalid character");
    }

    // Compute the target letter
    char target = start + offset;

    // Check if target is a letter
    if (target < 'A' || target > 'Z') {
        throw std::out_of_range("Invalid range");
    }

    return target;
}
