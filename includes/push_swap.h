/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:27:37 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 13:49:40 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

int ft_isdigit(int c);
int ft_atoi(const char *str);
void check_args(int argc, char **argv);
void error_exit(void);
void free_list(char **str);
void free_stack(t_list **stack);
char **ft_split(char const *s, char c);
t_list *ft_lstnew(int content);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstadd_back(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
void print_list(t_list *lst);
void putnbr(int n);
void init_stack(t_list **stack, char **argv);
void index_stack(t_list **stack);
void sort_stack(t_list **stack_a, t_list **stack_b);
void allocate_stacks(t_list **stack_a, t_list **stack_b);
int is_sorted(t_list *stack);
void free_stacks(t_list **stack_a, t_list **stack_b);

#endif