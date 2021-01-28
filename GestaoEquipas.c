#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


//																			ESTRUTURAS
// Estrutura Relat�rio
typedef struct Equipa
{
	char relatorio[1000];
	
} Equipa;


// Estrutura Viatura
typedef struct Viatura 
{
	
	char nCartadeConducao[20];
	char nomeDoCondutor[50];
	char matricula[20];
	int validadeCarta;
	
} Viatura;


// 																			ASSINATURAS
void ApresentarRelatorio (Equipa *e, int i);
void ApresentarViaturas (Viatura *v, int n);
void Questionario (int *avaliacao, int *n);


//																			MAIN
int main(int argc, char *argv[]) 
{
	// Configura��es
	setlocale(LC_ALL, "Portuguese");
	
	// Vari�veis
	Viatura v[100];
	Equipa e[100];
	int avaliacao[100];
	int opcao, opcao2, opcao3, opcaoV, opcaoE, opcaoQ;
	
	// contadores
	int contAvaliacao = 0, i, j = 0, n = 0;
	
	
	do
	{	
		system("cls");
		puts("-------Bem-Vindo---------\n");
		puts("1- Agenda");
		puts("2- Relat�rios");
		puts("3- Viaturas");
		puts("4- Question�rio");
		puts("5- Estat�sticas");
		puts("0- Sair");
		puts("");
		printf("Op��o:");
		scanf("%d", &opcao);
		switch (opcao)
		{
			case 1:
				break;
			case 2:
				do
				{
					system("cls");
					puts("======== MENU RELAT�RIOS ==========\n");
					puts("1- Escrever Relat�rio");
					puts("2- Consultar Relat�rio");
					puts("0- Sair\n");
					printf("Op��o:");
					scanf("%d", &opcao2);
					
					switch (opcao2)
					{
						case 1:
							system("cls");
							puts("============== RELAT�RIO =================");
							puts("");
							puts("");
							printf("Escreva o relat�rio desta visita:\n");
							fflush(stdin);
							gets(e[j].relatorio);
							j++;
							system("cls");
							break;
							
						case 2:
							system("cls");
							ApresentarRelatorio (e, j);							
							getch();
							system("cls");
							break;
					}
					
				} while (opcao2 != 0);
				
			case 3:
				do
				{
					// MENU Viaturas
					system("cls");
					puts("========= MENU VIATURAS ============");
					puts("");
					puts("1- Requisitar Viaturas");
					puts("2- Consultar Viaturas Requisitadas");
					puts("0- Voltar\n");
					printf("Op��o: ");
					scanf("%d", &opcao3);
					
					switch (opcao3)
					{
						case 1:
							// Registo da viatura
							system("cls");
							printf("Insira o seu nome:\n");
							fflush(stdin);
							gets(v[n].nomeDoCondutor);
							puts("");
							printf("Insira o n�mero da Carta de Condu��o:\n");
							fflush(stdin);
							gets(v[n].nCartadeConducao);
							puts("");
							printf("Insira a Validade da Carta de Condu��o:\n");
							scanf("%d", &v[n].validadeCarta);
							puts("");
							printf("Insira a matr�cula do carro que pretende requisitar:\n");
							fflush(stdin);
							gets(v[n].matricula);
							n++;
							break;
					
						
						case 2:	
							system("cls");
							ApresentarViaturas (v, n);
							getch();
							system("cls");

							break;
					
						default:
							break;
					}
					
				} while (opcao3 != 0);
				
				break;
				
				
			case 4:
				do
				{
					system("cls");
					puts("======== QUESTION�RIO ==========\n");
					puts("Deseja realizar o question�rio sobre funcionamento do lar\n");
					puts("1- Continuar");
					puts("0- Voltar\n");
					printf("Op��o:");
					scanf("%d", &opcaoQ);
					
					if (opcaoQ == 1)
					{
						Questionario(avaliacao, &contAvaliacao);
					}
					
				} while (opcaoQ != 0);
				
				break;

				
			case 5:
					system("cls");
					puts("======== MENU ESTAT�STICAS ==========\n");
					printf("1- Consultar Estat�sticas\t\t avalia�ao do lar: %d\n", avaliacao[n]);
					puts("0- Voltar\n");
					printf("Op��o:");
					scanf("%d", &opcaoE);
					
				break;


			default:
				break;				
		}
		
	}while(opcao!=0);	
	
	getchar();
}


//																	PROCEDIMENTOS E FUN��ES
// Procedimento para apresentar os relat�rios
void ApresentarRelatorio (Equipa *e, int n)
{
	// Vari�veis
	int i;
	
	// Instru��o de repeti��o para listar os relat�rios
	for(i = 0; i < n ; i++)
	{
		printf("%s", e[i].relatorio);
	}
	if (i < 1)
	{
		printf("Ainda n�o h� nenhum relat�rio sobre este lar :(");
	}
}


// Procedimento para apresentar os relat�rios
void ApresentarViaturas (Viatura *v, int n)
{
	// Vari�veis
	int i;
	
	system("cls");
	for (i = 0; i < n; i++)
	{
		puts("");
		puts("Viatura Requisitada:\n");
		printf("Matr�cula: %s\n", v[i].matricula);
		printf("Condutor: %s\n",  v[i].nomeDoCondutor);
		printf("Carta de Condu��o: %s\n",  v[i].nCartadeConducao);
		printf("Validade da Carta de Condu��o: %d\n", v[i].validadeCarta);
		puts("");
	}
	if (n < 1)
	{
		printf("Ainda n�o foram requisitadas viaturas :(");
	}
	puts("0- Voltar");
	
}


// Procedimento Question�rio
void Questionario (int *avaliacao, int *n)
{
	// Vari�veis
	int i, opcaoQ1, opcaoQ2, opcaoQ3, opcaoQ4, opcaoQ5, nota = 0;
	
	
	avaliacao[*n] = 0;
	
	
	
	// Instru��o de repeti��o para os 5 question�rios
	for (i = 0; i < 5; i++)
	{
		nota = 0;
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
		
		
		avaliacao[*n] += nota;
		
	}

	n++;
	
}

