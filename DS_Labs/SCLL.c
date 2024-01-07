#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void create(struct Node **start_ref) {
    int i,n;
    struct Node *temp, *last;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n == 0) {
        *start_ref = NULL;
        return;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the %dth element: ", 1);
    scanf("%d", &temp->data);
    temp->next = temp; //last node points to first node in circular linked list
    last = temp;
    *start_ref = temp; //first node
    for (i = 2; i <= n; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the %dth element: ", i);
        scanf("%d", &temp->data);
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
void insert(struct Node **start_ref, int pos, int data) {
    struct Node *temp, *new_node;
    int i;

    if (*start_ref == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (pos == 1) {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = *start_ref;
        *start_ref = new_node;
    } else {
        temp = *start_ref;
        for (i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete(struct Node **start_ref, int pos) {
    struct Node *temp, *prev;
    int i;

    if (*start_ref == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (pos == 1) {
        temp = *start_ref;
        *start_ref = temp->next;
        free(temp);
    } else {
        temp = *start_ref;
        for (i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        prev = temp;
        temp = temp->next;
        prev->next = temp->next;
        free(temp);
    }
}

void display(struct Node *start) {
    struct Node *temp;

    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }

    temp = start;
    printf("The elements in the circular linked list are: \n");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != start);

    printf("\n");
}

int main() {
    struct Node *start = NULL;

    create(&start);
    display(start);

    insert(&start, 2, 15);
    display(start);

    delete(&start, 3);
    display(start);

    return 0;
}