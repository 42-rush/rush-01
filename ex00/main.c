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

int	program(t_vector *vector, const char *arg, const char **ref_error_message)
{
	enum e_rush_errno	result;

	if (!_parse_argument(vector, arg))
	{
		*ref_error_message = "Error: invalid argument\n";
		return (EXIT_FAILURE + 2);
	}
	result = rush(vector);
	if (result != rush_success)
	{
		if (result == rush_error_indivisible)
			*ref_error_message = "Error: indivisible\n";
		else if (result == rush_error_out_of_range)
			*ref_error_message = "Error: out of range\n";
		else if (result == rush_error_bad_allocate)
			*ref_error_message = "Error: bad allocate\n";
		else if (result == rush_error_none_solution)
			*ref_error_message = "Error: none solution\n";
		return (EXIT_FAILURE + 16 + result);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_vector	vector;
	int			exit_status;
	const char	*error_message;

	if (argc != 2)
	{
		(void)ft_puterr("rush-01: Usage: ./rush-01"
			" \"col_up_1 ... col_up_n col_down_1 ... col_down_n"
			" row_left_1 ... row_left_n row_right_1 ... row_right_n\"\n");
		return (EXIT_FAILURE + 1);
	}
	vector_construct(&vector);
	error_message = NULL;
	exit_status = program(&vector, argv[1], &error_message);
	if (error_message != NULL)
		(void)ft_puterr(error_message);
	vector_destruct(&vector);
	return (exit_status);
}
