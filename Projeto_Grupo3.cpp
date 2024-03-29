#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <limits.h>



// Defini��es
#define TAMAMNHO 50



//																						ESTRUTURAS
// Estrutura Data
typedef struct RegistoData
{
	int dia;
	int mes;
	int ano;
	
}Data;


// Estrutura Registo de Visita
typedef struct registoVisita
{	
	int ID_Visita;
	int ID_Equipa;
	int ID_Lar;
	Data data;
	char hora;
	
}resVisita;


// Estrutura Registo Viatura
typedef struct Viatura
{	
	int id_viatura;
	char matricula [10];
	char marca[20];
	int nLugares;
	char ativo;
	
}viatura;


// Estrutura Registo Membro da Equipa Multidisciplinar
typedef struct registoMembro
{
	int ID_Equipa;
	int id_membro;
	char Nome[50];
    int contacto;
    int CC;
    char Morada[50];
    char CartaConducao[15];
    char AreaProfissional[50];
    char email[50];
    int ativo;
    int verificador;
    
}registo;


// Estrutura Registo Equipa Multidisciplinar
typedef struct registoEquipa
{
	int id_equipa;
	char Nome[50];
	char regiao[50];
	int equipa_ativa;
		
}equipas;


// Estrutura Registo Lar
typedef struct registoLar
{
	int ID_Lar;
	char Nome[50];
	char Regiao[50];
	char Morada[50];
	int n_idosos;
	int n_idosos_risco;
	int Ativo;
	
}lares;


// Estrutura REquisitar Viaturas
typedef struct RequisitarViaturas
{
	int ID_Visita;
	int ID_Viatura;
	
}reqViatura;


// Estrutura Avalia��o da Visita
typedef struct ContaAvaliacao
{
	int ID_Equipa;
	int ID_Lar;
	int Avaliacao;
	
}contAva;


// Estrutura Relat�rio Visita
typedef struct RegistoVisita
{
	int ID_Visita;
	int ID_Lar;
	int ID_Equipa;
	char Relatorio [500];
	int N_Covid;
	int N_Testes;
	
}regVisita;



// 																						VARI�VEIS
// Arrays
registo membro[TAMAMNHO];
equipas equipa[TAMAMNHO];
lares lar[TAMAMNHO];
resVisita agenda[TAMAMNHO];
reqViatura reViaturas[TAMAMNHO];
regVisita reVisita[TAMAMNHO];
viatura Viaturas[TAMAMNHO];
contAva Avaliacao[TAMAMNHO];

// Contadores / �ndices
int ID_equipa = 0;
int ID_membro = 0;
int id_lar = 0;
int id_visita = 0;
int ID_viatura = 0, nota = 0;
int ID_Equipa_Usar;
int ID_regVisita = 0;
int ID_reqViatura = 0;

// Contadores Profissionais
int contadormed = 0;
int contadorenf = 0;
int contadorass = 0;
int contadortec = 0;

// Array para guardar o contador dos profissionais por equipa
int contadormed1[TAMAMNHO];
int contadorenf1[TAMAMNHO];
int contadorass1[TAMAMNHO];
int contadortec1[TAMAMNHO];


	
//																						ASSINATURAS
// Procedimento Menu Principal
void Menugeral(char *password,char *passwordgestor,char *passwordequipa);


// Procedimentos Verifica��o Passwords
void Verificapassgestor(char *password, char *passwordgestor,char *passwordequipa);
void Verificapassequipa(char *password, char *passwordequipa,char *passwordgestor);

// Procedimentos do Gestor
void MenuGestor(char *password,char *passwordgestor,char *passwordequipa);
void Menuequipa(char *password,char *passwordgestor,char *passwordequipa);
void MenuSubmenu(char *password,char *passwordgestor,char *passwordequipa);
void MenuSubmenuEquipas(char *password, char *passwordequipa,char *passwordgestor);
void gerirMembros(char *password, char *passwordgestor,char *passwordequipa);


// Procedimentos Avalia��o Visitas
void Questionario(char *password,char *passwordequipa,char *passwordgestor);
void ContaAvaliacao(char *password, char *passwordequipa, char *passwordgestor);


// Procedimentos Gest�o Equipas
void criarrequipas(char *password, char *passwordgestor,char *passwordequipa);
void verificarEquipas(char *password, char *passwordgestor,char *passwordequipa);
void editarEquipas(char *password, char *passwordgestor,char *passwordequipa);
void desactivarEquipas(char *password, char *passwordgestor,char *passwordequipa);


// Procedimentos Gest�o Membros
void inserirMembros(char *password, char *passwordgestor,char *passwordequipa);
void mostrarMembros(char *password, char *passwordgestor,char *passwordequipa);
void editarMembros(char *password, char *passwordgestor,char *passwordequipa);
void desativarMembros(char *password, char *passwordgestor,char *passwordequipa);


// Procedimento Gest�o Lares
void MenuSubmenuLares(char *password,char *passwordequipa,char *passwordgestor);
void adicionarlares(char *password,char *passwordequipa,char *passwordgestor);
void verificarlares(char *password,char *passwordequipa,char *passwordgestor);
void editarlares(char *password,char *passwordequipa,char *passwordgestor);
void apagarlares(char *password,char *passwordequipa,char *passwordgestor);


// Procedimentos Gest�o Agenda
void gerirAgendas(char *password,char *passwordequipa,char *passwordgestor);
void adicionarAgenda(char *password,char *passwordequipa,char *passwordgestor);
void visualizarAgenda (char *password,char *passwordequipa,char *passwordgestor);
void editarAgenda (char *password,char *passwordequipa,char *passwordgestor);


// Procedimentos Gest�o Viaturas
void gerirViaturas(char *password,char *passwordequipa,char *passwordgestor);
void adicionarViaturas(char *password,char *passwordequipa,char *passwordgestor);
void verificarViaturas(char *password,char *passwordequipa,char *passwordgestor);
void editarViaturas(char *password,char *passwordequipa,char *passwordgestor);
void desactivarViaturas(char *password,char *passwordequipa,char *passwordgestor);


// Procedimentos Chefe de Equipa
void painelchefeequipa(char *password,char *passwordequipa,char *passwordgestor);
void VerificarEquipaUtilizador(char *password,char *passwordequipa,char *passwordgestor);


// Procedimentos da Equipa
void MenuVisita(char *password,char *passwordequipa,char *passwordgestor);
void RegistarVisita(char *password,char *passwordequipa,char *passwordgestor);
void RequisitarViaturas(char *password,char *passwordequipa,char *passwordgestor);
void VerificarRelatorio(char *password,char *passwordequipa,char *passwordgestor);


// Procedimentos de Estat�sticas
void MediaAvaliacoesVisitas(char *password,char *passwordequipa,char *passwordgestor);
void ListarVisitas(char *password,char *passwordequipa,char *passwordgestor);



//																						MAIN
int main(int argc, char *argv[]) 
{	
	// Configura��es
	setlocale(LC_ALL, "Portuguese");
	
	// Vari�veis
	char passwordgestor[50] = "Gestor123456";	
	char passwordequipa[50] = "Equipa123456";
	char password[50];
	
	// Chamar pelo Procedimento com o Menu Principal
	Menugeral(password,passwordgestor,passwordequipa);
}



//																						PROCEDIMENTOS E FUN��ES
// Menu Principal
void Menugeral(char *password,char *passwordgestor,char *passwordequipa)
{
	// Vari�veis
	int opcao = 0;
	password[0] = '\0';
	
	
	do
	{
		// Escolha de Login
		system("cls");
		puts("======== Sistema de Lares =======");
		printf("|Gestor --- 1  \t\t\t|\n");
		printf("|Equipa --- 2 \t\t\t|\n");
		puts("=================================");
		printf("Op��o: ");
		
		
		// Instru��o para receber uma op��o V�lida	
		do
		{
			scanf("%d", &opcao);
			
			// Se op��o inv�lida, informa e pede uma v�lida
			if (opcao != 1 && opcao !=2)
			{
				printf("\nOp��o inv�lida, insira outra: ");
			}		
				
		} while (opcao != 1 && opcao != 2);
		
		
		// Se login Gestor chamar a fun��o X
	    if(opcao == 1)
		{
			password[0] = '\0';
			Verificapassgestor(password,passwordgestor,passwordequipa);	
		}
		
		
		// Se login Equipa chamar a fun��o Y
	    else if(opcao == 2)
		{
			password[0] = '\0';
			Verificapassequipa(password,passwordequipa,passwordgestor);
		}
		
	} while(opcao != 0);
		
}


// Verifica��o Password Gestor
void Verificapassgestor(char *password, char *passwordgestor,char *passwordequipa)
{
	// Vari�veis
	int i;
	password[0] = '\0';
	
	
	// Pede e recebe a password	
	printf("Password:");
	scanf(" %s", password);
   	puts("");
   	
   	
   	// Se password correta chama Fun��o X
	if(strcmp(password,passwordgestor) == 0)
	{
		MenuGestor(password,passwordgestor,passwordequipa);	
	}
	
	// Se password errada repete o processo
	else
	{
		printf("Password Invalida!!\n");
		Verificapassgestor(password,passwordgestor,passwordequipa);
	}
}


// Verifica��o Password Equipa
void Verificapassequipa(char *password, char *passwordequipa,char *passwordgestor)
{
	// Vari�veis
	int i;
	password[0] = '\0';
		
		
	// Pede e recebe a password	
	printf("Password:");
	scanf(" %s", password);
	puts("");
	
	   	
	// Se password correta chama Fun��o X
	if(strcmp(password,passwordequipa) == 0)
	{
		VerificarEquipaUtilizador(password,passwordequipa,passwordgestor);	
	}
	
	// Se password errada repete o processo	
	else
	{
		printf("Password Invalida!!\n");
		Verificapassequipa(password,passwordequipa,passwordgestor);
	}
}


// Menu Gestor
void MenuGestor(char *password,char *passwordgestor,char *passwordequipa)
{  	
	// Vari�veis
	int opcao, id, continuar, esta;
	
	
    do
    {
    	// Menu Gestor
    	system("cls");
        puts("========Bem vindo========");
		printf("|1- Gerir dados\t\t|\n");
		printf("|2- Imprimir relat�rio\t|\n");
		printf("|3- Imprimir Estat�scas\t|\n");			
		printf("|0- Menu de utilizador\t|\n");
		puts("=========================");
		printf("Op��o: ");
        scanf(" %d", &opcao);


        switch (opcao)
        {
	        case 1:
	        	// Gerir Dados
	        	system("CLS");
	        	MenuSubmenu(password,passwordgestor,passwordequipa);
	            break;
	
	        case 2:
	        	// Imprimir Relat�rios
	        	system("CLS");
	            VerificarRelatorio(password,passwordgestor,passwordequipa);
	            break;
	
	
	        case 3:
	        	// Imprimir Estat�sticas
	        	system("CLS");
	        
				do
				{
					ListarVisitas(password,passwordgestor,passwordequipa);
	        		MediaAvaliacoesVisitas(password,passwordgestor,passwordequipa);	        		
	        		printf("\nEstatisticas: ");
	        		scanf("%d", &esta);
	        		
				}while(esta != 0);
				
	        	//ContaAvaliacao(password,passwordgestor,passwordequipa);       	
	            break;
	            
	            
			case 0:
				// Voltar ao Menu Principal
				system("CLS");
				Menugeral(password,passwordgestor,passwordequipa);
	            break;
	            
	            
	        default:
	            printf("Escolha invalida.\n");
	            break;
        }
        
    } while(opcao != 0);
    
}


