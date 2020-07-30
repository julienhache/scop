/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:26:49 by jhache            #+#    #+#             */
/*   Updated: 2020/07/26 22:00:01 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/utils/get_line/get_line.h"

int main(int ac, char **av)
{
	t_gl_data	test;

	if (ac < 2)
		return -1;
	test = gl_open_file(av[1]);
	while (get_line(&test))
	{
		printf("%s\n", test.line);
	}
	return 0;
}