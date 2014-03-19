#include "comp_list.h"

#define MAX_HASH_SLOT 10000
#define HASH_SIZE 101

typedef struct comp_dict_item_t {
        struct comp_dict_item_t* next;
        struct comp_dict_item_t* previous;
        struct comp_list_t_t *line_occurrences;
        int code;            
        const char* key;  
} comp_dict_item_t;

typedef struct comp_dict_t {
        comp_dict_item_t* hash[MAX_HASH_SLOT]; 
        comp_dict_item_t* start;               
        comp_dict_item_t* end; 
} comp_dict_t;

struct comp_dict_t* dictCreate();
void                dictAddItem(struct comp_dict_t **dictionary, const char *key, int code, int line);
int                 dictEditItem(struct comp_dict_t *dictionary, const char *key, int new_code);
int                 dictRemoveItem(struct comp_dict_t *dictionary, const char *key);
void                dictPrint(struct comp_dict_t *dictionary);
void                dictEmpty(struct comp_dict_t *dictionary);
int                 dictGetHashValue(const char *key);
