#include<iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;
};

void push(Node** head_ref, int x){
	Node* newNode = new Node();
	newNode->val = x;
	newNode->next = NULL;

	if(*head_ref == NULL){
		*head_ref = newNode;
		return;
	}
	newNode->next = *head_ref;
	*head_ref = newNode;
}

void append(Node** head_ref, int x){
	Node* newNode = new Node();
	newNode->val = x;
	newNode->next = NULL;

	Node* temp = *head_ref;

	if(*head_ref == NULL){
		*head_ref = newNode;
		return;
	}

	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = newNode;
}

void printList(Node* head){
	Node* newNode = head;
	while(newNode != NULL){
		cout << newNode->val << " ";
		newNode = newNode->next;
	}
	cout << "\n";
}

Node* reverseList(Node* head){
	Node* dummy = NULL;
	while(head != NULL){
		Node* next = head->next;
		head->next =  dummy;
		dummy = head;
		head = next;
	}
	return dummy;
}

int main() {
	Node* head = NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	printList(head);
	head = reverseList(head);
	printList(head);

}
