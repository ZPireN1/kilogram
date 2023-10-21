#pragma once

#include "person.h"

typedef struct {
    person_t * A;
    person_t * B;
} friendship_t;

friendship_t * new_friendship ();
friendship_t * scan_friendship ();
void free_friendship(friendship_t ** ptrFriend, bool del_persons);

int cmp_friendship(friendship_t * F1, friendship_t * F2);
void print_friendship(friendship_t * F);
