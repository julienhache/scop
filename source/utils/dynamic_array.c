/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:22:36 by jhache            #+#    #+#             */
/*   Updated: 2020/07/03 15:07:08 by jhache           ###   ########.fr       */
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

/* may call extend() if necessary (it will double the capacity) */
bool			append(t_darray *arr, void *data, size_t size)
{
	size_t		new_size;

	new_size = arr->size + size;
	if (new_size < arr->size)
		return (false);
	if (remaining_size(arr) < size)
	{
		if (!extend(arr, arr->capacity))
			return (false);
	}
	memcpy(arr->data + arr->size, data, size);
	arr->size = new_size;
	return (true);
}