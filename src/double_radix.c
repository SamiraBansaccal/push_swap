/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_radix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:15:49 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/21 23:34:39 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	bit1_in_lst(t_list *stack, int bit)
{
	while (stack)
	{
		if ((stack->content >> bit) & 1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	double_radix(t_list **stack_a, t_list **stack_b, int bit)
{
	int	value;
	int	len_b;

	if (bit1_in_lst(*stack_b, bit))
	{
		len_b = ft_lstsize(*stack_b);
		while (len_b--)
		{
			value = (*stack_b)->content;
			if ((value >> bit) & 1)
				push_swap("pa", stack_a, stack_b);
			else
				push_swap("rb", stack_a, stack_b);
		}
	}
	if (is_sorted(*stack_a) && !*stack_b)
		return ;
}
