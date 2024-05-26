/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:16:09 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/26 02:11:50 by sabansac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		push_swap("sa", stack_a, NULL);
	if (!is_sorted(*stack_a))
		push_swap("rra", stack_a, NULL);
	if (!is_sorted(*stack_a))
		push_swap("sa", stack_a, NULL);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	found;

	found = 0;
	while (found < 2)
	{
		if ((*stack_a)->content > 1)
			push_swap("ra", stack_a, stack_b);
		else
		{
			push_swap("pb", stack_a, stack_b);
			found++;
		}
	}
	sort_3(stack_a);
	if (!b_is_sorted(*stack_b))
		push_swap("sb", stack_a, stack_b);
	while (found != 0)
	{
		push_swap("pa", stack_a, stack_b);
		found--;
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->content == 2)
		push_swap("sa", stack_a, stack_b);
	push_swap("pb", stack_a, stack_b);
	sort_3(stack_a);
	push_swap("pa", stack_a, stack_b);
	if (!is_sorted(*stack_a))
	{
		if ((*stack_a)->content == 1)
			push_swap("sa", stack_a, stack_b);
		if ((*stack_a)->content == 3)
			push_swap("ra", stack_a, stack_b);
	}
}

void	mini_sort(t_list **stack_a, t_list **stack_b, int lstsize)
{
	if (lstsize == 2)
		push_swap("sa", stack_a, stack_b);
	else if (lstsize == 3)
		sort_3(stack_a);
	else if (lstsize == 4)
		sort_4(stack_a, stack_b);
	else if (lstsize == 5)
		sort_5(stack_a, stack_b);
}
