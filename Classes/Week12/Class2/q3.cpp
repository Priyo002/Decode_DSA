#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> arr = {1, 3, 6, 7, 8, 9, 10};

	int idx1 = -1;
	int idx2 = -1;

	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			if (idx1 == -1) {
				idx1 = i;
			}
			else {
				idx2 = i + 1;
			}
		}
	}
	swap(arr[idx1], arr[idx2]);
	for (auto i : arr) {
		cout << i << " ";
	}

}