// Login Equipa
void VerificarEquipaUtilizador(char *password,char *passwordequipa,char *passwordgestor)
{
	// Vari�veis
	char continuar, entrar;
	int x;
	
	
	do
	{
		// Login Equipa
		system("CLS");
		puts("=====================================");
		printf("|Pretende entrar no menu da equipa? |\n");
		puts("=====================================");
		scanf(" %c", &entrar);
		
		
		// Continuar o Login
		if((entrar == 's') || (entrar == 'S'))
		{
			system("cls");
			printf("Equipas Dispon�veis:\n\n");
			

			// Listar equipas registadas
			if (ID_equipa > 0)
			{
				for(x = 0; x < ID_equipa; x++)
				{
					printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);	
				}
				
				
				// Escolher o ind�ce para entrar no Menu de Equipa			
				printf("\n\nInsira o ID da Equipa que est� a usar o programa: ");
				scanf("%d", &ID_Equipa_Usar);
				
				
				for(x = 0; x < ID_equipa; x++)
				{
					// Escolher o ind�ce para entrar no Menu de Equipa
					if(ID_Equipa_Usar == equipa[x].id_equipa)
					{
						system("cls");
						Menuequipa(password, passwordequipa, passwordgestor);
					}
				}				
			}
			
			// N�o h� equipas dispon�veis
			else if(ID_equipa == 0)
			{
				system("cls");
				printf("N�o h� equipas dispon�veis\n");
			}			
		}
		
		// Decis�o para voltar ao Menu principal
		printf("\nPretende voltar ao menu do Login? ");
		scanf(" %c", &continuar);
		
		
	}while((continuar == 'n') || (continuar == 'N'));
	
}


// Menu Equipa
void Menuequipa(char *password,char *passwordequipa,char *passwordgestor)
{  	
	// Vari�veis
	int opcao;
	
		
	do
	{
		// Menu Equipa
		system("CLS");
		printf("====== Bem vindo equipa %d =======\n", ID_Equipa_Usar);
		printf("|1-Gerir Lares\t\t\t|\n");
		printf("|2-Gerir Agenda\t\t\t|\n");
		printf("|3-Registar visita a Lares\t| \n");
		printf("|4-Question�rio sobre o Lar\t|\n");
		printf("|5-Imprimir Relat�rios\t\t|\n");
		printf("|6-Imprimir Avalia��es\t\t|\n");
		printf("|7-Painel de chefe equipa\t|\n");
		printf("|0-Menu de utilizador\t\t|\n");
		puts("=================================");
		printf("Op��o: ");
		scanf(" %d", &opcao);


    	switch (opcao)
    	{
        	case 1:
        		// Gerir Lares
        		system("CLS");
        		MenuSubmenuLares(password, passwordequipa, passwordgestor);
            	break;


        	case 2:
        		// Gerir Agenda
        		system("CLS");
           		gerirAgendas(password, passwordequipa, passwordgestor);
            	break;


        	case 3:
        		// Registar visitas
        		system("CLS");
            	MenuVisita(password, passwordequipa, passwordgestor);
            	break;
        
        
         	case 4:
         		// Realizar o Question�rio
        		system("CLS");
            	Questionario(password, passwordequipa, passwordgestor);
            	break;
            
            
         	case 5:
         		// Consultar Relat�rio
        		system("CLS");
            	VerificarRelatorio(password, passwordequipa, passwordgestor);
            	break;   
            
            
        	case 6:
        		// Consultar Avalia��o
        		system("CLS");
            	printf(".......	em constru�ao......\n");
            	break;
            
            
			case 7:
				// Painel Chefe Equipa
        		system("CLS");
            	painelchefeequipa(password,passwordequipa,passwordgestor);
            	break;      
            
            
        	default:
            	break;
    	}
    	
    	
	} while(opcao != 0);
	
}


// Sub Menu Gestor / Gerir Dados
void MenuSubmenu(char *password,char *passwordgestor,char *passwordequipa)
{
	// Vari�veis
	int opcao;
	
	
    do
    {
    	// Gerir Dados
    	system("cls");
    	puts("========= Gerir dados ===========");
    	printf("|1 - Gerir Equipas\t\t|\n");
    	printf("|2 - Gerir Membros Equipas\t|\n");
    	printf("|3 - Gerir Viaturas\t\t|\n");
    	printf("|0 - Voltar ao menu Principal\t|\n");
    	puts("=================================");
    	printf("Op��o:");
        scanf(" %d", &opcao);


        switch (opcao)
        {
	        case 1:
	        	// Gerir Equipas
	        	system("CLS");
	            MenuSubmenuEquipas(password,passwordgestor,passwordequipa);
	            break;
	
	
	        case 2:
	        	// Gerir Membros Equipa
	        	system("CLS");
	        	gerirMembros(password,passwordgestor,passwordequipa);
	            break;
	    
	    
	        case 3:
	        	// Gerir Viaturas
	           	system("CLS");
	           	gerirViaturas(password,passwordgestor,passwordequipa);
	            break;
	
	
	        case 0:
	        	// Voltar ao Menu Gestor
	           	system("CLS");
	            MenuGestor(password,passwordgestor,passwordequipa);
			
				
	        default:
	            printf("Escolha invalida!\n");
	            break;
        }
        
    } while(opcao != 0);
    
}


// Sub Menu Gestor / Gerir Equipas
void MenuSubmenuEquipas(char *password, char *passwordgestor,char *passwordequipa)
{  
	// Vari�veis
    int opcao;
    
    
    do
	{
		// Gerir Equipas
		system("cls");
		puts("========= Gerir Equipas =========");
		printf("|1 - Criar Equipas\t\t|\n");
    	printf("|2 - Verificar Equipas\t\t|\n");
    	printf("|3 - Editar Equipas\t\t|\n");
    	printf("|4 - Desactivar Equipas\t\t|\n");
    	printf("|0 - Voltar ao menu Principal\t|\n");
    	puts("=================================");
    	printf("Op��o:");
        scanf(" %d", &opcao);


        switch (opcao)
        {
        
        	case 1:
        		// Criar Equipas
       		 	system("cls");
        		criarrequipas(password,passwordgestor,passwordequipa);
				break;
    
    
			case 2:
				// Verificar Equipas
            	system("cls");
				verificarEquipas(password,passwordgestor,passwordequipa);
				break;
				
				
        	case 3: 
        		// Editar Equipas
				system("cls");
				editarEquipas(password,passwordgestor,passwordequipa);
				break;
				
				
       		 case 4:
       		 	// Desativar Equipas
       		 	system("cls");
       		 	desactivarEquipas(password,passwordgestor,passwordequipa);
				break;
				
		    	
        	default:
        		system("CLS");
            	break;
     	}  
	 
	 
	} while(opcao != 0);
	
}


// Sub Menu Gestor / Gerir Membros
void gerirMembros(char *password, char *passwordgestor,char *passwordequipa)
{
	// Vari�veis
	int opcao;
    
    
    do
	{
		// Gerir Membros
		system("cls");
		puts("============= Gerir Membros =============");
		printf("|1-Adicionar Membros a Equipa\t\t|\n");
    	printf("|2-Verificar Membros das Equipas\t|\n");
    	printf("|3-Editar Membros das Equipas\t\t|\n");
    	printf("|4-Desactivar Membros das Equipas\t|\n");
    	printf("|0-Voltar ao menu Principal\t\t|\n");
    	puts("=========================================");
    	printf("Op��o:");
        scanf(" %d", &opcao);


        switch (opcao)
        {
        
        	case 1:
        		// Adicionar Membros
       		 	system("cls");
        		inserirMembros(password,passwordgestor,passwordequipa);
				break;
    
    
			case 2:
				// Verificar Membros
            	system("cls");
				mostrarMembros(password,passwordgestor,passwordequipa);
				break;
				
				
        	case 3: 
        		// Editar Membros
				system("cls");
				editarMembros(password,passwordgestor,passwordequipa);
				break;
				
				
       		 case 4:
       		 	// Desativar Membros
       		 	system("cls");
       		 	desativarMembros(password,passwordgestor,passwordequipa);
				break;
		
		
        	default:
            	break;
     	}  
	 
	 
	} while(opcao != 0);
	
}


// Sub Menu Gestor / Criar Equipas
void criarrequipas(char *password, char *passwordgestor,char *passwordequipa)
{
	// Vari�veis
	int x = 0, distrito;
	char maisequipa;	
	
	
	do
	{
		// Criar Equipas
		system("cls");
		puts("========== Criar Equipa ==========");
		
		
		// Cria��o e ativa��o da equipa	
		equipa[ID_equipa].id_equipa = ID_equipa;
		equipa[ID_equipa].equipa_ativa = 1;
		
		
		// Registo do nome	
		printf("\nInsira o nome da Equipa: ");
		fflush(stdin);
		gets(equipa[ID_equipa].Nome);

	
		// Atribui��o do Distrito
		puts("\n=========================== Distritos ===========================");	
		printf("|1.Viana do Castelo\t| 7.Viseu\t\t| 13.Portalegre\t|\n");
    	printf("|2.Vila Real\t\t| 8.Guarda\t\t| 14.Lisboa\t|\n");
    	printf("|3.Bragan�a\t\t| 9.Coimbra\t\t| 15.�vora\t|\n");
    	printf("|4.Braga\t\t| 10.Castelo Branco\t| 16.Set�bal\t|\n");
    	printf("|5.Porto\t\t| 11.Leiria\t\t| 17.Bejat\t|\n");
    	printf("|6.Aveiro\t\t| 12.Santar�m\t\t| 18.Faro\t|");
    	puts("\n=================================================================");
		puts("\nEscolha o distrito que pretende atribuir a equipa: ");
		scanf("%d", &distrito);
		
		
		switch(distrito)
		{
			case 1:
				strcpy(equipa[ID_equipa].regiao, "Viana do Castelo");
			break;
			
			
			case 2:
				strcpy(equipa[ID_equipa].regiao, "Vila Real");
			break;
			
			
			case 3:
				strcpy(equipa[ID_equipa].regiao, "Bragan�a");
			break;
			
			
			case 4:
				strcpy(equipa[ID_equipa].regiao,"Braga");
			break;
			
			
			case 5:
				strcpy(equipa[ID_equipa].regiao, "Porto");
			break;
			
			
			case 6:
				strcpy(equipa[ID_equipa].regiao, "Aveiro");
			break;
			
			
			case 7:
				strcpy(equipa[ID_equipa].regiao, "Viseu");
			break;
			
			
			case 8:
				strcpy(equipa[ID_equipa].regiao, "Guarda");
			break;
			
			
			case 9:
				strcpy(equipa[ID_equipa].regiao, "Coimbra");
			break;
			
			
			case 10:
				strcpy(equipa[ID_equipa].regiao, "Castelo");
			break;
			
			
			case 11:
				strcpy(equipa[ID_equipa].regiao, "Leiria");
			break;
			
			
			case 12:
				strcpy(equipa[ID_equipa].regiao, "Santar�m");
			break;
			
			
			case 13:
				strcpy(equipa[ID_equipa].regiao, "Portalegre");
			break;
			
			
			case 14:
				strcpy(equipa[ID_equipa].regiao, "Lisboa");
			break;
			
			
			case 15:
				strcpy(equipa[ID_equipa].regiao,"�vora");
			break;
			
			
			case 16:
				strcpy(equipa[ID_equipa].regiao, "Set�bal");
			break;
			
			
			case 17:
				strcpy(equipa[ID_equipa].regiao, "Beja");
			break;
			
			
			case 18:
				strcpy(equipa[ID_equipa].regiao, "Faro");
			break;
			
			
			default:
				printf("N�o escolheu um distrito v�lido");
		}


		printf("\n\nO ID desta Equipa �: %d", equipa[ID_equipa].id_equipa);
			
		ID_equipa ++;

		printf("\n\nPretende criar mais equipas? ");
		scanf(" %c", &maisequipa);


	} while((maisequipa == 'S') || (maisequipa == 's'));

}


