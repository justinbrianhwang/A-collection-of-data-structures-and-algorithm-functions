#pragma once
#define EMPTY NULL 
# define true 1
#define false 0
#include <stdio.h>
#include <stdlib.h>


/*
English
This header file is a header file that organizes linked list functions. 
If you want to use it, please cite the source, write the code, 
and leave the usage method for each function. 
I think it would be good if you use it appropriately.

Korean
이 헤더 파일은 연결리스트 함수를 정리한 헤더파일입니다. 
이를 이용하시려면, 출처를 밝혀서, 코드를 작성하시고, 
각 함수별로 사용방법도 남겼습니다. 
이를 적절히 잘 사용하시면 좋을 것 같습니다.
*/


// Data characteristics
/*
You can change this to any variable other than an integer. I wrote it as an integer for convenience.
이는 정수형 변수가 아닌 다른 변수들로 알아서 바꾸시면 됩니다. 저는 편의를 위해 정수형으로 작성했습니다.
*/

typedef int Data; 

// Node 
typedef struct Node {
	Data data;
	struct Node* link; // Next address
} LinkedList;

// making Node finction
LinkedList* newNode();

// add Node fuction
void addNode(LinkedList** head, Data data);

// compare Data
int compareData(Data d1, Data d2);

// A function that finds the data and inserts it after the node.
void InsertNode(LinkedList** head, Data finddata, Data insertdata);

// printing LinkedList
// Please change this function appropriately.
void printNode(LinkedList** head);

// delete Node
void deleteNode(LinkedList** head, Data deletedata);

// searching function
LinkedList* searchNode(LinkedList* head, Data searchdata);

// List length 
int listLength(LinkedList* head);

// reverse printing
void printReverse(LinkedList* head);

// clear List
void clearList(LinkedList** head);

// A function that inserts a node at a specific location.
void insertAtPosition(LinkedList** head, Data data, int position);

// A function that merges two lists.
LinkedList* mergeLists(LinkedList* list1, LinkedList* list2);

// A function that splits a list into two.
void splitList(LinkedList* head, LinkedList** front, LinkedList** back);

// A function that sorts a list.
void sortList(LinkedList** headRef);

// A function that finds the middle node of a list.
LinkedList* findMiddleNode(LinkedList* head);
