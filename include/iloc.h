/**
 * Definicao das estruturas necessarias para a geracao de codigo ILOC para a linguagem IKS
 * */

#include "comp_list.h"
#include "comp_tree.h"
#ifndef ILOC_H
#define ILOC_H

#define ILOC_NOP		0
#define ILOC_ADD 		1
#define ILOC_SUB 		2
#define ILOC_MULT 		3
#define ILOC_DIV 		4
#define ILOC_ADD_I 		5
#define ILOC_SUB_I 		6
#define ILOC_R_SUB_I 	7
#define ILOC_MULT_I 	8
#define ILOC_DIV_I 		9
#define ILOC_R_DIV_I 	10
#define ILOC_LSHIFT 	11
#define ILOC_LSHIFT_I 	12
#define ILOC_RSHIFT 	13
#define ILOC_RSHIFT_I 	14
#define ILOC_LOAD 		15
#define ILOC_LOAD_AI	16
#define ILOC_LOAD_AO	17
#define ILOC_CLOAD		18
#define ILOC_CLOAD_AI	19
#define ILOC_CLOAD_AO	20
#define ILOC_LOAD_I		21
#define ILOC_STORE		22
#define ILOC_STORE_AI	23
#define ILOC_STORE_AO	24
#define ILOC_CSTORE		25
#define ILOC_CSTORE_AI	26
#define ILOC_CSTORE_AO	27
#define ILOC_I2I		28
#define ILOC_C2C		29
#define ILOC_C2I		30
#define ILOC_I2C		31
#define ILOC_CMP_LT		32
#define ILOC_CMP_LE		33
#define ILOC_CMP_EQ		34
#define ILOC_CMP_GE		35
#define ILOC_CMP_GT		36
#define ILOC_CMP_NE		37
#define ILOC_CBR		38
#define ILOC_JUMP_I		39
#define ILOC_JUMP		40
#define ILOC_AND		41
#define ILOC_AND_I		42
#define ILOC_OR			43
#define ILOC_OR_I		44
#define ILOC_XOR		45
#define ILOC_XOR_I		46
#define ILOC_LABEL		47

int registersCount;
int labelsCount;
int offsetGlobal;
comp_list_t* ilocCreateCode(comp_list_t* concatOnList, int commandId, int count, ...); //dependendo do comando se passa um numero diferente de argumentos
																				//, passando a quantidade em count, os parametros consistem de strings
																				// de registradores, variaveis, ou literais

comp_list_t* ilocAstCode(comp_tree_t* ast);//cria o codigo ILOC para uma arvore AST de um programa

const char* ilocCreateRegister();
const char* ilocCreateLabel();
const char* ilocCreateLiteral(comp_dict_item_t *symbol);
int 		ilocComputeArrayOffset(int* dim1, int* dim2, int dims);
#endif
