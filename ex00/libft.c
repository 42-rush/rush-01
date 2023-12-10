/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:00:00 by jkong             #+#    #+#             */
/*   Updated: 1970/01/01 09:00:00 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		;
	return (i);
}

int	ft_puterr(const char *s)
{
	const size_t	len = ft_strlen(s);
	size_t			i;
	ssize_t			result;

	i = 0;
	while (i < len)
	{
		result = write(STDERR_FILENO, &s[i], len - i);
		if (result < 0)
			return (-1);
		i += result;
	}
	return (0);
}

static const bool	g_space[] = {
['\t'] = true,
['\n'] = true,
['\v'] = true,
['\f'] = true,
['\r'] = true,
[' '] = true,
[0xFF] = false,
};

bool	ft_isspace(char c)
{
	return (g_space[(unsigned char)c]);
}

static const bool	g_digit[] = {
['0'] = true,
['1'] = true,
['2'] = true,
['3'] = true,
['4'] = true,
['5'] = true,
['6'] = true,
['7'] = true,
['8'] = true,
['9'] = true,
[0xFF] = false,
};

bool	ft_isdigit(char c)
{
	return (g_digit[(unsigned char)c]);
}
