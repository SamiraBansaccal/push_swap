/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:16:09 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/21 23:16:14 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	get_distance(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->content == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	is_sort(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (!(*lst) || !(*lst)->next)
		return (1);
	current = *lst;
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

static int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->content;
	while (head->next)
	{
		head = head->next;
		if ((head->content < min) && head->content != val)
			min = head->content;
	}
	return (min);
}

static void	sort_3(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sort(stack_a))
		return ;
	if (head->content == min && head->next->content != next_min)
	{
		push_swap("ra", stack_a, stack_b);
		push_swap("sa", stack_a, stack_b);
		push_swap("rra", stack_a, stack_b);
	}
	else if (head->content == next_min)
	{
		if (head->next->content == min)
			push_swap("sa", stack_a, stack_b);
		else
			push_swap("rra", stack_a, stack_b);
	}
	else
	{
		if (head->next->content == min)
			push_swap("ra", stack_a, stack_b);
		else
		{
			push_swap("sa", stack_a, stack_b);
			push_swap("rra", stack_a, stack_b);
		}
	}
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sort(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		push_swap("ra", stack_a, stack_b);
	else if (distance == 2)
	{
		push_swap("ra", stack_a, stack_b);
		push_swap("ra", stack_a, stack_b);
	}
	else if (distance == 3)
		push_swap("rra", stack_a, stack_b);
	if (is_sort(stack_a))
		return ;
	push_swap("pb", stack_a, stack_b);
	sort_3(stack_a, stack_b);
	push_swap("pa", stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		push_swap("ra", stack_a, stack_b);
	else if (distance == 2)
	{
		push_swap("ra", stack_a, stack_b);
		push_swap("ra", stack_a, stack_b);
	}
	else if (distance == 3)
	{
		push_swap("rra", stack_a, stack_b);
		push_swap("rra", stack_a, stack_b);
	}
	else if (distance == 4)
		push_swap("rra", stack_a, stack_b);
	if (is_sort(stack_a))
		return ;
	push_swap("pb", stack_a, stack_b);
	sort_4(stack_a, stack_b);
	push_swap("pa", stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		push_swap("sa", stack_a, stack_b);
	else if (size == 3)
		sort_3(stack_a, stack_b);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}