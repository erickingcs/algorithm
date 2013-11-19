/*

 Gray Code

 The gray code is a binary numeral system where two successive values differ in only one bit.

 Given a non-negative integer n representing the total number of bits in the code,
 print the sequence of gray code. A gray code sequence must begin with 0.

 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

 00 - 0
 01 - 1
 11 - 3
 10 - 2

 Note:
 For a given n, a gray code sequence is not uniquely defined.

 For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

 For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

 */

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
	// http://en.wikipedia.org/wiki/Gray_code

	// The binary-reflected Gray code list for n bits can be generated recursively
	// from the list for n-1 bits by reflecting the list (i.e. listing the entries
	// in reverse order), concatenating the original list with the reversed list,
	// prefixing the entries in the original list with a binary 0, and then
	// prefixing the entries in the reflected list with a binary 1.
	vector<int> grayCode(int n) {
		if (n < 0) // error input
			return vector<int>();
		else if (n == 0) // online judge require it
			return vector<int>(1, 0);
		else if (n == 1)
			return vector<int>( { 0, 1 });
		else {
			vector<int> ret = grayCode(n - 1);
			for (int i = ret.size() - 1; i >= 0; i--)
				ret.push_back((1 << (n - 1)) | ret[i]);

			return ret;
		}
	}

	vector<int> grayCode2(int n) {
		vector<int> ret;
		int size = 1 << n; // total number: 0...2^n -1
		for (int i = 0; i < size; ++i)
			ret.push_back((i >> 1) ^ i);
		return ret;
	}
};

int main(int argc, char *argv[]) {
	int n = 3;
	Solution sol;

	vector<int> ret = sol.grayCode2(n);

	for (auto t : ret)
		cout << t << ends;

	return 0;
}
