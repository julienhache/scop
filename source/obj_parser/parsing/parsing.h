/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:00:34 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 20:14:22 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_PARSING_PARSING_H
#define OBJ_PARSER_PARSING_PARSING_H

#include "../obj_parser.h"

bool ParseLine(DynamicArray *data_array, ObjDataType type, const char *line);

#endif