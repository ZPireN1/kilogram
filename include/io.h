#pragma once

#include <stdio.h>

#include "list.h"
#include "friendship.h"
#include "person.h"

typedef enum { BIN, TEXT } stream_mode_t;

list_t * stream_2_person_list(char * filename, stream_mode_t mode);
list_t * stream_2_friendship_list(char * filename, stream_mode_t mode, list_t * Lpers);

friendship_t * friendship_from_stream(FILE * stream, stream_mode_t mode, list_t * Lpers);
// friendship_t * friendship_2_stream(FILE * stream, stream_mode_t mode, list_t * Lpers);

person_t * person_from_stream(FILE * stream, stream_mode_t mode);
// void person_2_stream(person_t * P, FILE * fd, stream_mode_t mode);