#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <limits.h>



// Definições
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


// Estrutura Avaliação da Visita
typedef struct ContaAvaliacao
{
	int ID_Equipa;
	int ID_Lar;
	int Avaliacao;

}contAva;


// Estrutura Relatório Visita
typedef struct RegistoVisita
{
	int ID_Visita;
	int ID_Lar;
	int ID_Equipa;
	char Relatorio [500];
	int N_Covid;
	int N_Testes;

}regVisita;



// 																						VARIÁVEIS
// Arrays
registo membro[TAMAMNHO];
equipas equipa[TAMAMNHO];
lares lar[TAMAMNHO];
resVisita agenda[TAMAMNHO];
reqViatura reViaturas[TAMAMNHO];
regVisita reVisita[TAMAMNHO];
viatura Viaturas[TAMAMNHO];
contAva Avaliacao[TAMAMNHO];
int Notas[TAMAMNHO];

// Contadores / índices
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
int contador;

// Array para guardar o contador dos profissionais por equipa
int contadormed1[TAMAMNHO];
int contadorenf1[TAMAMNHO];
int contadorass1[TAMAMNHO];
int contadortec1[TAMAMNHO];



//																						ASSINATURAS
// Procedimento Menu Principal
void Menugeral(char *password,char *passwordgestor,char *passwordequipa);


// Procedimentos Verificação Passwords
void Verificapassgestor(char *password, char *passwordgestor,char *passwordequipa);
void Verificapassequipa(char *password, char *passwordequipa,char *passwordgestor);

// Procedimentos do Gestor
void MenuGestor(char *password,char *passwordgestor,char *passwordequipa);
void Menuequipa(char *password,char *passwordgestor,char *passwordequipa);
void MenuSubmenu(char *password,char *passwordgestor,char *passwordequipa);
void MenuSubmenuEquipas(char *password, char *passwordequipa,char *passwordgestor);
void gerirMembros(char *password, char *passwordgestor,char *passwordequipa);


// Procedimentos Avaliação Visitas
void Questionario(char *password,char *passwordequipa,char *passwordgestor);
void ContaAvaliacao(char *password, char *passwordequipa, char *passwordgestor);


// Procedimentos Gestão Equipas
void criarrequipas(char *password, char *passwordgestor,char *passwordequipa);
void verificarEquipas(char *password, char *passwordgestor,char *passwordequipa);
void editarEquipas(char *password, char *passwordgestor,char *passwordequipa);
void desactivarEquipas(char *password, char *passwordgestor,char *passwordequipa);


// Procedimentos Gestão Membros
void inserirMembros(char *password, char *passwordgestor,char *passwordequipa);
void mostrarMembros(char *password, char *passwordgestor,char *passwordequipa);
void editarMembros(char *password, char *passwordgestor,char *passwordequipa);
void desativarMembros(char *password, char *passwordgestor,char *passwordequipa);


// Procedimento Gestão Lares
void MenuSubmenuLares(char *password,char *passwordequipa,char *passwordgestor);
void adicionarlares(char *password,char *passwordequipa,char *passwordgestor);
void verificarlares(char *password,char *passwordequipa,char *passwordgestor);
void editarlares(char *password,char *passwordequipa,char *passwordgestor);
void apagarlares(char *password,char *passwordequipa,char *passwordgestor);


// Procedimentos Gestão Agenda
void gerirAgendas(char *password,char *passwordequipa,char *passwordgestor);
void adicionarAgenda(char *password,char *passwordequipa,char *passwordgestor);
void visualizarAgenda (char *password,char *passwordequipa,char *passwordgestor);
void editarAgenda (char *password,char *passwordequipa,char *passwordgestor);


// Procedimentos Gestão Viaturas
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


// Procedimentos de Estatísticas
void MediaAvaliacoesVisitas(char *password,char *passwordequipa,char *passwordgestor);
void ListarVisitas(char *password,char *passwordequipa,char *passwordgestor);



//																						MAIN
int main(int argc, char *argv[]) 
{	
	// Configurações
	setlocale(LC_ALL, "Portuguese");

	// Variáveis
	char passwordgestor[50] = "Gestor123456";	
	char passwordequipa[50] = "Equipa123456";
	char password[50];

	// Chamar pelo Procedimento com o Menu Principal
	Menugeral(password,passwordgestor,passwordequipa);
}



//																						PROCEDIMENTOS E FUNÇÕES
// Menu Principal
void Menugeral(char *password,char *passwordgestor,char *passwordequipa)
{
	// Variáveis
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
		printf("Opção: ");


		// Instrução para receber uma opção Válida	
		do
		{
			scanf("%d", &opcao);

			// Se opção inválida, informa e pede uma válida
			if (opcao != 1 && opcao !=2)
			{
				printf("\nOpção inválida, insira outra: ");
			}		

		} while (opcao != 1 && opcao != 2);


		// Se login Gestor chamar a função X
	    if(opcao == 1)
		{
			password[0] = '\0';
			Verificapassgestor(password,passwordgestor,passwordequipa);	
		}


		// Se login Equipa chamar a função Y
	    else if(opcao == 2)
		{
			password[0] = '\0';
			Verificapassequipa(password,passwordequipa,passwordgestor);
		}

	} while(opcao != 0);

}


