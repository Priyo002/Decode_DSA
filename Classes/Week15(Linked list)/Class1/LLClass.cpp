#include<bits/stdc++.h>
using namespace std;

class Node { //User defined data type
public:
	int val;
	Node *next;
	Node(int val) {
		this->val = val;
		this->next = NULL;
	}
};

class linkedList { //User defined data structure
public:
	Node* head ;
	Node* tail ;
	int size;
	linkedList() {
		head = tail = NULL;
		size = 0;
	}
	void insertAtBegining(int val) {
		Node * temp = new Node(val);
		if (size == 0) head = temp;
		else {
			temp -> next = head;
			head = temp;
		}
		size++;
	}
	void insertAtEnd(int val) {
		Node* temp = new Node(val);
		if (size == 0) head = tail = temp;
		else {
			tail-> next = temp;
			tail = temp;
		}
		size++;
	}
	void insertAtIdx(int idx, int val) {
		if (idx == 0) insertAtBegining(val);
		else if (idx == size ) insertAtEnd(val);
		else if (idx < 0 || idx > size) {
			cout << "Invalid Index" << endl;
		}

		else {
			Node *t = new Node(val);
			Node *temp = head;
			for (int i = 1; i <= idx - 1; i++) {
				temp = temp->next;
			}
			t->next = temp->next;
			temp->next = t;
			size++;
		}
	}
	int getIdx(int idx) {
		if (idx < 0 || idx >= size) {
			cout << "Invalid Index ";
			return -1;
		}
		else if (idx == 0) return head->val;
		else if (idx == size - 1) return tail->val;
		else {
			Node *temp = head;
			for (int i = 1; i <= idx ; i++) {
				temp = temp -> next;
			}
			return temp->val;
		}
	}
	void deleteAtHead() {
		if (size == 0) cout << "List is Empty!";
		else {
			head = head->next;
			size--;
		}
	}
	void deleteAtTail() {
		if (size == 0) cout << "List is Empty";
		else {
			Node *temp = head;
			while (temp->next != tail) {
				temp = temp->next;
			}
			temp->next = NULL;
			tail = temp;
			size--;
		}
	}
	void deleteAtIdx(int idx) {
		if (idx < 0 || idx >= size) cout << "Invalid Index";
		else if (idx == 0) deleteAtHead();
		else if (idx == size - 1) deleteAtTail();
		else {
			Node *temp = head;
			for (int i = 1; i <= idx - 1; i++) {
				temp = temp->next;
			}
			temp->next = temp->next->next;
			size--;
		}
	}
	void display() {
		Node *temp = head;
		while (temp != NULL) {
			cout << temp->val << " ";
			temp = temp -> next;
		}
		cout << endl;
	}
};
int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	linkedList ll;
	ll.insertAtEnd(10);//{10}
	ll.display();
	ll.insertAtEnd(20);//{10->20}
	ll.display();
	ll.insertAtEnd(30);
	ll.display();
	ll.insertAtBegining(100);
	ll.display();
	ll.insertAtEnd(40);
	ll.display();
	ll.insertAtIdx(2, 90);
	ll.display();
	cout << ll.getIdx(3) << endl;
	cout << ll.getIdx(9) << endl;
	ll.deleteAtHead();
	ll.display();
	ll.deleteAtTail();
	ll.display();
	ll.deleteAtIdx(2);
	ll.display();
}