/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:56:48 by emir              #+#    #+#             */
/*   Updated: 2025/02/26 16:58:17 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	third = second->next;
	*stack = second;
	second->next = first;
	first->next = third;
	return (1);
}

void	sa(t_list **stack_a)
{
	if (swap(stack_a))
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	if (swap(stack_b))
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) && swap(stack_b))
		write(1, "ss\n", 3);
}
