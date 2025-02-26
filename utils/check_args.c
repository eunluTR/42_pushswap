/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:29:05 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 20:58:46 by emir             ###   ########.fr       */
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

char	*join_args(char **argv)
{
	char	*joined;
	char	*temp;
	char	*temp2;
	int		i;

	i = 1;
	joined = ft_strdup(""); 
	while (argv[i])
	{
		temp = ft_strjoin(joined, " ");  
		free(joined);
		temp2 = ft_strjoin(temp, argv[i]);
		free(temp);
		joined = temp2;
		i++;
	}
	return (joined);
}

void	check_args(int argc, char **argv)
{
	char	*all_args;
	char	**tokens;
	int		i;

	if (argc < 2)
		exit(0);
	all_args = join_args(argv);
	tokens = ft_split(all_args, ' ');
	free(all_args);
	i = 0;
	while (tokens[i])
	{
		if (!is_num(tokens[i]))
			error_exit();
		if (!is_int(tokens[i]))
			error_exit();
		if (is_in_list(ft_atoi(tokens[i]), tokens, i))
			error_exit();
		i++;
	}
	free_list(tokens);
}
