#pragma once
#include <stdio.h>
#include <stdlib.h>
// For constants, you can also change them as you wish.
#define INITIAL_CAPACITY 4

// Please change the data appropriately.
typedef int Data; 

typedef struct {
	Data* array;
	int size;
	int capacity;
} ArrayList;

// This is a function that initializes an array list.
ArrayList* createArrayList();

// Array list size increase function
void resizeArrayList(ArrayList* list);

// Function to add elements to an array list
void addElement(ArrayList* list, Data data);

// Function to insert an element at a specific position in an array list
void insertElementAt(ArrayList* list, int index, Data data);

// Function to delete an element at a specific position in an array list
void removeElementAt(ArrayList* list, int index);

// Function to search for elements in an array list
int searchElement(ArrayList* list, Data data);

// Array list output function
void printArrayList(ArrayList* list);

// Array list memory freeing function
void freeArrayList(ArrayList* list);
