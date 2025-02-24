/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:27:37 by marvin            #+#    #+#             */
/*   Updated: 2025/02/23 14:27:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

int ft_isdigit(int c);
int ft_atoi(const char *str);
void check_args(int argc, char **argv);
void error_exit(void);
void free_list(char **str);
char **ft_split(char const *s, char c);

#endif