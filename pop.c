#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
* m_pop - pops the very top element of the stack
* @stack_p: stack given by main in start.c
* @number: line number for error messages
*
* Return: void
*/
void m_pop(stack_t **stack_p, unsigned int number)
{
	stack_t *tmp = NULL;

	if (!stack_p || !*stack_p)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack_p)->next;
	free(*stack_p);
	*stack_p = tmp;
	if (!*stack_p)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack_p)->prev = NULL;
}
