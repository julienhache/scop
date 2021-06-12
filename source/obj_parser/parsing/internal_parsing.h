/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_parsing.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:48:49 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 20:14:22 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_PARSING_INTERNAL_PARSING_H
#define OBJ_PARSER_PARSING_INTERNAL_PARSING_H

#include "../obj_parser.h"

// Stores a parsing methods.
typedef bool (*ParseFunc)(DynamicArray *, const char *);

// Contains every parsing methods.
// They are accessible with an ObjDataType value as index.
extern const ParseFunc ParseFuncArray[OBJ_DATA_TYPE_FLAGS_NB];

bool ParseVertex(DynamicArray *data, const char *line);
bool ParseVTexture(DynamicArray *data, const char *line);
bool ParseVNormal(DynamicArray *data, const char *line);
bool ParseFace(DynamicArray *data, const char *line);
bool ParseDummy(DynamicArray *data, const char *line);
bool ParseError(DynamicArray *data, const char *line);

#endif