#include "stdio.h"
#include "stdlib.h"

struct No
{
    int Id;
    struct No *Esquerda;
    struct No *Direita;
};

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
        return BuscarNoComRecursividade(Raiz-> Direita, Id);
    else if (Id < Raiz-> Id)
        return BuscarNoComRecursividade(Raiz-> Esquerda, Id);
}

void EmOrdem(struct No *NoAtual)
{
    if (NoAtual == (struct No*) NULL)
        return;
  
    EmOrdem(NoAtual-> Esquerda); 
    printf("%d ", NoAtual->Id );
    EmOrdem(NoAtual-> Direita);
}

