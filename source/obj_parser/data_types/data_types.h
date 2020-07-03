/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:11:47 by jhache            #+#    #+#             */
/*   Updated: 2020/07/03 15:37:44 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_DATA_TYPES_DATA_TYPES_H
# define OBJ_PARSER_DATA_TYPES_DATA_TYPES_H

/* basic definitions */

# define OBJ_FLOAT	float;

typedef struct	s_4d_coordinates
{
	OBJ_FLOAT	x;
	OBJ_FLOAT	y;
	OBJ_FLOAT	z;
	OBJ_FLOAT	w;
}				t_4d;

typedef struct	s_3d_coordinates
{
	OBJ_FLOAT	x;
	OBJ_FLOAT	y;
	OBJ_FLOAT	z;
}				t_3d;

typedef struct	s_2d_coordinates
{
	OBJ_FLOAT	x;
	OBJ_FLOAT	y;
}				t_2d;


/* .obj file data types */

/* geometric vertices */
typedef t_4d	t_v;

/* texture vertices */
typedef t_3d	t_vt;

/* vertex normals */
typedef t_3d	t_vn;

/* parameter space vertices (for free-form curve/surface attributes) (unused) */
typedef t_3d	t_vp;

#endif