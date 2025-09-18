struct filme{
    char nome[60], classif[6];
    int ano, duracao;
    float gasto,renda,espec;
};

//Funções que manipulam esses TpDado
int ExibirFilmes()
{
	printf("\n\n### Lista de filmes ###\n\n");
	filme reg;
    FILE *arq = fopen("filmes.txt","r");
     
    fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);

    while(!feof(arq))
    {
        printf("%s %d %s %.2f %.2f %d %.2f \n",reg.nome, reg.ano, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.espec);
     		
    	fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
     
    }
    printf("%s %d %s %.2f %.2f %d %.2f \n",reg.nome, reg.ano, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.espec);
    fclose(arq);
    
    getch();

}

int VerificarMaiorLucro()
{
	printf("\n\n### Filme com maior lucro ###\n");
	filme reg;
    FILE *arq = fopen("filmes.txt","r");
    char nome[50];
    float maiorLucro;
     
    fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
    maiorLucro = reg.renda - reg.gasto;
    while(!feof(arq))
    {
     	
		if(maiorLucro < (reg.renda - reg.gasto))
		{
			strcpy(nome, reg.nome);
			maiorLucro = reg.renda - reg.gasto;
		}	
     		
    	fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
     
    }
    fclose(arq);
    
    printf("\nO filme com maior lucro e: %s, tendo um lucro de U$%.2f milhoes.", nome, maiorLucro);
    getch();

}

int VerificarMaiorTaxaEspectadores()
{
	printf("\n\n### Filme com maior taxa de espectadores ###\n");
	filme reg;
    FILE *arq = fopen("filmes.txt","r");
    char nome[50];
    float maiorTaxa;
     
    fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
    maiorTaxa= reg.espec;
    while(!feof(arq))
    {
     	
		if(maiorTaxa < reg.espec)
		{
			strcpy(nome, reg.nome);
			maiorTaxa = reg.espec;
		}	
     		
    	fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
     
    }
    fclose(arq);
    
    printf("\nO filme com maior taxa de espectadores e: %s, tendo uma taxa de %.1f espectadores.", nome, maiorTaxa);
    getch();

}

int MediaDuracao()
{
	printf("\n\n### Duracao media dos filmes ###\n");
	filme reg;
    FILE *arq = fopen("filmes.txt","r");
    char nome[50];
    int duracaoTotal = 0;
    int qtdFilme = 1;
    float media;
     
    fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);

    while(!feof(arq))
    {
     	duracaoTotal += reg.duracao;
		qtdFilme++;
     		
    	fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
     
    }
    fclose(arq);
  
    media = duracaoTotal / qtdFilme;
    
    printf("\nA media de duracao dos filmes e: %.1f minutos.", media);
    getch();

}










