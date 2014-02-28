#include <stdlib.h>
#include "comp_dict.h"

comp_dict_t* dictCreate(void){
	comp_dict_t *newDict;
	
	newDict = (comp_dict_t*)malloc(sizeof(comp_dict_t));
	
	return newDict;
}

