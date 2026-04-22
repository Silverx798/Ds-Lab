/#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;


void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert(int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Inserted successfully\n");
}

void deleteNumber(int num) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == num) {

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);

            printf("List after deletion: ");
            display();
            return;
        }
        temp = temp->next;
    }

    printf("Number %d not found\n", num);
}

void reverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    display();
}

void concatenate(int n) {
    if (n == 0) {
        printf("Second list is empty\n");
        return;
    }

    struct Node* second = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (second == NULL) {
            second = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    if (head == NULL) {
        head = second;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = second;
        if (second != NULL)
            second->prev = temp;
    }

    display();
}

void menu() {
    printf("Enter operation\n");
    printf("1: Insert\n");
    printf("2: Delete\n");
    printf("3: Display\n");
    printf("4: Reverse\n");
    printf("5: Concatenate\n");
    printf("6: Exit\n");
}

int main() {
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);

        if (choice == 1) {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (choice == 2) {
            int x;
            scanf("%d", &x);
            deleteNumber(x);
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            reverse();
        }
        else if (choice == 5) {
            int n;
            scanf("%d", &n);
            concatenate(n);
        }
        else if (choice == 6) {
            printf("Exit\n");
            break;
        }
    }

    return 0;
}
