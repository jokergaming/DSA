/*************************************************************************
	> File Name: array_search.c
	> Author: jokergaming
	> Mail: jokergaming 
	> Created Time: 2017年02月05日 星期日 10时50分08秒
 ************************************************************************/

#include<stdio.h>

int main()
{
	int array[] = {1, 3, 5, 7, 9};
	int item = 3, n = 5;
	int i = 0, j = 0;

	printf("The original array are: \n");

	for(i = 0; i < n; ++i)
		printf("array[%d] = %d \n", i, array[i]);

	while( j < n )
	{
		if(array[j] == item)
			break;
		++j;
	}

	printf("Found element %d at position %d \n", item, j+1);
}
