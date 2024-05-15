/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:12:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/15 06:01:35 by sabansac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstlen(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

int	ft_max_bits(t_list *stack)
{
	int		max_bits;
	int		max_value;
	int		value;
	t_list	*current;

	if (!stack)
		return (0);
	max_bits = 0;
	value = stack->content;
	current = stack->next;
	max_value = stack->content;
	while (current)
	{
		value = current->content;
		if (value > max_value)
			max_value = value;
		current = current->next;
	}
	while (max_value)
	{
		max_value = max_value >> 1;
		max_bits++;
	}
	return (max_bits);
}

void	negatives_sort(t_list **stack_a, t_list **stack_b)
{
	int	lstlen;
	int	value;

	lstlen = ft_lstlen(*stack_a);
	while (lstlen)
	{
		value = (*stack_a)->content;
		if (value > 0)
			push_swap("ra", stack_a, stack_b);
		else
			push_swap("pb", stack_a, stack_b);
		lstlen--;
	}
	while (*stack_b)
		push_swap("pa", stack_a, stack_b);
}
int	is_sort(t_list *lst)
{
	t_list	*current;
	t_list	*next;

	current = lst;
	next = current->next;
	while ((current->content < next->content) && next)
	{
		current = next;
		next = current->next;
	}
	if (!next)
		return (1);
	else
		return (0);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	lstlen;
	int	max_bits;
	int	bit;
	int	value;

	max_bits = ft_max_bits(*stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		lstlen = ft_lstlen(*stack_a);
		while (lstlen)
		{
			value = (*stack_a)->content;
			lstlen--;
			if ((value >> bit) & 1)
				push_swap("ra", stack_a, stack_b);
			else
				push_swap("pb", stack_a, stack_b);
		}
		while (*stack_b)
			push_swap("pa", stack_a, stack_b);
		bit++;
		if (is_sort(*stack_a))
			return ;
	}
	negatives_sort(stack_a, stack_b);
}
