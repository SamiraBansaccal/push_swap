/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 02:00:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/19 00:28:33 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_lst(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (*lst)
	{
		current = *lst;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	*lst = NULL;
	return ;
}

int	is_uniq(t_list *lst)
{
	t_list	*nbr;
	t_list	*next_nbr;

	while (lst)
	{
		nbr = lst;
		next_nbr = lst->next;
		while (next_nbr)
		{
			if (nbr->content == next_nbr->content)
				return (0);
			next_nbr = next_nbr->next;
		}
		lst = lst->next;
	}
	return (1);
}

int	is_valid(char **tab)
{
	long	nbr;
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '-' && tab[i][j + 1])
			j++;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]))
				j++;
			else
				return (0);
		}
		nbr = ft_atoi(tab[i]);
		if (!(nbr >= INT_MIN && nbr <= INT_MAX))
			return (0);
		i++;
	}
	return (1);
}

t_list	*init_stack(char **tab)
{
	t_list	*head;
	t_list	*new;
	int		nbr;

	head = NULL;
	if (!is_valid(tab))
		return (NULL);
	while (*tab)
	{
		nbr = ft_atoi(*tab);
		new = ft_lstnew(nbr);
		if (!new)
		{
			free_lst(&head);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		tab++;
	}
	if (!is_uniq(head))
	{
		free_lst(&head);
		return (NULL);
	}
	return (head);
}

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

	if (is_sort(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
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

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**tab;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (write(2, "Error\n", 6));
	else if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab)
			return (write(2, "Error\n", 6));
		stack_a = init_stack(tab);
		free_tab(tab);
	}
	else if (ac > 2)
		stack_a = init_stack(++av);
	if (!stack_a)
		return (write(2, "Error\n", 6));
	sort_stack(&stack_a, &stack_b);
	free_lst(&stack_a);
	return (0);
}
