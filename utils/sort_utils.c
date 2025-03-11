/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:31:09 by emir              #+#    #+#             */
/*   Updated: 2025/03/12 01:11:11 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_bits(t_list *stack)
{
	int	max_index;
	int	bits;

	max_index = 0;
	bits = 0;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	rotate_to_top(t_list **stack, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(stack);
			pos++;
		}
	}
}

static int	int_log2(int n)
{
	int	bits;

	bits = 0;
	while (n > 1)
	{
		n >>= 1;
		bits++;
	}
	return (bits);
}

int	estimate_radix_sort(int n)
{
	int	bits;

	bits = int_log2(n);
	return (2 * n * bits);
}

int	estimate_pop_min_sort(int n)
{
	if (n <= 3)
		return (n);
	return ((n + 1) * (n - 3) + 4 + (n - 3));
}
