#include "monty.h"
#include <ctype.h>

/**
 * opcode_push - opcode push pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: argument
 * Return: void
 */

void opcode_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_n;
	char *_value = strtok(NULL, " \n\t");

	if (_value == NULL || (!isdigit(*_value) && (atoi(_value) == 0)))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_n = malloc(sizeof(stack_t));
	if (new_n == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_n->n = atoi(_value);
	new_n->next = *stack;
	new_n->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_n;

	*stack = new_n;
}
