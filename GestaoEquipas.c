#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


//																			ESTRUTURAS
// Estrutura Relatório
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
	// Configurações
	setlocale(LC_ALL, "Portuguese");
	
	// Variáveis
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
		puts("2- Relatórios");
		puts("3- Viaturas");
		puts("4- Questionário");
		puts("5- Estatísticas");
		puts("0- Sair");
		puts("");
		printf("Opção:");
		scanf("%d", &opcao);
		switch (opcao)
		{
			case 1:
				break;
			case 2:
				do
				{
					system("cls");
					puts("======== MENU RELATÓRIOS ==========\n");
					puts("1- Escrever Relatório");
					puts("2- Consultar Relatório");
					puts("0- Sair\n");
					printf("Opção:");
					scanf("%d", &opcao2);
					
					switch (opcao2)
					{
						case 1:
							system("cls");
							puts("============== RELATÓRIO =================");
							puts("");
							puts("");
							printf("Escreva o relatório desta visita:\n");
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
					printf("Opção: ");
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
							printf("Insira o número da Carta de Condução:\n");
							fflush(stdin);
							gets(v[n].nCartadeConducao);
							puts("");
							printf("Insira a Validade da Carta de Condução:\n");
							scanf("%d", &v[n].validadeCarta);
							puts("");
							printf("Insira a matrícula do carro que pretende requisitar:\n");
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
					puts("======== QUESTIONÁRIO ==========\n");
					puts("Deseja realizar o questionário sobre funcionamento do lar\n");
					puts("1- Continuar");
					puts("0- Voltar\n");
					printf("Opção:");
					scanf("%d", &opcaoQ);
					
					if (opcaoQ == 1)
					{
						Questionario(avaliacao, &contAvaliacao);
					}
					
				} while (opcaoQ != 0);
				
				break;

				
			case 5:
					system("cls");
					puts("======== MENU ESTATÍSTICAS ==========\n");
					printf("1- Consultar Estatísticas\t\t avaliaçao do lar: %d\n", avaliacao[n]);
					puts("0- Voltar\n");
					printf("Opção:");
					scanf("%d", &opcaoE);
					
				break;


			default:
				break;				
		}
		
	}while(opcao!=0);	
	
	getchar();
}


//																	PROCEDIMENTOS E FUNÇÕES
// Procedimento para apresentar os relatórios
void ApresentarRelatorio (Equipa *e, int n)
{
	// Variáveis
	int i;
	
	// Instrução de repetição para listar os relatórios
	for(i = 0; i < n ; i++)
	{
		printf("%s", e[i].relatorio);
	}
	if (i < 1)
	{
		printf("Ainda não há nenhum relatório sobre este lar :(");
	}
}


// Procedimento para apresentar os relatórios
void ApresentarViaturas (Viatura *v, int n)
{
	// Variáveis
	int i;
	
	system("cls");
	for (i = 0; i < n; i++)
	{
		puts("");
		puts("Viatura Requisitada:\n");
		printf("Matrícula: %s\n", v[i].matricula);
		printf("Condutor: %s\n",  v[i].nomeDoCondutor);
		printf("Carta de Condução: %s\n",  v[i].nCartadeConducao);
		printf("Validade da Carta de Condução: %d\n", v[i].validadeCarta);
		puts("");
	}
	if (n < 1)
	{
		printf("Ainda não foram requisitadas viaturas :(");
	}
	puts("0- Voltar");
	
}


// Procedimento Questionário
void Questionario (int *avaliacao, int *n)
{
	// Variáveis
	int i, opcaoQ1, opcaoQ2, opcaoQ3, opcaoQ4, opcaoQ5, nota = 0;
	
	
	avaliacao[*n] = 0;
	
	
	
	// Instrução de repetição para os 5 questionários
	for (i = 0; i < 5; i++)
	{
		nota = 0;
		system("cls");
		puts("========= QUESTIONÁRIO ===========\n");
		printf("Quiz %d/5\n", i+1);
		puts("Concorda que os Docentes são bem tratados pelos funcionário?\n");
		puts("1- Discordo Totalmente");
		puts("2- Discordo Parcialmente");
		puts("3- Neutro");
		puts("4- Concordo Parcialmente");
		puts("5- Concordo Totalmente\n");		
		printf("Opção:");
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
		
		
		puts("\n\nConcorda que o Estabelicimento tem boas condições de segurança e higiene?\n");
		puts("1- Discordo Totalmente");
		puts("2- Discordo Parcialmente");
		puts("3- Neutro");
		puts("4- Concordo Parcialmente");
		puts("5- Concordo Totalmente\n");		
		printf("Opção:");
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
		
		
		puts("\n\nConcorda que a alimentação é boa e bem servida?\n");
		puts("1- Discordo Totalmente");
		puts("2- Discordo Parcialmente");
		puts("3- Neutro");
		puts("4- Concordo Parcialmente");
		puts("5- Concordo Totalmente\n");		
		printf("Opção:");
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
		
		
		puts("\n\nConcorda que o ambiente entre os Docentes é agradável?\n");
		puts("1- Discordo Totalmente");
		puts("2- Discordo Parcialmente");
		puts("3- Neutro");
		puts("4- Concordo Parcialmente");
		puts("5- Concordo Totalmente\n");		
		printf("Opção:");
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
		
		
		puts("\n\nConcorda que os funcionários tem uma boa relação de trabalho?\n");
		puts("1- Discordo Totalmente");
		puts("2- Discordo Parcialmente");
		puts("3- Neutro");
		puts("4- Concordo Parcialmente");
		puts("5- Concordo Totalmente\n");		
		printf("Opção:");
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

