struct TpDado
{
	int codigo;
	char nome[30];
	float valor;
};

//Funções que manipulam esses TpDado
int BuscaCodigo(FILE *PtrArq, int codigo)
{
	TpDado R;
	rewind(PtrArq);
	fread(&R, sizeof(TpDado), 1, PtrArq);
	while(!feof(PtrArq) && codigo != R.codigo)
		fread(&R, sizeof(TpDado), 1, PtrArq);
	
	if(!feof(PtrArq))
		return ftell(PtrArq) -  sizeof(TpDado);
	else 
		return -1;

}

void Cadastrar(void)
{
	TpDado Reg;
	int desl;
	FILE *Ptr = fopen("Dados.dat", "ab+");
	printf("\n\n### Cadastrar Dados ###\n");
	printf("\nCodigo: ");
	scanf("%d", &Reg.codigo);
	while(Reg.codigo > 0) 
	{
		desl = BuscaCodigo(Ptr, Reg.codigo);
		if(desl == -1) 
		{
			printf("Nome: ");
			fflush(stdin);
			gets(Reg.nome);
			printf("Valor: R$");
			scanf("%f", &Reg.valor);
			fwrite(&Reg, sizeof(TpDado), 1, Ptr);
		} 
		else 
		{
			printf("\nEsse codigo ja existe!\n");
		}
		
		
		printf("\nCodigo: ");
		scanf("%d", &Reg.codigo);
	}
	
	fclose(Ptr);
}

void Excluir(void)
{
	FILE *Ptr = fopen("Dados.dat","rb");
	TpDado Reg;
	int pos, AuxCod;
	printf("\n## Exclusao no Arquivo ##\n");
	if (Ptr == NULL)
		printf("\nErro de abertura!\n");
	else
		{
			printf("\nCodigo a Excluir: ");
			scanf("%d",&AuxCod);
			pos = BuscaCodigo(Ptr,AuxCod);
			if (pos==-1)
			{
				printf("\nCodigo nao encontrado!\n");
				fclose(Ptr);
				getch();
			}
			else
				{
					printf("\n** Dados Encontrados **\n");
					fseek(Ptr,pos,0);
					fread(&Reg,sizeof(TpDado),1,Ptr);
					printf("Codigo: %d\n",Reg.codigo);
					printf("Nome: %s\n",Reg.nome);
					printf("Codigo: %.2f\n",Reg.valor);
					printf("\nConfirma a Exclusao (S/N)?");
					if (toupper(getche())=='S')
					{
						FILE *PtrTemp = fopen("TempDados.dat","wb");
						rewind(Ptr);
						fread(&Reg,sizeof(TpDado),1,Ptr);
						while (!feof(Ptr))
						{
							if(AuxCod!=Reg.codigo)
								fwrite(&Reg,sizeof(TpDado),1,PtrTemp);
							
							fread(&Reg,sizeof(TpDado),1,Ptr);
						}
						fclose(Ptr);
						fclose(PtrTemp);
						remove("Dados.dat");
						rename("TempDados.dat","Dados.dat");
						printf("\n** Exclusao Concluida! **\n");
						getch();
					}
					else fclose(Ptr);
				}
		}	
}

void Consultar(void)
{
	FILE *Ptr = fopen("Dados.dat", "rb");
	TpDado Reg;
	int desl, auxcod;
	
	if(Ptr == NULL) 
		printf("\nArquivo nao aberto!\n");
	else
	{
		printf("\n\nDigite o codigo a ser consultado: ");
		scanf("%d", &auxcod);
		
		desl = BuscaCodigo(Ptr, auxcod);
		if(desl == -1)
			printf("\nCodigo nao encontrado!\n");
		else
		{
			fseek(Ptr, desl, 0);
			fread(&Reg, sizeof(TpDado), 1, Ptr);
			printf("\nCodigo: %d",Reg.codigo);
			printf("\nNome: %s",Reg.nome);
			printf("\nValor: R$%.2f",Reg.valor);
		}
		
		fclose(Ptr);
		getch();
	}
}

