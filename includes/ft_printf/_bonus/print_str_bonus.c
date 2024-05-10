/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:36:00 by sbansacc          #+#    #+#             */
/*   Updated: 2024/04/19 06:29:48 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize != 0)
	{
		i = 0;
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int	print_str(char *argument, int len, int *printed_char)
{
	int	i;

	i = 0;
	while (argument[i] && i < len)
	{
		if (write(1, &argument[i], 1) == (-1))
			return (-1);
		i++;
		(*printed_char)++;
	}
	return (0);
}

int	print_str_bonus(char *argument, t_flags flags)
{
	int		printed_char;
	int		len;
	char	*null;

	null = "(null)";
	if (argument == NULL)
		argument = null;
	printed_char = 0;
	len = ft_strlen(argument);
	if (flags.has_dot && len > flags.precision)
		len = flags.precision;
	if (!flags.has_minus && flags.width)
	{
		while (printed_char < (flags.width - len))
		{
			if (write(1, " ", 1) == (-1))
				return (-1);
			printed_char++;
		}
	}
	if (print_str(argument, len, &printed_char) == (-1))
		return (-1);
	if (print_minus(flags, &printed_char) == (-1))
		return (-1);
	return (printed_char);
}