// Sub Menu Gestor / Verificar Equipas
void verificarEquipas(char *password, char *passwordgestor,char *passwordequipa)
{
	// Vari�veis
	char visualizar_equipas;
	int x;
	
	
	do
	{
		system("cls");		
		printf("============ Verificar Equipas ============");
		
		
		// Listar equipas ativas
		for(x = 0; x < ID_equipa; x++)
		{
			if(equipa[x].equipa_ativa == 1)
			{
				printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
			}				
		}
		
		printf("\n\nPretende continuar a visualizar as equipas?\n(S/N): ");
		scanf(" %c", &visualizar_equipas);
		
		
	} while((visualizar_equipas == 's') || (visualizar_equipas == 'S'));
	
}


// Sub Menu Gestor / Editar Equipas
void editarEquipas(char *password, char *passwordgestor,char *passwordequipa)
{
	// Vari�veis
	char editar_equipa, distrito, voltar;
	int ID_editar, opcao, x;
	
	printf("============= Editar Equipas =============");
	
	
	do
	{
		// Listar todas as equipas
		for(x = 0; x < ID_equipa; x++)
		{
			printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
		}
		
		
		printf("\n\nPretende editar alguma Equipa?\n(S/N): ");
		scanf(" %c", &editar_equipa);
		
		
		// Decis�o editar
		if ((editar_equipa == 'S') || (editar_equipa == 's'))
		{
			// Escolha da equipa para editar
			printf("\nInsira o ID da equipa que pretende editar: ");
			scanf(" %d", &ID_editar);


			do
			{
				// Editar Equipa
				system("cls");
				puts("= Editar Equipas =");
				printf("|1 --- Nome\t|");
				printf("\n|2 --- Regi�o\t|");
				printf("\n|0 --- Sair\t|\n");
				puts("=================");
				printf("\nOp��o: ");
				
				scanf("%d", &opcao);
				
				
				switch(opcao)
				{
					case 1:
						// Registo Nome da Equipa
						system("CLS");
						printf("\nNome da equipa: ");
						fflush(stdin);
						gets(equipa[ID_editar].Nome);
						break;
						
						
					case 2:
						// Registo distrito da Equipa
						system("CLS");
						puts("\n=========================== Distritos ===========================");
						printf("|1.Viana do Castelo\t| 7.Viseu\t\t| 13.Portalegre\t|\n");
    					printf("|2.Vila Real\t\t| 8.Guarda\t\t| 14.Lisboa\t|\n");
    					printf("|3.Bragan�a\t\t| 9.Coimbra\t\t| 15.�vora\t|\n");
    					printf("|4.Braga\t\t| 10.Castelo Branco\t| 16.Set�bal\t|\n");
    					printf("|5.Porto\t\t| 11.Leiria\t\t| 17.Bejat\t|\n");
    					printf("|6.Aveiro\t\t| 12.Santar�m\t\t| 18.Faro\t|");
    					puts("\n=================================================================");
						puts("\nEscolha o distrito que pretende atribuir a equipa: ");
						scanf("%d", &distrito);
						
						
						switch(distrito)
						{
							case 1:
								strcpy(equipa[ID_editar].regiao, "Viana do Castelo");
							break;
							
							
							case 2:
								strcpy(equipa[ID_editar].regiao, "Vila Real");
							break;
						
							
							case 3:
								strcpy(equipa[ID_editar].regiao, "Bragan�a");
							break;
						
							
							case 4:
								strcpy(equipa[ID_editar].regiao,"Braga");
							break;
							
							
							case 5:
								strcpy(equipa[ID_editar].regiao, "Porto");
							break;
							
							
							case 6:
								strcpy(equipa[ID_editar].regiao, "Aveiro");
							break;
							
							
							case 7:
								strcpy(equipa[ID_editar].regiao, "Viseu");
							break;
							
							
							case 8:
								strcpy(equipa[ID_editar].regiao, "Guarda");
							break;
							
							
							case 9:
								strcpy(equipa[ID_editar].regiao, "Coimbra");
							break;
							
							
							case 10:
								strcpy(equipa[ID_editar].regiao, "Castelo");
							break;
							
							
							case 11:
								strcpy(equipa[ID_editar].regiao, "Leiria");
							break;
							
							
							case 12:
								strcpy(equipa[ID_editar].regiao, "Santar�m");
							break;
							
							
							case 13:
								strcpy(equipa[ID_editar].regiao, "Portalegre");
							break;
							
							
							case 14:
								strcpy(equipa[ID_editar].regiao, "Lisboa");
							break;
							
							
							case 15:
								strcpy(equipa[ID_editar].regiao,"�vora");
							break;
							
							
							case 16:
								strcpy(equipa[ID_editar].regiao, "Set�bal");
							break;
							
							
							case 17:
								strcpy(equipa[ID_editar].regiao, "Beja");
							break;
							
							
							case 18:
								strcpy(equipa[ID_editar].regiao, "Faro");
							break;			
						}
						
						break;
						
						
					default:
						break;
				}
				
				
			} while(opcao != 0);
				
		}
		
		// Decis�o voltar atr�s
		printf("\n\nPretende voltar para o menu anterior? ");
		puts("\n\tSim---(s)\n\tN�o---(n)");
		printf("\nOp��o: ");
		scanf(" %c", &voltar);
	
		
	} while ((voltar == 'n') || (voltar == 'N'));
	
}


// Sub Menu Gestor / Desativar Equipas
void desactivarEquipas(char *password, char *passwordgestor,char *passwordequipa)
{
	// Vari�veis
	char desactivar_equipa, confirmar_desactivar, desactivar_mais;
	int id_desactivar, x = 0;
	
	
	do
	{
		system("cls");
		printf("=========== Desactivar Equipas ===========");
		printf("\n\nEquipas Disponiveis: \n");
		
		
		// Listar equipas ativas
		for(x = 0; x < ID_equipa; x++)
		{
			if(equipa[x].id_equipa == 1)
			{
				printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
			}	
		}
		
		
		printf("\n\nPretende desactivar alguma equipa?\n(S/N): ");
		scanf(" %c", &desactivar_equipa);
		
		
		// Desativar Equipa escolhida
		if((desactivar_equipa == 's') || (desactivar_equipa == 'S'))
		{
			printf("\n\nInsira o ID da Equipa que pretende desactivar: ");
			scanf("%d", &id_desactivar);
			
			printf("\n\nPretende mesmo desactivar esta Equipa?\n(S/N): ");
			scanf(" %c", &confirmar_desactivar);
			
			if((confirmar_desactivar == 's') || (confirmar_desactivar == 'S'))
			{
				equipa[id_desactivar].equipa_ativa = 0;
			}
			if((confirmar_desactivar == 'n') || (confirmar_desactivar == 'N'))
			{
				equipa[id_desactivar].equipa_ativa = 1;
			}
		}
		
		printf("\n\nPretende desactivar mais alguma equipa?\n(S/N): ");
		scanf(" %c", &desactivar_mais);
		
		
	} while((desactivar_mais == 's') || (desactivar_mais == 'S'));
}


