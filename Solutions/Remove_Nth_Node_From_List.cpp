#include <bits/stdc++.h>
using namespace std;
 
class RemoveNth {
public:

    class Node {
    public:
        int data;
        Node* next;
        Node(int d)
        {
            data = d;
            next = NULL;
        }
    };
 
    
    Node* head;
 
   
    Node* deleteNode(int key)
    {
       
        Node* temp;
 
        Node* first = head;
 
        Node* second = head;
        for (int i = 0; i < key; i++) {
            
            if (second->next == NULL) {
                
                if (i == key - 1) {
                    temp = head;
                    head = head->next;
                    free(temp);
                }
                return head;
            }
            second = second->next;
        }
 
        while (second->next != NULL) {
            first = first->next;
            second = second->next;
        }
  
        temp = first->next;
        first->next = first->next->next;
        free(temp);
        return head;
    }
 

    Node* push(int new_data)
    {
        Node* new_node = new Node(new_data);
        new_node->next = head;
        head = new_node;
        return head;
    }
 
    
    void print()
    {
        Node* hnode = head;
        while (hnode != NULL) {
            cout << (hnode->data) << (" ");
            hnode = hnode->next;
        }
    }
};
 

int main()
{
    RemoveNth* list = new RemoveNth();
 
    list->head = list->push(6);
    list->head = list->push(4);
    list->head = list->push(3);
    list->head = list->push(5);
 
    cout << ("Created Linked list :\n");
    list->print();
 
    int N = 1;
    list->head = list->deleteNode(N);
 
    cout << ("\nList after Deletion :\n");
    list->print();
}