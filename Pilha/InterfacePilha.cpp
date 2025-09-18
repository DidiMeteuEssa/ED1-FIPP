#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>

#include "TADPilhaINT.h"

char Menu() 
{
	clrscr();
	printf("\n### M E N U - PILHA ###\n");
	printf("\n[A] Inicializar");
	printf("\n[B] PUSH");
	printf("\n[C] POP");
	printf("\n[D] Elemento TOPO");
	printf("\n[E] Exibir elementos da PILHA");
	printf("\n[F] Concatenar pilhas");
	printf("\n\n[ESC] Sair");
	printf("\n\nSua opcao: ");
	
	return toupper(getche());
}

void Concatenacao(TpPilha &p1, TpPilha p2)
{
	TpPilha aux;
	
	Inicializar(aux);
	
	while(!Vazia(p2.topo))
		PUSH(aux, POP(p2));
		
	while(!Vazia(aux.topo) && !Cheia(p1.topo))
		PUSH(p1, POP(aux));
		
}

void CadastrarPilha(TpPilha &pilha)
{
	int numero;
	printf("\n\nDigite o numero: ");
	scanf("%d", &numero);
	
	while(!Cheia(pilha.topo) && numero > 0)
	{
		if(numero != 0)
			PUSH(pilha, numero);
			
		printf("\nDigite o numero: ");
		scanf("%d", &numero);
		
	}
}

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

void Executar()
{	
	TpPilha p, p2;
	Inicializar(p);
	Inicializar(p2);
	int num;
	char opcao;
	do
	{
		opcao = Menu();
		switch(opcao)
		{
			case 'A':
				printf("\n\nA pilha foi inicializada com TOPO em -1!");
				getch();
				break;
				
			case 'B': 
				printf("\n\nPilha 1:");
				if(!Cheia(p.topo))
					CadastrarPilha(p);
				else
					printf("\n\nA pilha esta cheia!");
					
				printf("\n\nPilha 2:");
				if(!Cheia(p2.topo))
					CadastrarPilha(p2);	
				else
					printf("\n\nA pilha esta cheia!");
					
				getch();
				break;
				
			case 'C': 
				if(!Vazia(p.topo))
					printf("\n\nElemento [%d] retirado da pilha!", POP(p));
				else
					printf("\n\nA pilha esta vazia!");
					
				getch();
				break;
				
			case 'D': 
				if(!Vazia(p.topo))
					printf("\n\nElemento do topo: %d", ElementoTopo(p));
				else
					printf("\n\nA pilha esta vazia!");
			
				getch();
				break;
				
			case 'E': 
			
				if(!Vazia(p.topo))
				{
					printf("\n\nExibindo a pilha: \n");
					ExibirPilha(p);
				}
				
				else
					printf("\n\nA pilha esta vazia!");
					
				getch();
				break;
				
			case 'F': 
				if(!Vazia(p.topo))
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
					
		}
		
	} while (opcao != 27);
	
}

int main()
{
	Executar();
	return 0;
}
