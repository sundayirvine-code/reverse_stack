#include <stdio.h>
#include <stdlib.h>

/**
 * Node: node of a linked list
 * @data: integer value of node
 * @next: pointer to next node;
*/
typedef struct Node{
	int data;
	struct Node *next;
}node;

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
int main()
{
	int data;

	/* original stack */
	node * original = NULL;

	/*push value onto original stack*/
	push(3, &original);
	push(4, &original);

	/*print original stack*/
	printf("Before: ");
	print(&original);

	/*call reverse*/
	reverse_stack(&original);

	/*print original stack after reversal*/
	printf("After: ");
	print(&original);

	return (0);
}