// Verificação Password Gestor
void Verificapassgestor(char *password, char *passwordgestor,char *passwordequipa)
{
	// Variáveis
	int i;
	password[0] = '\0';


	// Pede e recebe a password	
	printf("Password:");
	scanf(" %s", password);
   	puts("");


   	// Se password correta chama Função X
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


// Verificação Password Equipa
void Verificapassequipa(char *password, char *passwordequipa,char *passwordgestor)
{
	// Variáveis
	int i;
	password[0] = '\0';


	// Pede e recebe a password	
	printf("Password:");
	scanf(" %s", password);
	puts("");


	// Se password correta chama Função X
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
	// Variáveis
	int opcao, id, continuar, esta, i, j, k, l, id2, maior;
	float media = 0, media2 = 0;


    do
    {
    	// Menu Gestor
    	system("cls");
        puts("========Bem vindo========");
		printf("|1- Gerir dados\t\t|\n");
		printf("|2- Imprimir relatório\t|\n");
		printf("|3- Imprimir Estatíscas\t|\n");			
		printf("|0- Menu de utilizador\t|\n");
		puts("=========================");
		printf("Opção: ");
        scanf(" %d", &opcao);


        switch (opcao)
        {
	        case 1:
	        	// Gerir Dados
	        	system("CLS");
	        	MenuSubmenu(password,passwordgestor,passwordequipa);
	            break;

	        case 2:
	        	// Imprimir Relatórios
	        	system("CLS");
	            VerificarRelatorio(password,passwordgestor,passwordequipa);
	            break;


	        case 3:
	        	// Imprimir Estatísticas
	        	system("CLS");

				do
				{
					for (i = 0; i < id_visita; i++)
					{
						media += Avaliacao[i].Avaliacao;
					}
					
					media = media / id_visita;
					
															
					/*
					
					for (j = 0; j < id_visita; j++)
					{
						media2 += Notas[i];
					}
					
					media2 = media2 / id_visita;
					
					
					printf("id_visita: %d", id_visita);
					printf("Média: %f", media2);

					
					MediaAvaliacoesVisitas(password,passwordgestor,passwordequipa);	        		
					ListarVisitas(password,passwordgestor,passwordequipa);	
					*/
				
					
					
					puts("Listagem dos Lares e as suas avaliações: ");
					// Lstar visitas
					for (k = 0; k < id_visita; k++)
					{
						for (l = k+1; l < id_visita; l++)
						{
							if (Avaliacao[k].Avaliacao < Avaliacao[l].Avaliacao)
							{
								maior = Avaliacao[l].Avaliacao;
								Avaliacao[l].Avaliacao = Avaliacao[k].Avaliacao;
								Avaliacao[k].Avaliacao = maior;
								
								id2 = Avaliacao[l].ID_Lar;
								Avaliacao[l].ID_Lar = Avaliacao[k].ID_Lar;
								Avaliacao[k].ID_Lar = id2;
							}

						}
					
						// Mostrar por ordem da melhor visita para a pior
						printf("\n%dº Lar %d - %d", k+1, id2, maior);
					}
		

	        		puts("");
	        		printf("\nA média de avaliações é: %.2f", media);
					puts("");
	        		printf("\nVoltar: ");
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
	// Variáveis
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
			printf("Equipas Disponíveis:\n\n");


			// Listar equipas registadas
			if (ID_equipa > 0)
			{
				for(x = 0; x < ID_equipa; x++)
				{
					printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);	
				}


				// Escolher o indíce para entrar no Menu de Equipa			
				printf("\n\nInsira o ID da Equipa que está a usar o programa: ");
				scanf("%d", &ID_Equipa_Usar);


				for(x = 0; x < ID_equipa; x++)
				{
					// Escolher o indíce para entrar no Menu de Equipa
					if(ID_Equipa_Usar == equipa[x].id_equipa)
					{
						system("cls");
						Menuequipa(password, passwordequipa, passwordgestor);
					}
				}				
			}

			// Não há equipas disponíveis
			else if(ID_equipa == 0)
			{
				system("cls");
				printf("Não há equipas disponíveis\n");
			}			
		}

		// Decisão para voltar ao Menu principal
		printf("\nPretende voltar ao menu do Login? ");
		scanf(" %c", &continuar);


	}while((continuar == 'n') || (continuar == 'N'));

}


// Menu Equipa
void Menuequipa(char *password,char *passwordequipa,char *passwordgestor)
{  	
	// Variáveis
	int opcao;


	do
	{
		// Menu Equipa
		system("CLS");
		printf("====== Bem vindo equipa %d =======\n", ID_Equipa_Usar);
		printf("|1-Gerir Lares\t\t\t|\n");
		printf("|2-Gerir Agenda\t\t\t|\n");
		printf("|3-Registar visita a Lares\t| \n");
		printf("|4-Questionário sobre o Lar\t|\n");
		printf("|5-Imprimir Relatórios\t\t|\n");
		printf("|6-Imprimir Avaliações\t\t|\n");
		printf("|7-Painel de chefe equipa\t|\n");
		printf("|0-Menu de utilizador\t\t|\n");
		puts("=================================");
		printf("Opção: ");
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
         		// Realizar o Questionário
        		system("CLS");
            	Questionario(password, passwordequipa, passwordgestor);
            	break;


         	case 5:
         		// Consultar Relatório
        		system("CLS");
            	VerificarRelatorio(password, passwordequipa, passwordgestor);
            	break;   


        	case 6:
        		// Consultar Avaliação
        		system("CLS");
            	ContaAvaliacao(password,passwordequipa,passwordgestor);
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
	// Variáveis
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
    	printf("Opção:");
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
	// Variáveis
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
    	printf("Opção:");
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
	// Variáveis
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
    	printf("Opção:");
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
	// Variáveis
	int x = 0, distrito;
	char maisequipa;	


	do
	{
		// Criar Equipas
		system("cls");
		puts("========== Criar Equipa ==========");


		// Criação e ativação da equipa	
		equipa[ID_equipa].id_equipa = ID_equipa;
		equipa[ID_equipa].equipa_ativa = 1;


		// Registo do nome	
		printf("\nInsira o nome da Equipa: ");
		fflush(stdin);
		gets(equipa[ID_equipa].Nome);


		// Atribuição do Distrito
		puts("\n=========================== Distritos ===========================");	
		printf("|1.Viana do Castelo\t| 7.Viseu\t\t| 13.Portalegre\t|\n");
    	printf("|2.Vila Real\t\t| 8.Guarda\t\t| 14.Lisboa\t|\n");
    	printf("|3.Bragança\t\t| 9.Coimbra\t\t| 15.Évora\t|\n");
    	printf("|4.Braga\t\t| 10.Castelo Branco\t| 16.Setúbal\t|\n");
    	printf("|5.Porto\t\t| 11.Leiria\t\t| 17.Bejat\t|\n");
    	printf("|6.Aveiro\t\t| 12.Santarém\t\t| 18.Faro\t|");
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
				strcpy(equipa[ID_equipa].regiao, "Bragança");
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
				strcpy(equipa[ID_equipa].regiao, "Santarém");
			break;


			case 13:
				strcpy(equipa[ID_equipa].regiao, "Portalegre");
			break;


			case 14:
				strcpy(equipa[ID_equipa].regiao, "Lisboa");
			break;


			case 15:
				strcpy(equipa[ID_equipa].regiao,"Évora");
			break;


			case 16:
				strcpy(equipa[ID_equipa].regiao, "Setúbal");
			break;


			case 17:
				strcpy(equipa[ID_equipa].regiao, "Beja");
			break;


			case 18:
				strcpy(equipa[ID_equipa].regiao, "Faro");
			break;


			default:
				printf("Não escolheu um distrito válido");
		}


		printf("\n\nO ID desta Equipa é: %d", equipa[ID_equipa].id_equipa);

		ID_equipa ++;

		printf("\n\nPretende criar mais equipas? ");
		scanf(" %c", &maisequipa);


	} while((maisequipa == 'S') || (maisequipa == 's'));

}


// Sub Menu Gestor / Verificar Equipas
void verificarEquipas(char *password, char *passwordgestor,char *passwordequipa)
{
	// Variáveis
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
	// Variáveis
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


		// Decisão editar
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
				printf("\n|2 --- Região\t|");
				printf("\n|0 --- Sair\t|\n");
				puts("=================");
				printf("\nOpção: ");

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
    					printf("|3.Bragança\t\t| 9.Coimbra\t\t| 15.Évora\t|\n");
    					printf("|4.Braga\t\t| 10.Castelo Branco\t| 16.Setúbal\t|\n");
    					printf("|5.Porto\t\t| 11.Leiria\t\t| 17.Bejat\t|\n");
    					printf("|6.Aveiro\t\t| 12.Santarém\t\t| 18.Faro\t|");
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
								strcpy(equipa[ID_editar].regiao, "Bragança");
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
								strcpy(equipa[ID_editar].regiao, "Santarém");
							break;


							case 13:
								strcpy(equipa[ID_editar].regiao, "Portalegre");
							break;


							case 14:
								strcpy(equipa[ID_editar].regiao, "Lisboa");
							break;


							case 15:
								strcpy(equipa[ID_editar].regiao,"Évora");
							break;


							case 16:
								strcpy(equipa[ID_editar].regiao, "Setúbal");
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

		// Decisão voltar atrás
		printf("\n\nPretende voltar para o menu anterior? ");
		puts("\n\tSim---(s)\n\tNão---(n)");
		printf("\nOpção: ");
		scanf(" %c", &voltar);


	} while ((voltar == 'n') || (voltar == 'N'));

}


