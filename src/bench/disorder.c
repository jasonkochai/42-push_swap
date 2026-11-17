/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:10:35 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/17 19:01:19 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*

compute_disorder: Measure how unsorted stack a is and store it in
config->disorder. It counts the inversions (pairs where a higher value sits
above a lower one) and divides by the number of pairs, so the result runs
from 0.0 (already sorted) to 1.0 (fully reversed). Every pair is compared,
so it costs O(n^2). A stack with fewer than two numbers gives 0.0.

strategy_picker: Only acts when no strategy flag was given (ADAPTIVE). It
then marks the run as adaptive and picks the strategy from the disorder:
below 0.2 SIMPLE, below 0.5 MEDIUM, otherwise COMPLEX. A strategy forced by
a flag is left as it is.

*/

#include "../inc/push_swap.h"

void	compute_disorder(t_stack *a, t_config *config)
{
	int mistakes;
	int total_pairs;
	t_node *node1;
	t_node *node2;

	mistakes = 0;
	total_pairs = 0;
	node1 = a->top;
	while(node1)
	{
		node2 = node1->next;
		while(node2)
		{
			total_pairs++;
			if (node1->value > node2->value)
				mistakes++;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	if (total_pairs == 0)								// avoid undefined behavior, division with zero
		config->disorder = 0.0f;
	else
		config->disorder = (float)mistakes/ total_pairs;
}

void	strategy_picker(t_config *config)
{
	if (config->strategy == ADAPTIVE)
	{
		config->adaptive = true;
		if (config->disorder < 0.2f)
			config->strategy = SIMPLE;
		else if (config->disorder >= 0.2f && config->disorder < 0.5f)
			config->strategy = MEDIUM;
		else
			config->strategy = COMPLEX;
	}
}
