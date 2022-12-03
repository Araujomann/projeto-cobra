#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

typedef struct{    //STRUCTS//
char modelo[20];
char placa[8];
char cor[15];
}idCar;

typedef struct Funcionario{
char nome[20];
char endereco[20];
int idade;
float salario;
}Funcionario;

typedef struct client{
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

typedef struct{   
char modelo[20];
char placa[8];
char cor[15];
char data[20];
}idBaixa;

void inicialpage();  //?rea de prot?tipos das fun??es//
void principalMenu();
void caixaOficina();
void carrosOficina();
void baixasCarros();
void alterarDados();
void clientes();

void funcionarios();	//FUNCIONARIOS
void cadastrar();
void listar();
void alterar();
void excluir();
int verificaNomeExistente(char nome[20]);

void cadastrarCli();	//CLIENTES
void listarCli();
void alterarCli();
void excluirCli();
int verificaNomeExistenteCli(char nome[40]);

void cadastrarCarr();	//CARROS
void listarCarr();
void alterarCarr();
void excluirCarr();
int verificaNomeExistentecarr(char modelo[20]);

FILE *pFuncionario;
FILE *pCliente;
FILE *pCarro;


int main(){    //FUNÇÃO PRINCIPAL//////////////////////////////////////////////////////////////
  int option;
	setlocale(LC_ALL, "Portuguese");
	system("cls");
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
						funcionarios();
					break;
					case 3:
						system("cls");
						carrosOficina();
					break;
					case 4: 
						system("cls");
						baixasCarros();
					break;
					case 5:
						system("cls");
						clientes();
					break;
					case 6:
						printf("Saindo...");
						Sleep(1150);
						exit(1);
					break;
					default:
						printf("Opção inválida! Por favor, digite uma das opções acima!\nAperte <<ENTER>> se entendeu. \n");
						getch();
						
				
			}
 	}while(option != 6);
}



void inicialpage(){
	printf("\t\tSistema de Controle e Administração da Trevor's Workshop  \n\n");
	printf("Seja bem-vindo(a) ao sistema de registro da melhor oficina de carros tunados da América!");
	printf("\n\n\n\n\tAperte qualquer tecla para continuar.\n");
	getch();

}
void principalMenu(){
	printf("O que deseja fazer?\n\n");
	printf("1 - Caixa da Oficina\n2 - Funcionários\n3 - Carros na Oficina\n4 - Liberação de Carros\n5 - Clientes\n6 - Sair\n");
}
void caixaOficina(){
  int option;
  FILE *ptrFile1, *ptrFile2;
  registroCaixa produto;
  tipoDServico servico;
	
	do{
		system("cls");
	  printf("1 - Registrar produtos vendidos\n2 - Registrar serviços e manutenções\n3 - Voltar\n");
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
		    printf("\n\t\tSalvando...");
		    Sleep(1450);
	      	
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
		    printf("\n\t\tSalvando...");
		    Sleep(1450);
	      
	        ptrFile2 = fopen("listaDeSevicos.txt", "a");
	        fprintf(ptrFile2, "SERVI?O REALIZADO:\n%s\nvalor: %.2f\ncliente: %s\ncarro: %s\ndata: %s\n\n", servico.servico, servico.valor, servico.cliente, servico.carro, servico.data);
	        fclose(ptrFile2);
	      
	    break;
	    case 3:
	    	main();
	    break;
	    default:
	      	printf("Opção inválida! Por favor, digite uma das opções acima!\nAperte <<ENTER>> se entendeu. \n");
			getch();
	    }
	}while(option != 3);
}
   	
void carrosOficina(){
   		int op;
		do{
			printf("1 - Registrar carro\n2 - lista de carros na oficina\n3 - Editar dados dos carros\n4 - Despachar carro\n5 - Voltar\n");
			scanf("%d", &op);
			
			switch(op){
				case 1:
					cadastrarCarr();
				break;
				case 2:
					listarCarr();
				break;
				case 3:
					alterarCarr();
				break;
				case 4:
					excluirCarr();
				break;
				case 5:
					main();
				break;
				default:
					printf("Opção inválida! Por favor, digite uma das opções acima!\nAperte <<ENTER>> se entendeu. \n");
					getch();
					
			}
	}while(op != 5);
	}
   	
