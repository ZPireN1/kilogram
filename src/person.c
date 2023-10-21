#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "person.h"
#include "friendship.h"
#include "io.h"

person_t * new_person () {
	person_t * P = calloc ( 1, sizeof(person_t) );
	assert (P);
	P->birth_date.day = 1;
	P->birth_date.month = 4;
	P->birth_date.year = 69;
	P->friends = new_list ( );
	return P;
}

person_t * scan_person () {
	person_t * P = calloc ( 1, sizeof(person_t) );
	assert (P);
	printf ( "Nom : " ), scanf ( "%s", P->name );
	printf ( "Prénom : " ), scanf ( "%s", P->forename );
	printf ( "Date de naissance (jj/mm/aaaa) " ), scanf ( "%d/%d/%d", &(P->birth_date.day), &(P->birth_date.month), &(P->birth_date.year) );
	P->friends = new_list ( );
	return P;
}

void free_person ( person_t ** ptrP, bool del_friends ) {
	assert (ptrP && *ptrP);
	if ( del_friends ) {
		del_list( &((*ptrP)->friends), NULL );
	}
	free (*ptrP);
	*ptrP = NULL;
}

int cmp_person (person_t * P1, person_t * P2 ) {
	int cmpNames = strcmp ( P1->name, P2->name );
	return ( cmpNames == 0 ) ? strcmp ( P1->forename, P2->forename ) : cmpNames;
}

void print_person ( person_t * P ) {
    assert (P);
		printf ( "___________Person___________\n" );
    printf ( "\tNom : %s\n", P->name );
		printf ( "\tPrénom : %s\n", P->forename );
		printf ( "\tDate de naissance : %02d/%02d/%04d\n", P->birth_date.day, P->birth_date.month, P->birth_date.year );
		printf ( "\tAvec %02d amitiés !\n", P->friends->numelm );
		printf ( "________Person ended________\n" );
}
