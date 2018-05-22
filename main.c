#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h> 

/*
Projeto de AED2 - Padaria Bom Apetite
Data: 01/05/2018
Contribuidores: 
-> Joel Carvalho nº12607
-> Fábio Gonçalves nº13025
-> Pedro Falcão nº13047
*/

typedef struct Aluno{
	int numero;
	char nome[45];
}Aluno;

typedef struct Alimentos{
	char nome[45];
	float preco;
	int stock;
	struct Alimentos *proximo;
} Alimentos;

typedef struct Cliente{
	char nome[45];
	int NIF;
	struct Cliente *proximo;
} Cliente;

/*typedef struct Alimentos_clientes{
	char nome_cliente[45];
	char nome_alimento[45];
	int quantidade;
	float preco;
	//hora de compra
	struct Alimentos_clientes *proximo;
} Alimentos_clientes;
*/
void inserirElementosArray(int array[], int numElementos) {
   int i;
   
   for (i = 0; i < numElementos; i++) {
       array[i] = i*2; 
   }
}

void inserirElementosEstrutura(Aluno aluno[], int numElementos) {
   int i;
   
   for (i = 0; i < numElementos; i++) {
       aluno[i].numero = i*2 - rand() % 10; 
       strcpy(aluno[i].nome, "A" + (rand() % 26));
   }
}

int compararQsortArray(const void *a, const void *b) { 
    return *(int*)a-*(int*)b; 
} 

int compararQsortEstrutura(const void *a, const void *b) { 
    struct Aluno *aa = (struct Aluno *)a;
	struct Aluno *ab = (struct Aluno *)b;
	
	return (aa->numero - ab->numero);
} 

