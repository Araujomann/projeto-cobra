#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{    //STRUCTS//
char modeloCarro;
char placa;
}idCar;

typedef struct{
char nome[40];
char cpf[12];
char telefone[20];
char modeloCar[30];
char placa[8];
}cliente;

typedef struct{
char produto[25];
float valor;
char data[20];
} registroCaixa;

typedef struct{
char servico[100];
char cliente[40];
char carro[30];
char data[20];
}tipoDServico;

void inicialpage();  //Área de protótipos das funções//
void principalMenu();
void caixaOficina();



int main(){    //FUNÇÃO PRINCIPAL
  int option;
	setlocale(LC_ALL, "Portuguese");
	inicialpage();

  printf("O que deseja fazer?\n\n");
	printf("1 - Caixa da Oficina\n2 - Clientes\n3 - Carros na Oficina\n4 - Carros despachados(Em período de garantia)\n5 - Sair\n");
  
	scanf("%d", &option);
  switch(option){
			case 1:
			  caixaOficina();      //CHAMADA DE PROCEDIMENTO//
			break;
			case 2: 
				printf("1 - Cadastrar novo cliente\n2 - Corrigir\n3 - Lista de Clientes\n4 - Remover cliente\n");
			break;
			case 3:
				
			
			case 4: 
				/*printf("Digite o nome do(a) proprietário(a) do carro: \n");
				gets(carOwner);
				printf("Digite o modelo do carro: \n");
				gets(nameCar);
				printf("Digite a placa do carro: \n");
				gets(placa);
			break;*/
			case 5:
				return 0;
			break;
			default:
				printf("Opção inválida! Por favor, digite uma opção válida: \n");
				scanf("%d", &option);
		
	}
}
	/*principalMenu();
	option();*/
	
	
	


void inicialpage(){
	printf("\t\t\t\t\t\tSistema de Controle e Administração da Trevor's Workshop  \n\n");
	printf("\t\tSeja bem-vindo(a) ao sistema de registro da melhor oficina de carros tunados da América!");
	printf("\n\n\n\n\t Aperte qualquer tecla para continuar.\n");
	getchar();

}
void principalMenu(){
	printf("Selecione uma opção:\n\n");
	printf("1 - Caixa da Oficina\n\n2 - Clientes\n3 - Carros na Oficina\n4 - Carros despachados(Em período de garantia)\n5 - Sair\n");
}
void caixaOficina(){
  int option;
  FILE *ptrFile1, *ptrFile2;
  registroCaixa produto;
  tipoDServico servico;

  printf("1 - Produtos vendidos\n2 - Serviços e manutenções\n");
  scanf("%d", &option);
  
  switch(option){
    case 1: 
    
      printf("Digite o produto, o valor e a data respectivamente: ");
      scanf("%s %f %s", produto.produto, &produto.valor, produto.data);
      
      ptrFile1 = fopen("listaDeVendas.txt", "a");
      fprintf(ptrFile1, "%s %f %s", produto.produto, produto.valor, produto.data);
      fclose(ptrFile1);
    
    break;
    case 2:
  
      printf("Serviço prestado: ");
      gets(servico.servico);
      printf("Nome do cliente:");
      gets(servico.cliente);
      printf("Modelo do carro: ");
      gets(servico.carro);
      printf("Data: ");
      gets(servico.data);
      
    break;
    default:
      printf("Opção inválida, por favor, escolha uma das opções acima:");
    }
}