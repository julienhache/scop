/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:20:05 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 20:04:47 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_GET_LINE_GET_LINE_H
#define UTILS_GET_LINE_GET_LINE_H

#include <stdbool.h>
#include <stdio.h>

#define GL_BUF_SIZE 64

// Stores the content read from a file.
// Only 'line' should be used to access the data. Other attributes are for
// internal use. Use the functions declared in the file to manage the data.
typedef struct GLData {
    char  _buf[GL_BUF_SIZE + 1];
    FILE *_fd;
    char *line;
} GLData;

/*
** How to use GLData:
** - Open a file with GLOpenFile(),
** - Call GLGetLine() to get the next line of the file.
**   Repeat the operation until the return is 'false',
**   meaning either an error occured, or EOF is reached.
** - Close the file with GLCloseFile().
*/
GLData GLOpenFile(const char *filename);
bool   GLGetLine(GLData *data);
void   GLCloseFile(GLData *data);

#endif