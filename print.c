#include "reverse.h"

/**
 * print - print stack values
 * @top: double pointer to top of stack
 * 
 * Return: Nothing
 */
void print(node **top)
{
	node *ptr = *top;
	if (!ptr)
	{
		printf("Empty stack\n");
		exit(1);
	}
	while(ptr)
	{
		printf("%d ", ptr -> data);
		ptr = ptr -> next;
	}
	printf("\n");
}