/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 10:11:57 by jhache            #+#    #+#             */
/*   Updated: 2020/07/26 22:42:16 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "obj_parser/obj_parser.h"

int	main(int argc, char **argv)
{
	t_obj_file	*file_data;

	if (argc != 2)
		return (0);
	file_data = parse_file(argv[1]);
	destroy_obj_file(file_data);
	free(file_data);
	return (0);
}