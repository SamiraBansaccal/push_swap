/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:23:04 by sbansacc          #+#    #+#             */
/*   Updated: 2024/04/21 04:08:36 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf_bonus.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*interb;

	i = 0;
	interb = (char *)b;
	while (i < len)
	{
		interb[i] = (char)c;
		i++;
	}
	return (b);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
