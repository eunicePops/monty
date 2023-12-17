#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * m_push - push element into the stack
 * @stack_p: stack given by main
 * @number: number of lines
 *
 * Return: void
 */
void m_push(stack_t **stack_p, unsigned int number)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", number);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack_p, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack_p, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
