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
