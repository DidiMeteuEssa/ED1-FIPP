#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>

#include "Dados.h"

char Menu() 
{
	clrscr();
	printf("\n### M E N U ###\n");
	printf("\n[A] Cadastrar");
	printf("\n[B] Excluir");
	printf("\n[C] Consultar");
	printf("\n[D] Exibir");
	printf("\n[E] Relatorio em arquivo texto");
	printf("\n[F] Ler por caractere");
	printf("\n[G] Ler por string");
	printf("\n[H] Texto para maiusculo char");
	printf("\n[I] Texto para maiusculo string");
	printf("\n\n[ESC] Sair");
	printf("\n\nSua opcao: ");
	
	return toupper(getche());
}

void Executar()
{
	char opcao;
	do
	{
		opcao = Menu();
		switch(opcao)
		{
			case 'A': 
				Cadastrar();
				break;
				
			case 'B': 
				Excluir();
				break;
				
			case 'C': 
				Consultar();
				break;
				
			case 'D': 
				Exibir();
				break;
				
			case 'E': 
				RelatorioTexto();
				break;
				
			case 'F': 
				ExibeTxtCha("Relatorio.txt");
				break;
				
			case 'G': 
				ExibeTxtStr("Relatorio.txt");
				break;
				
			case 'H': 
				UpperCHR("Relatorio.txt");
				break;
				
			case 'I': 
				UpperSTR("Relatorio.txt");
				break;
					
		}
		
	} while (opcao != 27);
	
}

int main()
{
	Executar();
	return 0;
}
