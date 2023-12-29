
#include <stdio.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
    printf("%d enqueued successfully.\n", data);
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return;
    }
    printf("%d dequeued successfully.\n", queue[front]);
    front++;
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
