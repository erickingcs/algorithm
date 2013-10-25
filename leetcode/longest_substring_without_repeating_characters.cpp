/*
 Longest Substring Without Repeating Characters

 Given a string, find the length of the longest substring without repeating
 characters. For example, the longest substring without repeating letters for
 "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring
 is "b", with the length of 1.

 */

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		const int CHAR_SET = 256;
		bitset<CHAR_SET> char_map(0);
		int maxLength = 0;
		int i = 0, j = 0;
		int len = s.length();

		while (j < len) {
			if (!char_map.test(s[j])) { // not a repeat char, go ahead
				char_map.set(s[j]);
				j++;
			} else {
				// duplicate char, put forward i and delete first char
				char_map.reset(s[i]);
				i++;
			}
			// update current length
			maxLength = max(maxLength, j - i);
		}
		return maxLength;
	}

	//do not use bitset as compilation error of leetcode
	int lengthOfLongestSubstring2(string s) {
		const int CHAR_SET = 256;
		bool char_map[CHAR_SET] = { false };
		int maxLength = 0;
		int i = 0, j = 0;
		int len = s.length();

		while (j < len) {
			if (!char_map[s[j]]) { // not a repeat char, go ahead
				char_map[s[j]] = true;
				j++;
			} else {
				// duplicate char, put forward i and delete first char
				char_map[s[i]] = false;
				i++;
			}
			// update current length
			maxLength = max(maxLength, j - i);
		}
		return maxLength;
	}
};

int main(int argc, char* argv[]) {
	string s("aaa");

	Solution sol;
	cout << sol.lengthOfLongestSubstring(s) << endl;
	cout << sol.lengthOfLongestSubstring2(s) << endl;

	return 0;
}
