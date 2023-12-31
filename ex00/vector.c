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

#include "vector.h"
#include <stddef.h>

void	vector_construct(t_vector *vector)
{
	vector->data = NULL;
	vector->size = (size_t)0;
	vector->capacity = (size_t)0;
}

void	vector_destruct(t_vector *vector)
{
	free(vector->data);
}

unsigned int	*vector_reserve(t_vector *vector, size_t new_capacity)
{
	unsigned int *const	old_data = vector->data;
	unsigned int		*new_data;
	size_t				i;

	if (vector->capacity >= new_capacity)
		return (old_data);
	new_data = malloc(new_capacity * sizeof(*vector->data));
	if (new_data == NULL)
		return (NULL);
	i = 0;
	while (i < vector->size)
	{
		new_data[i] = old_data[i];
		i++;
	}
	free(old_data);
	vector->data = new_data;
	vector->capacity = new_capacity;
	return (new_data);
}

bool	vector_push(t_vector *vector, unsigned int value)
{
	const size_t	future_size = vector->size + 1;
	size_t			new_capacity;

	new_capacity = vector->capacity;
	if (new_capacity < future_size)
	{
		new_capacity <<= 1;
		if (new_capacity < future_size)
			new_capacity = future_size;
		if (vector_reserve(vector, new_capacity) == NULL)
			return (false);
	}
	vector->data[vector->size] = value;
	vector->size++;
	return (true);
}
