#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro ()//fun��o responsavel por cadastrar usu�rios no sistema
{
	char arquivo [40];//criando uma string
	char cpf [40];//criando uma string
	char nome[40];//criando uma string
	char sobrenome [40];//criando uma string
	char cargo [40];//criando uma string
	
	printf ("Digite o CPF a ser cadastrado:");//Coletando informa��o do usu�rio
	scanf ("%s", cpf);//%s referente a string
	
	strcpy(arquivo, cpf);// Respons�vel por copiar os valores das string
	
	FILE*file;// cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);// fecha o arquivo
			
	file = fopen (arquivo,"a");//abre arquivo
	fprintf(file,",");// coloca uma virgula
	fclose(file);//fecha arquivo
	
	printf ("Digite o nome a ser cadastrado:");//coletando informa��es do usu�rio
	scanf("%s",nome);//%s string
	
	file = fopen(arquivo,"a");//abre o arquivo e atua�liza
	fprintf(file,nome);//Salvando o conteudo da variavel nome dentro do arquivo
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e atua�liza
	fprintf(file,","); // adiciona uma virgula
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//coletando informa��o do usu�rio
	scanf("%s",sobrenome);//%s string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,sobrenome);//addiciona o sobrenome
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo
	fprintf(file,",");// adiciona virgula
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:");// coletando informa�oes do usu�rio
	scanf("%s",cargo);//%s string
	
	file = fopen(arquivo, "a");//atualiza o arquivo com o cargo
	fprintf(file,cargo);//adiciona o cargo
	fclose(file);//fecha o arquivo
	
	system("pause");// pausa a tela
		
}

int consulta ()//fun��o respons�vel por fazer a consulta de um usu�rio
{
	setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
	char cpf [40];//criando uma string
	char conteudo [200];// criando uma string
	
	printf ("Digite o CPF a ser consultado:");//cletando informa�oes para apresentar uma resposta ao usu�rio
	scanf("%s",cpf);//%s string
	
	FILE*file;
	file = fopen(cpf,"r");//abre o arquivo e ler
	
	if(file == NULL)
	{
		printf ("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
		
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
	
	
}

int deletar ()//fun��o respons�vel por deletar um usu�rio

{
	setlocale(LC_ALL, "Portuguese");
	
 	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s",cpf);
	
	FILE*file;//entrar dentro da FILE e puxar os arquivos
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usu�rio n�o cadastrado no sistema.\n");
		system ("pause");
	}
	else
	{
		remove(cpf);
		printf("Usu�rio deletado com sucesso.\n");
		system ("pause");
	
	}
}

int main ()//fun��o pelo menu
{

	int  opcao=0;//definando a vari�vel op��o e colocando ela =  0
	int  laco=1;
	
	for (laco=1;laco=1;)
	{
		system ("cls");//limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
		printf ("# # # # # # # # # # # # # # # # # # #\n"); //inicio do menu
		printf ("#                                   #\n");
		printf ("#         Cart�rio da EBAC          # \n");
		printf ("#                                   #\n");
		printf ("# Escolha a op��o desejada no menu: #\n");
		printf ("#                                   #\n");
		printf ("#\t1- Registrar nomes          #\n"); //\n pula a linha, \t come�a o texto com um espa�o e o printf apresnta o texto na tela para o usu�rio
		printf ("#\t2- Consultar nomes          #\n");
		printf ("#\t3- Deletar nomes            #\n");
		printf ("#                                   #\n");
		printf ("# # # # # # # # # # # # # # # # # # #\n\n"); //fim do menu
		printf ("Op��o:");
		
		scanf  ("%d", &opcao); //armazenando a escola do usuario 
	
		system ("cls"); //limpando a tela
	
		switch (opcao)// la�o de repeti��o
		{
			case 1:
			registro ();//chamada da fu��o registro
			break;
			
			case 2:
			consulta();//chamada da fun��o consulta
			break;
			
			case 3:
			deletar();//chamada da fun��o deletar
			break;
			
			default:
			printf ("Essa op��o n�o est� disponivel!\n\n");// resposta ao usuario quando o mesmo digita algo divergente
			system ("pause");
			break;
				
		}
	
	}
}
