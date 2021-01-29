/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:48:34 by jhache            #+#    #+#             */
/*   Updated: 2021/01/29 22:23:12 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "lexing.h"

const obj_lexing_func	g_lexing_array[OBJ_DATA_TYPE_NB] = {
	lex_vertex,
	lex_vtexture,
	lex_vnormal,
	lex_face
};

t_obj_data_type			lex_line(const char *line)
{
	t_obj_data_type		result;
	size_t				i;
	const size_t		array_len =
		sizeof(g_lexing_array) / sizeof(obj_lexing_func);

	result = OBJ_NONE;
	i = 0;
	if (strlen(line) == 0)
		return (result);
	while (result == OBJ_NONE && i < array_len)
	{
		result = g_lexing_array[i++](line);
	}
	return (result);
}

t_obj_data_type			lex_vertex(const char *line)
{
	const size_t		word_len = strcspn(line, " \t\n\v\f\r");

	if (word_len == 0)
		return (OBJ_NONE);
	return (strncmp(line, "v", word_len) == 0 ? OBJ_V : OBJ_NONE);
}

t_obj_data_type			lex_vtexture(const char *line)
{
	const size_t		word_len = strcspn(line, " \t\n\v\f\r");

	if (word_len == 0)
		return (OBJ_NONE);
	return (strncmp(line, "vt", word_len) == 0 ? OBJ_VT : OBJ_NONE);
}

t_obj_data_type			lex_vnormal(const char *line)
{
	const size_t		word_len = strcspn(line, " \t\n\v\f\r");

	if (word_len == 0)
		return (OBJ_NONE);
	return (strncmp(line, "vn", word_len) == 0 ? OBJ_VN : OBJ_NONE);
}

t_obj_data_type			lex_face(const char *line)
{
	const size_t		word_len = strcspn(line, " \t\n\v\f\r");

	if (word_len == 0)
		return (OBJ_NONE);
	return (strncmp(line, "f", word_len) == 0 ? OBJ_F : OBJ_NONE);
}