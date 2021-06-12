/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 10:11:57 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 18:36:37 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "obj_parser/obj_parser.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        return 0;
    }

    ObjFile *file_data = ParseFile(argv[1]);
    DestroyObjFile(file_data);
    free(file_data);
    return (0);
}