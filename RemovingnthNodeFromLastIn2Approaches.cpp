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

Node* deleteNthNodeFromLast1(Node* head, int number){
	Node* start = new Node();
	start->next = head;

	Node* fast = start;
	Node* slow = start;

	for(int i=0;i<number;i++) {
		fast = fast->next;
	}

	while(fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
	}

	slow->next = slow->next->next;

	return start->next;

}

Node* deleteNthNodeFromLast2(Node* head, int number) {
	int count = 0;
	Node* temp = head;
	while(temp !=NULL ){
		temp = temp->next;
		count++;
	}
	
	temp = head;

	if(number>count) {
		cout << "Not possible\n";
		return head;
	}

	if(number == count){
		return head->next;
	}

	Node* current = head;
	Node* previous = NULL;
	int required = count - number + 1;
	count = 1;

	while(count != required) {
		previous = current;
		current = current->next;
		count++;
	}

	previous->next = current->next;
	return head;
}

int main() {
	Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	printList(head);
	head = deleteNthNodeFromLast1(head, 5);
	printList(head);
}