// Sub Menu Gestor / Desativar Equipas
void desactivarEquipas(char *password, char *passwordgestor,char *passwordequipa)
{
	// Variáveis
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
    char opcao5;
    char opcao;
	int x = 0;
	char profissao1[50] = "medico";
	char profissao2[50] = "enfermeiro";
	char profissao3[50] = "assistente";
	char profissao4[50] = "tecnico";
	char carta;
	char escolha;
	int id;
	int escolha1;
	int idatual = 999999;
	contadormed = 0; 
	contadorenf = 0;
	contadorass = 0;
	contadortec = 0;
		
 	do
	{
		system("cls");
		
		puts("-----Inserir Elementos a Equipa-----\n");
		printf("\n É necessario inserir um membro para cada area.\n");
		
		for(x = 0; x < ID_equipa; x++)
		{
			printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
		}
		
		membro[ID_membro].id_membro = ID_membro;
		membro[ID_membro].ativo = 1;
		
		puts("\n\nInsira o ID da equipa a que pretende adicionar o membro: ");
		scanf("%d", &id);
		
		if(idatual != id)
		{
			contador = 0;
		}

		membro[ID_membro].ID_Equipa = id;	
		
		system("cls");
		
		printf("\nNome do novo membro: ");
		fflush(stdin);
		gets(membro[ID_membro].Nome);
		
		printf("\nÁrea Profissional: ");
		printf("\n\t1 -- Medico\n\t2 -- Enfermeiro\n\t3 -- Assistente social\n\t4 --  Tecnico");
		printf("\nOpção: ");
		scanf(" %d", &escolha1);
		
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
			
				
		printf("\nContacto: ");
		scanf("%d", &membro[ID_membro].contacto);
			
		printf("\nCartão de cidadão: ");
		scanf("%d", &membro[ID_membro].CC);
		
		printf("\nMorada: ");
		fflush(stdin);
		gets(membro[ID_membro].Morada);
		
		printf("\nEmail: ");
		fflush(stdin);
		gets(membro[ID_membro].email);
		
		for(x = 0; x < ID_membro + 1; x++)
		{
			if(contador == 0)
			{
				printf("\nEste membro é chefe de equipa?\n(s/n): ");
				scanf(" %c", &escolha);
				if((escolha == 's') || (escolha == 'S'))
				{
					contador = 1;
					membro[ID_membro].verificador = 1;
				}
				else if((escolha == 'n') || (escolha == 'N'))
				{
					contador = 0;
					membro[ID_membro].verificador = 0;
				}
			}

		}

		printf("\nPossui Carta de Condução: ");
		printf("\n\tSim---(s)\n\tNão---(n)");
		printf("\nOpção: ");
		scanf(" %c", &carta);
	
		if((carta == 's') || (carta == 'S'))
		{
			printf("\nInsira o Numero da Carta de Condução: ");
			fflush(stdin);
			gets(membro[ID_membro].CartaConducao);
		}
		else if((carta == 'n') || (carta == 'N'))
		{
			membro[ID_membro].CartaConducao == "Não possui carta de condução";
		}
		ID_membro++;
		
		contadormed1[id] += contadormed;
		contadorenf1[id] += contadorenf;
		contadorass1[id] += contadorass;
		contadortec1[id] += contadortec;

		
		printf("\n\nPretende adicionar mais membros a alguma equipa? (S/N): ");
		scanf(" %c", &opcao5);
	
	}while((opcao5 == 'S') || (opcao5 == 's'));
	
	if((opcao5 == 'n')||(opcao5 == 'N'))
	{
		if(contadormed1[id] >= 1 && contadorenf1[id] >= 1 && contadorass1[id] >= 1 && contadortec1[id] >= 1)
		{
			gerirMembros(password,passwordgestor,passwordequipa);
		}
		else
		{
			inserirMembros(password,passwordgestor,passwordequipa);
			printf("\n\nTem de ter um membro pelo menos um funcionario de cada area!");
		}
	}	
}


// Sub Menu Gestor / Mostrar Membros
void mostrarMembros(char *password, char *passwordgestor,char *passwordequipa)
{

	int i, x, k, opcao4, identificador;
	char opcao5, ver_dados, opcao3;
	char profissao1[50] = "medico";
	char profissao2[50] = "enfermeiro";
	char profissao3[50] = "assistente";
	char profissao4[50] = "tecnico";


	do
	{
		system("cls");

		// Listar todas as equipas
		for(x = 0; x < ID_equipa; x++)
		{
			printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
		}


		printf("\n\nInsira o ID da equipa: ");
		scanf("%d", &identificador);


		// Listar todos os Membros
		for(k = 0; k < ID_membro; k++)
		{
			if((membro[k].ID_Equipa == identificador) && (membro[k].ativo == 1))
			{
				if(strcmp(membro[k].AreaProfissional, profissao1) == 0)
				{
					printf("\n%d --- %s --- Médico", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, profissao2) == 0)
				{
					printf("\n%d --- %s --- Enfermeiro", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, profissao3) == 0)
				{
					printf("\n%d --- %s --- Assistente social", membro[k].id_membro ,&membro[k].Nome);
				}
				else if(strcmp(membro[k].AreaProfissional, profissao4) == 0)
				{
					printf("\n%d --- %s --- Técnico Saude Ambiental", membro[k].id_membro ,&membro[k].Nome);
				}
			}
		}


		printf("\n\nPretende ver os dados relativos a algum membro?\n(S/N): ");
		scanf(" %c", &ver_dados);


		// Visualizar informações de um Membro
		if((ver_dados == 's') || (ver_dados == 'S'))
		{
			printf("\n\nInsira o ID do membro que pretende visualizar: ");
			scanf("%d", &opcao4);

			system("cls");

			printf("O elemento %s, pertencente à Equipa com o ID %d, contém os seguintes dados: ", membro[opcao4].Nome, identificador);	

			printf("\n\nÁrea Profissional: %s", membro[opcao4].AreaProfissional);

   			printf("\nContacto: %d", membro[opcao4].contacto);

   			printf("\nCartão de Cidadão: %d", membro[opcao4].CC);

    		printf("\nMorada: %s", &membro[opcao4].Morada);

    		printf("\nEmail: %s", &membro[opcao4].email);

    		printf("\nCarta de Condução: %s", &membro[opcao4].CartaConducao);

    		if(membro[opcao4].ativo == '1')
			{
				printf("\nEste membro encontra-se: Ativo");
			}
			if(membro[opcao4].ativo == '0')
			{
				printf("\nEste membro encontra-se: Inativo");
			}
			
			printf("\n\nQuer visualizar os dados de outro membro?\n(S/N): ");
			scanf(" %c", &opcao3);
			
		}
		else
		{
			opcao3 = 'n';
		}


	}while((opcao3 == 'S') || (opcao3 == 's'));

}


// Sub Menu Gestor / Editar Membros	
void editarMembros(char *password, char *passwordgestor,char *passwordequipa)
{
	// Variáveis
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
					printf("\n%d --- %s --- Médico", membro[k].id_membro ,&membro[k].Nome);
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
				printf("\n|2 -- Área Profissional\t|");
				printf("\n|3 -- Contacto\t\t|");
				printf("\n|4 -- Cartão de Cidadão\t|");
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
						// Editar área profissional
						printf("\nÁrea Profissional: ");
    					printf("\n\t1 -- Medico\n2 -- Enfermeiro\n3 -- Assistente social\n4 --  Tecnico");
    					printf("\nOpção: ");
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
						printf("\nCartão de cidadão: ");
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
						// Editar Carta de Condução
						printf("\nPossui Carta de Condução: ");
    					printf("\n\tSim---(s)\n\tNão---(n)");
    					printf("\nOpção: ");
    					scanf(" %c", &carta1);

						if((carta1 == 's') || (carta1 == 'S'))
						{
							printf("\nInsira o Numero da Carta de Condução: ");
							fflush(stdin);
    						gets(membro[ID_editar].CartaConducao);
						}
						else if((carta1 == 'n') || (carta1 == 'N'))
						{
							strcpy(membro[ID_membro].CartaConducao, "Não possui carta de condução");
						}
						break;						
				}


			}while(opcao6 != 0);

		}

		printf("\n\nPretende editar mais algum Membro?");
		puts("\n\tSim---(s)\n\tNão---(n)");
		printf("\nOpção: ");
		scanf(" %c", &opcao);


	}while(opcao == 'S' || opcao == 's');

}


