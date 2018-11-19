#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int nos = 0;
    int nivel = 0;
    char tree[7][50];
    char no[10];
    int i = 0;
    int numeroDeNos;
    int posicao;
    int totalColuna = 50;
    int aux = 0;

    no[0] = '1';
    no[1] = '3';
    no[2] = '5';
    no[3] = '6';
    no[4] = '7';
    no[5] = '9';
    no[6] = '1';
    no[7] = '6';
    no[8] = '0';
    no[9] = '8';

    for(i = 0; i < 7; i++)
	{
        for(int j = 0; j < 50; j++)
		{
            tree[i][j] = '*';
        }
    }

    for(i = 0; i < 7; i++)
	{
		int cont = 0;
		numeroDeNos = pow(2, i) + 1;
        posicao = trunc(totalColuna/numeroDeNos);
        for(int j = 0; j < 50; j++)
		{
			if(aux + 1 == numeroDeNos)
			{
				continue;
			}
            if(cont == posicao) 
			{
                tree[i][j] = no[nos];
                nos++;
                cont = 0;
                aux++;
            }
            cont++;
        }
        aux = 0;
    }
    
    for(i = 0; i < 7; i++)
	{
        for(int j = 0; j < 50; j++)
		{
            printf("%c", tree[i][j]);
        }
        printf("\n");
    }
}
