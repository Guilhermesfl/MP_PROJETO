#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include <string.h>

grafo* cria_grafo(char* nome)
{
    grafo* G = (grafo*) malloc(sizeof(struct grafo));
    strcpy(G->Nome,nome);
    G->v = NULL;
    return G;
}

char* retorna_nome_grafo(grafo *G)
{
	return G->Nome;
}

grafo* destroi_grafo(grafo *G)
{
	if(G != NULL){
	G = LiberaVertices(G);
	free(G);
	return NULL;
	}

}
grafo* LiberaVertices(grafo *G)
{
    struct vertice *aux, *aux1;
    aux = G->v;
    aux1 = aux;
    while(aux != NULL){
    	if(aux->list)aux->list = LiberaArestas(aux->list);
    	aux = aux->prox;
    	free(aux1);
    	aux1 = aux;
    }
    return G;
}
Edge* LiberaArestas(Edge* l)
{
    Edge *aux;
    aux=l;
    while(l != NULL)
    {
        l = l->prox;
        free(aux);      
        aux = l;
    }
    return NULL;
}
grafo* adiciona_vertice(grafo *G,int x){

	if(G->v == NULL){
    	G->v = (struct vertice*)malloc(sizeof(struct vertice));
    	G->v->list = (Edge *)malloc(sizeof(Edge));
    	G->v->identificador = x;
    	G->v->valor_vertice = -1;
    	G->v->list->prox = NULL;
    	G->v->prox = NULL;
    } else {
    	struct vertice *aux = G->v;
    	while(aux->prox != NULL)aux = aux->prox;
    	aux->prox = (struct vertice*)malloc(sizeof(struct vertice));
    	aux->prox->list = (Edge *)malloc(sizeof(Edge));
    	aux->prox->identificador = x;
    	aux->prox->valor_vertice = -1;
    	aux->prox->list->prox = NULL;
    	aux->prox->prox = NULL;
    }
    return G;

}
grafo* muda_valor_vertice(grafo *G,int x,float v)
{
	struct vertice* aux;
    aux = G->v;
	while(aux->identificador != x && aux->prox != NULL) aux = aux->prox;
    if(aux->identificador == x){
        aux->valor_vertice = v;
    }else{
        printf("O vertice %d nao pertence ao grafo!", x);
    }
    return G;
}

float retorna_valor_vertice(grafo *G,int x){
    
    float valor=-1;
    struct vertice* aux;
    aux = G->v;

	while(aux->identificador != x && aux->prox != NULL) aux = aux->prox;
    if(aux->identificador == x){
        valor = aux->valor_vertice;
        return valor;
    } else return -1;
}
grafo* remove_vertice(grafo *G,int x){
    struct vertice *aux = G->v;
    struct vertice *aux1 = G->v;

    if(G->v){
    	while((aux->identificador != x) && (aux->prox != NULL)){
    		aux1 = aux;
    		aux = aux->prox;
    	}
		if(aux->identificador == x){
			aux->list = LiberaArestas(aux->list);
			if(aux->prox == NULL) aux->identificador = -1;
			else {
			aux1->prox = aux->prox;
			aux->list = LiberaArestas(aux->list);
			} 
		}
	}
    return G;
}
grafo* adiciona_aresta(grafo *G,int x,int y)
{
	struct vertice *aux = G->v;
    struct vertice *aux1 = G->v;
    Edge *aux_aresta;
    
    while(aux->identificador != x && aux->prox != NULL) aux = aux->prox;
    while(aux1->identificador != y && aux1->prox != NULL) aux1 = aux1->prox;
    if((aux->identificador == x) && (aux1->identificador == y)){
    	aux_aresta = aux->list;
    	if(aux_aresta->prox == NULL){
    		aux_aresta->vdestino = y;
        	aux_aresta->valor_aresta = -1;
        	aux_aresta->prox = (Edge*)malloc(sizeof(Edge));
        	aux_aresta->prox->prox = NULL;
    	}else {
 			while(aux_aresta->prox != NULL) aux_aresta = aux_aresta->prox;
        	aux_aresta->vdestino = y;
        	aux_aresta->valor_aresta = -1;
        	aux_aresta->prox = (Edge*)malloc(sizeof(Edge));
        	aux_aresta->prox->prox = NULL;
        }
    }
    /*else{
    	if(aux->identificador != x) printf("O vertice %d nao pertence ao grafo!", x);
    	else printf("O vertice %d nao pertence ao grafo!", y);
    }*/
    return G;
}
grafo* muda_valor_aresta(grafo *G,int x,int y,float v)
{
    
    Edge* aux_aresta;
    struct vertice* aux;
    aux = G->v;

    while(aux->identificador != x && aux->prox != NULL) aux = aux->prox;
    if(aux->identificador == x){
        aux_aresta = aux->list;
        while(aux_aresta->vdestino != y) aux_aresta = aux_aresta->prox;
        if(aux_aresta->vdestino == y){
        	aux_aresta->valor_aresta = v;
        }else printf("Nao existe aresta de %d para %d", x,y);
    }else{
        printf("O vertice %d nao pertence ao grafo!", x);
    }
    return G;   
}

