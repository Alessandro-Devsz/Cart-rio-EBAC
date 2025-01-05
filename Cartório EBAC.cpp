#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de oloca��o de espa�o de mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h>//Biblioteca que cuida das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/strings (conjunto de vari�veis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/strings (conjunto de vari�veis)
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string, salvar
	
	strcpy(arquivo,cpf);//Respons�vel por copiar valores das string
	FILE *file;//cria o arquivo
	
	file = fopen(arquivo, "w");//cria o arquivo (escrever "w")
	fprintf(file,"\nCPF: "); //Separa por categoria (bonito visualmente)
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); //(adicionar)
	fprintf(file,",\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome); 
	fclose(file); 
	file = fopen(arquivo, "a");
	fprintf(file,",\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);//armazenando a variavel "cpf" utilizando a fun��o "%s"
	
	FILE *file;
	file = fopen(cpf,"r");//abre o arquivo CPF e "R" de Read (Ler) a informa��o
	
	if(file == NULL)//Se a infroma��o n�o existir traz a seguinte informa��o
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n");
	}	

	printf("\nEssas s�o as informa��es do usu�rio: ");//informa��o a aparecer antes dos dados

	while(fgets(conteudo, 200, file) != NULL)//While (enquanto) tiver informa��o, armazene a informa��o em conteudo se for diferente de NULL (nulo)
	{
		printf("%s", conteudo);
		printf("\n");//Pular linha
	}
	
	system("pause");
	fclose(file);

}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //scanf: varrer o que o usu�rio digita e salvar onde pedimos
	
	remove(cpf); //deletar cpf
	
	FILE*file; //entrar na biblioteca arquivo, e puxar o arquivo
	file = fopen(cpf,"r"); //abra a pasta e procure o arquivo cpf, e leia.
	
	
	if(file == NULL) //Se n�o achar o arquivo
	{
		printf("CPF deletado com sucesso!\n"); //mensagem que n�o encontrou o cpf
	
		system("pause");
	}
	
}


int main() 
{
	int opcao=0;//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Respons�vel por limpar a tela

		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");//inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
		system("cls");
		
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //fim da sele��o
	
    
	}

}
