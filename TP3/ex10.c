#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int data;
    struct Element* next;
} Element;

typedef struct Queue {
    Element* head;
    Element* tail;
} Queue;

void initQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

int isQueueEmpty(Queue* q) {
    return (q->head == NULL);
}

void enqueue(Queue* q, int data) {
    Element* newElement = (Element*) malloc(sizeof(Element));
    newElement->data = data;
    newElement->next = NULL;
    
    if (isQueueEmpty(q)) {
        q->head = newElement;
        q->tail = newElement;
    }
    else {
        q->tail->next = newElement;
        q->tail = newElement;
    }
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Error: Queue is empty!\n");
        return -1;
    }
    
    Element* headElement = q->head;
    int data = headElement->data;
    
    if (q->head == q->tail) {
        q->head = NULL;
        q->tail = NULL;
    }
    else {
        q->head = q->head->next;
    }
    
    free(headElement);
    return data;
}

void printQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    Element* current = q->head;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    
    printQueue(&q);
    
    printf("Dequeued element: %d\n", dequeue(&q));
    
    printQueue(&q);
    
    return 0;
}
