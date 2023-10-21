#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "elmlist.h"

list_elm_t * new_list_elm ( void * datum ) {
  list_elm_t * E = calloc ( 1, sizeof(list_elm_t) );
  assert (E);
  E->datum = datum;
  return E;
}

void del_list_elm ( list_elm_t ** ptrE, void (*ptrf) () ) {
  /**
  * @todo
  */
}

list_elm_t * get_suc ( list_elm_t * E ) {
  assert (E);
  return E->suc;
}

list_elm_t * get_pred ( list_elm_t * E ) {
  /**
  * @todo
  */
}

void * get_data ( list_elm_t * E ) {
  assert (E);
  return E->datum;
}

void set_suc ( list_elm_t * E, list_elm_t * S ) {
  assert (E);
  E->suc = S;
}

void set_pred ( list_elm_t * E, list_elm_t * P ) {
  /**
  * @todo
  */
}

void set_data ( list_elm_t * E, void * data ) {
  assert (E);
  E->datum = data;
}