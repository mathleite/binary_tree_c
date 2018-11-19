#include "stdio.h"
#include "stdlib.h"
#include "function.c"

int main()
{
    struct No *Raiz = (struct No*) NULL;
    
    int Opt;
    do
    {
        system("cls");
        printf("1 - Inserir\n");
        printf("2 - Em-Ordem\n");
        printf("3 - Buscar Elemento Recursividade\n");       
        printf("0 - Sair\n");
        scanf("Escolha: %d", &Opt);
       
        if (Opt == 1)
        {
            int Id;
            printf("Informe o Id: ");
            scanf("%d", &Id);
            Raiz = AdicionarNoComRecursividade(Raiz, Id);            
        }        
        
        else if (Opt == 2)
        {
            EmOrdem(Raiz);
            printf("\n");
            system("pause");
        }
        
        else if (Opt == 3)
        {
            int Id;
            printf("Informe o Id: ");
            scanf("%d", &Id);
            struct No *NoLocalizado = BuscarNoComRecursividade(Raiz, Id);
            
            if (NoLocalizado == (struct No*) NULL)
                printf("Nao Localizado");
            else
                printf("Localizado No Endereco %x", NoLocalizado);

            printf("\n");
            system("pause");            
        }
                            
    } while (Opt != 0);
    
    return 0;
}
