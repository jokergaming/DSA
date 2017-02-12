/*************************************************************************
	> File Name: circular_linklist.c
	> Author: jokergaming
	> Mail: jokergaming 
	> Created Time: 2017年02月12日 星期日 11时39分06秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
	int data;
	int key;

	struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

bool isEmpty()
{
	return head==NULL;
}

int length()
{
	int length = 0;

	if(head == NULL)
		return 0;

	current = head->next;

	while(current != NULL)
	{
		length++;
		current = current->next;
	}

	return length;
}

void insertFirst(int key, int data)
{
	struct node* link = (struct node*)malloc(sizeof(struct node));
	link->key = key;
	link->data = data;

	if(isEmpty())
	{
		head = link;
		head->next = head;
	}
	else
	{
		link->next = head;
		head = link;
	}
}

struct node* deleteFirst()
{
	struct node* tempLink = head;
	if(head->next == head)
	{
		head = NULL;
		return tempLink;
	}

	head = head->next;
	return tempLink;
}

void printList()
{
	struct node* ptr = head;
	printf("\n[ ");

	if(head != NULL)
	{
		while(ptr->next != ptr)
		{
			printf("(%d, %d) ", ptr->key, ptr->data);
			ptr = ptr->next;
		}
	}
	printf(" ]");
}


int main()
{
	insertFirst(1, 10);
	insertFirst(2, 20);
	insertFirst(3, 30);
	insertFirst(4, 4);
	insertFirst(5, 59);
	insertFirst(6, 60);

	printf("Original List: ");

	printList();

	while(!isEmpty())
	{
		struct node* temp = deleteFirst();
		printf("\nDeleted value:");
		printf("(%d, %d) ", temp->key, temp->data);
	}

	printf("\n list after delteing all item");
	printList();
}
