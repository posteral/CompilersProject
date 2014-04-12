#ifndef COMP_DICT_H
#define COMP_DICT_H

#include "comp_list.h"

#define HASH_FUNCTION 1537
#define MAX_HASH_TABLE_SIZE 10000
#define MAX_KEY_SIZE 10000

#define IKS_SIMBOLO_INDEFINIDO 0
#define IKS_SIMBOLO_LITERAL_INT 1
#define IKS_SIMBOLO_LITERAL_FLOAT 2
#define IKS_SIMBOLO_LITERAL_CHAR 3
#define IKS_SIMBOLO_LITERAL_STRING 4
#define IKS_SIMBOLO_LITERAL_BOOL 5
#define IKS_SIMBOLO_IDENTIFICADOR 6

/*
    brief: This variable stores a literal with the correponding type.
*/
typedef union data_type {
        char  undefined_type[MAX_KEY_SIZE];
        int   int_type;
        float float_type;
        char  char_type;
        char  string_type[MAX_KEY_SIZE];
        int   bool_type;
        char  identifier_type[MAX_KEY_SIZE];
} data_type;

/*
    brief: This structure corresponds to the entries in the symbols table (dictionnary).
*/
typedef struct comp_dict_item_t {
        struct comp_dict_item_t* next;
        struct comp_dict_item_t* previous;
        struct comp_list_t_t*    line_occurrences;
        union  data_type         data;
        int                      type;
        int                      code;            
        char                     key[MAX_KEY_SIZE];  
} comp_dict_item_t;

/*
    brief:        This structure is the symbols table (dictionnary).
*/
typedef struct comp_dict_t {
        comp_dict_item_t* hash[MAX_HASH_TABLE_SIZE];
        comp_dict_item_t* start;               
        comp_dict_item_t* end; 
} comp_dict_t;

/*
    brief:        Create the symbols table.   
    parameters:   -
    return:       The symbols table.
*/
struct comp_dict_t* dictCreate();

/*
    brief:        Set the data of a literal symbol. For exemple the entry "3.0" of
                  the symbols table contains a float data type float containing 3.0
                  thanks to this function.     
    parameters:   dictionary - The symbols table,
                  key - The entry symbol of the symbols table to be seted.
    return: -
*/
void                dictSetData(struct comp_dict_t *dictionary, char *key);

/*
    brief:        Get the symbol of a literal entry in the symbols table.
    parameters:   symbol - A pointer to an entry of the symbols table.
    return:       A pointer to the symbol contained on the entry specified.
*/
void*               dictGetData(struct comp_dict_item_t *symbol);

/*
    brief:        Add a symbol to the symbols table.
    parameters:   dictionary - The symbols table,
                  key  - The symbol found,
                  type - The type of the symbol,
                  code - The code that identifies the symbol,
                  line - The line where the symbol was found.
    return:       A pointer to the entry added on the symbols table.
*/
comp_dict_item_t*   dictAddItem(struct comp_dict_t **dictionary, char *key, int type, int code, int line);

/*
    brief:        Edit an entry of the symbols table by changing the code associated to the symbol.
    parameters:   dictionary  - The symbols table,
                  key         - The symbol,
                  new_code    - The new code.
    returns:      Error code.
*/
int                 dictEditItem(struct comp_dict_t *dictionary, char *key, int new_code);

/*
    brief:        Remove an entry of the symbols table.
    parameters:   dictionary  - The symbols table,
                  key         - The symbol.
    returns:      Error code.
*/
int                 dictRemoveItem(struct comp_dict_t *dictionary, char *key);

void                dictPrintElementData(comp_dict_t *dictionary, char *key, int type);
void                dictPrint(struct comp_dict_t *dictionary);
void                dictEmpty(struct comp_dict_t *dictionary);

/*
    brief:        Hash function used on the dictionary structure.
    parameters:   s - The symbol on the entry of the symbols table.
    return:       The position of the symbol on the symbols table.
*/
int                 dictGetHashValue(char *s);

#endif
