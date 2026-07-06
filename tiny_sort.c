/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:17:43 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/18 13:41:57 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a, t_config *config);

void	tiny_sort(t_stack *a, t_stack *b, t_config *config)
{
	if (a->size == 2)
		sa(a, config);
	else if (a->size == 3)
		sort_three(a, config);
	else if (a->size == 4 || a->size == 5)
		extract_min_to_three(a, b, config);
}

static void	sort_three(t_stack *a, t_config *config)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->top->value;
	middle = a->top->next->value;
	bottom = a->bottom->value;
	if (top < middle && middle < bottom)
		return ;
	if (top < bottom && middle < bottom)
		sa(a, config);
	else if (top < middle && middle > bottom)
	{
		rra(a, config);
		if (a->top->value > a->top->next->value)
			sa(a, config);
	}
	else
	{
		ra(a, config);
		if (a->top->value > a->top->next->value)
			sa(a, config);
	}
}

void	extract_min_to_three(t_stack *a, t_stack *b, t_config *config)
{
	while (a->size > 3)
	{
		bring_min_to_top_of(a, config);
		pb(a, b, config);
	}
	sort_three(a, config);
	while (b->top)
		pa(a, b, config);
}
