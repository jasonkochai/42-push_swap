/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:56:23 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/18 13:47:09 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	if (argc == 1)
		return (0);
	stack_init(&a);
	stack_init(&b);
	config.checker = true;
	config.tokens = NULL;
	config.tokens = parse_numbers(argc, argv, 1);
	if (!config.tokens)
	{
		ft_printf_fd(2, "Error\n");
		exit(1);
	}
	build_stack(&a, &config);
	handle_input(&a, &b, &config);
	check_if_sorted(&a, &b);
	free_stack(&a);
	free_stack(&b);
	free_str_array(config.tokens);
	return (0);
}
