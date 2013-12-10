/*

 Combinations

 Given two integers n and k, return all possible combinations
 of k numbers out of 1 ... n.

 For example,
 If n = 4 and k = 2, a solution is:

 [
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
 ]

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(vector<int> &v, vector<vector<int> > &ret, vector<int> &selection,
             int n, int k)
    {
        if (k == 0) {
            ret.push_back(selection);
        } else {
            // choose v[i], and select k - 1 elements from v[i-1]...v[0]
            for (int i = n; i >= k; i--) {
                selection.push_back(v[i - 1]);
                dfs(v, ret, selection, i - 1, k - 1);  // i - 1
                selection.pop_back();
            }
        }
    }

    vector<vector<int> > combine(int n, int k)
    {
        vector<int> v;
        vector<vector<int> > ret;
        vector<int> selection;

        for (int i = n; i >= 1; i--)
            v.push_back(i);

        dfs(v, ret, selection, n, k);
        return ret;
    }
};

void print_ret(vector<vector<int>> &v)
{
    cout << endl;
    for (auto &v1 : v) {
        for (auto t : v1)
            cout << t << ends;
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    Solution sol;
    vector<vector<int>> ret = sol.combine(4, 2);
    print_ret(ret);

    return 0;
}