void baixasCarros(){
			int option;
			FILE *ptrFile;
			idBaixa registro;
			do{
				system("cls");
				printf("1 - Registrar\n2 - Voltar\n");
				scanf("%d", &option);
				
				switch(option){
					case 1:
						system("cls");
						printf("Modelo: \n");
						fflush(stdin);
						gets(registro.modelo);
						printf("Placa: \n");
						fflush(stdin);
						gets(registro.placa);
						fflush(stdin);
						printf("Cor: \n");
						fflush(stdin);
						gets(registro.cor);
						printf("Dia da saída do carro da oficina: \n");
						fflush(stdin);
						gets(registro.data);
						printf("\n\tSalvando...");
						Sleep(1450);
					break;
					case 2:
						main();
					break;
					default:
						printf("Opção inválida! Por favor, digite uma das opções acima!\nAperte <<ENTER>> se entendeu. \n");
						getch();
				}
		    }while(option != 2);
				
		}
		
void funcionarios(){
		int op;
		do{
			printf("1 - Cadastrar novo funcionário\n2 - lista de funcionários\n3 - Editar dados dos funcionários\n4 - Remover funcionário\n5 - Voltar\n");
			scanf("%d", &op);
			
			switch(op){
				case 1:
					cadastrar();
				break;
				case 2:
					listar();
				break;
				case 3:
					alterar();
				break;
				case 4:
					excluir();
				break;
				case 5:
					main();
				break;
				default:
					printf("Opção inválida! Por favor, digite uma das opções acima!\nAperte <<ENTER>> se entendeu. \n");
					getch();
					
			}
	}while(op != 5);
}

	
void cadastrar(){
	char nome[20];
	int op;
	
	system("cls");
	printf("Informe os dados do novo funcionário:\n\n Nome: ");
	fflush(stdin);
	gets(nome);
	if ((verificaNomeExistente(nome))==0){
		Funcionario func;
		pFuncionario = fopen("Funcionarios.txt","ab+");
		strcpy(func.nome,strupr(nome));
		printf(" Endereco: ");
		fflush(stdin);
		gets(func.endereco);
		printf(" Idade: ");
		scanf("%d",&func.idade);
		printf(" Salario R$: ");
		scanf("%f",&func.salario);
		if (fwrite(&func,sizeof(Funcionario),1,pFuncionario) !=1){
			printf("\nNão foi possível realizar esse registro!\n");
		}else{
			printf("\nSalvando...");
			Sleep(1450);
			printf("\n Novo colaborador cadastrado com sucesso!\n ");
			fclose(pFuncionario);
		}
	}
	else{
		printf("\nEste Funcionario já não é mais novo!\n ");	
	}
	fclose(pFuncionario);
	getch();
	system("cls");
}

int verificaNomeExistente(char nome[20]){
	Funcionario aux;

	int verificador = 0;
	
	pFuncionario = fopen("Funcionarios.txt","rb");
	if(pFuncionario!=NULL){
		rewind(pFuncionario);
		while(!feof(pFuncionario)){
			
			fread(&aux,sizeof(Funcionario),1,pFuncionario);
			if(!feof(pFuncionario)){
				if(strcmp(aux.nome,nome)==0){
					verificador = 1;
				}
			}
		}
	}else{
		printf("\n Erro ao abrir arquivo.\n");	
	}
	fclose(pFuncionario);
	//getch();	
	
	return verificador;
}

void listar(){
	system("cls");
	Funcionario auxfunc;
	int cont = 0;
	pFuncionario = fopen("Funcionarios.txt","rb");
	if(pFuncionario!=NULL){
		printf("Lista dos funcionários: \n\n");
		
		rewind(pFuncionario);
		while(!feof(pFuncionario)){
			fread(&auxfunc,sizeof(Funcionario),1,pFuncionario);
			if(!feof(pFuncionario)){
				cont++;
				printf(" [%i]\n Nome: %s\n Endereço: %s\n Idade: %d\nSalário R$: %.2f\n\n",cont,auxfunc.nome,auxfunc.endereco,auxfunc.idade,auxfunc.salario);
			}
		}
	}else{
		printf(" Erro ao tentar abrir arquivo\n");
	}
	
	if (cont == 0){
		printf("\n\t Não há funcionários cadastrados para listar!\n");
	}
	fclose(pFuncionario);
	getch();
	system("cls");
}


