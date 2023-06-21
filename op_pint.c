#include "monty.h"

/**
 * opcode_pint - opcode pint prints the value at the top of the stack,
 * followed by a new line.
 * @stack: pointer to the top of the stack
 * @line_number: argument
 * Return: void
 */

void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}