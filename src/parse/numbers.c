/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:14:27 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/17 20:04:35 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Make sure ./push_swap 1 2 3 and ./push_swap "1 2 3" behave the same

char	**parse_numbers(int argc, char **argv, int start_index)
{
	int		arg_count;
	int		i;
	char	**tokens;

	arg_count = argc - start_index;
	i = 0;
	if (start_index >= argc) 									// no numeric args after start_index
		return (NULL);
	if (arg_count == 1) 										// one numeric argv entry
	{
		tokens = ft_split(argv[start_index], ' ');				// split "1 2 3" to multiple argv "tokens"
		if (!tokens)
			return (NULL);
		if (!validate_nums(tokens)) 							// check if created tokens are valid
			return (NULL);
		return (tokens);
	}
	if (arg_count > 1) 											// more than one numeric argv entry
	{
		tokens = ft_calloc(arg_count + 1, sizeof(char *)); 		// allocate the tokens, and init all to NULL
		if (!tokens)
			return (NULL);
		while (i < arg_count) 									// do until all args are used up
		{
			tokens[i] = ft_strdup(argv[start_index + i]); 		// duplicate the argument string into tokens
			if (!tokens[i]) 									// if one copy fails,free up what was already allocated and return null
				return (free_str_array(tokens), NULL);
			i++;
		}
		tokens[arg_count] = NULL;   							// NULL-terminate
		if (!validate_nums(tokens)) 							// check if valid
			return (NULL); 
		return (tokens);
	}
	return (NULL);
}
