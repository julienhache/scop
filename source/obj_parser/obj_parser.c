/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:09:29 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 20:14:22 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_parser.h"

#include <stdio.h>
#include <stdlib.h>

#include "lexing/lexing.h"
#include "parsing/parsing.h"

void DestroyObjFile(ObjFile *data) {
    if (data == NULL) {
        return;
    }

    GLCloseFile(&data->filedata);

    DynamicArray *arrays = GET_DARRAYS(data);
    for (size_t i = 0; i < NUMBER_OF_DARRAY; ++i) {
        DArrayDelete(arrays + i++);
    }
}

static bool initData(ObjFile *data, const char *filename) {
    data->filename = filename;
    data->filedata = GLOpenFile(filename);
    if (data->filedata._fd == NULL) {
        DestroyObjFile(data);
        return false;
    }

    DynamicArray *const arrays = GET_DARRAYS(data);
    for (size_t i = 0; i < NUMBER_OF_DARRAY; ++i) {
        arrays[i] = DArrayCreate();
        if (arrays[i++].data == NULL) {
            DestroyObjFile(data);
            return false;
        }
    }
    return true;
}

// Parses a 'filename'.obj file.
// First, it allocates memory for an ObjFile and initializes it.
// The file is then lexed and parsed line by line.
ObjFile *ParseFile(const char *filename) {
    ObjFile *data = (ObjFile *)calloc(1, sizeof(ObjFile));
    if (data == NULL || !initData(data, filename)) {
        free(data);
        return NULL;
    }

    while (GLGetLine(&data->filedata)) {
        printf("parsing\t\"%s\"\n", data->filedata.line);
        ObjDataType data_type = LexLine(data->filedata.line);
        if (!ParseLine(&data->v, data_type, data->filedata.line)) {
            printf("Error while parsing. exiting the parser...\n");
            DestroyObjFile(data);
            free(data);
            return NULL;
        }
    }
    return data;
}