// Sub Menu Gestor / Inserir Membro a Equipa
void inserirMembros(char *password, char *passwordgestor,char *passwordequipa)
{
	// Vari�veis
	char profissao1[50] = "medico";
	char profissao2[50] = "enfermeiro";
	char profissao3[50] = "assistente";
	char profissao4[50] = "tecnico";
	char carta, escolha, opcao, opcao5;
	int id, escolha1, x = 0;
	contadormed = 0; 
	contadorenf = 0;
	contadorass = 0;
	contadortec = 0;
		
		
 	do
	{
		system("cls");	
		puts("========== Inserir Elementos a Equipa ==========\n");
		
		// Listar equipas
		for(x = 0; x < ID_equipa; x++)
		{
			printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
		}
		
		// ativar membro
		membro[ID_membro].id_membro = ID_membro;
		membro[ID_membro].ativo = 1;
		
		puts("\n\nInsira o ID da equipa a que pretende adicionar o membro: ");
		scanf("%d", &id);
		
		// inserir o membro � equipa selecionada
		membro[ID_membro].ID_Equipa = id;	
		
		system("cls");
		
		// Registo do nome
		printf("\nNome do novo membro: ");
		fflush(stdin);
		gets(membro[ID_membro].Nome);
		
		
		printf("\n�rea Profissional: ");
		printf("\n\t1 -- Medico\n\t2 -- Enfermeiro\n\t3 -- Assistente social\n\t4 --  Tecnico");
		printf("\nOp��o: ");
		scanf(" %d", &escolha1);
		
		
		// Registo da profiss�o
		if(escolha1 == 1)
		{
			strcpy(membro[ID_membro].AreaProfissional, profissao1);
			contadormed++;
		} 
		else if(escolha1 == 2)
		{
			strcpy(membro[ID_membro].AreaProfissional, profissao2);
			contadorenf++;
		}
		else if(escolha1 == 3)
		{
			strcpy(membro[ID_membro].AreaProfissional, profissao3);
			contadorass++;
		}
		else if(escolha1 == 4)
		{
			strcpy(membro[ID_membro].AreaProfissional, profissao4);
			contadortec++;
		}
		else
		{
			printf("Escolha Invalida");	
		}
			
		// Registo do Contacto	
		printf("\nContacto: ");
		scanf("%d", &membro[ID_membro].contacto);
			

		// Registo do CC
		printf("\nCart�o de cidad�o: ");
		scanf("%d", &membro[ID_membro].CC);
	

		// Registo da morada
		printf("\nMorada: ");
		fflush(stdin);
		gets(membro[ID_membro].Morada);
	
	
		// Registo do mail		
		printf("\nEmail: ");
		fflush(stdin);
		gets(membro[ID_membro].email);
		
		
		// Decis�o se � chefe de equipa
		printf("\nEste membro � chefe de equipa?\n(s/n): ");
		fflush(stdin);
		scanf(" %c", &escolha);
		
		if((escolha = 's') || (escolha = 'S'))
		{
			membro[ID_membro].verificador = 1;
		}
		
		else if((escolha = 'n') || (escolha = 'N'))
		{
			membro[ID_membro].verificador = 0;
		}


		// Registo da Carta de Condu��o
		printf("\nPossui Carta de Condu��o: ");
		printf("\n\tSim---(s)\n\tN�o---(n)");
		printf("\nOp��o: ");
		scanf(" %c", &carta);
	
		if((carta == 's') || (carta == 'S'))
		{
			printf("\nInsira o Numero da Carta de Condu��o: ");
			fflush(stdin);
			gets(membro[ID_membro].CartaConducao);
		}
		
		else if((carta == 'n') || (carta == 'N'))
		{
			strcpy(membro[ID_membro].CartaConducao, "N�o possui carta de condu��o");
		}
		
		
		// Guardar informa��es do membro e a sua profiss�o
		ID_membro++;
		
		contadormed1[id] += contadormed;
		contadorenf1[id] += contadorenf;
		contadorass1[id] += contadorass;
		contadortec1[id] += contadortec;

		
		printf("\n\nPretende adicionar mais membros a alguma equipa?\n(S/N): ");
		scanf(" %c", &opcao5);
	
	
	} while((opcao5 == 'S') || (opcao5 == 's'));
	
	
	
	if((opcao5 == 'n')||(opcao5 == 'N'))
	{
		// Gerir membros apenas se tiver um profissional de cada �rea
		if(contadormed1[id] >= 1 && contadorenf1[id] >= 1 && contadorass1[id] >= 1 && contadortec1[id] >= 1)
		{
			gerirMembros(password,passwordgestor,passwordequipa);
		}
		// Caso n�o tenho um profissional de cada �rea vai para o menu de inserir membros
		else
		{
			inserirMembros(password,passwordgestor,passwordequipa);
			printf("\n\nA equipa tem obrigatoriamente de ter um profissional de cada �rea!");
		}
	}	
}


// Sub Menu Gestor / Mostrar Membros
void mostrarMembros(char *password, char *passwordgestor,char *passwordequipa)
{
	
	int i,k, opcao4, identificador;
	char opcao5, ver_dados, opcao3;
	
	
	do
	{
		system("cls");
		
		// Listar todas as equipas
		for(x = 0; x < ID_equipa; x++)
		{
			printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
		}
		
		
		printf("Insira o ID da equipa\n");
		scanf("%d", &identificador);
		
		
		// Listar todos os Membros
		for(k = 0; k < ID_membro; k++)
		{
			if((membro[k].ID_Equipa == identificador) && (membro[k].ativo == 1))
			{
				if(strcmp(membro[k].AreaProfissional, "medico") == 0)
				{
					printf("\n%d --- %s --- M�dico", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, "enfermeiro") == 0)
				{
					printf("\n%d --- %s --- Enfermeiro", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, "assitente") == 0)
				{
					printf("\n%d --- %s --- Assistente social", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, "tecnico") == 0)
				{
					printf("\n%d --- %s --- Tecnico Saude Ambiental", membro[k].id_membro ,&membro[k].Nome);
				}
			}
		}
		
		
		printf("\n\nPretende ver os dados relativos a algum membro?\n(S/N): ");
		scanf(" %c", &ver_dados);
		
		
		// Visualizar informa��es de um Membro
		if((ver_dados == 's') || (ver_dados == 'S'))
		{
			printf("\n\nInsira o ID do membro que pretende visualizar: ");
			scanf("%d", &opcao4);
			
			system("cls");
					
			printf("O elemento %s, pertencente � Equipa com o ID %d, cont�m os seguintes dados: ", membro[opcao4].Nome, identificador);	
    		
			printf("\n\n�rea Profissional: %s", membro[opcao4].AreaProfissional);
			
   			printf("\nContacto: %d", membro[opcao4].contacto);
   			
   			printf("\nCart�o de Cidad�o: %d", membro[opcao4].CC);
   			
    		printf("\nMorada: %s", &membro[opcao4].Morada);
    		
    		printf("\nEmail: %s", &membro[opcao4].email);
    		
    		printf("\nCarta de Condu��o: %s", &membro[opcao4].CartaConducao);
    	
    		if(membro[opcao4].ativo == '1')
			{
				printf("\nEste membro encontra-se: Ativo");
			}
			if(membro[opcao4].ativo == '0')
			{
				printf("\nEste membro encontra-se: Inativo");
			}
		}

		printf("\n\nQuer visualizar os dados de outro membro?\n(S/N): ");
		scanf(" %c", &opcao3);
		
			
	}while((opcao3 == 'S') || (opcao3 == 's'));

}
		

// Sub Menu Gestor / Editar Membros	
void editarMembros(char *password, char *passwordgestor,char *passwordequipa)
{
	// Vari�veis
	int i, k, opcao2, opcao6, x, ID_editar, carta1, escolha1, identificador;
	char opcao5, editar_membro, opcao;
	char nome[50];
	char profissao1[50] = "medico";
	char profissao2[50] = "enfermeiro";
	char profissao3[50] = "assistente";
	char profissao4[50] = "tecnico";
	
	
	do
	{
		puts("========== Editar Membro da equipa ==========\n");
		
		
		// Listar Equipas
		for(x = 0; x < ID_equipa; x++)
		{
			printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
		}
		
		printf("\n\nInsira o ID da equipa: ");
    	scanf("%d", &identificador);
    	
    	
    	// Listar Membros da Equipa
    	for(k = 0; k < ID_membro; k++)
		{
			if(membro[x].ID_Equipa == identificador)
			{
				if(strcmp(membro[k].AreaProfissional, "medico") == 0)
				{
					printf("\n%d --- %s --- M�dico", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, "enfermeiro") == 0)
				{
					printf("\n%d --- %s --- Enfermeiro", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, "assitente") == 0)
				{
					printf("\n%d --- %s --- Assistente social", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, "tecnico") == 0)
				{
					printf("\n%d --- %s --- Tecnico Saude Ambiental", membro[k].id_membro ,&membro[k].Nome);
				}
			}
		}
    	
    	printf("\n\nPretende editar algum elemento?\n(S/N): ");
    	scanf(" %c", &editar_membro);
    	
    	if ((editar_membro == 'S') || (editar_membro == 's'))
		{
			printf("\nInsira o ID do membro que pretende editar: ");
			scanf(" %d", &ID_editar);
			
			
			do
			{
				// Editar Membro
				puts("===== Editar Membro =====");
				printf("|1 -- Nome\t\t|");
				printf("\n|2 -- �rea Profissional\t|");
				printf("\n|3 -- Contacto\t\t|");
				printf("\n|4 -- Cart�o de Cidad�o\t|");
				printf("\n|5 -- Morada\t\t|");
				printf("\n|6 -- Email\t\t|");
				printf("\n|7 -- Carta\t\t|");
				printf("\n|0 -- Sair\t\t|");
				printf("=========================\n");
				printf("\nOpcao: ");
				
				scanf("%d", &opcao6);
				
				switch(opcao6)
				{
					case 1:
						// Editar Nome
						printf("\nNome do membro: ");
    					fflush(stdin);
    					gets(membro[ID_editar].Nome);
						break;
						
						
					case 2:
						// Editar �rea profissional
						printf("\n�rea Profissional: ");
    					printf("\n\t1 -- Medico\n2 -- Enfermeiro\n3 -- Assistente social\n4 --  Tecnico");
    					printf("\nOp��o: ");
    					scanf(" %d", &escolha1);
    					
    					if(escolha1 == 1)
						{
							strcpy(membro[ID_editar].AreaProfissional, profissao1);
						}
						else if(escolha1 == 2)
						{
							strcpy(membro[ID_editar].AreaProfissional, profissao2);
						}
						else if(escolha1 == 3)
						{
							strcpy(membro[ID_editar].AreaProfissional, profissao3);
						}
						else if(escolha1 == 4)
						{
							strcpy(membro[ID_editar].AreaProfissional, profissao4);
						}
						else
						{
							printf("Escolha Invalida");	
						}
						break;
						
						
					case 3:
						// Editar Contacto
						printf("\nContacto: ");
   						scanf("%d", &membro[ID_editar].contacto);
						break;
						
						
					case 4:
						// Editar CC
						printf("\nCart�o de cidad�o: ");
   						scanf("%d", &membro[ID_editar].CC);
						break;
						
						
					case 5:
						// Editar Morada
						printf("\nMorada: ");
    					fflush(stdin);
    					gets(membro[ID_editar].Morada);
						break;
						
						
					case 6:
						// Editar Email
						printf("\nEmail: ");
    					fflush(stdin);
    					gets(membro[ID_editar].email);
						break;
						
						
					case 7:
						// Editar Carta de Condu��o
						printf("\nPossui Carta de Condu��o: ");
    					printf("\n\tSim---(s)\n\tN�o---(n)");
    					printf("\nOp��o: ");
    					scanf(" %c", &carta1);
    	
						if((carta1 == 's') || (carta1 == 'S'))
						{
							printf("\nInsira o Numero da Carta de Condu��o: ");
							fflush(stdin);
    						gets(membro[ID_editar].CartaConducao);
						}
						else if((carta1 == 'n') || (carta1 == 'N'))
						{
							strcpy(membro[ID_membro].CartaConducao, "N�o possui carta de condu��o");
						}
						break;						
				}
			
				
			}while(opcao6 != 0);
				
		}

		printf("\n\nPretende editar mais algum Membro?");
		puts("\n\tSim---(s)\n\tN�o---(n)");
		printf("\nOp��o: ");
		scanf(" %c", &opcao);
	
	
	}while(opcao == 'S' || opcao == 's');

}


