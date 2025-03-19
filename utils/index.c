/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:21:29 by emir              #+#    #+#             */
/*   Updated: 2025/03/19 12:29:07 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*get_min(t_list **stack)
{
	t_list	*min;
	t_list	*current;

	min = NULL;
	current = *stack;
	while (current)
	{
		if (current->index == -1)
		{
			if (!min || current->content < min->content)
				min = current;
		}
		current = current->next;
	}
	return (min);
}

int	get_min_pos(t_list *stack)
{
	int		min_val;
	int		min_pos;
	int		i;
	t_list	*current;

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

int	check_empty_input(char *input)
{
	int	i;

	i = 0;
	if (input == NULL || input[0] == '\0')
		return (0);
	while (input[i] == ' ')
		i++;
	if (input[i] == '\0')
		return (0);
	return (1);
}

void	index_stack(t_list **stack)
{
	t_list	*min;
	int		i;

	i = 0;
	min = get_min(stack);
	while (min != NULL)
	{
		min->index = i;
		i++;
		min = get_min(stack);
	}
}
