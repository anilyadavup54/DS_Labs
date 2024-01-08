#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(char* inorder, char* preorder, int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    struct Node* node = newNode(preorder[*preIndex]);
    (*preIndex)++;

    if (start == end)
        return node;

    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == node->data)
            break;
    }

    node->left = buildTree(inorder, preorder, start, i - 1, preIndex);
    node->right = buildTree(inorder, preorder, i + 1, end, preIndex);

    return node;
}

void inorderTraversal(struct Node* node) {
    if (node == NULL)
        return;

    inorderTraversal(node->left);
    printf("%c ", node->data);
    inorderTraversal(node->right);
}
void PostorderTraversal(struct Node* node) {
    if (node == NULL)
        return;

    PostorderTraversal(node->left);
    PostorderTraversal(node->right);
    printf("%c ", node->data);
}
void PreorderTraversal(struct Node* node) {
    if (node == NULL)
        return;
    printf("%c ", node->data);
    PreorderTraversal(node->left);
    PreorderTraversal(node->right);
}


int main() {
    char inorder[] = {'Q', 'B', 'K', 'C', 'F', 'A', 'G', 'P', 'E', 'D', 'H', 'R'};
    char preorder[] = {'G', 'B', 'Q', 'A', 'C', 'K', 'F', 'P', 'D', 'E', 'R', 'H'};

    int preIndex = 0;
    struct Node* root = buildTree(inorder, preorder, 0, 11, &preIndex);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder traversal: ");
    PreorderTraversal(root);
    printf("\n");
    printf("Postorder traversal: ");
    PostorderTraversal(root);
    printf("\n");

    return 0;
}
