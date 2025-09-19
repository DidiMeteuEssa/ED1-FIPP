#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "TADFilaCircuINT.h"

char Menu()
{
	system("cls");
	printf("\n### M E N U - FILA CIRCULAR COM PRIORIDADE ###\n");
	printf("\n[A] Inicializar");
	printf("\n[B] Inserir");
	printf("\n[C] Retirar");
	printf("\n[D] Elemento FIM");
	printf("\n[E] Exibir elementos da FILA");
	printf("\n\n[ESC] Sair");
	printf("\n\nSua opcao: ");

	return toupper(getche());
}

void CadastrarFila(TpFila &f)
{
	TpElemento elem;
	printf("\n\nDigite o numero: ");

	scanf("%d", &elem.elemento);

	while (!Cheia(f.fim) && elem.elemento > 0)
	{
		if (elem.elemento != 0)
		{
			printf("Digite a prioridade: ");
			scanf("%d", &elem.prioridade);
			Inserir(f, elem);
			printf("\nInicio %d    Fim %d     Cont %d", f.inicio, f.fim, f.cont);
		}

		printf("\nDigite o numero: ");
		scanf("%d", &elem.elemento);
	}
}

/*
int BuscaElemento(TpPilha p, int elemento)
{
	int i=0;
	while(!Vazio(p.topo) && p[i] != elemento)
		i++;

	if(!Vazio(p.topo))
		return i;
	else
		return -1;
}

void ExcluiElemento(TpPilha &p)
{
	int elemento;
	int busca;
	printf("\nQual elemento voce quer remover?");
	scanf("%d", &elemento);

	busca = BuscaElemento(p, elemento);

	if(busca == -1)
		printf("\nElemento nao encontrado!");
	else
		pop
}

*/

void Executar()
{
	TpFila f;
	Inicializar(f);
	char opcao;
	do
	{
		opcao = Menu();
		switch (opcao)
		{
		case 'A':
			printf("\n\nA FILA foi inicializada com TOPO em -1!");
			getch();
			break;

		case 'B':
			if (!Cheia(f.cont))
				CadastrarFila(f);
			else
				printf("\n\nA fila esta cheia!");

			getch();
			break;

		case 'C':
			if (!Vazia(f.cont))
			{
				printf("\n\nElemento [%d] retirado da fila!", Retirar(f));
				printf("\nInicio %d    Fim %d     Cont %d", f.inicio, f.fim, f.cont);
			}

			else
				printf("\n\nA fila esta vazia!");

			getch();
			break;

		case 'E':

			if (!Vazia(f.cont))
			{
				printf("\n\nExibindo a fila: \n");
				printf("\n\nElemento \t Prioridade\n");
				ExibirFila(f);
			}

			else
				printf("\n\nA fila esta vazia!");

			getch();
			break;

			/*
		case 'F':
			if(!Vazia(f.fim))
			{
				printf("\n\nConcatenacao feita!");
				Concatenacao(p, p2);
			}

			else
				printf("\n\nA pilha esta vazia!");

			getch();
			break;

		case 'G':
			if(!Vazia(p.topo))
				RemoverElemento(p);

			else
				printf("\n\nA pilha esta vazia!");

			getch();
			break;
				*/
		}

	} while (opcao != 27);
}

int main()
{
	Executar();
	return 0;
}