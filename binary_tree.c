#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "function.c"

int main()
{
    struct No *Raiz = (struct No*) NULL;

    int vetor[] = {35, 43, 23, 12, 77, 45, 94, 7, 42, 68, 81, 33, 2, 18, 67, 38};

    int Opt;
    int TamanhoVetor = sizeof(vetor)/sizeof(vetor[0]);
    do
    {
        system("cls");
        printf("1 - Inserir\n");
        printf("2 - Em-Ordem\n");
        printf("3 - Buscar Elemento Recursividade\n");
        printf("4 - Inserir vetor\n");
        printf("5 - Busca sequencial no Vetor\n");
        printf("6 - Mostrar Arvore Binaria\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &Opt);

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
            printf("\n");;
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

        else if (Opt == 4)
        {
            for(int i = 0; i < TamanhoVetor; i++)
            {
                int meio;
                if(i == 0)
                {
                    meio = trunc(((TamanhoVetor-1)) / 2);
                    Raiz = AdicionarNoComRecursividade(Raiz, vetor[meio]);
                }
                else if (i != meio)
                {
                    Raiz = AdicionarNoComRecursividade(Raiz, vetor[i]);
                }
            }
            printf("Arvore montada\n");
            system("pause");
        }

        else if (Opt == 5)
        {
            system("cls");
            int i;
            int busca;
            int elemento;

            printf("Vetor: ");

            for (i = 0; i < TamanhoVetor; i++)
            {
                printf("%d ", vetor[i]);
            }

            i = 0;

            printf("\nDigite o elemento a ser buscado: ");
            scanf("%d", &busca);

            printf("\nElementos verificados: ");

            while (elemento != busca)
            {
                elemento = vetor[i];
                printf("%d ", elemento);
                i++;
            }

            printf("\nNumero de iteracoes: %d\n", i);

            system("pause");
        }

        else if (Opt == 6)
        {
            MostraArvore(Raiz);
            system("pause");
        }

    } while (Opt != 0);

    return 0;
}
