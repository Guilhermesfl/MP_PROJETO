#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include <assert.h>

void TESTE_CRIA_E_RETORNA_NOME(grafo *G, char* nome);
void TESTE_ADICIONA_VERTICE(grafo *G, char *nome);
void TESTE_EDITA_VERTICE(grafo *G, char *nome);
void TESTE_REMOVE_VERTICE(grafo *G, char *nome);
void TESTE_ADICIONA_ARESTA(grafo *G, char *nome);
void TESTE_ADJACENTE(grafo *G, char *nome);
void TESTE_REMOVE_ARESTA(grafo *G, char *nome);
void TESTE_VIZINHOS(grafo *G, char *nome);
void TESTE_DESTROI(grafo *G, char *nome);

int main(int argc, char const *argv[])
{
    grafo *G = NULL;
    int x = 1, y = 2;
    char c[] = "teste";
    char g[] = "Guilherme";
    char a[] = "Alex";
    char o[] = "Oswaldy";

    //TESTE_CRIA_E_RETORNA_NOME(G,c); // TESTA AS FUNCOES cria_grafo e retorna_nome_grafo OK
    //TESTE_ADICIONA_VERTICE(G,c); //TESTA A FUNCAO adiciona_vertice OK
    //TESTE_EDITA_VERTICE(G,c); //TESTA A FUNCAO muda_valor_vertice OK
    //TESTE_RETORNA_VALOR_VERTICE(G,c,x,v);//TESTA A FUNCAO retorna_valor_vertice OK
    //TESTE_REMOVE_VERTICE(G,c); // TESTA A FUNCAO remove_vertice  OK
    //TESTE_ADICIONA_ARESTA(G,c); //TESTA A FUNCAO adicionar_aresta OK
    //TESTE_ADJACENTE(G,c);//TESTA A FUNCAO adjacente OK
    //TESTE_REMOVE_ARESTA(G,c); // TESTA A FUNCAO REMOVER ARESTA OK
    //TESTE_VIZINHOS(G,c); TESTA A FUNCAO vizinhos OK
    //TESTE_DESTROI(G,c);//TESTA A FUNCAO destroi_grafo OK

    return 0;
}
/**********************************************************************************************
*Função: Testa Cria e Retorna Nome Grafo
*Descrição
*   Função teste para verifica a corretude das funções retorna_nome_grafo e cria_grafo
*
*Valor retornado
*
*Parâmetros
*   G - ponteiro para o espaço onde o grafo está alocado 
*   nome - ponteiro para o espaço que receberá a string
*
*Assertivas de entrada
*   G != NULL
*
*Assertivas de saída
*   G != NULL
* 
**********************************************************************************************/
void TESTE_CRIA_E_RETORNA_NOME(grafo *G, char *nome)
{
    char *compara;
    G = cria_grafo(nome);
    assert(G);
    if((G != NULL) && (strcmp(G->Nome,nome) == 0)){
        printf("TESTE_CRIA_GRAFO SUCESSO!\n");
        compara = retorna_nome_grafo(G);
        if(strcmp(G->Nome,compara) == 0) printf("TESTE_RETORNA_NOME SUCESSO!\n");
        else printf("TESTE_RETORNA_NOME FALHOU!\n");
    }else{
        printf("TESTE_CRIA_GRAFO FALHOU!\n");
        exit(1);
    }
    assert(G);
}
/**********************************************************************************************
*Função: Testa Adiciona Vertice
*Descrição
*   Função teste para verifica a corretude da função adiciona_vertice
*
*Valor retornado
*
*Parâmetros
*   G - ponteiro para o espaço onde o grafo está alocado 
*   nome - ponteiro para o espaço que receberá a string
*   x - idenficador do vértice a ser adicionado
*   y - idenficador do vértice a ser adicionado
*
*Assertivas de entrada
*   G->v != NULL
*
*Assertivas de saída
*   G->v != NULL
* 
**********************************************************************************************/
void TESTE_ADICIONA_VERTICE(grafo *G, char *nome_grafo){
    char g[] = "Guilherme";
    char a[] = "Alex";
    G = cria_grafo(nome_grafo);
    G = adiciona_vertice(G,g);
    assert(G->v);
    if(strcmp(G->v->nome,g) == 0){
        G = adiciona_vertice(G,a);
        /*G->v foi atualizada novamente
        * G-v agora contém os vértices x e y
        */
        if(strcmp(G->v->prox->nome,a)==0)printf("TESTE_ADICIONA_VERTICE SUCESSO!\n");
    } else printf("TESTE_ADICIONA_VERTICE FALHOU!\n");
    assert(G->v);
}
void TESTE_EDITA_VERTICE(grafo *G, char *nome){
    char g[] = "Guilherme";
    G = cria_grafo(nome);
    G = adiciona_vertice(G,g);
    G = muda_valor_vertice(G,g);
    if(strcmp(G->v->nome,"TESTE") == 0) printf("TESTE_MUDA_VALOR_VERTICE SUCESSO!\n");
    else printf("TESTE_MUDA_VALOR_VERTICE FALHOU!\n");
}
/*
void TESTE_RETORNA_VALOR_VERTICE(grafo *G, char *nome, int x, float v){
    float aux;
    G = cria_grafo(nome);
    G = adiciona_vertice(G,x);
    aux = retorna_valor_vertice(G,x);
    if(aux == -1){
        G = muda_valor_vertice(G,x,v);
        aux = retorna_valor_vertice(G,x);
        if(aux == v) printf("TESTE_RETORNA_VALOR_VERTICE SUCESSO!\n");
        else printf("TESTE_RETORNA_VALOR_VERTICE FALHOU!\n");
    }else printf("TESTE_RETORNA_VALOR_VERTICE FALHOU!\n");
}
*/
/**********************************************************************************************
*Função: Teste Remove Vertice
*Descrição
*   Função teste para verifica a corretude da função remove_vertice
*
*Valor retornado
*
*Parâmetros
*   G - ponteiro para o espaço onde o grafo está alocado 
*   nome - ponteiro para o espaço que receberá a string
*   x - idenficador do vértice alvo
*   y - idenficador do segundo vértice alvo
*
*Assertivas de entrada
*   G->v == NULL
*
*Assertivas de saída
* 
**********************************************************************************************/
void TESTE_REMOVE_VERTICE(grafo *G, char *nome){
    char g[] = "Guilherme";
    char a[] = "Alex";
    G = cria_grafo(nome);
    G = remove_vertice(G,g);
    G = adiciona_vertice(G,g);
    G = remove_vertice(G,g);
    assert(!G->v);
    if(!G->v){
        G = adiciona_vertice(G,g);
        G = adiciona_vertice(G,a);
        G = remove_vertice(G,a);
        if((G->v->prox->nome,a) != 0) printf("TESTE_REMOVE_VERTICE SUCESSO!\n");
    } else printf("TESTE_REMOVE_VERTICE FALHOU!\n");
}
/**********************************************************************************************
*Função: Teste Adiciona Aresta
*Descrição
*   Função teste para verifica a corretude da função adiciona_aresta
*
*Valor retornado
*
*Parâmetros
*   G - ponteiro para o espaço onde o grafo está alocado
*   nome - ponteiro para o espaço que receberá a string
*   x - idenficador do vértice origem
*   y - idenficador do vértice destino
*
*Assertivas de entrada
*   G->v-list != NULL
*
*Assertivas de saída
* 
**********************************************************************************************/
void TESTE_ADICIONA_ARESTA(grafo *G, char *nome){
    char g[] = "Guilherme";
    char a[] = "Alex";
    G = cria_grafo(nome);
    G = adiciona_vertice(G,g);
    assert(G->v->list); 
    G = adiciona_aresta(G,g,a);
    G = adiciona_vertice(G,a);
    G = adiciona_aresta(G,g,a);
    if(strcmp(G->v->list->amigo,a) == 0)printf("TESTE_ADICIONA_ARESTA SUCESSO!\n");
    else printf("TESTE_ADICIONA_ARESTA FALHOU!\n");
}
/**********************************************************************************************
*Função: Teste Vizinhos
*Descrição
*   Função teste para verifica a corretude da função vizinhos
*
*Valor retornado
*
*Parâmetros
*   G - ponteiro para o espaço onde o grafo está alocado
*   nome - ponteiro para o espaço que receberá a string
*   x - idenficador do vértice alvo
*   y - idenficador do segundo vértice alvo
*
*Assertivas de entrada
*   G->v != NULL
*   G->v->list != NULL
*
*Assertivas de saída
* 
**********************************************************************************************/
void TESTE_VIZINHOS(grafo *G, char *nome){
    char g[] = "Guilherme";
    char a[] = "Alex";
    Edge *aux;
    G = cria_grafo(nome);
    G = adiciona_vertice(G,g);
    G = adiciona_vertice(G,a);
    G = adiciona_aresta(G,g,a);
    assert(G->v);
    assert(G->v->list);
    aux = vizinhos(G,g);
    if(strcmp(aux->amigo,a)==0){
        G = adiciona_aresta(G,g,a);
        aux = vizinhos(G,g);
        if(strcmp(aux->prox->amigo,a)==0) printf("TESTE_VIZINHOS SUCESSO!\n");
        else printf("TESTE_VIZINHOS FALHOU!\n");
    }else printf("TESTE_VIZINHOS FALHOU!\n");
}
/**********************************************************************************************
*Função: Teste Adjacente
*Descrição
*   Função teste para verifica a corretude da função adjacente
*
*Valor retornado
*
*Parâmetros
*   G - ponteiro para o espaço onde o grafo está alocado
*   nome - ponteiro para o espaço que receberá a string
*   x - idenficador do vértice origem
*   y - idenficador do vértice destino 
*
*Assertivas de entrada
*   G->v != NULL
*   G->v->list != NULL
*
*Assertivas de saída
* 
**********************************************************************************************/
void TESTE_ADJACENTE(grafo *G, char *nome){
    char g[] = "Guilherme";
    char a[] = "Alex";
    int aux;
    G = cria_grafo(nome);
    G = adiciona_vertice(G,g);
    G = adiciona_vertice(G,a);
    G = adiciona_aresta(G,g,a);
    aux = adjacente(G,a,g);
    if(aux == false){
        aux = adjacente(G,g,a);
        if(aux == true) printf("TESTE_ADJACENTE SUCESSO!\n");
        else printf("TESTE_ADJACENTE FALHOU!\n");   
    }else printf("TESTE_ADJACENTE FALHOU!\n");
}
/**********************************************************************************************
*Função: Teste Remove Aresta
*Descrição
*   Função teste para verifica a corretude da função remove_aresta
*
*Valor retornado
*
*Parâmetros
*   G - ponteiro para o espaço onde o grafo está alocado
*   nome - ponteiro para o espaço que receberá a string
*   x - idenficador do vértice origem
*   y - idenficador do vértice destino 
*
*Assertivas de entrada
*   G != NULL
*   G->v != NULL
*
*Assertivas de saída
* 
**********************************************************************************************/
void TESTE_REMOVE_ARESTA(grafo *G, char *nome){
    char g[] = "Guilherme";
    char a[] = "Alex";
    G = cria_grafo(nome);
    G = adiciona_vertice(G,g);
    G = adiciona_vertice(G,a);
    G = adiciona_aresta(G,g,a);
    G = remove_aresta(G,a,g);
    G = remove_aresta(G,g,a);
    if(!G->v->list->amigo)printf("TESTE_REMOVE_ARESTA SUCESSO!\n");
    else printf("TESTE_REMOVE_ARESTA FALHOU!\n");

}
/**********************************************************************************************
*Função: Testa Destoi
*Descrição
*   Função teste para verifica a corretude da função destroi_grafo
*Valor retornado
*
*Parâmetros
*   G - ponteiro para o espaço onde o grafo está alocado
*   nome - ponteiro para o espaço que receberá a string
*   x - idenficador do primeiro vértice auxiliar
*   y - idenficador do segundo vértice auxiliar 
*
*Assertivas de entrada
*   G == NULL
*
*Assertivas de saída
*   G == NULL
* 
**********************************************************************************************/
void TESTE_DESTROI(grafo *G, char *nome){
    char g[] = "Guilherme";
    char a[] = "Alex";
    assert(!G);
    G   = destroi_grafo(G);
    if(!G){
        G = cria_grafo(nome);
        G = destroi_grafo(G);
        if(!G){
            G = cria_grafo(nome);
            G = adiciona_vertice(G,g);
            G = destroi_grafo(G);
            if(!G){
                G = cria_grafo(nome);
                G = adiciona_vertice(G,g);
                G = adiciona_vertice(G,a);
                G = destroi_grafo(G);
            }
        }
    }
    if(!G) printf("TESTE_DESTROI SUCESSO!\n");
    else printf("TESTE_DESTROI FALHOU!\n");
}