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

static bool	_rush_solve(const t_rush *rush)
{
	(void)&rush;
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
	rush.s = vector->data;
	rush.n = vector->size / 4;
	rush.a = malloc(rush.n * rush.n * sizeof(*vector->data));
	if (rush.a == NULL)
		return (rush_error_memory_allocate);
	ft_memset(rush.a, 0, rush.n * rush.n * sizeof(*vector->data));
	encountered = _rush_solve(&rush);
	free(rush.a);
	if (!encountered)
		return (rush_error_none_solution);
	return (rush_success);
}
