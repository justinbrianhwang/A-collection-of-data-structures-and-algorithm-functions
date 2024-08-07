#include "Doubly Linked List.h"

DoublyLinkedList* newNode(Data data) {
    DoublyLinkedList* tmp = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    tmp->data = data;
    tmp->Llink = NULL;
    tmp->Rlink = NULL;
    return tmp;
}
void addNode(DoublyLinkedList** head, Data data) {
    DoublyLinkedList* tmp = newNode(data);
    if (*head == NULL) {
        *head = tmp;
        return;
    }
    DoublyLinkedList* current = *head;
    while (current->Rlink != NULL) {
        current = current->Rlink;
    }
    current->Rlink = tmp;
    tmp->Llink = current;
}
int compareData(Data d1, Data d2) {
    return d1 == d2;
}
void insertAfter(DoublyLinkedList* head, Data findData, Data insertData) {
    DoublyLinkedList* current = head;
    while (current != NULL && current->data != findData) {
        current = current->Rlink;
    }
    if (current == NULL) {
        printf("Node with data %d not found.\n", findData);
        return;
    }
    DoublyLinkedList* tmp = newNode(insertData);
    tmp->Rlink = current->Rlink;
    tmp->Llink = current;
    if (current->Rlink != NULL) {
        current->Rlink->Llink = tmp;
    }
    current->Rlink = tmp;
}
void deleteNode(DoublyLinkedList** head, Data deleteData) {
    DoublyLinkedList* current = *head;
    while (current != NULL && current->data != deleteData) {
        current = current->Rlink;
    }
    if (current == NULL) {
        printf("Node with data %d not found.\n", deleteData);
        return;
    }
    if (current->Llink != NULL) {
        current->Llink->Rlink = current->Rlink;
    }
    else {
        *head = current->Rlink;
    }
    if (current->Rlink != NULL) {
        current->Rlink->Llink = current->Llink;
    }
    free(current);
}
void printList(DoublyLinkedList* head) {
    DoublyLinkedList* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->Rlink;
    }
    printf("\n");
}
void printReverseList(DoublyLinkedList* head) {
    if (head == NULL) return;
    DoublyLinkedList* current = head;
    while (current->Rlink != NULL) {
        current = current->Rlink;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->Llink;
    }
    printf("\n");
}
DoublyLinkedList* searchNode(DoublyLinkedList* head, Data searchData) {
    DoublyLinkedList* current = head;
    while (current != NULL) {
        if (compareData(current->data, searchData)) {
            return current;
        }
        current = current->Rlink;
    }
    return NULL;
}
int listLength(DoublyLinkedList* head) {
    int length = 0;
    DoublyLinkedList* current = head;
    while (current != NULL) {
        length++;
        current = current->Rlink;
    }
    return length;
}
void clearList(DoublyLinkedList** head) {
    DoublyLinkedList* current = *head;
    while (current != NULL) {
        DoublyLinkedList* next = current->Rlink;
        free(current);
        current = next;
    }
    *head = NULL;
}
void insertAtPosition(DoublyLinkedList** head, Data data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        DoublyLinkedList* new_node = newNode(data);
        new_node->Rlink = *head;
        if (*head != NULL) {
            (*head)->Llink = new_node;
        }
        *head = new_node;
        return;
    }

    DoublyLinkedList* current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->Rlink;
    }

    if (current == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    DoublyLinkedList* new_node = newNode(data);
    new_node->Rlink = current->Rlink;
    new_node->Llink = current;
    if (current->Rlink != NULL) {
        current->Rlink->Llink = new_node;
    }
    current->Rlink = new_node;
}
DoublyLinkedList* mergeLists(DoublyLinkedList* list1, DoublyLinkedList* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    DoublyLinkedList* head = NULL;
    DoublyLinkedList** lastPtrRef = &head;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            *lastPtrRef = list1;
            list1 = list1->Rlink;
        }
        else {
            *lastPtrRef = list2;
            list2 = list2->Rlink;
        }
        (*lastPtrRef)->Llink = NULL;
        lastPtrRef = &((*lastPtrRef)->Rlink);
    }

    if (list1 != NULL) {
        *lastPtrRef = list1;
    }
    else {
        *lastPtrRef = list2;
    }

    return head;
}
void splitList(DoublyLinkedList* head, DoublyLinkedList** front, DoublyLinkedList** back) {
    if (head == NULL || head->Rlink == NULL) {
        *front = head;
        *back = NULL;
        return;
    }

    DoublyLinkedList* slow = head;
    DoublyLinkedList* fast = head->Rlink;

    while (fast != NULL) {
        fast = fast->Rlink;
        if (fast != NULL) {
            slow = slow->Rlink;
            fast = fast->Rlink;
        }
    }

    *front = head;
    *back = slow->Rlink;
    slow->Rlink = NULL;
    if (*back != NULL) {
        (*back)->Llink = NULL;
    }
}
void sortList(DoublyLinkedList** headRef) {
    DoublyLinkedList* head = *headRef;
    if (head == NULL || head->Rlink == NULL) {
        return;
    }

    DoublyLinkedList* a;
    DoublyLinkedList* b;

    splitList(head, &a, &b);

    sortList(&a);
    sortList(&b);

    *headRef = mergeLists(a, b);
}