void alterar(){
	Funcionario auxfunc, funcAlterado;
	int cont=-1;
	char nomePesquisa[20];
	system("cls");
	
	printf("Edição do registro de funcionários:\n\n");
	printf("Informe o NOME do Funcionário com erro no registro:\n ");
	fflush(stdin);
	gets(nomePesquisa);
	if(verificaNomeExistente(strupr(nomePesquisa)) == 1){
		pFuncionario = fopen("Funcionarios.txt","rb+");
		rewind(pFuncionario);
		while(!feof(pFuncionario)){
			fread(&auxfunc,sizeof(Funcionario),1,pFuncionario);
			if(!feof(pFuncionario)){
				cont++;
				if(strcmp(nomePesquisa,auxfunc.nome)==0){
					printf("\n Dados do Funcionário localizado:\n");
					printf(" Nome: %s\n Endereço: %s\n Idade: %d\nSalário R$: %.2f\n\n",auxfunc.nome,auxfunc.endereco,auxfunc.idade,auxfunc.salario);
					printf("\n Informe os dados para alteração do funcionário.\n");
					printf(" Nome: ");
					fflush(stdin);
					gets(nomePesquisa);
					fclose(pFuncionario);
					if((verificaNomeExistente(strupr(nomePesquisa))== 0) || ((verificaNomeExistente(strupr(nomePesquisa)) == 1) && (strcmp(auxfunc.nome,strupr(nomePesquisa)) == 0))){
						pFuncionario = fopen("Funcionarios.txt","rb+");
						strcpy(funcAlterado.nome,strupr(strupr(nomePesquisa)));
						printf(" Endereço: ");
						fflush(stdin);
						gets(funcAlterado.endereco);
						printf(" Idade: ");
						scanf("%d",&funcAlterado.idade);
						printf(" Salário R$: ");
						scanf("%f",&funcAlterado.salario);
						fseek(pFuncionario,cont*sizeof(Funcionario),SEEK_SET);
						fwrite(&funcAlterado,sizeof(Funcionario),1,pFuncionario);
						printf("\n Dados do Funcionário corrigidos!\n");		
						fclose(pFuncionario);
						break;
					}
					
					if ((verificaNomeExistente(nomePesquisa) == 1) && (strcmp(auxfunc.nome,nomePesquisa) != 0)){
						printf("\nNão foi possível alterar os dados do Funcionário.\nVocê está tentando inserir um nome já existente nos registros da empresa.\n ");
						fclose(pFuncionario);
						break;		
					}
				}
			}
		}
	}else{
		printf("\n Funcionário não localizado!\n ");		
	}
	
	fclose(pFuncionario);
	getch();
	system("cls");
}

void excluir(){
	char nomePesquisa[20];
	Funcionario funcExcluir;
	FILE *pExcluir;
	system("cls");
	printf("Exclusão de funcionários: \n\n");
	printf("Digite o NOME do funcionário que deseja excluir:\n ");
	fflush(stdin);
	gets(nomePesquisa);
	if(verificaNomeExistente(strupr(nomePesquisa))== 1){
		fclose(pFuncionario);
		pFuncionario = fopen("Funcionarios.txt","rb+");
		pExcluir = fopen("pExcluir.txt","wb+");
		rewind(pFuncionario);
		while(!feof(pFuncionario)){
			fread(&funcExcluir,sizeof(Funcionario),1,pFuncionario);
			
			if(!feof(pFuncionario)){
				if(strcmp(funcExcluir.nome,strupr(nomePesquisa))==0){
					printf("\n Funcionário Localizado!\n");
					printf("\nRemovendo...\n");
					Sleep(1450);
					printf("Removido!\n");
				}else{
					fwrite(&funcExcluir,sizeof(Funcionario),1,pExcluir);
				}
			}
		}
		fclose(pFuncionario);
		fclose(pExcluir);
		remove("Funcionarios.txt");
		rename("pExcluir.txt","Funcionarios.txt");
	}else{
		printf("\n Funcionário não localizado!\n ");		
	}
	getch();
	system("cls");
}

void clientes(){
    	int opcao;
    	do{

			printf("1 - Cadastrar novo cliente\n2 - Lista de clientes\n3 - Editar dados do CLiente\n4 - Remover cliente\n5 - Voltar\n");
			scanf("%d", &opcao);
			
			switch(opcao){
				case 1:
					cadastrarCli();
				break;
				case 2:
					listarCli();
				break;
				case 3:
					alterarCli();
				break;
				case 4:
					excluirCli();
				break;
				case 5:
					main();
				break;
				default:
					printf("Opção inválida! Por favor, digite uma das opções acima!\nAperte <<ENTER>> se entendeu. \n");
					getch();
					
			}
				
		}while(opcao != 5);
		
		
   	}
   	
