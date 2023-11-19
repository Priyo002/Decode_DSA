#include<bits/stdc++.h>
using namespace std;

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

int find(vector<int>&parent, int x) {
	//This method returns which group/cluster x belongs to
	if (parent[x] == x) return x;
	return parent[x] = find(parent, parent[x]);
}

bool Union(vector<int>& parent, vector<int>& rank, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);
	if (a == b) return true;//cycle detected
	if (rank[a] >= rank[b]) {
		rank[a]++;
		parent[b] = a;
	}
	else {
		rank[b]++;
		parent[a] = b;
	}
	return false;
}


int main() {

	init();
	//T.C. -> O(log*n)

	int n, m;
	cin >> n >> m;
	// n -> elements, m-> no. of queries;
	vector<int> parent(n + 1), rank(n + 1, 0);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		//Edge list is given
		int x, y;
		cin >> x >> y;
		bool b = Union(parent, rank, x, y);
		if (b) {
			cout << "Cycle Detected" << endl;
			break;
		}

	}

	return 0;
}