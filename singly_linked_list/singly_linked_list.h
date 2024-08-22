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
int length(Node* head);
void deleteList(Node** head_ref);

#endif // SINGLYLINKEDLIST_H
