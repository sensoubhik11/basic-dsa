#include "singly_linked_list.h"

//Function Definitions

//TC = O(1), SC = O(1)
void push(Node** head_ref, int data) {
  Node* new_node = new Node(data);
  if(*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  
  new_node->next = *head_ref;
  *head_ref = new_node;
}

//TC = O(n), SC = O(1)
void append(Node** head_ref, int data) {
  Node* new_node = new Node(data);
  if(*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  
  Node* current = *head_ref;
  while(current->next != NULL)
    current = current->next;
  
  current->next = new_node;
}

//TC = O(n), SC = O(1)
Node* append_recursive(Node* head, int data) {
  if(head == NULL) {
    return new Node(data);
  }

  head->next = append_recursive(head->next, data);
  return head;
}

void append_recursive2(Node** head_ref, int data) {
  if(*head_ref == NULL) {
    *head_ref = new Node(data);
    return;
  }
  
  return append_recursive2(&((*head_ref)->next), data);
}


//TC = O(n), SC = O(1)
void print(Node* head) {
  while(head != NULL) {
    std::cout << head->data << "->";
    head = head->next;
  }
  std::cout << "NULL\n";
}

//TC = O(n), SC = O(1)
int length(Node* head) {
  int len = 0;
  Node* current = head;
  while(current != NULL) {
    len++;
    current = current->next;
  }
  return len;
}

//TC = O(n), SC = O(1)
void deleteList(Node** head_ref) {
  Node* current = *head_ref;
  while(current != NULL) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  *head_ref = NULL;
}
