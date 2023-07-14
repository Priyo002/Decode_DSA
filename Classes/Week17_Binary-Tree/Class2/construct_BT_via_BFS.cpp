#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node *left;
	Node *right;
	Node(int val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

Node* construct(int arr[], int n) {
	queue<Node*> q;
	Node * root = new Node(arr[0]);
	q.push(root);
	int i = 1;
	int j = 2;
	while (q.size() && i < n) {
		Node* temp = q.front();
		q.pop();
		Node* l;
		Node* r;
		if (arr[i] != INT_MIN) l = new Node(arr[i]);
		else l = NULL;

		if (j != n && arr[j] != INT_MIN) r = new Node(arr[j]);
		else r = NULL;

		temp->left = l;
		temp->right = r;

		if (l) q.push(l);
		if (r) q.push(r);

		i += 2;
		j += 2;
	}
	return root;
}

void LevelOrder_Queue(Node *root) {//BFS
	queue<Node*> q;
	q.push(root);
	while (q.size()) {
		Node* temp = q.front();
		q.pop();
		cout << temp->val << " ";

		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right)
			q.push(temp->right);

	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9};
	int n = sizeof(arr) / sizeof(int);
	//construct
	Node* root = construct(arr, n);

	LevelOrder_Queue(root);


}