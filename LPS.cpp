//longest palindromic subsequnce

#include "bits/stdc++.h"
using namespace std;

#define int              long long
#define lld              long double
#define si(x)            (int)x.size()
#define pii              pair<int,int>
#define vt               vector
#define pb               push_back
#define ff               first
#define ss               second
#define all(x)           (x).begin(),(x).end()
#define FOR(a)           for(auto& ix :a)
#define rep(n)           for(int i=0;i<n;i++)
#define rfr(i,a,b)       for(int i = a ; i<=b ; i++)
#define mem(a,x)         memset(a,x,sizeof(a))
#define deb(x)           cout<<#x<<"="<<x<<endl;
#define debx(x,y)        cout<<#x<<"="<<x<<"   ";deb(y);
#define debxx(x,y,z)     cout<<#x<<"="<<x<<"   ";debx(y,z);
#define pnr(a)           FOR(a){cout<<ix<<" ";}cout<<endl;
#define pnrx(a)          FOR(a){cout<<ix.ff<<" "<<ix.ss<<endl;}
#define minpq(x)         priority_queue<x,vt<x>,greater<x>>

const int inf = 1e18 ,
          mxn = 2e5 + 5,
          mod = 1e9 + 7;

int solve()
{
	string s;
	cin >> s;

	int n = si(s);

	int dp[n ][n ];
	mem(dp , -1);
	for (int l = 1 ; l <= n ; l++)
	{
		if (l == 1)
		{
			for (int i = 0 ; i < n ; i++)
				dp[i][i] = 1;
		}
		else
		{
			for (int i = 0 ; i <= n - 1 - l ; i++)
			{
				if (s[i] == s[i + l])
				{
					dp[i][i + l - 1] = dp[i + 1][i + l - 2] + 2;
				}
				else
				{
					dp[i][i + l - 1] = max( dp[i - 1][i + l - 1] , dp[i][i + l - 2]);
				}
			}
		}
	}
	for (int i = 0 ; i < n ; i++)
	{
		pnr(dp[i])
	}

	return 0;
}
int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif

	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(20);

	int t = 1;
	//cin>>t;
	rfr(tt , 1 , t)
	{
		solve();
	}
	return 0 ;
}
