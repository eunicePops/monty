#include "monty.h"

/**
* rotr - rotates the last node of a stack_t stack
* @stack_P: stack head
* @number: line count
*
* Return: void
*/
void rotr(stack_t **stack_p, unsigned int number)
{
	stack_t *bottom;
	stack_t *prev;

	(void) number;
	if (!stack_p || !*stack_p || !(*stack_p)->next)
		return;

	bottom = *stack_p;

	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	bottom->next = *stack_p;
	bottom->prev = NULL;
	prev->next = NULL;
	(*stack_p)->prev = bottom;
	*stack_p = bottom;
}

