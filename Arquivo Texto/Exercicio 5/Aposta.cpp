#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>

struct TpAposta 
{
	int NrAposta, Dezenas[7], Acertos[5], QtdAcerto;	
	char Data[11];
};

void LerAposta(char NomeTxt[50]) {
	FILE *PtrAposta = fopen(NomeTxt, "r");
	TpAposta A;
	if(PtrAposta == NULL)
		printf("\nErro ao abrir arquivo\n");
	else {
		
		fscanf(PtrAposta, "%d %s %d %d %d %d %d %d %d", &A.NrAposta, &A.Data, &A.Dezenas[0], &A.Dezenas[1], &A.Dezenas[2], &A.Dezenas[3], &A.Dezenas[4], &A.Dezenas[5], &A.Dezenas[6]);
		while(!feof(PtrAposta))
		{
			printf("\n\nAposta Nr.: %d \t Data: %s", A.NrAposta, A.Data);
			printf("\nDezenas apostadas: ");
			for(int i = 0; i < 7; i++)
			{
				printf("[%d] ", A.Dezenas[i]);
			}
			
			fscanf(PtrAposta, "%d %s %d %d %d %d %d %d %d", &A.NrAposta, &A.Data, &A.Dezenas[0], &A.Dezenas[1], &A.Dezenas[2], &A.Dezenas[3], &A.Dezenas[4], &A.Dezenas[5], &A.Dezenas[6]);
			
		}
		
		getch();
		
		fclose(PtrAposta);
	}
}
void VerificarAcerto(char NomeTxt[50], int Sorteio[5]) {
	FILE *PtrAposta = fopen(NomeTxt, "r");
	TpAposta A;
	if(PtrAposta == NULL)
		printf("\nErro ao abrir arquivo\n");
	else {
		
		printf("Numeros sorteados: ");
		for(int i=0; i < 5; i++)
		{
			printf("[%d] ", Sorteio[i]);
		}
		
		printf("\n");
		
		fscanf(PtrAposta, "%d %s %d %d %d %d %d %d %d", &A.NrAposta, &A.Data, &A.Dezenas[0], &A.Dezenas[1], &A.Dezenas[2], &A.Dezenas[3], &A.Dezenas[4], &A.Dezenas[5], &A.Dezenas[6]);
		while(!feof(PtrAposta))
		{
			A.QtdAcerto=0;
			for(int i = 0; i < 7; i++)
			{
				for(int j = 0; j < 5; j++)
				{
					if(A.Dezenas[i] == Sorteio[j])
					{
						A.Acertos[A.QtdAcerto++] = Sorteio[j];
					}	
				}
					
			}
			
						
			if(A.QtdAcerto == 3)
				printf("\nAposta Nr. %d acertou um terno!",A.NrAposta);
				
			if(A.QtdAcerto == 4)
				printf("\nAposta Nr. %d acertou uma quadra!",A.NrAposta);
			
			if(A.QtdAcerto == 5)
				printf("\nAposta Nr. %d acertou uma quina!",A.NrAposta);
				
			if(A.QtdAcerto >= 3)
			{
				printf("\nNumeros apostados: ");
				for(int i = 0; i < 7; i++)
				{
					printf("[%d] ", A.Dezenas[i]);
				}
				
				printf("\nNumeros acertados: ");
				for(int i = 0; i < A.QtdAcerto; i++)
					printf("[%d] ", A.Acertos[i]);
				printf("\n");
			}
				
			fscanf(PtrAposta, "%d %s %d %d %d %d %d %d %d", &A.NrAposta, &A.Data, &A.Dezenas[0], &A.Dezenas[1], &A.Dezenas[2], &A.Dezenas[3], &A.Dezenas[4], &A.Dezenas[5], &A.Dezenas[6]);
			
		}
		
		getch();
		
		fclose(PtrAposta);
	}
}

void VerificarAcertoTxt(char NomeTxt[50], int Sorteio[5]) {
	FILE *PtrAposta = fopen(NomeTxt, "r");
	TpAposta A;
	if(PtrAposta == NULL)
		printf("\nErro ao abrir arquivo\n");
	else {
		FILE *PtrRelatorio = fopen("Relatorio.txt", "w+");
		fprintf(PtrRelatorio,"Numeros sorteados: ");
		for(int i=0; i < 5; i++)
		{
			fprintf(PtrRelatorio, "[%d] ", Sorteio[i]);
		}
		
		fprintf(PtrRelatorio, "\n");
		
		fscanf(PtrAposta, "%d %s %d %d %d %d %d %d %d", &A.NrAposta, &A.Data, &A.Dezenas[0], &A.Dezenas[1], &A.Dezenas[2], &A.Dezenas[3], &A.Dezenas[4], &A.Dezenas[5], &A.Dezenas[6]);
		while(!feof(PtrAposta))
		{
			A.QtdAcerto=0;
			for(int i = 0; i < 7; i++)
			{
				for(int j = 0; j < 5; j++)
				{
					if(A.Dezenas[i] == Sorteio[j])
					{
						A.Acertos[A.QtdAcerto++] = Sorteio[j];
					}	
				}
					
			}
			
						
			if(A.QtdAcerto == 3)
				fprintf(PtrRelatorio, "\nAposta Nr. %d acertou um terno!",A.NrAposta);
				
			if(A.QtdAcerto == 4)
				fprintf(PtrRelatorio, "\nAposta Nr. %d acertou uma quadra!",A.NrAposta);
			
			if(A.QtdAcerto == 5)
				fprintf(PtrRelatorio, "\nAposta Nr. %d acertou uma quina!",A.NrAposta);
				
			if(A.QtdAcerto >= 3)
			{
				fprintf(PtrRelatorio, "\nNumeros apostados: ");
				for(int i = 0; i < 7; i++)
				{
					fprintf(PtrRelatorio, "[%d] ", A.Dezenas[i]);
				}
				
				fprintf(PtrRelatorio, "\nNumeros acertados: ");
				for(int i = 0; i < A.QtdAcerto; i++)
					fprintf(PtrRelatorio, "[%d] ", A.Acertos[i]);
				fprintf(PtrRelatorio, "\n");
			}
				
			fscanf(PtrAposta, "%d %s %d %d %d %d %d %d %d", &A.NrAposta, &A.Data, &A.Dezenas[0], &A.Dezenas[1], &A.Dezenas[2], &A.Dezenas[3], &A.Dezenas[4], &A.Dezenas[5], &A.Dezenas[6]);
			
		}
		printf("Verifique o relatorio gerado!");
		
		fclose(PtrAposta);
		fclose(PtrRelatorio);
	}
}

int main()
{
	int Sorteio[5];
	Sorteio[0] = 5;
	Sorteio[1] = 10;
	Sorteio[2] = 15;
	Sorteio[3] = 8;
	Sorteio[4] = 16;
	VerificarAcertoTxt("Apostas.txt", Sorteio);
	return 0;
}
