/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:57:55 by jhache            #+#    #+#             */
/*   Updated: 2021/01/27 12:17:40 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

const obj_parsing_func	g_parsing_array[OBJ_DATA_TYPE_FLAGS_NB] = {
	dummy_parsing,
	dummy_parsing,
	dummy_parsing,
	dummy_parsing,
	dummy_parsing,
	error_parsing
};

bool		parse_line(
	t_darray *data_array, t_obj_data_type type, const char *line)
{
	return (g_parsing_array[type](data_array, line));
}

bool		dummy_parsing(t_darray *data_array, const char *line)
{
	(void)data_array;
	(void)line;
	return (true);
}

bool		error_parsing(t_darray *data_array, const char *line)
{
	(void)data_array;
	(void)line;
	return (false);
}