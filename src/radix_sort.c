/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:17:14 by emir              #+#    #+#             */
/*   Updated: 2025/02/26 18:58:05 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_list *stack)
{
	int max = 0;
	while (stack)
	{
		int tmp = stack->content;
		int bits = 0;
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
	int	i;
	int	max_bits;
	int	size;
	int	j;

	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		size = ft_lstsize(*stack_a);
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->content >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);    // *stack_b*'deki her şeyi geri al
		i++;
	}
}
