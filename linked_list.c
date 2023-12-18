#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * addqueue_node - adds a node to a stack_t stack in queue_node
 * @stack_p: stack head
 * @n: number of the node
 *
 * Return: newly created node, if memory allocation fails, the function will
 * return NULL.
 */
stack_t *addqueue_node(stack_t **stack_p,  int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack_p;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*stack_p)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack_p = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}

	return (new);
}

/**
 * add_node - adds a node to the start of a stack_t stack
 * @stack_p: stack head
 * @n: number for the new node
 *
 * Return: newly created node, if creation fails, the
 * function will return NULL.
 */
stack_t *add_node(stack_t **stack_p, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *stack_p;
	new->prev = NULL;
	if (*stack_p)
		(*stack_p)->prev = new;

	*stack_p = new;

	return (new);
}

/**
 * print_stack - prints the contents of a stack_t stack
 * @stack_p: stack head
 *
 * Return: number of elements of the list
 */
size_t print_stack(const stack_t *stack_p)
{
	size_t c = 0;

	while (stack_p)
	{
		printf("%d\n", stack_p->n);
		stack_p = stack_p->next;
		c++;
	}

	return (c);
}

/**
 * free_stack - frees a dlistint_t linked list
 * @stack_p: list head
 *
 * Return: void
 */
void free_stack(stack_t *stack_p)
{
	stack_t *current = stack_p;
	stack_t *next;

	if (stack_p)
	{
		next = stack_p->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
