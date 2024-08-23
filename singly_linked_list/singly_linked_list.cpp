#include "singly_linked_list.h"
#include<stack> //for std::stack

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

//TC = O(n), SC = O(n)
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

//TC = O(n), SC = O(n)
void print_recursive(Node* head) {
  if(head == NULL) {
    std::cout << "NULL\n";
    return;
  }
  std::cout << head->data << "->";
  print_recursive(head->next);
}

void printReverse(Node* head) {
  std::stack<Node*> s;
  while(head!=NULL) {
    s.push(head);
    head = head->next;
  }
  while(!s.empty()) {
    std::cout << s.top()->data << " ";
    s.pop();
  }
  std::cout << "\n"; 
}
void printReverse_recursive(Node* head) {
  if(head == NULL) {
    std::cout << "NULL";
    return;
  }
  printReverse_recursive(head->next);
  std::cout << "<-" << head->data;
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

//TC = O(n), SC = O(n)
int length_recursive(Node* head) {
  if(head == NULL)
    return 0;
  return 1 + length_recursive(head->next);
}

void reverseList(Node** head_ref) {
  if(*head_ref == NULL || (*head_ref)->next == NULL)
    return;
  Node* prev = NULL, *curr = *head_ref;
  while(curr!=NULL) {
    Node* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  *head_ref = prev;
}

//TC = 2n, SC = O(n)
Node* reverseList_recursive(Node* head) {
  if(head == NULL || head->next == NULL)
    return head;

  Node* rest = reverseList_recursive(head->next);
  head->next->next = head;
  head->next = NULL;
  return rest;
}

//T(n) = n/2, SC = O(1)
int secondMiddle(Node* head) {
  Node* slow = head, *fast = head;
  while(fast != NULL && fast->next!= NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

//Floyd Cycle Detection Algorithm
//TC = O(n), SC = O(1)    
bool detectLoop(Node* head) {
  Node* slow = head, *fast = head;
  while(fast != NULL && fast->next!= NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) {
      return true;
    }
  }
  return false;
}

void removeLoop(Node* head) {
  bool isLoop = false;
  Node* slow = head, *fast = head;
  while(fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) {
      isLoop = true;
      break;
    }
  }
  if(isLoop) {
    slow = head;
    while(slow->next != fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    fast->next = NULL;
  }
}

//TC = O(n), SC = O(1)
bool search(Node* head, int target) {
  if(head == NULL) return false;
  
  while(head != NULL) {
    if(head->data == target) return true;
    head = head->next;
  }
  return false;
}
//TC = O(n), SC = O(n)
bool search_recursive(Node* head, int target) {
  if(head == NULL) return false;
  if(head->data == target) return true;
  return search_recursive(head->next, target);
}

void deleteNode(Node** head_ref, int target) {
  if(*head_ref == NULL) {
    std::cout << "List Empty\n";
    return;
  }
  if((*head_ref)->data == target) {
    Node* temp = *head_ref;
    (*head_ref) = (*head_ref)->next;
    delete temp;
    return;
  }
  
  Node* curr = *head_ref;
  while(curr->next != NULL) {
    if(curr->next->data == target) {
      Node* temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
      return;
    }
    curr = curr->next;
  }
}

Node* deleteNode_recursive(Node* head, int target) {
  if(head == NULL) {
    return NULL;
  }
  if(head->data == target) {
    Node* temp = head->next;
    delete head;
    return temp;
  }
  head->next = deleteNode_recursive(head->next, target);
  return head;
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

//TC = O(n), SC = O(n)
void deleteList_recursive(Node* head) {
  if(head == NULL)
      return;
  Node* temp = head->next;
  delete head;
  deleteList_recursive(temp);
}

// T(n) = 2n+1, SC = O(n)
void deleteList_recursive2(Node* head) {
  if(head == NULL)
    return;
  deleteList_recursive2(head->next);
  delete head;
}
