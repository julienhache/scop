/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:20:05 by jhache            #+#    #+#             */
/*   Updated: 2020/07/10 03:05:09 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_GET_LINE_GET_LINE_H
# define UTILS_GET_LINE_GET_LINE_H

# include <stdio.h>

# define GETLINE_BUFFER_SIZE	64

typedef struct	s_gl_data
{
	char		_buf[GETLINE_BUFFER_SIZE];
	FILE		*fd;
	char		*line;
}				t_gl_data;

t_gl_data		open_file(char *filename);
void			close_file(t_gl_data *data);
size_t			get_line(t_gl_data *data);

#endif