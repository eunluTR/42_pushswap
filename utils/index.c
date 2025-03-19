/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:21:29 by emir              #+#    #+#             */
/*   Updated: 2025/03/19 12:39:23 by eunlu            ###   ########.fr       */
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

int	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
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
