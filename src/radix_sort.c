/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:17:14 by emir              #+#    #+#             */
/*   Updated: 2025/02/26 17:17:16 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_list *stack)
{
	int		max;
	int		bits;
	int		tmp;

	max = 0;
	while (stack)
	{
		tmp = stack->content;
		bits = 0;
		while (tmp)
		{
			tmp >>= 1;
			bits++;
		}
		if (bits > max)
			max = bits;
		stack = stack->next;
	}
	return (max);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		max_bits;
	int		bit;

	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		bit = 1 << i;
		while (*stack_a)
		{
			if ((*stack_a)->content & bit)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		++i;
	}
}
