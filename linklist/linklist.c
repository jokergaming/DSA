/*************************************************************************
	> File Name: linklist.c
	> Author: jokergaming
	> Mail: jokergaming 
	> Created Time: 2017年02月05日 星期日 11时02分51秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//struct node define
struct node {
	int data;
	int key;
	struct node* next;
};

//empty list define
struct node* head = NULL;
struct node* current = NULL;

//display the list one element one by one
void printList()
{
	struct node* ptr = head;
	printf("\n[ ");

	while(ptr != NULL)
	{
		printf("(%d, %d) ", ptr->key, ptr->data);
		ptr = ptr->next;
	}

	printf(" ]");
}

//insert link at the first location
void insertFirst(int key, int data)
{
	//create a link use malloc
	struct node* link = (struct node*)malloc(sizeof(struct node));

	link->key = key;
	link->data = data;

	link->next = head;

	//make head pointer to the created link, so it can insert at first position
	head = link;
}

//delete first item
struct node* deleteFirst()
{
	struct node* tempLink = head;

	head = head->next;

	//return the delete link
	return tempLink;
}

//is linklist empty? yes return 1:no return 0
bool isEmpty()
{
	return head == NULL;
}

//return the length of linklist
int length()
{
	int length = 0;
	struct node* current;

	for(current = head; current != NULL; current = current->next)
		++length;

	return length;
}

//find a link with given key
struct node* find(int key)
{
	struct node* current = head;

	if(head == NULL)
		return NULL;

	while(current->key != key)
	{
		if(current->next == NULL)
			return NULL;
		else
			current = current->next;
	}
	return current;
}

//delete a link with given key
struct node* delete(int key)
{
	struct node* current = head;
	struct node* previous = NULL;

	//if list is empty
	if(head == NULL)
		return NULL;
	
	while(current->key != key)
	{
		if(current->next == NULL)
			return NULL;
		else
		{
			previous = current;
			current = current->next;
		}
	}

	if(current == head)
		head = head->next;
	else
		previous->next = current->next;

	return current;
}

void sort()
{
	int i, j, k;
	int tempKey, tempData;
	struct node* current;
	struct node* next;

	int size = length();
	k = size;

	for(i = 0; i < size - 1; i++, k--)
	{
		current = head;
		next = head->next;

		for(j = 1; j < k; j++)
		{
			if(current->data > next->data)
			{
				tempData = current->data;
				current->data = next->data;
				next->data = tempData;
				
				tempKey = current->key;
				current->key = next->key;
				next->key = tempKey;
			}

			current = current->next;
			next = next->next;
		}
	}
}

void reverse(struct node** head_ref)
{
	struct node* prev = NULL;
	struct node* current = *head_ref;
	struct node* next;

	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head_ref = prev;
}

int main()
{
	insertFirst(1, 10);
	insertFirst(2, 20);
	insertFirst(3, 30);
	insertFirst(4,	1);
	insertFirst(5, 40);
	insertFirst(6, 56);

	printf("Original list: ");

	printList();

	while(!isEmpty())
	{
		struct node* temp = deleteFirst();
		printf("\n Deleted value: ");
		printf("(%d, %d) ", temp->key, temp->data);
	}

	printf("\nList after deleting all item: ");
	printList();
	insertFirst(1, 10);
	insertFirst(2, 20);
	insertFirst(3, 30);
	insertFirst(4,	1);
	insertFirst(5, 40);
	insertFirst(6, 56);

	printf("\nRestored list: ");
	printList();
	printf("\n");

	struct node* foundLink = find(4);

	if(foundLink != NULL)
	{
		printf("Element found: ");
		printf("(%d, %d) ", foundLink->key, foundLink->data);
		printf("\n");
	}
	else
		printf("element not found.");

	delete(4);
	printf("List after deleting an item: ");
	printList();
	printf("\n");
	foundLink = find(4);

	if(foundLink != NULL)
	{
		printf("Element found: ");
		printf("(%d, %d) ", foundLink->key, foundLink->data);
		printf("\n");
	}

	else
		printf("Element not found.");

	printf("\n");
	sort();

	printf("list after sorting the data: ");
	printList();

	reverse(&head);
	printf("\n List after reversing the data: ");
	printList();
}
