#include "comp_tree.h"

int main ()
{
    comp_tree_t *tree = treeCreateNode(0, NULL);
 
    int option = 1;
    while(option)
    {             
                 system("cls");
                 printf("\n\n--------------------------------------");
                 printf("\n              MENU : TREE");    
                 printf("\n--------------------------------------");
                 printf("\n[0] : EXIT");
                 printf("\n[1] : APPEND NODE");
                 printf("\n[2] : INSERT NODE");
                 printf("\n[3] : REMOVE NODE");
                 printf("\n[4] : EDIT NODE");
                 printf("\n[5] : PRINT TREE");
                 printf("\n[6] : DELETE TREE");
                 printf("\nPlease enter the option: ");
                 scanf("%d", &option);
                 
                 switch(option)
                 {
                  case 0:
                       break;
                  case 1:
                       system("cls");
                       int data;
                       printf("\n\n--------------------------------------");
                       printf("\n            APPEND NODE");    
                       printf("\n--------------------------------------");
                       printf("\nNode data? (int) ");
                       scanf("%d", &data);
                       treeAppendNode(tree, createIntData(data));
                       getch();
                       break; 
                  case 2:
                       system("cls");
                       int insert_data, idx;
                       printf("\n\n--------------------------------------");
                       printf("\n            INSERT NODE");    
                       printf("\n--------------------------------------");
                       printf("\nNode data? (int) ");
                       scanf("%d", &insert_data);
                       printf("\nNode index? (int) ");
                       scanf("%d", &idx);
                       treeInsertNode(tree, idx, createIntData(insert_data)); 
                       getch();
                       break; 
                  case 3:
                       system("cls");
                       int remove_idx;
                       printf("\n\n--------------------------------------");
                       printf("\n            REMOVE NODE");    
                       printf("\n--------------------------------------");
                       printf("\nNode index? (int) ");
                       scanf("%d", &remove_idx);
                       treeDeleteNode(tree, remove_idx); 
                       printf("NOTE: Node was removed!");
                       getch();
                       break;
                  case 4:
                       system("cls");
                       int edit_data, edit_idx;
                       printf("\n\n--------------------------------------");
                       printf("\n            EDIT NODE");    
                       printf("\n--------------------------------------");
                       printf("\nNode new data? (int) ");
                       scanf("%d", &edit_data);
                       printf("\nNode index? (int) ");
                       scanf("%d", &edit_idx);
                       treeEditNode(tree, edit_idx, createIntData(edit_data)); 
                       printf("NOTE: Node was edited!");
                       getch();
                       break;
                  case 5:    
                       system("cls");
                       printf("\n\n--------------------------------------");
                       printf("\n            PRINT TREE");    
                       printf("\n--------------------------------------");
                       treePrint(tree); 
                       getch();
                       break;
                  case 6:
                       system("cls");
                       printf("\n\n--------------------------------------");
                       printf("\n            DELETE TREE");    
                       printf("\n--------------------------------------");
                       treeFree(tree); 
                       printf("NOTE: Tree was deleted!");
                       getch();
                       break;
                  default:
                          printf("\nInvalid option! Please enter numbers from 0 to 5.");
                          getch();
                       
                  }
    }
    return 0;
}