void cadastrarCli(){
	char nome[40];
	int op;
	
	system("cls");
	printf("Informe os dados do novo cliente:\n\n Nome: ");
	fflush(stdin);
	gets(nome);
	if ((verificaNomeExistenteCli(nome))==0){
		client func;
		pCliente = fopen("clientList.txt","ab+");
		strcpy(func.nome,strupr(nome));
		printf(" CPF: ");
		fflush(stdin);
		gets(func.cpf);
		printf(" Telefone: ");
		fflush(stdin);
		gets(func.telefone);
		printf(" Modelo do carro: ");
		gets(func.modeloCar);
		printf(" Placa: ");
		fflush(stdin);
		gets(func.placa);
		if (fwrite(&func,sizeof(client),1,pCliente) !=1){
			printf("\nNão foi possível realizar esse registro!\n");
		}else{
			printf("\nSalvando...");
			Sleep(1450);
			printf("\n Novo cliente cadastrado com sucesso!\n ");
			fclose(pCliente);
		}
	}
	else{
		printf("\nEste Funcionario já não é mais novo!\n ");	
	}
	fclose(pCliente);
	getch();
	system("cls");
}

int verificaNomeExistenteCli(char nome[40]){
	client aux;

	int verificador = 0;
	
	pCliente = fopen("clientList.txt","rb");
	if(pCliente!=NULL){
		rewind(pCliente);
		while(!feof(pCliente)){
			
			fread(&aux,sizeof(client),1,pCliente);
			if(!feof(pCliente)){
				if(strcmp(aux.nome,nome)==0){
					verificador = 1;
				}
			}
		}
	}else{
		printf("\n Erro ao abrir arquivo.\n");	
	}
	fclose(pCliente);

	
	return verificador;
}

void listarCli(){
	system("cls");
	client auxfunc;
	int cont = 0;
	pCliente = fopen("clientList.txt","rb");
	if(pCliente!=NULL){
		printf("Lista de fiéis clientes: \n\n");
		
		rewind(pCliente);
		while(!feof(pCliente)){
			fread(&auxfunc,sizeof(client),1,pCliente);
			if(!feof(pCliente)){
				cont++;
				printf(" [%i]\n Nome: %s\n CPF: %s\n Telefone: %s\n Modelo do carro: %s\n Placa: %s\n\n",cont,auxfunc.nome,auxfunc.cpf,auxfunc.telefone,auxfunc.modeloCar, auxfunc.placa);
			}
		}
	}else{
		printf(" Erro ao tentar abrir arquivo\n");
	}
	
	if (cont == 0){
		printf("\n\t Não há clientes cadastrados para listar!\n");
	}
	fclose(pCliente);
	getch();
	system("cls");
}

void alterarCli(){
	client auxfunc, funcAlterado;
	int cont=-1;
	char nomePesquisa[20];
	system("cls");
	
	printf("Editor de registro de clientes:\n\n");
	printf("Informe o <NOME> do cliente com erro no registro:\n ");
	fflush(stdin);
	gets(nomePesquisa);
	if(verificaNomeExistenteCli(strupr(nomePesquisa)) == 1){
		pCliente = fopen("clientList.txt","rb+");
		rewind(pCliente);
		while(!feof(pCliente)){
			fread(&auxfunc,sizeof(client),1,pCliente);
			if(!feof(pCliente)){
				cont++;
				if(strcmp(nomePesquisa,auxfunc.nome)==0){
					printf("\n Dados do cliente localizado:\n");
					printf(" Nome: %s\n CPF: %s\n Telefone: %s\nModelo do carro: %s\nPlaca: %s\n",auxfunc.nome,auxfunc.cpf,auxfunc.telefone,auxfunc.modeloCar, auxfunc.placa);
					printf("\n Informe os novos dados do cliente:\n");
					printf(" Nome: ");
					fflush(stdin);
					gets(nomePesquisa);
					fclose(pCliente);
					if((verificaNomeExistenteCli(strupr(nomePesquisa))== 0) || ((verificaNomeExistenteCli(strupr(nomePesquisa)) == 1) && (strcmp(auxfunc.nome,strupr(nomePesquisa)) == 0))){
						pCliente = fopen("clientList.txt","rb+");
						strcpy(funcAlterado.nome,strupr(strupr(nomePesquisa)));
						printf(" CPF: ");
						fflush(stdin);
						gets(funcAlterado.cpf);
						printf(" Telefone: ");
						fflush(stdin);
						gets(funcAlterado.telefone);
						printf(" Modelo do carro: ");
						fflush(stdin);
						gets(funcAlterado.modeloCar);
						printf(" Placa do carro: ");
						fflush(stdin);
						gets(funcAlterado.placa);
						fseek(pCliente,cont*sizeof(client),SEEK_SET);
						fwrite(&funcAlterado,sizeof(client),1,pCliente);
						printf("\n Dados do Funcionário corrigidos!\n");		
						fclose(pCliente);
						break;
					}
					
					if ((verificaNomeExistenteCli(nomePesquisa) == 1) && (strcmp(auxfunc.nome,nomePesquisa) != 0)){
						printf("\nNão foi possível alterar do Cliente.\nVocê está tentando inserir um nome já existente nos registros da empresa.\n ");
						fclose(pCliente);
						break;		
					}
				}
			}
		}
	}else{
		printf("\n Cliente não localizado no banco de dados da empresa!\n ");		
	}
	
	fclose(pCliente);
	getch();
	system("cls");
}

