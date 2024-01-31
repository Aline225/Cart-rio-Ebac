#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <string.h> //biblioteca respons�vel por cuidar das strings

//bibliotecas sempre ser�o a primeira coisa no c�digo


//Criando Fun��es
int registro()//fun��o respons�vel por cadastrar usu�rios no sistema
{
	setlocale(LC_ALL,"Portuguese");
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
		
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo,"w"); //cria o arquivo, w = write ou seja, cria arquivo
	fprintf(file,cpf);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a"); //a = atualiza arquivo
	fprintf(file,", ");//adiciona v�rgula
	fclose(file);//fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",nome);//salvando informa��o na vari�vel nome
	
	file = fopen(arquivo,"a");//abrindo o arquivo no modo de atualiza��o
	fprintf(file,nome);//salvando a informa��o no arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo,"a"); //abrindo o arquivo no modo de atualiza��o
	fprintf(file,", ");//salvando a informa��o no arquivo
	fclose(file);//fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coleta de informa��o do usu�rio
	scanf("%s",sobrenome);//salvando a informa��o digitada, na vari�vel
	
	file = fopen(arquivo,"a");//abrindo o arquivo no modo de atualiza��o
	fprintf(file,sobrenome);//salvando a informa��o no arquivo
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo,"a"); //abrindo o arquivo no modo de atualiza��o
	fprintf(file,", ");//salvando informa��o no arquivo
	fclose(file);//fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coleta de informa��o
	scanf("%s",cargo);//salvamento de informa��o coletada
	
	file = fopen(arquivo,"a");//abrindo o arquivo no modo de atualiza��o
	fprintf(file,cargo);//salvando informa��o no arquivo
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo,"a"); //abrindo o arquivo no modo de atualiza��o
	fprintf(file,"; ");//gravando informa��o no arquivo
	fclose(file);//fecha arquivo
	
	system("pause");//pausa o programa at� nova a��o do usu�rio
	
}

int consulta()//consulta arquivos salvos sobre os clientes
{
	setlocale(LC_ALL,"Portuguese");//seta a linguagem que ser� usada
	//inicio defini��o de vari�veis
	char cpf[40];
	char conteudo[200];
	//fim defini��o de vari�veis
	
	printf("Digite o CPF a ser consultado: ");//coleta de informa��o do usu�rio
	scanf("%s",cpf);//salva informa��o na vari�vel
	
	FILE *file;//FILE � a fun��o e file � o arquivo que est� sendo setado
	file = fopen(cpf,"r");//r = read, l� o arquivo e cpf � a vari�vel que possui o nome real do file
	
	if(file == NULL)//testa se o arquivo existe
	{
		printf("\nArquivo n�o localizado!\n\n");//o arquivo n�o existe
		system("pause");//peusa o programa at� uma nova a��o do usu�rio
	}
	while(fgets(conteudo, 200, file)!= NULL)//enquanto estiver escrevendo na v�ri�vel ou na string conte�do at� 200 valores que est�o dentro do arquivo e for diferente de nulo, ele vai escrever.
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");//mensagem para o operador
		printf("%s",conteudo);//mostra as informa��es do usu�rio
		printf("\n\n");// /n pula uma linha
		system("pause");//pausa o sistema at� nova a��o do usu�rio
		
	}
}

int deletar()//fun��o que ir� deletar os arquivos de usu�rios desejados
{
	//inicio das vari�veis
	char cpf[40];
	//fim das vari�veis
	printf("Digite o CPF do usu�rio a ser deletado: ");//coleta de informa��o
	scanf("%s",cpf);//salva informa��o na vari�vel
	
	remove(cpf);//apaga o arquivo que foi informado
	
	FILE *file;//FILE � a fun��o e *file � o arquivo propriamente dito sendo setado pela fun��o
	file = fopen(cpf,"r");//"r" � o comando que informa que est� lendo o arquivo, fopen � a fun��o que est� abrindo o arquivo, cpf � o nome do arquivo.
	
	if(file == NULL)//testa se o arquivo existe
	{
		printf("\n\nUsu�rio deletado ou n�o cadastrado no sistema!\n\n");//mensagem se o arquivo n�o existe
		system("pause");//pausa o programa at� nova a��o do usu�rio
	}
	else
	{
		printf("\n\nErro ao deletar o arquivo\n\n");//mensagem de erro caso encontrado o arquivo
		system("pause");//pausa o programa at� nova a��o do usu�rio
	}
	
	
}

int main(void) //inicio do programa
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	//fim defini��o vari�veis
	for(laco=1;laco=1;)
	{
		system("cls");//respons�vel por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
		printf("\t\t***Cart�rio da Ebac***\n\n"); //inicio do menu
		printf("Escolha a op��o desejada:\n\n");//mostra uma mensagem na tela para o usu�rio
		printf("\t1_Resgistrar nomes.\n");//mostra uma mensagem na tela para o usu�rio
		printf("\t2_Consultar nomes.\n");//mostra uma mensagem na tela para o usu�rio
		printf("\t3_Deletar nomes.\n\n"); //mostra uma mensagem na tela para o usu�rio
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");//limpa a tela
	
		switch(opcao) //inicio da sele��o
		{
	   		case 1:
			registro();//chama a fun��o registro
			break;//fim do case 1
			
			case 2: 
			consulta();//chama a fun��o consulta
			break;//fim do case 2
			
			case 3:
			deletar();//chama a fun��o deletar
			break;//fim do case 3
			
			default: //quando a op��o n�o est� presenta nos cases
			printf("Op��o inv�lida.\n");//mensagem caso a op��o n�o seja v�lida
			system("pause");//pausa o programa at� nova a��o do usu�rio
			break;//fim do default
		} 
 	}//Fim da sele��o
}

