#pragma once

#include <stdbool.h>
#include "elmlist.h"

/**
Abstract type for double-linked list modeled by
- 2 pointers pointing to the head and the tail of the list
- the number of element the list contains
*/
typedef struct {
  list_elm_t * head, * tail;
  int numelm;
} list_t;

/****************
Constructors & co
****************/
list_t * new_list();

void del_list(list_t ** ptrL, void (*ptrf) ());

bool empty_list(list_t * L);

/********************
Accessors & modifiers
********************/
list_elm_t * get_head(list_t * L);
void set_head(list_t * L);

list_elm_t * get_tail(list_t * L);
void set_tail(list_t * L);

/** Add on head, add on tail, insert data after place localized by cmp_ptr */
void cons(list_t * L, void * datum);

void queue(list_t * L, void * datum);

void insert_ordered(list_t * L, void * datum, int (*cmp_ptrf) ());

/** Display list on stdout stream */
void view_list(list_t * L, void (*view_fct_ptr) (), char * entete);

void * find(list_t * L, void * datum, int (*ptrFct) ());