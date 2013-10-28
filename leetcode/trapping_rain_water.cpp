/*

 Trapping Rain Water

 Given n non-negative integers representing an elevation map
 where the width of each bar is 1, compute how much water it
 is able to trap after raining.

 For example,
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

 The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 In this case, 6 units of rain water (blue section) are being trapped.
 Thanks Marcos for contributing this image!

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	// O(n)
	int trap(int A[], int n) {
		int *pbegin = A, *pend = A + n;
		int *pmax = max_element(pbegin, pend);
		int h = 0, water = 0;

		// calculate from left to max
		// either update height or accumulate water
		for (; pbegin < pmax; pbegin++) {
			if (*pbegin > h)
				h = *pbegin;
			else {
				water += h - *pbegin;
			}
		}

		// calculate from right to max
		// either update height or accumulate water
		h = 0;
		--pend;
		for (; pend > pmax; pend--) {
			if (*pend > h)
				h = *pend;
			else {
				water += h - *pend;
			}
		}

		return water;
	}
};

int main(int argc, char* argv[]) {
	int a[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	Solution sol;

	int ret = sol.trap(a, end(a) - begin(a));
	cout << ret << endl;

	return 0;
}
