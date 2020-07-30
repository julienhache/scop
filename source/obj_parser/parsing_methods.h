/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_methods.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:00:34 by jhache            #+#    #+#             */
/*   Updated: 2020/07/30 11:38:11 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_PARSING_METHODS_H
# define OBJ_PARSER_PARSING_METHODS_H

# include "obj_parser.h"

/*
** The following function pointer store a parsing methods.
** It will be used in a function pointers array, which indices
** are represented by t_obj_data_type values.
*/
typedef bool (*obj_parsing_func)(t_darray *, const char *);

extern const obj_parsing_func	g_parsing_array[OBJ_DATA_TYPE_FLAGS_NB];


bool		dummy_parsing(t_darray *data_array, const char *line);
bool		error_parsing(t_darray *data_array, const char *line);

#endif