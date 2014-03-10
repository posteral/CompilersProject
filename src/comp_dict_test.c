#include "comp_dict.h"

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
                 printf("\n[6] : >>> RUN DEFAULT EXEMPLE <<<");
                 printf("\nPlease enter the option: ");
                 scanf("%d", &option);
                 
                 switch(option)
                 {
                  case 0:
                       break;
                  case 1:
                       system("cls");
                       char *key = malloc(sizeof(char) * 100);;
                       int value;
                       printf("\n\n--------------------------------------");
                       printf("\n            ADD ITEMS");    
                       printf("\n--------------------------------------");
                       printf("\nKey? (string) ");
                       scanf("%s", key);
                       printf("\nValue? (integer) ");
                       scanf("%d", &value);
                       dictAddItem(&dictionary, key, value);
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
                       printf("\nThe item was removed!");
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
                       //dictEmpty(dictionary);
                       printf("\nDictionary was emptied!");
                       getch();
                       break;
                  case 6:
                       system("cls");
                       printf("\n\n--------------------------------------");
                       printf("\n            ADD ITEMS 'int' AND 'float'");    
                       printf("\n--------------------------------------\n");
                       dictAddItem(&dictionary, "int", 1);
                       dictAddItem(&dictionary, "float", 2);
                       dictPrint(dictionary);
                       printf("\n\n--------------------------------------");
                       printf("\n            EDIT ITEM 'int'");    
                       printf("\n--------------------------------------\n");
                       dictEditItem(dictionary, "int", 0);
                       dictPrint(dictionary);
                       printf("\n\n--------------------------------------");
                       printf("\n            REMOVE ITEM 'int'");    
                       printf("\n--------------------------------------\n");
                       dictRemoveItem(dictionary, "int");
                       dictPrint(dictionary);
                       getch();
                       break;                       
                  default:
                          printf("\nInvalid option! Please enter numbers from 0 to 5.");
                          getch();
                       
                  }
    }
    
    return 0;
}
