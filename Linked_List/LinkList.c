/* DATA_STRUCTURE
 *  
 * 1.1 LINKED_LIST
 *
 * Descritpion: The Linked List Implementation using C Language
 *
 * Author: 	ZHONGRUI LI
 *
 * Date: 	August 28 2014
 *
 * Methods:   	AppendToHead()
 *		InsertNode()
 *		DeleteNode()
 *		PrintLinkedList()
 *		LinkedListInit()
 *		ReverseLinkedListIteration()
 *		ReverseLinkedListRecursion()
 * 		ReversePrintLinkedListRecursion()
 *   		main()
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define true 1

//The node structure
typedef struct Node
{
	int data;
	struct Node * next;
}Node;

//Append a node to the head of the linked list
void AppendNodetoHead(Node ** head, int data){
	
	Node * tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = (*head);
	(*head) = tmp;
}

//Insert a node to any postion of the linked list
void InsertNode(Node** head, int data, int position)
{
	if(position <= 0)
	{
		printf("Invaild postion!");
		return;
	}
	Node * tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	int i;
	Node * cur = (*head);
	if(position == 1)
	{
		tmp->next = cur;
		(*head) = tmp;
	}
	else
	{
		for(i = 1; i < position-1; i++)
		{
			if(cur->next != NULL)
				cur = cur->next;
			else
				break;
		}
		tmp->next = cur->next;
		cur->next = tmp;
	}
}

//Delete a node of the linked list
void DeleteNode(Node ** head, int position)
{
	if((*head) == NULL)
	{
		printf("List is null!\n");
		return;
	}
	if(position <= 0)
	{
		printf("Invaild position!\n");
		return;
	}
	Node * cur = (*head);
	if(position  == 1)
	{
		(*head) = cur->next;
		cur->next = NULL;
		free(cur);
		return;
	}
	Node * pre = NULL;
	int i;
	for(i = 1; i < position; i++)
	{
		if(cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		else
			break;
	}
	pre->next = cur->next;
	cur->next = NULL;
	free(cur);

}

//Reverse Linked List using iterative method
void ReverseLinkedListIteration(Node ** head)
{
	Node * pre, * cur, * next;
	cur = (*head);
	pre = NULL;
	next = cur->next;
	while(cur->next != NULL)
	{
		cur->next = pre;
		pre = cur;
		cur = next;
		next = cur->next;
	}
	cur->next = pre;
	(*head) = cur;
}
//Reverse Linked List using recursive method
Node * ReverseLinkedListRecursion(Node * head)
{
	if(head->next == NULL)
		return head;
	
	Node * newHead = ReverseLinkedListRecursion(head->next);

	head->next->next = head;

	head->next = NULL;

	return newHead;

}
//Print all the node of the linked list 
void PrintLinkedList(Node ** head){
	
	Node * tmp = (*head);
	printf("Linked List:");
	while(tmp != NULL)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("end\n");
}
//Reservely print the linked list 
void ReversePrintLinkedListRecursion(Node * head)
{
	if(head == NULL)
	{
		printf("Linked List: end<-");
		return;
	}
	ReversePrintLinkedListRecursion(head->next);
	printf("%d<-", head->data);
}
//Initialize a empty linked list with only a null node
Node * LinkedListInit()
{
	Node * head = NULL;
	return head;

}

void main()
{
	Node * head = LinkedListInit();
	printf("How many numbers? \n");
	int i, n, data, position;
	scanf("%d", &n);
	for(i = 0 ; i < n; i++)
	{
		printf("Enter the insert data \n");
		scanf("%d", &data);
		AppendNodetoHead(&head, data);
		PrintLinkedList(&head);
	}
	char operation;

	while(true)
	{
		printf("------------------------------------\n");
		printf("What do you want to do? \n(Insert:i|Delete:d|Quit:q|Iterative_Reverse:r\nRecursive_Reverse:c|Reserve_Print:p) ");
		
		scanf(" %c", &operation);

		switch(operation)
		{
			case 'i':
				printf("Enter the insert position ");
				scanf("%d", &position);
				printf("Enter the insert data ");
				scanf("%d", &data);
				InsertNode(&head, data, position);
				PrintLinkedList(&head);
			break;
			case 'd':
				printf("Enter the delete position ");
				scanf("%d", &position);
				DeleteNode(&head, position);
				PrintLinkedList(&head);
			break;	
			case 'r':
				ReverseLinkedListIteration(&head);
				PrintLinkedList(&head);
			break;
			case 'c':
				head = ReverseLinkedListRecursion(head);
				PrintLinkedList(&head);
			break;
			case 'p':
				ReversePrintLinkedListRecursion(head);
				printf("\n");
			break;
			case 'q':
				return;
			break;

		}

	}

	
}
