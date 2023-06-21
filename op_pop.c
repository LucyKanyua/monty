#include "monty.h"

/**
 * opcode_pop - opcode pop removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: argument
 * Return: void
 */

void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t _current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	_current = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
