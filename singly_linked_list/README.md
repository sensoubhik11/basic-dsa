# Singly Linked List

Implementation of a singly linked list in C++ with various operations, including both iterative and recursive versions of the functions.

## Files

- **`singly_linked_list.h`**: This header file contains declarations of the `Node` class and functions related to the singly linked list.
- **`singly_linked_list.cpp`**: Contains the implementations (definitions) of the functions declared in the header file.
- **`main.cpp`**: The entry point of the program. It demonstrates the usage of the functions.

## How to Compile?

- Open a terminal in this directory and run:
  ```bash
  g++ -o sll.out main.cpp singly_linked_list.cpp
  ```
- `sll.out` is the executable. Run it.
  ```bash
  ./sll.out
  ```

#### For detecting buffer overflows, memory leaks, etc. Use this command
  ```bash
  g++ -o sll.out main.cpp singly_linked_list.cpp -fsanitize=address -fsanitize=undefined
  ```

## Functions

### 1. Basic Operations

- **`void push(Node** head_ref, int data);`**
  - Description: Inserts a node at the beginning of the list.
  - TC: O(1), SC: O(1)

- **`void append(Node** head_ref, int data);`**
  - Description: Appends a node at the end of the list.
  - TC: O(n), SC: O(1)

- **`Node* append_recursive(Node* head, int data);`**
  - Description: Recursively appends a node at the end of the list.
  - TC: O(n), SC: O(n) (due to recursion stack)

- **`void append_recursive2(Node** head_ref, int data);`**
  - Description: Recursively appends a node at the end of the list using a double pointer.
  - TC: O(n), SC: O(n) (due to recursion stack)

### 2. Printing the List

- **`void print(Node* head);`**
  - Description: Iteratively prints all elements in the list.
  - TC: O(n), SC: O(1)

- **`void print_recursive(Node* head);`**
  - Description: Recursively prints all elements in the list.
  - TC: O(n), SC: O(n) (due to recursion stack)

- **`void printReverse(Node* head);`**
  - Description: Iteratively prints the list in reverse order.
  - TC: O(n), SC: O(n)

- **`void printReverse_recursive(Node* head);`**
  - Description: Recursively prints the list in reverse order.
  - TC: O(n), SC: O(n) (due to recursion stack)

### 3. Length of the List

- **`int length(Node* head);`**
  - Description: Iteratively calculates the length of the list.
  - TC: O(n), SC: O(1)

- **`int length_recursive(Node* head);`**
  - Description: Recursively calculates the length of the list.
  - TC: O(n), SC: O(n) (due to recursion stack)

### 4. Reversing the List

- **`void reverseList(Node** head_ref);`**
  - Description: Reverses the list iteratively.
  - TC: O(n), SC: O(1)

- **`Node* reverseList_recursive(Node* head);`**
  - Description: Recursively reverses the list.
  - TC: O(n), SC: O(n) (due to recursion stack)

### 5. Middle and Loop Detection

- **`int secondMiddle(Node* head);`**
  - Description: Finds the second middle element in the list.
  - TC: O(n), SC: O(1)

- **`bool detectLoop(Node* head);`**
  - Description: Detects a loop in the list using Floyd’s Cycle-Finding Algorithm.
  - TC: O(n), SC: O(1)

- **`void removeLoop(Node* head);`**
  - Description: Removes a loop in the list if present.
  - TC: O(n), SC: O(1)

### 6. Searching

- **`bool search(Node* head, int target);`**
  - Description: Iteratively searches for a value in the list.
  - TC: O(n), SC: O(1)

- **`bool search_recursive(Node* head, int target);`**
  - Description: Recursively searches for a value in the list.
  - TC: O(n), SC: O(n) (due to recursion stack)

### 7. Deletion

- **`void deleteNode(Node** head_ref, int target);`**
  - Description: Deletes a node containing the target value.
  - TC: O(n), SC: O(1)

- **`Node* deleteNode_recursive(Node* head, int target);`**
  - Description: Recursively deletes a node containing the target value.
  - TC: O(n), SC: O(n) (due to recursion stack)

- **`void deleteList(Node** head_ref);`**
  - Description: Iteratively deletes the entire list.
  - TC: O(n), SC: O(1)

- **`void deleteList_recursive(Node* head);`**
  - Description: Recursively deletes the entire list.
  - TC: O(n), SC: O(n) (due to recursion stack)

- **`void deleteList_recursive2(Node* head);`**
  - Description: Another recursive approach to delete the entire list.
  - TC: O(n), SC: O(n) (due to recursion stack)
