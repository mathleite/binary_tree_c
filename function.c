#include "stdio.h"
#include "stdlib.h"

struct No
{
    int Id;
    struct No *Esquerda;
    struct No *Direita;
};

#define tamanho 10

struct tipo_fila{
	struct No *dados[tamanho];
	int ini;
	int fim;
};

int i;

struct tipo_fila fila;

void mostra_fila(){
	printf(" === Fila ===\n");
	for(i = fila.ini; i < tamanho; i++){
		printf(" [%i]", fila.dados[i]);
	}
}

void enfileira(struct No *elemento){
	if(fila.fim == tamanho){
		printf("Filha cheia.\n");
		system("pause");

	} else {
		fila.dados[fila.fim] = elemento;
		fila.fim++;
	}
}

struct No* desenfileira(){
	struct No *elemento;
	if(fila.fim == fila.ini){
		return NULL;
	} else {
	    elemento = fila.dados[fila.ini];
	    for(i = fila.ini; i < fila.fim; i++){
	    	fila.dados[i] = fila.dados[i + 1];
	    }
        fila.dados[fila.fim] = 0;
		fila.fim--;
		return elemento;
	}
}

struct No *Atual = (struct No*) NULL;
struct No *Ultimo = (struct No*) NULL;

struct No* AdicionarNoComRecursividade(struct No *Raiz, int Id)
{
    if (Raiz == (struct No*) NULL)
    {
        Raiz = (struct No*) malloc(sizeof(struct No));
        Raiz-> Id = Id;
        Raiz-> Esquerda = (struct No*) NULL;
        Raiz-> Direita = (struct No*) NULL;
        return Raiz;
    }

    if (Id < Raiz-> Id)
        Raiz-> Esquerda = AdicionarNoComRecursividade(Raiz-> Esquerda, Id);
    else if (Id > Raiz-> Id)
        Raiz-> Direita = AdicionarNoComRecursividade(Raiz-> Direita, Id);

    return Raiz;
}

// Retorna apenas o endereço do nó localizado
struct No* BuscarNoComRecursividade(struct No *Raiz, int Id)
{
    if (Raiz == (struct No*) NULL)
        return Raiz;

    if (Raiz-> Id == Id)
        return Raiz;


    if (Id > Raiz-> Id)
    {
        return BuscarNoComRecursividade(Raiz-> Direita, Id);
    }
    else if (Id < Raiz-> Id)
    {
        return BuscarNoComRecursividade(Raiz-> Esquerda, Id);
    }
}

void EmOrdem(struct No *NoAtual)
{
    if (NoAtual == (struct No*) NULL)
        return;

    EmOrdem(NoAtual-> Esquerda);
    printf("%d ", NoAtual->Id );
    EmOrdem(NoAtual-> Direita);
}

void MostraArvore(struct No *NoAtual)
{
    if (NoAtual == (struct No*) NULL)
        return;

    for (int i = 0; i < 16; i++)
    {
        if (NoAtual->Esquerda == (struct No*) NULL && NoAtual->Direita == (struct No*) NULL)
        {
            //printf("\n     %d <- Pai\n", NoAtual->Id );
        }
        else if (NoAtual->Esquerda != (struct No*) NULL && NoAtual->Direita == (struct No*) NULL ||
                 NoAtual->Esquerda == (struct No*) NULL && NoAtual->Direita == (struct No*) NULL)
        {
            if (NoAtual->Esquerda->Esquerda == (struct No*) NULL && NoAtual->Esquerda->Direita == (struct No*) NULL)
            {
                printf("\n     %d <- Pai\n", NoAtual->Id );
                printf("    /\n");
                printf("%d <- Folha\n", NoAtual->Esquerda->Id );
            }
            else
            {
                printf("\n     %d <- Pai\n", NoAtual->Id );
                printf("    /\n");
                printf("%d <- Filho\n", NoAtual->Esquerda->Id );
                enfileira(NoAtual->Esquerda);
            }
        }
        else if (NoAtual->Direita != (struct No*) NULL && NoAtual->Esquerda == (struct No*) NULL)
        {
            if (NoAtual->Direita->Esquerda == (struct No*) NULL && NoAtual->Direita->Direita == (struct No*) NULL)
            {
                printf("\n     %d <- Pai\n", NoAtual->Id );
                printf("       \\\n ");
                printf("       %d <- Folha\n", NoAtual->Direita->Id );
            }
            else
            {
                printf("\n     %d <- Pai\n", NoAtual->Id );
                printf("       \\\n ");
                printf("       %d <- Filho\n", NoAtual->Direita->Id );
                enfileira(NoAtual->Direita);
            }
        }
        else
        {
            if (NoAtual->Direita->Esquerda == (struct No*) NULL && NoAtual->Direita->Direita == (struct No*) NULL &&
                NoAtual->Esquerda->Esquerda == (struct No*) NULL && NoAtual->Esquerda->Direita == (struct No*) NULL)
            {
                printf("\n     %d <- Pai\n", NoAtual->Id );
                printf("    /  \\\n ");
                printf("  %d   %d <- Folhas\n", NoAtual->Esquerda->Id, NoAtual->Direita->Id);
            }
            else
            {
                printf("\n     %d <- Pai\n", NoAtual->Id );
                printf("    /  \\\n ");
                printf("  %d   %d <- Filhos\n", NoAtual->Esquerda->Id, NoAtual->Direita->Id);
                enfileira(NoAtual->Esquerda);
                enfileira(NoAtual->Direita);
            }
        }

        NoAtual = desenfileira();

        if (NoAtual == NULL)
            break;
    }
}