void Exibir(void)
{
	int i = 1;
	FILE *Ptr = fopen("Dados.dat", "rb");
	TpDado Reg;
	printf("\n\n## Conteudo do Arquivo ##\n");
	if(Ptr == NULL) 
		printf("\nErro de abertura!zn");
	else
	{
		fread(&Reg, sizeof(TpDado), 1, Ptr);
		while(!feof(Ptr))
		{
			printf("\n#%d \t %d \t %s \t R$%.2f", i++, Reg.codigo, Reg.nome, Reg.valor);
			
			fread(&Reg, sizeof(TpDado), 1, Ptr);
		}
		fclose(Ptr);
	}
	
	getch();
}

void RelatorioTexto()
{
	int i = 1;
	FILE *Ptr = fopen("Dados.dat", "rb");
	FILE *PtrTxt = fopen("Relatorio.txt", "w");
	TpDado Reg;
	printf("\n\n## Conteudo do Arquivo ##\n");
	if(Ptr == NULL) 
		printf("\nErro de abertura!zn");
	else
	{
		fprintf(PtrTxt,"Codigo \t Nome \t Valor R$\n");
		fread(&Reg,sizeof(TpDado),1,Ptr);
		while(!feof(Ptr))
		{
			fprintf(PtrTxt,"%d \t %s \t R$%.2f\n",Reg.codigo,Reg.nome,Reg.valor);
			fread(&Reg,sizeof(TpDado),1,Ptr);
		}
		fclose(Ptr);
		fclose(PtrTxt);
		printf("\n*** Relatorio de dados gerado! ***\n");
	}
	
	getch();
}

void ExibeTxtCha(char NomeTxt[100])
{
	char caractere;
	FILE *PtrTxt = fopen(NomeTxt, "r");
	if(PtrTxt == NULL)
		printf("\nErro de Abertura\n");
	else
	{
		printf("\n\n");
		caractere = fgetc(PtrTxt);
		while(!feof(PtrTxt))
		{
			printf("%c", caractere);
			caractere = fgetc(PtrTxt);
		}
		fclose(PtrTxt);
	}
	getch();
}

void ExibeTxtStr(char NomeTxt[100])
{
	char linha[100];
	FILE *PtrTxt = fopen(NomeTxt, "r");
	if(PtrTxt == NULL)
		printf("\nErro de Abertura\n");
	else
	{
		printf("\n\n");
		fgets(linha, 100, PtrTxt);
		while(!feof(PtrTxt))
		{
			printf("%s", linha);
			fgets(linha, 100, PtrTxt);
		}
		fclose(PtrTxt);
	}
	getch();
}

void UpperCHR(char NomeTxt[100])
{
	char caractere;
	FILE *PtrTxt = fopen(NomeTxt, "r");
	FILE *PtrUpp = fopen("RelUpper.txt", "w");
	printf("\n## Converte Texto mara Maiusculo ##\n");
	if(PtrTxt == NULL)
		printf("\nErro de Abertura\n");
	else
	{
		printf("\n\n");
		caractere = fgetc(PtrTxt);
		while(!feof(PtrTxt))
		{
			fputc(toupper(caractere), PtrUpp);
			caractere = fgetc(PtrTxt);
		}
		fclose(PtrTxt);
		fclose(PtrUpp);
	}
	getch();
}

void UpperSTR(char NomeTxt[100])
{
	char linha[100];
	FILE *PtrTxt = fopen(NomeTxt, "r");
	FILE *PtrUpp = fopen("RelUpper.txt", "w");
	printf("\n## Converte Texto mara Maiusculo ##\n");
	if(PtrTxt == NULL)
		printf("\nErro de Abertura\n");
	else
	{
		printf("\n\n");
		fgets(linha, 100, PtrTxt);
		while(!feof(PtrTxt))
		{
			strupr(linha);
			
			fputs(linha, PtrUpp);
			fgets(linha, 100, PtrTxt);
		}
		fclose(PtrTxt);
		fclose(PtrUpp);
	}
	getch();
}










