#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "comp_list.h"
#include "iloc.h"
#include "iks_ast.h"


const char* ilocCreateRegister()
{
    char buffer[1000];

    registersCount++;
    sprintf(buffer, "%s%d", "r",registersCount);

    return strdup(buffer);
}

const char * ilocCreateLabel()
{
    char buffer[1000];

    labelsCount++;
    sprintf(buffer, "%s%d", "L",labelsCount);

    return strdup(buffer);
}

const char * ilocCreateLiteral(comp_dict_item_t *symbol)
{
    char buffer[1000];
    switch(symbol->type){
                              case IKS_SIMBOLO_INDEFINIDO: 
                                   sprintf(buffer, " %s ", symbol->data.undefined_type);
                                   break; 
                              case IKS_SIMBOLO_LITERAL_INT:
                                   sprintf(buffer, " %d ", symbol->data.int_type);
                                   break;   
                              case IKS_SIMBOLO_LITERAL_FLOAT:
                                   sprintf(buffer, " %f ", symbol->data.float_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_CHAR:
                                   sprintf(buffer, " %c ", symbol->data.char_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_STRING:
                                   sprintf(buffer, " %s ", symbol->data.string_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_BOOL: 
                                   sprintf(buffer, " %d ", symbol->data.bool_type);
                                   break;;
                              case IKS_SIMBOLO_IDENTIFICADOR:
                                   sprintf(buffer, " %s ", symbol->data.identifier_type);
                                   break;
     } 

    return strdup(buffer);
}

void ilocPrintCode(comp_list_t* program)
{
	if(program != NULL)
	{
		comp_list_t* first = program;
		do
		{
			printf("%s\n", first->code);
			first = first->next;
		}
		while(first != program);
	}
}

comp_list_t* ilocCreateCode(comp_list_t* concatOnList, int commandId, int count, ...){
	va_list ap;
	int j;
	char* param[3];
	char commandCode[1000];
	if(count>0){
		va_start(ap, count);
		for(j=0; j<count; j++)
			param[j] = va_arg(ap, char*);
		va_end(ap);
	}
	switch(commandId){
		case ILOC_ADD:	sprintf(commandCode, "add %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_SUB:	sprintf(commandCode, "sub %s, %s => %s", param[0], param[1], param[2]);	break;

		case ILOC_MULT: sprintf(commandCode, "mult %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_DIV:	sprintf(commandCode, "div %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_ADD_I: sprintf(commandCode, "addI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_SUB_I: sprintf(commandCode, "subI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_R_SUB_I: sprintf(commandCode, "rsubI %s, %s => %s", param[0], param[1], param[2]); 	break;

		case ILOC_MULT_I: sprintf(commandCode, "multI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_DIV_I: sprintf(commandCode, "divI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_R_DIV_I: sprintf(commandCode, "rdivI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_LSHIFT: sprintf(commandCode, "lshift %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_LSHIFT_I: sprintf(commandCode, "lshiftI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_RSHIFT: sprintf(commandCode, "rshift %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_RSHIFT_I: sprintf(commandCode, "rshiftI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_AND: sprintf(commandCode, "and %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_AND_I: sprintf(commandCode, "andI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_OR: sprintf(commandCode, "or %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_OR_I: sprintf(commandCode, "orI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_XOR: sprintf(commandCode, "xor %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_XOR_I: sprintf(commandCode, "xorI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_LOAD: sprintf(commandCode, "load %s => %s", param[0], param[1]);break;

		case ILOC_LOAD_AI: sprintf(commandCode, "loadAI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_LOAD_AO: sprintf(commandCode, "loadAO %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_CLOAD: sprintf(commandCode, "cload %s => %s", param[0], param[1]);break;

		case ILOC_CLOAD_AI:	sprintf(commandCode, "cloadAI %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_CLOAD_AO: sprintf(commandCode, "cloadAO %s, %s => %s", param[0], param[1], param[2]);break;

		case ILOC_LOAD_I: sprintf(commandCode, "loadI %s => %s", param[0], param[1]);break;

		case ILOC_STORE: sprintf(commandCode, "store %s => %s", param[0], param[1]);break;

		case ILOC_STORE_AI:	sprintf(commandCode, "storeAI %s => %s, %s", param[0], param[1], param[2]);break;

		case ILOC_STORE_AO: sprintf(commandCode, "storeAO %s => %s, %s", param[0], param[1], param[2]);break;

		case ILOC_CSTORE: sprintf(commandCode, "cstore %s => %s", param[0], param[1]);break;

		case ILOC_CSTORE_AI: sprintf(commandCode, "cstoreAI %s => %s, %s", param[0], param[1], param[2]);break;

		case ILOC_CSTORE_AO: sprintf(commandCode, "cstoreAO %s => %s, %s", param[0], param[1], param[2]);break;

		case ILOC_I2I: sprintf(commandCode, "i2i %s => %s", param[0], param[1]);break;

		case ILOC_C2C: sprintf(commandCode, "c2c %s => %s", param[0], param[1]);break;

		case ILOC_C2I: sprintf(commandCode, "c2i %s => %s", param[0], param[1]);break;

		case ILOC_I2C: sprintf(commandCode, "i2c %s => %s", param[0], param[1]);break;

		case ILOC_CMP_LT: sprintf(commandCode, "cmp_LT %s, %s -> %s", param[0], param[1], param[2]);break;

		case ILOC_CMP_LE: sprintf(commandCode, "cmp_LE %s, %s -> %s", param[0], param[1], param[2]);break;

		case ILOC_CMP_EQ: sprintf(commandCode, "cmp_EQ %s, %s -> %s", param[0], param[1], param[2]);break;

		case ILOC_CMP_GE: sprintf(commandCode, "cmp_GE %s, %s -> %s", param[0], param[1], param[2]);break;

		case ILOC_CMP_GT: sprintf(commandCode, "cmp_GT %s, %s -> %s", param[0], param[1], param[2]);break;

		case ILOC_CMP_NE: sprintf(commandCode, "cmp_NE %s, %s -> %s", param[0], param[1], param[2]);break;

		case ILOC_CBR: sprintf(commandCode, "cbr %s -> %s, %s", param[0], param[1], param[2]);break;

		case ILOC_JUMP_I: sprintf(commandCode, "jumpI -> %s", param[0]);break;

		case ILOC_JUMP:	sprintf(commandCode, "jump -> %s", param[0]);break;

		case ILOC_NOP:	sprintf(commandCode, "nop");break;

		case ILOC_LABEL: sprintf(commandCode, "\n%s: ", param[0]);break;

	}
	comp_list_t* newCode = NULL; //= listAdd(commandCode, NULL);
	listPushCode(&newCode, commandCode);
	return listConcatenate(concatOnList, newCode);
}

comp_list_t* ilocAstCode(comp_tree_t* ast){
	if(ast==NULL)
		return NULL;
	comp_tree_t* aux = ast;
	comp_list_t* childCode = NULL;
	comp_list_t* broCode = NULL;
	comp_list_t* parentCode = NULL;
	const char* param;
	const char* label;
	const char* next;
	const char* next2;

	//inicializacao dos atributos herdados para os filhos
	switch(aux->type){
		case IKS_AST_IF_ELSE:{
			aux->labelTrue = ilocCreateLabel();
			aux->labelFalse = ilocCreateLabel();
			aux->children[0]->labelTrue = aux->labelTrue;
			aux->children[0]->labelFalse = aux->labelFalse;
		}
		case IKS_AST_LOGICO_E:{
			aux->children[0]->labelTrue = ilocCreateLabel();
			aux->children[0]->labelFalse = aux->labelFalse;
			if(aux->children[1] != NULL){
				aux->children[1]->labelTrue = aux->labelTrue;
				aux->children[1]->labelFalse = aux->labelFalse;
			}
		}
		case IKS_AST_LOGICO_OU:{
			aux->children[0]->labelFalse = ilocCreateLabel();
			aux->children[0]->labelTrue = aux->labelTrue;
			if(aux->children[1] != NULL){
				aux->children[1]->labelTrue = aux->labelTrue;
				aux->children[1]->labelFalse = aux->labelFalse;
			}
		}
	}
	
	int i;

	for(i=0; i<aux->nbChildren;i++)//processando todos os filhos
		childCode = ilocAstCode(aux->children[i]);

	//processando nodo atual
	switch(aux->type){//gera codigo para nodo atual
		case  IKS_AST_PROGRAMA: {
								//fprintf(stderr, "\nPrograma");
								//fprintf(stderr, "\nnbChildren: %d", aux->nbChildren);
								param = NULL;
								parentCode =  ilocCreateCode(parentCode, ILOC_LOAD_I, 2, "0", "fp"); //inicializa fp com zero
								parentCode =  ilocCreateCode(parentCode, ILOC_LOAD_I, 2, "0", "sp"); //inicializa sp com zero
								if(aux->children!= NULL)
									parentCode =  listConcatenate(parentCode, aux->children[0]->code); //concatena com o codigo do corpo da funcao
								listPrint(parentCode);
								//fprintf(stderr, "\nFim programa");
								break;
								}
		case IKS_AST_FUNCAO: {
								//fprintf(stderr, "\nFunction");
								param = NULL;
								parentCode =  ilocCreateCode(parentCode, ILOC_LABEL, 1, aux->symbol->data.identifier_type); //gera label com nome da funcao
								if(aux->children!= NULL)
									parentCode =  listConcatenate(parentCode, aux->children[0]->code); //concatena com o codigo do corpo da funcao
								listPrint(parentCode);
								//fprintf(stderr, "\nFim funcao");
								break;
								}
		case IKS_AST_RETURN: {
								fprintf(stderr, "\nReturn");
								param = ilocCreateRegister();
								parentCode =  listConcatenate(parentCode, aux->children[0]->code); //concatena com o codigo da expressao a ser retornada
								parentCode =  ilocCreateCode(parentCode, ILOC_I2I, 2, aux->children[0]->code->reg, "rt"); //carrega valor produzido pela expressao para o registrador de retorno de funcao
								parentCode =  ilocCreateCode(parentCode, ILOC_LOAD, 2, "fp", param); //carrega o endereco de retorno salvo no primeiro endereco do RA
								parentCode =  ilocCreateCode(parentCode, ILOC_I2I, 2, "fp", "sp"); //restaura o valor de sp para o valor antigo, marcado por fp
								parentCode =  ilocCreateCode(parentCode, ILOC_LOAD_AI, 3, "fp", "4", "fp"); //carrega o valor de fp antigo salvo no segundo endereco do RA
								parentCode =  ilocCreateCode(parentCode, ILOC_JUMP, 1, param);
								listPrint(parentCode);
								fprintf(stderr, "\nFim return");
								if(aux->nbChildren > 1)
											parentCode = listConcatenate(parentCode, aux->children[2]->code);
								break;
								}
		case IKS_AST_CHAMADA_DE_FUNCAO: {
								//fprintf(stderr, "\nCall");
								next = ilocCreateRegister();
								param = "rt";
								if(aux->children[1] != NULL)
									parentCode =  listConcatenate(parentCode, aux->children[1]->code); //concatena com o codigo das expressoes calculadas nos parametros da funcao
								parentCode =  ilocCreateCode(parentCode, ILOC_STORE_AI, 3, "fp", "sp", "4"); //salva o fp atual em sp+4
								parentCode =  ilocCreateCode(parentCode, ILOC_I2I, 2, "sp", "fp"); //substitui o antigo fp pelo sp
								int sp = 8;
								comp_tree_t* args = aux->children[0]->symbol->arguments; //lista de identificadores dos argumentos declarados para a funcao
								comp_tree_t* regList = NULL;
								if(aux->children[1] != NULL)
									regList = aux->children[1];
								while(args != NULL){ //para cada argumento declarado, salva o valor produzido na expressao
									if(args->children[0] != NULL)
									{
										sp += args->children[0]->symbol->offset; //a cada store incrementa o valor que sp vai assumir apos a insercao do registro de ativacao
										char offset[132];
										sprintf(offset, "%d", args->children[0]->symbol->offset);
										if(regList!=NULL){
											parentCode =  ilocCreateCode(parentCode, ILOC_STORE_AI, 3, regList->code->reg, "fp", offset); //reg: registrador que armazena o resultado da expressao
											//regList = regList->parent->child;
										}
										args = args->children[0];
									}
									else
										args = NULL;
								}
								sp += 10; //aloca espaco para "salvar o estado da maquina"
								char stack[32];
								sprintf(stack, "%d", sp);
								parentCode = ilocCreateCode(parentCode, ILOC_LOAD_I, 2, stack, "sp"); //aponta o final da pilha para depois do registro de ativacao
								parentCode = ilocCreateCode(parentCode, ILOC_I2I, 2, "PC", next); //salva o PC
								parentCode = ilocCreateCode(parentCode, ILOC_ADD_I, 3, next, "3", next); //soma 3
								parentCode = ilocCreateCode(parentCode, ILOC_STORE, 2, next, "fp"); //salva o endereco da proxima instrucao no registro de ativacao
								parentCode = ilocCreateCode(parentCode, ILOC_JUMP_I, 1, aux->children[0]->symbol->data.identifier_type); //salto para a funcao
								listPrint(parentCode);
								//fprintf(stderr, "\nFim call");
								break;								
								}
		case IKS_AST_IDENTIFICADOR: {
										fprintf(stderr, "\nIdentificador");
										if(aux->parent != NULL)
										{
											if(aux->parent->type != IKS_AST_ATRIBUICAO || (aux->parent->type == IKS_AST_ATRIBUICAO && aux->parent->children[0] != aux)){ //nao esta do lado esquerdo de uma atribuicao
												param = ilocCreateRegister();
												char offset[132];
												sprintf(offset, "%d", aux->symbol->offset);
												parentCode =  ilocCreateCode(parentCode, ILOC_LOAD_AI, 3, "bss", offset, param);		
											}
										}
										else
										{
											param = ilocCreateRegister();
											char offset[132];
											sprintf(offset, "%d", aux->symbol->offset);
											parentCode =  ilocCreateCode(parentCode, ILOC_LOAD_AI, 3, "bss", offset, param);		
										}
										listPrint(parentCode);							
										fprintf(stderr, "\nFim ID");
										break;
									}
		case IKS_AST_VETOR_INDEXADO:{
									fprintf(stderr, "\nVetor");
									parentCode =  listConcatenate(parentCode, aux->children[1]->code);
									if(aux->parent->type != IKS_AST_ATRIBUICAO || (aux->parent->type == IKS_AST_ATRIBUICAO && aux->parent->children[0] != aux)){ //nao esta do lado esquerdo de uma atribuicao
										param = ilocCreateRegister();
										if(aux->children[1]->type == IKS_AST_LITERAL){
											char offset[132];
											sprintf(offset, "%d", aux->children[0]->symbol->offset+(aux->children[1]->symbol->data.int_type*aux->children[0]->symbol->vectorTypeSize));//calculo do offset para vetor unidimensional
											parentCode =  ilocCreateCode(parentCode, ILOC_LOAD_AI, 3, "bss", offset, param);
										}
										else
										{
											char offset[132];
											sprintf(offset,"%d",aux->children[0]->symbol->offset);
											parentCode =  ilocCreateCode(parentCode, ILOC_ADD_I, 3, aux->children[1]->code->reg, offset, param);
											parentCode =  ilocCreateCode(parentCode, ILOC_LOAD_AO, 3, "bss", param, param);
										}
									}
									listPrint(parentCode);
									fprintf(stderr, "\nFim vetor");
									break;
									}

		case IKS_AST_ARIM_SOMA: 	{
										fprintf(stderr, "\nSoma");
										param = ilocCreateRegister();
										parentCode =  listConcatenate(parentCode, aux->children[0]->code);
										parentCode =  listConcatenate(parentCode, aux->children[1]->code);
										parentCode = ilocCreateCode(parentCode, ILOC_ADD, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
										listPrint(parentCode);
										fprintf(stderr, "\nFim soma");
										if(aux->nbChildren > 2)
											parentCode = listConcatenate(parentCode, aux->children[2]->code);
										break;
									}
		case IKS_AST_ARIM_SUBTRACAO: 	{
											fprintf(stderr, "\nSubtracao");
											param = ilocCreateRegister();
											parentCode =  listConcatenate(parentCode, aux->children[0]->code);
											parentCode =  listConcatenate(parentCode, aux->children[1]->code);
											parentCode = ilocCreateCode(parentCode, ILOC_SUB, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
											listPrint(parentCode);
											fprintf(stderr, "\nFim subtracao");
											if(aux->nbChildren > 2)
												parentCode = listConcatenate(parentCode, aux->children[2]->code);
											break;
										}
		case IKS_AST_ARIM_MULTIPLICACAO: {
											fprintf(stderr, "\nMultiplicacao");
											param = ilocCreateRegister();
											parentCode =  listConcatenate(parentCode, aux->children[0]->code);
											parentCode =  listConcatenate(parentCode, aux->children[1]->code);
											parentCode = ilocCreateCode(parentCode, ILOC_MULT, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
											listPrint(parentCode);
											if(aux->nbChildren > 2)
												parentCode = listConcatenate(parentCode, aux->children[2]->code);
											break;
										}
		case IKS_AST_ARIM_DIVISAO: {
										param = ilocCreateRegister();
										parentCode =  listConcatenate(parentCode, aux->children[0]->code);
										parentCode =  listConcatenate(parentCode, aux->children[1]->code);
										parentCode = ilocCreateCode(parentCode, ILOC_DIV, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
										if(aux->nbChildren > 2)
											parentCode = listConcatenate(parentCode, aux->children[2]->code);
										break;
									}
		case IKS_AST_ARIM_INVERSAO: break;
		case IKS_AST_LOGICO_E: {
									param = ilocCreateRegister();
									label = ilocCreateLabel();
									parentCode =  listConcatenate(parentCode, aux->children[0]->code);
									parentCode =  listConcatenate(parentCode, aux->children[1]->code);
									parentCode = ilocCreateCode(parentCode, ILOC_AND, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
									parentCode = ilocCreateCode(parentCode, ILOC_CBR, 3, param, label, aux->labelFalse);
									parentCode = ilocCreateCode(parentCode, ILOC_LABEL, 1,label);
									if(aux->nbChildren > 2)
											parentCode = listConcatenate(parentCode, aux->children[2]->code);
									break;
								}
		case IKS_AST_LOGICO_OU: {
									param = ilocCreateRegister();
									label = ilocCreateLabel();
									parentCode =  listConcatenate(parentCode, aux->children[0]->code);
									parentCode =  listConcatenate(parentCode, aux->children[1]->code);
									parentCode = ilocCreateCode(parentCode, ILOC_OR, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
									parentCode = ilocCreateCode(parentCode, ILOC_CBR, 3, param, aux->labelTrue, label);
									parentCode = ilocCreateCode(parentCode, ILOC_LABEL, 1,label);
									if(aux->nbChildren > 2)
											parentCode = listConcatenate(parentCode, aux->children[2]->code);
									break;
								}
		case IKS_AST_LOGICO_COMP_DIF: {
										param = ilocCreateRegister();
										parentCode =  listConcatenate(parentCode, aux->children[0]->code);
										parentCode =  listConcatenate(parentCode, aux->children[1]->code);
										parentCode = ilocCreateCode(parentCode, ILOC_CMP_NE, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
										if(aux->nbChildren > 2)
											parentCode = listConcatenate(parentCode, aux->children[2]->code);
										break;
									}
		case IKS_AST_LOGICO_COMP_IGUAL: {
										param = ilocCreateRegister();
										parentCode =  listConcatenate(parentCode, aux->children[0]->code);
										parentCode =  listConcatenate(parentCode, aux->children[1]->code);
										parentCode = ilocCreateCode(parentCode, ILOC_CMP_EQ, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
										if(aux->nbChildren > 2)
											parentCode = listConcatenate(parentCode, aux->children[2]->code);
										break;
									}
		case IKS_AST_LOGICO_COMP_LE: {
										param = ilocCreateRegister();
										parentCode =  listConcatenate(parentCode, aux->children[0]->code);
										parentCode =  listConcatenate(parentCode, aux->children[1]->code);
										parentCode = ilocCreateCode(parentCode, ILOC_CMP_LE, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
										if(aux->nbChildren > 2)
											parentCode = listConcatenate(parentCode, aux->children[2]->code);
										break;
									}
		case IKS_AST_LOGICO_COMP_GE: {
										param = ilocCreateRegister();
										parentCode =  listConcatenate(parentCode, aux->children[0]->code);
										parentCode =  listConcatenate(parentCode, aux->children[1]->code);
										parentCode = ilocCreateCode(parentCode, ILOC_CMP_GE, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
										if(aux->nbChildren > 2)
											parentCode = listConcatenate(parentCode, aux->children[2]->code);
										break;
									}
		case IKS_AST_LOGICO_COMP_L: {
										fprintf(stderr, "\nLess than");
										param = ilocCreateRegister();
										parentCode =  listConcatenate(parentCode, aux->children[0]->code);
										parentCode =  listConcatenate(parentCode, aux->children[1]->code);
										parentCode = ilocCreateCode(parentCode, ILOC_CMP_LT, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
										if(aux->nbChildren > 2)
											parentCode = listConcatenate(parentCode, aux->children[2]->code);	
										fprintf(stderr, "\nEnd less than");
										break;
									}
		case IKS_AST_LOGICO_COMP_G: {
										fprintf(stderr, "\nGreater");
										param = ilocCreateRegister();
										parentCode =  listConcatenate(parentCode, aux->children[0]->code);
										parentCode =  listConcatenate(parentCode, aux->children[1]->code);
										parentCode = ilocCreateCode(parentCode, ILOC_CMP_GT, 3, aux->children[0]->code->reg, aux->children[1]->code->reg, param);
										listPrint(parentCode);
										if(aux->nbChildren > 2)
											parentCode = listConcatenate(parentCode, aux->children[2]->code);
										fprintf(stderr, "\nFim greater");
										break;
									}
		case IKS_AST_IF_ELSE: {
								fprintf(stderr, "\nIF");
								label = ilocCreateLabel();
								parentCode =  listConcatenate(parentCode, aux->children[0]->code);
								parentCode =  ilocCreateCode(parentCode, ILOC_CBR, 3, aux->children[0]->code->reg, aux->children[0]->labelTrue, label);
								parentCode =  ilocCreateCode(parentCode, ILOC_LABEL, 1, aux->children[0]->labelTrue);
								parentCode =  listConcatenate(parentCode, aux->children[1]->code);
								parentCode =  ilocCreateCode(parentCode, ILOC_JUMP, 1, label);
								parentCode =  ilocCreateCode(parentCode, ILOC_LABEL, 1, aux->children[0]->labelFalse);
								if(aux->children[2]!= NULL){
									parentCode =  listConcatenate(parentCode, aux->children[2]->code);
								}
								parentCode =  ilocCreateCode(parentCode, ILOC_LABEL, 1, label);
								listPrint(parentCode);
								fprintf(stderr, "\nFim IF");
								break;
							}
		case IKS_AST_DO_WHILE: {
								label = ilocCreateLabel();
								next = ilocCreateLabel();
								parentCode =  ilocCreateCode(parentCode, ILOC_LABEL, 1, label);
								parentCode =  listConcatenate(parentCode, aux->children[0]->code);
								parentCode =  listConcatenate(parentCode, aux->children[1]->code);
								parentCode =  ilocCreateCode(parentCode, ILOC_CBR, 3, aux->children[1]->code->reg, label, next);
								parentCode =  ilocCreateCode(parentCode, ILOC_LABEL, 1, next);
								if(aux->nbChildren > 2)
										parentCode = listConcatenate(parentCode, aux->children[2]->code);
								break;
							}
		case IKS_AST_WHILE_DO: {
								fprintf(stderr, "\nWhile");
								label = ilocCreateLabel(); 	//before test expression
								next = ilocCreateLabel();	//enter while
								next2 = ilocCreateLabel();	//leave while
								parentCode =  ilocCreateCode(parentCode, ILOC_LABEL, 1, label);
								parentCode =  listConcatenate(parentCode, aux->children[0]->code);
								parentCode =  ilocCreateCode(parentCode, ILOC_CBR, 3, aux->children[0]->code->reg, next, next2);
								parentCode =  ilocCreateCode(parentCode, ILOC_LABEL, 1, next);
								parentCode =  listConcatenate(parentCode, aux->children[1]->code);
								parentCode =  ilocCreateCode(parentCode, ILOC_JUMP, 1, label);
								parentCode =  ilocCreateCode(parentCode, ILOC_LABEL, 1, next2);
								if(aux->nbChildren > 2)
										parentCode = listConcatenate(parentCode, aux->children[2]->code);
								fprintf(stderr, "\nEnd while");
								break;
							}
		case IKS_AST_ATRIBUICAO: {
									fprintf(stderr, "\nASSIGN");
									param = aux->children[1]->code->reg;
									parentCode = listConcatenate(parentCode, aux->children[1]->code);
									char offset[132];
									if(aux->children[0]->type == IKS_AST_VETOR_INDEXADO)
									{

										if(aux->children[0]->children[1]->type == IKS_AST_LITERAL)
										{									
											sprintf(offset, "%d", (aux->children[0]->children[0]->symbol->offset+(aux->children[0]->children[1]->symbol->data.int_type*aux->children[0]->children[0]->symbol->vectorTypeSize)));
											parentCode = ilocCreateCode(parentCode, ILOC_STORE_AO, 3, param, "bss", offset);
										}										
										else
										{
											if(aux->children[0]->children[1]->type == IKS_AST_ARIM_MULTIPLICACAO)
												fprintf(stderr, "\n>>>>>>>>>>>>>>>>MULTIPLICACAO: %s", aux->children[0]->code->reg);
											parentCode = listConcatenate(parentCode, aux->children[0]->children[1]->code);
											sprintf(offset,"%d",aux->children[0]->children[0]->symbol->offset);
											parentCode = ilocCreateCode(parentCode, ILOC_ADD_I, 3, aux->children[0]->children[1]->code->reg, offset, param);
											parentCode = ilocCreateCode(parentCode, ILOC_STORE_AO, 3, param, "bss", param);
										}
									}
									else
									{
										sprintf(offset, "%d", aux->children[0]->symbol->offset);
										parentCode = ilocCreateCode(parentCode, ILOC_STORE_AI, 3, aux->children[1]->code->reg, "bss", offset);
									}
									if(aux->nbChildren > 2)
										parentCode = listConcatenate(parentCode, aux->children[2]->code);
									listPrint(parentCode);
									fprintf(stderr, "\nFIM ASSIGN");
									break;
								}
		case IKS_AST_LITERAL:{
								fprintf(stderr, "\nLiteral ");
								treePrintElementData(aux->symbol);
								param = ilocCreateRegister();
								parentCode = ilocCreateCode(parentCode, ILOC_LOAD_I, 2, ilocCreateLiteral(aux->symbol), param);
								listPrint(parentCode);
								fprintf(stderr, "\nFim literal");
								break;
							}
	}

	/*if(aux->broList!=NULL){//percorre o irmao
		broCode = ilocAstCode(aux->broList);
		parentCode = listConcatenate(parentCode, broCode);
	}*/
	if(parentCode != NULL)
	{
		if(param != NULL)
			strcpy(parentCode->reg,param);
		ast->code = parentCode;
	}
	else 
		ast->code = childCode;

	if(ast->type == IKS_AST_ARIM_MULTIPLICACAO)
		fprintf(stderr, "\n----------------------REGISTROOOOOOO: %s", ast->code->reg);
											

	return ast->code;
}

