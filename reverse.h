#ifndef STACK_H
#define STACK_H

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

void reverse_stack(node **top);
int pop(node **top);
void print(node **top);
void push(int data, node**top);


#endif
