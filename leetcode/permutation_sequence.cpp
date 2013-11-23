/*

 Permutation Sequence

 The set [1,2,3,…,n] contains a total of n! unique permutations.

 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):

 "123"
 "132"
 "213"
 "231"
 "312"
 "321"

 Given n and k, return the kth permutation sequence.
 Note: Given n will be between 1 and 9 inclusive.

 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// TLE
class Solution {
public:
	string getPermutation(int n, int k) {
		string ret;
		if (k <= 0)
			return ret;

		vector<int> v(n);
		iota(v.begin(), v.end(), 1);

		while (--k) {
			next_permutation(v.begin(), v.end());
		}

		for (auto t : v) {
			ret += t + '0';
		}

		return ret;
	}
};

class Solution2 {
public:
	long long factorial(int n) {
		long long product = 1;
		for (int i = 2; i <= n; i++) {
			product *= i;
		}
		return product;
	}

	string getPermutation(int n, int k) {
		if (n < 1 || k < 1)
			return "";

		string orig, ret;
		for (int i = 1; i <= n; i++) {
			orig += i + '0';
		}

		// Cantor encode, start from 0
		--k;
		int base = factorial(n - 1); // (n-1)!

		for (int i = n - 1; i > 0; k %= base, base /= i, --i) {
			// judge it belongs to which permutation
			// the sub permu, leading with orig[sub]
			int sub = k / base;
			ret += orig[sub];
			orig.erase(sub, 1);
		}
		ret += orig[0]; // i == 0, the last one

		return ret;
	}
};

int main(int argc, char *argv[]) {
	Solution sol;
	Solution2 sol2;

	for (int i = 1; i <= 6; i++) {
		cout << sol.getPermutation(3, i) << endl;
		cout << sol2.getPermutation(3, i) << endl;
	}

	return 0;
}
