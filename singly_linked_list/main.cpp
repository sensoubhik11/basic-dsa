#include "singly_linked_list.h"
/* For compilation : 
 * $ g++ -o sll.out main.cpp singly_linked_list.cpp
 * sll.out is the executable
 * To run :
 * $ ./sll.out
*/

int main() {
  Node* head = NULL;
  
  for(int i=1; i<6; i++)
    push(&head, i*7);
  print(head);
  
  append(&head, 17);
  print(head);
  
  head = append_recursive(head, 29);
  append_recursive2(&head, 23);
  print(head);
  
  std::cout << "Length is " << length(head) << "\n";
  
  deleteList(&head);
  print(head);
  
  return 0;
}
