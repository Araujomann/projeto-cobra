#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

typedef struct{    //STRUCTS//
char modeloCarro;
char placa;
}idCar;

typedef struct{
char nome[40];
char cpf[15];
char telefone[20];
char modeloCar[30];
char placa[8];
}client;

typedef struct{
char produto[25];
float valor;
char data[20];
} registroCaixa;

typedef struct{
char servico[100];
float valor;
char cliente[40];
char carro[30];
char data[20];
}tipoDServico;

void inicialpage();  //Área de protótipos das funções//
void principalMenu();
void caixaOficina();
void clientes();



int main(){    //FUNÇÃO PRINCIPAL//////////////////////////////////////////////////////////////
  int option;
	setlocale(LC_ALL, "Portuguese");
	inicialpage();
	do{	
  		system("cls");
  		principalMenu();
		scanf("%d", &option);
		
		  switch(option){
					case 1:
						system("cls");
					  	caixaOficina();      //CHAMADA DE PROCEDIMENTO//
					break;
					case 2:
						system("cls");
						clientes();
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
						printf("Opção inválida! Por favor, digite uma das opções acima!\nAperte <<ENTER>> se entendeu. \n");
						getch();
						
				
			}
 	}while(option != 5);
}



void inicialpage(){
	printf("\t\t\t\t\t\tSistema de Controle e Administração da Trevor's Workshop  \n\n");
	printf("\t\t\t\tSeja bem-vindo(a) ao sistema de registro da melhor oficina de carros tunados da América!");
	printf("\n\n\n\n\t Aperte qualquer tecla para continuar.\n");
	getch();

}
void principalMenu(){
	printf("O que deseja fazer?\n\n");
	printf("1 - Caixa da Oficina\n2 - Clientes\n3 - Carros na Oficina\n4 - Carros despachados(Em período de garantia)\n5 - Sair\n");
}
void caixaOficina(){
  int option;
  FILE *ptrFile1, *ptrFile2;
  registroCaixa produto;
  tipoDServico servico;

  printf("1 - Registrar produtos vendidos\n2 - Registrar serviços e manutenções\n3 - Voltar");
  scanf("%d", &option);
  
  
  switch(option){
    case 1: 
      system("cls");
      printf("Produto: \n");
      fflush(stdin);
      gets(produto.produto);
      printf("Valor: \n");
      scanf("%f", &produto.valor);
      printf("Data de compra: \n");
      fflush(stdin);
      gets(produto.data);
      
      
      ptrFile1 = fopen("listaDeVendas.txt", "a");
      fprintf(ptrFile1, "VENDA REALIZADA:\nproduto: %s\nvalor: R$%.2f\n data: %s\n\n", produto.produto, produto.valor, produto.data);
      fclose(ptrFile1);
    
    break;
    case 2:
  	  system("cls");
      printf("Serviço prestado: ");
      fflush(stdin);
      gets(servico.servico);
      printf("Valor do serviço: ");
      scanf("%f", &servico.valor);
      printf("Nome do cliente: ");
      fflush(stdin);
      gets(servico.cliente);
      printf("Modelo do carro: ");
      fflush(stdin);
      gets(servico.carro);
      printf("Data: ");
      fflush(stdin);
      gets(servico.data);
      
      ptrFile2 = fopen("listaDeSevicos.txt", "a");
      fprintf(ptrFile2, "SERVIÇO REALIZADO:\n%s\nvalor: %.2f\ncliente: %s\ncarro: %s\ndata: %s\n\n", servico.servico, servico.valor, servico.cliente, servico.carro, servico.data);
      fclose(ptrFile2);
      
    break;
    case 3:
    	main();
    break;
    default:
      printf("Opção inválida, por favor, escolha uma das opções acima:");
    }
}
    void clientes(){
    	int option;
    	client cliente;
    	FILE *ptrFile;
    	
    	printf("1 - Cadastrar novo cliente\n2 - Corrigir\n3 - Lista de Clientes\n4 - Remover cliente\n5 - Voltar\n");
    	scanf("%d", &option);
    	
    	switch(option){
    		case 1:
    			system("cls");
    			printf("Nome do novo cliente: \n");
    			fflush(stdin);
    			gets(cliente.nome);
    			printf("CPF: \n");
    			fflush(stdin);
    			gets(cliente.cpf);
    			printf("Número para contato: \n");
    			fflush(stdin);
    			gets(cliente.telefone);
    			printf("Modelo do carro do cliente: \n");
    			fflush(stdin);
    			gets(cliente.modeloCar);
    			printf("Placa do carro: \n");
    			fflush(stdin);
    			gets(cliente.placa);
    			
	    		ptrFile = fopen("listaDeClientes.txt", "a");
	    		fprintf(ptrFile, "DADOS DO NOVO CLIENTE:\nnome: %s\nCPF: %s\ncontato: %s\ncarro: %s\nplaca: %s\n\n", cliente.nome, cliente.cpf, cliente.telefone, cliente.modeloCar, cliente.placa);
	    		fclose(ptrFile);
    		break;
    		case 2:
    		
    		break;
    		case 3:
    			
    		break;
    		case 4:
    			
    		break;
    		
    		case 5:
    			main();
    		break;
    		default:
    			 printf("Opção inválida, por favor, escolha uma das opções acima:");
		}
    
    	
	}
	



