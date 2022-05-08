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

Node* middleNodeOptimized(Node* head) {
	Node* slowTortoise = head;
	Node* fastTortoise = head;

	while((fastTortoise != NULL) && (fastTortoise->next != NULL)) {
		fastTortoise = fastTortoise->next->next;
		slowTortoise = slowTortoise->next;
	}

	return slowTortoise;
}

Node* middleNodeNaive(Node* head_ref) {
	int count = 0;
	int middle;
	Node* temp = head_ref;
	while(temp != NULL) {
		temp = temp->next;
		count++;
	}
	temp = head_ref;

	middle = (count/2) + 1;

	for(int i = 1;i<middle;i++) {
		temp = temp->next;
	}

	return temp;
}

int main() {
	Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	printList(head);
	Node* middle = middleNodeOptimized(head);
	//cout << middle->val << "\n";

}
