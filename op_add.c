#include "monty.h"

/**
 * opcode_add - adds the top two elements of a stack
 * @stack: pointer to the top of a stack
 * @line_number: where instruction originate
 * Return: void
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum = 0;
	
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + ((*stack)->next)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;
	(*stack)->prev = NULL;
	free(temp);
}
