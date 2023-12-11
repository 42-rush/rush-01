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

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "vector.h"
#include "rush.h"

static size_t	_uint_length(unsigned int n)
{
	static const unsigned int	radix = 10U;
	size_t						i;

	i = n == 0U;
	while (n != 0U)
	{
		i++;
		n /= radix;
	}
	return (i);
}

static bool	_uint_try_parse(const char *s, size_t len, unsigned int *out_value)
{
	unsigned long	number;
	size_t			i;

	if (len > _uint_length(UINT_MAX))
		return (false);
	i = 0;
	number = 0UL;
	while (i < len && s[i] != '\0')
		number = 10UL * number + (s[i++] - '0');
	if (number > UINT_MAX)
		return (false);
	*out_value = number;
	return (true);
}

static bool	_parse_argument(t_vector *vector, const char *s)
{
	size_t			i;
	unsigned int	value;

	i = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		if (!*s)
			break ;
		i = 0;
		while (ft_isdigit(s[i]))
			i++;
		if ((s[i] != '\0' && !ft_isspace(s[i]))
			|| !_uint_try_parse(s, i, &value)
			|| !vector_push(vector, value))
			return (false);
		s += i;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_vector	vector;
	int			exit_status;

	if (argc != 2)
	{
		(void)ft_puterr("rush-01: Usage: ./rush-01"
			" \"col_up_1 ... col_up_n col_down_1 ... col_down_n"
			" row_left_1 ... row_left_n row_right_1 ... row_right_n\"\n");
		return (EXIT_FAILURE + 1);
	}
	vector_construct(&vector);
	exit_status = EXIT_SUCCESS;
	if (!_parse_argument(&vector, argv[1])
		|| rush(&vector) != rush_success)
	{
		(void)ft_puterr("Error\n");
		exit_status = EXIT_FAILURE;
	}
	vector_destruct(&vector);
	return (exit_status);
}
