/*

 Longest Palindromic Substring

 Given a string S, find the longest palindromic substring in S.
 You may assume that the maximum length of S is 1000, and there exists
 one unique longest palindromic substring.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    // O(n^2)
    // there exist O(n) algorithm
    // http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
    string longestPalindrome(string s)
    {
        int len = s.size();
        if (len == 0)
            return "";

        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int subStrLen = 0, start = 0;

        // dp[i][j] is true means s[i]...s[j] is palindrome
        for (int col = 0; col < len; col++) {
            for (int row = 0; row <= col; row++) {
                if (row == col) { // single char is palindrome
                    dp[row][col] = true;
                    if (col - row + 1 > subStrLen) { // update the longest candidate
                        subStrLen = col - row + 1;
                        start = row;
                    }
                } else if (s[row] == s[col]) {
                    // short circuit evaluation
                    // row + 1 == col means only have two letters, be careful
                    if (row + 1 == col || dp[row + 1][col - 1]) {
                        dp[row][col] = true;
                        if (col - row + 1 > subStrLen) {  // update the longest candidate
                            subStrLen = col - row + 1;
                            start = row;
                        }
                    }
                }
            }
        }

        return s.substr(start, subStrLen);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s1;
    string s2("a");
    string s3("aba");
    string s4("abcc");

    cout << sol.longestPalindrome(s1) << endl;
    cout << sol.longestPalindrome(s2) << endl;
    cout << sol.longestPalindrome(s3) << endl;
    cout << sol.longestPalindrome(s4) << endl;

    return 0;
}
