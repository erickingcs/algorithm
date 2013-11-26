/*

   Pow(x, n)

   Implement pow(x, n).

*/

#include <iostream>

using namespace std;

class Solution {
	public:
		double do_positive_pow(double x, int n) {
			if (n == 0) return 1;
			else {
				double y = do_positive_pow(x, n/2);
				y *= y;
				if (n % 2 == 1) y *= x;
				return y;
			}
		}

		double pow(double x, int n) {
			if (x == 0) return 0;
			if (n > 0) return do_positive_pow(x, n);
			else return 1 / do_positive_pow(x, -n);
		}
};

int main(int argc, char *argv[]) {
	Solution sol;

	cout << sol.pow(2.1, 2) << endl;
	cout << sol.pow(2, -2) << endl;

	return 0;
}
