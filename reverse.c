#include "reverse.h"


/**
 * reverse_stack - Reverses a stack using two temp stacks
 * @top: double pointer to top of original stack
 * 
 * Return: Nothing
 */
void reverse_stack(node **top)
{
	node *stack1 = NULL; /*temp stack 1*/
	node *stack2 = NULL; /*temp stack 2*/

	/*pop original stack and push  to stack 1*/
	while(*top)
	{
		push(pop(top), &stack1);
	}

	/*pop stack 1 and push to stack 2*/
	while(stack1)
	{
		push(pop(&stack1), &stack2);
	}

	/*pop stack 2 and push to original stack*/
	while(stack2)
	{
		push(pop(&stack2), top);
	}

}

/**
 * main - main function
 * 
 * Return: 0 Always
*/