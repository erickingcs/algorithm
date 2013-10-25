/*

 Letter Combinations of a Phone Number

 Given a digit string, return all possible letter combinations that the number could represent.
 A mapping of digit to letters (just like on the telephone buttons) is given below.


 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
	vector<string> d2c; // digit to char map
public:
	Solution() :
			d2c( { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",
					"wxyz" }) {
	}

	vector<string> letterCombinations(string digits) {
		int len = digits.size();
		vector<string> ret;

		dfs(digits, ret, "", 0, len);

		return ret;
	}

	void dfs(string &digits, vector<string> &ret, string s, int start, // s, not &s
			int end) {
		if (start == end) {
			ret.push_back(s);
		} else {
			int index = digits[start] - '0';
			for (int i = 0; i < d2c[index].size(); i++)
				dfs(digits, ret, s + d2c[index][i], start + 1, end);
		}
	}
};

int main(int argc, char *argv[]) {
	Solution sol;
	string s("23");

	vector<string> ret = sol.letterCombinations(s);

	for (auto t : ret)
		cout << t << ends;

	return 0;
}
