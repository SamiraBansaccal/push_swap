/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 02:00:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/26 04:36:10 by sabansac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*push_swap(char *cmd, t_list **stack_a, t_list **stack_b)
{
	static char	*cmd_lst;
	char		*temp;

	if (!cmd_lst)
		cmd_lst = ft_strdup("");
	if ((ft_strncmp(cmd, "cmd", 2) == 0))
		return (cmd_lst);
	else if (ps(cmd, stack_a, stack_b) == 0)
	{
		cmd_lst = ft_strjoin(cmd_lst, cmd);
		temp = ft_strjoin(cmd_lst, "\n");
		free(cmd_lst);
		cmd_lst = temp;
	}
	return (NULL);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	char	*cmd_lst;

	if (is_sorted(*stack_a) && !*stack_b)
		return ;
	map_to_ranks(stack_a);
	if (ft_lstsize(*stack_a) <= 5)
		mini_sort(stack_a, stack_b, ft_lstsize(*stack_a));
	else
		radix_sort(stack_a, stack_b);
	cmd_lst = push_swap("cmd", NULL, NULL);
	optimised_cmd(cmd_lst);
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
		stack_a = init_stack(++av);
	if (!stack_a)
		return (write(2, "Error\n", 6));
	sort_stack(&stack_a, &stack_b);
	free_lst(&stack_a);
	return (0);
}
