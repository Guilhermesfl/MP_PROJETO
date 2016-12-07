#include <stdio.h>
#include "func.h"
#include <stdlib.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
 int opcao, opcao1, i, item, tipo_transacao, opcao2;
 int idade1, idade2;
 char *nome,*rede_social = "Facebook 2";
 lista_cadastrada *itens;
 transacoes *lista_geral_trans;
 tp_trans *trans;
 grafo *G;
 struct vertice* aux;
 trans = preenche_lista_transacoes(trans);
 G = cria_grafo(rede_social);
 nome = (char*) malloc(30*sizeof(char));
 itens = preenche_lista_itens(itens);

 //Adm do projeto: Guilherme Lopes
 do{
  printf("Digite a opcao a ser acessada:\n");
  printf("1 - Interface do USUARIO\n");
  printf("2 - Interface do ADMINISTRADOR\n");
  printf("3 - Leitor e Escritor da rede social\n");
  printf("-1 - Sair\n");
  scanf("%d", &opcao);

  switch(opcao){
   case 1:
    /****************** INTERFACE USUÁRIO ******************/
    do{
     printf("*********MENU USUARIO*********\n");
     printf("1 - Criar Pessoa\n");
     printf("2 - Editar Pessoa\n");
     printf("3 - Excluir Pessoa\n");
     printf("4 - Trasacoes\n");
     printf("-1 - Sair\n");
     scanf("%d", &opcao1);
     switch(opcao1){
      case 1:
       assert(G);
       printf("Digite o nome da Pessoa: ");
       scanf("%s", nome);
       G = adiciona_vertice(G,nome);
       break;
      
      case 2: 
       printf("Digite o nome da pessoa a ser editada:");
       scanf("%s", nome);
       assert(G);
       G = muda_valor_vertice(G,nome);
       break;
      
      case 3:
       printf("Digite o nome da pessoa a ser excluida:");
       scanf("%s", nome);
       assert(G);
       G = remove_vertice(G,nome); 
       break;
      case 4:
       printf("Digite o nome de usuario: ");
            scanf("%s", nome);
            printf("*********ITENS*********\n");
            for(i=0;i<20;i++) printf("%d - %s\n", i,itens->campos[i]);
            scanf("%d", &item);
            printf("**********TRANSACOES**********\n");
            for(i=0;i<2;i++) printf("%d - %s\n", i,trans->campos[i]);
            scanf("%d", &tipo_transacao);
            assert(G);
            printf("Dejesa restringir a idade?\n");
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            scanf("%d", &opcao2);
            if(opcao2 == 1){
             printf("Digite a idade limite maxima: ");
             scanf("%d", &idade1);
             printf("Digite a idade limite minima: ");
             scanf("%d", &idade2);
             G = adicionar_transacao(G,nome,itens->campos[item],trans->campos[tipo_transacao],lista_geral_trans,idade2,idade1);
            }
            else G = adicionar_transacao(G,nome,itens->campos[item],trans->campos[tipo_transacao],lista_geral_trans,0,1000);
       
            break;
       
      default:
       break;
     }
    }while(opcao1 != -1);

    break;

   case 2:
    /****************** INTERFACE ADMINISTRADOR *******************/
   
    do{
     printf("*********MENU ADMINISTRADOR*********\n");
     printf("1 - Exibir informacoes dos usuarios\n");
     printf("2 - Exibir Trasacoes realizadas\n");
     printf("3 - Editar Trasacoes\n");
     printf("-1 - Sair\n");
     scanf("%d", &opcao1);
  
     switch(opcao1){
      case 1:
       //FALTA ADICIONAR INTERESSES, TRASACOES E AVALIACOES
       printf("Lista de Usuarios: \n");
       assert(G);
       aux = G->v;
       while(aux!=NULL){ //Enquanto houver algum vertice no grafo
        Imprime_Lista(aux); //imprime as especificações do vértice
        aux = aux->prox;
        printf("\n");
       }

       break;
     
      /*case 2: 
       assert(G);
       aux = G->v;
       trans = aux->transacao;
       while(aux!=NULL){
        printf("Usuario em analise: %s", aux->nome); //Imprime o nome do usuario em questão
        while(trans!=NULL){
         printf("Situacao da transaçao: %d\n",trans->situacao); //Situação da transação
         printf("Item envolvido: %s\n",trans->item); //Item que está envolvido na transação
         printf("Tipo de transacao: %s\n",trans->tipo_transacao); //Tipo de transação: Aluguel, Venda, etc.
         trans = trans->prox;
        }
 aux = aux->prox; 
       }
       break;
      
      case 3:
       printf("1 - Cadastrar Transacao\n");
       printf("2 - Descadastrar Transacao\n");
       scanf("%d",&opcao);
       if(opcao == 1){
        printf("Digite o nome de usuario");
        scanf("%s", nome);
        printf("*********ITENS*********\n");
        for(i=0;i<20;i++) printf("%d - %s\n", i,itens->campos[i]); //Expõe todos os itens que podem ser envolvidos em transações
        scanf("%d", item);
        printf("**********TRANSACOES**********\n");
        for(i=0;i<4;i++) printf("%d - %s\n", i,trans->campos[i]); //Tipos possíveis de transacao
        scanf("%d", tipo_transacao);
        G = adicionar_transacao(G,nome,itens->campos[item],trans->campos[tipo_transacao]); //Adiciona uma transação na lista de transações
       }
       else{
        printf("Digite o nome de usuario");
        scanf("%s", nome);
        aux = G->v;
        while(aux->nome!=nome && aux->prox!=NULL){ //Busca o vertice em que a transação deve ser deletada
         aux = aux->prox;
        }

        aux2 = aux;

        while(aux->transacao!=NULL){ //Mostra a lista de transações do usuário
         printf("Item da transacao: %s\n",aux->transacao->item);
         printf("Status da transacao: %s\n",aux->transacao->tipo_transacao);
         printf("Situacao da transacao: %s\n",aux->transacao->situacao);
         aux = aux->prox;
        }
        printf("Digite o item da transacao que deseja remover?\n"); //Opção que requer o nome do item que deve ser deletada
        scanf("%s", item);
        aux2 = retira(aux2,item);
        printf("Transacao removida com sucesso.\n");
       }
       break;
      */
      default:
      break;
     }
    }while(opcao1 != -1);

    break;
   }
   }while(opcao!= -1);
   return 0;
  }
    /*
   case 3:
    /****************** LEITOR E ESCRITOR DA REDE SOCIAL *******************/
   /*
    do{
     printf("*********MENU LEITURA E ESCRITA*********\n");
     printf("1 - Salvar dados da rede em um arquivo\n");
     printf("2 - Recuperar rede social\n");
     printf("3 - Sair\n");
 
     switch(opcao1){
      case 1:
       fp = fopen("Rede_social.txt", "r+");
       aux = G->v;
       trans = aux->transacao;
       while(aux!=NULL){ //Adiciona as características dos vértices (Separados por ponto e vírgula)
        fprintf(fp,"%s",aux->nome);
        fputs(";",fp);
        fprintf(fp,"%s",aux->genero);
        fputs(";",fp);
        fprintf(fp,"%s",aux->idade);
        fputs(";",fp);
        fprintf(fp,"%s",aux->niv_educacional);
        fputs(";",fp);
        fprintf(fp,"%d",aux->CEP);
        fputs(";",fp);
        fprintf(fp,"%s",aux->interesses);
        fputs(";",fp);
        while(trans!=NULL){ //Adiciona as transações dos vértices
         fprintf(fp,"%d",trans->situacao);
         fputs(";",fp);
         printf(fp,"%s",trans->item);
         fputs(";",fp);
         printf(fp,"%s",trans->tipo_transacao);
         fputs(";",fp);
         trans = trans->prox;
        }
        fputs("\n",fp); //Pula a linha no arquivo para diferenciar os vertices
        aux = aux->prox; 
       }
       fclose(fp);
       break;
     
      case 2: 
       break;
      
      case 3:

       break;
      
      default:
      break;
     }
    }while(opcao1 != -1);

    break;
   default:
    break;
  }

 }
 while(opcao != -1);

 return 0;
}
*/