/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 03:16:48 by sabansac          #+#    #+#             */
/*   Updated: 2024/05/26 05:00:45 by sabansac         ###   ########.fr       */
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

/*---------------------arg_validity------------------------*/

int		is_sorted(t_list *lst);
int		b_is_sorted(t_list *lst);
int		is_uniq(t_list *lst);
int		is_valid(char **tab);

/*---------------------map_to_ranks-------------------------*/

void	map_to_ranks(t_list **stack);

/*---------------------malloc_stuff-------------------------*/

void	free_lst(t_list **lst);
void	free_tab(char **tab);
t_list	*ft_lstdup(t_list *lst);

/*---------------------push_swap-----------------------------*/
char	*push_swap(char *cmd, t_list **stack_a, t_list **stack_b);
int		ps(char *cmd, t_list **stack_a, t_list **stack_b);

/*---------------------optimised_cmd-------------------------*/

void	optimised_cmd(char *cmds);

/*---------------------minisort------------------------------*/

void	mini_sort(t_list **stack_a, t_list **stack_b, int chunk_size);

/*---------------------radix_sort----------------------------*/

void	radix_sort(t_list **stack_a, t_list **stack_b);

/*---------------------double_radix--------------------------*/

void	double_radix(t_list **stack_a, t_list **stack_b, int bit);

#endif