/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:49:51 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 17:26:19 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv);
	allocate_stacks(stack_a, stack_b);
	init_stack(stack_a, argv);
	if (is_sorted(*stack_a))
		return (0);
	sort_stack(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	
	return (0);
}
