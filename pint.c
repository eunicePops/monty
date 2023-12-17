#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * m_pint - print the value at the top of the stack
 * @stack_p: stack given by main in start.c
 * @number: number of lines
 *
 * Return: void
 */
void m_pint(stack_t **stack_p, unsigned int number)
{
	if (!stack_p || !(*stack_p))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", number);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*stack_p)->n);
}
