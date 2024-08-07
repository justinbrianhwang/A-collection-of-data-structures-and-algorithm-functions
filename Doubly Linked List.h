#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct DoublyLinkedList {
    Data data;
    struct DoublyLinkedList* Llink;  // prevNode
    struct DoublyLinkedList* Rlink;  // nextnode
} DoublyLinkedList;


// Function to create a new node
DoublyLinkedList* newNode(Data data);

// Function to add a node to the end of the list
void addNode(DoublyLinkedList** head, Data data);


// Function to compare data
int compareData(Data d1, Data d2);


// Function to insert a node after a specific data
void insertAfter(DoublyLinkedList* head, Data findData, Data insertData);


// Function to delete a node
void deleteNode(DoublyLinkedList** head, Data deleteData);


// Function to print the list
void printList(DoublyLinkedList* head);


// Function to print the list in reverse order
void printReverseList(DoublyLinkedList* head);

// Function to search for a node
DoublyLinkedList* searchNode(DoublyLinkedList* head, Data searchData);

// Function to calculate the length of the list
int listLength(DoublyLinkedList* head);

// Function to clear the list
void clearList(DoublyLinkedList** head);

// Function to insert a node at a specific position
void insertAtPosition(DoublyLinkedList** head, Data data, int position);

// Function to merge two lists
DoublyLinkedList* mergeLists(DoublyLinkedList* list1, DoublyLinkedList* list2);

// Function to split a list into two halves
void splitList(DoublyLinkedList* head, DoublyLinkedList** front, DoublyLinkedList** back);

// Function to sort the list
void sortList(DoublyLinkedList** headRef);