void excluirCli(){
	char nomePesquisa[20];
	client funcExcluir;
	FILE *pExcluir;
	system("cls");
	printf("Banimento de clientes: \n\n");
	printf("Digite o NOME do cliente que deseja excluir:\n ");
	fflush(stdin);
	gets(nomePesquisa);
	if(verificaNomeExistenteCli(strupr(nomePesquisa))== 1){
		fclose(pCliente);
		pCliente = fopen("clientList.txt","rb+");
		pExcluir = fopen("pExcluir.txt","wb+");
		rewind(pCliente);
		while(!feof(pCliente)){
			fread(&funcExcluir,sizeof(client),1,pCliente);
			
			if(!feof(pCliente)){
				if(strcmp(funcExcluir.nome,strupr(nomePesquisa))==0){
					printf("\n Cliente Localizado!\n");
					printf("\nRemovendo...\n");
					Sleep(1450);
					printf("Removido!\n");
				}else{
					fwrite(&funcExcluir,sizeof(client),1,pExcluir);
				}
			}
		}
		fclose(pCliente);
		fclose(pExcluir);
		remove("clientList.txt");
		rename("pExcluir.txt","clientList.txt");
	}else{
		printf("\n Cliente não localizado nos registros!\n ");		
	}
	getch();
	system("cls");
}



void cadastrarCarr(){
	char modelo[20];
		int op;
		
		system("cls");
		printf("Informe os dados do carro:\n\n Modelo: ");
		fflush(stdin);
		gets(modelo);
		if ((verificaNomeExistente(modelo))==0){
			idCar func;
			pCarro = fopen("carrosNaOficina.txt","ab+");
			strcpy(func.modelo,strupr(modelo));
			printf(" Placa: ");
			fflush(stdin);
			gets(func.placa);
			printf(" Cor: ");
			fflush(stdin);
			gets(func.cor);
			Sleep(1343);
			if (fwrite(&func,sizeof(idCar),1,pCarro) !=1){
				printf("\nNão foi possível registrar o carro!\n");
			}else{
				printf("\nSalvando...");
				Sleep(1450);
				printf("\n Carro registrado com sucesso!\n ");
				Sleep(1200);
				fclose(pCarro);
			}
		}
		else{
			printf("\nEste carro já está na oficina!\n ");	
		}
		fclose(pCarro);
		system("cls");
}


int verificaNomeExistenteCarr(char modelo[20]){
	idCar aux;

	int verificador = 0;
	
	pCarro = fopen("carrosNaOficina.txt","rb");
	if(pCarro!=NULL){
		rewind(pCarro);
		while(!feof(pCarro)){
			
			fread(&aux,sizeof(idCar),1,pCarro);
			if(!feof(pCarro)){
				if(strcmp(aux.modelo,modelo)==0){
					verificador = 1;
				}
			}
		}
	}else{
		printf("\n Erro ao abrir arquivo.\n");	
	}
	fclose(pCarro);
	getch();	
	
	return verificador;
}

