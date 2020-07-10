/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:20:10 by jhache            #+#    #+#             */
/*   Updated: 2020/07/10 03:05:07 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool		my_reallocf(void **data, size_t size)
{
	void		*new_buf;

	new_buf = realloc(*data, size);
	if (new_buf == NULL)
	{
		free(*data);
		return (false);
	}
	*data = new_buf;
	return (true);
}

t_gl_data		open_file(char *filename)
{
	t_gl_data	data;

	data.fd = fopen(filename, "r");
	data.line = NULL;
	data._buf[0] = '\0';
	return (data);
}

void			close_file(t_gl_data *data)
{
	fclose(data->fd);
}

size_t			get_line(t_gl_data *data)
{
	char		*tmp;
	size_t		wcount;
	size_t		rcount;

	rcount = 0;
	while (true)
	{
		tmp = strchr(data->_buf, '\n');
		wcount = (tmp != NULL ? tmp - data->_buf : strlen(data->_buf));
		rcount += wcount;
		if (!my_reallocf(&data->line, rcount + 1))
			return (-1);
		strncat(data->line, data->_buf, wcount);
		data->line[rcount] = '\0';
		if (tmp != NULL)
		{
			memmove(data->_buf, data->_buf + wcount + 1,
					GETLINE_BUFFER_SIZE - wcount);
			break ;
		}
		wcount = fread(data->_buf, 1, GETLINE_BUFFER_SIZE, data->fd);
		if (wcount != GETLINE_BUFFER_SIZE)//EOF or error, we add a \n to end the loop at the next lap
			data->_buf[wcount] = '\n';
	}
	return (rcount);
}