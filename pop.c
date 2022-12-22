#include "reverse.h"

/**
 * pop - deletes top of a stack
 * @top: double pointer to top of stack
 * 
 * Return: deleted value
 */
int pop(node **top)
{
	/*temp var for deleting*/
	node *temp;
	/*return value*/
	int val;

	/*pop if stacks is not empty*/
	if(!*top)
	{
		printf("stack underflow");
		exit(1);
	}
	/*get top data*/
	temp = *top;
	val = temp -> data;

	/*move top*/
	*top = (*top) -> next;
	free(temp);
	temp = NULL;

	return (val);

}