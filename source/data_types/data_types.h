/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:11:47 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 20:31:00 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_DATA_TYPES_DATA_TYPES_H
#define OBJ_PARSER_DATA_TYPES_DATA_TYPES_H

#include <limits.h>

// basic definitions

#define OBJ_FLOAT   float
#define OBJ_INTEGER int

typedef struct Float4D {
    OBJ_FLOAT x;
    OBJ_FLOAT y;
    OBJ_FLOAT z;
    OBJ_FLOAT w;
} Float4D;

typedef struct Float3D {
    OBJ_FLOAT x;
    OBJ_FLOAT y;
    OBJ_FLOAT z;
} Float3D;

typedef struct Float2D {
    OBJ_FLOAT x;
    OBJ_FLOAT y;
} Float2D;

typedef struct Int3D {
    OBJ_INTEGER x;
    OBJ_INTEGER y;
    OBJ_INTEGER z;
} Int3D;

// .obj file data types

typedef Float4D t_vertex;
typedef Float3D t_vtexture;
typedef Float3D t_vnormal;

#define MAX_VERTICES_PER_FACE 4

typedef struct s_face {
    Int3D vertices[MAX_VERTICES_PER_FACE];
} t_face;

#endif