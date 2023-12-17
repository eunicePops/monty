#include "monty.h"

/**
 * pall - prints the stack
 * @stack_p: stack given by main in start.c
 * @number: number of lines
 *
 * Return: void
 */
void m_pall(stack_t **stack_p, unsigned int number __attribute__((unused)))
{
	print_stack(*stack_p);
}
