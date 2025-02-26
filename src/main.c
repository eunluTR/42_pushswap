/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:49:51 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 13:51:08 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	
	check_args(argc, argv);
	allocate_stacks(stack_a, stack_b);
	initStack(stack_a, argv);
	if (is_sorted(*stack_a))
		return (0);
	sort_stack(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	
	return (0);
}
