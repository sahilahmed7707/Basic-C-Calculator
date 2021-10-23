#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
#define ll long long
	int n;
	vector<pair<ll , ll>> a;
	int ans = 0;


	void merge(int l , int mid , int r) {

		vector<pair<ll , ll>> t(r - l + 1);
		for (int i = mid + 1 ; i <= r ; i++)
			a[i].first += a[i].first;

		int i = l , j = mid + 1 , k = 0;

		while (i <= mid  and j <= r) {
			if (a[j].first < a[i].first) {
				j++;
			} else {
				ans += j - 1 - mid;
				i++;
			}
		}

		while (i <= mid) {
			ans += r - mid;
			i++;
		}

		while ( j <= r) {
			j++;
		}

		for (int i = mid + 1 ; i <= r ; i++)
			a[i].first /= 2; //a[i].first;

		i = l  , j = mid + 1  , k = 0;
		while (i <= mid  and j <= r) {
			if (a[j].first < a[i].first) {
				t[k] = a[j];
				j++;
			} else {
				t[k] = a[i];
				i++;
			}
			k++;
		}

		while (i <= mid) {
			t[k] = a[i];
			i++;
			k++;
		}

		while ( j <= r) {
			t[k] = a[j];
			k++;
			j++;
		}
		for (int ix = l ; ix <= r ; ix++)
			a[ix] = t[ix - l];

	}

	void mergesort(int l , int r) {
		if (l >= r)
			return;
		int mid = (l + r) / 2;
		mergesort(l , mid);
		mergesort(mid + 1 , r);
		merge(l , mid , r);
	}

	int reversePairs(vector<int>& nums) {
		n = nums.size();
		a.resize(n);

		for (int i = 0 ; i < n ; i++)
			a[i] = {nums[i] , i};

		mergesort(0 , n - 1);

		return ans;


	}
};

int main() {
	return 0 ;
}
