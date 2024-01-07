#include <stdio.h>
#include <stdlib.h>

//Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

//Function to get new node
struct Node* getNewNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//Insert at beguning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = getNewNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
        }
        else {
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
            }
}
//Function to insert a new node at a specific position in the linked list
void insertAtPosition(struct Node** head, int pos, int data) {
    if(pos == 0) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    struct Node* newNode = getNewNode(data);
    int i;
    for(i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    if(newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

//Function to delete a node at a specific position in the linked list
void deleteAtPosition(struct Node** head, int pos) {
    if(*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct Node* temp = *head;
    for(int i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

//Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    printf("Linked list: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    //Create an empty linked list
    struct Node* head = NULL;
    //Insert nodes into the linked list
    insertAtBeginning(&head,50);
    insertAtBeginning(&head,40);
    insertAtBeginning(&head,30);
    insertAtBeginning(&head,20);
    insertAtBeginning(&head,10);
    display(head);
    insertAtPosition(&head, 3,54);
    display(head);
    //Delete a node at position 1 from the linked list
    deleteAtPosition(&head,4);
    display(head);
    return 0;
}