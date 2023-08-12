#include<bits/stdc++.h>
using namespace std;

/*
Q: Given an Array convert that array to a heap. (max)
(We can't use an extra array)

Every sorted array must be a heap(max or min) but not
every heap might be sorted array
*/

//O(nlogn)

#define ll long long
#define endl '\n'

class MaxHeap {
	vector<int> hp;
	int i;

	void upheapify(int ci) {
		while (ci > 0) {
			int pi = (ci - 1) / 2;
			if (hp[pi] < hp[ci]) {
				swap(hp[pi], hp[ci]);
				ci = pi;
			}
			else {
				break;
			}
		}
	}
	void downheapify(int idx) {
		while (idx < hp.size()) {
			int lc = 2 * idx + 1;
			int rc = 2 * idx + 2;
			if (lc >= hp.size()) break; //idx-> leaf
			int maxEl = idx;
			if (hp[lc] > hp[maxEl]) {
				maxEl = lc;
			}
			if (rc < hp.size() && hp[rc] > hp[maxEl]) {
				maxEl = rc;
			}
			if (maxEl != idx) {
				swap(hp[idx], hp[maxEl]);
				idx = maxEl;
			}
			else break;
		}
	}
public:
	void pop() {
		//removes the highest priority element
		if (empty()) return;
		swap(hp[0], hp[hp.size() - 1]);
		hp.pop_back();
		if (!empty()) downheapify(0);
	}

	int peek() {
		if (empty()) return INT_MIN;
		return hp[0];
	}
	void push(int element) {
		hp.push_back(element);
		upheapify(hp.size() - 1);
	}
	bool empty() {
		return hp.size() == 0;
	}
	void display() {
		cout << "[";
		for (int i = 0; i < hp.size(); i++) {
			cout << hp[i] << ",";
		}
		cout << "]" << endl;
	}

	MaxHeap(vector<int> v) {
		hp = v;
		for (int i = 1; i < hp.size(); i++) {
			upheapify(i);
		}
	}
};

void init() {
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

void solve() {

}

int main() {

	init();

	vector<int> v = {9, 6, 1, 19, 3, 2, 8, 12, 5};
	MaxHeap hp(v);
	hp.display();
	hp.push(100);
	hp.display();

	return 0;
}