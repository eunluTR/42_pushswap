/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:29:05 by marvin            #+#    #+#             */
/*   Updated: 2025/02/23 14:29:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int 	is_in_list(int num, char **argv, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (ft_atoi(argv[j]) == num)
			return (1);
		j++;
	}
	return (0);
}

static int	is_num(char *num)
{
	int i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_int(char *num)
{
	long	tmp;

	tmp = ft_atoi(num);
	if (tmp > 2147483647 || tmp < -2147483648)
		return (0);
	return (1);
}

void	check_args(int argc, char **argv)
{
	int		i;
	char	**arg_list;

	if (argc == 1)
		exit(0);
	if (argc != 2)
		error_exit();
	arg_list = ft_split(argv[1], ' ');
	i = 0;
	while (arg_list[i])
	{
		if (!is_num(arg_list[i]))
			error_exit();
		if (!is_int(arg_list[i]))
			error_exit();
		if (is_in_list(ft_atoi(arg_list[i]), arg_list, i))
			error_exit();
		i++;
	}
	free_list(arg_list);
}
