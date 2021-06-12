/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:48:34 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 19:45:29 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "internal_lexing.h"

// clang-format off
const LexFunc LexFuncArray[OBJ_DATA_TYPE_NB] = {
    LexVertex,
	LexVtexture,
	LexVnormal,
	LexFace
};
//clang-format on

ObjDataType LexLine(const char *line) {
    ObjDataType result = OBJ_NONE;

    if (strlen(line) == 0) {
        return result;
    }

    size_t i = 0;
    while (result == OBJ_NONE && i < OBJ_DATA_TYPE_NB) {
        result = LexFuncArray[i++](line);
    }
    return result;
}

ObjDataType LexVertex(const char *line) {
    const size_t word_len = strcspn(line, " \t\n\v\f\r");

    if (word_len == 0) {
        return OBJ_NONE;
    }
    return (strncmp(line, "v", word_len) == 0 ? OBJ_V : OBJ_NONE);
}

ObjDataType LexVtexture(const char *line) {
    const size_t word_len = strcspn(line, " \t\n\v\f\r");

    if (word_len == 0) {
        return OBJ_NONE;
    }
    return (strncmp(line, "vt", word_len) == 0 ? OBJ_VT : OBJ_NONE);
}

ObjDataType LexVnormal(const char *line) {
    const size_t word_len = strcspn(line, " \t\n\v\f\r");

    if (word_len == 0) {
        return OBJ_NONE;
    }
    return (strncmp(line, "vn", word_len) == 0 ? OBJ_VN : OBJ_NONE);
}

ObjDataType LexFace(const char *line) {
    const size_t word_len = strcspn(line, " \t\n\v\f\r");

    if (word_len == 0) {
        return OBJ_NONE;
    }
    return (strncmp(line, "f", word_len) == 0 ? OBJ_F : OBJ_NONE);
}