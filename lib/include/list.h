/**
 * @file list.h
 * @brief Header of a list implementation.
 * @author Guillaume Roumage
 * @date 04/2024
*/

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

typedef enum list_error_e {
    LIST_E_SUCCESS,
    LIST_E_MEMORY,
    LIST_E_LIST_IS_NULL,
    LIST_E_LIST_MANIPULATION,
    LIST_E_FILE_DESCRIPTOR_IS_NULL,
} list_error_t;

typedef struct list_node_t {
    uint8_t coeff;
    struct list_node_t *next;
} list_node_t;

typedef struct list_t {
    list_node_t *head;
    list_node_t *tail;
    size_t size;
} list_t;

list_t *list_init();
list_t *list_create_from_array(uint8_t *coeffs, size_t size);
list_t *list_copy(list_t *l);
list_error_t list_destroy(list_t *l);
list_error_t list_add_beginning(list_t *l, uint8_t coeff);
list_error_t list_add_end(list_t *l, uint8_t coeff);
list_error_t list_add_at(list_t *l, uint8_t coeff, size_t pos);
list_error_t list_add_after(list_t *l, uint8_t coeff, list_node_t *node);
list_error_t list_remove_coeff(list_t *l, uint8_t coeff);
list_error_t list_remove_node(list_t *l, list_node_t *node);
list_error_t list_remove_head(list_t *l);
list_error_t list_remove_tail(list_t *l);
list_error_t list_get_pos(list_t *l, list_node_t *node);
list_node_t *list_get_at_pos(list_t *l, size_t pos);
list_error_t list_print(FILE *, list_t *l);
list_error_t list_assert(list_t *l, uint8_t *coeffs, size_t size);

#endif // LIST_H
