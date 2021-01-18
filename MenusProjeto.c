#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <limits.h>

//Estrutura com informação da equipa
typedef struct registoMembro
{
	int ID_Equipa;
	char Nome[50];
    int contacto;
    int CC;
    char Morada[50];
    char CartaConducao[15];
    char AreaProfissional[50];
    char email[50];
}registo;

//Funcoes
void Menugeral(char *password,char *passwordgestor,char *passwordequipa);
void Verificapassgestor(char *password, char *passwordgestor,char *passwordequipa);
void Verificapassequipa(char *password, char *passwordequipa,char *passwordgestor);
void MenuGestor(char *password,char *passwordgestor,char *passwordequipa);
void Menuequipa(char *password,char *passwordgestor,char *passwordequipa);
void MenuSubmenu(char *password,char *passwordgestor,char *passwordequipa);
void MenuSubmenuEquipas(char *password, char *passwordequipa,char *passwordgestor);

int main(int argc, char *argv[]) 
{	
	setlocale(LC_ALL, "Portuguese");
	char passwordgestor[50] = "Gestor123456";	
	char passwordequipa[50] = "Equipa123456";
	char password[50];
	registo membro[1000];
	Menugeral(password,passwordgestor,passwordequipa);
}

//Menu usuario
void Menugeral(char *password,char *passwordgestor,char *passwordequipa)
{
		int opcao = 0;
		password[0] = '\0';
		puts("---------Sistema de Lares---------");
		printf("Gestor --- 1 \n");
		printf("Equipa --- 2 \n");
		printf("Opcao: ");	
		scanf("%d", &opcao);
        if(opcao == 1)
		{
			password[0] = '\0';
			Verificapassgestor(password,passwordgestor,passwordequipa);	
		}
        else if(opcao == 2)
		{
			password[0] = '\0';
			Verificapassequipa(password,passwordequipa,passwordgestor);
		}
		else 
		{
			password[0] = '\0';
			printf("Escolha invalida.\n");	
		}
}

//Verificacao pass gestor
void Verificapassgestor(char *password, char *passwordgestor,char *passwordequipa)
{
	int i;
	password[0] = '\0';
		
		printf("Password:");
    	scanf(" %s", password);
	   
		printf("\n");
		if(strcmp(password,passwordgestor) == 0)
		{
			MenuGestor(password,passwordgestor,passwordequipa);	
		}
		else
		{
			printf("Password Invalida!!\n");
			Verificapassgestor(password,passwordgestor,passwordequipa);
		}
}

//Verificacao pass equipa
void Verificapassequipa(char *password, char *passwordequipa,char *passwordgestor)
{
	int i;
	password[0] = '\0';
		
		printf("Password:");
    	scanf(" %s", password);
	   
		printf("\n");
		if(strcmp(password,passwordequipa) == 0)
		{
			Menuequipa(password,passwordequipa,passwordgestor);	
		}
		else
		{
			printf("Password Invalida!!\n");
			Verificapassequipa(password,passwordequipa,passwordgestor);
		}
}

//Menu gestor
void MenuGestor(char *password,char *passwordgestor,char *passwordequipa)
{  	
	int contador = 1;
	system("CLS");
    while (contador)
    {
        puts("---------Bem vindo..........\n");
		printf("1- Gerir dados\n");
		printf("2- Eliminar dados existentes\n");
		printf("3- Imprimir relatorio\n");
		printf("4- Imprimir Estatiscas\n");			
		printf("0- Menu de usuarios\n");
		printf("Opçao: ");
        int opcao;
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
        	system("CLS");
        	MenuSubmenu(password,passwordgestor,passwordequipa);
            break;

        case 2:
        	system("CLS");
            printf(".......	em construçao......\n");
            break;

        case 3:
        	system("CLS");
            printf(".......	em construçao......\n");
            break;
		case 0:
			system("CLS");
			Menugeral(password,passwordgestor,passwordequipa);
            break;
        default:
            printf("Escolha invalida.\n");
            break;
        }
    }
}

//Menu equipa
void Menuequipa(char *password,char *passwordequipa,char *passwordgestor)
{  	
	int contador = 1;
	int opcao;
	system("CLS");
    while (contador)
    {
        puts("---------Bem vindo..........\n");
    	printf("1 - Visualizar Agenda\n");
   		printf("2 - Requisitar Viatura\n");
    	printf("3 - Questionário sobre o Lar\n");
    	printf("4 - Realizar Realatório\n");
    	printf("5 - Imprimir Relatórios\n");
    	printf("6 - Imprimir Avaliações\n");
    	printf("0 - Menu de usuarios\n");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
        	system("CLS");
        	printf(".......	em construçao......\n");
            break;

        case 2:
        	system("CLS");
            printf(".......	em construçao......\n");
            break;

        case 3:
        	system("CLS");
            printf(".......	em construçao......\n");
            break;
		case 0:
			system("CLS");
			Menugeral(password,passwordgestor,passwordequipa);
            break;
        default:
            printf("Escolha invalida.\n");
            break;
        }
    }
}

//Sub Menu
void MenuSubmenu(char *password,char *passwordgestor,char *passwordequipa)
{
	int opcao;
    int contador  = 1;
    while (opcao)
    {
    	printf("1-Gerir dados Equipa\n");
    	printf("2-Gerir dados Lares\n");
    	printf("3-Gerir Viaturas\n");
    	printf("0-Voltar ao menu Principal\n");
    	printf("Opção:");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
        	system("CLS");
            MenuSubmenuEquipas(password,passwordgestor,passwordequipa);
            break;

        case 2:
           	system("CLS");
            break;
        case 3:
           	system("CLS");
            break;

        case 0:
           	system("CLS");
            MenuGestor(password,passwordgestor,passwordequipa);
			
        default:
            printf("Escolha invalida!\n");
            break;
        }
    }
}

// Menu acrescentar equipas
void MenuSubmenuEquipas(char *password, char *passwordgestor,char *passwordequipa)
{  
    int opcao, contador  = 1;

    while(contador)
	{
		system("cls");
		
    	printf("1-Inserir Elementos a Equipa\n");
    	printf("2-Verificar Membros de uma Equipa \n");
    	printf("3-Editar Membro de uma Equipa\n");
    	printf("0-Voltar ao menu Principal\n");
    	printf("Opção:");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        
			case 1:
            	printf("Invalid choice.\n");
				break;
				
        	case 2: 
				printf("Invalid choice.\n");
				break;
				
       		 case 3:
        		printf("Invalid choice.\n");
				break;
				
        	case 0:
           		system("CLS");
		    	MenuGestor(password,passwordgestor,passwordequipa);
            	
        	default:
        		system("CLS");
            	printf("Invalid choice.\n");
            	break;
     	}  
	 
	}
}
