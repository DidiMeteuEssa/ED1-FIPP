#define MAXFILA 10

struct TpElemento
{
	int elemento, prioridade;
};

struct TpFila
{
	int inicio, fim, cont;
	TpElemento fila[MAXFILA];
};

void Inicializar(TpFila &f)
{
	f.inicio = 0;
	f.fim = -1;
	f.cont = 0;
}


void Inserir(TpFila &F, TpElemento novo)
{
	F.fim = (F.fim + 1) % MAXFILA;
	F.fila[F.fim] = novo;
	F.cont++;

	int i = F.fim;
	while (i != F.inicio && F.fila[i].prioridade < F.fila[(i - 1 + MAXFILA) % MAXFILA].prioridade)
	{
		TpElemento temp = F.fila[i];
		F.fila[i] = F.fila[(i - 1 + MAXFILA) % MAXFILA];
		F.fila[(i - 1 + MAXFILA) % MAXFILA] = temp;
		i = (i - 1 + MAXFILA) % MAXFILA;
	}
}

TpElemento Retirar(TpFila &F)
{
	TpElemento vazio = {'\0', -1};
	TpElemento retirado = F.fila[F.inicio];
	F.inicio = (F.inicio + 1) % MAXFILA;
	F.cont--;
	return retirado;
}


char Vazia(int cont)
{
	return cont == 0;
}

char Cheia(int cont)
{
	return cont == MAXFILA;
}

TpElemento retornarInicio(TpFila &F)
{
	return F.fila[F.inicio];
}

TpElemento retornarFim(TpFila &F)
{
	return F.fila[F.fim];
}

void ExibirFila(TpFila F)
{
	int i = F.inicio;
	for (int c = 0; c < F.cont; c++)
	{
		printf("\n %d \t\t %d\n", F.fila[i].elemento, F.fila[i].prioridade);
		i = (i + 1) % MAXFILA;
	}
}
