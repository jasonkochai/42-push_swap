/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:19:40 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/19 12:20:07 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	Min extraction method:

	Look at the current stack a
	Find the minimum value
	Rotate a so that value reaches the top
	Push it to b
	Repeat until a is small enough to finish directly
	Sort the remaining tiny core
	Push everything back

*/

#include "push_swap.h"

void	simple_sort(t_stack *a, t_stack *b, t_config *config)
{
	if (a->size <= 5)
		tiny_sort(a, b, config);
	else
		extract_min_to_three(a, b, config);
}
