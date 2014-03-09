#include "../include/comp_dict.h"

int main (int argc, char **argv)
{
    comp_dict_t *dictionary = dictCreate();
    
    // Adding items :
    char *data;
    data = "integer";
    dictAddItem(dictionary, "int", data);
    data = "floating";
    dictAddItem(dictionary, "float", data);
    
    //Printing:
    printf("\nCreating the dictionary ...")
    dictPrint(dictionary);
    
    //Removing:
    dictRemoveItem(dictionary, "item");
    
    //Printing:
    printf("\nRemoving items from the dictionary ...")
    dictPrint(dictionary);
    
    //Editing:
    dictEditItem(dictionary, "float", "floated");
    
    //Printing:
    printf("\nEditing items from the dictionary ...")
    dictPrint(dictionary);
    
    //Empting:
    dictEmpty(dictionary);
    
    //Printing:
    printf("\nEmpting the dictionary ...")
    dictPrint(dictionary);
    
    return 0;
}
