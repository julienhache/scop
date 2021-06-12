/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 11:55:28 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 20:13:43 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_DYNAMIC_ARRAY_DYNAMIC_ARRAY_H
#define UTILS_DYNAMIC_ARRAY_DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DynamicArray {
    void * data;
    size_t size;
    size_t capacity;
} DynamicArray;

#define DARRAY_MIN_SIZE 128

bool         DArrayInit(DynamicArray *arr, size_t size);
DynamicArray DArrayCreate(void);
void         DArrayDelete(DynamicArray *arr);

bool DArrayAppend(DynamicArray *arr, void *data, size_t size);

#endif