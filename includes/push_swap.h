/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 03:16:48 by sabansac          #+#    #+#             */
/*   Updated: 2024/05/23 04:06:48 by sbansacc         ###   ########.fr       */
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

int		b_is_sorted(t_list *lst);
void	optimised_cmd(char *cmds);
void	radix_sort(t_list **stack_a, t_list **stack_b);
char	*push_swap(char *cmd, t_list **stack_a, t_list **stack_b);
void	print_list(t_list *list);
int		ft_lstlen(t_list *lst);
void	free_lst(t_list **lst);
int		bit0_in_lst(t_list *stack, int bit);

void	double_radix(t_list **stack_a, t_list **stack_b, int bit);

int		is_sorted(t_list *lst);
int		is_uniq(t_list *lst);
int		is_valid(char **tab);

void	mini_sort(t_list **stack_a, t_list **stack_b, int chunk_size);

typedef struct cmd_list
{
	char			*content;
	struct cmd_list	*next;
}	cmd_lst;

#endif