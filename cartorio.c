#include <stdio.h> //biblioteca de comunicação com o usuário
#include <locale.h> //biblioteca de alocaçôes de texto por região
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <string.h> //biblioteca responsável por cuidar das strings

//bibliotecas sempre serão a primeira coisa no código


//Criando Funções
int registro()//função responsável por cadastrar usuários no sistema
{
	setlocale(LC_ALL,"Portuguese");
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
		
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo,"w"); //cria o arquivo, w = write ou seja, cria arquivo
	fprintf(file,cpf);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a"); //a = atualiza arquivo
	fprintf(file,", ");//adiciona vírgula
	fclose(file);//fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",nome);//salvando informação na variável nome
	
	file = fopen(arquivo,"a");//abrindo o arquivo no modo de atualização
	fprintf(file,nome);//salvando a informação no arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo,"a"); //abrindo o arquivo no modo de atualização
	fprintf(file,", ");//salvando a informação no arquivo
	fclose(file);//fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coleta de informação do usuário
	scanf("%s",sobrenome);//salvando a informação digitada, na variável
	
	file = fopen(arquivo,"a");//abrindo o arquivo no modo de atualização
	fprintf(file,sobrenome);//salvando a informação no arquivo
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo,"a"); //abrindo o arquivo no modo de atualização
	fprintf(file,", ");//salvando informação no arquivo
	fclose(file);//fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coleta de informação
	scanf("%s",cargo);//salvamento de informação coletada
	
	file = fopen(arquivo,"a");//abrindo o arquivo no modo de atualização
	fprintf(file,cargo);//salvando informação no arquivo
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo,"a"); //abrindo o arquivo no modo de atualização
	fprintf(file,"; ");//gravando informação no arquivo
	fclose(file);//fecha arquivo
	
	system("pause");//pausa o programa até nova ação do usuário
	
}

int consulta()//consulta arquivos salvos sobre os clientes
{
	setlocale(LC_ALL,"Portuguese");//seta a linguagem que será usada
	//inicio definição de variáveis
	char cpf[40];
	char conteudo[200];
	//fim definição de variáveis
	
	printf("Digite o CPF a ser consultado: ");//coleta de informação do usuário
	scanf("%s",cpf);//salva informação na variável
	
	FILE *file;//FILE é a função e file é o arquivo que está sendo setado
	file = fopen(cpf,"r");//r = read, lê o arquivo e cpf é a variável que possui o nome real do file
	
	if(file == NULL)//testa se o arquivo existe
	{
		printf("\nArquivo não localizado!\n\n");//o arquivo não existe
		system("pause");//peusa o programa até uma nova ação do usuário
	}
	while(fgets(conteudo, 200, file)!= NULL)//enquanto estiver escrevendo na váriável ou na string conteúdo até 200 valores que estão dentro do arquivo e for diferente de nulo, ele vai escrever.
	{
		printf("\nEssas são as informações do usuário: \n\n");//mensagem para o operador
		printf("%s",conteudo);//mostra as informações do usuário
		printf("\n\n");// /n pula uma linha
		system("pause");//pausa o sistema até nova ação do usuário
		
	}
}

int deletar()//função que irá deletar os arquivos de usuários desejados
{
	//inicio das variáveis
	char cpf[40];
	//fim das variáveis
	printf("Digite o CPF do usuário a ser deletado: ");//coleta de informação
	scanf("%s",cpf);//salva informação na variável
	
	remove(cpf);//apaga o arquivo que foi informado
	
	FILE *file;//FILE é a função e *file é o arquivo propriamente dito sendo setado pela função
	file = fopen(cpf,"r");//"r" é o comando que informa que está lendo o arquivo, fopen é a função que está abrindo o arquivo, cpf é o nome do arquivo.
	
	if(file == NULL)//testa se o arquivo existe
	{
		printf("\n\nUsuário deletado ou não cadastrado no sistema!\n\n");//mensagem se o arquivo não existe
		system("pause");//pausa o programa até nova ação do usuário
	}
	else
	{
		printf("\n\nErro ao deletar o arquivo\n\n");//mensagem de erro caso encontrado o arquivo
		system("pause");//pausa o programa até nova ação do usuário
	}
	
	
}

int main(void) //inicio do programa
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	//fim definição variáveis
	for(laco=1;laco=1;)
	{
		system("cls");//responsável por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
		printf("\t\t***Cartório da Ebac***\n\n"); //inicio do menu
		printf("Escolha a opção desejada:\n\n");//mostra uma mensagem na tela para o usuário
		printf("\t1_Resgistrar nomes.\n");//mostra uma mensagem na tela para o usuário
		printf("\t2_Consultar nomes.\n");//mostra uma mensagem na tela para o usuário
		printf("\t3_Deletar nomes.\n\n"); //mostra uma mensagem na tela para o usuário
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");//limpa a tela
	
		switch(opcao) //inicio da seleção
		{
	   		case 1:
			registro();//chama a função registro
			break;//fim do case 1
			
			case 2: 
			consulta();//chama a função consulta
			break;//fim do case 2
			
			case 3:
			deletar();//chama a função deletar
			break;//fim do case 3
			
			default: //quando a opção não está presenta nos cases
			printf("Opção inválida.\n");//mensagem caso a opção não seja válida
			system("pause");//pausa o programa até nova ação do usuário
			break;//fim do default
		} 
 	}//Fim da seleção
}

