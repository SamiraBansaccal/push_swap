/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_ranks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:56:35 by sabansac          #+#    #+#             */
/*   Updated: 2024/05/26 04:19:15 by sabansac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *integ1, int *integ2)
{
	int	temp;

	temp = *integ1;
	*integ1 = *integ2;
	*integ2 = temp;
}

void	ft_lstsort(t_list *lst)
{
	int		swapped;
	t_list	*current;
	t_list	*end;

	end = NULL;
	if (!lst)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = lst;
		while (current->next != end)
		{
			if (current->content > current->next->content)
			{
				ft_swap(&(current->content), &(current->next->content));
				swapped = 1;
			}
			current = current->next;
		}
		end = current;
	}
}

int	get_index(long value, t_list *order_lst)
{
	int	i;

	i = 0;
	while (order_lst)
	{
		if (order_lst->content == value)
			return (i);
		order_lst = order_lst->next;
		i++;
	}
	return (-1);
}

void	map_to_ranks(t_list **stack)
{
	t_list	*sorted_stack;
	t_list	*current;

	sorted_stack = ft_lstdup(*stack);
	current = *stack;
	ft_lstsort(sorted_stack);
	while (current)
	{
		current->content = get_index(current->content, sorted_stack);
		current = current->next;
	}
	free_lst(&sorted_stack);
}
