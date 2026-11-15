/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:59:18 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/17 20:14:11 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*

stack_init: Set a stack to empty: size 0, no top and no bottom node. A NULL
stack is ignored.

build_stack: Create one node for each string in config->tokens, in order,
and append it at the bottom, so the first number given on the command line
ends up on top of stack a. It expects the tokens to be validated already
(parse_input checks the format, the int range and duplicates), which is why
the (int) cast of ft_atol is safe here. If a node cannot be allocated it
frees the nodes built so far and the tokens, prints "Error" to stderr and
exits with 1.

*/

#include "../inc/push_swap.h"

void	stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

void	build_stack(t_stack *stack, t_config *config)
{
	t_node *new_node;
	int i;
	int nbr;

	i = 0;
	while (config->tokens[i])
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
		{
			free_stack(stack);
			free_str_array(config->tokens);
			ft_printf_fd(2, "Error\n");
			exit(1);
		}
		nbr = (int)ft_atol(config->tokens[i]);
		new_node->value = nbr;
		append_node(stack, new_node);
		i++;
		stack->size++;
	}
}
