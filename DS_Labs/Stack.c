#include<stdio.h>
#define MAX_SIZE 5
int stack[MAX_SIZE];


int top = -1;
int stack[MAX_SIZE];

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull(){
    if(top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack is Full\n");
        return;
    }
    stack[++top] = data;
    printf("Pushed element : %d\n", data);
}

int pop(){
    if(isEmpty()){
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top--];
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50); // Full

    printf("Popped element : %d\n", pop());
    printf("Popped element : %d\n", pop());
    printf("Popped element : %d\n", pop());

    push(60); // Now not full
    push(70);
    push(80);
    push(90); // Full again

    printf("Top element : %d\n", stack[top]);
    return 0;
}