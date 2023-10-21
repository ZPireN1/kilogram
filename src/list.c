#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "elmlist.h"
#include "list.h"

/*********************************
DÉCLARATIONS DES FONCTIONS PRIVÉES
*********************************/
void insert_after ( list_t * L, void * datum, list_elm_t * place );

/**********************************
DÉFINITIONS DES FONCTIONS PUBLIQUES
**********************************/
list_t * new_list () {
  list_t * L = calloc ( 1, sizeof(list_t) );
  assert (L);
  return L;
}

void del_list ( list_t ** ptrL, void (*ptrf) () ) {
  /**
  * @todo
  */
}

bool empty_list ( list_t * L ) {
  assert (L);
  return L->numelm == 0;
}

list_elm_t * get_head ( list_t * L ) {
  assert (L);
  return L->head;
}

list_elm_t * get_tail ( list_t * L ) {
  assert (L);
  return L->tail;
}

void cons ( list_t * L, void * datum ) {
  /**
  * @todo
  */
}

void queue ( list_t * L, void * datum ) {
  /**
  * @todo
  */
}

void insert_ordered ( list_t * L, void * datum, int (*cmp_ptrf) () ) {
  /**
  * @todo
  */
}

void * find ( list_t * L, void * datum, int (*ptrFct) () ) {
  /**
  * @todo
  */
}

void view_ligne ( int length ) {
  printf ( "\t\t" );
	for(int c=0; c < length; c += 1 ) printf ( "=");
	printf ( "\n" );
}

void view_list ( list_t * L, void (*view_fct_ptr) (), char * entete) {
	int lg = strlen ( entete ) + 5;
	view_ligne ( lg );
  printf ( "\t\t|| %s ||\n", entete );
	view_ligne ( lg );
  if ( empty_list ( L ) ) {
    printf("[ ] //empty list\n");
  }
  else {
    list_elm_t * iterator = L->head;
    while ( iterator ) {
      (*view_fct_ptr) ( iterator->datum );
			printf ( "\n" );
      iterator = iterator->suc;
    }
  }
  view_ligne ( lg );
}

/*******************************************
Définitions des fonctions privées du TA list
*******************************************/

void insert_after ( list_t * L, void * datum, list_elm_t * place) {
  assert (L);
  if ( empty_list ( L ) || !place ) {
    cons ( L, datum );
  } else if ( place == L->tail ) {
    queue ( L, datum );
  } else {
    list_elm_t * E = new_list_elm( datum );
    E->pred = place;
    E->suc = place->suc;
    place->suc->pred = E;
    place->suc = E;
    L->numelm += 1;
  }
}