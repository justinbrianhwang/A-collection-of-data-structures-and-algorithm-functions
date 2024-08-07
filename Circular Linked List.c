#include "Circular Linked LIst.h"
CircularSinglyLinkedList* newNode(Data data) {
    CircularSinglyLinkedList* tmp = (CircularSinglyLinkedList*)malloc(sizeof(CircularSinglyLinkedList));
    tmp->data = data;
    tmp->next = tmp; // Point to itself to form a circular list
    return tmp;
}
void addNode(CircularSinglyLinkedList** head, Data data) {
    CircularSinglyLinkedList* tmp = newNode(data);
    if (*head == NULL) {
        *head = tmp;
        return;
    }
    CircularSinglyLinkedList* current = *head;
    while (current->next != *head) {
        current = current->next;
    }
    current->next = tmp;
    tmp->next = *head;
}
int compareData(Data d1, Data d2) {
    return d1 == d2;
}
void insertAfter(CircularSinglyLinkedList* head, Data findData, Data insertData) {
    CircularSinglyLinkedList* current = head;
    do {
        if (current->data == findData) {
            CircularSinglyLinkedList* tmp = newNode(insertData);
            tmp->next = current->next;
            current->next = tmp;
            return;
        }
        current = current->next;
    } while (current != head);
    printf("Node with data %d not found.\n", findData);
}
void deleteNode(CircularSinglyLinkedList** head, Data deleteData) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    CircularSinglyLinkedList* current = *head;
    CircularSinglyLinkedList* previous = NULL;

    // Find the node to be deleted
    do {
        if (current->data == deleteData) {
            if (previous != NULL) {
                previous->next = current->next;
            }
            else {
                // If the node to be deleted is the only node in the list
                if (current->next == current) {
                    *head = NULL;
                    free(current);
                    return;
                }
                // If the node to be deleted is the head node
                CircularSinglyLinkedList* last = *head;
                while (last->next != *head) {
                    last = last->next;
                }
                last->next = current->next;
                *head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    } while (current != *head);

    printf("Node with data %d not found.\n", deleteData);
}
void printList(CircularSinglyLinkedList* head) {
    if (head == NULL) return;
    CircularSinglyLinkedList* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}
void printReverseList(CircularSinglyLinkedList* head) {
    if (head == NULL) return;
    CircularSinglyLinkedList* current = head;
    CircularSinglyLinkedList* prev = NULL;
    CircularSinglyLinkedList* next = NULL;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    head->next = prev;

    current = prev;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != prev);
    printf("\n");

    // Restore the original order
    current = prev;
    prev = NULL;
    next = NULL;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head->next);
    head->next = prev;
}
CircularSinglyLinkedList* searchNode(CircularSinglyLinkedList* head, Data searchData) {
    if (head == NULL) return NULL;
    CircularSinglyLinkedList* current = head;
    do {
        if (compareData(current->data, searchData)) {
            return current;
        }
        current = current->next;
    } while (current != head);
    return NULL;
}
int listLength(CircularSinglyLinkedList* head) {
    if (head == NULL) return 0;
    int length = 0;
    CircularSinglyLinkedList* current = head;
    do {
        length++;
        current = current->next;
    } while (current != head);
    return length;
}
void clearList(CircularSinglyLinkedList** head) {
    if (*head == NULL) return;
    CircularSinglyLinkedList* current = *head;
    CircularSinglyLinkedList* nextNode;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != *head);
    *head = NULL;
}
void insertAtPosition(CircularSinglyLinkedList** head, Data data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    CircularSinglyLinkedList* new_node = newNode(data);
    if (position == 0) {
        if (*head == NULL) {
            *head = new_node;
            return;
        }
        CircularSinglyLinkedList* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        new_node->next = *head;
        current->next = new_node;
        *head = new_node;
        return;
    }

    CircularSinglyLinkedList* current = *head;
    for (int i = 0; i < position - 1 && current->next != *head; i++) {
        current = current->next;
    }

    if (current->next == *head && position != 0) {
        printf("Position out of bounds.\n");
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}
CircularSinglyLinkedList* mergeLists(CircularSinglyLinkedList* list1, CircularSinglyLinkedList* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    CircularSinglyLinkedList* head1 = list1;
    CircularSinglyLinkedList* head2 = list2;

    while (head1->next != list1) {
        head1 = head1->next;
    }
    head1->next = list2;

    while (head2->next != list2) {
        head2 = head2->next;
    }
    head2->next = list1;

    return list1;
}
void splitList(CircularSinglyLinkedList* head, CircularSinglyLinkedList** front, CircularSinglyLinkedList** back) {
    if (head == NULL || head->next == head) {
        *front = head;
        *back = NULL;
        return;
    }

    CircularSinglyLinkedList* slow = head;
    CircularSinglyLinkedList* fast = head->next;

    while (fast != head && fast->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    *front = head;
    *back = slow->next;
    slow->next = head;

    CircularSinglyLinkedList* current = *back;
    while (current->next != head) {
        current = current->next;
    }
    current->next = *back;
}
void sortList(CircularSinglyLinkedList** headRef) {
    CircularSinglyLinkedList* head = *headRef;
    if (head == NULL || head->next == head) {
        return;
    }

    CircularSinglyLinkedList* a;
    CircularSinglyLinkedList* b;

    splitList(head, &a, &b);

    sortList(&a);
    sortList(&b);

    *headRef = mergeLists(a, b);
}