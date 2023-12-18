#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pchar - prints the int at the top of the stack as char
 * @stack_p: stack given by main
 * @number: amount of lines
 *
 * Return: void
 */
void pchar(stack_t **stack_p, unsigned int number)
{
	if (!stack_p || !(*stack_p))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*stack_p)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack_p)->n);
}

