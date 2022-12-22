#include "reverse.h"

/**
 * push - insert data at the top of a stack
 * @top: double pointer to top of stack
 * 
 * Return: Nothing
 */
void push(int data, node**top)
{
	node *new;
	new = malloc(sizeof(node));
	/*check if we were allocated memory*/
	if(!new)
	{
		printf("stack overflow\n");
		exit(1);
	}
	new -> data = data;
	new -> next = *top;
	*top = new;
}