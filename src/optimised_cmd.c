/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:46:58 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/26 04:45:10 by sabansac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	optimise_pa_pb(char **cmds)
{
	char	*to_optimise;
	char	*new_cmds;
	char	*part2;

	while (ft_strnstr(*cmds, "pa\npb\n", ft_strlen(*cmds))
		|| (ft_strnstr(*cmds, "pb\npa\n", ft_strlen(*cmds))))
	{
		to_optimise = ft_strnstr(*cmds, "pa\npb\n", ft_strlen(*cmds));
		if (!to_optimise)
			to_optimise = ft_strnstr(*cmds, "pb\npa\n", ft_strlen(*cmds));
		part2 = to_optimise + 6;
		*to_optimise = '\0';
		new_cmds = ft_strjoin(*cmds, part2);
		free(*cmds);
		*cmds = new_cmds;
	}
}

void	optimise_ra_rb(char **cmds)
{
	char	*to_optimise;
	char	*part2;
	char	*part1;
	char	*new_cmds;

	while (ft_strnstr(*cmds, "ra\nrb\n", ft_strlen(*cmds))
		|| (ft_strnstr(*cmds, "rb\nra\n", ft_strlen(*cmds))))
	{
		to_optimise = ft_strnstr(*cmds, "ra\nrb\n", ft_strlen(*cmds));
		if (!to_optimise)
			to_optimise = ft_strnstr(*cmds, "rb\nra\n", ft_strlen(*cmds));
		part2 = to_optimise + 6;
		*to_optimise = '\0';
		part1 = ft_strjoin(*cmds, "rr\n");
		new_cmds = ft_strjoin(part1, part2);
		free(part1);
		free(*cmds);
		*cmds = new_cmds;
	}
}

void	optimised_cmd(char *cmds)
{
	if (!cmds)
		return ;
	while (ft_strnstr(cmds, "pa\npb\n", ft_strlen(cmds))
		|| ft_strnstr(cmds, "pb\npa\n", ft_strlen(cmds))
		|| ft_strnstr(cmds, "ra\nrb\n", ft_strlen(cmds))
		|| ft_strnstr(cmds, "rb\nra\n", ft_strlen(cmds)))
	{
		optimise_pa_pb(&cmds);
		optimise_ra_rb(&cmds);
	}
	*(cmds + ft_strlen(cmds) - 1) = '\0';
	ft_printf("%s\n", cmds);
	free(cmds);
}
