#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


#define INSTRUCTIONS              \
	{                           \
		{"push", push},       \
		    {"pall", m_pall},   \
		    {"pint", m_pint},   \
		    {"pop", m_pop},     \
		    {"swap", m_swap},   \
		    {"nop", m_nop},     \
		    {"div", m_div},    \
		    {"mul", m_mul},    \
		    {"add", m_add},    \
		    {"sub", m_sub},    \
		    {"mod", m_mod},     \
		    {"pchar", pchar}, \
		    {"pstr", pstr},   \
		    {"rotl", rotl},   \
		    {"rotr", rotr},   \
		{                     \
			NULL, NULL      \
		}                     \
	}


typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;


void free_stack(stack_t *stack_p);

void rotr(stack_t **stack_p, unsigned int number);
void pstr(stack_t **stack_p, unsigned int number);
void pchar(stack_t **stack_p, unsigned int number);
void rotl(stack_t **stack_p, unsigned int number);

void m_div(stack_t **stack_p, unsigned int number);
void m_add(stack_t **stack_p, unsigned int number);
void m_sub(stack_t **stack_p, unsigned int number);
void m_mul(stack_t **stack_p, unsigned int number);
void m_mod(stack_t **stack_p, unsigned int number);



void m_push(stack_t **stack_p, unsigned int number);
void m_swap(stack_t **stack_p, unsigned int number);
void m_pop(stack_t **stack_p, unsigned int number);
void m_nop(stack_t **stack_p, unsigned int number);
void m_pall(stack_t **stack_p unsigned int number);
void m_pint(stack_t **stack_p, unsigned int number);


stack_t *add_node(stack_t **stack,_p, int n);
stack_t *addqueue_node(stack_t **stack_p, int n);

size_t print_stack(const stack_t *stack_p);


void opcode(stack_t **stack_p, char *str, unsigned int number);

int is_digit(char *string);
int isnumber(char *str);


#endif /* MONTY_H */
