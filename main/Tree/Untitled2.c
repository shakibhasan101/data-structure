#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left, *right;
};

struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int value) {
    if (node == NULL)
        return newNode(value);
    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    return node;
}

void preorder(struct node *node) {
    if (node != NULL) {
        printf("%d ", node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(struct node *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->value);
        inorder(node->right);
    }
}

void postorder(struct node *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->value);
    }
}

int main() {
    struct node *root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

