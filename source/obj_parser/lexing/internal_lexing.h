/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_lexing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:40:48 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 19:45:29 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_LEXING_INTERNAL_LEXING_H
#define OBJ_PARSER_LEXING_INTERNAL_LEXING_H

#include "../obj_parser.h"

// Stores a lexing methods.
typedef ObjDataType (*LexFunc)(const char *);

// Contains every lexing methods.
// They are accessible with an ObjDataType value as index.
extern const LexFunc LexFuncArray[OBJ_DATA_TYPE_NB];

ObjDataType LexVertex(const char *line);
ObjDataType LexVtexture(const char *line);
ObjDataType LexVnormal(const char *line);
ObjDataType LexFace(const char *line);

#endif