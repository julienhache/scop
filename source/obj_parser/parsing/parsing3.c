/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 22:55:41 by jhache            #+#    #+#             */
/*   Updated: 2021/01/29 23:15:16 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "parsing.h"
#include "data_types/data_types.h"

static bool	parse_triplet(t_3di *result, const char *line)
{
	result->x = atoi(line);
	line = strstr(line, "/ \t\n\v\f\r");
	if (line == NULL || *line != '/')
		return (true);
	result->y = atoi(++line);
	line = strstr(line, "/ \t\n\v\f\r");
	if (line == NULL || *line != '/')
		return (true);
	result->z = atoi(++line);
	line = strstr(line, "/ \t\n\v\f\r");
	return (line == NULL || *line != '/');
}

bool		parse_face(t_darray *data, const char *line)
{
	t_face			result;
	size_t			i;
	const size_t	len = strlen(line);
	t_3di			*current_value;

	memset(&result, 0, sizeof(result));
	i = strcspn(line, "1234567890-");
	current_value = (t_3di *)&result;
	while (i < len)
	{
		if ((uintptr_t)current_value >= ((uintptr_t)&result + sizeof(result)))
			return (false);
		if (!parse_triplet(current_value++, line + i))
			return (false);
		i += strspn(line + i, "/1234567890-");
		i += strcspn(line + i, "1234567890-");
	}
	append(data, &result, sizeof(result));
	return (true);
}