// Sub Menu Gestor / Desativar Membros
void desativarMembros(char *password, char *passwordgestor,char *passwordequipa)
{
	int identificador, k, opcao4, x = 0;
	char desactivar_membro, opcao;
	
	
	do
	{
		puts("========== Desativar Membro da equipa ==========\n");
		
		
		// Listar Equipas Ativas
		for(x = 0; x < ID_membro; x++)
		{
			if(equipa[x].equipa_ativa == 1)
			{
				printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
			}			
		}
		
		
		printf("Insira o ID da equipa\n");
    	scanf("%d", &identificador);
    	
    	
    	// Listar todos os Membros
		for(k = 0; k < ID_membro; k++)
		{
			if((membro[k].ID_Equipa == identificador) && (membro[k].ativo == 1))
			{
				if(strcmp(membro[k].AreaProfissional, "medico") == 0)
				{
					printf("\n%d --- %s --- M�dico", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, "enfermeiro") == 0)
				{
					printf("\n%d --- %s --- Enfermeiro", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, "assitente") == 0)
				{
					printf("\n%d --- %s --- Assistente social", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, "tecnico") == 0)
				{
					printf("\n%d --- %s --- Tecnico Saude Ambiental", membro[k].id_membro ,&membro[k].Nome);
				}
			}
		}
			
				
		printf("\n\nPretende desactivar algum membro?\n(S/N)");
		scanf(" %c", &desactivar_membro);
		
		
		// Desativar Membro
		if((desactivar_membro == 's') || (desactivar_membro == 'S'))
		{
			printf("\nInsira o ID do membro que pretende desactivar: ");
			scanf("%d", &opcao4);
			
			membro[opcao4].ativo = 0;
		}
		
		puts("Pretende remover algum Membro de outra equipa?\n(S/N)");
		puts("\tSim---(s)\n \tN�o---(n)");
		scanf(" %c", &opcao);


	} while((opcao == 'S') || (opcao == 's'));
}


// Sub Menu Gestor / Mostrar Membros
void MenuSubmenuLares(char *password,char *passwordequipa,char *passwordgestor)
{
	int opcao;
	
  	do
    {
		system("cls");
		puts("========== Gerir Lares ==========");
		printf("|1 - Adicionar Lares\t\t|\n");
		printf("|2 - Verificar Lares Existentes\t|\n");
		printf("|3 - Editar Lares Existentes\t|\n");
		printf("|4 - Desactivar Lares\t\t|\n");
		printf("|0 - Voltar ao menu Principal\t|\n");
		puts("=================================\n");
		printf("\nOp��o: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				system("CLS");
				adicionarlares(password,passwordequipa,passwordgestor);
			break;
			
			case 2:
				system("CLS");
				editarlares(password,passwordequipa,passwordgestor);
			break;
			
			case 3:
				system("CLS");
				verificarlares(password,passwordequipa,passwordgestor);
			break;
			
			case 4:
				system("CLS");
				apagarlares(password,passwordequipa,passwordgestor);
			break;
			
			case 0:
				system("CLS");
				Menuequipa(password,passwordequipa,passwordgestor);	
			break;
			
		 default:
            printf("Escolha invalida!\n");
            break;
        }	

	}while(opcao != 0);
}


void adicionarlares(char *password,char *passwordequipa,char *passwordgestor)
{

	char adicionar_lares;
	int distrito;
			
	do
	{
		system("cls");
		printf("========== Adicionar Lares ==========");
					
		lar[id_lar].ID_Lar = id_lar;
					
		printf("\n\nNome do lar: ");
		fflush(stdin);
        gets(lar[id_lar].Nome);
        
        strcpy(lar[id_lar].Regiao, equipa[ID_Equipa_Usar].regiao);
        			
        printf("\nMorada do Lar: ");
		fflush(stdin);
        gets(lar[id_lar].Morada);
        
        printf("\nInsira o n�mero de idosos do lar: ");
        scanf("%d", &lar[id_lar].n_idosos);
        
        printf("\nInsira o n�mero de idosos de risco do lar (Idosos com mais de 65 anos): ");
        scanf("%d", &lar[id_lar].n_idosos_risco);
					
		lar[id_lar].Ativo = 1;
		id_lar ++;
					
		printf("\n\nPretende adicionar mais lares? (S/N)");
		scanf(" %c", &adicionar_lares);
		
	}while((adicionar_lares == 's') || (adicionar_lares == 'S'));
}


void editarlares(char *password,char *passwordequipa,char *passwordgestor)
{
	
	int k;
	char verificar_lares;
	int escolha_lar;
	char verificar_mais;
	
	do
	{
		system("cls");
		printf("========== Verificar Lares ==========");
		printf("\n\nLares Disponiveis: \n");
					
		for(k = 0; k < id_lar; k++)
		{
			if(lar[k].Ativo == 1)
			{
				printf("\n[%d] --- %s --- %s", lar[k].ID_Lar, lar[k].Nome, lar[k].Regiao);
			}
			
		}
					
		printf("\n\nPretende visualizar os dados de algum dos Lares?\n(S/N): ");
		scanf(" %c", &verificar_lares);
					
		if((verificar_lares == 's') || (verificar_lares == 'S'))
		{
			printf("\nInsira o ID do Lar que pretende visualizar: ");
			scanf("%d", &escolha_lar);
						
			printf("\nNome: %s", lar[escolha_lar].Nome);
						
			printf("\nRegi�o: %s", lar[escolha_lar].Regiao);
						
			printf("\nMorada: %s", lar[escolha_lar].Morada);
						
			if(lar[escolha_lar].Ativo == 1)
			{
				printf("\nEste lar encontra-se: Ativo");
			}
			else if (lar[escolha_lar].Ativo == 0)
			{
				printf("\nEste lar encontra-se: Inativo");
			}
							
			}
					
			printf("\n\nPretende voltar a verificar os Lares?\n(S/N): ");
			scanf(" %c", &verificar_mais);
			}
			while((verificar_mais == 's') || (verificar_mais == 'S'));
}


void verificarlares(char *password,char *passwordequipa,char *passwordgestor)
{
	int k;
	char editar_lar;
	int id_editar,opcao_editar, distrito;
	char voltar_editar;
				
	do
	{
		system("cls");
		printf("========== Editar Lares ==========");
		printf("\n\nLares Disponiveis: \n");
		
		for(k = 0; k < id_lar; k++)
		{
			if(lar[k].Ativo == 1)
			{
				printf("\n[%d] --- %s --- %s", lar[k].ID_Lar, lar[k].Nome, lar[k].Regiao);
			}
			
		}
		
		printf("\n\nPretende editar a informa��o de algum lar?\n(S/N): ");
		scanf(" %c", &editar_lar);
		
		if((editar_lar == 's') || (editar_lar == 'S'))
		{
			printf("\nInsira o ID do lar que pretende editar: ");
			scanf("%d", &id_editar);
			
			do
			{
				printf("\n\nInsira que campo pretende editar: ");
				puts("= Editar Equipas=");
				printf("|1 --- Nome\t|");
				printf("\n|2 --- Regi�o\t|");
				printf("\n|3 --- Morada\t|");
				printf("\n|0 --- Sair\t|\n");
				puts("=================");
				printf("\nOpc�o: ");
				scanf("%d", &opcao_editar);
				
				switch(opcao_editar)
				{
					case 1:
						printf("\nNome do lar: ");
						fflush(stdin);
						gets(lar[id_editar].Nome);
						break;
					case 2:
						system("CLS");
						puts("\n=========================== Distritos ===========================");
						printf("|1.Viana do Castelo\t| 7.Viseu\t\t| 13.Portalegre\t|\n");
    					printf("|2.Vila Real\t\t| 8.Guarda\t\t| 14.Lisboa\t|\n");
    					printf("|3.Bragan�a\t\t| 9.Coimbra\t\t| 15.�vora\t|\n");
    					printf("|4.Braga\t\t| 10.Castelo Branco\t| 16.Set�bal\t|\n");
    					printf("|5.Porto\t\t| 11.Leiria\t\t| 17.Bejat\t|\n");
    					printf("|6.Aveiro\t\t| 12.Santar�m\t\t| 18.Faro\t|");
    					puts("\n=================================================================");
						printf("\nRegi�o onde se encontra o Lar: ");
						scanf("%d", &distrito);
						
						switch(distrito)
						{
							case 1:
								strcpy(lar[id_editar].Regiao, "Viana do Castelo");
							break;
							
							case 2:
								strcpy(lar[id_editar].Regiao, "Vila Real");
							break;
							
							case 3:
								strcpy(lar[id_editar].Regiao, "Bragan�a");
							break;
							
							case 4:
								strcpy(lar[id_editar].Regiao,"Braga");
							break;
							
							case 5:
								strcpy(lar[id_editar].Regiao, "Porto");
							break;
							
							case 6:
								strcpy(lar[id_editar].Regiao, "Aveiro");
							break;
							
							case 7:
								strcpy(lar[id_editar].Regiao, "Viseu");
							break;
							
							case 8:
								strcpy(lar[id_editar].Regiao, "Guarda");
							break;
							
							case 9:
								strcpy(lar[id_editar].Regiao, "Coimbra");
							break;
							
							case 10:
								strcpy(lar[id_editar].Regiao, "Castelo");
							break;
							
							case 11:
								strcpy(lar[id_editar].Regiao, "Leiria");
							break;
							
							case 12:
								strcpy(lar[id_editar].Regiao, "Santar�m");
							break;
							
							case 13:
								strcpy(lar[id_editar].Regiao, "Portalegre");
							break;
							
							case 14:
								strcpy(lar[id_editar].Regiao, "Lisboa");
							break;
							
							case 15:
								strcpy(lar[id_editar].Regiao,"�vora");
							break;
							
							case 16:
								strcpy(lar[id_editar].Regiao, "Set�bal");
							break;
							
							case 17:
								strcpy(lar[id_editar].Regiao, "Beja");
							break;
							
							case 18:
								strcpy(lar[id_editar].Regiao, "Faro");
							break;
							
							default:
								printf("N�o escolheu um distrito v�lido");
						}
						break;
					case 3:
						printf("\nMorada do Lar: ");
						fflush(stdin);
						gets(lar[id_editar].Morada);
						break;
						
				}
			}
			while(opcao_editar != 0);
		}
		
		printf("Prentende voltar a editar algum lar?\n(S/N): ");
		scanf("%c", &voltar_editar);
		
	}
	while((voltar_editar == 's') || (voltar_editar == 'S'));
}


void apagarlares(char *password,char *passwordequipa,char *passwordgestor)
{
	int k;
	char desactivar_lar;
	int id_desactivar; 
	char confirmar_desactivar,desactivar_mais;
	
				do
				{
					system("cls");
					printf("========== Desactivar Lares ==========");
					printf("\n\nLares Disponiveis: \n");
					
					for(k = 0; k < id_lar; k++)
					{
						if(lar[k].Ativo == 1)
						{
							printf("\n[%d] --- %s --- %s", lar[k].ID_Lar, lar[k].Nome, lar[k].Regiao);
						}
			
					}
					
					printf("\n\nPretende desactivar algum lar?\n(S/N): ");
					scanf(" %c", &desactivar_lar);
					
					if((desactivar_lar == 's') || (desactivar_lar == 'S'))
					{
						printf("\n\nInsira o ID do lar que pretende desactivar: ");
						scanf("%d", &id_desactivar);
						
						printf("\n\nPretende mesmo desactivar este Lar?\n(S/N): ");
						scanf(" %c", &confirmar_desactivar);
						
						if((confirmar_desactivar == 's') || (confirmar_desactivar == 'S'))
						{
							lar[id_desactivar].Ativo = 0;
						}
						if((confirmar_desactivar == 'n') || (confirmar_desactivar == 'N'))
						{
							lar[id_desactivar].Ativo = 1;
						}
					}
					
					printf("\n\nPretende desactivar mais algum lar?\n(S/N): ");
					scanf(" %c", &desactivar_mais);
				}while((desactivar_mais == 's') || (desactivar_mais == 'S'));
}


