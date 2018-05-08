#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h> 

/*
Projeto de AED2 - Padaria Bom Apetite
Data: 01/05/2018 aaaa
Contribuidores: 
-> Joel Carvalho nº12607
-> Fábio Gonçalves nº13025
-> Pedro Falcão nº13047
*/

typedef struct Aluno{
	int numero;
	char nome[45];
}Aluno;

void inserirElementosArray(int array[], int numElementos) 
{
   int i;
   
   for (i = 0; i < numElementos; i++) {
       array[i] = i*2; 
   }
}

void inserirElementosEstrutura(Aluno aluno[], int numElementos) 
{
   int i;
   
   for (i = 0; i < numElementos; i++) {
       aluno[i].numero = i*2 - rand() % 10; 
       strcpy(aluno[i].nome, "A" + (rand() % 26));
   }
}

int compararQsortArray(const void *a, const void *b) 
{ 
    return *(int*)a-*(int*)b; 
} 

int compararQsortEstrutura(const void *a, const void *b) 
{ 
    struct Aluno *aa = (struct Aluno *)a;
	struct Aluno *ab = (struct Aluno *)b;
	
	return (aa->numero - ab->numero);
} 

void ordenarQsort(int numElementos, char* tipo)
{	
	int array[numElementos];
	float inicioTempo, fimTempo, tempo;
	Aluno alunos[numElementos];
			
	if(stricmp(tipo, "array") == 0){
		inserirElementosArray(array, numElementos);
		inicioTempo = clock();
	    qsort(array, numElementos, sizeof(int), compararQsortArray);
	}
	else if(stricmp(tipo, "estrutura") == 0) {
		inserirElementosEstrutura(alunos, numElementos);
		inicioTempo = clock();
	    qsort(alunos, numElementos, sizeof(struct Aluno), compararQsortEstrutura);
	}
    
    fimTempo = clock();
  	tempo = (fimTempo-inicioTempo) / CLOCKS_PER_SEC; 
	printf("----------------------------------------\n");
	printf("|%-20s|%-15s|\n", "TIPO DE ORDENAÇÃO", "TEMPO GASTO(segs)");
	printf("----------------------------------------\n");
	printf("|%-20.20s|%-3.5f          |\n", "Qsort", tempo);
}

void ordenarPermutacao(int numElementos, char* tipo)
{   
	int i, j;
	int array[numElementos];
	float inicioTempo, fimTempo, tempo;
	Aluno alunos[numElementos];
	
	if(stricmp(tipo, "array") == 0){
		int auxiliar;
		inserirElementosArray(array, numElementos);
		inicioTempo = clock();
		
		for (i = 1; i < numElementos; i++)  {
	        for (j = i+1; j <= numElementos; j++)  {
	            if (array[i] > array[j]) {
	               auxiliar = array[i]; 
				   array[i] = array[j]; 
				   array[j] = auxiliar;
	            }
	        }
		}
	}
	else if(stricmp(tipo, "estrutura") == 0) {
		Aluno auxiliar;
		inserirElementosEstrutura(alunos, numElementos);
		inicioTempo = clock();
		
		for (i = 1; i < numElementos; i++)  {
	        for (j = i+1; j <= numElementos; j++)  {
	            if (alunos[i].numero > alunos[j].numero) {
	               auxiliar = alunos[i]; 
				   alunos[i] = alunos[j]; 
				   alunos[j] = auxiliar;
	            }
	        }
		}
	}
	
	fimTempo = clock(); 
	tempo = (fimTempo-inicioTempo) / CLOCKS_PER_SEC; 
	printf("|%-20.20s|%-3.5f          |\n", "Permutação", tempo);
	printf("----------------------------------------\n");
}

void ordenaArray(){
	int numElementos;
	
	printf("Número que elementos do array[>=3000]");
	scanf("%d", &numElementos);
		
	while(numElementos < 3000) {
		printf("Número que elementos do array[>=3000]");
		scanf("%d", &numElementos);
	} 
	
	ordenarQsort(numElementos, "array");
	ordenarPermutacao(numElementos, "array");
	system("pause");
}

void ordenaEstrutura(){
	int numElementos;
	
	printf("Número que elementos da estrutura[>=3000]");
	scanf("%d", &numElementos);
		
	while(numElementos < 3000) {
		printf("Número que elementos da estrutura[>=3000]");
		scanf("%d", &numElementos);
	} 
	
	ordenarQsort(numElementos, "estrutura");
	ordenarPermutacao(numElementos, "estrutura");
	system("pause");
}

