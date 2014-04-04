#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "comp_dict.h"

struct comp_dict_t* dictCreate(void)
{
    int i;
	comp_dict_t *newDict;
	
    newDict = (comp_dict_t*)malloc(sizeof(comp_dict_t));
	newDict->start=NULL;
	newDict->end=NULL;
	for(i = 0; i < MAX_HASH_TABLE_SIZE; i++)
	      newDict->hash[i] = NULL;
	
	return newDict;
}

void dictSetData(struct comp_dict_t *dictionary, char *key)
{
     switch(dictionary->hash[dictGetHashValue(key)]->type){
                              case IKS_SIMBOLO_INDEFINIDO: 
                                   strcpy(dictionary->hash[dictGetHashValue(key)]->data.undefined_type, key);
                                   //printf("%s", dictionary->hash[dictGetHashValue(key)]->data.undefined_type);
                                   break; 
                              case IKS_SIMBOLO_LITERAL_INT:
                                   dictionary->hash[dictGetHashValue(key)]->data.int_type = atoi(key);
                                   //printf("%d", dictionary->hash[dictGetHashValue(key)]->data.int_type);
                                   break;   
                              case IKS_SIMBOLO_LITERAL_FLOAT:
                                   dictionary->hash[dictGetHashValue(key)]->data.float_type = atof(key);
                                   //printf("%f", dictionary->hash[dictGetHashValue(key)]->data.float_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_CHAR:
                                   dictionary->hash[dictGetHashValue(key)]->data.char_type = *key;
                                   //printf("%c", dictionary->hash[dictGetHashValue(key)]->data.char_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_STRING:
                                   strcpy(dictionary->hash[dictGetHashValue(key)]->data.string_type, key);
                                   //printf("%s", dictionary->hash[dictGetHashValue(key)]->data.string_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_BOOL: 
                                   if( strcmp(key, "true") == 0 )
                                                  dictionary->hash[dictGetHashValue(key)]->data.bool_type = 1;
                                   else
                                                  dictionary->hash[dictGetHashValue(key)]->data.bool_type = 0;
                                   break;
                              case IKS_SIMBOLO_IDENTIFICADOR:
                                   strcpy(dictionary->hash[dictGetHashValue(key)]->data.identifier_type, key);
                                   //printf("%s", dictionary->hash[dictGetHashValue(key)]->data.identifier_type);
                                   break;
     } 
}

comp_dict_item_t* dictAddItem(struct comp_dict_t **dictionary, char *key, int type, int code, int line){

	 //return;
     if(*dictionary == NULL)
     {
                    *dictionary = dictCreate();
   	 }   	 

     /*if key hasn't already been added: */
     //printf("\nTrying to access hash[%d]", dictGetHashValue(key));
     //if(dictGetHashValue(key)<0)
	//	return;
	
	comp_dict_item_t *item = NULL;
	
	
     if( (*dictionary)->hash[dictGetHashValue(key)] == NULL )
     {	 
		 item = (comp_dict_item_t *)malloc(sizeof(comp_dict_item_t));
         strcpy(item->key, key);
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
     dictSetData(*dictionary, key);
     
     return (*dictionary)->hash[dictGetHashValue(key)];
}

int dictEditItem(struct comp_dict_t *dictionary, char *key, int new_code)
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

int dictRemoveItem(struct comp_dict_t *dictionary, char *key){ 
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

void dictPrintElementData(comp_dict_t *dictionary, char *key, int type)
{
 switch(type){
                              case IKS_SIMBOLO_INDEFINIDO: 
                                   printf("%s", dictionary->hash[dictGetHashValue(key)]->data.undefined_type);
                                   break; 
                              case IKS_SIMBOLO_LITERAL_INT:
                                   printf("%d", dictionary->hash[dictGetHashValue(key)]->data.int_type);
                                   break;   
                              case IKS_SIMBOLO_LITERAL_FLOAT:
                                   printf("%f", dictionary->hash[dictGetHashValue(key)]->data.float_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_CHAR:
                                   printf("%c", dictionary->hash[dictGetHashValue(key)]->data.char_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_STRING:
                                   printf("%s", dictionary->hash[dictGetHashValue(key)]->data.string_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_BOOL: 
                                   printf("%d", dictionary->hash[dictGetHashValue(key)]->data.int_type);
                                   break;
                              case IKS_SIMBOLO_IDENTIFICADOR:
                                   printf("%s", dictionary->hash[dictGetHashValue(key)]->data.identifier_type);
                                   break;
     }                       
}

void dictPrint(struct comp_dict_t *dictionary)
{
     comp_dict_item_t *printed_item;
     printed_item = dictionary->start;
     if(!printed_item)
                      printf("\nThe dictionary is empty!");
     while(printed_item != NULL)
     {
      printf("\nKEY: %s\t VALUE: %d\t TYPE: %d\t DATA: ", printed_item->key, printed_item->code, printed_item->type);
      dictPrintElementData(dictionary, printed_item->key, printed_item->type);
      struct comp_list_t_t *line_list = printed_item->line_occurrences;
      printf("\t LINES:");
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

int dictGetHashValue(char *key)
{
    long int hash_value;	
    int i = 0;
    for (hash_value = 0; *key != '\0'; key++){
		//printf("\n*key = %d", *key);
      hash_value = *key +  hash_value;
      //printf("\nhash_value = %d", hash_value);
      i++;
	}
      
    //printf("\nHash value: %d, i : %d, return %d", hash_value, i, hash_value % HASH_FUNCTION);
    return hash_value % HASH_FUNCTION;
}

