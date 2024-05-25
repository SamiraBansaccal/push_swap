/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:46:58 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/25 04:13:14 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void optimise_pa_pb(char **cmds)
{
    char *to_optimise;
    char *new_part;
    char *temp;

    while ((to_optimise = ft_strnstr(*cmds, "pa\npb\n", ft_strlen(*cmds))) ||
           (to_optimise = ft_strnstr(*cmds, "pb\npa\n", ft_strlen(*cmds))))
    {
        new_part = to_optimise + 6;
        *to_optimise = '\0';
        temp = ft_strjoin(*cmds, new_part);
        free(*cmds);
        *cmds = temp;
    }
}

void optimise_ra_rb(char **cmds)
{
    char *to_optimise;
    char *new_part;
    char *temp;
	char *final;

    while ((to_optimise = ft_strnstr(*cmds, "ra\nrb\n", ft_strlen(*cmds))) ||
           (to_optimise = ft_strnstr(*cmds, "rb\nra\n", ft_strlen(*cmds))))
    {
        new_part = to_optimise + 6;
        *to_optimise = '\0';
        temp = ft_strjoin(*cmds, "rr\n");
        final = ft_strjoin(temp, new_part);
        free(temp);
        free(*cmds);
        *cmds = final;
    }
}

void optimised_cmd(char *cmds)
{
    char *optimised_cmds = ft_strdup(cmds);

    if (!optimised_cmds)
        return;

    while (ft_strnstr(optimised_cmds, "pa\npb\n", ft_strlen(optimised_cmds)) ||
           ft_strnstr(optimised_cmds, "pb\npa\n", ft_strlen(optimised_cmds)) ||
           ft_strnstr(optimised_cmds, "ra\nrb\n", ft_strlen(optimised_cmds)) ||
           ft_strnstr(optimised_cmds, "rb\nra\n", ft_strlen(optimised_cmds)))
    {
        optimise_pa_pb(&optimised_cmds);
        optimise_ra_rb(&optimised_cmds);
    }

    *(optimised_cmds + ft_strlen(optimised_cmds) - 1) = '\0';
    ft_printf("%s\n", optimised_cmds);
    free(optimised_cmds);
}

/*
void	optimise_pa_pb(char **cmds)
{
	char	*to_optimise;
	char	*new_part;
	
	while (ft_strnstr(*cmds, "pa\npb\n", ft_strlen(*cmds)))
	{
		to_optimise = ft_strnstr(*cmds, "pa\npb\n", ft_strlen(*cmds));
		new_part = to_optimise +  6;
		*to_optimise = 0;
		*cmds = ft_strjoin(*cmds, new_part);
	}
	while (ft_strnstr(*cmds, "pb\npa\n", ft_strlen(*cmds)))
	{
		to_optimise = ft_strnstr(*cmds, "pb\npa\n", ft_strlen(*cmds));
		new_part = to_optimise +  6;
		*to_optimise = 0;
		*cmds = ft_strjoin(*cmds, new_part);
	}
}

void	optimise_ra_rb(char **cmds)
{
	char	*to_optimise;
	char	*new_part;
	char	*temp;

	while (ft_strnstr(*cmds, "ra\nrb\n", ft_strlen(*cmds)) || 
		(ft_strnstr(*cmds, "rb\nra\n", ft_strlen(*cmds))))
	{
		while (ft_strnstr(*cmds, "ra\nrb\n", ft_strlen(*cmds)))
		{
			to_optimise = ft_strnstr(*cmds, "ra\nrb\n", ft_strlen(*cmds));
			new_part = to_optimise +  6;
			*to_optimise = 0;
			temp = ft_strjoin(*cmds, "rr\n");
			free(*cmds);
			*cmds = ft_strjoin(temp, new_part);
			free(temp);
		}
		while (ft_strnstr(*cmds, "rb\nra\n", ft_strlen(*cmds)))
		{
			to_optimise = ft_strnstr(*cmds, "pb\npa\n", ft_strlen(*cmds));
			new_part = to_optimise +  6;
			*to_optimise = 0;
			temp = ft_strjoin(*cmds, "rr\n");
			free(*cmds);
			*cmds = ft_strjoin(temp, new_part);
			free(temp);
		}
	}
}

void	optimised_cmd(char *cmds)
{
	while (ft_strnstr(cmds, "pa\npb\n", ft_strlen(cmds)) ||
		ft_strnstr(cmds, "pb\npa\n", ft_strlen(cmds)) ||
		ft_strnstr(cmds, "ra\nrb\n", ft_strlen(cmds)) ||
		ft_strnstr(cmds, "rb\nra\n", ft_strlen(cmds)))
	{
		optimise_pa_pb(&cmds);
		optimise_ra_rb(&cmds);
	}
	*(cmds + ft_strlen(cmds) - 1) = 0;
	ft_printf("%s\n", cmds);
	free(cmds);
}*/