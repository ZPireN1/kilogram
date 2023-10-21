#pragma once

/**
 * @typedef abstract type modeling a list element containing
 * - a pointer to a datum
 * - 2 pointers to its predecessor and successor resp.
 */
typedef struct  list_elm {
  void * datum;
  struct  list_elm * suc;
  struct  list_elm * pred; // Get Back To The ...
} list_elm_t;

/**
 * @brief create a new list element around datum
 * @param datum : a pointer to a datum
 * @return a list element
 */
list_elm_t * new_list_elm(void * datum);

/**
 * @brief delete list element and possibly its data
 * if ptrFct is null, function does not delete the data
 * if ptrFct is not null, function deletes the data
 * @param ptrE : a double pointer to a list element
 * @param ptrFct : a pointer to a function or NULL
 */
void del_list_elm(list_elm_t ** ptrE, void (*ptrFct)(void *));

/**
 * @brief who's next ?
 * @param E : list element
 */
list_elm_t * get_suc(list_elm_t * E);

/**
 * @brief who's before ?
 * @param E : list element
 */
list_elm_t * get_pred(list_elm_t * E);

/**
 * @brief what is the data ?
 * @param E : list element
 */
void * get_data(list_elm_t * E);

/**
 * @brief set list element's successor of E to S
 * @param E : list element
 * @param S : list element
 */
void set_suc(list_elm_t * E, list_elm_t * S);

/**
 * @brief set list element's predecessor of E to S 
 * @param E : list element
 * @param S : list element
 */
void set_pred(list_elm_t * E, list_elm_t * P);

/**
 * @brief set list element's datum of E to datum
 * @param E : list element
 * @param datum : datum
 */
void set_data(list_elm_t * E, void * datum);