/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:20:10 by jhache            #+#    #+#             */
/*   Updated: 2020/07/26 22:42:31 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool		my_reallocf(void **data, size_t size)
{
	void		*new_data;

	new_data = realloc(*data, size);
	if (new_data == NULL)
	{
		free(*data);
		return (false);
	}
	*data = new_data;
	return (true);
}

t_gl_data		gl_open_file(char *filename)
{
	t_gl_data	data;

	data._buf[0] = '\0';
	data._buf[GL_BUF_SIZE] = '\0';
	data._fd = fopen(filename, "r");
	data.line = calloc(1, 1);
	return (data);
}

void			gl_close_file(t_gl_data *data)
{
	if (data->_fd != NULL)
		fclose(data->_fd);
}

bool			get_line(t_gl_data *d)
{
	char		*tmp;
	size_t		wcount;
	size_t		rcount;

	rcount = 0;
	d->line[0] = '\0';
	while (true)
	{
		tmp = strchr(d->_buf, '\n');
		wcount = (tmp ? (size_t)(tmp - d->_buf) : strlen(d->_buf));
		rcount += wcount;
		if (!my_reallocf((void **)&d->line, rcount + 1))
			return (false);
		strncat(d->line, d->_buf, wcount);
		d->line[rcount] = '\0';
		if (tmp != NULL)
		{
			memmove(d->_buf, d->_buf + wcount + 1, GL_BUF_SIZE - wcount + 1);
			break ;
		}
		wcount = fread(d->_buf, 1, GL_BUF_SIZE, d->_fd);
		if (wcount != GL_BUF_SIZE)
			memcpy(d->_buf + wcount, "\n\0", 2);
	}
	return (rcount > 0 || strlen(d->_buf) > 0 || !feof(d->_fd));
}