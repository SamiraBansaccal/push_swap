/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:12:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/19 01:03:41 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void find_min_max_bits(t_list *stack, int *min_bits, int *max_bits)
{
	long	min;
	long	max;
	long	next_value;

	if (!stack)
		return ;
	max = stack->content;
	min = stack->content;
	while (stack)
	{
		next_value = stack->content;
		if (max < next_value)
			max = next_value;
		if (min > next_value)
			min = next_value;
		stack = stack->next;
	}
	*min_bits = 0;
    *max_bits = 0;
    while (min && min != (-1))
	{
		min = min >> 1;
        (*min_bits)++;
	}
    while (max && max != (-1))
	{
		max = max >> 1;
        (*max_bits)++;
	}
}

void	negatives_sort(t_list **stack_a, t_list **stack_b)
{
	int	lstlen;
	int	value;

	lstlen = ft_lstsize(*stack_a);
	while (lstlen - 1)
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

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	len_a;
	int	len_b;
	int	max_bits;
	int min_bits;
	int	bit;
	int	value;

	if (is_sorted(*stack_a) && !*stack_b)
			return ;
	find_min_max_bits(*stack_a, &min_bits, &max_bits);
	min_bits = 0;
	bit = min_bits;
	while (bit < max_bits)
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
		len_b = ft_lstsize(*stack_b);
		bit++;
		/*ft_printf("BITEEEEEUH");*/
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
			return ;/*
		else
			ft_printf("ENSUITE");*/
	}
	negatives_sort(stack_a, stack_b);
	if (is_sorted(*stack_a) && !*stack_b)
		return ;
	/*else
	{
		ft_printf("shit");
		print_list(*stack_a);
		return ;
	}*/
}
