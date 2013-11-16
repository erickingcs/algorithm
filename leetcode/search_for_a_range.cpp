/*

 Search for a Range

 Given a sorted array of integers, find the starting and ending
 position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].

 */

#include <iostream>
#include <vector>

using namespace std;

// O(log n)
class Solution {
public:
	bool findLeft(int a[], int n, int target, int &left) {
		int low = 0, high = n - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (a[mid] > target)
				high = mid - 1;
			else if (a[mid] < target)
				low = mid + 1;
			else { // a[mid] == target
				if (a[low] == target) {
					left = low; // update lower bound
					return true;
				}

				low += 1; // continue find lower bound
				high = mid;
			}
		}

		return false;
	}

	bool findRight(int a[], int n, int target, int &right) {
		int low = 0, high = n - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (a[mid] > target)
				high = mid - 1;
			else if (a[mid] < target)
				low = mid + 1;
			else { // a[mid] == target
				if (a[high] == target) {
					right = high; // update upper bound
					return true;
				}
				low = mid; // continue find upper bound
				high -= 1;
			}
		}

		return false;
	}

	vector<int> searchRange(int A[], int n, int target) {
		vector<int> ret;
		int left = -1, right = -1;
		if (findLeft(A, n, target, left) && findRight(A, n, target, right))
			;
		ret.push_back(left);
		ret.push_back(right);
		return ret;
	}
};

int main(int argc, char *argv[]) {
	Solution sol;
	int a[] = { 5, 7, 7, 8, 8, 10 };

	vector<int> ret = sol.searchRange(a, sizeof(a) / sizeof(int), 8);
	cout << ret[0] << ends << ret[1] << endl;

	return 0;
}
