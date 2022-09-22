#include "header/FilaDinamica.h" // -> lista ligada
#include "header/FilaEstatica.h" // -> vetor
#include "header/PilhaDinamica.h" // -> lista ligada
#include "header/PilhaEstatica.h" // -> vetor
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
    - A quantidade de gols marcados por um time em um partida deve ser um numero aleatorio
    entre 0 e 7, inclusive
    - Nao ha empates. Caso a quantidade de gols marcados por ambos os times em uma partida seja igual,
    descarte este placar e gere outro placar aleatorio para a mesma partida, ate que nao haja empate
    - Voce pode assumir que o numero N de times sera sempre par
    - Havera no maximo 50 times e no maximo 20 potes
    - Os nomes dos times serao strings de ate 30 caracteres cada, contendo apenas letras minusculas e
    maiusculas
*/

int main()
{
    // N times, K potes
    int N, K;

    // recebe N  e K
    scanf("%d %d", &N, &K);

    // vetor dos times
    char **times;

    // aloca quantidade de strings que tera o vetor
    times = malloc(sizeof(char*) * N);

    // aloca quantidade de caracteres por string dentro do vetor
    int j;
    for(j = 0; j < N; j++)
        times[j] = malloc(20 * sizeof(char));

    // matriz dos potes
    char ***potes;

    // aloca numero de potes como linhas da matriz
    potes = malloc(sizeof(char*) * K);

    // verifica quantidade de times por pote
    int quantTimes = N / K;
    if (N % K != 0)
        quantTimes += 1;

    // aloca numero de colunas ou seja numero de times por pote
    int z;
    for(z = 0; z < K; z++)
        potes[z] = malloc(sizeof(char*) * quantTimes);

    // aloca numero de caracteres por celula da matriz
    int w, b;
    for(w = 0; w < K; w++)
        for(b = 0; b < quantTimes; b++)
            potes[w][b] = malloc(sizeof(char) * 20);

    // recebe o nome dos times
    int i;
    for(i = 0;i < N; i++)
        scanf("%s", times[i]);

    // testa vetor times
    /*printf("\n");
    for(i = 0;i < N; i++)
        printf("%s\n", times[i]);*/

    // monta a matriz com os potes formados
    int x = 0, y = 0;
    for(i = 0; i < N; i++)
    {
        potes[x][y] = times[i];
        x++;
        if(x == K)
        {
            x = 0;
            y++;
        }
    }

    // testa a matriz de potes
    int m;
    for(m = 0; m < K; m++)
    {  
        printf("\npote: ");
        for(j = 0; j < quantTimes; j++)
        {
            if(potes[m][j] != NULL)
                printf("%s ", potes[m][j]);
        }
    }

    // libera memoria do vetor de times
    int k;
    for(k = 0; k < N; k++)
        free(times[k]);
    free(times);

    // libera memoria do matriz de potes
    for(k = 0; k < K; k++)
    {
        for(j = 0; j < quantTimes; j++)
            free(potes[k][j]);
        free(potes[k]);
    }
    free(potes);

    return 0;
}