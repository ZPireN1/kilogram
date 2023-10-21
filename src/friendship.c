#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "friendship.h"
#include "person.h"
#include "list.h"

friendship_t * new_friendship(){
	friendship_t * F = calloc ( 1, sizeof(friendship_t) );
	assert ( F );
	return F;
}

friendship_t * scan_friendship(list_t * Lpers){
  friendship_t * F = new_friendship ();
	printf ( "Définissez une amitié entre \n" );
	person_t * P = scan_person ();
	person_t * P1 = find ( Lpers, P, &cmp_person );
	assert ( P1 );
	free_person ( &P, NULL );
  /**
  * @todo
  */
	return F;
}

void free_friendship(friendship_t ** ptrFriend, bool del_persons){
  /**
  * @todo
  */
}

int cmp_friendship(friendship_t * F1, friendship_t * F2){
  /**
  * @todo
  */
}

void print_friendship(friendship_t * F){
	printf ( "___________Friendship___________\n" );
	print_person ( F->A );
	printf ( "\n" );
	print_person ( F->B );
	printf ( "\t\t\t\tS'AIMENT D'AMOUR\n" );
	printf ( "________Friendship ended________\n" );
}
