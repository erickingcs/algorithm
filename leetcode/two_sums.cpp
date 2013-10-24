/*
 Two Sum

 Given an array of integers, find two numbers such that they add up to a specific target number.
 The function twoSum should return indices of the two numbers such that they add up to the target,
 where index1 must be less than index2. Please note that your returned answers (both index1 and
 index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	// brute force, O(n^2)
	vector<int> twoSum1(vector<int> &numbers, int target) {
		vector<int> ret;
		auto begin = numbers.begin(), end = numbers.end();
		for (auto ite = begin; ite != end; ite++) {
			auto t = find(ite + 1, end, target - *ite);
			if (t != end) {
				ret.push_back(ite - begin + 1);
				ret.push_back(t - begin + 1);
				return ret;
			}
		}
	}

	// hash, O(n)
	vector<int> twoSum2(vector<int> &numbers, int target) {
		vector<int> ret;
		unordered_map<int, int> hash; // no need to use multimap

		for (int i = 0; i < numbers.size(); i++) {
			hash[numbers[i]] = i;
		}

		// traverse the original array, if it has duplicate numbers and those duplicate
		// numbers' addition is target, it must have two duplicate
		// we keep the latter one's subscript in hash table
		for (int i = 0; i < numbers.size(); i++) { // original array
			int sub = target - numbers[i];
			if (hash.find(sub) != hash.end()) {
				int index2 = hash[sub];
				if (i > index2)
					swap(i, index2);
				ret.push_back(i + 1);
				ret.push_back(index2 + 1);
				return ret;
			}
		}
	}
};

int main(int argc, char* argv[]) {
	vector<int> numbers = { 1, 2, 6, 2, 5 };
	int target = 4;
	Solution s;

	vector<int> res = s.twoSum2(numbers, target);
	for (auto e : res) {
		cout << e << ends;
	}

	return 0;
}
