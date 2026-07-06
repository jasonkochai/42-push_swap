/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:03:29 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/18 16:12:06 by jakoch           ###   ########.fr       */
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
	parse_input(argc, argv, &config);
	build_stack(&a, &config);
	compute_disorder(&a, &config);
	strategy_picker(&config);
	if (config.disorder > 0.0f)
		choose_algo(&a, &b, &config);
	if (config.bench == true)
		print_bench(&config);
	if (config.count_only == true)
		ft_printf("%d\n", config.total_ops);
	free_stack(&a);
	free_stack(&b);
	free_str_array(config.tokens);
	return (0);
}
