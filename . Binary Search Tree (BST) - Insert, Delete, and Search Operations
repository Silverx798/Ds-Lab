#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert node
Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}


Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
       if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }


        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }


        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


int search(Node* root, int key) {
    if (root == NULL)
        return 0;

    if (key == root->data)
        return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}


int main() {
    int n;
    scanf("%d", &n);

    Node* root = NULL;
    int op, val;

    char output[100][20];
    int outIndex = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &op, &val);

        if (op == 1) {
            root = insert(root, val);
        } 
        else if (op == 2) {
            root = deleteNode(root, val);
        } 
        else if (op == 3) {
            if (search(root, val))
                sprintf(output[outIndex++], "found");
            else
                sprintf(output[outIndex++], "not found");
        }
    }


    for (int i = 0; i < outIndex; i++) {
        printf("%s\n", output[i]);
    }

    return 0;
}
