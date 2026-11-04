/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:56:23 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/17 16:38:20 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack a;  										// Create stacks
	t_stack b;
	t_config config;

	if (argc == 1)
		return (0); 									// no parameters 
	stack_init(&a); 									// initialize stack a
	stack_init(&b); 									// init stack b
	config.checker = true;								// sets checker to be active, needed for checking in ops
	config.tokens = NULL;								// init tokens
	config.tokens = parse_numbers(argc, argv, 1);       // parse input, make sure valid input (this time no flag parsing just number validation)
	if (!config.tokens)
	{
		ft_printf_fd(2, "Error\n");
		exit(1);
	}
	build_stack(&a, &config);							// build stack a
	handle_input(&a, &b, &config);						// use get_next_line to read from stdin, check that each input is an operation and execute it
	check_if_sorted(&a, &b);							// implement a function that checks if after the input it is sorted (OK, KO print)
	free_stack(&a);										// free everything
	free_stack(&b);
	free_str_array(config.tokens);
	return (0);
}
