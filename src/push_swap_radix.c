/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:12:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/08 19:42:44 by sbansacc         ###   ########.fr       */
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

int	max_bits(t_list *stack)
{
	int	max_bits;
	int	max_value;
	int	current;
	int	next;

	max_bits = 0;
	current = stack->content;
	next = stack->next->next;
	max_value = current;
	while (next)
	{
		if (current < next)
			max_value = next;
		current = next;
		next = next->next->content;
	}
	while (max_value)
	{
		max_value = max_value >> 1;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	lstlen;
	int	max_bits;
	int	bit;
	int	i;
	int	value;

	lstlen = lstlen(*stack_a);
	max_bits = max_bits(stack_a);
	bit = 0;
	i = 0;
	while (bit < max_bits)
	{
		while (i < lstlen)
		{
			value = stack_a->content;
			if (value >> bit & 1)
				push_swap("ra", stack_a, stack_b);
			else
				push_swap("pb", stack_a, stack_b);
			i++;
		}
		while (*stack_b)
			push_swap("pa", stack_a, stack_b);
		bit++;
	}
}

