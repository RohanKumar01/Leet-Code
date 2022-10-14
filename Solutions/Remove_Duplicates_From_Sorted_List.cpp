#include <bits/stdc++.h>
using namespace std;


class Node
{
	public:
	int data;
	Node* next;
};


void removeDuplicates(Node* head)
{
	
	Node* current = head;

	
	Node* next_next;
	
	
	if (current == NULL)
	return;

	
	while (current->next != NULL)
	{
	
	if (current->data == current->next->data)
	{
			
		next_next = current->next->next;
		free(current->next);
		current->next = next_next;
	}
	else 
	{
		current = current->next;
	}
	}
}


void push(Node** head_ref, int new_data)
{
	
	Node* new_node = new Node();
			
	
	new_node->data = new_data;
				
	
	new_node->next = (*head_ref);	
		
	
	(*head_ref) = new_node;
}

void print(Node *node)
{
	while (node!=NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

/* Driver program to test above functions*/
int main()
{
	
	Node* head = NULL;
	
	
	push(&head, 25);
	push(&head, 19);
	push(&head, 19);
	push(&head, 12);
	push(&head, 12);
	push(&head, 12);									

	cout<<"Before removal of elements ";
	print(head);


	removeDuplicates(head);

	cout<<"\nAfter removal of elements ";	
	print(head);			
	
	return 0;
}


