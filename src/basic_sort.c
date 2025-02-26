/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:17:23 by emir              #+#    #+#             */
/*   Updated: 2025/02/26 21:35:26 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void sort_3(t_list **stack)
{
    int a = (*stack)->content;
    int b = (*stack)->next->content;
    int c = (*stack)->next->next->content;

    if (a > b && a < c)
        sa(stack);
    else if (a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > c && b < c)
        ra(stack);
    else if (a < b && a > c)
        rra(stack);
    else if (a < b && b > c)
    {
        sa(stack);
        ra(stack);
    }
}

static void sort_4(t_list **stack_a, t_list **stack_b)
{
    int pos = get_min_pos(*stack_a);
    rotate_to_top(stack_a, pos, ft_lstsize(*stack_a));
    pb(stack_a, stack_b);
    sort_3(stack_a);
    pa(stack_a, stack_b);
}

static void sort_5(t_list **stack_a, t_list **stack_b)
{
    int pos;

    pos = get_min_pos(*stack_a);
    rotate_to_top(stack_a, pos, ft_lstsize(*stack_a));
    pb(stack_a, stack_b);

    pos = get_min_pos(*stack_a);
    rotate_to_top(stack_a, pos, ft_lstsize(*stack_a));
    pb(stack_a, stack_b);

    sort_3(stack_a);

    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}

void basic_sort(t_list **stack_a, t_list **stack_b)
{
    int size = ft_lstsize(*stack_a);

    if (size == 2)
    {
        if ((*stack_a)->content > (*stack_a)->next->content)
            sa(stack_a);
    }
    else if (size == 3)
        sort_3(stack_a);
    else if (size == 4)
        sort_4(stack_a, stack_b);
    else if (size == 5)
        sort_5(stack_a, stack_b);
}
