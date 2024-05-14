/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 02:00:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/14 01:00:43 by sabansac         ###   ########.fr       */
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
	int	nbr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]))
				j++;
			else
				return (0);
		}
		nbr = ft_atoi(tab[i]);
		if (!(nbr > INT_MIN && nbr < INT_MAX))
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
	free_lst(&stack_a);
	return (0);
}
