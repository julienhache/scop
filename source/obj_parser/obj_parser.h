/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:08:19 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 20:14:22 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Defines how to parse and store .obj file data.

#ifndef OBJ_PARSER_OBJ_PARSER_H
#define OBJ_PARSER_OBJ_PARSER_H

#include "utils/dynamic_array/dynamic_array.h"
#include "utils/get_line/get_line.h"

// Identifies the type of data in a .obj file.
// Each identifier's value is used as an array index for the ObjFile's darrays.
typedef enum ObjDataType {
    // geometric vertices
    OBJ_V = 0,
    // texture vertices
    OBJ_VT,
    // vertex normals
    OBJ_VN,
    // parameter space vertices (free-form curve/surface attributes)
    // OBJ_VP, (unused)
    // faces (as groups of vertices)
    OBJ_F,
    // Error handling
    OBJ_NONE,
    OBJ_ERROR
} ObjDataType;

// TODO(jhache): use ObjDataType flags to automatically update these macros
#define OBJ_DATA_TYPE_NB       4
#define OBJ_DATA_TYPE_FLAGS_NB 6

// Stores a .obj file data.
// You should use the ParseFile() and DestroyObjFile() functions
// to retrieve / destroy your instance. Dont forget to call free()
// on ParseFile()'s returned value.
typedef struct ObjFile {
    const char * filename;
    GLData       filedata;
    DynamicArray v;
    DynamicArray vt;
    DynamicArray vn;
    DynamicArray f;
} ObjFile;

// Provides a pointer interface for all darrays of a ObjFile instance.
// Example:
//  while (i++ < NUMBER_OF_DARRAY) {
//      [use 'GET_DARRAYS(obj_file)[i]' element...]
#define GET_DARRAYS(obj_file) (&obj_file->v)
#define NUMBER_OF_DARRAY      OBJ_DATA_TYPE_NB

// Parses a 'filename'.obj file. Return an allocated ObjFile instance,
// or NULL if an error occurs.
ObjFile *ParseFile(const char *filename);
void     DestroyObjFile(ObjFile *data);

#endif