#include <stdio.h>
#include <stdlib.h>
#include "no.h"

NO *inicio;
int tam=0;

void addinicio (int elemento){

    NO *novo = malloc(sizeof(NO));
    novo->elemento=elemento;
    novo->prox = NULL;
    novo->ant = NULL;
    if(tam==0){
        inicio = novo;
        novo->ant=novo;
        novo->prox=novo;
    }else{
        novo->prox = inicio;
        novo->ant=inicio->ant;
        inicio->ant->prox=novo;
        inicio->ant=novo;
        inicio = novo;
    }
    tam++;
}

void addfim (int elemento){

    NO* novo = malloc(sizeof(NO));
    novo->elemento = elemento;
    novo->prox = NULL;
    novo->ant = NULL;

    if(tam==0){
        inicio=novo;
    }else{
        novo->prox = inicio;
        novo->ant=inicio->ant;
        inicio->ant->prox=novo;
        inicio->ant=novo;
    }
    tam++;
}

void addposicao (int posicao, int elemento){

    if(posicao>=0 && posicao<=tam){
    NO* novo = malloc(sizeof(NO));
    novo->elemento = elemento;
    novo->ant = NULL;
    novo->prox = NULL;

    if(posicao==0){
        addinicio(elemento);
    }else if (posicao==tam){
        addfim(elemento);
    }else{
        NO* aux = inicio;

        int i;
        for(i=0; i<posicao-1;i++){
            aux=aux->prox;
            }
        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox->ant = novo;
        aux->prox = novo;
        tam++;
        }

    }
}

void rminicio (){
    if(tam>0){
        NO* lixo = inicio;
        if(tam==1){
            inicio=NULL;
        }
        else{
            inicio->ant->prox=inicio->prox;
            inicio->prox->ant=inicio->ant;
            inicio=inicio->prox;
        }
    free(lixo);
    tam--;
    }else
    printf("Nao tem nada para ser removido");
    }

void rmfim (){
    if (tam>0){
            NO* lixo = inicio->ant;
        if(tam==1){
            inicio=NULL;
        }else{
            inicio->ant->ant->prox=inicio;
            inicio->ant=inicio->ant->ant;
        }
        free(lixo);
        tam--;
    }else
    printf("Nao tem nada para ser removido");
}

void rmposicao (int posicao){
    if(posicao>0 && posicao<tam && tam>0){
        if (posicao==1)
            rminicio();
        else if (posicao==tam)
            rmfim();
        else{
            NO* aux = inicio;
            int i;
            for(i=0;i<posicao-1;i++){
                aux=aux->prox;
            }
            NO* lixo = aux->prox;
            aux->prox=aux->prox->prox;
            aux->prox->prox->ant=aux;
            free(lixo);
            tam--;
            }
    }else
        printf("Nao tem nada para ser removido");

}



void imprimir () {
    int i=0;
    NO* aux=inicio;
        while(aux->prox!=inicio){
        printf("%d ",aux->elemento);
        aux=aux->prox;
    }
    printf("%d ",aux->elemento);
    printf("\n");
}

    void inverso (){

    int i, j;
    for(i=tam;i>=0;i--){
        NO *aux = inicio;
        for(j=0;j<i;j++){
            aux=aux->prox;
        }
        printf("%d ",aux->elemento);
    }

    }

    int soma (NO* aux){
        if(aux->prox != inicio){
            return aux->elemento + soma(aux->prox);
        }else{
            return aux->elemento;
        }
    }

    void removervalor (int valor){
    NO *aux = inicio;
    int i;
    for(i=0;i<tam;i++){
        if(aux->elemento!=elemento){
            aux = aux->prox;
        }else{
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;

        NO *aux2 = aux;
        free(aux2);
        }
    }
    }



int main () {

    NO* menor = malloc(sizeof(NO));

    addinicio(20);
    addinicio(10);
    addfim(40);
    addposicao(2,15);
    addposicao(4,10);
    addinicio(20);
    addinicio(15);
    addfim(5);
    addfim(5);
    printf("tam= %d\n", tam);
    imprimir();

    int u = soma(inicio);
    printf("%d ",u);

return 0;
}
