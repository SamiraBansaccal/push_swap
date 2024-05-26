/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:12:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/26 02:08:20 by sabansac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max_bits(t_list *stack)
{
	long	max;
	long	next_value;
	int		max_bits;

	max_bits = 0;
	if (!stack)
		return (0);
	max = stack->content;
	while (stack)
	{
		next_value = stack->content;
		if (max < next_value)
			max = next_value;
		stack = stack->next;
	}
	while (max && max != (-1))
	{
		max = max >> 1;
		max_bits++;
	}
	return (max_bits);
}

int	bit0_in_lst(t_list *stack, int bit)
{
	while (stack)
	{
		if (((stack->content >> bit) & 1) == 0)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	len_a;
	int	max_bit;
	int	bit;

	max_bit = find_max_bits(*stack_a);
	bit = 0;
	while (bit < max_bit && !is_sorted(*stack_a))
	{
		len_a = ft_lstsize(*stack_a);
		if (bit0_in_lst(*stack_a, bit))
		{
			while (len_a--)
			{
				if (((*stack_a)->content >> bit) & 1)
					push_swap("ra", stack_a, stack_b);
				else
					push_swap("pb", stack_a, stack_b);
			}
		}
		bit++;
		double_radix(stack_a, stack_b, bit);
	}
	while (*stack_b)
		push_swap("pa", stack_a, stack_b);
}
