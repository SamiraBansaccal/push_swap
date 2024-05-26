/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:15:32 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/26 04:48:31 by sabansac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