void gerirAgendas(char *password,char *passwordequipa,char *passwordgestor)
{
	int opcao;
	
	do
	{
		system("cls");
					
		puts("");			
		puts("================= Gerir Agendas =================");
		printf("|\t1-Adicionar dados a Agenda\t\t|\n");
    	printf("|\t2-Visualizar Agenda de uma equipa\t|\n");
    	printf("|\t3-Editar Agenda de uma equipa\t\t|\n");
    	printf("|\t0-Voltar ao Menu Principal\t\t|\n");
    	puts("=================================================");
    	printf("\nOp��o:");
    	scanf(" %d", &opcao);
    	
    	switch(opcao)
		{
			case 1:
				adicionarAgenda(password, passwordequipa, passwordgestor);
				break;
			case 2:
				visualizarAgenda(password, passwordequipa, passwordgestor);
				break;
			case 3:
				editarAgenda(password, passwordequipa, passwordgestor);
				break;
			default:
				break;
		}
		
	}while(opcao != 0);
}


void adicionarAgenda(char *password,char *passwordequipa,char *passwordgestor)
{
	char dados_agenda;
	int x;
	
	do
	{
		system ("cls");
		printf("========== Adicionar dados a agenda ==========");
					
		agenda[id_visita].ID_Visita = id_visita;
					
		for(x = 0; x < ID_equipa; x ++)
		{
			printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
		}
							
		printf("\n\nInsira a que equipa pretende adicionar dados a agenda: ");
		scanf("%d", &agenda[id_visita].ID_Equipa);
					
		for(x = 0; x < id_lar; x ++)
		{
			printf("\n[%d] --- %s --- %s", lar[x].ID_Lar, lar[x].Nome, lar[x].Regiao);
		}			
					
		printf("\n\nInsira o Lar que a equipa ter� de visitar: ");
		scanf("%d", &agenda[id_visita].ID_Lar);
					
		printf("\nInsira a hora da visita: ");
		scanf("%s", &agenda[id_visita].hora);
					
		printf("\nInsira o dia da visita: ");
		scanf("%s", &agenda[id_visita].data.dia);
					
		printf("\nInsira o m�s da visita: ");
		scanf("%s", &agenda[id_visita].data.mes);
					
		printf("\nInsira o ano da visita: ");
		scanf("%s", &agenda[id_visita].data.ano);
					
		id_visita++;
					
		printf("\n\nPretende adicionar mais alguma visita? ");
		scanf(" %c", &dados_agenda);
	
	}
	while((dados_agenda == 's')||(dados_agenda == 'S'));
}


void visualizarAgenda (char *password,char *passwordequipa,char *passwordgestor)
{
	int opcao, opcao1;
	int j;
	puts("========== Visualizar Agenda ==========");
	do
	{	
		
		printf("\nInsira o ID da equipa a que pretende ver a agenda: ");
		scanf(" %d", &opcao);
		
		puts("\n[ID] --- Equipa ---> Lar");
		
		for(j = 0; j < id_visita; j++)
		{
			if(agenda[j].ID_Equipa == opcao)
			{
				printf("\n%d --- %d ---> %d", agenda[j].ID_Visita , agenda[j].ID_Equipa, agenda[j].ID_Lar);
			}
		}
		
		printf("\n\nInsira 0 para voltar atras: ");
		scanf("%d", &opcao1);
	}
	while(opcao1 != 0);
}


void editarAgenda (char *password,char *passwordequipa,char *passwordgestor)
{
	int x = 0, n;
	int opcao3, opcao4, opcao5;
	char alterar_agenda;
	puts("========== Editar Agenda ==========");
	do
	{	
		for(x = 0; x < ID_equipa; x ++)
		{
			printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
		}
		
		printf("\n\nInsira o ID da equipa a que pretende ver a agenda: ");
		scanf(" %d", &opcao3);
		
		//mostrar todas as visitas marcadas
		for(x = 0; x < id_visita; x++)
		{
			if(agenda[x].ID_Equipa == opcao3)
			{
				printf("\n%d --- %d ---> %d", agenda[x].ID_Visita , agenda[x].ID_Equipa, agenda[x].ID_Lar);
			}
		}
		
		printf("\n\nPretende alterar alguma marca��o apresentada? ");
		scanf(" %c", &alterar_agenda);
		
		if((alterar_agenda == 's') || (alterar_agenda == 'S'))
		{
			//pedir qual marca��o pretende mudar
			printf("\nInsira o ID da marca��o que pretende alterar: ");
			scanf("%d", &opcao4);
			
			//encontrar a marca��o
			for(x = 0; x < id_visita; x++)
			{
				if(agenda[x].ID_Visita == opcao4)
				{
					n = x;
				}
			}
			
			do
			{
				//menu para escolher a informa��o que pretende mudar
				system("cls");
				printf("========== Edi��o Agenda ==========");
				printf("|n\n1- ID da Equipa Responsavel");
				printf("\n2- ID do Lar a que vai ser realizada a visita");
				printf("\n3 - Horas");
				printf("\n4- Dia");
				printf("\n5- Mes");
				printf("\n6- Ano");
				printf("\n0-Sair");
				printf("\n\nOpcao: ");
				
				scanf("%d", &opcao5);
				
				//switch para recolher a escolha 	
				switch(opcao5)
				{
					case 1: 
						//mostrar todas as equipas
						printf("Insira o ID da Equipa responsavel: ");
						scanf("%d", &agenda[n].ID_Equipa);
						break;
						
					case 2:
						//mostrar todos os lares
						printf("ID do Lar a que vai ser realizada a visita: ");
						scanf("%d", &agenda[n].ID_Lar);
						break;
						
					case 3:
						printf("Insira as horas da consulta: ");
						scanf("%s", &agenda[n].hora);
						break;
						
					case 4:
						printf("Insira o dia da consulta: ");
						scanf("%d", &agenda[n].data.dia);
						break;
						
					case 5:
						printf("Insira o m�s da consulta: ");
						scanf("%d", &agenda[n].data.mes);
						break;
						
					case 6:
						printf("Insira o ano da visita: ");
						scanf("%d", &agenda[n].data.ano);
						break;
						
					default:
						break;	
						
				}
			} 
			while(opcao5 != 0);
		}
		
		printf("\n\nInsira 0 para voltar atras: ");
		scanf("%d", &opcao3);
		
	}while(opcao3 != 0);
}


void gerirViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	int opcao;
	
	do
	{
		system("cls");
		
    	puts("======== Gerir Viaturas =========");
    	printf("|1-Inserir Viaturas\t\t|\n");
    	printf("|2-Verificar Viaturas inseridas|\n");
    	printf("|3-Editar uma viatura\t\t|\n");
    	printf("|4-Desativar viatura\t\t|\n");
    	printf("|0-Voltar ao menu Principal\t|\n");
    	puts("=================================");
    	printf("Op��o:");
        scanf(" %d", &opcao);
        
        switch(opcao)
		{
			case 1:
				adicionarViaturas(password, passwordequipa, passwordgestor);
				break;
				
			case 2:
				verificarViaturas(password, passwordequipa, passwordgestor);
				break;
				
			case 3:
				editarViaturas(password, passwordequipa, passwordgestor);
				break;
				
			case 4:
				desactivarViaturas(password, passwordequipa, passwordgestor);
				break;
		}
	}
	while(opcao != 0 );
}


void adicionarViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	char opcao;
	
	do
	{
		system("cls");
		
		puts("========== Inserir viaturas ==========\n");
		Viaturas[ID_viatura].id_viatura = ID_viatura;
		Viaturas[ID_viatura].ativo = '1';
		
		printf("\nMarca do carro:");
		fflush(stdin);
		gets(Viaturas[ID_viatura].marca);
		
		printf("\nMatricula (AA-AA-AA): ");
		fflush(stdin);
		gets(Viaturas[ID_viatura].matricula);
			
		printf("\nN�mero de lugares: ");
		scanf("%d", &Viaturas[ID_viatura].nLugares);
		         			   			
		ID_viatura++;
		
		puts("Pretende inserir mais alguma viatura?");
		puts("\tSim---(s)\n \tN�o---(n)");
		scanf(" %c", &opcao);
		
	
	}while(opcao == 'S' || opcao == 's');
	
}


void verificarViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	int opcao3, k;
	int opcao4;
	do
	{
		system("cls");
		puts("========== Verificar Viaturas ==========");
		
		for(k = 0; k < ID_viatura; k++)
		{
			if(Viaturas[k].ativo == 1)
			{
				printf("\n[%d] --- %d --- %s --- %s", Viaturas[k].id_viatura, Viaturas[k].nLugares ,Viaturas[k].marca, Viaturas[k].matricula);
			}
			
			
		}
			
		printf("\n\nPretende ver os dados relativos a que viatura?");
		scanf("%d", &opcao4);
			
			
					
		printf("\n\nA viatura da marca %s, com o ID %d, cont�m os seguintes dados: ", Viaturas[opcao4].marca, opcao4);        		
		            		
        printf("\nMatricula: %s", &Viaturas[opcao4].matricula);
		
		printf("N�mero de lugares %d\n", Viaturas[opcao4].nLugares);
	
	
		if(Viaturas[opcao4].ativo == '0')
		{
			puts("O veiculo est� Inativo");
		}
		if(Viaturas[opcao4].ativo == '1')
		{
			puts("O veiculo est� Ativo");
		}
			

		printf("\n\nPretende vizualisar mais alguma viatura?");
		printf("(S)---sim\t(N)---n�o");
		scanf(" %c", &opcao3);
			
	}while(opcao3 == 's' || opcao3 == 'S');	
}


void editarViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	int k, identificador, escolha;
	char opcao;
	
	do
	{	
		puts("========== Editar viaturas ==========\n");
		for(k = 0; k < ID_viatura; k++)
		{
			if(Viaturas[k].ativo == 1)
			{
				printf("\nN� Lugares %d --- %s --- %s", Viaturas[k].nLugares , Viaturas[k].matricula, Viaturas[ID_viatura].marca);
			}
			
				
		}
		
		printf("Insira o ID da viatura\n");
    	scanf("%d", &identificador);
    	puts("1.Marca\n2.Matricula\n3.Lugares");
    	scanf("%d", &escolha);
    	
    	switch(escolha)
		{
		 	case 1:
		 		printf("Marca do carro:\n");
				fflush(stdin);
				gets(Viaturas[identificador].marca);
		 		break;					                     		
		 
		 	case 3:
		 		printf("Matricula:\n");
				fflush(stdin);
				gets(Viaturas[identificador].matricula);
		 		break;
		 
		 	case 6:
		    	printf("N�mero de lugares\n");
				scanf("%d", &Viaturas[identificador].nLugares);
		 		break;
		 
		 						
		}
	
		puts("Pretende editar mais alguma viatura?");
		puts("\n\tSim---(s)\n \tN�o---(n)");
		scanf(" %c", &opcao);
	
	}while(opcao == 'S' || opcao == 's');
}


void desactivarViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	int identificador, k;
	char opcao;
	
	do
	{	
		system ("cls");
		puts("========== Desativar Viatura ==========\n");
		for(k = 0; k < ID_viatura; k++)
		{

			printf("N� Lugares %d --- %s --- %s", Viaturas[k].nLugares , Viaturas[k].matricula, Viaturas[ID_viatura].marca);
				
		}
		printf("Insira o ID da viatura\n");
    	scanf("%d", &identificador);
		
		Viaturas[identificador].ativo = '0';		        					
	
		puts("Pretende remover mais alguma viatura?");
		puts("\tSim---(s)\n \tN�o---(n)");
		scanf(" %c", &opcao);
	
	}while(opcao == 'S' || opcao == 's');
}


void Questionario(char *password,char *passwordequipa,char *passwordgestor)
{
	// Vari�veis
	int i, k, n, opcaoQ1, opcaoQ2, opcaoQ3, opcaoQ4, opcaoQ5, id;
	char continuar;
	
	do
	{
		for(k = 0; k < id_lar; k++)
		{
			printf("\n[%d] --- %s --- %s", lar[k].ID_Lar, lar[k].Nome, lar[k].Regiao);
		}
		
		printf("Insira o ID do Lar que pretende avaliar: ");
		scanf("%d", &id);
		
		Avaliacao[id].ID_Lar = id;
		Avaliacao[id].ID_Equipa = ID_Equipa_Usar;
		nota = 0;
		
		for (i = 0; i < 5; i++)
		{
			
			system("cls");
			puts("========= QUESTION�RIO ===========\n");
			printf("Quiz %d/5\n", i+1);
			puts("Concorda que os Docentes s�o bem tratados pelos funcion�rio?\n");
			puts("1- Discordo Totalmente");
			puts("2- Discordo Parcialmente");
			puts("3- Neutro");
			puts("4- Concordo Parcialmente");
			puts("5- Concordo Totalmente\n");		
			printf("Op��o:");
			scanf("%d", &opcaoQ1);
			
			switch (opcaoQ1)
			{
				case 1:
					nota += 0;
					break;
					
				case 2:
					nota += 1;
					break;
					
				case 3:
					nota += 2;
					break;
					
				case 4:
					nota += 3;
					break;
					
				case 5:
					nota += 4;
					break;
					
				default:
					break;
			}	
			
			
			puts("\n\nConcorda que o Estabelicimento tem boas condi��es de seguran�a e higiene?\n");
			puts("1- Discordo Totalmente");
			puts("2- Discordo Parcialmente");
			puts("3- Neutro");
			puts("4- Concordo Parcialmente");
			puts("5- Concordo Totalmente\n");		
			printf("Op��o:");
			scanf("%d", &opcaoQ2);
			
			switch (opcaoQ2)
			{
				case 1:
					nota += 0;
					break;
					
				case 2:
					nota += 1;
					break;
					
				case 3:
					nota += 2;
					break;
					
				case 4:
					nota += 3;
					break;
					
				case 5:
					nota += 4;
					break;
					
				default:
					break;
			}
			
			
			puts("\n\nConcorda que a alimenta��o � boa e bem servida?\n");
			puts("1- Discordo Totalmente");
			puts("2- Discordo Parcialmente");
			puts("3- Neutro");
			puts("4- Concordo Parcialmente");
			puts("5- Concordo Totalmente\n");		
			printf("Op��o:");
			scanf("%d", &opcaoQ3);
			
			switch (opcaoQ3)
			{
				case 1:
					nota += 0;
					break;
					
				case 2:
					nota += 1;
					break;
					
				case 3:
					nota += 2;
					break;
					
				case 4:
					nota += 3;
					break;
					
				case 5:
					nota += 4;
					break;
					
				default:
					break;
			}
			
			
			puts("\n\nConcorda que o ambiente entre os Docentes � agrad�vel?\n");
			puts("1- Discordo Totalmente");
			puts("2- Discordo Parcialmente");
			puts("3- Neutro");
			puts("4- Concordo Parcialmente");
			puts("5- Concordo Totalmente\n");		
			printf("Op��o:");
			scanf("%d", &opcaoQ4);
			
			switch (opcaoQ4)
			{
				case 1:
					nota += 0;
					break;
					
				case 2:
					nota += 1;
					break;
					
				case 3:
					nota += 2;
					break;
					
				case 4:
					nota += 3;
					break;
					
				case 5:
					nota += 4;
					break;
					
				default:
					break;
			}
			
			
			puts("\n\nConcorda que os funcion�rios tem uma boa rela��o de trabalho?\n");
			puts("1- Discordo Totalmente");
			puts("2- Discordo Parcialmente");
			puts("3- Neutro");
			puts("4- Concordo Parcialmente");
			puts("5- Concordo Totalmente\n");		
			printf("Op��o:");
			scanf("%d", &opcaoQ5);
			
			switch (opcaoQ5)
			{
				case 1:
					nota += 0;
					break;
					
				case 2:
					nota += 1;
					break;
					
				case 3:
					nota += 2;
					break;
					
				case 4:
					nota += 3;
					break;
					
				case 5:
					nota += 4;
					break;
					
				default:
					break;
			}	
		}
		
		Avaliacao[id].Avaliacao = nota;
		
		printf("\n\nPretende Realizar o Questionario sobre mais algum Lar? ");
		scanf(" %c", &continuar);
		
	}while((continuar == 's') || (continuar == 'S'));
	
	 
}


void ContaAvaliacao(char *password,char *passwordequipa,char *passwordgestor)
{
	int id, continuar, k;
	
	do
	{
		printf("===== Lares Disponiveis: =====\n");
		
		for(k = 0; k < id_lar; k++)
		{
			printf("\n[%d] --- %s --- %s", lar[k].ID_Lar, lar[k].Nome, lar[k].Regiao);
		}
		
		printf("\n\nInsira o Lar que pretende ver as estaticticas: ");
		scanf("%d", &id);
	
		printf("\n\nA avaliacao do lar �: %d", Avaliacao[id].Avaliacao);
		printf("\n\nInsira 0 para voltar atras: ");
		scanf(" %d", &continuar);
		
	}while(continuar != 0);
}


