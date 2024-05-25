/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 02:00:55 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/23 02:03:51 by sbansacc         ###   ########.fr       */
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

t_list *ft_lstdup(t_list *lst)
{
    t_list	*new_lst;
	
	new_lst = NULL;
    while (lst)
    {
        ft_lstadd_back(&new_lst, ft_lstnew(lst->content));
        lst = lst->next;
    }
    return (new_lst);
}

// Fonction pour trier une liste chaînée (tri à bulle pour la simplicité)
void ft_lstsort(t_list *lst)
{
    int swapped;
    t_list *ptr;
    t_list *lptr = NULL;

    if (!lst)
        return;

    do
    {
        swapped = 0;
        ptr = lst;

        while (ptr->next != lptr)
        {
            if (ptr->content > ptr->next->content)
            {
                long temp = ptr->content;
                ptr->content = ptr->next->content;
                ptr->next->content = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

int get_index(long value, t_list *order_lst)
{
    int	i;

	i = 0;
    while (order_lst)
    {
        if (order_lst->content == value)
            return i;
        order_lst = order_lst->next;
        i++;
    }
    return -1;
}

void map_to_ranks(t_list **stack)
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
