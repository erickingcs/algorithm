/*

 Climbing Stairs

 You are climbing a staircase. It takes n steps to reach to the top.
 Each time you can either climb 1 or 2 steps. In how many distinct ways
 can you climb to the top?

 */

#include <iostream>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1; // bug
        int s1 = 1, s2 = 2;
        for (int i = 3; i <= n; i++) {
            int t = s1 + s2;
            s1 = s2;
            s2 = t;
        }

        return s2;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.climbStairs(4) << endl;

    return 0;
}
