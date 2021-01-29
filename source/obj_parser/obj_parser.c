/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:09:29 by jhache            #+#    #+#             */
/*   Updated: 2021/01/29 23:18:00 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_parser.h"
#include "parsing/parsing.h"
#include "lexing/lexing.h"

#include <stdlib.h>
#include <stdio.h>

void					destroy_obj_file(t_obj_file *data)
{
	size_t		i;
	t_darray	*arrays;

	if (data == NULL)
		return ;
	gl_close_file(&data->filedata);
	arrays = &data->v;
	i = 0;
	while (i < NUMBER_OF_DARRAY)
	{
		del_darray(arrays + i++);
	}
}

/*
** NB: data must be allocated before calling init_data().
*/
static bool				init_data(t_obj_file *data, const char *filename)
{
	size_t				i;
	t_darray * const	first_array = &data->v;

	data->filename = filename;
	data->filedata = gl_open_file(filename);
	if (data->filedata._fd == NULL)
	{
		destroy_obj_file(data);
		return (false);
	}
	i = 0;
	while (i < NUMBER_OF_DARRAY)
	{
		first_array[i] = create_darray();
		if (first_array[i++].data == NULL)
		{
			destroy_obj_file(data);
			return (false);
		}
	}
	return (true);
}

t_obj_file				*parse_file(const char *filename)
{
	t_obj_file	*data;

	data = (t_obj_file*)calloc(1, sizeof(t_obj_file));
	if (data == NULL || !init_data(data, filename))
	{
		free(data);
		return (NULL);
	}
	while (get_line(&data->filedata))
	{
		printf("parsing\t\"%s\"\n", data->filedata.line);
		t_obj_data_type data_type = lex_line(data->filedata.line);
		if (!parse_line(&data->v, data_type, data->filedata.line))
		{
			printf("Error while parsing. exiting the parser...\n");
			destroy_obj_file(data);
			free(data);
			return (NULL);
		}
	}
	return (data);
}