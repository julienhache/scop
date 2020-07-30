/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:08:19 by jhache            #+#    #+#             */
/*   Updated: 2020/07/30 12:20:26 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_OBJ_PARSER_H
# define OBJ_PARSER_OBJ_PARSER_H

# include "data_types/data_types.h"
# include "utils/dynamic_array/dynamic_array.h"
# include "utils/get_line/get_line.h"

/*
** t_obj_file is a struct that will contain all the data of a .obj file.
** An instance of t_obj_file shall be allocated and return only by the
** parse_file() function.
** To deallocate a t_obj_file instance provided by the parse_file() func,
** you must call destroy_obj_file(), then free() the instance's memory.
*/
typedef struct		s_obj_file
{
	char		*filename;
	t_gl_data	filedata;
	t_darray	v;
	t_darray	vt;
	t_darray	vn;
	t_darray	f;
}					t_obj_file;

/*
** NUMBER_OF_DARRAY is used to loop on all darrays of a t_obj_file instance.
** This way, you can easily reach any (or each) data.
** A common way to achieve this is:
** 	{
** 		t_darray * const	first_darray = &data->v;// the first element
** 		[...]
** 		while (darray_index++ < NUMBER_OF_DARRAY) {[...]}
** 	}
*/
# define NUMBER_OF_DARRAY	OBJ_DATA_TYPE_NB

t_obj_file		*parse_file(char *filename);
void			destroy_obj_file(t_obj_file *data);

#endif