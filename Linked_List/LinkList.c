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
 * Methods:   	append()
 *		insertNode()
 *		deleteNode()
 *		printList()
 *		listInit()
 *   		main()
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define true 1
typedef struct Node
{
	int data;
	struct Node * next;
}Node;

void append(Node ** head, int data){
	
	Node * tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = (*head);
	(*head) = tmp;
}
void insertNode(Node** head, int data, int position)
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
void deleteNode(Node ** head, int position)
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
void printList(Node ** head){
	
	Node * tmp = (*head);
	printf("List is:");
	while(tmp != NULL)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("end\n");
}

Node * listInit()
{
	Node * head = NULL;
	return head;

}

void main()
{
	Node * head = listInit();
	printf("How many numbers? \n");
	int i, n, data, position;
	scanf("%d", &n);
	for(i = 0 ; i < n; i++)
	{
		printf("Enter the insert data \n");
		scanf("%d", &data);
		append(&head, data);
		printList(&head);
	}
	char operation;

	while(true)
	{
		printf("What do you want to do? \n(Insert:i|Delete:d|Quit:q) ");
		
		scanf(" %c", &operation);

		switch(operation)
		{
			case 'i':
				printf("Enter the insert position ");
				scanf("%d", &position);
				printf("Enter the insert data ");
				scanf("%d", &data);
				insertNode(&head, data, position);
				printList(&head);
			break;
			case 'd':
				printf("Enter the delete position ");
				scanf("%d", &position);
				deleteNode(&head, position);
				printList(&head);
			break;		
			case 'q':
				return;
			break;

		}

	}

	
}
