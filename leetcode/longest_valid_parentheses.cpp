/*

 Longest Valid Parentheses

 Given a string containing just the characters '(' and ')',
 find the length of the longest valid (well-formed) parentheses substring.

 For "(()", the longest valid parentheses substring is "()", which has length = 2.

 Another example is ")()())", where the longest valid parentheses
 substring is "()()", which has length = 4.

 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int sLen = s.size();
        if (sLen <= 1)
            return 0;

        stack<int> stk; // record '(' position
        int ret = 0;
        int lastRighP = -1; // last position of ')', must be -1, consider ()

        for (int i = 0; i < sLen; i++) {
            if (s[i] == '(')
                stk.push(i);
            else { // ')'
                if (stk.empty()) { // no match
                    lastRighP = i;
                } else { // match, need to pop stack and calculate length
                    stk.pop();
                    if (stk.empty()) { // case 1
                        ret = max(ret, i - lastRighP);
                    } else { // case 2
                        ret = max(ret, i - stk.top());
                    }
                }
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s1(")()())");
    string s2("()");
    string s3("((((");
    string s4("))))");

    cout << sol.longestValidParentheses(s1) << endl;
    cout << sol.longestValidParentheses(s2) << endl;
    cout << sol.longestValidParentheses(s3) << endl;
    cout << sol.longestValidParentheses(s4) << endl;

    return 0;
}
