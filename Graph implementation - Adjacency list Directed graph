#include<stdio.h>
#include<stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

typedef struct node* GNODE;

GNODE graph[50] = {NULL};



void print(int *N) {
    for(int i = 1; i <= *N; i++) {
        if(graph[i] != NULL) {
            printf("%d=>", i);
            GNODE temp = graph[i];
            while(temp != NULL) {
                printf("%d\t", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}



void insertEdge(int *N) {
    int s, d;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &s);

}
