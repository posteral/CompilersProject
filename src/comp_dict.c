#include <stdlib.h>
#include <stdio.h>
#include "comp_dict.h"

struct comp_dict_t* dictCreate(void)
{
    int i;
	comp_dict_t *newDict;
	newDict = (comp_dict_t*)malloc(sizeof(comp_dict_t));
	newDict->start=NULL;
	newDict->end=NULL;
	 	
	return newDict;
}

void dictAddItem(struct comp_dict_t **dictionary, const char *key, int type, int code, int line){

     if(*dictionary == NULL)
     {
                    *dictionary = dictCreate();
   	 }   	 
   	 
     /*if key hasn't already been added: */
     if( (*dictionary)->hash[dictGetHashValue(key)] == NULL )
     {	 
         comp_dict_item_t *item = (comp_dict_item_t *)malloc(sizeof(comp_dict_item_t));
         item->key = key;
         item->code = code;
         item->type = type;
         item->line_occurrences = listCreate();
         item->next = NULL;     
                 
         if ((*dictionary)->start == NULL) 
         {
            //printf("\nNOTE: First element added on the dictionary!"); 
            (*dictionary)->start = item;      
            item->previous = NULL;
         }   
         else 
         {
              item->previous = (*dictionary)->end;
              (*dictionary)->end->next = item;
         }
              
         (*dictionary)->hash[dictGetHashValue(key)] = item;
         (*dictionary)->end = item; 
         //printf("\nNOTE: Element (%s,%d) added on the dictionary!", (*dictionary)->hash[dictGetHashValue(key)]->key, (*dictionary)->hash[dictGetHashValue(key)]->code);
     }
     
     listPush(&((*dictionary)->hash[dictGetHashValue(key)]->line_occurrences), line);
}

int dictEditItem(struct comp_dict_t *dictionary, const char *key, int new_code)
{
     if(dictionary->start == NULL || dictionary->hash[dictGetHashValue(key)] == NULL)
     { 
       //printf("\nWARNING: There is no element with this key in the dictionary to be edited!");
       return -1;   
     }
     
     dictionary->hash[dictGetHashValue(key)]->code = new_code;
     //printf("\nNOTE: The element %s has changed its value to %d!", key, new_code);
     return 0;     
}

int dictRemoveItem(struct comp_dict_t *dictionary, const char *key){ 
     comp_dict_item_t *removed_element;   

     if(dictionary->start == NULL || dictionary->hash[dictGetHashValue(key)] == NULL)
     { 
       //printf("\nWARNING: There is no element with this key in the dictionary to be removed!");
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
     else {
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
	  }
      
     listEmpty(removed_element->line_occurrences);         
     removed_element = NULL;
     //printf("\nNOTE: The element %s was removed!", key);  
     return 0;
}

void dictPrint(struct comp_dict_t *dictionary)
{
     comp_dict_item_t *printed_item;
     printed_item = dictionary->start;
     if(!printed_item)
                      printf("\nThe dictionary is empty!");
     while(printed_item != NULL)
     {
      printf("\nKEY: %s\t VALUE: %d\t TYPE: %d", printed_item->key, printed_item->code, printed_item->type);
      struct comp_list_t_t *line_list = printed_item->line_occurrences;
      printf(" LINES:");
      while(line_list)
      {
                      printf(" %d ", line_list->data);
                      line_list = line_list->next;
      }
      printed_item = printed_item->next;
     }
}

void dictEmpty(struct comp_dict_t *dictionary)
{
     comp_dict_item_t *removed_element, *to_be_removed_element;
     
     to_be_removed_element = dictionary->start;
     if(!to_be_removed_element)
                      printf("\nThe dictionary is empty!");
     
     while(to_be_removed_element != NULL)
     {
      removed_element = to_be_removed_element;
      to_be_removed_element = removed_element->next;
      dictRemoveItem(dictionary, removed_element->key);
     }
}

int dictGetHashValue(const char *key)
{
    int hash_value;
    for (hash_value = 0; *key != '\0'; key++)
      hash_value = *key + 31 * hash_value;
    return hash_value % HASH_SIZE; 
}