grafo* remove_aresta(grafo *G,int x,int y){
    struct vertice *aux;
    Edge *aux_aresta, *aux_aresta1;
    aux = G->v;


    while(aux->identificador != x && aux->prox != NULL) aux = aux->prox;
    if(aux->identificador == x){
    	if(aux->list != NULL){
        	aux_aresta = aux->list;
        	while((aux_aresta->vdestino != y) && (aux_aresta->prox != NULL)){
        	    aux_aresta1 = aux_aresta;
        	    aux_aresta = aux_aresta->prox;
        	}
        	if(aux_aresta->vdestino == y){
        	    if(aux_aresta->prox != NULL){
        	        aux_aresta1 = aux_aresta->prox;
        	        free(aux_aresta);
        	    }else free(aux_aresta);
        	}
    	}
    }

    return G;
}

float retorna_valor_aresta(grafo *G,int x,int y)
{
    float valor=-1;
    Edge* aux_aresta;
    struct vertice* aux;
    aux = G->v;

    while(aux->identificador != x && aux->prox != NULL) aux = aux->prox;
    if(aux->identificador == x){
        aux_aresta = aux->list;
        while(aux_aresta->vdestino != y) aux_aresta = aux_aresta->prox;
        if(aux_aresta->vdestino == y) valor = aux_aresta->valor_aresta;
        else printf("Nao existe aresta de %d para %d", x,y);
    }else{
        printf("O vertice %d nao pertence ao grafo!", x);
    }
    return valor;
}
Edge* vizinhos(grafo* G, int x)
{
	
	struct vertice *aux = G->v;
	while(aux->identificador != x && aux->prox != NULL) aux = aux->prox;
	if(aux->identificador == x){
		return aux->list;	
	}else{	
		printf("O vertice x nao pertence ao grafo!");
	} return NULL;

}

void Imprime_Lista(Edge *l, int x)
{
	if(l){
		printf("Vizinhos de %d\n", x);
		while(l != NULL){
			printf("%d ", l->vdestino);
			l = l->prox;
		}
	}else printf("O vertice %d nao possui vizinhos!\n", x);
}

bool adjacente(grafo *G, int x, int y){
	
	struct vertice *aux = G->v; //Variavel auxiliar para percorrer a lista de vetores
	Edge *aux_aresta;
	while((aux->identificador != x) && (aux->prox != NULL)) aux = aux->prox;
	if(aux->identificador == x){
		aux_aresta = aux->list;
		while(aux_aresta->vdestino != y && aux_aresta->prox != NULL) aux_aresta = aux_aresta->prox;	
		if(aux_aresta->vdestino == y) return true;
		else return false;		
	}else{
		printf("O vertice x nao pertence ao grafo!");
		return false;
	} 
	
}