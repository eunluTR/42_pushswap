/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:27 by emir              #+#    #+#             */
/*   Updated: 2025/02/26 17:11:51 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_list **src, t_list **dst)
{
	t_list	*first;

	if (!*src)
		return (0);
	first = *src;
	*src = first->next;
	first->next = *dst;
	*dst = first;
	return (1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a))
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b))
		write(1, "pb\n", 3);
}
