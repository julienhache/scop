/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <jhache@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:22:36 by jhache            #+#    #+#             */
/*   Updated: 2021/06/12 20:21:04 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_array.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static size_t _RemainingSize(DynamicArray *arr) {
    return (arr->capacity - arr->size);
}

static bool _Extend(DynamicArray *arr, size_t size) {
    void *const tmp = realloc(arr->data, arr->capacity + size);
    const bool  res = (tmp != NULL);

    if (res) {
        arr->data = tmp;
        arr->capacity += size;
    }
    return res;
}

bool DArrayInit(DynamicArray *arr, size_t size) {
    if (size < DARRAY_MIN_SIZE) {
        size = DARRAY_MIN_SIZE;
    }
    arr->data = malloc(size);
    if (arr->data == NULL) {
        return false;
    }
    arr->capacity = size;
    arr->size = 0;
    return true;
}

DynamicArray DArrayCreate(void) {
    DynamicArray res;

    DArrayInit(&res, DARRAY_MIN_SIZE);
    return res;
}

// clang-format off
void DArrayDelete(DynamicArray *arr) {
	free(arr->data);
}
// clang-format on

/* may call _Extend() if necessary (it will double the capacity) */
bool DArrayAppend(DynamicArray *arr, void *data, size_t size) {
    const size_t new_size = arr->size + size;

    if (new_size < arr->size) {
        return false;
    }
    while (_RemainingSize(arr) < size) {
        if (!_Extend(arr, arr->capacity)) {
            return false;
        }
    }
    memcpy(arr->data + arr->size, data, size);
    arr->size = new_size;
    return true;
}