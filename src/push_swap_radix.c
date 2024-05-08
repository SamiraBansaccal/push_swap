/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:12:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/02 22:05:36 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lstlen(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
		lst = lst->next;
	return (len);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	lstlen;
	int	max_bits;

	lstlen = lstlen(*stack_a);
	max_bits = 0;
	
}
