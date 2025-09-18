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
	printf("\n[A] Listar Filmes");
	printf("\n[B] Verificar filme com maior lucro");
	printf("\n[C] Verificar filme com maior taxa de espectadores");
	printf("\n[D] Duracao media dos filmes");
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
				ExibirFilmes();
				break;
				
			case 'B': 
				VerificarMaiorLucro();
				break;
				
			case 'C': 
				VerificarMaiorTaxaEspectadores();
				break;
				
			case 'D': 
				MediaDuracao();
				break;	
		}
		
	} while (opcao != 27);
	
}

int main()
{
	Executar();
	return 0;
}


 

 
 

