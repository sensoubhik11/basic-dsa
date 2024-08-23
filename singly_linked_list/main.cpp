#include "singly_linked_list.h"
/* For compilation : 
 * $ g++ -o sll.out main.cpp singly_linked_list.cpp
 * sll.out is the executable
 * To run :
 * $ ./sll.out
 * To detect memory leaks, compile in this way
 * $ g++ -o sll.out main.cpp singly_linked_list.cpp -fsanitize=address -fsanitize=undefined
*/

int main() {
    Node* head = NULL;

    //Section 1: Insertion Functions
    std::cout<<"Demonstrating Insertion Functions\n";
    std::cout<<"-----------------------------\n";
    for (int i=1; i<6; i++)
        push(&head, i*7);   //Inserts at the beginning

    append(&head, 17);        //Inserts at the end
    head = append_recursive(head, 29);   //Recursive insert at the end
    append_recursive2(&head, 23);        //Another recursive insert at the end

    print(head);    //Print the list
    std::cout<<"Length is "<<length(head)<<"\n";
    std::cout<<"-----------------------------\n\n";

    //Section 2: Reversal Functions
    std::cout<<"Demonstrating Reversal Functions\n";
    std::cout<<"-----------------------------\n";
    head = reverseList_recursive(head);  //Recursive reversal
    print(head);

    reverseList(&head);  //Iterative reversal
    print(head);
    std::cout<<"-----------------------------\n\n";

    //Section 3: Deletion Functions
    std::cout<<"Demonstrating Deletion Functions\n";
    std::cout<<"-----------------------------\n";
    deleteList(&head);    // Delete entire list
    print(head);
    std::cout<<"-----------------------------\n\n";

    //Section 4: Loop Detection and Removal
    std::cout<<"Demonstrating Loop Detection and Removal\n";
    std::cout<<"-----------------------------\n";
    Node* head2 = new Node(13);
    head2->next = new Node(17);
    head2->next->next = new Node(19);
    head2->next->next->next = new Node(23);
    head2->next->next->next->next = head2->next->next;    // Creating a loop

    detectLoop(head2) ? std::cout<<"Loop exists\n" : std::cout<<"Loop doesn't exist\n";
    if (detectLoop(head2))
        removeLoop(head2);

    detectLoop(head2) ? std::cout<<"Loop exists\n" : std::cout<<"Loop doesn't exist\n";
    print(head2);
    std::cout<<"-----------------------------\n\n";

    //Section 5: Searching and Node Deletion
    std::cout<<"Demonstrating Searching and Node Deletion\n";
    std::cout<<"-----------------------------\n";
    std::cout<<"Deleting node having value 19\n";
    head2 = deleteNode_recursive(head2, 19);
    print(head2);

    search(head2, 17) ? std::cout<<"Found 17\n" : std::cout<<"17 not found\n";
    search_recursive(head2, 23) ? std::cout<<"Found 23\n" : std::cout<<"23 not found\n";
    std::cout<<"-----------------------------\n\n";

    // Section 6: Reverse Printing Functions
    std::cout<<"Demonstrating Reverse Printing Functions\n";
    std::cout<<"-----------------------------\n";
    printReverse(head2);           // Iterative reverse print
    printReverse_recursive(head2); // Recursive reverse print
    std::cout<<"\n-----------------------------\n\n";

    // Clean up
    deleteList_recursive2(head2);
    head2=NULL;

    return 0;
}
