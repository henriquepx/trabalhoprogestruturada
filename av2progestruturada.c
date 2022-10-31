/*
Centro Universitário Unicarioca - Análise e Desenvolvimento de Sistemas
AV2 - Programação Estruturada [Turma 931 - PROGRAMAÇÃO ESTRUTURADA 2022/2]
Aluno: Henrique Pinheiro Xavier
Matrícula: 2022100679
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Lista{
    int elem;
    struct Lista *proximo;
}No;

void inserir_ordenado(No **lista, int numero){
    No *auxiliar, *novo = malloc(sizeof(No));

    if(novo){
        novo -> elem = numero;
        if(*lista == NULL){
            novo -> proximo = NULL;
            *lista = novo;
        }
        else if(novo -> elem < (*lista) -> elem){
            novo -> proximo = *lista;
            *lista = novo;
        }
        else{
            auxiliar = *lista;
            while(auxiliar -> proximo && novo -> elem > auxiliar -> proximo -> elem)
                auxiliar = auxiliar->proximo;
                novo -> proximo = auxiliar -> proximo;
                auxiliar -> proximo = novo;
        }
    }
    else
        printf("ERRO!\n");
}

No* remover(No **lista, int numero){
    No *aux, *remover = NULL;

    if(*lista){
        if((*lista)->elem == numero){
            remover = *lista;
            *lista = remover -> proximo;
        }
        else{
            aux = *lista;
            while(aux -> proximo && aux -> proximo -> elem != numero)
                aux = aux -> proximo;
            if(aux -> proximo){
                remover = aux -> proximo;
                aux -> proximo = remover -> proximo;
            }
        }
    }
    return remover;
}

void imprimir(No *Lista){
    printf("\n\tLista: ");
    while(Lista){
        printf("%d ", Lista -> elem);
        Lista = Lista -> proximo;
    }
    printf("\n\n");
}

int main(){

    setlocale(LC_ALL, "");

    int opcao, elem, anterior;
    No *removido, *lista = NULL;

    do {
        printf("\n [0] Sair");
        printf("\n [1] Inserir");
        printf("\n [2] Exibir");
        printf("\n [3] Remover\n\n");
        scanf("%d", &opcao);

        switch(opcao){

        case 1:
            printf("\nDigite um número: ");
            scanf("%d", &elem);
            inserir_ordenado(&lista, elem);
            break;

        case 2:
            imprimir(lista);
            break;

        case 3:
            printf("\nDigite o número a ser removido da lista: ");
            scanf("%d", &elem);
            removido = remover(&lista, elem);
            if(removido){
                printf("\nElemento a ser removido: %d\n", removido->elem);
                free(removido);
            }
            else
                printf("\nElemento inexistente!\n");
            break;

        default:
            if(opcao != 0)
                printf("\nOpção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}
