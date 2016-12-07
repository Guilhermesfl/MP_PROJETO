#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>
#include <assert.h>

/* FUNÇÃO QUE PREENCHE O SIGNIFICADO DOS CAMPOS DO REGISTRO */
lista_cadastrada* preenche_lista_itens(lista_cadastrada *lista)
{
 lista = (lista_cadastrada*)malloc(sizeof(lista_cadastrada));
 lista->campos[0] = "Tenis";
 lista->campos[1] = "Computador";
 lista->campos[2] = "Carro";
 lista->campos[3] = "Bicicleta";
 lista->campos[4] = "Blu-ray";
 lista->campos[5] = "Oculos";
 lista->campos[6] = "Cadeira para churrasco";
 lista->campos[7] = "Churrasqueira";
 lista->campos[8] = "Terno";
 lista->campos[9] = "Calca";
 lista->campos[10] = "Livros";
 lista->campos[11] = "Relogio";
 lista->campos[12] = "Mecanico";
 lista->campos[13] = "Jardinagem";
 lista->campos[14] = "Limpeza de casa";
 lista->campos[15] = "Encanamento";
 lista->campos[16] = "Consertos";
 lista->campos[17] = "Entregas";
 lista->campos[18] = "Carona";
 lista->campos[19] = "Aula";

 return lista;
}

