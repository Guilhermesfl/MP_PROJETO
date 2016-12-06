#include <stdioh.>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int opcao;
	char *nome,*rede_social = "Facebook 2";
	lista_cadastrada *itens;
	tp_trans *trans;
	grafo *G;
	G = cria_grafo(rede_social);

	//Adm do projeto: Guilherme Lopes
	do{
		printf("Digite a opcao a ser acessada:");
		printf("1 - Interface do USUARIO\n");
		printf("2 - Interface do ADMINISTRADOR\n");
		printf("3 - Leitor e Escritor da rede social\n");
		printf("-1 - Sair\n");
		scanf("%d", &opcao)

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
							G = adiciona_vertice(grafo *G);
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
							printf("Digite o nome de usuario");
							scanf("%s", nome);
							printf("*********ITENS*********\n");
							for(i=0;i<20;i++) printf("%d - %s\n", i,itens->campos[i]);
							scanf("%d", item);
							printf("**********TRANSACOES**********\n");
							for(i=0;i<4;i++) printf("%d - %s\n", i,trans->campos[i]);
							scanf("%d", tipo_transacao);
							assert(G);
							G = adicionar_transacao(G,nome,itens->campos[item],trans->campos[tipo_transacao],lista_geral_trans);
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
	
					switch(opcao1){
						case 1:
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

			case 3:
				/****************** LEITOR E ESCRITOR DA REDE SOCIAL *******************/
				do{
					printf("*********MENU LEITURA E ESCRITA*********\n");
					printf("1 - Salvar dados da rede em um arquivo\n");
					printf("2 - Recuperar rede social\n");
					printf("3 - Sair\n");
	
					switch(opcao1){
						case 1:
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
	}while(opcao != -1);

	return 0;
}