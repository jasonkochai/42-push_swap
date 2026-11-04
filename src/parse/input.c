/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:28:46 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/15 19:01:22 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void config_init(t_config *config)
{
	config->num_start = 1;
	config->strategy = ADAPTIVE; 										// set adaptive as default strategy
	config->strategy_picked = false;
	config->adaptive = false;
	config->bench = false;
	config->checker = false;
	config->tokens = NULL;
	config->disorder = 0.0f;
	config->total_ops = 0;
	config->pa = 0;
	config->pb = 0;
	config->ra = 0;
	config->rb = 0;
	config->rr = 0;
	config->rra = 0;
	config->rrb = 0;
	config->rrr = 0;
	config->sa = 0;
	config->sb = 0;
	config->ss = 0;
}

void	parse_input(int argc, char **argv, t_config *config)
{
	int	i;

	i = 1;
	config_init(config);
	while (i < argc) 													// Loop until argv arguments are numeric
	{
		if (parse_flags(argv[i], config)) 								// check whether argument is a flag and store it
			i++;
		else
			break ;
	}
	config->num_start = i; 												// set numeric start index
	config->tokens = parse_numbers(argc, argv, config->num_start);		// stores **tokens from parse_numbers
	if (!config->tokens) 												// Checks parse_numbers and handles error in case it returns NULL on error
	{
		ft_printf_fd(2, "Error\n");
		exit(1);
	}
}
