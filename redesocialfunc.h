typedef struct grafo grafo;
typedef struct Vertice vertice;
typedef struct edge Edge;

struct edge {
    int vdestino;   //vertice destino da aresta
    float valor_aresta;       //peso de cada aresta
    Edge *prox;
};
struct vertice {
    Edge *list; //ponteiro para lista de arestas
    int identificador;
    float valor_vertice;
    struct vertice *prox;
};
struct grafo {
    struct vertice *v; // vetor de vertices
    char Nome[20];
};
typedef enum { 
	true, false 
}bool;

Edge* LiberaArestas(Edge *l);
grafo* LiberaVertices(grafo * G);
grafo* cria_grafo(char* nome);
char* retorna_nome_grafo(grafo *G);
grafo* destroi_grafo(grafo *G);
bool adjacente(grafo *G,int x,int y);
Edge* vizinhos(grafo *G,int x);
grafo* adiciona_vertice(grafo *G,int x);
grafo* remove_vertice(grafo *G,int x);
grafo* adiciona_aresta(grafo *G,int x,int y);
grafo* remove_aresta(grafo *G,int x,int y);
float retorna_valor_vertice(grafo *G,int x);
grafo* muda_valor_vertice(grafo *G,int x,float v);
float retorna_valor_aresta(grafo *G,int x,int y);
grafo* muda_valor_aresta(grafo *G,int x,int y,float v);
void Imprime_Lista(Edge *l, int x);