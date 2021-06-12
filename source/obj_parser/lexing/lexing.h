/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:47:34 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 19:44:01 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_LEXING_LEXING_H
#define OBJ_PARSER_LEXING_LEXING_H

#include "../obj_parser.h"

ObjDataType LexLine(const char *line);

#endif