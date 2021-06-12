/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:57:55 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 20:14:22 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "data_types/data_types.h"
#include "internal_parsing.h"

// clang-format off
const ParseFunc ParseFuncArray[OBJ_DATA_TYPE_FLAGS_NB] = {
    ParseVertex,
    ParseVTexture,
    ParseVNormal,
    ParseFace,
    ParseDummy,
    ParseError
};
// clang-format on

bool ParseLine(DynamicArray *data_array, ObjDataType type, const char *line) {
    return (ParseFuncArray[type](data_array + type, line));
}

bool ParseVertex(DynamicArray *data, const char *line) {
    t_vertex     result = (t_vertex){0., 0., 0., 1.};
    OBJ_FLOAT *  current_value = (OBJ_FLOAT *)&result;
    const size_t len = strlen(line);
    size_t       i = strcspn(line, "1234567890-");

    while (i < len) {
        // check if we iterate past the 'result' memory
        if ((uintptr_t)current_value >= ((uintptr_t)&result + sizeof(result))) {
            return false;
        }
        *current_value = atof(line + i);
        ++current_value;
        i += strspn(line + i, ".1234567890-");
        i += strcspn(line + i, "1234567890-");
    }
    DArrayAppend(data, &result, sizeof(result));
    return true;
}

bool ParseVTexture(DynamicArray *data, const char *line) {
    t_vtexture   result = (t_vtexture){0., 0., 0.};
    OBJ_FLOAT *  current_value = (OBJ_FLOAT *)&result;
    const size_t len = strlen(line);
    size_t       i = strcspn(line, "1234567890-");

    while (i < len) {
        // check if we iterate past the 'result' memory
        if ((uintptr_t)current_value >= ((uintptr_t)&result + sizeof(result))) {
            return false;
        }
        *current_value = atof(line + i);
        ++current_value;
        i += strspn(line + i, ".1234567890-");
        i += strcspn(line + i, "1234567890-");
    }
    DArrayAppend(data, &result, sizeof(result));
    return true;
}

bool ParseVNormal(DynamicArray *data, const char *line) {
    t_vnormal    result = (t_vnormal){0., 0., 0.};
    OBJ_FLOAT *  current_value = (OBJ_FLOAT *)&result;
    const size_t len = strlen(line);
    size_t       i = strcspn(line, "1234567890-");

    while (i < len) {
        // check if we iterate past the 'result' memory
        if ((uintptr_t)current_value >= ((uintptr_t)&result + sizeof(result))) {
            return false;
        }
        *current_value = atof(line + i);
        ++current_value;
        i += strspn(line + i, ".1234567890-");
        i += strcspn(line + i, "1234567890-");
    }
    DArrayAppend(data, &result, sizeof(result));
    return true;
}

// Helps in the face parsing algorithm.
// It converts all 3 values from 'line' to a t_3di struct.
static bool _ParseTriplet(t_3di *result, const char *line) {
    result->x = atoi(line);
    line = strstr(line, "/ \t\n\v\f\r");
    if (line == NULL || *line != '/') return (true);
    result->y = atoi(++line);
    line = strstr(line, "/ \t\n\v\f\r");
    if (line == NULL || *line != '/') return (true);
    result->z = atoi(++line);
    line = strstr(line, "/ \t\n\v\f\r");
    return (line == NULL || *line != '/');
}

bool ParseFace(DynamicArray *data, const char *line) {
    t_face result;
    t_3di *current_value = (t_3di *)&result;

    memset(&result, 0, sizeof(result));
    const size_t len = strlen(line);
    size_t       i = strcspn(line, "1234567890-");
    while (i < len) {
        // check if we iterate past the 'result' memory
        if ((uintptr_t)current_value >= ((uintptr_t)&result + sizeof(result))) {
            return false;
        }
        if (!_ParseTriplet(current_value++, line + i)) {
            return false;
        }
        i += strspn(line + i, "/1234567890-");
        i += strcspn(line + i, "1234567890-");
    }
    DArrayAppend(data, &result, sizeof(result));
    return true;
}

bool ParseDummy(DynamicArray *data, const char *line) {
    (void)data;
    (void)line;
    return true;
}

bool ParseError(DynamicArray *data, const char *line) {
    (void)data;
    (void)line;
    return false;
}