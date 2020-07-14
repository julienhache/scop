/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:20:05 by jhache            #+#    #+#             */
/*   Updated: 2020/07/14 16:41:56 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_GET_LINE_GET_LINE_H
# define UTILS_GET_LINE_GET_LINE_H

# include <stdio.h>
# include <stdbool.h>

# define GL_BUF_SIZE	64

/*
** t_gl_data is a "black box" struct, that will handle
** a read operation on an associated file, line by line.
** open_file() will create a new data instance,
** get_line() will feed the next associated file line in the "line" parameter,
** and close_file() will delete any instance.
**
** You should only access to the "line" parameter directly ;
** the other ones are for internal use.
*/
typedef struct	s_gl_data
{
	char		_buf[GL_BUF_SIZE+1];
	FILE		*_fd;
	char		*line;
}				t_gl_data;

/*
** How to use t_gl_data:
** - Open a file with open_file(),
** - Call get_line() to get the next line of the file.
**   Repeat the operation until the return is 'false',
**   meaning either an error occured, or EOF is reached.
** - Close the file with close_file().
*/
t_gl_data		open_file(char *filename);
bool			get_line(t_gl_data *data);
void			close_file(t_gl_data *data);

#endif