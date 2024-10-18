#include <iostream>
#include <stdexcept>

// Function to perform a single rotation on the array
void rotateOnce(float arr[], int size) {
    if (size <= 0) {
        throw std::invalid_argument("Array size must be positive.");
    }

    float temp = arr[0];
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
}

// Function to rotate the array by a specified number of positions
void rotateArray(float arr[], int size, int rotations) {
    if (size <= 0) {
        throw std::invalid_argument("Array size must be positive.");
    }
    if (rotations < 0) {
        throw std::invalid_argument("Number of rotations must be non-negative.");
    }

    rotations = rotations % size; // Handle cases where rotations > size

    for (int i = 0; i < rotations; i++) {
        rotateOnce(arr, size);
    }
}

// Function to print the array
void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int MAX_SIZE = 100;
    float arr[MAX_SIZE];
    int size, rotations;

    std::cout << "Enter the number of elements in the array (1-" << MAX_SIZE << "): ";
    std::cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        std::cerr << "Invalid array size." << std::endl;
        return 1;
    }

    std::cout << "Enter the values of the elements: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Enter the number of rotations: ";
    std::cin >> rotations;

    try {
        rotateArray(arr, size, rotations);
        std::cout << "Final array after rotation: ";
        printArray(arr, size);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
