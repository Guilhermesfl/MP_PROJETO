typedef struct grafo grafo;
typedef struct Vertice vertice;
typedef struct edge Edge;
typedef struct Lista lista;

struct Lista{
 lista *prox;
 int situacao;
 int idade;
 char *item;
 char *tipo_transacao; // VENDA,COMPRA,ALUGUEL E OUTROS
 char *origem;
 char *destino;
};

struct edge {
    char* amigo; //vertice destino da aresta
    Edge *prox;
};

typedef struct Transacoes{
 lista *solicitacoes;
}transacoes;

struct vertice {
    Edge *list; //ponteiro para lista de arestas
    char *nome;
    char *genero;
    int idade;
    char *niv_educacional;
    int  CEP;
    char *interesses[20];
    int  num_interesses;
    // falta adicionar avaliações
    lista *transacao;
    struct vertice *prox;
};
struct grafo {
    struct vertice *v; // vetor de vertices
    char Nome[20]; 
};

typedef struct lista_itens{
 char *campos[20];
} lista_cadastrada;

typedef struct lista_trans{
 char *campos[2];
} tp_trans;

typedef enum { 
 true, false 
}bool;

lista_cadastrada* preenche_lista_itens(lista_cadastrada *lista);
tp_trans* preenche_lista_transacoes(tp_trans *lista);
grafo *adicionar_transacao(grafo *G, char *nome, char *item, char *trans, transacoes *geral_trans, int min, int max);
Edge* LiberaArestas(Edge *l);
grafo* LiberaVertices(grafo * G);
grafo* cria_grafo(char* nome);
char* retorna_nome_grafo(grafo *G);
grafo* destroi_grafo(grafo *G);
bool adjacente(grafo *G, char* x,char* y);
Edge* vizinhos(grafo *G,char* x);
grafo* adiciona_vertice(grafo *G,char *nome);
grafo* remove_vertice(grafo *G,char *nome);
grafo* adiciona_aresta(grafo *G,char *nome,char *nome1);
grafo* remove_aresta(grafo *G,char *nome,char *nome1);
float retorna_valor_vertice(grafo *G,char *nome);
grafo* muda_valor_vertice(grafo *G,char *nome);
void Imprime_Lista(Edge *l, char* x);