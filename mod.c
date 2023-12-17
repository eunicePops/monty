#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * m_mod - computes the remainder of the division
 * @stack_p: stack given by main
 * @number: number of lines
 *
 * Return: void
 */
void m_mod(stack_t **stack_p, unsigned int number)
{
	int result;

	if (!stack_p || !*stack_p || !((*stack_p)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", number);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack_p)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack_p)->next->n) % ((*stack_p)->n);
	m_pop(stack_p, number);/*For top node*/
	(*stack_p)->n = result;
}
