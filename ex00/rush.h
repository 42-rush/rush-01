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

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include "vector.h"

typedef struct s_rush
{
	const unsigned int	*s;
	unsigned int		n;
	unsigned int		*a;
}	t_rush;

enum e_rush_errno
{
	rush_success,
	rush_error_indivisible,
	rush_error_out_of_range,
	rush_error_memory_allocate,
};

enum e_rush_errno	rush(const t_vector *vector);

#endif
