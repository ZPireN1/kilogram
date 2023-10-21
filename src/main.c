#include <stdio.h>
#include <ctype.h>

#include "list.h"
#include "person.h"
#include "friendship.h"
#include "io.h"

int main(int argc, char *argv[]){
	#ifdef _DEBUG_0
		printf ( "main starts with argv[1] = %s and argv[2] = %s\n", argv[1], argv[2] );
	#endif
	/* VERSION LECTURE AU CLAVIER */
	list_t * Lpers = new_list();
	int OK;
	char choix;
	do {
		person_t * P = scan_person();
		print_person(P);
		insert_ordered(Lpers, P, &cmp_person);
		do{
			printf("Une aute personne ? (O/N) "), scanf(" %c", &choix);
			choix = toupper(choix);
		}while(choix != 'N' && choix != 'O');
		OK = (choix == 'O');
	}while(OK);
	view_list(Lpers, &print_person, "_______Liste des personnes_______");
	/******
		VERSION LECTURE D'UN FICHIER DE PERSONNES
		À FAIRE UNE FOIS LA VERSION CLAVIER FONCTIONNANT

	list_t * Lpers = stream_2_person_list ( argv[1], TEXT );
	******/

	/* VERSION LECTURE AU CLAVIER */
	list_t * Lfriends = new_list();
	do{
		friendship_t * F = scan_friendship(Lpers);
		print_friendship(F);
		queue(Lfriends,F);
		do{
			printf("Une aute amitié ? (O/N) "), scanf(" %c", &choix);
			choix = toupper(choix);
		}while(choix != 'N' && choix != 'O');
		OK = (choix == 'O');
	}while(OK);
	view_list(Lfriends, &print_friendship, "_______Liste des amitiés_______");
	return 0;
	/******
		VERSION LECTURE D'UN FICHIER DE PERSONNES
		À FAIRE UNE FOIS LA VERSION CLAVIER FONCTIONNANT

	list_t * Lfriends = stream_2_friendship_list ( argv[2], TEXT, Lpers );
	******/
}
