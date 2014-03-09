#include "comp_dict.c"

int main ()
{
    comp_dict_t *dictionary = dictCreate();
 
    int option = 1;
    while(option)
    {             
                 system("cls");
                 printf("\n\n--------------------------------------");
                 printf("\n                 MENU");    
                 printf("\n--------------------------------------");
                 printf("\n[0] : EXIT");
                 printf("\n[1] : ADD ITEMS");
                 printf("\n[2] : REMOVE ITEMS");
                 printf("\n[3] : EDIT ITEMS");
                 printf("\n[4] : PRINT DICTIONARY");
                 printf("\n[5] : DELETE DICTIONARY");
                 printf("\nPlease enter the option: ");
                 scanf("%d", &option);
                 
                 switch(option)
                 {
                  case 0:
                       break;
                  case 1:
                       system("cls");
                       char key[10];
                       int value;
                       printf("\n\n--------------------------------------");
                       printf("\n            ADD ITEMS");    
                       printf("\n--------------------------------------");
                       printf("\nKey? (string) ");
                       scanf("%s", key);
                       printf("\nValue? (integer) ");
                       scanf("%d", &value);
                       dictAddItem(dictionary, key, value);
                       getch();
                       break; 
                  case 2:
                       system("cls");
                       printf("\n\n--------------------------------------");
                       printf("\n            REMOVE ITEMS");    
                       printf("\n--------------------------------------");
                       printf("\nKey? (string) ");
                       scanf("%s", key);
                       dictRemoveItem(dictionary, key);
                       getch();
                       break; 
                  case 3:
                       system("cls");
                       printf("\n\n--------------------------------------");
                       printf("\n            EDIT ITEMS");    
                       printf("\n--------------------------------------");
                       printf("\nKey? (string) ");
                       scanf("%s", key);
                       printf("\nNew value? (integer) ");
                       scanf("%d", &value);
                       dictEditItem(dictionary, key, value);
                       printf("\nThe item was edited!"); 
                       getch();
                       break;
                  case 4:
                       system("cls");
                       printf("\n\n--------------------------------------");
                       printf("\n            PRINT DICTIONARY");    
                       printf("\n--------------------------------------");
                       dictPrint(dictionary);
                       getch();
                       break;
                  case 5:    
                       dictEmpty(dictionary);
                       printf("\nDictionary was emptied!");
                       getch();
                       break;
                  default:
                          printf("\nInvalid option! Please enter numbers from 0 to 5.");
                          getch();
                       
                  }
    }
    // Adding items :
    int data;
    data = 100;
    dictAddItem(dictionary, "int", data);
    data = 200;
    dictAddItem(dictionary, "float", data);
    
    //Printing:
    printf("\n\n--------------------------------------");
    printf("\nCreating the dictionary ...");    
    printf("\n--------------------------------------");
    dictPrint(dictionary);
    
    //Removing:
    dictRemoveItem(dictionary, "int");
    
    //Printing:
    printf("\n\n--------------------------------------");
    printf("\nRemoving items from the dictionary ...");
    printf("\n--------------------------------------");
    dictPrint(dictionary);
    
    //Editing:
    dictEditItem(dictionary, "float", 300);
    
    //Printing:
    printf("\n\n--------------------------------------");
    printf("\nEditing items from the dictionary ...");
    printf("\n--------------------------------------");
    dictPrint(dictionary);
    
    //Empting:
    dictEmpty(dictionary);
    
    //Printing:
    printf("\n\n--------------------------------------");
    printf("\nEmpting the dictionary ...");
    printf("\n--------------------------------------");
    dictPrint(dictionary);
    
    getch();
    return 0;
}
