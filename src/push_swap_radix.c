/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:12:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/21 02:07:46 by sabansac         ###   ########.fr       */
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

int	negativs_in_lst(t_list *stack)
{
	while (stack)
	{
		if (stack->content < 0)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	negatives_sort(t_list **stack_a, t_list **stack_b)
{
	int	lstlen;
	int	value;

	if (!*stack_a || (!negativs_in_lst(*stack_a) || !negativs_in_lst(*stack_b)))
		return ;
	lstlen = ft_lstsize(*stack_a);
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

int	is_sorted(t_list *lst)
{
	t_list	*current;
	t_list	*next;

	if (!lst || !lst->next)
		return (1);
	current = lst;
	next = current->next;
	while (next && (current->content < next->content))
	{
		current = next;
		next = current->next;
	}
	if (!next)
		return (1);
	else
		return (0);
}

int	bit0_in_lst(t_list *stack, int bit)
{
	while (stack)
	{
		if (!((stack->content >> bit) & 1))
			return (1);
		stack = stack->next;
	}
	return (0);
}

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

void	insertion_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	t_list	*next;

	current = *stack_a;
	next = current->next;
	while (next && !is_sorted(*stack_a))
	{
		if (current->content < next->content)
			push_swap("ra", stack_a, stack_b);
		else
			push_swap("sa", stack_a, stack_b);
		if (is_sorted(*stack_a))
			return ;
		current = *stack_a;
		next = current->next;
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	len_a;
	int	len_b;
	int	max_bit;
	int	bit;
	int	value;

	if (is_sorted(*stack_a) && !*stack_b)
		return ;
	max_bit = find_max_bits(*stack_a);

	bit = max_bit / 4;
	while (bit < max_bit && !is_sorted(*stack_a))
	{
		if (bit0_in_lst(*stack_a, bit))
		{
			len_a = ft_lstsize(*stack_a);
			while (len_a)
			{
				value = (*stack_a)->content;
				len_a--;
				if ((value >> bit) & 1)
					push_swap("ra", stack_a, stack_b);
				else
					push_swap("pb", stack_a, stack_b);
			}
		}
		bit++;
		if (bit1_in_lst(*stack_b, bit))
		{
			len_b = ft_lstsize(*stack_b);
			while (len_b)
			{
				value = (*stack_b)->content;
				len_b--;
				if ((value >> bit) & 1)
					push_swap("pa", stack_a, stack_b);
				else
					push_swap("rb", stack_a, stack_b);
			}
			if (is_sorted(*stack_a) && !*stack_b)
				return ;
		}
	}
	negatives_sort(stack_a, stack_b);
	while (*stack_b)
		push_swap("pa", stack_a, stack_b);
	insertion_sort(stack_a, stack_b);
}
