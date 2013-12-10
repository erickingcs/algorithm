/*

 Subsets II:

 Given a collection of integers that might contain duplicates, S,
 return all possible subsets.

 Note:

 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,2], a solution is:

 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void get_non_empty_subset(vector<int> &v, int start, int end,
                              vector<vector<int> > &ret, vector<int> &selection)
    {
        for (int i = start; i <= end; i++) {
            // judge whether it is a repeating number
            bool isDuplicate = false;
            for (int j = start; j < i; j++) {
                if (v[j] == v[i])
                    isDuplicate = true;
            }

            if (!isDuplicate) {
                selection.push_back(v[i]);
                ret.push_back(selection);
                get_non_empty_subset(v, i + 1, end, ret, selection);
                selection.pop_back();
            }
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &v)
    {
        vector<vector<int> > ret;
        vector<int> selection;

        sort(v.begin(), v.end()); //make sure small numbers are present first
        ret.push_back(selection); // add empty subset first
        get_non_empty_subset(v, 0, v.size() - 1, ret, selection);

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
    vector<int> v = { 1, 2, 2 };
    Solution sol;

    vector<vector<int>> ret = sol.subsetsWithDup(v);
    print_ret(ret);

    return 0;
}
