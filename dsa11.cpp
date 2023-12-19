#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertBegin(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void insertAfter(Node* prev_node, int new_data)
{
	if (prev_node == NULL) {
		cout << "The given previous node cannot be NULL";
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}
void insertEnd(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	Node* last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return;
}

void printList(struct Node* node) {
  while (node != NULL) {
  cout << node->data << " ";
  node = node->next;
  }
}

int main(){
    struct Node* head =NULL;
    insertEnd(&head,9);
    insertBegin(&head,8);
    insertAfter(head->next,90);
    insertAfter(head->next,29);
    insertBegin(&head,32);
    insertAfter(head->next,18);
    printList(head);

}


