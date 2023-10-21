#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "io.h"
#include "list.h"
#include "person.h"
#include "friendship.h"

/**
	@note une zone tampon utile aux fichiers binaires
*/
typedef struct {
	char nameA[LG];
	char forenameA[LG];
	char nameB[LG];
	char forenameB[LG];
} buffer_t;

list_t * stream_2_person_list ( char * filename, stream_mode_t mode ) {
  /**
  * @todo
  */
	return L;
}

list_t * stream_2_friendship_list ( char * filename, stream_mode_t mode, list_t * Lpers ) {
  /**
  * @todo
  */
	return L;
}

person_t * person_from_stream ( FILE * stream, stream_mode_t mode ) {
  /**
  * @todo
  */
	return P;
}

// void person_2_stream ( person_t * P, FILE * fd, stream_mode_t mode ) {
// }

friendship_t * friendship_from_stream(FILE * stream, stream_mode_t mode, list_t * Lpers){
  /**
  * @todo
  */
	return F;
}
