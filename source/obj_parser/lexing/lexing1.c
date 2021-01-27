/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:48:34 by jhache            #+#    #+#             */
/*   Updated: 2021/01/27 12:34:27 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

const obj_lexing_func	g_lexing_array[OBJ_DATA_TYPE_NB] = {
	dummy_lexing,
	dummy_lexing,
	dummy_lexing,
	dummy_lexing
};

t_obj_data_type			lex_line(const char *line)
{
	t_obj_data_type		result;
	size_t				i;
	const size_t		array_len =
		sizeof(g_lexing_array) / sizeof(obj_lexing_func);

	result = OBJ_NONE;
	i = 0;
	while (result == OBJ_NONE && i < array_len)
	{
		result = g_lexing_array[i++](line);
	}
	return (result);
}

t_obj_data_type			dummy_lexing(const char *line)
{
	(void)line;
	return (OBJ_NONE);
}