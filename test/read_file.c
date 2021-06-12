/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:26:49 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 20:04:02 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/utils/get_line/get_line.h"

int main(int ac, char **av) {
    GLData test;

    if (ac < 2) return -1;
    test = GLOpenFile(av[1]);
    while (GLGetLine(&test)) {
        printf("%s\n", test.line);
    }
    return 0;
}