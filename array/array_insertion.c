/*************************************************************************
	> File Name: array_insertion.c
	> Author: jokergaming
	> Mail: jokergaming 
	> Created Time: 2017年02月05日 星期日 10时39分06秒
 ************************************************************************/

#include<stdio.h>

main()
{
	int array[] = {1, 3, 5, 7, 8};
	int item = 10, k = 3, n = 5;
	int i = 0, j = n;

	printf("The origin array elements are: \n");

	for(i = 0; i < 5; i++)
	{
		printf("array[%d] = %d \n", i, array[i]);
	}

	n = n + 1;

	while( k <= j )
	{
		array[j+1] = array[j];
		--j;
	}

	array[k] = item;

	printf("The array elements after insertion: \n");

	for(i = 0; i < n; i++)
		printf("array[%d] = %d \n", i, array[i]);
}

