#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void apresentacao() {
    printf("\n\n\t\t\t\t---------------------------------------------");
    printf("\n\t\t\tTrabalho da faculdade de Análise e Desevolvimento de Sistemas\n");
    printf("\t\t\t\t\t931 - PROGRAMAÇÃO ESTRUTURADA 2022/2");
    printf("\n\t\t\t\t---------------------------------------------");
    printf("\n\t\t\t\t\tAluno: Henrique Pinheiro Xavier");
    printf("\n\t\t\t\t\t\tMatrícula: 2022100679");
    printf("\n\t\t\t\tDisciplina: 931 - PROGRAMAÇÃO ESTRUTURADA 2022/2");
}

void fim() {
    printf("\n\t\t\t\t----------------- FIM -----------------------\n\n");
}

int somaPares(int vet[], int tam, int soma) {
    if(tam == 0) {
        return soma =+ soma;
    }
    else {
        if(vet[tam - 1] % 2 == 0) {
            return somaPares(vet, tam - 1, soma + vet[tam - 1]);
        } else {
            return somaPares(vet, tam - 1, soma);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    apresentacao();

    int i, vet1[10], vet2[10], vet3[10], vet4[10], vet5[10], totalPares = 0, maior, maiorPar, menor;

    srand(time(NULL));
    for(i=0; i < 10; i++) {
        vet1[i] = rand() % 100;
        vet2[i] = rand() % 100;
        vet3[i] = rand() % 100;
        vet4[i] = rand() % 100;
        vet5[i] = rand() % 100;
    }

    printf("\n\n\t\t\t5 vetores contendo 10 valores inteiros gerados aleatoriamente:");
    printf("\n\t\t\tNúmeros do vetor 1: ");
    for(i=0; i < 10; i++) {
        printf("%d ", vet1[i]);
    }

    printf("\n\t\t\tNúmeros do vetor 2: ");
    for(i=0; i < 10; i++) {
        printf("%d ", vet2[i]);
    }

    printf("\n\t\t\tNúmeros do vetor 3: ");
    for(i=0; i < 10; i++) {
        printf("%d ", vet3[i]);
    }

    printf("\n\t\t\tNúmeros do vetor 4: ");
    for(i=0; i < 10; i++) {
        printf("%d ", vet4[i]);
    }

    printf("\n\t\t\tNúmeros do vetor 5: ");
    for(i=0; i < 10; i++) {
        printf("%d ", vet5[i]);
    }

    maior = menor = vet2[0];
    maiorPar = vet2[0];
    for(i=0; i < 10; i++) {
        if(vet2[i] % 2 == 0) {
            if (maiorPar < vet2[i]) {
            maiorPar = vet2[i];
        }
        }

        if (maior < vet2[i]) {
            maior = vet2[i];
        }
        if (menor > vet2[i]) {
            menor = vet2[i];
        }
    }

    printf("\n\n\t\t\tSoma apenas dos valores pares de cada vetor utilizando uma função recursiva: ");
    printf("\n\t\t\tSoma dos pares do vetor 1: %d\n", somaPares(vet1, 10, 0));
    printf("\t\t\tSoma dos pares do vetor 2: %d\n", somaPares(vet2, 10, 0));
    printf("\t\t\tSoma dos pares do vetor 3: %d\n", somaPares(vet3, 10, 0));
    printf("\t\t\tSoma dos pares do vetor 4: %d\n", somaPares(vet4, 10, 0));
    printf("\t\t\tSoma dos pares do vetor 5: %d\n", somaPares(vet5, 10, 0));
    printf("\n\n\t\t\tRetornando o maior elemento PAR do vetor 2: ");
    printf("\n\t\t\tO maior elemento PAR do vetor 2 é: %d ", maiorPar);
    printf("\n\n\t\t\tRetornando o maior e menor elemento do vetor 2: ");
    printf("\n\t\t\tO maior elemento do vetor 2 é: %d | Menor elemento do vetor 2 é: %d\n", maior, menor);

    fim();

    return 0;
}
