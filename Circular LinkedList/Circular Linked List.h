#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef int Data;

typedef struct CircularSinglyLinkedList {
    Data data;
    struct CircularSinglyLinkedList* next;  // Next node
} CircularSinglyLinkedList;

// Function to create a new node
CircularSinglyLinkedList* newNode(Data data);

// Function to add a node to the end of the list
void addNode(CircularSinglyLinkedList** head, Data data);

// Function to compare data
int compareData(Data d1, Data d2);

// Function to insert a node after a specific data
void insertAfter(CircularSinglyLinkedList* head, Data findData, Data insertData);

// Function to delete a node
void deleteNode(CircularSinglyLinkedList** head, Data deleteData);

// Function to print the list
void printList(CircularSinglyLinkedList* head);

// Function to print the list in reverse order
void printReverseList(CircularSinglyLinkedList* head);

// Function to search for a node
CircularSinglyLinkedList* searchNode(CircularSinglyLinkedList* head, Data searchData);

// Function to calculate the length of the list
int listLength(CircularSinglyLinkedList* head);

// Function to clear the list
void clearList(CircularSinglyLinkedList** head);

// Function to insert a node at a specific position
void insertAtPosition(CircularSinglyLinkedList** head, Data data, int position);

// Function to merge two lists
CircularSinglyLinkedList* mergeLists(CircularSinglyLinkedList* list1, CircularSinglyLinkedList* list2);

// Function to split a list into two halves
void splitList(CircularSinglyLinkedList* head, CircularSinglyLinkedList** front, CircularSinglyLinkedList** back);

// Function to sort the list
void sortList(CircularSinglyLinkedList** headRef);
