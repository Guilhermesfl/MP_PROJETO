typedef struct grafo grafo;
typedef struct Vertice vertice;
typedef struct edge Edge;

struct edge {
    char* amigo; //vertice destino da aresta
    float valor_aresta; //Vai indicar se duas pessoas são amigas ou não
    Edge *prox;
};
struct vertice {
    Edge *list; //ponteiro para lista de arestas
    char *nome;
    char *genero;
    char *idade;
    char *niv_educacional;
    int  *CEP;
    char *interesses[200];
    // falta adicionar transações e avaliações
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
grafo* adiciona_vertice(grafo *G,char *nome);
grafo* remove_vertice(grafo *G,char *nome);
grafo* adiciona_aresta(grafo *G,char *nome,char *nome1);
grafo* remove_aresta(grafo *G,char *nome,char *nome1);
float retorna_valor_vertice(grafo *G,char *nome);
grafo* muda_valor_vertice(grafo *G,char *nome);
float retorna_valor_aresta(grafo *G,char *nome,char *nome);
void Imprime_Lista(Edge *l, int x);