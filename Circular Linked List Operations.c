#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(int n) {
	
NODE head = NULL, newnode, temp;
    int val;

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val);

        newnode = (NODE)malloc(sizeof(struct node));
        newnode->data = val;

        if(head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            temp = head;
            while(temp->next != head)
                temp = temp->next;

            temp->next = newnode;
            newnode->next = head;
        }
    }
    return head;


}

// Traverse CLL
void traverseListInCLL(NODE head) {

  NODE temp = head;

    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != head);

    printf("\n");

}

// Insert at given position in CLL
NODE insertAtPositionInCLL(NODE head, int pos, int x) {
NODE newnode, temp, last;
    int count = 1;

    newnode = (NODE)malloc(sizeof(struct node));
    newnode->data = x;

    if(pos == 1)
    {
        if(head == NULL)
        {
            head = newnode;
            newnode->next = head;
            return head;
        }

        last = head;
        while(last->next != head)
            last = last->next;

        newnode->next = head;
        last->next = newnode;
        head = newnode;
        return head;
    }

    temp = head;

    while(count < pos-1 && temp->next != head)
    {
        temp = temp->next;
        count++;
    }

    if(count != pos-1)
    {
        printf("Position not found\n");
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;

}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL(NODE head, int pos) {
NODE temp=head, prev, last;
    int count=1;

    if(pos <=0)
    {
        printf("Position not found\n");
        return head;
    }

    if(pos == 1)
    {
        int val = head->data;

        if(head->next == head)
        {
            free(head);
            printf("Deleted element: %d\n", val);
            return NULL;
        }

        last = head;
        while(last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;

        printf("Deleted element: %d\n", val);
        return head;
    }

    while(count < pos && temp->next != head)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if(count != pos)
    {
        printf("Position not found\n");
        return head;
    }

    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);

    return head;
}

// Reverse CLL
NODE reverseCLL(NODE head) {
	
 NODE prev=NULL, curr=head, next, first=head;

    do{
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }while(curr != head);

    first->next = prev;
    head = prev;

    return head;

}

// Concatenate two CLLs
NODE concatCLL(NODE first, NODE second) {

if(first == NULL) return second;
    if(second == NULL) return first;

    NODE temp1 = first, temp2 = second;

    while(temp1->next != first)
        temp1 = temp1->next;

    while(temp2->next != second)
        temp2 = temp2->next;

    temp1->next = second;
    temp2->next = first;

    return first;


}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
