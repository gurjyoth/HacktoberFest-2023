#include <iostream>
#include <vector>

class Solution {
public:
    // Function to find the majority element in the given vector
    int majorityElement(std::vector<int> &nums) {
        // Initialize a counter and a variable to hold the potential majority element
        int cnt = 0;
        int element;
        int n = nums.size(); // Get the size of the input vector

        // Iterate through the vector to find the majority element
        for (int i = 0; i < n; i++) {
            // If the count is zero, we set the current element as the potential majority
            if (cnt == 0) {
                element = nums[i];
            }

            // Increment or decrement the count based on whether the current element matches the potential majority
            if (nums[i] == element) {
                cnt++; // Increment count if current element matches
            } else {
                cnt--; // Decrement count if current element does not match
            }
        }

        // Return the found majority element
        return element;
    }
};

// Example usage of the Solution class
int main() {
    Solution solution; // Create an instance of the Solution class
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2}; // Example input vector

    // Find and output the majority element
    int majority = solution.majorityElement(nums);
    std::cout << "The majority element is: " << majority << std::endl;

    return 0; // Indicate that the program ended successfully
}
