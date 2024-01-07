#include<stdio.h>
#include<stdlib.h>

// Node definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Linked list creation
Node* createLinkedList() {
    Node* head = NULL;
    int data;

    printf("Enter the data to be inserted into the linked list (0 to stop): ");
    while(1) {
        scanf("%d", &data);
        if(data == 0) break;

        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Insertion at the beginning
Node* insertAtBeginning(Node* head) {
    int data;
    printf("Enter the data to be inserted at the beginning: ");
    scanf("%d", &data);

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;

    return head;
}

// Deletion at the beginning
Node* deleteAtBeginning(Node* head) {
    if(head == NULL) {
        printf("Linked list is empty.\n");
        return head;
    }

    Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

// Deletion at a particular position
Node* deleteAtPosition(Node* head, int position) {
    if(head == NULL) {
        printf("Linked list is empty.\n");
        return head;
    }

    if(position == 0) {
        deleteAtBeginning(head);
        return head;
    }

    Node* temp = head;
    int index = 0;
    while(temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if(temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

// Display linked list
void displayLinkedList(Node* head) {
    if(head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("The linked list is: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = createLinkedList();

    insertAtBeginning(&head,10);
    displayLinkedList(&head);

    head = deleteAtBeginning(head);
    displayLinkedList(head);

    head = deleteAtPosition(head, 1);
    displayLinkedList(head);

    return 0;
}