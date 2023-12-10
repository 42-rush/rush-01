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
	while (s[i])
		i++;
	return (i);
}

void	ft_puterr(const char *s)
{
	const size_t	len = ft_strlen(s);
	size_t			i;
	ssize_t			result;

	i = 0;
	while (i < len)
	{
		result = write(STDERR_FILENO, &s[i], len - i);
		if (result < 0)
			return ;
		i += result;
	}
}

static const bool g_space[] = {
	['\t'] = true,
	['\n'] = true,
	['\v'] = true,
	['\f'] = true,
	['\r'] = true,
	[' '] = true,
};

bool ft_isspace(char c)
{
	return (g_space[c]);
}
