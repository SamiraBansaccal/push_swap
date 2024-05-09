/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 03:16:48 by sabansac          #+#    #+#             */
/*   Updated: 2024/05/09 05:41:04 by sabansac         ###   ########.fr       */
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

#endif