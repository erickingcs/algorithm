/*

 Subsets

 Given a set of distinct integers, S, return all possible subsets.

 Note:

 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.

 For example,
 If S = [1,2,3], a solution is:

 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void get_non_empty_subset(vector<int> &v, int start, int end,
			vector<vector<int> > &ret, vector<int> &selection) {
		for (int i = start; i <= end; i++) {
			selection.push_back(v[i]);
			ret.push_back(selection);
			get_non_empty_subset(v, i + 1, end, ret, selection);
			selection.pop_back();
		}
	}

	vector<vector<int> > subsets(vector<int> &v) {
		vector<vector<int> > ret;
		vector<int> selection;

		sort(v.begin(), v.end()); //make sure small numbers are present first
		ret.push_back(selection); // add empty subset first
		get_non_empty_subset(v, 0, v.size() - 1, ret, selection);

		return ret;
	}
};

void print_ret(vector<vector<int>> &v) {
	cout << endl;
	for (auto &v1 : v) {
		for (auto t : v1)
			cout << t << ends;
		cout << endl;
	}
}

int main(int argc, char* argv[]) {
	vector<int> v = { 3, 1, 2 };
	Solution sol;

	vector<vector<int>> ret = sol.subsets(v);
	print_ret(ret);

	return 0;
}
