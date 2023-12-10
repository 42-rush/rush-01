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
#include "libft.h"
#include "vector.h"

#include <stdio.h>
#define PRINT_VECTOR(_v) for (size_t i = 0; i < (_v)->size; i++) printf(#_v "[ %zu ] = %d\n", i, (_v)->data[i])

static t_vector	*parse_argument(const char *s)
{
	t_vector	*vec;
	size_t		i;

	vec = vector_new();
	i = 0;
	while (*s)
	{
		//TODO: 
		if (!vector_push(vec, i))
		{
			vector_delete(vec);
			return (NULL);
		}
	}
	return (vec);
}

int	main(int argc, char *argv[])
{
	t_vector	*vec;

	if (argc != 2)
	{
		ft_puterr("Error\n");
		return (EXIT_FAILURE);
	}
	vec = parse_argument(argv[1]);
	if (vec == NULL)
	{
		ft_puterr("Error\n");
		return (EXIT_FAILURE);
	}
	vector_delete(vec);
	return (EXIT_SUCCESS);
}
