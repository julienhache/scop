/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:20:10 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 20:12:16 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool _Reallocf(void **data, size_t size) {
    void *new_data = realloc(*data, size);
    if (new_data == NULL) {
        free(*data);
        return false;
    }
    *data = new_data;
    return true;
}

GLData GLOpenFile(const char *filename) {
    GLData data;

    data._buf[0] = '\0';
    data._buf[GL_BUF_SIZE] = '\0';
    data._fd = fopen(filename, "r");
    data.line = calloc(1, 1);
    return (data);
}

void GLCloseFile(GLData *data) {
    if (data->_fd != NULL) {
        fclose(data->_fd);
    }
}

// TODO(jhache): add some comments (this function is too convoluted)
bool GLGetLine(GLData *data) {
    char * tmp = NULL;
    size_t wcount = 0;
    size_t rcount = 0;

    data->line[0] = '\0';
    while (true) {
        tmp = strchr(data->_buf, '\n');
        wcount = (tmp ? (size_t)(tmp - data->_buf) : strlen(data->_buf));
        rcount += wcount;

        if (!_Reallocf((void **)&data->line, rcount + 1)) {
            return false;
        }

        strncat(data->line, data->_buf, wcount);
        data->line[rcount] = '\0';
        if (tmp != NULL) {
            memmove(data->_buf,
                    data->_buf + wcount + 1,
                    GL_BUF_SIZE - wcount + 1);
            break;
        }
        wcount = fread(data->_buf, 1, GL_BUF_SIZE, data->_fd);
        if (wcount != GL_BUF_SIZE) {
            memcpy(data->_buf + wcount, "\n\0", 2);
        }
    }
    return (rcount > 0 || strlen(data->_buf) > 0 || !feof(data->_fd));
}