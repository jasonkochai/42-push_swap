/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:47:26 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/19 12:16:14 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*

ft_atol: Convert a string to a long. Skips leading whitespace, takes one
optional sign, then reads digits until the first non-digit; anything after
that is ignored, and a string with no digits gives 0. A value outside the
int range saturates instead of overflowing: it returns LONG_MAX (or LONG_MIN
for a negative number), so the caller can reject it with a simple range
check.

convert_digits: The digit loop of ft_atol. It checks against INT_MAX (or
-INT_MIN) before each step, so the long never overflows.

ft_int_sqrt: Integer square root, rounded down: 10 gives 3, 16 gives 4.
Returns 0 for 0 and for negative numbers. The loop divides instead of
multiplying, so root * root cannot overflow.

*/

#include "../inc/push_swap.h"

static long	convert_digits(const char *str, int i, int symbol)
{
	long	result;
	long	limit;
	int		digit;

	result = 0;
	limit = INT_MAX;
	if (symbol < 0)
		limit = -(long)INT_MIN;
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - '0';
		if (result > (limit - digit) / 10)
		{
			if (symbol < 0)
				return (LONG_MIN);
			return (LONG_MAX);
		}
		result = result * 10 + digit;
		i++;
	}
	return (result * symbol);
}

long	ft_atol(const char *str)
{
	int	i;
	int	symbol;

	i = 0;
	symbol = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			symbol = -symbol;
		i++;
	}
	return (convert_digits(str, i, symbol));
}

int	ft_int_sqrt(int number)
{
	int	root;

	if (number <= 0)
		return (0);
	if (number == 1)
		return (1);
	root = 0;
	while (root + 1 <= number / (root + 1))
		root++;
	return (root);
}
