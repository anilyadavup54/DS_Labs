#include<stdio.h>

#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    if((rear + 1) % SIZE == front) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if(front == -1 || front == rear) {
        return 1;
    }
    return 0;
}
void enqueue(int data) {
    if(isFull()) {
        printf("Queue is full.\n");
    } else {
        if(front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = data;
        printf("Enqueued %d.\n", data);
    }
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("Dequeued element.\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    isEmpty();
    enqueue(50);
    dequeue();
    dequeue();
    enqueue(60);
    enqueue(70);
    return 0;
}