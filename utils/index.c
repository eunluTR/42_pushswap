/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:21:29 by emir              #+#    #+#             */
/*   Updated: 2025/03/05 12:45:36 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*get_min(t_list **stack)
{
    t_list *min;
    t_list *current;

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

void index_stack(t_list **stack)
{
    t_list *min;
    int i = 0;
    while ((min = get_min(stack)) != NULL)
    {
        min->index = i;
        i++;
    }
}
