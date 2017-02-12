/*************************************************************************
	> File Name: stack.c
	> Author: jokergaming
	> Mail: jokergaming 
	> Created Time: 2017年02月12日 星期日 13时53分17秒
 ************************************************************************/

#include<stdio.h>

int MAXSIZE = 100;
int stack[100];
int top = -1;

int isempty()
{
	return top == -1;
}

int isfull()
{
	return top == MAXSIZE;
}

int get_top()
{
	return stack[top];
}

int pop()
{
	int data;

	if(!isempty())
	{
		data = stack[top--];
		return data;
	}
	else
		printf("Cound not retrieve data, Stack is empty. \n");
}

int push(int data)
{
	if(!isfull())
	{
		stack[++top] = data;
	}
	else
	{
		printf("Could not insert data, Stack is full.\n");
	}
}


int main()
{
	push(3);
	push(5);
	push(9);
	push(1);
	push(12);
	push(15);

	printf("Element at top of the stack: %d\n", get_top());
	printf("Element: \n");

	while(!isempty())
	{
		int data = pop();
		printf("%d\n", data);
	}

	printf("Stack full: %s\n", isfull()?"true":"false");
	printf("Stack empty: %s\n", isempty()?"true":"false");

	return 0;
}

