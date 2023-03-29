#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro ()//função responsavel por cadastrar usuários no sistema
{
	char arquivo [40];//criando uma string
	char cpf [40];//criando uma string
	char nome[40];//criando uma string
	char sobrenome [40];//criando uma string
	char cargo [40];//criando uma string
	
	printf ("Digite o CPF a ser cadastrado:");//Coletando informação do usuário
	scanf ("%s", cpf);//%s referente a string
	
	strcpy(arquivo, cpf);// Responsável por copiar os valores das string
	
	FILE*file;// cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);// fecha o arquivo
			
	file = fopen (arquivo,"a");//abre arquivo
	fprintf(file,",");// coloca uma virgula
	fclose(file);//fecha arquivo
	
	printf ("Digite o nome a ser cadastrado:");//coletando informações do usuário
	scanf("%s",nome);//%s string
	
	file = fopen(arquivo,"a");//abre o arquivo e atuaçliza
	fprintf(file,nome);//Salvando o conteudo da variavel nome dentro do arquivo
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e atuaçliza
	fprintf(file,","); // adiciona uma virgula
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//coletando informação do usuário
	scanf("%s",sobrenome);//%s string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,sobrenome);//addiciona o sobrenome
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo
	fprintf(file,",");// adiciona virgula
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:");// coletando informaçoes do usuário
	scanf("%s",cargo);//%s string
	
	file = fopen(arquivo, "a");//atualiza o arquivo com o cargo
	fprintf(file,cargo);//adiciona o cargo
	fclose(file);//fecha o arquivo
	
	system("pause");// pausa a tela
		
}

int consulta ()//função responsável por fazer a consulta de um usuário
{
	setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
	char cpf [40];//criando uma string
	char conteudo [200];// criando uma string
	
	printf ("Digite o CPF a ser consultado:");//cletando informaçoes para apresentar uma resposta ao usuário
	scanf("%s",cpf);//%s string
	
	FILE*file;
	file = fopen(cpf,"r");//abre o arquivo e ler
	
	if(file == NULL)
	{
		printf ("Não foi possivel abrir o arquivo, não localizado!.\n");
		
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
	
	
}

int deletar ()//função responsável por deletar um usuário

{
	setlocale(LC_ALL, "Portuguese");
	
 	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s",cpf);
	
	FILE*file;//entrar dentro da FILE e puxar os arquivos
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usuário não cadastrado no sistema.\n");
		system ("pause");
	}
	else
	{
		remove(cpf);
		printf("Usuário deletado com sucesso.\n");
		system ("pause");
	
	}
}

int main ()//função pelo menu
{

	int  opcao=0;//definando a variável opção e colocando ela =  0
	int  laco=1;
	
	for (laco=1;laco=1;)
	{
		system ("cls");//limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
		printf ("# # # # # # # # # # # # # # # # # # #\n"); //inicio do menu
		printf ("#                                   #\n");
		printf ("#         Cartório da EBAC          # \n");
		printf ("#                                   #\n");
		printf ("# Escolha a opção desejada no menu: #\n");
		printf ("#                                   #\n");
		printf ("#\t1- Registrar nomes          #\n"); //\n pula a linha, \t começa o texto com um espaço e o printf apresnta o texto na tela para o usuário
		printf ("#\t2- Consultar nomes          #\n");
		printf ("#\t3- Deletar nomes            #\n");
		printf ("#                                   #\n");
		printf ("# # # # # # # # # # # # # # # # # # #\n\n"); //fim do menu
		printf ("Opção:");
		
		scanf  ("%d", &opcao); //armazenando a escola do usuario 
	
		system ("cls"); //limpando a tela
	
		switch (opcao)// laço de repetição
		{
			case 1:
			registro ();//chamada da fução registro
			break;
			
			case 2:
			consulta();//chamada da função consulta
			break;
			
			case 3:
			deletar();//chamada da função deletar
			break;
			
			default:
			printf ("Essa opção não está disponivel!\n\n");// resposta ao usuario quando o mesmo digita algo divergente
			system ("pause");
			break;
				
		}
	
	}
}
