/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:00:34 by jhache            #+#    #+#             */
/*   Updated: 2021/01/29 22:45:43 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_PARSING_PARSING_H
# define OBJ_PARSER_PARSING_PARSING_H

# include "../obj_parser.h"

/*
** The following function pointer store a parsing methods.
** It will be used in a function pointers array, whose indices
** are represented by t_obj_data_type values.
*/
typedef bool (*obj_parsing_func)(t_darray *, const char *);

extern const obj_parsing_func	g_parsing_array[OBJ_DATA_TYPE_FLAGS_NB];

bool		parse_line(
	t_darray *data_array, t_obj_data_type type, const char *line);

bool		parse_vertex(t_darray *data, const char *line);
bool		parse_vtexture(t_darray *data, const char *line);
bool		parse_vnormal(t_darray *data, const char *line);
bool		parse_face(t_darray *data, const char *line);
bool		dummy_parsing(t_darray *data, const char *line);
bool		error_parsing(t_darray *data, const char *line);

#endif