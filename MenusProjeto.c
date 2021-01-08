#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
#include <locale.h>


// Chamar pelo procedimento que identifica os lares com mais e menos casos de Covid-19 
void MaisMenosCasos (int *casos, int contador);

// Chamar pelo procedimento que identifica os lares com pior e melhor avalia��o
void MelhorPiorAvaliacao(int *avaliacoes, int contadoravaliacao);

// Chamar pelo procedimento que calcula a percentagem de cada lar
void Percentagem(int *casos, int *utentes, int contador);

// Chamar pelo procedimento que verifica se a password inserida na conta "Gestor" est� correta
int Verificapassgestor(char *password, char *passwordgestor);

// Chamar pelo procedimento que verifica se a password inserida na conta "Equipa" est� correta
int Verificapasequipa(char *password, char *passwordequipa);

//
//int MenuSubmenuEquipas(void);

//
void MenuSubmenuEquipas(RegistoMembro *membros);

//
int MenuSubmenuLares(void);

//
void MenuGestor(RegistoMembro *membros);

//
void Menugeral(void);

//
const char* escolha();


// Estrutura com informa��o de um membro
typedef struct registoMembro
{
	char Nome[50];
	int contacto;
	double CC;
	char Morada[50];
	char CartaConducao[15];
	char AreaProfissional[20];
	char email[50];
	
}RegistoMembro;


// Estrutura com informa��o de um lar
typedef struct registoLar
{
	char Nome[50];
	char Morada[50];
	int NumeroUtentes;
	int NumeroFuncionarios;
	int id;
	int contacto;
	char email[50];
	
}RegistoLar;



int main(int argc, char *argv[]) 
{
	
	// Configura��es da consola
	setlocale(LC_ALL, "Portuguese");
	system("color F0");
	
	// Variav�is
	int i,opcao,opcao2,verificadorpasswordgestor,verificadorpasswordequipa;
	RegistoMembro membros[1000];
	char verificador;
	char passwordgestor[50] = "Gestor123456";					// Password GESTOR
	char passwordequipa[50] = "Equipa123456";					// Password EQUIPA
	char password[50];
	char ch;
	int casos[250], contador = 0, avaliacoes[250], contadoravaliacao = 0, percentagemCovid, utentes[250], contadorUtente = 0;
	char opcao1 = 's';
	
	// Menu com os logins (Equipa/Gestor) e a respetiva valida��o da password
    Menugeral();
	verificador = escolha();
	
	// Verificar a password
    if(verificador == 'G' || verificador == 'g')
	{	
		verificadorpasswordgestor = 0;
		verificadorpasswordgestor = Verificapassgestor(password,passwordgestor);
		
		if(verificadorpasswordgestor == 1)
		{
			system("CLS");
			MenuGestor(RegistoMembro *membros);
		}
		else 
		{
			printf("Password Invalida!!");
		}
    }
	else if(verificador == 'e' || verificador == 'E')
	{
		verificadorpasswordequipa = 0;
   		verificadorpasswordequipa = Verificapasequipa(password,passwordequipa);
   		
		if(verificadorpasswordequipa == 1)
		{
			system("CLS");
			MenuGestor(RegistoMembro *membros);
		}
		else 
		{
			printf("Password Invalida!!");
		}
	}

	getchar();
	return 0;
}


	//funcao verificar e escolher opcao gestor
	int Verificapassgestor(char *password, char *passwordgestor)
	{
		// variav�is
		int i,verificador = 0;
	
		printf("Password:");
    	
		do
		{ 
        	password[i]=getch();
			 
        	if(password[i]!='\r')
            	printf("*"); 
        	
			i++;
			 
    	}while(password[i-1]!='\r');
    	
    	password[i-1] = '\0';
		printf("\n");
		
		if(strcmp(password,passwordgestor) == 0)
			verificador = 1;
		else
			verificador = 0;		
    	
    return verificador;	
}


//funcao verificar e escolher opcao equipa
int Verificapasequipa(char *password, char *passwordequipa)
{
	// vari�veis
	int i,verificador = 0;
	
		printf("Password:");
		
    	do
		{ 
        	password[i]=getch(); 
        
			if(password[i]!='\r')
            	printf("*"); 
        
			i++; 
    	
		}while(password[i-1]!='\r');
    	
		password[i-1] = '\0';
		printf("\n");
		
		if(strcmp(password,passwordequipa) == 0)
			verificador = 1;
		else
			verificador = 0;		
    	
    return verificador;	

}


