#include <stdlib.h>
#include "../include/comp_dict.h"

struct comp_dict_t* dictCreate(void){
	comp_dict_t *newDict;
	
	newDict = (comp_dict_t*)malloc(sizeof(comp_dict_t));
	
	return newDict;
}

void dictAddItem(struct comp_dict_t *dictionary, const char *key, const char *data){
     comp_dict_item_t *item = (comp_dict_item_t *)malloc(sizeof(comp_dict_item_t));
     item->data = data;
     item->next = NULL;
     
     if (dictionary->start == NULL) {        
        item->previous = NULL;
     }   
     else {
          item->previous = dictionary->end;
          dictionary->end->next = item;
          }
          
     dictionary->hash[dictGetHashValue(key)] = item;
     dictionary->end = item; 
}

int dictEditItem(struct comp_dict_t *dictionary, const char *key, const char *new_data)
{
     if(dictionary->start == NULL || dictionary->hash[dictGetHashValue(key)] == NULL)
     { 
       printf("WARNING: There is no element with this key in the dictionary!");
       return -1;   
     }
     
     dictionary->hash[dictGetHashValue(key)]->data = new_data;
     return 0;     
}

int dictRemoveItem(struct comp_dict_t *dictionary, const char *key){ 
     comp_dict_item_t *removed_element;   

     if(dictionary->start == NULL || dictionary->hash[dictGetHashValue(key)] == NULL)
     { 
       printf("WARNING: There is no element with this key in the dictionary!");
       return -1;   
     }
     
     // First element
     if(dictionary->hash[dictGetHashValue(key)]->previous == NULL) 
     {   
         removed_element = dictionary->hash[dictGetHashValue(key)];   
         dictionary->start = dictionary->hash[dictGetHashValue(key)]->next;   
         if(dictionary->start == NULL)  
                              dictionary->end = NULL; 
         else   
                              dictionary->start->previous = NULL; 
     }
     else 
          // Last element
          if(dictionary->hash[dictGetHashValue(key)]->next == NULL) 
          {   
            removed_element = dictionary->hash[dictGetHashValue(key)];   
            dictionary->end->previous->next = NULL;   
            dictionary->end = dictionary->end->previous;   
          }
          // Otherwise
          else 
          {   
              dictionary->hash[dictGetHashValue(key)]->previous->next = dictionary->hash[dictGetHashValue(key)]->next;   
              dictionary->hash[dictGetHashValue(key)]->next->previous = dictionary->hash[dictGetHashValue(key)]->previous;   
          }
               
     free(removed_element);     
     return 0;
}

void dictPrint(struct comp_dict_t *dictionary)
{
     comp_dict_item_t *printed_item;
     printed_item = dictionary->start;
     
     while(printed_item != NULL)
     {
      printf("\nKEY: %s \nVALUE: %s", printed_item->key, printed_item->data);
      printed_item = printed_item->next;
     }
}

void dictEmpty(struct comp_dict_t *dictionary)
{
     comp_dict_item_t *removed_item;
     removed_item = dictionary->start;
     
     while(removed_item != NULL)
     {
      dictRemoveItem(dictionary, removed_item->key);
      removed_item = removed_item->next;
     }
}

int dictGetHashValue(const char *key)
{
    int hash_value;
    for (hash_value = 0; *key != '\0'; key++)
      hash_value = *key + 31 * hash_value;
    return hash_value % HASH_SIZE;   
}
