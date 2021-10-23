#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    const int inf = INT_MAX;
#define si(a) (int)(a.size())
    vector<int> a , b;
    int n , m;


    int getkth(int k) {
        int l = max(0, k - m) , r = n;

        while (l <= r) {
            int mid = (l + r) / 2;
            int i = mid;
            int j = k - i;


            int l1 = i == 0 ? -inf : a[i - 1];
            int l2 = j == 0 ? -inf : b[j - 1];
            int r1 = i >= n ? inf : a[i];
            int r2 = j >= m ? inf : b[j];
            cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl;

            if (l1 <= r2  and l2 <= r1) {
                return max(l1 , l2);
            }
            if (l1 > r2) {
                r = mid - 1;
            } else
                l = mid + 1;

        }
        return -1;
    }


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;

        if (si(a) > si(b))
            swap(a , b);


        n = si(a);
        m = si(b);

        if (n == 0) {
            if (m % 2) {
                return b[m / 2];
            } else {
                return (b[m / 2 - 1] + b[m / 2]) / 2.0;
            }
        }

        if (m == 1) {
            return (a[0] + b[0]) / 2.0;
        }

        if ((n + m) % 2) {
            cout << (n + m) / 2 + 1 << endl;
            return getkth((n + m) / 2 + 1);
        } else {
            int x = getkth((n + m) / 2);
            cout << x << endl;
            int y = getkth((n + m) / 2 + 1);
            cout << y << endl;
            return (x + y) / 2.0;
        }
        return 1;

    }
};

int main() {
#ifdef LOCAL
    freopen("/home/sammy/Documents/sublimeCode/input.txt", "r", stdin);
    //freopen("/home/sammy/Documents/sublimeCode/output.txt", "w", stdout);
#endif

    return 0 ;
}
