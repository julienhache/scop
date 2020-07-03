/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:22:36 by jhache            #+#    #+#             */
/*   Updated: 2020/07/03 16:23:09 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_array.h"

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static size_t	remaining_size(t_darray *arr)
{
	return (arr->capacity - arr->size);
}

static bool		extend(t_darray *arr, size_t size)
{
	void		*tmp;
	bool		res;

	tmp = realloc(arr->data, arr->capacity + size);
	res = (tmp != NULL);
	if (res)
	{
		arr->data = tmp;
		arr->capacity += size;
	}
	return (res);
}

bool			init_darray(t_darray *arr, size_t size)
{
	if (size < DARRAY_MIN_SIZE)
		size = DARRAY_MIN_SIZE;
	arr->data = malloc(size);
	if (arr->data == NULL)
		return (false);
	arr->capacity = size;
	arr->size = 0;
	return (true);
}

t_darray		create_darray(void)
{
	t_darray	res;

	init_darray(&res, DARRAY_MIN_SIZE);
	return (res);
}

void			del_darray(t_darray *arr)
{
	free(arr->data);
}

/* may call extend() if necessary (it will double the capacity) */
bool			append(t_darray *arr, void *data, size_t size)
{
	size_t		new_size;

	new_size = arr->size + size;
	if (new_size < arr->size)
		return (false);
	while (remaining_size(arr) < size)
	{
		if (!extend(arr, arr->capacity))
			return (false);
	}
	memcpy(arr->data + arr->size, data, size);
	arr->size = new_size;
	return (true);
}