#include<iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;
};

class LinkedList {
public:
	Node *head;
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

Node* intersection(Node* head1, Node* head2) {
	Node* a = head1;
	Node* b =  head2;

	while(a!=b) {
		a = (a==NULL)?head2:a->next;
		b = (b==NULL)?head1:b->next;
	}

	if(a == NULL && b == NULL) {
		cout << "No common node\n";
		return NULL;
	}

	return a;
}

int main() {
	LinkedList l1 = LinkedList();
	LinkedList l2 = LinkedList();
	l1.insertNode(1);
	l1.insertNode(2);
	l1.insertNode(3);
	l1.insertNode(4);
	l1.insertNode(5);
	l1.insertNode(6);
	l1.insertNode(7);

	l2.insertNode(10);
	l2.insertNode(9);
	l2.insertNode(8);
	l2.head->next->next->next = l1.head->next->next;

	l1.printList();
	l2.printList();

	Node* common = intersection(l1.head, l2.head);
	if(common != NULL){
		cout << common->val << " ";
	}
	
	return 0;
}
