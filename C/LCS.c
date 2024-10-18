// Script to find the longest common subsequence
#include <stdio.h>
#include <string.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the longest common subsequence
void find_lcs(char *str1, char *str2, int m, int n) {
    // Create a 2D array to store the lengths of common subsequences
    int dp[m + 1][n + 1];

    // Initialize the first row and column to 0
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    // Fill the dp array in a bottom-up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the longest common subsequence
    int length = dp[m][n];
    char lcs[length + 1];
    lcs[length] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[length - 1] = str1[i - 1];
            i--;
            j--;
            length--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char str1[] = "AGGTAB";
    char str2[] = "GXTXAYB";

    int m = strlen(str1);
    int n = strlen(str2);

    find_lcs(str1, str2, m, n);

    return 0;
}