// Sub Menu Gestor / Desativar Membros
void desativarMembros(char *password, char *passwordgestor,char *passwordequipa)
{
	// Variáveis
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
					printf("\n%d --- %s --- Médico", membro[k].id_membro ,&membro[k].Nome);
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
		puts("\tSim---(s)\n \tNão---(n)");
		scanf(" %c", &opcao);


	} while((opcao == 'S') || (opcao == 's'));
}


// Sub Menu Equipa / Gerir Lares
void MenuSubmenuLares(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variáveis
	int opcao;

  	do
    {
    	// Gestão de Lares
		system("cls");
		puts("========== Gerir Lares ==========");
		printf("|1 - Adicionar Lares\t\t|\n");
		printf("|2 - Verificar Lares Existentes\t|\n");
		printf("|3 - Editar Lares Existentes\t|\n");
		printf("|4 - Desactivar Lares\t\t|\n");
		printf("|0 - Voltar ao menu Principal\t|\n");
		puts("=================================\n");
		printf("\nOpção: ");
		scanf("%d", &opcao);


		switch(opcao)
		{
			case 1:
				// Adicionar Lares
				system("CLS");
				adicionarlares(password,passwordequipa,passwordgestor);
			break;


			case 2:
				// Verificar Lares
				system("CLS");
				editarlares(password,passwordequipa,passwordgestor);
			break;


			case 3:
				// Editar Lares
				system("CLS");
				verificarlares(password,passwordequipa,passwordgestor);
			break;


			case 4:
				// Desativar Lares
				system("CLS");
				apagarlares(password,passwordequipa,passwordgestor);
			break;


			case 0:
				// Voltar ao Menu de Equipa
				system("CLS");
				Menuequipa(password,passwordequipa,passwordgestor);	
			break;


		 default:
            printf("Escolha invalida!\n");
            break;
        }	


	} while(opcao != 0);

}


// Sub Menu Equipa / Adicionar Lares
void adicionarlares(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variáveis
	char adicionar_lares;
	int distrito;


	do
	{
		// Adicionar Lares
		system("cls");
		printf("========== Adicionar Lares ==========");

		lar[id_lar].ID_Lar = id_lar;


		// Registo do Nome			
		printf("\n\nNome do lar: ");
		fflush(stdin);
        gets(lar[id_lar].Nome);

        strcpy(lar[id_lar].Regiao, equipa[ID_Equipa_Usar].regiao);


		// Registo da Morada			
        printf("\nMorada do Lar: ");
		fflush(stdin);
        gets(lar[id_lar].Morada);


        // Registo do número de Docentes
        printf("\nInsira o número de docentes do lar: ");
        scanf("%d", &lar[id_lar].n_idosos);


        // Registo do número de Docentes de risco
        printf("\nInsira o número de docentes de risco do lar (Idosos com mais de 65 anos): ");
        scanf("%d", &lar[id_lar].n_idosos_risco);

		lar[id_lar].Ativo = 1;
		id_lar ++;


		printf("\n\nPretende adicionar mais lares? (S/N)");
		scanf(" %c", &adicionar_lares);


	} while((adicionar_lares == 's') || (adicionar_lares == 'S'));

}


// Sub Menu Equipa / Verificar Lares
void editarlares(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variáveis
	int k, escolha_lar;
	char verificar_lares, verifica_mais, verificar_mais;


	do
	{
		// Verificar Lares
		system("cls");
		printf("========== Verificar Lares ==========");
		printf("\n\nLares Disponiveis: \n");


		// Listar Lares			
		for(k = 0; k < id_lar; k++)
		{
			if(lar[k].Ativo == 1)
			{
				printf("\n[%d] --- %s --- %s", lar[k].ID_Lar, lar[k].Nome, lar[k].Regiao);
			}

		}

		// Instrução de Repetição			
		printf("\n\nPretende visualizar os dados de algum dos Lares?\n(S/N): ");
		scanf(" %c", &verificar_lares);


		// Mostrar Informações do Lar			
		if((verificar_lares == 's') || (verificar_lares == 'S'))
		{
			// Inserir Numero do Lar 
			printf("\nInsira o ID do Lar que pretende visualizar: ");
			scanf("%d", &escolha_lar);

			// Mostar Nome do Lar 			
			printf("\nNome: %s", lar[escolha_lar].Nome);

			// Mostar Região do Lar			
			printf("\nRegião: %s", lar[escolha_lar].Regiao);

			// Mostar Morada do Lar			
			printf("\nMorada: %s", lar[escolha_lar].Morada);

			// Indicar se o Lar esta Ativo			
			if(lar[escolha_lar].Ativo == 1)
			{
				printf("\nEste lar encontra-se: Ativo");
			}
			else if (lar[escolha_lar].Ativo == 0)
			{
				printf("\nEste lar encontra-se: Inativo");
			}

		}

		// Instrução de Repetição			
		printf("\n\nPretende voltar a verificar os Lares?\n(S/N): ");
		scanf(" %c", &verificar_mais);

	} while((verificar_mais == 's') || (verificar_mais == 'S'));
}


// Sub Menu Equipa / Editar Lares
void verificarlares(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variáveis
	char editar_lar, voltar_editar;
	int id_editar, opcao_editar, distrito, k;


	do
	{
		// Editar Lares
		system("cls");
		printf("========== Editar Lares ==========");
		printf("\n\nLares Disponiveis: \n");


		// Listar Lares ativos
		for(k = 0; k < id_lar; k++)
		{
			if(lar[k].Ativo == 1)
			{
				printf("\n[%d] --- %s --- %s", lar[k].ID_Lar, lar[k].Nome, lar[k].Regiao);
			}			
		}

		// Instrução de Repetição
		printf("\n\nPretende editar a informação de algum lar?\n(S/N): ");
		scanf(" %c", &editar_lar);


		// Editar informações Lar escolhido      
		if((editar_lar == 's') || (editar_lar == 'S'))
		{
			printf("\nInsira o ID do lar que pretende editar: ");
			scanf("%d", &id_editar);

			do
			{
				// Menu
				printf("\n\nInsira que campo pretende editar: ");
				puts("= Editar Equipas=");
				printf("|1 --- Nome\t|");
				printf("\n|2 --- Região\t|");
				printf("\n|3 --- Morada\t|");
				printf("\n|0 --- Sair\t|\n");
				puts("=================");
				printf("\nOpcão: ");
				scanf("%d", &opcao_editar);

				switch(opcao_editar)
				{
					case 1:
						// editar nome do lar
						printf("\nNome do lar: ");
						fflush(stdin);
						gets(lar[id_editar].Nome);
						break;

					case 2:
						// menu do distritos
						system("CLS");
						puts("\n=========================== Distritos ===========================");
						printf("|1.Viana do Castelo\t| 7.Viseu\t\t| 13.Portalegre\t|\n");
    					printf("|2.Vila Real\t\t| 8.Guarda\t\t| 14.Lisboa\t|\n");
    					printf("|3.Bragança\t\t| 9.Coimbra\t\t| 15.Évora\t|\n");
    					printf("|4.Braga\t\t| 10.Castelo Branco\t| 16.Setúbal\t|\n");
    					printf("|5.Porto\t\t| 11.Leiria\t\t| 17.Bejat\t|\n");
    					printf("|6.Aveiro\t\t| 12.Santarém\t\t| 18.Faro\t|");
    					puts("\n=================================================================");
						printf("\nRegião onde se encontra o Lar: ");
						scanf("%d", &distrito);

						// Inserir Distrito do Lar
						switch(distrito)
						{
							case 1:
								strcpy(lar[id_editar].Regiao, "Viana do Castelo");
							break;

							case 2:
								strcpy(lar[id_editar].Regiao, "Vila Real");
							break;

							case 3:
								strcpy(lar[id_editar].Regiao, "Bragança");
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
								strcpy(lar[id_editar].Regiao, "Santarém");
							break;

							case 13:
								strcpy(lar[id_editar].Regiao, "Portalegre");
							break;

							case 14:
								strcpy(lar[id_editar].Regiao, "Lisboa");
							break;

							case 15:
								strcpy(lar[id_editar].Regiao,"Évora");
							break;

							case 16:
								strcpy(lar[id_editar].Regiao, "Setúbal");
							break;

							case 17:
								strcpy(lar[id_editar].Regiao, "Beja");
							break;

							case 18:
								strcpy(lar[id_editar].Regiao, "Faro");
							break;

							default:
								printf("Não escolheu um distrito válido");
						}

						break;

					case 3:
						// inserir morada do lar
						printf("\nMorada do Lar: ");
						fflush(stdin);
						gets(lar[id_editar].Morada);

						break;

				}

			}while(opcao_editar != 0);
		}

		// Instrução de Repetição
		printf("Prentende voltar a editar algum lar?\n(S/N): ");
		scanf("%c", &voltar_editar);

	}while((voltar_editar == 's') || (voltar_editar == 'S'));
}


