#include "reverse.h"

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