void procuraBinaria(int numElementos, char* tipo, int procurado){
	int array[numElementos];
	float inicioTempo, fimTempo, tempo;
	Aluno alunos[numElementos];
	int encontrado = 0, minimo = 0, maximo = numElementos - 1, j, meio;
	int ajuda;
	
	if(stricmp(tipo, "array") == 0){
		inserirElementosArray(array, numElementos);
		
		inicioTempo = clock();
		encontrado = 0;
		
		while((maximo >= minimo) && (encontrado == 0 ))
		{ 
			meio = (maximo + minimo) / 2;
			if (array[meio] == procurado) 
			{
				encontrado = 1;
			}
			else 	
			{
		 		if (array[meio] > procurado) 		
			 	{
			 		maximo = meio - 1;
				}
				else 
				{
				 	minimo = meio + 1; 
				}
			}
		}
		ajuda = (encontrado == 0 ? -1 : array[meio]);
	}
    
    fimTempo = clock();
  	tempo = (fimTempo-inicioTempo) / CLOCKS_PER_SEC; 
	printf("-----------------------------------------------------\n");
	printf("|%-20s|%-15s|%-10s|\n", "TIPO DE PROCURA", "TEMPO GASTO(segs)", "Encontrado? ");
	printf("-----------------------------------------------------\n");
	printf("|%-20.20s|%-3.5f          |Posição:%-3d|\n", "Binária", tempo, ajuda);
}

void procuraLinear(int numElementos, char* tipo, int procurado){
	
	int array[numElementos], i, encontrado, ajuda, c;
	float inicioTempo, fimTempo, tempo;
	Aluno alunos[numElementos];
	
	if(stricmp(tipo, "array") == 0){
		inserirElementosArray(array, numElementos);
		
		inicioTempo = clock();
		encontrado = 0;

	    for(i = 0; i < numElementos; i++){
	     	if(array[i] == procurado){
     			ajuda = i+1;
     		 	break;
			}
		    else{
		 		c++;
		 		ajuda = -1;
			}
	 	}
	}
    
    fimTempo = clock();
  	tempo = (fimTempo-inicioTempo) / CLOCKS_PER_SEC; 
	printf("|%-20.20s|%-3.5f          |Posição:%-3d|\n", "Linear", tempo, ajuda);
	printf("-----------------------------------------------------\n");
}

void procuraArrays(){
	int numElementos, procurado, array[numElementos];
	
	printf("Número que elementos da estrutura[>=3000]");
	scanf("%d", &numElementos);
		
	while(numElementos < 3000) {
		printf("Número que elementos da estrutura[>=3000]");
		scanf("%d", &numElementos);
	} 
	
	printf("Qual o número que pretende encontrar? ");
	scanf("%d", &procurado);
	
	procuraBinaria(numElementos, "array", procurado);
	procuraLinear(numElementos, "array", procurado);
	
	system("pause");
}

int menuGeral(){
	int opc;
	
	system("cls");
	printf("\n\n\t\|---------------MENU PRINCIPAL---------------|\n"); 
	puts("\t\|\t\t\t\t\t     |");
	printf("\t|1- Realizar estudos\t\t\t     |\n");
	printf("\t|2- Padaria/Pastelaria Bom Apetite\t     |\n");
	printf("\t|0- Sair\t\t\t\t     |\n");
	puts("\t|\--------------------------------------------|");
	printf("\nEscolha o menu que pretende visualizar: ");
	scanf("%d", &opc);
	fflush(stdin);
	
	return opc;
}

void menuEstudos(){
	int opc;
	
	system("cls");
	printf("\n\n\t|---------------MENU ESTUDOS---------------|\n");
	puts("\t\|\t\t\t\t\t   |");
	printf("\t|1- Testar tempos de ordenação arrays\t   |\n");
	printf("\t|2- Testar tempos de ordenação estruturas  |\n");
	printf("\t|3- Testar tempos de procura arrays\t   |\n");
	printf("\t|-> ((Prima qualquer tecla para voltar)) <-|\n");
	puts("\t|\------------------------------------------|");
	printf("\nEscolha o menu que pretende visualizar: ");
	scanf("%d", &opc);
	fflush(stdin);
	
	switch(opc){
		case 1:
			ordenaArray();
			break;
		case 2:
			ordenaEstrutura();
			break;	
		case 3:
			procuraArrays();
			break;	
		
		default:	
			printf("Opcao invalida! Tente novamente.\n");
	}
}

void menuPadaria(){
	int opc;
	
	system("cls");
	printf("\t\tPadaria/Pastelaria Bom Apetite \n");
	puts("");
	printf("\t1- Inserir Cliente\n");
	printf("\t2- Inserir Alimento\n");
	printf("\t3- Listar Clientes\n");
	printf("\t4- Listar Alimentos\n");
	printf("\t5- Procurar Cliente\n");
	printf("\t6- Procurar Alimento\n");
	printf("\t7- Remover Cliente\n");
	printf("\t8- Remover Alimento\n");
	printf("\tSelecione qualquer tecla para voltar ao menu anterior\n");
	puts("");
	printf("Escolha o menu que pretende visualizar: ");
	scanf("%d", &opc);
	fflush(stdin);
	
	/*switch(opc){
		case 1:
			break;	
		case 2:
			break;	
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;	
		case 8:
			break;					
		default:	
	}*/
}

void main() {
	int opc;
	setlocale(LC_ALL, "Portuguese");
	
	do {
		opc = menuGeral();
		
		if (opc == 1) 
			menuEstudos();
		else if (opc == 2)
			menuPadaria();
			
	} while(opc != 0);
	
	system("cls");
	printf("Volte sempre!!");
}
