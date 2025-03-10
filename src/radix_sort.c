/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:17:14 by emir              #+#    #+#             */
/*   Updated: 2025/03/08 07:53:08 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
