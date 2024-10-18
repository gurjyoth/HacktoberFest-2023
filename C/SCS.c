// Script to find the Shortest Common Supersequence
#include <stdio.h>
#include <string.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the length of the shortest common supersequence
int shortestCommonSupersequenceLength(char *str1, char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    // Create a 2D array to store the lengths of common supersequences
    int dp[m + 1][n + 1];

    // Initialize the first row and column to 0
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Fill the dp array in a bottom-up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

// Function to print the shortest common supersequence
void printSCS(char *str1, char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int SCSLength = shortestCommonSupersequenceLength(str1, str2);
    char SCS[SCSLength + 1];

    int i = m, j = n, k = SCSLength;

    // Reconstruct the shortest common supersequence
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            SCS[k - 1] = str1[i - 1];
            i--;
            j--;
            k--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            SCS[k - 1] = str1[i - 1];
            i--;
            k--;
        } else {
            SCS[k - 1] = str2[j - 1];
            j--;
            k--;
        }
    }

    // Add any remaining characters from str1
    while (i > 0) {
        SCS[k - 1] = str1[i - 1];
        i--;
        k--;
    }

    // Add any remaining characters from str2
    while (j > 0) {
        SCS[k - 1] = str2[j - 1];
        j--;
        k--;
    }

    SCS[SCSLength] = '\0';

    printf("Shortest Common Supersequence: %s\n", SCS);
}

int main() {
    char str1[] = "ABCBDAB";
    char str2[] = "BDCABA";

    int SCSLength = shortestCommonSupersequenceLength(str1, str2);
    printf("Length of Shortest Common Supersequence: %d\n", SCSLength);

    printSCS(str1, str2);

    return 0;
}
