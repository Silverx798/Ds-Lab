struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE createNode(int x) {
     NODE newNode =( NODE)malloc(sizeof( struct node));
	if (newNode==NULL)
	{
		printf("Memory allocation failed");
		exit(1);
	}
    newNode->data=x;
	newNode->next=NULL;
    return newNode;    
}

NODE addNode(NODE first, int x) {
    NODE temp;
    NODE newNode=createNode(x);
     if (first==NULL)
	{
		return newNode;
		
	}

	temp=first;
    while(temp->next!= NULL)
		{
			temp=temp->next;
		}
	temp->next=newNode;
	 return first;
    
}
