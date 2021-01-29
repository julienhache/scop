/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:11:47 by jhache            #+#    #+#             */
/*   Updated: 2021/01/29 22:14:54 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_DATA_TYPES_DATA_TYPES_H
# define OBJ_PARSER_DATA_TYPES_DATA_TYPES_H

#include <limits.h>

/* basic definitions */

# define OBJ_FLOAT		float
# define OBJ_INTEGER	int

typedef struct	s_4d_float
{
	OBJ_FLOAT	x;
	OBJ_FLOAT	y;
	OBJ_FLOAT	z;
	OBJ_FLOAT	w;
}				t_4df;

typedef struct	s_3d_float
{
	OBJ_FLOAT	x;
	OBJ_FLOAT	y;
	OBJ_FLOAT	z;
}				t_3df;

typedef struct	s_2d_float
{
	OBJ_FLOAT	x;
	OBJ_FLOAT	y;
}				t_2df;

typedef struct s_3d_integer
{
	OBJ_INTEGER	x;
	OBJ_INTEGER	y;
	OBJ_INTEGER	z;
}				t_3di;

/* .obj file data types */

typedef t_4df	t_vertex;
typedef t_3df	t_vtexture;
typedef t_3df	t_vnormal;

# define MAX_VERTICES_PER_FACE	4

typedef struct	s_face
{
	t_3di		vertices[MAX_VERTICES_PER_FACE];			
}				t_face;

#endif