void ordenarQsort(int numElementos, char* tipo){	
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

void ordenarPermutacao(int numElementos, char* tipo){   
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

Alimentos *alocarAlimento(){
	Alimentos *novo = (Alimentos *) malloc(sizeof(Alimentos));
	
	if(!novo){
		printf("Sem memoria disponivel!\n");
		return;
	}
	else {

		printf("Nome do alimento: ");
		gets(novo->nome);
		fflush(stdin);
		printf("Preço por unidade: ");
		scanf("%f", &novo->preco);
		fflush(stdin);
		printf("Qtd em stock: ");
		scanf("%d", &novo->stock);
		fflush(stdin);
		
		return novo;
	}
}

void InserirAlimentos(Alimentos *lista_alimentos){
	char optn[2];
	
	do{
		
		Alimentos *novo_alimento = alocarAlimento();
		novo_alimento->proximo = NULL;
		
		if(lista_alimentos->proximo == NULL)
		{
			lista_alimentos->proximo = novo_alimento;
		}
		else {
			Alimentos *aux = lista_alimentos->proximo;
			
			while(aux->proximo != NULL)
			{
				aux = aux->proximo;
			}
		
			aux->proximo = novo_alimento;
		}
		 
		 printf("\nDeseja inserir mais alimentos?\nS-SIM\nN-NÃO\n");
		 gets(optn);
	 
	} while(stricmp(optn, "N"));
}

void ListarAlimentos(Alimentos *lista_alimentos){
	printf("-------------------------------------------------\n");
	printf("|%-20s|%-15s|%-10s|\n", "NOME", "PREÇO(EURO)", "STOCK");
	printf("-------------------------------------------------\n");
	
	if(lista_alimentos->proximo == NULL){
		printf("|Sem alimentos disponíveis!\t\t\t|\n");
		printf("-------------------------------------------------\n");
		system("pause");
		return;
	}
	
	Alimentos *temp;
	temp = lista_alimentos->proximo; // Evitar guardar lixo
	
	while(temp != NULL){
		printf("|%-20.20s|%-2.2f\t     |%-3d\t|\n", temp->nome, temp->preco, temp->stock);
		temp = temp->proximo;
	}
	printf("-------------------------------------------------\n");
	system("pause");
}

void ProcurarAlimento(Alimentos *lista_alimentos){
	char alimentoProcurado[45];
	int encontrado = 0;
	
	printf("Nome do alimento a procurar: ");
	gets(alimentoProcurado);
	
	printf("-------------------------------------------------\n");
	printf("|%-20s|%-15s|%-10s|\n", "NOME", "PREÇO(EURO)", "STOCK");
	printf("-------------------------------------------------\n");
	
	if(lista_alimentos->proximo == NULL){
		printf("|Sem alimentos disponíveis!\t\t\t|\n");
		printf("-------------------------------------------------\n");
		system("pause");
		return;
	}
	
	Alimentos *temp = lista_alimentos->proximo; 
	
	while(temp != NULL && !encontrado){
		if(stricmp(alimentoProcurado, temp->nome) == 0){
			encontrado = 1;
			printf("|%-20.20s|%-2.2f\t     |%-3d\t|\n", temp->nome, temp->preco, temp->stock);
		}
		temp = temp->proximo;
	}
	
	if(!encontrado){
		printf("|Alimento não encontrado! Tente novamente!\t|\n");
	}
	printf("-------------------------------------------------\n");
	system("pause");
}

void RemoverAlimento(Alimentos *lista_alimentos){
	char alimentoRemover[45];
	int removido = 0;
	Alimentos *anterior;
	
	printf("Nome do alimento a remover: ");
	gets(alimentoRemover);
	
	printf("-------------------------------------------------\n");
	printf("|%-20s|%-15s|%-10s|\n", "NOME", "PREÇO(EURO)", "STOCK");
	printf("-------------------------------------------------\n");
	
	if(lista_alimentos->proximo == NULL){
		printf("|Sem alimentos disponíveis!\t\t\t|\n");
		printf("-------------------------------------------------\n");
		system("pause");
		return;
	}
	
	Alimentos *temp = lista_alimentos->proximo; 
	
	// Se for o primeiro elemento da lista
	if(temp != NULL && stricmp(alimentoRemover, temp->nome) == 0){
		printf("|ALIMENTO REMOVIDO COM SUCESSO!\t\t\t|\n");
		printf("|%-20.20s|%-2.2f\t     |%-3d\t|\n", temp->nome, temp->preco, temp->stock);
		printf("-------------------------------------------------\n");
		lista_alimentos->proximo = temp->proximo;
		free(temp);
		system("pause");
		return;
	}
	
	// Se for o segundo ou mais elemento da lista
	while(temp != NULL && !removido){
		if(stricmp(alimentoRemover, temp->nome) == 0){
			removido = 1;
			printf("|ALIMENTO REMOVIDO COM SUCESSO!\t\t\t|\n");
			printf("|%-20.20s|%-2.2f\t     |%-3d\t|\n", temp->nome, temp->preco, temp->stock);
			printf("-------------------------------------------------\n");
			system("pause");
			break;
		}
		anterior = temp;
		temp = temp->proximo;
	}
	
	// Se encontrou o elemento a eliminar
	if(temp != NULL){
		free(temp);	
		// Unir a lista
		anterior->proximo = temp->proximo;
	}
	
	if(!removido){
		printf("|Alimento não encontrado! Tente novamente!\t|\n");
	}
	printf("-------------------------------------------------\n");
	system("pause");
}

Cliente *alocarCliente(){
	Cliente *novo = (Cliente*)malloc(sizeof(Cliente));

	if (!novo) {
		printf("Sem memoria disponivel!\n");
		return;
	}
	else {

		printf("Nome do Cliente: ");
		gets(novo->nome);
		fflush(stdin);
		printf("NIF do Cliente: ");
		scanf("%d", &novo->NIF);
		fflush(stdin);

		return novo;
	}
}

void InserirClientes(Cliente *lista_clientes){
	char optn[1];

	do {

		Cliente *novo_cliente = alocarCliente();
		novo_cliente->proximo = NULL;

		if (lista_clientes->proximo == NULL)
		{
			lista_clientes->proximo = novo_cliente;
		}
		else {
			Cliente *aux = lista_clientes->proximo;

			while (aux->proximo != NULL)
			{
				aux = aux->proximo;
			}

			aux->proximo = novo_cliente;
		}

		printf("\nDeseja inserir mais Clientes?\nS-SIM\nN-NÃO\n");
		gets(optn);

	} while (stricmp(optn, "N"));
}

ListarClientes(Cliente *lista_clientes){
	printf("-------------------------------------------------\n");
	printf("|NOME||NIF|");
	printf("-------------------------------------------------\n");
	
	if(lista_clientes->proximo == NULL){
		printf("|Sem alimentos disponíveis!\t\t\t|\n");
		printf("-------------------------------------------------\n");
		system("pause");
		return;
	}
	
	Cliente *temp;
	temp = lista_clientes->proximo; // Evitar guardar lixo
	
	while(temp != NULL){
		printf("|%s|%d\t|\n", temp->nome, temp->NIF);
		temp = temp->proximo;
	}
	printf("-------------------------------------------------\n");
	system("pause");
}

void ProcurarCliente(Cliente *lista_clientes){
	int clienteProcurado;
	int encontrado = 0;
	
	printf("NIF do Cliente a procurar: ");
	scanf("%d", &clienteProcurado);
	
	printf("-------------------------------------------------\n");
	printf("|%-20s|%-15s|%-10s|\n", "NOME", "NIF");
	printf("-------------------------------------------------\n");
	
	if(lista_clientes->proximo == NULL){
		printf("|Sem clientes disponíveis!\t\t\t|\n");
		printf("-------------------------------------------------\n");
		system("pause");
		return;
	}
	
	Cliente *temp = lista_clientes->proximo; 
	
	while(temp != NULL && !encontrado){
		if(clienteProcurado == temp->NIF){
			encontrado = 1;
			printf("|%s  |%d|\n", temp->nome, temp->NIF);
		}
		temp = temp->proximo;
	}
	
	if(!encontrado){
		printf("|Alimento não encontrado! Tente novamente!\t|\n");
	}
	printf("-------------------------------------------------\n");
	system("pause");
}
/*
void RemoverCliente(Cliente *lista_clientes){
	int clienteRemover;
	int removido = 0;
	Alimentos *anterior;
	
	printf("NIF do cliente a remover: ");
	scanf("%d", &clienteRemover);
	
	printf("-------------------------------------------------\n");
	printf("|%-20s|%-15s|%-10s|\n", "NOME", "NIF");
	printf("-------------------------------------------------\n");
	
	if(lista_clientes->proximo == NULL){
		printf("|Sem clientes disponíveis!\t\t\t|\n");
		printf("-------------------------------------------------\n");
		system("pause");
		return;
	}
	
	Cliente *temp = lista_clientes->proximo; 
	
	// Se for o primeiro elemento da lista
	if(temp != NULL && temp->NIF == clienteRemover){
		printf("|CLIENTE REMOVIDO COM SUCESSO!\t\t\t|\n");
		printf("|%-20.20s|%d\t|\n", temp->nome, temp->NIF);
		printf("-------------------------------------------------\n");
		lista_clientes->proximo = temp->proximo;
		free(temp);
		system("pause");
		return;
	}
	
	// Se for o segundo ou mais elemento da lista
	while(temp != NULL && !removido){
		if(stricmp(alimentoRemover, temp->nome) == 0){
			removido = 1;
			printf("|ALIMENTO REMOVIDO COM SUCESSO!\t\t\t|\n");
			printf("|%-20.20s|%-2.2f\t     |%-3d\t|\n", temp->nome, temp->preco, temp->stock);
			printf("-------------------------------------------------\n");
			system("pause");
			break;
		}
		anterior = temp;
		temp = temp->proximo;
	}
	
	// Se encontrou o elemento a eliminar
	if(temp != NULL){
		free(temp);	
		// Unir a lista
		anterior->proximo = temp->proximo;
	}
	
	if(!removido){
		printf("|Alimento não encontrado! Tente novamente!\t|\n");
	}
	printf("-------------------------------------------------\n");
	system("pause");
}
*/
void menuPadaria(Alimentos *lista_alimentos, Cliente *lista_clientes){
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
	printf("\t7- Próximo Cliente\n");
	printf("\t8- Remover Alimento\n");
	printf("\tSelecione qualquer tecla para voltar ao menu anterior\n");
	puts("");
	printf("Escolha o menu que pretende visualizar: ");
	scanf("%d", &opc);
	fflush(stdin);
	
	switch(opc){
		case 1:
			InserirClientes(lista_clientes);
			break;
		case 2:
			InserirAlimentos(lista_alimentos);
			break;	
		case 3:
			ListarClientes(lista_clientes);
			break;
		case 4:
			ListarAlimentos(lista_alimentos);
			break;
		case 5:
			ProcurarCliente(lista_clientes);
			break;
		case 6:
			ProcurarAlimento(lista_alimentos);
			break;
		case 7:
			//ProximoCliente();
			break;	
		case 8:
			RemoverAlimento(lista_alimentos);
			break;					
		default: printf("Opção inválida");
 }
}

void main() {

	// Inicializar a lista
	Alimentos *lista_alimentos = (Alimentos*) malloc(sizeof(Alimentos));
	lista_alimentos->proximo = NULL;
	Cliente *lista_clientes = (Cliente*)malloc(sizeof(Cliente));
	lista_clientes->proximo = NULL;
	int opc;
	
	setlocale(LC_ALL, "Portuguese");
	
	do {
		opc = menuGeral();
		
		if (opc == 1) 
			menuEstudos();
		else if (opc == 2)
			menuPadaria(lista_alimentos, lista_clientes);
			
	} while(opc != 0);
	
	system("cls");
	printf("Volte sempre!!");
}

