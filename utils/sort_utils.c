/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:31:09 by emir              #+#    #+#             */
/*   Updated: 2025/02/26 21:37:57 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_min_pos(t_list *stack)
{
    int     min_val;
    int     min_pos;
    int     i;
    t_list  *current;

    min_val = stack->content;
    min_pos = 0;
    i = 0;
    current = stack;
    while (current)
    {
        if (current->content < min_val)
        {
            min_val = current->content;
            min_pos = i;
        }
        current = current->next;
        i++;
    }
    return (min_pos);
}

int	get_max_bits(t_list *stack)
{
	int	max_bits = 0;

	while (stack)
	{
		int	val = stack->content;
		int	bits = 0;

		if (val < 0)
			val = -val;

		while (val != 0)
		{
			val >>= 1;
			bits++;
		}
		if (bits > max_bits)
			max_bits = bits;
		stack = stack->next;
	}
	return (max_bits);
}

void rotate_to_top(t_list **stack, int pos, int size)
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
