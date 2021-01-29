/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:08:19 by jhache            #+#    #+#             */
/*   Updated: 2021/01/29 22:15:44 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_OBJ_PARSER_H
# define OBJ_PARSER_OBJ_PARSER_H

# include "utils/dynamic_array/dynamic_array.h"
# include "utils/get_line/get_line.h"

/*
** Vertex data
**
** The integral value of each identifier are used
** as array index for the t_obj_file's darrays.
*/
typedef enum	e_obj_data_type
{
	/* geometric vertices */
	OBJ_V = 0,
	/* texture vertices */
	OBJ_VT,
	/* vertex normals */
	OBJ_VN,
	/* parameter space vertices (free-form curve/surface attributes) (unused) */
/*	OBJ_VP, */
	/* faces (as groups of vertices) */
	OBJ_F,
	/* Error handling */
	OBJ_NONE,
	OBJ_ERROR
}				t_obj_data_type;

# define OBJ_DATA_TYPE_NB		4
# define OBJ_DATA_TYPE_FLAGS_NB	6

/*
** t_obj_file is a struct that will contain all the data of a .obj file.
** An instance of t_obj_file shall be allocated and return only by the
** parse_file() function.
** To deallocate a t_obj_file instance provided by the parse_file() func,
** you must call destroy_obj_file(), then free() the instance's memory.
*/
typedef struct		s_obj_file
{
	const char	*filename;
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
** 		t_darray * const	darray = &data->v;// the first element
**      size_t				darr_i = 0;
** 		[...]
** 		while (darr_i++ < NUMBER_OF_DARRAY) {[use darray[darr_i] element...]}
** 	}
*/
# define NUMBER_OF_DARRAY	OBJ_DATA_TYPE_NB

t_obj_file		*parse_file(const char *filename);
void			destroy_obj_file(t_obj_file *data);

#endif