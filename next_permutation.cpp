#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {

		vector<int> a = nums;

		int idx = -1;
		int n = a.size();

		if (n == 1) {
			return;
		}

		int i  = n - 2;
		while (i >= 0  and a[i] >= a[i + 1])i--;

		if (i >= 0) {

			int j = n - 1;
			while (a[j] <= a[i])j--;
			swap(a[i] , a[j]);
		}

		int l = i + 1 , r = n - 1;
		while (l < r)swap(a[l] , a[r]) , l++ , r--;

		nums = a;
	}
};

int main() {


	return 0 ;
}