//funcao para sub menu da gest�o das equipas 
void MenuSubmenuEquipas(RegistoMembro *membros)
{  
	// vari�veis
    int opcao2;
    int contador  = 1;
    
    while (contador)
    {
    	printf("1-Inserir Equipas\n");
    	printf("2-Editar Equipas \n");
    	printf("3-Eliminar Equipas\n");
    	printf("0-Voltar ao menu Principal\n");
    	printf("Op��o:");
        scanf(" %d", &opcao2);

        switch (opcao2)
        {
        
			case 1:
        		int i, id;
        		char carta, opcao;
            	puts("-----Inserir uma Nova equipa-----\n");
            	
				do
				{
					puts("Insira o ID da equipa:");
					scanf(" %d", &id);
					puts("Nome do novo membro:\n");
            		//scanf(" %c", &membro[i].Nome);
            		puts("�rea Profissional:");
            		//scanf(" %c", &membro[i].Nome);
            		puts("Contacto:");
           			//scanf(" %c", &membro[i].Nome);
           			puts("Cart�o de cidad�o");
           			//scanf(" %c", &membro[i].Nome);
            		puts("Morada:");
            		//scanf(" %c", &membro[i].Nome);
            		puts("Email:");
            		//scanf(" %c", &membro[i].Nome);
            		puts("Possui Carta de Condu��O:");
            		puts("\tSim---(s)\n \tN�o---(n)");
            		scanf(" %c", &carta);
            	
					if(carta == 's' || carta == 'S')
					{
						puts("Insira o Numero da Carta de Condu��o");
						//scanf(" %c", &membro[i].Nome);
					}
					
        			i++;
        			
        			puts("Pretende Inserir mais algum Membro?");
        			puts("\tSim---(s)\n \tN�o---(n)");
        			scanf(" %c", &opcao);
        		
				}while(opcao != 'n' || opcao != 'N');

            
        	case 2:  
            	printf(".......	em constru�ao......\n");
            	break;
        
       		 case 3:
        		printf(".......	em constru�ao......\n");
            	break;

        	case 0:
           		system("CLS");
		    	contador = 0;  
            	MenuGestor();

        	default:
            	printf("Invalid choice.\n");
            	break;
        }
    }
}


//fun��o para sub menu da gest�o das equipas dos lares 
int MenuSubmenuLares(void)
{  
	// vari�veis
    int opcao2;
    int contador  = 1;
    
    while (contador)
    {
    	printf("1-Inserir Lares\n");
    	printf("2-Editar Lares \n");
    	printf("3-Eliminar Lares\n");
    	printf("0-Voltar ao menu Principal\n");
    	printf("Op��o:");
        scanf(" %d", &opcao2);

        switch (opcao2)
        {
        	case 1:
            	printf(".......	em constru�ao......\n");
            	break;

        	case 2:
           		printf(".......	em constru�ao......\n");
           		break;
        
        	case 3:
        		printf(".......	em constru�ao......\n");
            	break;

        	case 0:
           		system("CLS");
		    	contador = 0;  
            	MenuGestor();

        	default:
            	printf("Invalid choice.\n");
            	break;
        }
    }
}


//funcao para sub menu
void Menugeral(void)
{
		char verificador;
		puts("---------Sistema de Lares---------");
		printf("Gestor --- G \n");
		printf("Equipa --- E \n");
		printf("Opcao: ");			
}


//funcao 
void MenuGestor(RegistoMembro *membros)
{  	
	// vari�veis
	int contador = 1;
	
    while (contador)
    {
        puts("---------Bem vindo..........\n");
		printf("1-Edi��o de equipas.\n");
		printf("2-Edi��o de lares\n");
		printf("3-Imprimir relatorio\n");
		printf("4-Imprimir Estatiscas\n");			
		printf("0-Menu de usuarios\n");
		printf("Op�ao: ");
        int opcao;
        scanf(" %d", &opcao);

        switch (opcao)
        {
        	case 1:
        		system("CLS");
            	MenuSubmenuEquipas(RegistoMembro *membros);
            	break;

        	case 2:
            	system("CLS");
            	MenuSubmenuLares();
            	break;

        	case 3:
            	contador = 0;  
            	break;
            
        	case 4:
        		contador = 0;
        		break;
        	
			case 0:
				system("CLS");
            	Menugeral();
            	escolha();
            
        	default:
            	printf("Escolha invalida.\n");
            	break;
        }
    }		
}


const char* escolha()
{
	char verificador;
    scanf(" %c",&verificador);
    return verificador;
}


//funcao para ver os lares com mais e menos casos
void MaisMenosCasos (int *casos, int contador)
{
	// vari�veis
	int maior = -500, menor = 500, i;
		
	for( i = 0; i < contador; i++)
	{
		if (casos[i] > maior) 	
		{
			maior = casos[i]; 
		}
	}
	
	for( i = 0; i < contador; i++)
	{
		if (casos[i] < menor)
		{
			menor = casos[i];
		}
	}
	
	if(menor != 500)
	{
		printf("O lar com mais casos t�m %d \n", maior);
		printf("\nO lar com menos casos t�m %d \n", menor); 	
	}
	else 
	{
		puts("\nNos lares inseridos n�o houve nenhum caso de Covid");	
	}
}


//funcao para ver a melhor e a pior avali�ao dos lares
void MelhorPiorAvaliacao(int *avaliacoes, int contadoravaliacao)
{
	// vari�veis
	int maior = -500, menor = 500, i;
		
	for( i = 0; i < contadoravaliacao; i++)
	{
		if (avaliacoes[i] > maior) 	
		{
			maior = avaliacoes[i]; 
		}
	}

	for( i = 0; i < contadoravaliacao; i++)
	{
		if (avaliacoes[i] < menor)
		{
			menor = avaliacoes[i];
		}
	}
	
	if(menor != 500)
	{
		printf("\nA melhor avalia��o dos lares � %d \n", maior);
		printf("\nO A pior avalia��o dos lares � %d \n", menor); 	
	}
	else 
	{
		puts("\nNos lares inseridos n�o houve nenhum caso de Covid");	
	}	
}


//funcao para calcular a percentagem
void Percentagem(int *casos, int *utentes, int contador)
{
	// vari�veis
	int i, calculo, percentagem;
	
	for( i = 0; i < contador; i++)
	{
		calculo = casos[i] * 100;
		percentagem = calculo / utentes[i];
		printf("\nA percentagem por este lar � de %d\n", percentagem);
	}
}