tp_trans* preenche_lista_transacoes(tp_trans *lista)
{
 lista = (tp_trans*)malloc(sizeof(tp_trans));
 lista->campos[0] = "Comprar";
 lista->campos[1] = "Vender";

 return lista;
}
/**********************************************************************************************
*Função: Cria Grafo
*
*Descrição
* Função aloca a estruta do grafo e seta a lista de vértices para NULL
*
*Parâmetros
* nome - ponteiro para o espaço que receberá a string
*
*Valor retornado
* Retorna um ponteiro para grafo
*
*Assertivas de entrada
*
*Assertivas de saída
*
**********************************************************************************************/
grafo* cria_grafo(char* nome)
{
    grafo* G = (grafo*) malloc(sizeof(struct grafo));
    strcpy(G->Nome,nome);
    G->v = NULL;
    return G;
}
/**********************************************************************************************
*Função: Retorna Nome Grafo
*
*Descrição
*   Função retorna o nome identificador do grafo
*
*Parâmetros
* G - ponteiro para o espaço onde o grafo está alocado
*
*Valor retornado
*   Retorna um ponteiro para o espaço que recebeu a string com o nome do grafo
*
*Assertivas de entrada
*
*Assertivas de saída
*    
**********************************************************************************************/
char* retorna_nome_grafo(grafo *G)
{
 return G->Nome;
}
/**********************************************************************************************
*Função: Destroi Grafo
*Descrição
* Função libera o espaço alocado pelo grafo
*
*Valor retornado
* Retorna um ponteiro para NULL
*
*Parâmetros
* G - ponteiro para o espaço onde o grafo está alocado 
*
*Assertivas de entrada
*
*Assertivas de saída
* 
**********************************************************************************************/
grafo* destroi_grafo(grafo *G)
{
 if(G != NULL){
 G = LiberaVertices(G);
 free(G);
 return NULL;
 }
 return NULL;
}
/**********************************************************************************************
*Função: Libera Vertices
*Descrição
* Função libera o espaço alocado pelos vértices do grafo
*
*Valor retornado
* Retorna um ponteiro para NULL
*
*Parâmetros
* G - ponteiro para o espaço onde o grafo está alocado 
*
*Assertivas de entrada
*
*Assertivas de saída
*
**********************************************************************************************/
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
/**********************************************************************************************
*Função: Libera Arestas
*Descrição
* Função libera o espaço alocado pelas arestas do grafo
*
*Valor retornado
* Retorna um ponteiro para NULL indicando que a lista de arestas foi liberada
*
*Parâmetros
* l - ponteiro para o espaço onde a lista de arestas do grafo está alocado 
*
*Assertivas de entrada
*
*Assertivas de saída
*
**************************************************
 ******************************************/
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
/**********************************************************************************************
*Função: Adiciona Vertice
*Descrição
* Função adiciona um vertice à estrutura do grafo,alocando sua lista de arestas e inicializando
*a mesma e o identificador do vertice
*
*Valor retornado
* Retorna um ponteiro para a nova estrutura do grafo
*
*Parâmetros
* G - ponteiro para o espaço onde o grafo está alocado 
* x - idenficador do vértice a ser adicionado
*
*Assertivas de entrada
*
*Assertivas de saída
*
**********************************************************************************************/
grafo* adiciona_vertice(grafo *G, char* nome){

    int opcao,i=0;

    if(G->v == NULL){
        G->v = (struct vertice*)malloc(sizeof(struct vertice));
        for(i=0;i<20;i++) G->v->interesses[i] = (char* )malloc(200*sizeof(char));
        G->v->list = (Edge *)malloc(sizeof(Edge));
        printf("****INSERIR DADOS DA PESSOA****\n");
        G->v->nome = nome;
        printf("Sexo:");
        G->v->genero = (char*) malloc(30*sizeof(char));
        scanf("%s", G->v->genero);
        getchar();
        printf("Idade:");
        scanf("%d", &G->v->idade);
        printf("Nivel Educacional:");
        G->v->niv_educacional = (char*) malloc(30*sizeof(char));
        scanf("%s", G->v->niv_educacional);
        printf("CEP:");
        scanf("%d", &G->v->CEP);

        printf("Deseja digitar algum interesse?\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        scanf("%d", &opcao);
        while(opcao == 1 && i<20){
            printf("Digite seus interesses:");
            scanf("%[^\n]s", G->v->interesses[i]);
            printf("Deseja digitar mais algum:");
            scanf("%d", &opcao);
            i++;
        }
        G->v->num_interesses = i;
        G->v->list->prox = NULL;
        G->v->prox = NULL;

    } else {
        struct vertice *aux = G->v;
        while(aux->prox != NULL)aux = aux->prox;
        aux->prox = (struct vertice*)malloc(sizeof(struct vertice));
        for(i=0;i<20;i++) aux->prox->interesses[i] = (char* )malloc(200*sizeof(char));
        aux->prox->list = (Edge *)malloc(sizeof(Edge));
        printf("****INSERIR DADOS DA PESSOA****\n");
        aux->prox->nome = nome;
        printf("Sexo:");
        aux->prox->genero = (char*) malloc(30*sizeof(char));
        scanf("%s", aux->prox->genero);
        getchar();
        printf("Idade:");
        scanf("%d", &aux->prox->idade);
        printf("Nivel Educacional:");
        aux->prox->niv_educacional = (char*) malloc(30*sizeof(char));
        scanf("%s", aux->prox->niv_educacional);
        printf("CEP:");
        scanf("%d", &aux->prox->CEP);
        printf("Deseja digitar algum interesse?\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        scanf("%d", &opcao);
        while(opcao == 1 && i<20){
            printf("Digite seus interesses:");
            scanf("%[^\n]s", aux->prox->interesses[i]);
            printf("Deseja digitar mais algum:");
            scanf("%d", &opcao);
            i++;
        }
        aux->prox->num_interesses = i;
        aux->prox->list->prox = NULL;
        aux->prox->prox = NULL;
    }
    return G;
}
/**********************************************************************************************
*Função: Muda Valor Vertice
*Descrição
* Função adiciona um vertice à estrutura do grafo,alocando sua lista de arestas e inicializando
*a mesma e o identificador do vertice
*
*Valor retornado
* Retorna um ponteiro para a estrutura do grafo atualizada
*
*Parâmetros
* G - ponteiro para o espaço onde o grafo está alocado 
* x - idenficador do vértice  alvo
* v - valor a der atribuido ao vértice x
*
*Assertivas de entrada
*
*Assertivas de saída
*
**********************************************************************************************/
grafo* muda_valor_vertice(grafo *G,char *nome)
{
    int opcao,i=0,opcao1,opcao2;
    char *aux1;
    struct vertice* aux;
    aux = G->v;
    while(aux->nome != nome && aux->prox != NULL) aux = aux->prox;
    if(aux->nome == nome){
        printf("******EDITAR DADOS*********\n");
        printf("Nome atual: %s\n", aux->nome);
        printf("Novo nome:");
        scanf("%s", aux->nome);
        printf("Sexo atual: %s\n", aux->genero);
        printf("Novo sexo:");
        scanf("%s", aux->genero);
        printf("Idade atual: %d\n", aux->idade);
        printf("Nova idade:");
        scanf("%d", &aux->idade);
        printf("Nivel Educacional atual: %s\n", aux->niv_educacional);
        printf("Novo nivel educacional:");
        scanf("%s", aux->niv_educacional);
        printf("CEP atual: %d\n", aux->CEP);
        printf("Novo CEP:");
        scanf("%d", &aux->CEP);
        printf("Deseja editar seus interesses?\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        scanf("%d", &opcao);
        if(opcao == 1) {
         do{
          printf("O que voce deseja fazer?\n");
          printf("1 - Modificar\n");
          printf("2 - Excluir\n");
          printf("3 - Adicionar\n");
          printf("-1 - Sair\n");
          scanf("%d", &opcao1);
          if(((opcao < 1) || (opcao > 3)) && (opcao != -1)){
           printf("Digite uma opcao valida!\n");
           scanf("%d", &opcao1);
          }
          if(opcao1 == 1 || opcao1 == 2){
           printf("Interesses");
           for(i=0;i<aux->num_interesses;i++) printf("%d - %s", i, aux->interesses[i]);
       printf("Digite o interesse\n");
       scanf("%d", &opcao2);
           if(opcao1 == 1)
           {
            printf("Digite o novo interesse");
            scanf("%s", aux1);
            strcpy(aux->interesses[i], aux1);
           } else {
            for(i=opcao1;i<=aux->num_interesses;i--) strcpy(aux->interesses[i],aux->interesses[i+1]);
            printf("Interesse excluido!");
            aux->num_interesses--;
           }
          } else if(opcao1 == 3){
           if(aux->num_interesses < 20){
            printf("Digite o novo interesse:");
            scanf("%[^\n]s", aux->interesses[aux->num_interesses+1]);
            aux->num_interesses++;
           } else {
            printf("Voce ja digitou o maximo de interesses!");
            printf("Exclua algum ou modifique algum para realizar essa operacao!\n");
           }
          } else opcao1 = -1;
         }while(opcao1 != -1);
     }
        printf("Deseja alterar as amizades?\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        scanf("%d", &opcao);
        if(opcao == 1){
         do{
          printf("O que voce deseja fazer\n");
          printf("1 - Adicionar\n");
          printf("2 - Excluir\n");
          printf("-1 - Sair\n");
          scanf("%d", &opcao1);
          switch(opcao1){
           case 1:
            printf("Digite o nome da pessoa:\n");
            scanf("%s", aux1);
            G = adiciona_aresta(G,aux->nome,aux1);
            break;
           case 2:
            printf("Digite o nome da pessoa:\n");
            scanf("%s", aux1);
            G = remove_aresta(G, aux->nome, aux1);
            G = remove_aresta(G, aux1, aux->nome);
            break;
           default:
            printf("Digite um valor valido!\n");
            break;
           case -1:
            break;
            }
         }while(opcao1 != -1);
        }
    }else{
        printf("A pessoa %s nao existe na rede social\n", nome);
    }
    return G;
}

/**********************************************************************************************
*Função: Remove Vertice
*Descrição
* Função remove um vértice alvo x do grafo caso o mesmo exista
*
*Valor retornado
* Retorna um ponteiro para a estrutura do grafo atualizada
*
*Parâmetros
* G - ponteiro para o espaço ond

e o grafo está alocado 
* x - idenficador do vértice alvo
*
*Assertivas de entrada
*
*Assertivas de saída
*
**********************************************************************************************/
grafo* remove_vertice(grafo *G,char *nome)
{
    struct vertice *aux = G->v;
    struct vertice *aux1 = G->v;
    struct vertice *aux2 = G->v;

    if(G->v){
        while((aux->nome != nome) && (aux->prox != NULL)){
            aux1 = aux;
            aux = aux->prox;
        }
        if(aux->nome == nome){
            //while(aux2->prox != NULL){
            //    remove_aresta(G, aux2->nome, aux1->nome);
            //    aux2 = aux2->prox;
            //}
            //aux->list = LiberaArestas(aux->list);
            if(aux == aux1) G->v = NULL;
            else {
                aux1->prox = aux->prox;
                //aux->list = LiberaArestas(aux->list);
            }    
        }
    } else {
        printf("O GRAFO NAO POSSUI VERTICES!\n");
    }
    return G;
}
/**********************************************************************************************
*Função: Adiciona Aresta
*Descrição
* Função adiciona uma aresta que parte do vértice de identificador x para o vértice de 
*identificador y
*
*Valor retornado
* Retorna um ponteiro para a estrutura do grafo atualizada
*
*Parâmetros
* G - ponteiro para o espaço onde o grafo está alocado 
* x - idenficador do vértice origem
* y - identificador do vértice destino
*
*Assertivas de entrada
*
*Assertivas de saída
*
**********************************************************************************************/
grafo* adiciona_aresta(grafo *G,char *x,char *y)
{
 struct vertice *aux = G->v;
    struct vertice *aux1 = G->v;
    Edge *aux_aresta;
    
    while(aux->nome != x && aux->prox != NULL) aux = aux->prox;
    while(aux1->nome != y && aux1->prox != NULL) aux1 = aux1->prox;
    if(aux->nome == x){
        aux_aresta = aux->list;
        if(aux1->nome == y){
            if(aux_aresta->prox == NULL){
                aux_aresta->amigo = y;
                aux_aresta->prox = (Edge*)malloc(sizeof(Edge));
                aux_aresta->prox->prox = NULL;
            }else {
                while(aux_aresta->prox != NULL) aux_aresta = aux_aresta->prox;
                aux_aresta->amigo = y;
                aux_aresta->prox = (Edge*)malloc(sizeof(Edge));
                aux_aresta->prox->prox = NULL;
            }
        } else printf("%s nao esta cadastrado(a) na rede social!\n", y);
    } else printf("%s nao esta cadastrado(a) na rede social!", x);

    return G;
}
/**********************************************************************************************
*Função: Remove Aresta
*Descrição
* Função remove a aresta que conecta x à y 
*
*Valor retornado
* Retorna um ponteiro para a estrutura do grafo atualizada
*
*Parâmetros
* G - ponteiro para o espaço onde o grafo está alocado 
* x - idenficador do vértice origem
* y - identificador do vértice destino
*
*Assertivas de entrada
*
*Assertivas de saída
*
**********************************************************************************************/
grafo* remove_aresta(grafo *G,char* x,char* y){
    struct vertice *aux;
    Edge *aux_aresta, *aux_aresta1;
    aux = G->v;


    while(aux->nome != x && aux->prox != NULL) aux = aux->prox;
    if(aux->nome == x){
        if(aux->list != NULL){
        aux_aresta = aux->list;
        while((strcmp(aux_aresta->amigo,y) != 0) && (aux_aresta->prox != NULL)){
            aux_aresta1 = aux_aresta;
            aux_aresta = aux_aresta->prox;
        }
        if(strcmp(aux_aresta->amigo,y)==0){
            if(aux_aresta->prox != NULL){
                aux_aresta1 = aux_aresta->prox;
                free(aux_aresta);
            }else free(aux_aresta);
        }else printf("Essa pessoa nao esta na sua lista de amigos!\n");
     }
    }

    return G;
}

/**********************************************************************************************
*Função: Vizinhos
*Descrição
 * Função um ponteiro para a lista de vetores adjacentes ao vértice x
*
*Valor retornado
* Retorna um lista contendo os identificador dos vértices adjacentes ao vértice x
*
*Parâmetros
* G - ponteiro para o espaço onde o grafo está alocado 
* x - idenficador do vértice
*
*Assertivas de entrada
*
*Assertivas de saída
*
**********************************************************************************************/
Edge* vizinhos(grafo* G, char* x)
{
 
    struct vertice *aux = G->v;
    while(aux->nome != x && aux->prox != NULL) aux = aux->prox;
    if(aux->nome == x){
        return aux->list; 
    }else{ 
        printf("O vertice x nao pertence ao grafo!");
    } return NULL;

}
/**********************************************************************************************
*Função: Adjacente
*Descrição
* Função que testa se existe uma aresta que parte de x para y
*
*Valor retornado
* Retorna uma flag indicando a veracidade do teste
*
*Parâmetros
* G - ponteiro para o espaço onde o grafo está alocado 
* x - idenficador do vértice origem
* y - identificador do vértice destino
*
*Assertivas de entrada
*
*Assertivas de saída
* 
**********************************************************************************************/
bool adjacente(grafo *G, char* x, char* y){
 
    struct vertice *aux = G->v; //Variavel auxiliar para percorrer a lista de vetores
    Edge *aux_aresta;
    while((aux->nome != x) && (aux->prox != NULL)) aux = aux->prox;
    if(aux->nome == x){
        aux_aresta = aux->list;
        while(aux_aresta->amigo != y && aux_aresta->prox != NULL) aux_aresta = aux_aresta->prox; 
        if(aux_aresta->amigo == y) return true;
    else return false; 
    }else{
        printf("O vertice x nao pertence ao grafo!");
        return false;
    } 
 
}
/**********************************************************************************************
*Função: Adicionar Transação
*Descrição
* Função adiciona transações ao histórico do usuário
*
*Valor retornado
* Retorna o grafo atualizado
*
*Parâmetros
* G - ponteiro para o espaço onde o grafo está alocado 
* nome - idenficador do vértice origem
* item - identificador do item a ser transacionado
* trans - identificador do tipo de transação
*
*Assertivas de entrada
*
*Assertivas de saída
* 
**********************************************************************************************/

grafo *adicionar_transacao(grafo *G, char *nome, char *item, char *trans, transacoes* geral_trans, int min, int max)
{
 struct vertice *aux = G->v;
 lista *aux1 = geral_trans->solicitacoes;
 lista *aux2;

 
 while((aux->nome != nome) && (aux->prox != NULL)) aux = aux->prox;
 if(aux->nome == nome){
    aux2 = aux->transacao;
    while(aux2->prox != NULL) aux2 = aux2->prox;
  if(strcmp(trans, "Compra")==0){
   while(aux1->prox != NULL && strcmp(aux1->tipo_transacao,"Venda")!=0 && aux1->item != item && aux1->idade >= min && aux1->idade <= max && aux1->situacao != 0) aux1=aux1->prox;
   if(aux1->item == item && strcmp(aux1->tipo_transacao,"Venda")==0 && aux1->idade >= min && aux1->idade <= max && aux1->situacao == 0){
    strcpy(aux2->item,item);
    strcpy(aux2->origem,nome);
    strcpy(aux2->destino,aux1->origem);
    strcpy(aux1->destino,aux->nome);
    strcpy(aux2->tipo_transacao,trans);  
    aux2->situacao = 1;
    aux1->situacao = 1;
   } else {
    while(aux2->prox != NULL) aux2 = aux2->prox;
    strcpy(aux2->item,item);
    strcpy(aux2->origem,nome);
    strcpy(aux2->tipo_transacao,trans);  
    aux2->situacao = 0;
    strcpy(aux1->item,item);
    strcpy(aux1->origem,nome);
    strcpy(aux1->tipo_transacao,trans);  
    aux1->situacao = 0;   
    
   }
  } else {
   while(aux1->prox != NULL && strcmp(aux1->tipo_transacao,"Compra")!=0 && aux1->item != item && aux1->idade >= min && aux1->idade <= max && aux1->situacao != 0) aux1=aux1->prox;
   if(aux1->item == item && strcmp(aux1->tipo_transacao,"Compra")==0 && aux1->idade >= min && aux1->idade <= max && aux1->situacao == 0){
    strcpy(aux2->item,item);
    strcpy(aux2->origem,nome);
    strcpy(aux2->destino,aux1->origem);
 strcpy(aux1->destino,aux->nome);
    strcpy(aux2->tipo_transacao,trans);  
    aux2->situacao = 1;
    aux1->situacao = 1;
   } else {
    while(aux2->prox != NULL) aux2 = aux2->prox;
    strcpy(aux2->item,item);
    strcpy(aux2->origem,nome);
    strcpy(aux2->tipo_transacao,trans);  
    aux2->situacao = 0;
    strcpy(aux1->item,item);
    strcpy(aux1->origem,nome);
    strcpy(aux1->tipo_transacao,trans);  
    aux1->situacao = 0;  
   } 
  } 
 } else printf("%s nao existe na rede social!\n", nome);

 return G;
}

/**********************************************************************************************
*Função: Imprime Lista
*Descrição
* Imprime os itens contidos em uma lista
*
*Valor retornado
* 
*
*Parâmetros
* l - vertice a ser explorado
* 
* 
*Assertivas de entrada
* l != NULL
*Assertivas de saída
* 
**********************************************************************************************/
void Imprime_Lista(struct vertice *l)
{
    struct vertice* l2 = l;
    printf("Nome: %s\n",l->nome);
    printf("Sexo: %s\n",l->genero);
    printf("Idade: %d\n",l->idade);
    printf("Nivel Educacional: %s\n",l->niv_educacional);
    printf("CEP: %d\n",l->CEP);

  if(l){
    printf("Sao amigos de %s", l->nome);
    while(l2->list->prox!=NULL){
        printf("%s, ", l2->list->amigo);
        l2 = l2->prox;
        if(l2->prox == NULL) break;
    }

  }
  else printf("A rede social nao possui amigos!\n");
}
