/*************************************************************************
	> File Name: array_deletion.c
	> Author: jokergaming
	> Mail: jokergaming 
	> Created Time: 2017年02月05日 星期日 10时45分29秒
 ************************************************************************/

#include<stdio.h>

int main()
{
	int array[] = {1, 3, 5, 7, 9};
	int k = 3, n = 5;
	int i, j;

	printf("The original array are: \n");

	for(i = 0; i < n; ++i)
		printf("array[%d] = %d \n", i, array[i]);

	j = k;

	while(j < n)
	{
		array[j-1] = array[j];
		++j;
	}

	n = n - 1;

	printf("The array after deletion are: \n");

	for(i = 0; i < n; ++i)
		printf("array[%d] = %d \n", i, array[i]);
}
