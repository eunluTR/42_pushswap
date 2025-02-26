/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:13:16 by emir              #+#    #+#             */
/*   Updated: 2025/02/26 17:14:12 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_last;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second_last = first;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = first;
	*stack = last;
	return (1);
}

void rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a))
		write(1, "rra\n", 4);
}

void rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b))
		write(1, "rrb\n", 4);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate(stack_a) && reverse_rotate(stack_b))
		write(1, "rrr\n", 4);
}
