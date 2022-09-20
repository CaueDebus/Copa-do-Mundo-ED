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

    // criar as K potes
    Pilha * potes;

    // vetor dos times
    char **times;

    // aloca quantidade de strings que tera o vetor
    times = malloc(sizeof(char*) * N);

    // aloca quantidade de caracteres por string dentro do vetor
    int j;
    for(j = 0; j < N; j++)
        times[j] = malloc(20 * sizeof(char));

    // recebe o nome dos times
    int i;
    for(i = 0;i < N; i++)
    {
        scanf("%s", times[i]);
    }

    free(times);
    return 0;
}