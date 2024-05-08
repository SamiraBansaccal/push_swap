/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 02:00:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/02 22:05:00 by sbansacc         ###   ########.fr       */
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
			tab[i++];
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
int	stack_is_valid(t_list *stack)
{

}

t_list	*init_stack(char **tab)
{
	t_list	*head;
	t_list	*new;

	head = NULL;
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
		stack_a = init_stack(av + 1);
	if (!stack_is_valid(stack_a))
		return (write(2, "Error\n", 6));
	stack_b = NULL;
	radix_sort(&stack_a, &stack_b);
	free_lst(stack_a);
	return (0);
}
