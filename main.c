//#include "header/FilaDinamica.h" // -> lista ligada
//#include "header/FilaEstatica.h" // -> vetor
//#include "header/PilhaDinamica.h" // -> lista ligada
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

typedef struct {
    char ***potes;
    char **times;
    int quantTimes;
    int N, K;
} vars;

void alocaTimes(vars * variaveis)
{
    // aloca quantidade de strings que tera o vetor
    variaveis->times = malloc(sizeof(char*) * variaveis->N);

    // aloca quantidade de caracteres por string dentro do vetor
    int j;
    for(j = 0; j < variaveis->N; j++)
        variaveis->times[j] = malloc(30 * sizeof(char));
}

void alocaPotes(vars * variaveis)
{
    // aloca numero de potes como linhas da matriz
    variaveis->potes = malloc(sizeof(char*) * variaveis->K);

    // aloca numero de colunas ou seja numero de times por pote
    int z;
    for(z = 0; z < variaveis->K; z++)
        variaveis->potes[z] = malloc(sizeof(char*) * variaveis->quantTimes);

    // aloca numero de caracteres por celula da matriz
    int w, b;
    for(w = 0; w < variaveis->K; w++)
        for(b = 0; b < variaveis->quantTimes; b++)
            variaveis->potes[w][b] = malloc(sizeof(char) * 30);

    return variaveis->potes;
}

void imprimeTimes(vars * variaveis)
{
    // testa vetor times
    printf("\n");
    int i;
    for(i = 0;i < variaveis->N; i++)
        printf("%s\n", variaveis->times[i]);
}

void imprimeMatriz(vars * variaveis)
{
    // testa a matriz de potes
    int m, j;
    for(m = 0; m < variaveis->K; m++)
    {  
        printf("\npote: ");
        for(j = 0; j < variaveis->quantTimes; j++)
        {
            if(variaveis->potes[m][j] != NULL)
                printf("%s ", variaveis->potes[m][j]);
        }
    }
}

void liberaMem(vars * variaveis)
{
    // libera memoria do vetor de times
    int k, j;
    for(k = 0; k < variaveis->N; k++)
        free(variaveis->times[k]);
    free(variaveis->times);

    // libera memoria do matriz de potes
    for(k = 0; k < variaveis->K; k++)
    {
        for(j = 0; j < variaveis->quantTimes; j++)
            free(variaveis->potes[k][j]);
        free(variaveis->potes[k]);
    }
    free(variaveis->potes);
}

int main()
{
    vars variaveis;

    // recebe N  e K
    scanf("%d %d", &variaveis.N, &variaveis.K);

    // vetor dos times
    alocaTimes(&variaveis);

    // verifica quantidade de times por pote
    variaveis.quantTimes = variaveis.N / variaveis.K;
    if (variaveis.N % variaveis.K != 0)
        variaveis.quantTimes += 1;

    // matriz dos potes
    alocaPotes(&variaveis);

    // recebe o nome dos times
    int i;
    for(i = 0;i < variaveis.N; i++)
        scanf("%s", variaveis.times[i]);

    // monta a matriz com os potes formados
    int x = 0, y = 0;
    for(i = 0; i < variaveis.N; i++)
    {
        variaveis.potes[x][y] = variaveis.times[i];
        x++;
        if(x == variaveis.K)
        {
            x = 0;
            y++;
        }
    }

    imprimeMatriz(&variaveis);

    liberaMem(&variaveis);

    return 0;
}