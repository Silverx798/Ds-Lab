#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void printRange(struct Node* root, int low, int high) {
    if (root == NULL) {
        return;
    }

    if (low < root->data) {
        printRange(root->left, low, high);
    }

    if (low <= root->data && high >= root->data) {
        printf("%d ", root->data);
    }

    if (high > root->data) {
        printRange(root->right, low, high);
    }
}

int main() {
    struct Node* root1 = newNode(17);
    root1->left = newNode(4);
    root1->right = newNode(18);
    root1->left->left = newNode(2);
    root1->left->right = newNode(9);

    int l1 = 4, h1 = 24;
    printf("Example 1 Output: ");
    printRange(root1, l1, h1);
    printf("\n");

    struct Node* root2 = newNode(16);
    root2->left = newNode(7);
    root2->right = newNode(20);
    root2->left->left = newNode(1);
    root2->left->right = newNode(10);

    int l2 = 13, h2 = 23;
    printf("Example 2 Output: ");
    printRange(root2, l2, h2);
    printf("\n");
    return 0;
}
