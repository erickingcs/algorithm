/*

 Add Binary

 Given two binary strings, return their sum (also a binary string).

 For example,
 a = "11"
 b = "1"
 Return "100".

 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	void charAdd(char c1, char c2, char &carry, char &sum) {
		if (c1 == '1' && c2 == '1' && carry == '1') {
			sum = '1';
			carry = '1';
		} else if ((c1 == '1' && c2 == '1') || (c1 == '1' && carry == '1')
				|| (c2 == '1' && carry == '1')) {
			sum = '0';
			carry = '1';
		} else if (c1 == '1' || c2 == '1' || carry == '1') {
			sum = '1';
			carry = '0';
		} else {
			sum = '0';
			carry = '0';
		}
	}

	string addBinary(string a, string b) {
		if (a.empty())
			return b;
		if (b.empty())
			return a;

		int aLen = a.size(), bLen = b.size();
		string ret;
		char sum = '0';
		char carry = '0';

		while (aLen && bLen) {
			charAdd(a[aLen - 1], b[bLen - 1], carry, sum);
			ret = sum + ret;
			aLen--;
			bLen--;
		}

		while (aLen) {
			charAdd(a[aLen - 1], '0', carry, sum);
			ret = sum + ret;
			aLen--;
		}

		while (bLen) {
			charAdd(b[bLen - 1], '0', carry, sum);
			ret = sum + ret;
			bLen--;
		}

		if (carry == '1')
			ret = '1' + ret;

		return ret;
	}
};

int main(int argc, char *argv[]) {
	Solution sol;
	string s1("11");
	string s2("1");

	cout << sol.addBinary(s1, s2) << endl;

	return 0;
}
