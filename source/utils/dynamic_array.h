/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 11:55:28 by jhache            #+#    #+#             */
/*   Updated: 2020/07/03 16:29:07 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_DYNAMIC_ARRAY_H
# define UTILS_DYNAMIC_ARRAY_H

# include <stddef.h>
# include <stdbool.h>

typedef struct		s_dynamic_array
{
	void			*data;
	size_t			size;
	size_t			capacity;
}					t_darray;

# define DARRAY_MIN_SIZE 128

bool		init_darray(t_darray *arr, size_t size);
t_darray	create_darray(void);
void		del_darray(t_darray *arr);

bool		append(t_darray *arr, void *data, size_t size);


#endif