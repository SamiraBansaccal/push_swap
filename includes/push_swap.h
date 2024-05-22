/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 03:16:48 by sabansac          #+#    #+#             */
/*   Updated: 2024/05/21 23:31:36 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft.h"
# include "./ft_printf.h"

void	radix_sort(t_list **stack_a, t_list **stack_b);
int		push_swap(char *cmd, t_list **stack_a, t_list **stack_b);
void	print_list(t_list *list);
int		ft_lstlen(t_list *lst);

void	double_radix(t_list **stack_a, t_list **stack_b, int bit);

int		is_sorted(t_list *lst);
int		is_uniq(t_list *lst);
int		is_valid(char **tab);

void	simple_sort(t_list **stack_a, t_list **stack_b);

#endif