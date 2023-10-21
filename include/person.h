#pragma once

#include <stdbool.h>

// #include "io.h"
#include "list.h"

/**
    @note LG assure une allocation statique des chaînes de caractères
        C'est utile pour charger/sauvegarder dans un fichier binaire.
*/
#define LG 40

typedef struct {
    char name[LG];
    char forename[LG];
    struct {
        int day;
        int month;
        int year;
    } birth_date;
	list_t * friends;
	// bool passing_through;
} person_t;

person_t * new_person();
person_t * scan_person();
void free_person(person_t ** ptrP, bool del_friends);

int cmp_person(person_t * P1, person_t * P2);
void print_person(person_t * P);