// Sub Menu Equipa / Apagar Lares
void apagarlares(char *password,char *passwordequipa,char *passwordgestor)
{
	// variaveis
	int k;
	char desactivar_lar;
	int id_desactivar; 
	char confirmar_desactivar,desactivar_mais;

	do
	{
		system("cls");
		printf("========== Desactivar Lares ==========");
		printf("\n\nLares Disponiveis: \n");

		// Listar Lares Ativos
		for(k = 0; k < id_lar; k++)
		{
			if(lar[k].Ativo == 1)
			{
				printf("\n[%d] --- %s --- %s", lar[k].ID_Lar, lar[k].Nome, lar[k].Regiao);
			}

		}

		// Instrução de Repetição
		printf("\n\nPretende desactivar algum lar?\n(S/N): ");
		scanf(" %c", &desactivar_lar);

		// Apagar Lar Escolhido
		if((desactivar_lar == 's') || (desactivar_lar == 'S'))
		{
			printf("\n\nInsira o ID do lar que pretende desactivar: ");
			scanf("%d", &id_desactivar);

			printf("\n\nPretende mesmo desactivar este Lar?\n(S/N): ");
			scanf(" %c", &confirmar_desactivar);

			// Desativar Lar
			if((confirmar_desactivar == 's') || (confirmar_desactivar == 'S'))
			{
				lar[id_desactivar].Ativo = 0;
			}
			else if((confirmar_desactivar == 'n') || (confirmar_desactivar == 'N'))
			{
				lar[id_desactivar].Ativo = 1;
			}
		}

		// Instrução de Repetição
		printf("\n\nPretende desactivar mais algum lar?\n(S/N): ");
		scanf(" %c", &desactivar_mais);

	}while((desactivar_mais == 's') || (desactivar_mais == 'S'));
}


