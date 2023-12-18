#include "monty.h"

/**
* rotl - rotates the first element of the stack
* @stack_p: stack head
* @number: line count
*
* Return: void
*/
void rotl(stack_t **stack_p, unsigned int number)
{
	stack_t *left;
	stack_t *right;

	(void) number;
	if (!stack_p || !*stack_p || !(*stack_p)->next)
		return;

	left = right = *stack_p;

	while (right->next) /* move the right pointer to the last node */
		right = right->next;
	right->next = left; /* a circle infinite linked list loop */
	left->prev = right;
	*stack_p = left->next; /* so we cut the link between the 0 and 1 element */
	(*stack_P)->prev->next = NULL;
	(*stack_p)->prev = NULL;
}
