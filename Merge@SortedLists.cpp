#include<iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;
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

Node* mergedists(Node* head1, Node* head2) {
	Node* newNode = NULL;
	Node* temp = newNode;

	if(head1 == NULL && head2 == NULL) {
		return newNode;
	}

	if(head1->val < head2->val){
		newNode = head1;
		head1 = head1->next;
	} else {
		newNode = head2;
		head2 = head2->next;
	}

	temp = newNode;

	while(head1 != NULL && head2 != NULL){
		if(head1->val < head2->val){
			newNode->next = head1;
			head1 = head1->next;
		} else {
			newNode->next = head2;
			head2 = head2->next;
		}
		newNode = newNode->next;
	}

	while(head1 != NULL) {
		newNode->next = head1;
		head1 = head1->next;
		newNode = newNode->next;
	}

	while(head2 != NULL) {
		newNode->next = head2;
		head2 = head2->next;
		newNode = newNode->next;
	}

	return temp;
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

	l1.insertNode(5);
	l1.insertNode(3);
	l1.insertNode(1);

	l2.insertNode(6);
	l2.insertNode(4);
	l2.insertNode(2);

	l1.printList();
	l2.printList();


	Node* newHead = mergedists(l1.head, l2.head);

	if(newHead != NULL){
		printListGlobal(newHead);
	} else {
		cout << "mergedist is Empty\n";
	}
}
