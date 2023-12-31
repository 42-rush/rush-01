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

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_vector
{
	unsigned int	*data;
	size_t			size;
	size_t			capacity;
}	t_vector;

void			vector_construct(t_vector *vector);
void			vector_destruct(t_vector *vector);
unsigned int	*vector_reserve(t_vector *vector, size_t new_capacity);
bool			vector_push(t_vector *vector, unsigned int value);

#endif
