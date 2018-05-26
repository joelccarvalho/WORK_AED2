#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h> 

/*
Projeto de AED2 - Pastelaria/Padaria Bom Apetite
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

// Assinaturas
void inserirElementosArray(int array[], int numElementos);
void inserirElementosEstrutura(Aluno aluno[], int numElementos);
int compararQsortArray(const void *a, const void *b);
int compararQsortEstrutura(const void *a, const void *b);
void ordenarQsort(int numElementos, char* tipo);
void ordenarPermutacao(int numElementos, char* tipo);
void ordenaArray();
void ordenaEstrutura();
void procuraBinaria(int numElementos, char* tipo, int procurado);
void procuraLinear(int numElementos, char* tipo, int procurado);
void procuraArrays();
int menuGeral();
void menuEstudos();
void menuPadaria(Alimentos *lista_alimentos, Cliente *lista_clientes);
Alimentos *alocarAlimento();
void inserirAlimentos(Alimentos *lista_alimentos);
char *randomPalavra();
Alimentos* inserirAlimentosRandom(Alimentos *lista_alimentos);
void listarAlimentos(Alimentos *lista_alimentos);
void procurarAlimento(Alimentos *lista_alimentos);
void removerAlimento(Alimentos *lista_alimentos);
Cliente *alocarCliente();
void inserirClientes(Cliente *lista_clientes);
Cliente* inserirClientesRandom(Cliente *lista_clientes);
void listarClientes(Cliente *lista_clientes);
void procurarCliente(Cliente *lista_clientes);
void proximoCliente(Cliente *lista_clientes);

void main(int argc, char *argv[]) {

	// Inicializar as listas
	Alimentos *lista_alimentos = (Alimentos*) malloc(sizeof(Alimentos));
	lista_alimentos->proximo   = NULL;
	Cliente *lista_clientes    = (Cliente*)malloc(sizeof(Cliente));
	lista_clientes->proximo    = NULL;
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

int menuGeral(){
	int opc;
	
	system("cls");
	printf("\n\n%55s","|---------------MENU PRINCIPAL---------------|\n"); 
	printf("%9s %45s", "|", "|\n");
	printf("\t|1- Realizar estudos\t\t\t     |\n");
	printf("\t|2- Padaria/Pastelaria Bom Apetite\t     |\n");
	printf("\t|0- Sair\t\t\t\t     |\n");
	printf("%54s", "|--------------------------------------------|");
	printf("\n\n\tEscolha o menu que pretende visualizar: ");
	scanf("%d", &opc);
	fflush(stdin);
	
	return opc;
}

void menuEstudos(){
	int opc;
	
	system("cls");
	printf("\n\n\t|---------------MENU ESTUDOS---------------|\n");
	printf("%9s %43s", "|", "|\n");
	printf("\t|1- Testar tempos de ordenação arrays\t   |\n");
	printf("\t|2- Testar tempos de ordenação estruturas  |\n");
	printf("\t|3- Testar tempos de procura arrays\t   |\n");
	printf("\t|-> ((Prima qualquer tecla para voltar)) <-|\n");
	printf("%52s", "|------------------------------------------|");
	printf("\n\n\tEscolha o menu que pretende visualizar: ");
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

void menuPadaria(Alimentos *lista_alimentos, Cliente *lista_clientes){
	int opc;

	system("cls");
	printf("\n\n\t|---------------PADARIA/PASTELARIA BOM APETITE---------------|\n");
	printf("%9s %61s", "|", "|\n");
	printf("\t|1- Inserir Cliente\t\t\t\t\t     |\n");
	printf("\t|2- Inserir Alimento\t\t\t\t\t     |\n");
	printf("\t|3- Listar Clientes\t\t\t\t\t     |\n");
	printf("\t|4- Listar Alimentos\t\t\t\t\t     |\n");
	printf("\t|5- Procurar Cliente\t\t\t\t\t     |\n");
	printf("\t|6- Procurar Alimento\t\t\t\t\t     |\n");
	printf("\t|7- Próximo Cliente\t\t\t\t\t     |\n");
	printf("\t|8- Remover Alimento\t\t\t\t\t     |\n");
	printf("\t|----------> ((Prima qualquer tecla para voltar)) <----------|\n");
	printf("%70s", "|------------------------------------------------------------|");
	printf("\n\n\tEscolha o menu que pretende visualizar: ");
	scanf("%d", &opc);
	fflush(stdin);
	
	switch(opc){
		case 1:
			inserirClientes(lista_clientes);
			break;
		case 2:
			inserirAlimentos(lista_alimentos);
			break;	
		case 3:
			listarClientes(lista_clientes);
			break;
		case 4:
			listarAlimentos(lista_alimentos);
			break;
		case 5:
			procurarCliente(lista_clientes);
			break;
		case 6:
			procurarAlimento(lista_alimentos);
			break;
		case 7:
			proximoCliente(lista_clientes);
			break;	
		case 8:
			removerAlimento(lista_alimentos);
			break;					
		default: printf("Opção inválida");
 	}
}

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

void inserirAlimentos(Alimentos *lista_alimentos){
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
		 
		 printf("\nDeseja inserir mais alimentos?\nS-SIM(s)\nN-NÃO(n)\n");
		 gets(optn);
	 
	} while(stricmp(optn, "N"));
}

char *randomPalavra() {
  char *letras = malloc((4 + 1) * sizeof(char)); // Reservar espaço em memória para cada letra gerada
  int i;
  char consoantes[] = "bcdfghjlmnpqrstv"; // Consoantes mais usadas
  char vogais[] = "aeiou";
  
  for (i = 0; i < 4; i++) {
  	// Sortear letra para cada posição da nova palavra
  	// Para ser palavra mais fáceis de leitura, para posições impares geramos uma cosoante e para posições pares geramos uma vogal
  	if(i % 2 == 0)
  	{
    	letras[i] = consoantes[rand() % (strlen(consoantes))];
	}
    else
    {
    	letras[i] = vogais[rand() % (strlen(vogais))];
	}
  }
  
  return letras;
}

Alimentos* inserirAlimentosRandom(Alimentos *lista_alimentos){
	
	int i;
	char *nome_alimento;
	int randomAlimentos = 10;
  	
  	// Gerar alimentos sorteados e inserir na lista
	for(i = 0; i < randomAlimentos; i++){
		Alimentos *novo_alimento = (Alimentos *) malloc(sizeof(Alimentos));
		nome_alimento = randomPalavra();
		strcpy(novo_alimento->nome, nome_alimento);
		novo_alimento->stock   = rand() % 20;
		novo_alimento->preco   = (float)((rand()%5)/0.3) + 1; // Rand entre 0 e 4(Max = 13.33), + 1 para evitar produtos a custo zero
		novo_alimento->proximo = NULL;
		
		if(lista_alimentos->proximo == NULL){
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
	}
	
	return lista_alimentos;
}

void listarAlimentos(Alimentos *lista_alimentos){
	
	int cont = 0, sem_stock = 0;
	float preco_alto = 0, preco_baixo = 0;
	
	// Se a lista for vazia, insere alimentos random(para não usar ficheiros de gravação)
	if(lista_alimentos->proximo == NULL){
		lista_alimentos = inserirAlimentosRandom(lista_alimentos);
	}
	
	printf("-------------------------------------------------\n");
	printf("|%-20s|%-15s|%-10s|\n", "NOME", "PREÇO(EURO)", "STOCK");
	printf("-------------------------------------------------\n");
	
	if(lista_alimentos->proximo == NULL){
		printf("|Sem alimentos disponíveis!\t\t\t|\n");
		printf("-------------------------------------------------\n");
		printf("TOTAL: %d\n", cont);
		system("pause");
		return;
	}
	
	Alimentos *temp;
	temp = lista_alimentos->proximo; // Evitar guardar lixo
	
	while(temp != NULL){
		printf("|%-20.20s|%-2.2f\t     |%-3d\t|\n", temp->nome, temp->preco, temp->stock);
		
		cont++;
		
		if(temp->stock == 0){
			sem_stock++;
		}
		
		if(preco_alto < temp->preco){
			preco_alto = temp->preco;
		}
		
		preco_baixo = (cont == 1 ? preco_alto : preco_baixo);
		
		if(preco_baixo > temp->preco){
			preco_baixo = temp->preco;
		}
		
		temp = temp->proximo;
	}
	printf("-------------------------------------------------\n");
	printf("TOTAL: %d\n", cont);
	printf("PREÇO MAIS ELEVADO: %.2f Euro(s)\n", preco_alto);
	printf("PREÇO MAIS BAIXO: %.2f Euro(s)\n", preco_baixo);
	printf("Nº ALIMENTOS SEM STOCK: %d\n", sem_stock);
	system("pause");
}

void procurarAlimento(Alimentos *lista_alimentos){
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

void removerAlimento(Alimentos *lista_alimentos){
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

void inserirClientes(Cliente *lista_clientes){
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

		printf("\nDeseja inserir mais Clientes?\nS-SIM(s)\nN-NÃO(n)\n");
		gets(optn);

	} while (stricmp(optn, "N"));
}

Cliente* inserirClientesRandom(Cliente *lista_clientes){
	
	int i;
	char *palavra;
	int randomClientes = 10;
  	
  	// Gerar clientes sorteados e inserir na lista
	for(i = 0; i < randomClientes; i++){
		Cliente *novo_cliente = (Cliente*) malloc(sizeof(Cliente));
		palavra = randomPalavra();
		strcpy(novo_cliente->nome, palavra);
		novo_cliente->NIF     = rand() % 100000000 + 900000000; 
		novo_cliente->proximo = NULL;
		
		if(lista_clientes->proximo == NULL){
			lista_clientes->proximo = novo_cliente;
		}
		else {                    
			Cliente *aux = lista_clientes->proximo;
			
			while(aux->proximo != NULL)
			{
				aux = aux->proximo;
			}
		
			aux->proximo = novo_cliente;
		}
	}
	
	return lista_clientes;
}

void listarClientes(Cliente *lista_clientes){
	int cont = 0;
	
	// Se a lista for vazia, insere clientes random(para não usar ficheiros de gravação)
	if(lista_clientes->proximo == NULL){
		lista_clientes = inserirClientesRandom(lista_clientes);
	}
	
	printf("-------------------------------------------------\n");
	printf("|%-25s|%-21s|\n", "NOME", "NIF");
	printf("-------------------------------------------------\n");
	
	if(lista_clientes->proximo == NULL){
		printf("|Sem clientes disponíveis!\t\t\t|\n");
		printf("-------------------------------------------------\n");
		printf("TOTAL: %d\n", cont);
		system("pause");
		return;
	}
	
	Cliente *temp;
	temp = lista_clientes->proximo; // Evitar guardar lixo
	
	while(temp != NULL){
		printf("|%-25s|%-21d|\n", temp->nome, temp->NIF);
		cont++;
		temp = temp->proximo;
	}
	printf("-------------------------------------------------\n");
	printf("TOTAL: %d\n", cont);
	system("pause");
}

void procurarCliente(Cliente *lista_clientes){
	int clienteProcurado;
	int encontrado = 0;
	
	printf("NIF do Cliente a procurar: ");
	scanf("%d", &clienteProcurado);
	
	printf("-------------------------------------------------\n");
	printf("|%-25s|%-21s|\n", "NOME", "NIF");
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
			printf("|%-25s|%-21d|\n", temp->nome, temp->NIF);
		}
		temp = temp->proximo;
	}
	
	if(!encontrado){
		printf("|Alimento não encontrado! Tente novamente!\t|\n");
	}
	printf("-------------------------------------------------\n");
	system("pause");
}

void proximoCliente(Cliente *lista_clientes){
	int clienteRemover;
	int removido = 0;
	Alimentos *anterior;
	
	printf("NIF do cliente a remover: ");
	scanf("%d", &clienteRemover);
	
	printf("-------------------------------------------------\n");
	printf("|%-25s|%-21s|\n", "NOME", "NIF");
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
		printf("|%-25s|%-21d|\n", temp->nome, temp->NIF);
		printf("-------------------------------------------------\n");
		lista_clientes->proximo = temp->proximo;
		free(temp);
		system("pause");
		return;
	}
	
	// Se for o segundo ou mais elemento da lista
	while(temp != NULL && !removido){
		if(clienteRemover == temp->NIF){
			removido = 1;
			printf("|CLIENTE REMOVIDO COM SUCESSO!\t\t\t|\n");
			printf("|%-25s|%-21d|\n", temp->nome, temp->NIF);
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
		printf("|Cliente não encontrado! Tente novamente!\t|\n");
	}
	printf("-------------------------------------------------\n");
	system("pause");
}


