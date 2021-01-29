/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 22:44:24 by jhache            #+#    #+#             */
/*   Updated: 2021/01/29 22:45:08 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/dynamic_array/dynamic_array.h"

bool		dummy_parsing(t_darray *data, const char *line)
{
	(void)data;
	(void)line;
	return (true);
}

bool		error_parsing(t_darray *data, const char *line)
{
	(void)data;
	(void)line;
	return (false);
}