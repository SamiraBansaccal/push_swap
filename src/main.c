/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 02:00:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/11 19:52:05 by sbansacc         ###   ########.fr       */
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

int	is_uniq(char **tab)
{
	while (*tab)
	{
		tab++
	}
	
}

int	is_valid_tab(char **tab)
{
	if (!is_uniq(tab))
		return (0);
	while (*tab)
	{
		if (!(ft_atoi(*tab) >= INT_MIN) && !(ft_atoi(*tab) <= INT_MAX))
			return (0);
		tab++;
	}
	return (1);
}

t_list	*init_stack(char **tab)
{
	t_list	*head;
	t_list	*new;

	head = NULL;
	if (!is_valid_tab(tab))
		return (NULL);
	while (*tab)
	{
		new = ft_lstnew(ft_atoi(*tab));
		if (!new)
		{
			free_lst(&head);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		tab++;
	}
	return (head);
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
		stack_a = init_stack(av);
	if (!stack_a)
		return (write(2, "Error\n", 6));
	radix_sort(&stack_a, &stack_b);
	print_list(stack_a);
	free_lst(&stack_a);
	return (0);
}