// Sub Menu Equipa / Gerir Agenda
void gerirAgendas(char *password,char *passwordequipa,char *passwordgestor)
{
	// variaveis
	int opcao;

	do
	{
		// Gestão de Agenda
		system("cls");			
		puts("");			
		puts("================= Gerir Agendas =================");
		printf("|\t1-Adicionar dados a Agenda\t\t|\n");
    	printf("|\t2-Visualizar Agenda de uma equipa\t|\n");
    	printf("|\t3-Editar Agenda de uma equipa\t\t|\n");
    	printf("|\t0-Voltar ao Menu Principal\t\t|\n");
    	puts("=================================================");
    	printf("\nOpção:");
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


// Sub Menu Equipa / Adicionar Agenda
void adicionarAgenda(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	char dados_agenda;
	int x;

	do
	{
		system ("cls");
		printf("========== Adicionar dados a agenda ==========");

		agenda[id_visita].ID_Visita = id_visita;

		// Listar Equipas			
		for(x = 0; x < ID_equipa; x ++)
		{
			printf("\n[%d] --- %s --- %s", equipa[x].id_equipa, equipa[x].Nome, equipa[x].regiao);
		}

		// Inserir Numero da Equipa					
		printf("\n\nInsira a que equipa pretende adicionar dados a agenda: ");
		scanf("%d", &agenda[id_visita].ID_Equipa);

		// lsitar Lares			
		for(x = 0; x < id_lar; x ++)
		{
			printf("\n[%d] --- %s --- %s", lar[x].ID_Lar, lar[x].Nome, lar[x].Regiao);
		}			

		// Inserir Numero do Lar			
		printf("\n\nInsira o Lar que a equipa terá de visitar: ");
		scanf("%d", &agenda[id_visita].ID_Lar);

		// Inserir Hora da Visita			
		printf("\nInsira a hora da visita: ");
		scanf("%s", &agenda[id_visita].hora);

		// Inserir Dia da Visita			
		printf("\nInsira o dia da visita: ");
		scanf("%s", &agenda[id_visita].data.dia);

		// Inserir Mês da Visita			
		printf("\nInsira o mês da visita: ");
		scanf("%s", &agenda[id_visita].data.mes);

		// Inserir Ano da Visita
		printf("\nInsira o ano da visita: ");
		scanf("%s", &agenda[id_visita].data.ano);

		id_visita++;

		// Instrução de Repetição			
		printf("\n\nPretende adicionar mais alguma visita? ");
		scanf(" %c", &dados_agenda);

	}
	while((dados_agenda == 's')||(dados_agenda == 'S'));
}


// Sub Menu Equipa / Ver Agenda
void visualizarAgenda (char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	int opcao, opcao1;
	int j;

	puts("========== Visualizar Agenda ==========");

	do
	{	

		printf("\nInsira o ID da equipa a que pretende ver a agenda: ");
		scanf(" %d", &opcao);

		puts("\n[ID] --- Equipa ---> Lar");

		// listar Marcações
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


// Sub Menu Equipa / Editar Agenda
void editarAgenda (char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	int x = 0, n;
	int opcao3, opcao4, opcao5;
	char alterar_agenda;

	puts("========== Editar Agenda ==========");

	do
	{	
		// Listar Equipas
		for(x = 0; x < ID_equipa; x++)
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

		printf("\n\nPretende alterar alguma marcação apresentada? ");
		scanf(" %c", &alterar_agenda);

		if((alterar_agenda == 's') || (alterar_agenda == 'S'))
		{
			//pedir qual marcação pretende mudar
			printf("\nInsira o ID da marcação que pretende alterar: ");
			scanf("%d", &opcao4);

			//encontrar a marcação
			for(x = 0; x < id_visita; x++)
			{
				if(agenda[x].ID_Visita == opcao4)
				{
					n = x;
				}
			}

			do
			{
				//menu para escolher a informação que pretende mudar
				system("cls");
				printf("========== Edição Agenda ==========");
				printf("\n\n1- ID da Equipa Responsavel");
				printf("\n2- ID do Lar a que vai ser realizada a visita");
				printf("\n3- Horas");
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
						// Inserir a equipa
						printf("Insira o ID da Equipa responsavel: ");
						scanf("%d", &agenda[n].ID_Equipa);
						break;

					case 2:
						// Inserir o lar
						printf("ID do Lar a que vai ser realizada a visita: ");
						scanf("%d", &agenda[n].ID_Lar);
						break;

					case 3:
						// Inserir as horas
						printf("Insira as horas da visita: ");
						scanf("%s", &agenda[n].hora);
						break;

					case 4:
						// Inserir o dia
						printf("Insira o dia da visita: ");
						scanf("%d", &agenda[n].data.dia);
						break;

					case 5:
						// Inserir o Mês
						printf("Insira o mês da visita: ");
						scanf("%d", &agenda[n].data.mes);
						break;

					case 6:
						// Inserir o Ano
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


// Sub Menu Gestor / Gerir Viaturas
void gerirViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	int opcao;

	do
	{

		system("cls");

		// Menu
    	puts("======== Gerir Viaturas =========");
    	printf("|1-Inserir Viaturas\t\t|\n");
    	printf("|2-Verificar Viaturas inseridas|\n");
    	printf("|3-Editar uma viatura\t\t|\n");
    	printf("|4-Desativar viatura\t\t|\n");
    	printf("|0-Voltar ao menu Principal\t|\n");
    	puts("=================================");
    	printf("Opção:");
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


// Sub Menu Gestor / Requisitar Viaturas
void adicionarViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	char opcao;

	do
	{
		system("cls");

		// ativar a viatura
		puts("========== Inserir viaturas ==========\n");
		Viaturas[ID_viatura].id_viatura = ID_viatura;
		Viaturas[ID_viatura].ativo = '1';

		// Inserir Marca 
		printf("\nMarca do carro:");
		fflush(stdin);
		gets(Viaturas[ID_viatura].marca);

		// Inserir Matricula
		printf("\nMatricula (AA-AA-AA): ");
		fflush(stdin);
		gets(Viaturas[ID_viatura].matricula);

		// Inserir Lugares da Viatura 	
		printf("\nNúmero de lugares: ");
		scanf("%d", &Viaturas[ID_viatura].nLugares);

		ID_viatura++;

		puts("Pretende inserir mais alguma viatura?");
		puts("\tSim---(s)\n \tNão---(n)");
		scanf(" %c", &opcao);


	}while(opcao == 'S' || opcao == 's');

}


// Sub Menu Gestor / Verificar Viaturas
void verificarViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	int opcao3, k;
	int opcao4;
	do
	{
		system("cls");
		puts("========== Verificar Viaturas ==========");

		// listar Viaturas
		for(k = 0; k < ID_viatura; k++)
		{
			if(Viaturas[k].ativo == 1)
			{
				printf("\n[%d] --- %d --- %s --- %s", Viaturas[k].id_viatura, Viaturas[k].nLugares ,Viaturas[k].marca, Viaturas[k].matricula);
			}


		}

		// Inserir Numero da Viatura	
		printf("\n\nPretende ver os dados relativos a que viatura?");
		scanf("%d", &opcao4);


		// Mostrar dados da Viatura			
		printf("\n\nA viatura da marca %s, com o ID %d, contém os seguintes dados: ", Viaturas[opcao4].marca, opcao4);        		

		 // Mostrar Matricula           		
        printf("\nMatricula: %s", &Viaturas[opcao4].matricula);

		// Mostrar Lugares da Viatura
		printf("Número de lugares %d\n", Viaturas[opcao4].nLugares);

		// Indicar se a viatura esta disponivel
		if(Viaturas[opcao4].ativo == '0')
		{
			puts("O veiculo está Inativo");
		}
		else if(Viaturas[opcao4].ativo == '1')
		{
			puts("O veiculo está Ativo");
		}


		printf("\n\nPretende vizualisar mais alguma viatura?");
		printf("(S)---sim\t(N)---não");
		scanf(" %c", &opcao3);

	}while(opcao3 == 's' || opcao3 == 'S');	
}


// Sub Menu Gestor / Editar Viatura
void editarViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	int k, identificador, escolha;
	char opcao;

	do
	{	
		puts("========== Editar viaturas ==========\n");

		// Listar viaturas disponiveis
		for(k = 0; k < ID_viatura; k++)
		{
			if(Viaturas[k].ativo == 1)
			{
				printf("\nNº Lugares %d --- %s --- %s", Viaturas[k].nLugares , Viaturas[k].matricula, Viaturas[ID_viatura].marca);
			}


		}

		// Inserir Numero da Viatura
		printf("Insira o ID da viatura\n");
    	scanf("%d", &identificador);
    	puts("1.Marca\n2.Matricula\n3.Lugares");
    	scanf("%d", &escolha);

    	switch(escolha)
		{
		 	case 1:
		 		// Inserir Marca da Viatura
		 		printf("Marca do carro:\n");
				fflush(stdin);
				gets(Viaturas[identificador].marca);
		 		break;					                     		

		 	case 3:
		 		// Inserir Matricula da Viatura
		 		printf("Matricula:\n");
				fflush(stdin);
				gets(Viaturas[identificador].matricula);
		 		break;

		 	case 6:
		 		// Inserir Numero de Lugares da Viatura
		    	printf("Número de lugares\n");
				scanf("%d", &Viaturas[identificador].nLugares);
		 		break;


		}

		puts("Pretende editar mais alguma viatura?");
		puts("\n\tSim---(s)\n \tNão---(n)");
		scanf(" %c", &opcao);

	}while(opcao == 'S' || opcao == 's');
}


// Sub Menu Gestor / Desativar Viaturas
void desactivarViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	int identificador, k;
	char opcao;

	do
	{	
		system ("cls");
		puts("========== Desativar Viatura ==========\n");

		// Listar Viaturas
		for(k = 0; k < ID_viatura; k++)
		{

			printf("Nº Lugares %d --- %s --- %s", Viaturas[k].nLugares , Viaturas[k].matricula, Viaturas[ID_viatura].marca);

		}

		// Identificar a viatura
		printf("Insira o ID da viatura\n");
    	scanf("%d", &identificador);

		// Desativar Viatura
		Viaturas[identificador].ativo = '0';		        					

		puts("Pretende remover mais alguma viatura?");
		puts("\tSim---(s)\n \tNão---(n)");
		scanf(" %c", &opcao);

	}while(opcao == 'S' || opcao == 's');
}


// Sub Menu Equipa / Questionario
void Questionario(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variáveis
	int i, k, n, opcaoQ1, opcaoQ2, opcaoQ3, opcaoQ4, opcaoQ5, id;
	char continuar;

	do
	{
		// Listar Lares
		for(k = 0; k < id_lar; k++)
		{
			printf("\n[%d] --- %s --- %s", lar[k].ID_Lar, lar[k].Nome, lar[k].Regiao);
		}

		// Pedir Numero do Lar
		printf("\n\nInsira o ID do Lar que pretende avaliar: ");
		scanf("%d", &id);

		Avaliacao[id].ID_Lar = id;
		Avaliacao[id].ID_Equipa = ID_Equipa_Usar;
		nota = 0;

		// Questionario
		for (i = 0; i < 5; i++)
		{

			system("cls");
			puts("========= QUESTIONÁRIO ===========\n");
			printf("Quiz %d/5\n", i+1);
			// Perguntas
			puts("Concorda que os Docentes são bem tratados pelos funcionário?\n");
			puts("1- Discordo Totalmente");
			puts("2- Discordo Parcialmente");
			puts("3- Neutro");
			puts("4- Concordo Parcialmente");
			puts("5- Concordo Totalmente\n");		
			printf("Opção:");
			scanf("%d", &opcaoQ1);

			// Atribuição da nota
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

			// Perguntas
			puts("\n\nConcorda que o Estabelicimento tem boas condições de segurança e higiene?\n");
			puts("1- Discordo Totalmente");
			puts("2- Discordo Parcialmente");
			puts("3- Neutro");
			puts("4- Concordo Parcialmente");
			puts("5- Concordo Totalmente\n");		
			printf("Opção:");
			scanf("%d", &opcaoQ2);

			// Atribuição da Nota
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

			// Perguntas
			puts("\n\nConcorda que a alimentação é boa e bem servida?\n");
			puts("1- Discordo Totalmente");
			puts("2- Discordo Parcialmente");
			puts("3- Neutro");
			puts("4- Concordo Parcialmente");
			puts("5- Concordo Totalmente\n");		
			printf("Opção:");
			scanf("%d", &opcaoQ3);

			// Atribuição da nota
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

			// Perguntas
			puts("\n\nConcorda que o ambiente entre os Docentes é agradável?\n");
			puts("1- Discordo Totalmente");
			puts("2- Discordo Parcialmente");
			puts("3- Neutro");
			puts("4- Concordo Parcialmente");
			puts("5- Concordo Totalmente\n");		
			printf("Opção:");
			scanf("%d", &opcaoQ4);

			// Atribuição da nota
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

			// Perguntas
			puts("\n\nConcorda que os funcionários tem uma boa relação de trabalho?\n");
			puts("1- Discordo Totalmente");
			puts("2- Discordo Parcialmente");
			puts("3- Neutro");
			puts("4- Concordo Parcialmente");
			puts("5- Concordo Totalmente\n");		
			printf("Opção:");
			scanf("%d", &opcaoQ5);

			// Atribuição da nota
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
		Notas[id_visita] = nota;
		id_visita++;
		
	
	
		system("cls");
		printf("\n\nPretende Realizar o Questionario sobre mais algum Lar? ");
		scanf(" %c", &continuar);

	}while((continuar == 's') || (continuar == 'S'));


}


// Sub Menu Equipa / Mostra Notas
void ContaAvaliacao(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	int id, continuar, k;

	do
	{
		printf("===== Lares Disponiveis: =====\n");

		// Listar Lares
		for(k = 0; k < id_lar; k++)
		{
			printf("\n[%d] --- %s --- %s", lar[k].ID_Lar, lar[k].Nome, lar[k].Regiao);
		}

		// Inserir Numero do Lar
		printf("\n\nInsira o Lar que pretende ver as estaticticas: ");
		scanf("%d", &id);

		// Mostar a Nota que o Lar Obteve 
		printf("\n\nA avaliacao do lar é: %d", Avaliacao[id].Avaliacao);
		puts("");
		printf("\n\n\nInsira 0 para voltar atras: ");
		scanf(" %d", &continuar);

	}while(continuar != 0);
}


// Sub Menu Equipa / Chefe de Equipa
void painelchefeequipa(char *password,char *passwordequipa,char *passwordgestor)
{
	system ("cls");

	// Variaveis
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
		// Listar Membros
		for(g = 0; g < ID_membro; g++)
		{
			if(membro[g].ID_Equipa == ID_Equipa_Usar)
			{
				printf("\n----- %d ---- %s \n", membro[g].id_membro, membro[g].Nome);
			}
		}

		// Inserir Numero do Chefe da Equipa
		printf("\nDigite o seu ID se for capitão, se não for por favor insira 500 para voltar atras: ");
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
						// Menu
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
							// Adicionar um Membro á Equipa
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

									// Inserir Nome
									printf("\nNome do novo membro: ");
									fflush(stdin);
									gets(membro[ID_membro].Nome);

									// Inserir Area do Membro
									printf("\nÁrea Profissional: ");
									printf("\n\t1 -- Medico\n\t2 -- Enfermeiro\n\t3 -- Assistente social\n\t4 --Tecnico Ambiental");
									printf("\nOpção: ");
									scanf(" %c", &membro[ID_membro].AreaProfissional);

									// Inserir Contacto do Membro
									printf("\nContacto: ");
									scanf("%d", &membro[ID_membro].contacto);

									// Inserir CC do Membro	
									printf("\nCartão de cidadão: ");
									scanf("%d", &membro[ID_membro].CC);

									// Inserir Morada do Membro
									printf("\nMorada: ");
									fflush(stdin);
									gets(membro[ID_membro].Morada);

									// Inserir E-Mail do Membro
									printf("\nEmail: ");
									fflush(stdin);
									gets(membro[ID_membro].email);

									// Perguntar de Possui Carta de Condução
									printf("\nPossui Carta de Condução: ");
									printf("\n\tSim---(s)\n\tNão---(n)");
									printf("\nOpção: ");
									scanf(" %c", &carta);

									if((carta == 's') || (carta == 'S'))
									{
										// Inserir Carta de Conução
										printf("\nInsira o Numero da Carta de Condução: ");
										fflush(stdin);
										gets(membro[ID_membro].CartaConducao);
									}
									else if((carta == 'n') || (carta == 'N'))
									{
										strcpy(membro[ID_membro].CartaConducao, "Não possui carta de condução");
									}
									ID_membro++;

									printf("\n\nPretende adicionar mais membros a alguma equipa?\n(S/N): ");
									scanf(" %c", &opcao);

								}while(opcao5 == 'S' || opcao5 == 's');
								break;

							// Editar Membro
							case 2:

								do
								{
									puts("========== Editar Membro da equipa ==========\n");

									// Listar Membros
									for(x = 0; x < ID_membro; x++)
									{
										if(membro[x].ID_Equipa == ID_Equipa_Usar)
										{
											if(strcmp(membro[x].AreaProfissional, "medico") == 0)
											{
												printf("%d --- %s --- Médico", membro[x].id_membro ,&membro[x].Nome);
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
										// Inserir Numero do Membro para Edição
										printf("\nInsira o ID do membro que pretende editar: ");
										scanf(" %d", &ID_editar);

										do
										{
											//Menu
											puts("===== Editar Membro =====");
											printf("|1 -- Nome\t\t|");
											printf("\n|2 -- Área Profissional\t|");
											printf("\n|3 -- Contacto\t\t|");
											printf("\n|4 -- Cartão de Cidadão\t|");
											printf("\n|5 -- Morada\t\t|");
											printf("\n|6 -- Email\t\t|");
											printf("\n|7 -- Carta\t\t|");
											printf("\n|0 -- Sair\t\t|");
											printf("=========================\n");
											printf("\nOpcao: ");
											scanf("%d", &opcao6);

											switch(opcao6)
											{
												// Editar Nome do Membro
												case 1:
													printf("\nNome do membro: ");
							    					fflush(stdin);
							    					gets(membro[ID_editar].Nome);
													break;

												// Editar Area do Membro	
												case 2:
													printf("\nÁrea Profissional: ");
							    					printf("\n\t1 -- Medico\n\t2 -- Enfermeiro\n\t3 -- Assistente social");
							    					printf("\nOpção: ");
							    					scanf(" %c", &membro[ID_editar].AreaProfissional);
													break;

												// Editar Contacto do Membro
												case 3:
													printf("\nContacto: ");
							   						scanf("%d", &membro[ID_editar].contacto);
													break;

												// Editar CC do Membro	
												case 4:
													printf("\nCartão de cidadão: ");
							   						scanf("%d", &membro[ID_editar].CC);
													break;

												// Editar Morada do Membro	
												case 5:
													printf("\nMorada: ");
							    					fflush(stdin);
							    					gets(membro[ID_editar].Morada);
													break;

												// Editar E-Mail do Membro	
												case 6:
													printf("\nEmail: ");
							    					fflush(stdin);
							    					gets(membro[ID_editar].email);
													break;

												// Perguntar se possuir Carta de Condução	
												case 7:
													printf("\nPossui Carta de Condução: ");
							    					printf("\n\tSim---(s)\n\tNão---(n)");
							    					printf("\nOpção: ");
							    					scanf(" %c", &carta1);

													if((carta1 == 's') || (carta1 == 'S'))
													{
														// Editar Numero da Carta de Condução do Membro
														printf("\nInsira o Numero da Carta de Condução: ");
														fflush(stdin);
							    						gets(membro[ID_editar].CartaConducao);
													}
													else if((carta1 == 'n') || (carta1 == 'N'))
													{
														strcpy(membro[ID_membro].CartaConducao, "Não possui carta de condução");
													}
													break;
											}

										}while(opcao6 != 0);

									}

									printf("\n\nPretende editar mais algum Membro?");
									puts("\n\tSim---(s)\n\tNão---(n)");
									printf("\nOpção: ");
									scanf(" %c", &opcao);

								}while(opcao == 'S' || opcao == 's');
								break;

							// Desativar Membro	
							case 3: 

				            	do
								{	
									puts("========== Desativar Membro da equipa ==========\n");

									// Listar Membros
									for(x = 0; x < ID_membro; x++)
									{
										if(strcmp(membro[x].AreaProfissional, "medico") == 0)
										{
											printf("\n%d --- %s --- Médico", membro[x].id_membro ,&membro[x].Nome);
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
										// Inserir Numero do Membro
										printf("\nInsira o ID do membro que pretende desactivar: ");
										scanf("%d", &opcao4);

										// Desativação do Membro
										membro[opcao4].ativo = '0';
									}

				        			puts("Pretende remover algum Membro de outra equipa?\n(S/N)");
				        			puts("\tSim---(s)\n \tNão---(n)");
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


// Menu Equipa / Menu de Visitas
void MenuVisita(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	int opcao;

	do
	{
		system("cls");
		// Menu
		puts("=============== Registar Visitas ================");
		printf("|\t1 -- Requisitar Viaturas para Visita\t|");
		printf("\n|\t2 -- Registar Visita\t\t\t|\n");
		printf("|\t0 -- Voltar para menu anterior\t\t|\n");
		puts("=================================================");
		printf("\nOpção: ");
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


// Sub Menu Visitas / Requisitar Visitar
void RequisitarViaturas(char *password,char *passwordequipa,char *passwordgestor)
{
	int k;
	char requisitar_mais;

	do
	{
		printf("Viaturas Disponiveis: \n");

		// Listar Visitas
		for(k = 0; k < ID_viatura; k++)
		{
			if(Viaturas[k].ativo == '1')
			{
				printf("\nID: %d Nº Lugares %d --- %s --- %s\n", Viaturas[k].id_viatura, Viaturas[k].nLugares , Viaturas[k].matricula, Viaturas[k].marca);
			}


		}

		// Inserir Numero da Viatura
		printf("Insira o ID da Viatura que pretende requisitar: ");
		scanf("%d", &reViaturas[ID_reqViatura].ID_Viatura);

		printf("\n\nVisitas Disponiveis: \n");

		// Listar Visitas Agendadas
		for(k = 0; k < id_visita; k++)
		{
			if(agenda[k].ID_Equipa == ID_Equipa_Usar)
			{
				printf("\n%d --- %d ---> %d", agenda[k].ID_Visita , agenda[k].ID_Equipa, agenda[k].ID_Lar);
			}
		}

		// Inserir Numero da Visita
		printf("Insira o ID da Visita onde esta viatura vai ser usada: ");
		scanf("%d", &reVisita[ID_reqViatura].ID_Visita);

		printf("\n\nPretende requisitar mais viaturas: ");
		scanf(" %c", &requisitar_mais);

	}while((requisitar_mais == 's') || (requisitar_mais == 'S'));
}


// Sub Menu Visita / Registar Visita
void RegistarVisita(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	char registarVisita;
	int n_covid;

	do
	{
		printf("========== Registo Visita ==========");		
		printf("\n\nInsira o ID do Lar que foi visitado: ");
		scanf("%d", &reVisita[ID_regVisita].ID_Visita);

		reVisita[ID_regVisita].ID_Equipa = ID_Equipa_Usar;
		reVisita[ID_regVisita].ID_Visita = ID_regVisita;

		// 
		printf("\nEscreva um Relatório sobre a Visita: ");
		fflush(stdin);
		gets(reVisita[ID_regVisita].Relatorio);

		// Inserir Numero de Teste realizados
		printf("\nInsira o numero de testes ao Covid 19 Realizados no Lar: ");
		scanf("%d", &reVisita[ID_regVisita].N_Testes);

		// Inseri Numero de Casos Positivos
		printf("\nInsira o numero de casos de Covid 19 encontrados no Lar: ");
		scanf("%d", &n_covid);

		reVisita[ID_regVisita].N_Covid = n_covid;

		/*
		if(n_covid > 0)
		{
			do
			{
				printf("\nEscreva um Relatório sobre a Visita: ");
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


// Sub Menu Visita / Ver Relatorio
void VerificarRelatorio(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variaveis
	int k, id_visita;
	char verRelatorio;

	do
	{
		printf("========== Verificar Relatorios ==========");

		printf("\n\nVisitas disponiveis para consulta:  \n");

		// Listar Visitas
		for(k = 0; k < ID_regVisita; k++)
		{
			printf("\n[%d] --- %d --- %d", reVisita[k].ID_Visita, reVisita[k].ID_Equipa, reVisita[k].ID_Lar);
		}

		// Inserir Numero da Visita
		printf("\n\nInsira de que visita pretende imprimir o relatório: ");
		scanf("%d", &id_visita);

		// Mostar Relatorio
		printf("\n\n Relatório: %s", reVisita[id_visita].Relatorio);

		// Mostar Casos Positivos
		printf("\n\n Casos de Covid: %d", reVisita[id_visita].N_Covid);

		// Mostrar Viaturas Requisitadas
		printf("\n\nForam usadas as seguintes viaturas: ");

		for(k = 0; k < ID_viatura; k++)
		{
			if(reVisita[k].ID_Visita == id_visita)
			{
				printf("\nID: %d Nº Lugares %d --- %s --- %s\n", Viaturas[k].id_viatura, Viaturas[k].nLugares , Viaturas[k].matricula, Viaturas[k].marca);
			}
		}

		// Insstrução de Repetição
		printf("\n\nPretende ver mais algum relatório: ");
		scanf(" %c", &verRelatorio);

	}while((verRelatorio == 's') || (verRelatorio == 'S'));
}


/*
// Sub Menu Visita / Avaliação da Visita
void MediaAvaliacoesVisitas(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variáveis
	int i, soma = 0, contadorAvaliacoes = 0;
	float media = 0;


	// Somar as avaliações das visitas
	for(i = 0; i < id_visita; i++)
	{
		// Calcular apenas as avaliações dos lares visitados
		if(Avaliacao[i].Avaliacao > 1)
		{
			soma += Avaliacao[i].Avaliacao;
			contadorAvaliacoes++;
		}		
	}

	// Calcular a média das avaliações
	media = soma / (float)contadorAvaliacoes;	
	printf("A média: %f", media);
}
*/
/*
// Sub Menu Visita / Listar Visitas 
void ListarVisitas(char *password,char *passwordequipa,char *passwordgestor)
{
	// Variáveis
	int i, j, id, maior;
	

	puts("Listagem dos Lares e as suas avaliações: ");
	// Lstar visitas
	for (i = 0; i < id_visita; i++)
	{
		for (j = i+1; j < id_visita - 1; j++)
		{
			if (Avaliacao[i].Avaliacao > Avaliacao[j].Avaliacao)
			{
				maior = Avaliacao[j].Avaliacao;
				Avaliacao[j].Avaliacao = Avaliacao[i].Avaliacao;
				Avaliacao[i].Avaliacao = maior;
				
				id = Avaliacao[j].ID_Lar;
				Avaliacao[j].ID_Lar = Avaliacao[i].ID_Lar;
				Avaliacao[i].ID_Lar = id;
			}
		}

		// Mostrar por ordem da melhor visita para a pior
		printf("\n%dº Lar %d - %d", i+1, id, maior);
	}
}
*/
