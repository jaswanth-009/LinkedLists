#include<iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;

	Node() {
		val = 0;
		next = NULL;
	}

	Node(int x) {
		val = x;
		next = NULL;
	}
};


class LinkedList {
public:
	Node* head;
	LinkedList() {
		head = NULL;
	}
	void insertNode(int x);
	void printList();
};

void LinkedList::insertNode(int x) {
	Node* newNode = new Node();
	newNode->val = x;
	newNode->next = NULL;

	if(head == NULL) {
		head = newNode;
		return;
	}

	newNode->next = head;
	head = newNode;
}

void LinkedList::printList() {
	Node* temp = head;
	while(temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << "\n";
}

void addLists(Node* a, Node* b) {
	
	LinkedList l = LinkedList();

	if(a == NULL && b == NULL) return;
	if(a == NULL) return;
	if(b == NULL) return;;

	int carry = 0;

	while(a != NULL || b != NULL || carry != 0) {

		int sum = 0;

		if(a != NULL) {
			sum += a->val;
			a = a->next;
		}

		if(b != NULL) {
			sum += b->val;
			b = b->next;
		}

		sum += carry;

		carry = sum/10;

		l.insertNode(sum%10);

	}

	l.printList();
}

void printListGlobal(Node* head) {
	Node* temp = head;
	while(temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}

	cout << "\n";
}

int main() {

	LinkedList l1 = LinkedList();
	LinkedList l2 = LinkedList();

	l1.insertNode(9);
	l1.insertNode(9);
	l1.insertNode(9);


	l2.insertNode(6);
	l2.insertNode(5);
	l2.insertNode(4);

	l1.printList();
	l2.printList();

	addLists(l1.head, l2.head);
}
