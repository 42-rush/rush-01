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

#include "rush.h"
#include <unistd.h>
#include "libft.h"
#include "vector.h"

static bool	_rush_check(const t_rush *rush, size_t x, size_t y)
{
	(void)&rush;
	(void)&x;
	(void)&y;
	return (true);
}

static void	_rush_candidate(const t_rush *rush)
{
	size_t			x;
	size_t			y;
	unsigned int	n[4];

	x = 0;
	while (x < rush->n)
	{
		y = 0;
		while (y < rush->n)
		{
			n[0] = rush->view[rush->n * 0 + x];
			n[1] = rush->view[rush->n * 1 + x];
			n[2] = rush->view[rush->n * 2 + y];
			n[3] = rush->view[rush->n * 3 + y];
		}
		x++;
	}
}

static bool	_rush_solve(const t_rush *rush, size_t index)
{
	const size_t	x = index % rush->n;
	const size_t	y = index / rush->n;
	unsigned int	value;
	unsigned int	backup;

	if (index == rush->n * rush->n)
		return (true);
	backup = rush->height[x + rush->n * y];
	value = 0;
	while (value < rush->n)
	{
		rush->height[x + rush->n * y] = value;
		if (_rush_solve(rush, index + 1))
			return (true);
		value++;
	}
	rush->height[x + rush->n * y] = backup;
	return (false);
}

enum e_rush_errno	rush(const t_vector *vector)
{
	t_rush		rush;
	size_t		i;
	bool		encountered;

	if (vector->size % 4 != 0)
		return (rush_error_indivisible);
	i = 0;
	while (i < vector->size)
	{
		if (vector->data[i] < 1 || vector->data[i] >= rush.n)
			return (rush_error_out_of_range);
		i++;
	}
	rush.view = vector->data;
	rush.n = vector->size / 4;
	rush.height = malloc(rush.n * rush.n * sizeof(*vector->data));
	if (rush.height == NULL)
		return (rush_error_memory_allocate);
	ft_memset(rush.height, 0, rush.n * rush.n * sizeof(*vector->data));
	_rush_candidate(&rush);
	encountered = _rush_solve(&rush, 0);
	free(rush.height);
	if (!encountered)
		return (rush_error_none_solution);
	return (rush_success);
}
