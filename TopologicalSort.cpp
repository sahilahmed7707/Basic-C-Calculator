#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> gr[N];
vector<int> order;


int toposort() {
	priority_queue<int , vector<int> , greater<int>> q;  /// lexiographically smallest
	vector<int> indeg(n + 1, 0);

	for (int i = 1; i <= n; i++) // indegree calculation
		for (auto &it : gr[i])
			indeg[it]++;

	for (int i = 1; i <= n; i++)  // pushing numbers with 0 indegre
	{
		if (!indeg[i])
			q.push(i);
	}

	while (!q.empty())
	{
		int u = q.top();
		q.pop();
		order.push_back(u);
		for (auto &v : gr[u])
		{
			indeg[v]--;
			if (!indeg[v])
				q.push(v);
		}
	}
	if (order.size() == n)
		return 1;
	return 0;

}

int solve() {
	cin >> n;
	int m;
	cin >> m;

	for (int i = 0 ; i < m ; i++) {
		int x , y;
		cin >> x >> y;
		gr[x].push_back(y);
	}
	if (toposort() == 0) {
		cout << "Sandro fails." << endl;
		return 0;
	}


	vector<int> ans(n + 1);


	for (int i = 0 ; i < n ; i++) {
		ans[order[i]] = i + 1;
	}

	for (int i = 1 ; i <= n ; i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}


int main() {
#ifdef LOCAL
	freopen("/home/sammy/Documents/sublimeCode/input.txt", "r", stdin);
	//freopen("/home/sammy/Documents/sublimeCode/output.txt", "w", stdout);
#endif
	solve();

	return 0 ;
}
