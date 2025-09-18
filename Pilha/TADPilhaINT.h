#define MAXPILHA 10

struct TpPilha
{
	int topo, pilha[MAXPILHA];
};

void Inicializar(TpPilha &p)
{
	p.topo = -1;
}

void PUSH(TpPilha &p, int elemento)
{
	p.pilha[++p.topo] = elemento;
}

int POP(TpPilha &p)
{
	return p.pilha[p.topo--];
}

char Vazia(int topo) 
{
	return topo == -1;
}

char Cheia(int topo) 
{
	return topo == MAXPILHA - 1;
}

int ElementoTopo(TpPilha p)
{
	return p.pilha[p.topo];
}

void ExibirPilha(TpPilha p)
{
	while(!Vazia(p.topo))
		printf("\n%d", POP(p));	
}


