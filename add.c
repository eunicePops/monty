#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * m_add -  adds the first two nodes of the stack
 * @stack_p: stack given by main
 * @number: number of lines
 *
 * Return: void
 */
void m_add(stack_t **stack_p, unsigned int number)
{
	int result;

	if (!stack_p || !*stack_p || !((*stack_p)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack_p)->next->n) + ((*stack_p)->n);
	m_pop(stack_p, number); /*For top node*/
	(*stack_p)->n = result;
}
