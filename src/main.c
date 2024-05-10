/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 02:00:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/10 20:42:39 by sabansac         ###   ########.fr       */
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

int	is_valid_nbr(char *tab)
{
	if (*tab == '-')
		tab++;
	while (*tab)
	{
		if (!ft_isdigit(*tab))
			return (-1);
		tab++;
	}
	return (0);
}

t_list	*init_stack(char **tab)
{
	t_list	*head;
	t_list	*new;

	head = NULL;
	while (*tab)
	{
		if (!is_valid_nbr(*tab))
			return (NULL);
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
	{
		stack_a = init_stack(av);
	}
	if (!stack_a)
		return (write(2, "Error\n", 6));
	radix_sort(&stack_a, &stack_b);
	print_list(stack_a);
	free_lst(&stack_a);
	return (0);
}
