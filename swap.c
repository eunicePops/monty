#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * m_swap -  swaps data from top to previous
 * @stack_p: stack given by main
 * number: number of lines
 *
 * Return: void
 */
void m_swap(stack_t **stack_p, unsigned int number)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!stack_p || !*stack_p || !((*stack_p)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack_p;
	tmp_n = tmp->n;
	tmp->n = tmp_n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}
