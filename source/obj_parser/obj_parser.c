/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:09:29 by jhache            #+#    #+#             */
/*   Updated: 2020/07/30 12:04:45 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_parser.h"
#include "parsing_methods.h"

#include <stdlib.h>
#include <stdio.h>

const obj_parsing_func	g_parsing_array[OBJ_DATA_TYPE_FLAGS_NB] = {
	dummy_parsing,
	dummy_parsing,
	dummy_parsing,
	dummy_parsing,
	dummy_parsing,
	error_parsing
};

void					destroy_obj_file(t_obj_file *data)
{
	size_t				i;
	t_darray * const	first_array = &data->v;

	if (data == NULL)
		return ;
	gl_close_file(&data->filedata);
	i = 0;
	while (i < NUMBER_OF_DARRAY)
	{
		del_darray(first_array + i++);
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

t_obj_data_type			lex_line(const char *line)
{
	(void)line;
	return (OBJ_NONE);
}

static bool			parse_line_data(
	t_darray *data_array, t_obj_data_type type, const char *line)
{
	return g_parsing_array[type](data_array, line);
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
		printf("parsing \"%s\"\n", data->filedata.line);
		t_obj_data_type data_type = lex_line(data->filedata.line);
		//printf("data_type: %d\n", data_type);
		if (!parse_line_data(&data->v, data_type, data->filedata.line))
		{
			//printf("Error while parsing. exiting the parser...\n");
			destroy_obj_file(data);
			free(data);
			return (NULL);
		}
		//printf("Parsed. going to next line...\n\n");
	}
	return (data);
}