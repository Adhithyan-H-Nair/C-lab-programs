#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node* appendNode(struct node* head, int data){
	struct node* newNode =malloc(sizeof(struct node *));
	newNode->data = data;
	newNode->link = NULL;
	if(head == NULL)
	{
		return newNode;
	}
	else{
		struct node *current=head;
		while(current->link != NULL)
		{
			current = current->link;
		}
		current->link=newNode;
	}
	
	return head;
}

struct node* userInput(struct node* head){
	int data;
	char choice; 
	head = NULL;
	do{
		printf("\nEnter the data: ");
		scanf("%d",&data);
		
		head = appendNode(head,data);
		printf("do you want to add another node? (y/n)");
		scanf(" %c", &choice);
	}while(choice == 'y' || choice == 'Y');
	
	return head;
}

void printList(struct node* head)
{
	struct node* current = head;
	while(current != NULL)
	{
		printf("%d->", current->data);
		current = current->link;
	}
	printf("NULL\n");
}

struct node* insertAtFront(struct node* head){
	int data;
	printf("Enter the data to put in the front: "); 	
	scanf("%d", &data);
	printf("Linked List before insertion:");
	printList(head);
	struct node* newNode =malloc(sizeof(struct node *));
	if(newNode==NULL){
		printf("Memory Underflow:No isnertion");
	}
	else{
		
		newNode->link=head;
		newNode->data=data;
		head=newNode;
		return head;
	}
	
}

struct node* insertAtEnd(struct node* head){
	int data;
	printf("Enter the data to put in the end: "); 	
	scanf("%d", &data);
	printf("Linked List before insertion:");
	printList(head);
	struct node* newNode =malloc(sizeof(struct node *));
	struct node* ptr=head;
	if(newNode==NULL){
		printf("Memory Overflow:No isnertion");
	}
	else{
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=newNode;
		newNode->data=data;
	}
	return head;
}

struct node* insertAtPosition(struct node* head){
	int data,key;
	printf("Enter the data to insert: "); 	
	scanf("%d", &data);
	printf("Enter the key: ");
	scanf("%d", &key);
	printf("Linked List before Insertion:");
	printList(head);
	struct node* newNode =malloc(sizeof(struct node *));
	struct node* ptr=head;
	if(newNode==NULL){
		printf("Insertion not Possible");
	}
	else{
		while(ptr->data!=key)
		{
			ptr=ptr->link;
		}
		if(ptr->link==NULL){
			printf("Key is not available");
		}
		else{
			newNode->link=ptr->link;
			newNode->data=data;
			ptr->link=newNode;
		
		}
	}
	return head;
}

struct node* deleteAtFront(struct node* head){
	struct node* ptr=head;
	if(ptr==NULL){
		printf("The list is empty");
	}
	else{
		head=ptr->link;
	}
	return head;
}

struct node* deleteAtEnd(struct node* head){
	struct node* ptr=head;
	struct node* ptr1; 
	
	if(ptr==NULL){
		printf("The list is empty");
	}
	else{
		while(ptr->link!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->link;
		}
		ptr1->link=NULL;
	}
	return head;
}

struct node* deleteAtPosition(struct node* head){
	int key;
	printf("Enter the key: ");
	scanf("%d", &key);
	printf("Linked List before deletion:");
	printList(head);
	struct node* start=head;
	struct node* ptr;
	struct node* temp;
	int count = 0;
	if(start == NULL)  
    	{  
        	printf("List is empty.\n");  
        	return head;
    	}  
    	ptr = start;
    	while (ptr != NULL)  
    	{  
        	if(ptr -> data == key)
        	{
            		count = 1;
            		break;
        	}
        	ptr = ptr -> link;  
    	}
    	if(count == 1)
    	{
        	if(start -> data == key)  
        	{  
            		printf("Deleted data: %d", start -> data);
            		temp = start;
            		start = start -> link; 
            		free(temp); 
            		return head;
        	}  
        	ptr = start;
        	while (ptr -> link -> link != NULL)  
        	{  
            		if(ptr -> link -> data == key)
            		{
                		break;
            		}
            		ptr = ptr -> link;  
        	}
        	printf("Deleted data: %d \n", ptr -> link -> data);
        	temp = ptr -> link;
        	free(temp);
        	ptr -> link = ptr -> link -> link;
        	return head;
    	}    
    	else
    	{
        	printf("No node found.\n");
        	return head;
    	}
}

void main()
{
	int option;
	int choice;
	struct node *head = NULL;
	do{
		printf("\n=======================================================Linked List Implementaion=======================================================\n");
		printf("(1)Create a List\n");
		printf("\n");
		printf("(2)Traverse List\n");
		printf("\n");
		printf("(3)Insert at begining\n(4)Insert at end\n(5)Insert at any position\n");
		printf("\n");
		printf("(6)Delete at begining\n(7)Delete at end\n(8)Delete at any position\n");
		printf("\n");
		printf("(9)Exit\n");
		printf("\n");
		printf("Enter the option:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:	printf("-------------------------------------------------------------Creating a List------------------------------------------------------------");
					head = userInput(head);
			case 2:	printf("\n-------------------------------------------------------------Traversing------------------------------------------------------------\n");
			  		printf("Linked list: ");
			  		printList(head);
			  		break;	
			case 3:	printf("-------------------------------------------------------------Insertion at begining------------------------------------------------------------");
					head = insertAtFront(head);
					printf("Linked List after insertion:");
					printList(head);
					break;
					
			case 4:	printf("\n-------------------------------------------------------------Insertion at End------------------------------------------------------------\n");
					head = insertAtEnd(head);
					printf("Linked List after insertion:");
					printList(head);
					break;
					
			case 5:	printf("\n------------------------------------------------------------Insertion at any Position---------------------------------------------------------\n");
					head = insertAtPosition(head);
					printf("Linked List after insertion:");
					printList(head);
					break;
					
			case 6:	printf("\n-------------------------------------------------------------Deletion at Front------------------------------------------------------------\n");
					printf("Linked List before deletion:");
					printList(head);
					head = deleteAtFront(head);
					printf("Linked List after deletion:");
					printList(head);
					break;
					
			case 7:	printf("\n-------------------------------------------------------------Deletion from End------------------------------------------------------------\n");
					printf("Linked List before deletion: ");
					printList(head);
					head = deleteAtEnd(head);
					printf("\n Linked List after deletion: ");
					printList(head);
					break;
					
			case 8:	printf("\n------------------------------------------------------------Deletion at any Positon-----------------------------------------------------------\n");
					head = deleteAtPosition(head);
					printf("\nLinked List after deletion: ");
					printList(head);
					break;
			case 9:	printf("Exiting Program.....");
					break;
					
			default:	if(option>9 || option<1){
						printf("\n************Invalid Selection************\n");
					}
					break;
		}
	}while(option != 9);
}