void listarCarr(){
	system("cls");
	idCar auxfunc;
	int cont = 0;
	pCarro = fopen("carrosNaOficina.txt","rb");
	if(pCarro!=NULL){
		printf("Lista de carros: \n\n");
		
		rewind(pCarro);
		while(!feof(pCarro)){
			fread(&auxfunc,sizeof(idCar),1,pCarro);
			if(!feof(pCarro)){
				cont++;
				printf(" [%i]\n Modelo: %s\n Placa: %s\n Cor: %s\n\n",cont,auxfunc.modelo,auxfunc.placa,auxfunc.cor);
			}
		}
	}else{
		printf(" Erro ao tentar abrir arquivo\n");
	}
	
	if (cont == 0){
		printf("\n\t Não há carros na oficina!\n");
	}
	fclose(pCarro);
	getch();
	system("cls");
}

void alterarCarr(){
	idCar auxfunc, funcAlterado;
	int cont=-1;
	char nomePesquisa[20];
	system("cls");
	
	printf("Edição de registro dos carros:\n\n");
	printf("Informe o MODELO com erro no registro:\n ");
	fflush(stdin);
	gets(nomePesquisa);
	if(verificaNomeExistenteCarr(strupr(nomePesquisa)) == 1){
		pCarro = fopen("carrosNaOficina.txt","rb+");
		rewind(pCarro);
		while(!feof(pCarro)){
			fread(&auxfunc,sizeof(idCar),1,pCarro);
			if(!feof(pCarro)){
				cont++;
				if(strcmp(nomePesquisa,auxfunc.modelo)==0){
					printf("\n Dados do carro localizado:\n");
					printf(" Modelo: %s\n Placa: %s\n Cor: %s\n\n",auxfunc.modelo,auxfunc.placa,auxfunc.cor);
					printf("\n Registre os novos dados do carro:\n");
					printf(" Modelo: ");
					fflush(stdin);
					gets(nomePesquisa);
					fclose(pCarro);
					if((verificaNomeExistenteCarr(strupr(nomePesquisa))== 0) || ((verificaNomeExistenteCarr(strupr(nomePesquisa)) == 1) && (strcmp(auxfunc.modelo,strupr(nomePesquisa)) == 0))){
						pCarro = fopen("carrosNaOficina.txt","rb+");
						strcpy(funcAlterado.modelo,strupr(strupr(nomePesquisa)));
						printf(" Placa: ");
						fflush(stdin);
						gets(funcAlterado.placa);
						printf(" Cor: ");
						gets(funcAlterado.cor);
						fseek(pCarro,cont*sizeof(idCar),SEEK_SET);
						fwrite(&funcAlterado,sizeof(idCar),1,pCarro);
						printf("\nSalvando...");
						Sleep(1410);
						printf("\n Os dados do carro foram corrigidos!\n");		
						fclose(pCarro);
						break;
					}
					
					if ((verificaNomeExistenteCarr(nomePesquisa) == 1) && (strcmp(auxfunc.modelo,nomePesquisa) != 0)){
						printf("\nNão foi possível alterar os dados do Carro.\nVocê está inserindo um carro já existente na oficina.\n ");
						fclose(pCarro);
						break;		
					}
				}
			}
		}
	}else{
		printf("\n Carro não localizado!\n ");		
	}
	
	fclose(pCarro);
	getch();
	system("cls");
}  


void excluirCarr(){
	char nomePesquisa[20];
	idCar funcExcluir;
	FILE *pExcluir;
	system("cls");
	printf("Liberação de carros: \n\n");
	printf("Digite o MODELO do carro que está saindo da oficina:\n ");
	fflush(stdin);
	gets(nomePesquisa);
	if(verificaNomeExistenteCarr(strupr(nomePesquisa))== 1){
		fclose(pCarro);
		pCarro = fopen("carrosNaOficina.txt","rb+");
		pExcluir = fopen("pExcluir.txt","wb+");
		rewind(pCarro);
		while(!feof(pCarro)){
			fread(&funcExcluir,sizeof(idCar),1,pCarro);
			
			if(!feof(pCarro)){
				if(strcmp(funcExcluir.modelo,strupr(nomePesquisa))==0){
					printf("\n Carro Localizado!\n");
					printf("\nLiberando...\n");
					Sleep(1450);
					printf("Liberado!\n");
				}else{
					fwrite(&funcExcluir,sizeof(idCar),1,pExcluir);
				}
			}
		}
		fclose(pCarro);
		fclose(pExcluir);
		remove("carrosNaOficina.txt");
		rename("pExcluir.txt","carrosNaOficina.txt");
	}else{
		printf("\n Carro não encontrado!\n ");		
	}
	getch();
	system("cls");
}

