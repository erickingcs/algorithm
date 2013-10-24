/*

 Longest Consecutive Sequence

 Given an unsorted array of integers, find the length of the
 longest consecutive elements sequence.

 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

 Your algorithm should run in O(n) complexity.

 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_set<int> arr;

		// construct hash table
		// O(n)
		for (auto e : num)
			arr.insert(e);

		// for each element in array, we only need to search hash table at most three times
		// because we delete it from hash table after finding it
		// so it is O(n)
		int maxLen = 0;
		int tmpLen = 0;
		for (auto e : num) {
			tmpLen = 1;
			arr.erase(e);

			int small = e - 1;
			while (arr.find(small) != arr.end()) { // little than e
				tmpLen++;
				arr.erase(small);
				small--;
			}

			int big = e + 1;
			while (arr.find(big) != arr.end()) { // greater than e
				tmpLen++;
				arr.erase(big);
				big++;
			}

			maxLen = max(maxLen, tmpLen);
		}

		return maxLen;
	}
};

int main(int argc, char* argv[]) {
	Solution sol;
	vector<int> num = { 100, 4, 200, 1, 3, 2 };

	cout << sol.longestConsecutive(num);

	return 0;
}
