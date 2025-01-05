#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de olocação de espaço de memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h>//Biblioteca que cuida das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/strings (conjunto de variáveis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/strings (conjunto de variáveis)
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string, salvar
	
	strcpy(arquivo,cpf);//Responsável por copiar valores das string
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
	scanf("%s",cpf);//armazenando a variavel "cpf" utilizando a função "%s"
	
	FILE *file;
	file = fopen(cpf,"r");//abre o arquivo CPF e "R" de Read (Ler) a informação
	
	if(file == NULL)//Se a infromação não existir traz a seguinte informação
	{
		printf("Não foi possível abrir o arquivo, não localizado.\n");
	}	

	printf("\nEssas são as informações do usuário: ");//informação a aparecer antes dos dados

	while(fgets(conteudo, 200, file) != NULL)//While (enquanto) tiver informação, armazene a informação em conteudo se for diferente de NULL (nulo)
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //scanf: varrer o que o usuário digita e salvar onde pedimos
	
	remove(cpf); //deletar cpf
	
	FILE*file; //entrar na biblioteca arquivo, e puxar o arquivo
	file = fopen(cpf,"r"); //abra a pasta e procure o arquivo cpf, e leia.
	
	
	if(file == NULL) //Se não achar o arquivo
	{
		printf("CPF deletado com sucesso!\n"); //mensagem que não encontrou o cpf
	
		system("pause");
	}
	
}


int main() 
{
	int opcao=0;//Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Responsável por limpar a tela

		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");//inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usuário
	
		system("cls");
		
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
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
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		} //fim da seleção
	
    
	}

}
