/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:17:23 by emir              #+#    #+#             */
/*   Updated: 2025/02/26 18:53:47 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int 	get_min(t_list *stack)
{
	int		min;
	t_list	*current;

	min = stack->content;
	current = stack;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}

static void	sort_3(t_list **stack)
{
	int		min;

	min = get_min(*stack);
	if ((*stack)->content == min)
	{
		if ((*stack)->next->content > (*stack)->next->next->content)
			sa(stack);
	}
	else if ((*stack)->next->content == min)
	{
		ra(stack);
		if ((*stack)->content > (*stack)->next->content)
			sa(stack);
	}
	else
	{
		rra(stack);
		if ((*stack)->content < (*stack)->next->content)
			sa(stack);
	}
}

static void sort_4(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		max;
	int		i;

	i = 0;
	while (i < 2)
	{
		min = get_min(*stack_a);
		max = ft_lstlast(*stack_a)->content;
		if ((*stack_a)->content == min || (*stack_a)->content == max)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		++i;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

static void sort_5(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		max;
	int		i;

	i = 0;
	while (i < 3)
	{
		min = get_min(*stack_a);
		max = ft_lstlast(*stack_a)->content;
		if ((*stack_a)->content == min || (*stack_a)->content == max)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		++i;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void basic_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 3)
		sort_3(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_5(stack_a, stack_b);
}
