#ifndef COMP_DICT_H
#define COMP_DICT_H

#include "comp_list.h"

#define HASH_FUNCTION 101
#define MAX_HASH_TABLE_SIZE 10000
#define MAX_KEY_SIZE 10000

#define IKS_SIMBOLO_INDEFINIDO 0
#define IKS_SIMBOLO_LITERAL_INT 1
#define IKS_SIMBOLO_LITERAL_FLOAT 2
#define IKS_SIMBOLO_LITERAL_CHAR 3
#define IKS_SIMBOLO_LITERAL_STRING 4
#define IKS_SIMBOLO_LITERAL_BOOL 5
#define IKS_SIMBOLO_IDENTIFICADOR 6

typedef union data_type {
        char  undefined_type[MAX_KEY_SIZE];
        int   int_type;
        float float_type;
        char  char_type;
        char  string_type[MAX_KEY_SIZE];
        int   bool_type;
        char  identifier_type[MAX_KEY_SIZE];
} data_type;

typedef struct comp_dict_item_t {
        struct comp_dict_item_t* next;
        struct comp_dict_item_t* previous;
        struct comp_list_t_t*    line_occurrences;
        union  data_type         data;
        int                      type;
        int                      code;            
        char                     key[MAX_KEY_SIZE];  
} comp_dict_item_t;

typedef struct comp_dict_t {
        comp_dict_item_t* hash[MAX_HASH_TABLE_SIZE];
        comp_dict_item_t* start;               
        comp_dict_item_t* end; 
} comp_dict_t;

struct comp_dict_t* dictCreate();
void                dictSetData(struct comp_dict_t *dictionary, char *key);
void                dictAddItem(struct comp_dict_t **dictionary, char *key, int type, int code, int line);
int                 dictEditItem(struct comp_dict_t *dictionary, char *key, int new_code);
int                 dictRemoveItem(struct comp_dict_t *dictionary, char *key);
void                dictPrintElementData(comp_dict_t *dictionary, char *key, int type);
void                dictPrint(struct comp_dict_t *dictionary);
void                dictEmpty(struct comp_dict_t *dictionary);
int   dictGetHashValue(char *s);

#endif
