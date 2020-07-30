/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_method1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:57:55 by jhache            #+#    #+#             */
/*   Updated: 2020/07/30 11:26:08 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_parser.h"

bool		dummy_parsing(t_darray *data_array, const char *line)
{
	(void)data_array;
	(void)line;
	return (true);
}

bool		error_parsing(t_darray *data_array, const char *line)
{
	(void)data_array;
	(void)line;
	return (false);
}