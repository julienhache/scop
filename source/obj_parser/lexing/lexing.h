/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:47:34 by jhache            #+#    #+#             */
/*   Updated: 2021/01/29 12:42:05 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_LEXING_LEXING_H
# define OBJ_PARSER_LEXING_LEXING_H

# include "../obj_parser.h"

/*
** The following function pointer store a lexing methods.
** It will be used in a function pointers array, whose indices
** are represented by t_obj_data_type values.
*/
typedef t_obj_data_type (*obj_lexing_func)(const char *);

extern const obj_lexing_func	g_lexing_array[OBJ_DATA_TYPE_NB];

t_obj_data_type		lex_line(const char *line);

t_obj_data_type		lex_vertex(const char *line);
t_obj_data_type		lex_vtexture(const char *line);
t_obj_data_type		lex_vnormal(const char *line);
t_obj_data_type		lex_face(const char *line);

#endif