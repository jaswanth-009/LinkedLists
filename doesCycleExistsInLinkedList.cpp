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

void doesCycleExist(Node* head) {
	Node* slow = head;
	Node* fast = head;

	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast) {
			cout << "Exists\n";
			return;
		}
	}

	if(fast == NULL || fast->next == NULL) {
		cout << "No cycle\n";
	}
}


int main(){
LinkedList l1 = LinkedList();

l1.insertNode(1);
l1.insertNode(2);
l1.insertNode(3);
l1.insertNode(4);
l1.insertNode(5);

//l1.head->next->next->next->next->next = l1.head;

doesCycleExist(l1.head);

}
