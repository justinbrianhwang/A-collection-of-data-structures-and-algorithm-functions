#include "LinkedList.h"

LinkedList* newNode() {
	LinkedList* tmp;
	tmp = (LinkedList*)malloc(sizeof(LinkedList));
	tmp->link = EMPTY;
	return tmp;
}
void addNode(LinkedList** head, Data data) {
	// If the head node is empty, it means the nodes are still empty.
	if ((*head) == EMPTY) {
		LinkedList* tmp = newNode();
		tmp->data = data;
		*head = tmp;
	}
	else {
		addNode(&((*head)->link), data);
	}
}
int compareData(Data d1, Data d2) {
	if (d1 == d2)
		return true;
	else
		return false;

}
void InsertNode(LinkedList** head, Data finddata, Data insertdata) {
	// If found!
	if (compareData(finddata, insertdata)) {
		LinkedList* tmp = newNode();
		tmp->data = insertdata;
		tmp->link = (*head)->link;
		(*head)->link = tmp;
	}
	// If there is no such node itself
	else if ((*head)->link == EMPTY) {
		printf("There is no such node.\n");
	}
	// If the node has not been discovered yet
	else {
		InsertNode(&((*head)->link), finddata, insertdata);
	}

}
void printNode(LinkedList** head) {
	if ((*head) == EMPTY) {
		return;
	}
	else {
		printf("%d ", (*head)->data); 
		printNode(&((*head)->link));
	}
}
void deleteNode(LinkedList** head, Data deletedata) {
	if ((*head) == EMPTY) {
		printf("The node does not exist.\n");
		return;
	}

	if (compareData((*head)->data, deletedata)) {
		LinkedList* tmp = *head; // temporary pointer
		*head = (*head)->link;
		free(tmp);
	}
	else {
		deleteNode(&((*head)->link), deletedata);
	}
}
LinkedList* searchNode(LinkedList* head, Data searchdata) {
	if (head == EMPTY) {
		return NULL;
	}

	if (compareData(head->data, searchdata)) {
		return head;
	}
	return searchNode(head->link, searchdata);
}
int listLength(LinkedList* head) {
	if (head == EMPTY)
		return 0;
	return 1 + listLength(head->link);
}
void printReverse(LinkedList* head) {
	if (head == EMPTY) {
		return;
	}
	printReverse(head->link);
	printf("%d ", head->data);
}
void clearList(LinkedList** head) {
	while (*head != EMPTY) {
		deleteNode(head, (*head)->data);
	}
}
void insertAtPosition(LinkedList** head, Data data, int position) {
	if (position < 0) {
		printf("Invalid position.\n");
		return;
	}

	if (position == 0) {
		LinkedList* new_node = newNode();
		new_node->data = data;
		new_node->link = *head;
		*head = new_node;
		return;
	}

	LinkedList* current = *head;
	for (int i = 0; i < position - 1 && current != NULL; i++) {
		current = current->link;
	}

	if (current == NULL) {
		printf("Position out of bounds.\n");
		return;
	}

	LinkedList* new_node = newNode();
	new_node->data = data;
	new_node->link = current->link;
	current->link = new_node;
}
LinkedList* mergeLists(LinkedList* list1, LinkedList* list2) {
	if (list1 == EMPTY) return list2;
	if (list2 == EMPTY) return list1;

	LinkedList* head = EMPTY;
	LinkedList** lastPtrRef = &head;

	while (list1 != EMPTY && list2 != EMPTY) {
		if (compareData(list1->data, list2->data) <= 0) {
			*lastPtrRef = list1;
			list1 = list1->link;
		}
		else {
			*lastPtrRef = list2;
			list2 = list2->link;
		}
		lastPtrRef = &((*lastPtrRef)->link);
	}

	if (list1 != EMPTY) {
		*lastPtrRef = list1;
	}
	else {
		*lastPtrRef = list2;
	}

	return head;
}
void splitList(LinkedList* head, LinkedList** front, LinkedList** back) {
	if (head == EMPTY || head->link == EMPTY) {
		*front = head;
		*back = EMPTY;
		return;
	}

	LinkedList* slow = head;
	LinkedList* fast = head->link;

	while (fast != EMPTY) {
		fast = fast->link;
		if (fast != EMPTY) {
			slow = slow->link;
			fast = fast->link;
		}
	}

	*front = head;
	*back = slow->link;
	slow->link = EMPTY;
}
void sortList(LinkedList** headRef) {
	LinkedList* head = *headRef;
	if (head == EMPTY || head->link == EMPTY) {
		return;
	}

	LinkedList* a;
	LinkedList* b;

	splitList(head, &a, &b);

	sortList(&a);
	sortList(&b);

	*headRef = mergeLists(a, b);
}
LinkedList* findMiddleNode(LinkedList* head) {
	if (head == EMPTY) return EMPTY;

	LinkedList* slow = head;
	LinkedList* fast = head;

	while (fast != EMPTY && fast->link != EMPTY) {
		slow = slow->link;
		fast = fast->link->link;
	}

	return slow;
}

