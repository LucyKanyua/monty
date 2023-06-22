#include "monty.h"

/**
 * opcode_swap - swaps two elements of a stack
 * @stack: pointer to the top of a stack
 * @line_number: line number where instructions originated
 * Return: void
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = temp;
}
