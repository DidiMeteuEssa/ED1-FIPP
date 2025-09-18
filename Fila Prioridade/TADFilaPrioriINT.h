#define MAXFILA 10

struct TpElemento
{
	int elemento, prioridade;
};

struct TpFila
{
	int fim;
	TpElemento fila[MAXFILA];
};

void Inicializar(TpFila &f)
{
	f.fim = -1;
}

void Inserir(TpFila &f, TpElemento elem)
{
	int i = f.fim;
	f.fim++;

	while (i >= 0 && f.fila[i].prioridade > elem.prioridade)
	{
		f.fila[i + 1] = f.fila[i];
		i--;
	}

	f.fila[i + 1] = elem;
}

TpElemento Retirar(TpFila &f)
{
	TpElemento retirado = f.fila[0];
	for (int i = 0; i < f.fim; i++)
		f.fila[i] = f.fila[i + 1];

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

void ExibirFila(TpFila f)
{
	int i = 0;
	TpElemento aux;

	while (!Vazia(f.fim))
	{
		aux = Retirar(f);
		printf("%d \t\t %d \n", aux.elemento, aux.prioridade);
	}
}
