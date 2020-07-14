/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:26:49 by jhache            #+#    #+#             */
/*   Updated: 2020/07/14 16:18:31 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/utils/get_line/get_line.h"

int main(int ac, char **av)
{
	t_gl_data	test;
	size_t		ret;

	if (ac < 2)
		return -1;
	test = open_file(av[1]);
	while ((ret = get_line(&test)) > 0)
	{
		printf("%s\n", test.line);
	}
	return 0;
}