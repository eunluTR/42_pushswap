/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:16:24 by emir              #+#    #+#             */
/*   Updated: 2025/02/26 21:03:48 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_list **stack, char **argv)
{
	char	*all_args;
	char	**arg_list;
	t_list	*new;
	int		i;

	all_args = join_args(argv);
	arg_list = ft_split(all_args, ' ');
	free(all_args);

	i = 0;
	while (arg_list[i])
	{
		new = ft_lstnew(ft_atoi(arg_list[i]));
		new->index = -1;
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	free_list(arg_list);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		basic_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

void	allocate_stacks(t_list **stack_a, t_list **stack_b)
{
	stack_a = (t_list **)malloc(sizeof(t_list));
		if (!stack_a)
			error_exit();
	stack_b = (t_list **)malloc(sizeof(t_list));
		if (!stack_b)
			error_exit();
	*stack_a = NULL;
	*stack_b = NULL;
}

int		is_sorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
}
