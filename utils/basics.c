/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:33:09 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 19:23:50 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
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

void print_list(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		putnbr(current->content);
		current = current->next;
	}
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*p1;
	int		i;

	len = ft_strlen(s1);
	p1 = malloc(len + 1);
	if (!p1)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p1[i] = s1[i];
		++i;
	}
	p1[len] = '\0';
	return (p1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = malloc(len_s1 + len_s2 + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}
