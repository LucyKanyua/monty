#include "monty.h"

/**
 * opcode_pall - opcode pall prints all the values on the stack,
 * starting from the top of the stack
 * @stack: pointer to the stack
 * @line_number: argument
 * Return: void
 */

void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *_current = *stack;

	while (_current != NULL)
	{
		printf("%d\n", _current->n);
		_current = _current->next;
	}
}
