#include "arrayList.h"
ArrayList* createArrayList() {
	ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
	list->array = (Data*)malloc(INITIAL_CAPACITY * sizeof(Data));
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	return list;
}
void resizeArrayList(ArrayList* list) {
	list->capacity *= 2;
	list->array = (Data*)realloc(list->array, list->capacity * sizeof(Data));
}
void addElement(ArrayList* list, Data data) {
	if (list->size == list->capacity) {
		resizeArrayList(list);
	}
	list->array[list->size++] = data;
}
void insertElementAt(ArrayList* list, int index, Data data) {
    if (index < 0 || index > list->size) {
        printf("Index out of bounds.\n");
        return;
    }
    if (list->size == list->capacity) {
        resizeArrayList(list);
    }
    for (int i = list->size; i > index; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index] = data;
    list->size++;
}
void removeElementAt(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds.\n");
        return;
    }
    for (int i = index; i < list->size - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
}
int searchElement(ArrayList* list, Data data) {
    for (int i = 0; i < list->size; i++) {
        if (list->array[i] == data) {
            return i;
        }
    }
    return -1;  // 요소를 찾지 못한 경우
}
void printArrayList(ArrayList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}
void freeArrayList(ArrayList* list) {
    free(list->array);
    free(list);
}
