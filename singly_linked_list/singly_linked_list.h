#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include<iostream>

class Node {
  public:
  int data;
  Node* next;
  
  Node(int x = 0):data{x}, next{NULL}{}
};

//Function Declarations
void push(Node** head_ref, int data);

void append(Node** head_ref, int data);
Node* append_recursive(Node* head, int data);
void append_recursive2(Node** head_ref, int data);

void print(Node* head);
void print_recursive(Node* head);
void printReverse(Node* head);
void printReverse_recursive(Node* head);

int length(Node* head);
int length_recursive(Node* head);

void reverseList(Node** head_ref);
Node* reverseList_recursive(Node* head);

int secondMiddle(Node* head);

//Floyd Cycle Detection Algorithm
bool detectLoop(Node* head);
void removeLoop(Node* head);

bool search(Node* head, int target);
bool search_recursive(Node* head, int target);

void deleteNode(Node** head_ref, int target);
Node* deleteNode_recursive(Node* head, int target);

void deleteList(Node** head_ref);
void deleteList_recursive(Node* head);
void deleteList_recursive2(Node* head);

#endif // SINGLYLINKEDLIST_H
