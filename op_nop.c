#include "monty.h"

/**
 * opcode_nop - does nothing
 * @stack: pointer to the stack
 * @line_number: line number where the instruction originates from
 * Return: void
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
