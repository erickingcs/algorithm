/*

 Search in Rotated Sorted Array ||

 Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?

 Would this affect the run-time complexity? How and why?

 Write a function to determine if a given target is in the array.

 */

#include <iostream>

using namespace std;

// O(n)
class Solution
{
public:
    bool search(int A[], int n, int target)
    {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == target)
                return true;
            else { // A[mid] != target
                if (A[low] <= A[mid]) {
                    if (A[low] == A[mid]) {
                        // simply add first subscript...
                        // I cannot find good way to deal with it. :(
                        // does it still exist O(log n) algorithm?
                        low++;
                        continue;
                    }

                    // otherwise, elements in the first part is in order
                    // || means A[mid] > target && A[low] > target
                    // also note here A[mid] != target
                    if (A[mid] < target || A[low] > target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                } else { // A[low] > A[mid]
                    // elements in the second part is in order
                    if (A[mid] > target || A[high] < target) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = { 4, 5, 6, 7, 0, 1, 1, 1, 2 };
    int a2[] = { 1, 1, 3 };
    int a3[] = { 1, 1, 3, 1 };

    cout << sol.search(a, sizeof(a) / sizeof(int), 4) << endl;
    cout << sol.search(a, sizeof(a) / sizeof(int), 7) << endl; // bug
    cout << sol.search(a, sizeof(a) / sizeof(int), 0) << endl;
    cout << sol.search(a, sizeof(a) / sizeof(int), 1) << endl;
    cout << sol.search(a, sizeof(a) / sizeof(int), 3) << endl;

    cout << sol.search(a2, sizeof(a2) / sizeof(int), 3) << endl; // bug
    cout << sol.search(a3, sizeof(a3) / sizeof(int), 3) << endl; // bug

    return 0;
}
