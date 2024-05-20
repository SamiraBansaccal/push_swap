/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:12:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/20 02:37:47 by sabansac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_max_bits(t_list *stack)
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

void	negatives_sort(t_list **stack_a, t_list **stack_b)
{
	int	lstlen;
	int	value;

	if (!*stack_a)
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

void insertion_sort(t_list **stack_a, t_list **stack_b) 
{
    // Assurez-vous que cette fonction utilise des méthodes appropriées pour votre structure de données
    t_list *next;

	while (*stack_a)
	{
		push_swap("pb", stack_a, stack_b);
        next = (*stack_a)->next;
        // Trouver la position correcte dans la liste triée
        while (*stack_b && (*stack_b)->content < (*stack_a)->content)
            push_swap("rb", stack_a, stack_b);
        // Insérer l'élément courant dans la liste triée
        push_swap("rb", stack_a, stack_b);
    }
    while (*stack_b)
			push_swap("pa", stack_a, stack_b);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	len_a;
	int	bit;
	int	value;

	if (is_sorted(*stack_a) && !*stack_b)
		return ;
	bit = find_max_bits(*stack_a);
	while (bit > 0)
	{
		len_a = ft_lstsize(*stack_a);
		while (len_a)
		{
			value = (*stack_a)->content;
			if (((value >> bit) & 3) < 2)
				push_swap("pb", stack_a, stack_b);
			else
				push_swap("ra", stack_a, stack_b);
			len_a--;
		}
		while (*stack_b)
			push_swap("pa", stack_a, stack_b);
		if (is_sorted(*stack_a) && !*stack_b)
			return ;
		bit -= 2;
	}
	printf("SHIT\n");
	print_list(*stack_a);
	insertion_sort(stack_a, stack_b);
	if (is_sorted(*stack_a) && !*stack_b)
		return ;
	else
	{
		printf("SHIT");
		print_list(*stack_a);
	}
}
