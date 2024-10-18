/* Program to determine if a number is even or odd */

#include <stdio.h>

int main(void) {
    int n; // Variable to store the user input
    char choice; // Variable to store the user's choice to continue or exit

    do {
        // Prompt the user for input
        printf("Enter an integer: ");
        
        // Check if the input is valid
        if (scanf("%d", &n) != 1) {
            // Clear the input buffer if the input is not an integer
            while (getchar() != '\n'); // Discard invalid input
            printf("Invalid input! Please enter a valid integer.\n");
            continue; // Restart the loop to ask for input again
        }

        // Check if the number is even or odd
        if (n % 2 == 0) {
            printf("%d is an even number!\n", n);
        } else {
            printf("%d is an odd number!\n", n);
        }

        // Ask the user if they want to check another number
        printf("Do you want to check another number? (y/n): ");
        // Read the user's choice
        while (getchar() != '\n'); // Clear the input buffer
        choice = getchar();

    } while (choice == 'y' || choice == 'Y'); // Continue if user enters 'y' or 'Y'

    printf("Thank you for using the program!\n"); // Exit message
    return 0; // End of main
}
