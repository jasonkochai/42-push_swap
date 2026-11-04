/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:03:29 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/17 18:54:36 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack a;  								// Create stacks
	t_stack b;
	t_config config;

	if (argc == 1)
		return (0); 							// no parameters 
	stack_init(&a); 							// initialize stack a
	stack_init(&b); 							// init stack b
	parse_input(argc, argv, &config); 			// parse to check whether flags are present, string needs to be split, checking correct input, range and dupes
	build_stack(&a, &config); 					// build stack a
	compute_disorder(&a, &config);				// compute disorder, check if sorted (disorder 0)
	strategy_picker(&config);					// set either forced strategy or adaptive default based on disorder
	if (config.disorder > 0.0f)
		choose_algo(&a, &b, &config);			// run algo
	if (config.bench == true)
		print_bench(&config);					// print bench
	free_stack(&a);								// free everything
	free_stack(&b);
	free_str_array(config.tokens);
	return (0);
}
