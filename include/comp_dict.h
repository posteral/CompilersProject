#define MAX_HASH_SLOT 10000

typedef struct comp_dict_item_t {
        struct comp_dict_item_t* next;
        struct comp_dict_item_t* previous;
        void* data;            
        const char* key;  
} comp_dict_item_t;

typedef struct comp_dict_t {
        comp_dict_item_t* hash[MAX_HASH_SLOT]; 
        comp_dict_item_t* start;               
        comp_dict_item_t* end; 
} comp_dict_t;

struct comp_dict_t* dictCreate();
