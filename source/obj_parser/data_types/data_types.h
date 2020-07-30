/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:11:47 by jhache            #+#    #+#             */
/*   Updated: 2020/07/30 11:12:05 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_DATA_TYPES_DATA_TYPES_H
# define OBJ_PARSER_DATA_TYPES_DATA_TYPES_H

#include <limits.h>

/* basic definitions */

# define OBJ_FLOAT	float

typedef struct	s_4d_coordinates
{
	OBJ_FLOAT	x;
	OBJ_FLOAT	y;
	OBJ_FLOAT	z;
	OBJ_FLOAT	w;
}				t_4df;

typedef struct	s_3d_coordinates
{
	OBJ_FLOAT	x;
	OBJ_FLOAT	y;
	OBJ_FLOAT	z;
}				t_3df;

typedef struct	s_2d_coordinates
{
	OBJ_FLOAT	x;
	OBJ_FLOAT	y;
}				t_2df;


/* .obj file data types */

/* Vertex data
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

typedef enum e_obj_data_type t_obj_data_type;

#endif