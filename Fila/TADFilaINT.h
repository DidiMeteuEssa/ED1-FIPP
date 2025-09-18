#define MAXFILA 10

struct TpFila
{
	int fim, fila[MAXFILA];
};

void Inicializar(TpFila &f)
{
	f.fim = -1;
}

void Inserir(TpFila &f, int elemento)
{
	f.fila[++f.fim] = elemento;
}

int Retirar(TpFila &f)
{
	int retirado = f.fila[0];
	int aux;
	for(int i = 0; i < f.fim; i++)
		f.fila[i] = f.fila[i+1];
		
	f.fim--;
	
	return retirado;
}

char Vazia(int fim) 
{
	return fim == -1;
}

char Cheia(int fim) 
{
	return fim == MAXFILA - 1;
}

int ElementoInicio(TpFila f)
{
	return f.fila[0];
}

int ElementoFim(TpFila f)
{
	return f.fila[f.fim];
}

void ExibirFila(TpFila f)
{
	while(!Vazia(f.fim))
		printf("\n%d", Retirar(f));	
}


