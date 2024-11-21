#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *, int *);
int asc(int, int);
int desc(int, int);
//Uso : ./bubble_sort (ASC OR DESC) num1 num2 num3 ...
int main(int argc, char *argv[])
{
	if( argc < 3)
		return 1;

	int (*order_by)(int, int);
	if( strcmp(argv[1], "ASC") == 0)
		order_by = asc;
	else
		if( strcmp(argv[1], "DESC") == 0)
			order_by = desc;
		else
			return 1;

	int length = argc - 2;
	int *array = (int *) malloc(length * sizeof(int));
	if( array == NULL)
		return 1;

	for( int i = 0; i < length; i++ )
		*(array + i) = atoi(argv[i + 2]);

	for( int j = 1; j < length - 1; j++ )
		for( int k = 0; k < length - j; k++ )
			if(order_by(*(array + k), *(array + k + 1)))
				swap(&(*(array + k)), &(*(array + k + 1)));

	for( int i = 0; i < length; i++ )
		printf("%d ", *(array + i));

	printf("\n");
	free(array);
	return 0;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int asc(int number_a, int number_b)
{
	return number_a > number_b;
}

int desc(int number_a, int number_b)
{
	return number_a < number_b;
}