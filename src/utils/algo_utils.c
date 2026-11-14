/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:42:20 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/17 20:17:41 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Dedicated file for sort algorithm utility functions.

	rank_stack_values_of: Replace every value in stack a with its rank, so
	the smallest number becomes 0 and the largest becomes size - 1. The
	order of the nodes does not change. medium_sort and complex_sort call
	it first, so they can work with chunk boundaries and bits of small,
	non-negative numbers instead of the raw input. Parsing has already
	rejected duplicates, so every rank is unique. If the copy cannot be
	allocated it frees the stack and the tokens, prints "Error" to stderr
	and exits with 1.

	copy_stack_into_array: Copy the values of stack a, top to bottom, into
	a new array of a->size ints. Returns NULL if malloc fails.

	sort_array: Sort that copy in place in ascending order (selection
	sort, O(n^2)).

	turn_stack_value_into_rank: Overwrite each node's value with the index
	where that value sits in the sorted copy.
*/

#include "../inc/push_swap.h"

static int	*copy_stack_into_array(t_stack *a);
static void	sort_array(int *copied_array, int stack_size);
static void	turn_stack_value_into_rank(t_stack *a, int *sorted_array);

void	rank_stack_values_of(t_stack *a, t_config *config)
{
	int *copy_of_stack;
	
	copy_of_stack = copy_stack_into_array(a);
	if (!copy_of_stack)
	{
		free_stack(a);
		free_str_array(config->tokens);
		ft_printf_fd(2, "Error\n");
		exit(1);
	}
	sort_array(copy_of_stack, a->size);
	turn_stack_value_into_rank(a, copy_of_stack);
	free(copy_of_stack);
}

static int	*copy_stack_into_array(t_stack *a)
{
	int *copy_of_stack;
	int i;
	t_node *current;
	
	copy_of_stack = malloc(sizeof(int) * a->size);
	if (!copy_of_stack)
		return (NULL);
	current = a->top;
	i = 0;
	while (current)
	{
		copy_of_stack[i++] = current->value;						// copy stack a node values into an array
		current = current->next;
	}
	return (copy_of_stack);
}

static void	sort_array(int *copied_array, int stack_size)
{
	int min_index;
	int i;
	int j;
	int temp;
	
	i = 0;
	while (i < stack_size - 1)											// Go through the array
		{
			min_index = i;
			j = i + 1;
			while (j < stack_size)
			{
				if (copied_array[j] < copied_array[min_index])		// if the current min value is bigger then the value at current index
					min_index = j;									// set to new min value index
				j++;
			}
			if (min_index != i)										// if the found min value index differs from the one before
			{
				temp = copied_array[i];
				copied_array[i] = copied_array[min_index];			// swap them
				copied_array[min_index] = temp;
			}														// copied_array will now have a sorted array with stack a values
			i++;
		}
}

static void	turn_stack_value_into_rank(t_stack *a, int *sorted_array)
{
	t_node *current;
	int i;

	current = a->top;												// reset current node
	i = 0;
	while (current)										
	{
		i = 0;
		while (i < a->size)
		{
			if (current->value == sorted_array[i])					// Assign rank values based on the index, comparing against the sorted array
			{
				current->value = i;									// overwrites a stack values with ranks
				break;		
			}
			else
				i++;
		}
		current = current->next;
	}
}