void painelchefeequipa(char *password,char *passwordequipa,char *passwordgestor)
{
	system ("cls");
	int x = 0;
	int id = 0;
	int opcao,identificador;
	char opcao5,escolha,carta;
	int idequipa,k,ID_editar,opcao6, opcao4;
	char editar_membro,carta1, voltar, desactivar_membro;
	char nome[50];
	int i,g;	
	
	do
	{
		for(g = 0; g < ID_membro; g++)
		{
			if(membro[g].ID_Equipa == ID_Equipa_Usar)
			{
				printf("\n----- %d ---- %s \n", membro[g].id_membro, membro[g].Nome);
			}
		}
		
		printf("Digite o seu ID se for capit�o, se n�o for porfavor insira 500 para voltar atras: ");
		scanf("%d", &id);
		
		if(id != 500)
		{
			for(x = 0; x < ID_membro; x++)
			{
				if(id == membro[x].id_membro && membro[x].verificador == 1)
				{
					do
					{
						system("cls");
						puts("==========Gerir dados============");
    					printf("|1-Adicionar novo membro\t|\n");
    					printf("|2-Editar membro\t\t|\n");
    					printf("|3-Desativar membro\t\t|\n");
    					printf("|0 - Voltar ao menu Principal\t|\n");
    					puts("=================================");
						printf("Opcao: ");	
						scanf("%d", &opcao);
						
						switch(opcao)
						{
							case 1:
								
								do
								{
									system("cls");
									
									puts("========== Inserir Elementos a Equipa ==========\n");
									
									
									membro[ID_membro].id_membro = ID_membro;
									membro[ID_membro].ativo = '1';
									membro[ID_membro].ID_Equipa = ID_Equipa_Usar;	
									membro[ID_membro].verificador = 0;
									
									system("cls");
									
									printf("\nNome do novo membro: ");
									fflush(stdin);
									gets(membro[ID_membro].Nome);
									
									printf("\n�rea Profissional: ");
									printf("\n\t1 -- Medico\n\t2 -- Enfermeiro\n\t3 -- Assistente social\n\t4 --Tecnico Ambiental");
									printf("\nOp��o: ");
									scanf(" %c", &membro[ID_membro].AreaProfissional);
									
									printf("\nContacto: ");
									scanf("%d", &membro[ID_membro].contacto);
										
									printf("\nCart�o de cidad�o: ");
									scanf("%d", &membro[ID_membro].CC);
									
									printf("\nMorada: ");
									fflush(stdin);
									gets(membro[ID_membro].Morada);
									
									printf("\nEmail: ");
									fflush(stdin);
									gets(membro[ID_membro].email);
							
									printf("\nPossui Carta de Condu��o: ");
									printf("\n\tSim---(s)\n\tN�o---(n)");
									printf("\nOp��o: ");
									scanf(" %c", &carta);
								
									if((carta == 's') || (carta == 'S'))
									{
										printf("\nInsira o Numero da Carta de Condu��o: ");
										fflush(stdin);
										gets(membro[ID_membro].CartaConducao);
									}
									else if((carta == 'n') || (carta == 'N'))
									{
										strcpy(membro[ID_membro].CartaConducao, "N�o possui carta de condu��o");
									}
									ID_membro++;
									
									printf("\n\nPretende adicionar mais membros a alguma equipa?\n(S/N): ");
									scanf(" %c", &opcao);
								
								}while(opcao5 == 'S' || opcao5 == 's');
								break;
							
							case 2:
								do
								{
									puts("========== Editar Membro da equipa ==========\n");
					
									for(x = 0; x < ID_membro; x++)
									{
										if(membro[x].ID_Equipa == ID_Equipa_Usar)
										{
											if(strcmp(membro[x].AreaProfissional, "medico") == 0)
											{
												printf("%d --- %s --- M�dico", membro[x].id_membro ,&membro[x].Nome);
											}
											else if(strcmp(membro[x].AreaProfissional, "enfermeiro") == 0)
											{
												printf("%d --- %s --- Enfermeiro", membro[x].id_membro ,&membro[x].Nome);
											}
											else if(strcmp(membro[x].AreaProfissional, "assitente") == 0)
											{
												printf("%d --- %s --- Assistente social", membro[x].id_membro ,&membro[x].Nome);
											}
										}
										
									}
									
									printf("Pretende editar algum elemento? (S/N): ");
				    				scanf(" %c", &editar_membro);
				    	
				    				if ((editar_membro == 'S') || (editar_membro == 's'))
									{
										printf("\nInsira o ID do membro que pretende editar: ");
										scanf(" %d", &ID_editar);
										
										do
										{
											puts("===== Editar Membro =====");
											printf("|1 -- Nome\t\t|");
											printf("\n|2 -- �rea Profissional\t|");
											printf("\n|3 -- Contacto\t\t|");
											printf("\n|4 -- Cart�o de Cidad�o\t|");
											printf("\n|5 -- Morada\t\t|");
											printf("\n|6 -- Email\t\t|");
											printf("\n|7 -- Carta\t\t|");
											printf("\n|0 -- Sair\t\t|");
											printf("=========================\n");
											printf("\nOpcao: ");
											scanf("%d", &opcao6);
						
											switch(opcao6)
											{
												case 1:
													printf("\nNome do membro: ");
							    					fflush(stdin);
							    					gets(membro[ID_editar].Nome);
													break;
													
												case 2:
													printf("\n�rea Profissional: ");
							    					printf("\n\t1 -- Medico\n\t2 -- Enfermeiro\n\t3 -- Assistente social");
							    					printf("\nOp��o: ");
							    					scanf(" %c", &membro[ID_editar].AreaProfissional);
													break;
													
												case 3:
													printf("\nContacto: ");
							   						scanf("%d", &membro[ID_editar].contacto);
													break;
													
												case 4:
													printf("\nCart�o de cidad�o: ");
							   						scanf("%d", &membro[ID_editar].CC);
													break;
													
												case 5:
													printf("\nMorada: ");
							    					fflush(stdin);
							    					gets(membro[ID_editar].Morada);
													break;
													
												case 6:
													printf("\nEmail: ");
							    					fflush(stdin);
							    					gets(membro[ID_editar].email);
													break;
													
												case 7:
													printf("\nPossui Carta de Condu��o: ");
							    					printf("\n\tSim---(s)\n\tN�o---(n)");
							    					printf("\nOp��o: ");
							    					scanf(" %c", &carta1);
							    	
													if((carta1 == 's') || (carta1 == 'S'))
													{
														printf("\nInsira o Numero da Carta de Condu��o: ");
														fflush(stdin);
							    						gets(membro[ID_editar].CartaConducao);
													}
													else if((carta1 == 'n') || (carta1 == 'N'))
													{
														strcpy(membro[ID_membro].CartaConducao, "N�o possui carta de condu��o");
													}
													break;
											}
											
										}while(opcao6 != 0);
								
									}
				
									printf("\n\nPretende editar mais algum Membro?");
									puts("\n\tSim---(s)\n\tN�o---(n)");
									printf("\nOp��o: ");
									scanf(" %c", &opcao);
					
								}while(opcao == 'S' || opcao == 's');
								break;
								
							case 3: 
							
								
				            	do
								{	
									puts("========== Desativar Membro da equipa ==========\n");
									
									for(x = 0; x < ID_membro; x++)
									{
										if(strcmp(membro[x].AreaProfissional, "medico") == 0)
										{
											printf("\n%d --- %s --- M�dico", membro[x].id_membro ,&membro[x].Nome);
										}
										else if(strcmp(membro[x].AreaProfissional, "enfermeiro") == 0)
										{
											printf("\n%d --- %s --- Enfermeiro", membro[x].id_membro ,&membro[x].Nome);
										}
										else if(strcmp(membro[x].AreaProfissional, "assitente") == 0)
										{
											printf("\n%d --- %s --- Assistente social", membro[x].id_membro ,&membro[x].Nome);
										}
										else if(strcmp(membro[x].AreaProfissional, "tecnico") == 0)
										{
											printf("\n%d --- %s --- Tecnico Saude Ambiental", membro[x].id_membro ,&membro[x].Nome);
										}
										
									}
											
									printf("\n\nPretende desactivar algum membro?\n(S/N)");
									scanf(" %c", &desactivar_membro);
									
									if((desactivar_membro == 's') || (desactivar_membro == 'S'))
									{
										printf("\nInsira o ID do membro que pretende desactivar: ");
										scanf("%d", &opcao4);
										
										membro[opcao4].ativo = '0';
									}
				            		
				        			puts("Pretende remover algum Membro de outra equipa?\n(S/N)");
				        			puts("\tSim---(s)\n \tN�o---(n)");
				        			scanf(" %c", &opcao);
				        
								}while((opcao == 'S') || (opcao == 's'));
								break;
						}
						
					}while(opcao != 0);
				}
			}
		}
		
		printf("\n\nPretende voltar ao menu da equipa? ");
		scanf(" %c", &voltar);
			
	}while((voltar == 'n') || (voltar == 'N'));
}


void MenuVisita(char *password,char *passwordequipa,char *passwordgestor)
{
	int opcao;
	
	do
	{
		system("cls");
		puts("=============== Registar Visitas ================");
		printf("|\t1 -- Requisitar Viaturas para Visita\t|");
		printf("\n|\t2 -- Registar Visita\t\t\t|\n");
		printf("|\t0 -- Voltar para menu anterior\t\t|\n");
		puts("=================================================");
		printf("\nOp��o: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				RequisitarViaturas(password,passwordgestor,passwordequipa);
				break;
				
			case 2:
				RegistarVisita(password,passwordgestor,passwordequipa);
				break;
				
			default:
				break;
				
		}
			
	}while(opcao != 0);
}


void RequisitarViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	int k;
	char requisitar_mais;
	
	do
	{
		printf("Viaturas Disponiveis: \n");
		
		for(k = 0; k < ID_viatura; k++)
		{
			if(Viaturas[k].ativo == '1')
			{
				printf("\nID: %d N� Lugares %d --- %s --- %s\n", Viaturas[k].id_viatura, Viaturas[k].nLugares , Viaturas[k].matricula, Viaturas[k].marca);
			}
			
			
		}
		
		printf("Insira o ID da Viatura que pretende requisitar: ");
		scanf("%d", &reViaturas[ID_reqViatura].ID_Viatura);
		
		printf("\n\nVisitas Disponiveis: \n");
		
		for(k = 0; k < id_visita; k++)
		{
			if(agenda[k].ID_Equipa == ID_Equipa_Usar)
			{
				printf("\n%d --- %d ---> %d", agenda[k].ID_Visita , agenda[k].ID_Equipa, agenda[k].ID_Lar);
			}
		}
		
		printf("Insira o ID da Visita onde esta viatura vai ser usada: ");
		scanf("%d", &reVisita[ID_reqViatura].ID_Visita);
		
		printf("\n\nPretende requisitar mais viaturas: ");
		scanf(" %c", &requisitar_mais);
		
	}while((requisitar_mais == 's') || (requisitar_mais == 'S'));
}


void RegistarVisita(char *password,char *passwordequipa,char *passwordgestor)
{

	char registarVisita;
	int n_covid;
	
	do
	{
		printf("========== Registo Visita ==========");		
		printf("\n\nInsira o ID do Lar que foi visitado: ");
		scanf("%d", &reVisita[ID_regVisita].ID_Visita);
		
		reVisita[ID_regVisita].ID_Equipa = ID_Equipa_Usar;
		reVisita[ID_regVisita].ID_Visita = ID_regVisita;
		
		printf("\nEscreva um Relat�rio sobre a Visita: ");
		fflush(stdin);
		gets(reVisita[ID_regVisita].Relatorio);
		
		printf("\nInsira o numero de testes ao Covid 19 Realizados no Lar: ");
		scanf("%d", &reVisita[ID_regVisita].N_Testes);
		
		printf("\nInsira o numero de casos de Covid 19 encontrados no Lar: ");
		scanf("%d", &n_covid);
		
		reVisita[ID_regVisita].N_Covid = n_covid;
		
		/*
		if(n_covid > 0)
		{
			do
			{
				printf("\nEscreva um Relat�rio sobre a Visita: ");
				fflush(stdin);
				gets(reVisita[ID_regVisita].Relatorio);
				
				
			}while();
		}
		*/
		
		printf("\nPretende registar mais alguma Visita? ");
		scanf(" %c", &registarVisita);
		
		ID_regVisita++;
		
		
	}while((registarVisita == 's') || (registarVisita == 'S'));

}
 

void VerificarRelatorio(char *password,char *passwordequipa,char *passwordgestor)
{
	int k, id_visita;
	char verRelatorio;
	
	do
	{
		printf("========== Verificar Relatorios ==========");
		
		printf("\n\nVisitas disponiveis para consulta:  \n");
		
		for(k = 0; k < ID_regVisita; k++)
		{
			printf("\n[%d] --- %d --- %d", reVisita[k].ID_Visita, reVisita[k].ID_Equipa, reVisita[k].ID_Lar);
		}
		
		printf("\n\nInsira de que visita pretende imprimir o relat�rio: ");
		scanf("%d", &id_visita);
		
		printf("\n\n Relat�rio: %s", reVisita[id_visita].Relatorio);
		
		printf("\n\n Casos de Covid: %d", reVisita[id_visita].N_Covid);
		
		printf("\n\nForam usadas as seguintes viaturas: ");
		for(k = 0; k < ID_viatura; k++)
		{
			if(reVisita[k].ID_Visita == id_visita)
			{
				printf("\nID: %d N� Lugares %d --- %s --- %s\n", Viaturas[k].id_viatura, Viaturas[k].nLugares , Viaturas[k].matricula, Viaturas[k].marca);
			}
		}
		
		printf("\n\nPretende ver mais algum relat�rio: ");
		scanf(" %c", &verRelatorio);
		
	}while((verRelatorio == 's') || (verRelatorio == 'S'));
}


void MediaAvaliacoesVisitas(char *password,char *passwordequipa,char *passwordgestor)
{
	// Vari�veis
	int i, soma, contadorAvaliacoes;
	float media;
	soma = media = contadorAvaliacoes = 0;
	
	
	// Somar as avalia��es das visitas
	for(i = 0; i < id_visita; i++)
	{
		// Calcular apenas as avalia��es dos lares visitados
		if(Avaliacao[i].Avaliacao < 1)
		{
			soma += Avaliacao[i].Avaliacao;
			contadorAvaliacoes++;
		}		
	}
	
	// Calcular a m�dia das avalia��es
	media = soma / (float)contadorAvaliacoes;	
	printf("A m�dia: %f",media );
}


void ListarVisitas(char *password,char *passwordequipa,char *passwordgestor)
{
	// Vari�veis
	int i, j, aux, id;
	int maior = Avaliacao[0].Avaliacao;
	
	
	for (i = 0; i < id_visita; i++)
	{
		for (j = 1; j < id_visita; i++)
		{
			// Calcular apenas as avalia��es dos lares visitados
			if(Avaliacao[j].Avaliacao > maior)
			{
				maior = Avaliacao[j].Avaliacao;
				id = Avaliacao[j].ID_Lar;
			}
		}
		
		// Mostrar por ordem da melhor visita para a pior
		printf("%d� Lar %d - %d", i+1, id, maior);
	}
}


