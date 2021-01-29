/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:57:55 by jhache            #+#    #+#             */
/*   Updated: 2021/01/29 22:55:58 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "parsing.h"
#include "data_types/data_types.h"

const obj_parsing_func	g_parsing_array[OBJ_DATA_TYPE_FLAGS_NB] = {
	parse_vertex,
	parse_vtexture,
	parse_vnormal,
	parse_face,
	dummy_parsing,
	error_parsing
};

bool		parse_line(
	t_darray *data_array, t_obj_data_type type, const char *line)
{
	return (g_parsing_array[type](data_array + type, line));
}

bool		parse_vertex(t_darray *data, const char *line)
{
	t_vertex		result;
	size_t			i;
	const size_t	len = strlen(line);
	OBJ_FLOAT		*current_value;

	result = (t_vertex){0., 0., 0., 1.};
	i = strcspn(line, "1234567890-");
	current_value = (OBJ_FLOAT *)&result;
	while (i < len)
	{
		if ((uintptr_t)current_value >= ((uintptr_t)&result + sizeof(result)))
			return (false);
		*current_value = atof(line + i);
		++current_value;
		i += strspn(line + i, ".1234567890-");
		i += strcspn(line + i, "1234567890-");
	}
	append(data, &result, sizeof(result));
	return (true);
}

bool		parse_vtexture(t_darray *data, const char *line)
{
	t_vtexture		result;
	size_t			i;
	const size_t	len = strlen(line);
	OBJ_FLOAT		*current_value;

	result = (t_vtexture){0., 0., 0.};
	i = strcspn(line, "1234567890-");
	current_value = (OBJ_FLOAT *)&result;
	while (i < len)
	{
		if ((uintptr_t)current_value >= ((uintptr_t)&result + sizeof(result)))
			return (false);
		*current_value = atof(line + i);
		++current_value;
		i += strspn(line + i, ".1234567890-");
		i += strcspn(line + i, "1234567890-");
	}
	append(data, &result, sizeof(result));
	return (true);
}

bool		parse_vnormal(t_darray *data, const char *line)
{
	t_vnormal		result;
	size_t			i;
	const size_t	len = strlen(line);
	OBJ_FLOAT		*current_value;

	result = (t_vnormal){0., 0., 0.};
	i = strcspn(line, "1234567890-");
	current_value = (OBJ_FLOAT *)&result;
	while (i < len)
	{
		if ((uintptr_t)current_value >= ((uintptr_t)&result + sizeof(result)))
			return (false);
		*current_value = atof(line + i);
		++current_value;
		i += strspn(line + i, ".1234567890-");
		i += strcspn(line + i, "1234567890-");
	}
	append(data, &result, sizeof(result));
	return (true);
}