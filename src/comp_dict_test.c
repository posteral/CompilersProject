#include "../include/comp_dict.h"

int main (int argc, char **argv)
{
    comp_dict_t *dictionary = dictCreate();
    
    // Adding items :
    int data;
    data = 100;
    dictAddItem(dictionary, "int", data);
    data = 200;
    dictAddItem(dictionary, "float", data);
    
    //Printing:
    printf("\nCreating the dictionary ...");
    dictPrint(dictionary);
    
    //Removing:
    dictRemoveItem(dictionary, "int");
    
    //Printing:
    printf("\nRemoving items from the dictionary ...");
    dictPrint(dictionary);
    
    //Editing:
    dictEditItem(dictionary, "float", 300);
    
    //Printing:
    printf("\nEditing items from the dictionary ...");
    dictPrint(dictionary);
    
    //Empting:
    dictEmpty(dictionary);
    
    //Printing:
    printf("\nEmpting the dictionary ...");
    dictPrint(dictionary);
    
    return 0;
}
