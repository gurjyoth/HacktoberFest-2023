#include <stdio.h>
#include <stdbool.h>

// Function to determine if you can jump to the end of the array
bool canJump(int *nums, int numsSize) {
    int maxReach = 0; // Initialize the maximum reachable index

    for (int i = 0; i < numsSize; i++) {
        // If the current index is beyond the maximum reachable index, return false
        if (i > maxReach) {
            return false;
        }

        // Update the maximum reachable index
        maxReach = (i + nums[i] > maxReach) ? (i + nums[i]) : maxReach;

        // If we can reach or exceed the last index, return true
        if (maxReach >= numsSize - 1) {
            return true;
        }
    }

    return false; // If we finish the loop without reaching the end, return false
}

int main() {
    // Example input array
    int nums[] = {2, 3, 1, 1, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    // Check if the end of the array can be reached and print the result
    if (canJump(nums, numsSize)) {
        printf("Yes, you can reach the end of the array!\n");
    } else {
        printf("No, you cannot reach the end of the array.\n");
    }

    return 0;
}
