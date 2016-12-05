#include <stdioh.>
#include <strdlib.h>

int main(int argc, char const *argv[])
{
	int opcao;
	char *nome,*rede_social = "Facebook 2";
	grafo *G;
	G = cria_grafo(rede_social);


	do{
		printf("Digite a opcao a ser acessada:");
		printf("1 - Interface do USUARIO\n");
		printf("2 - Interface do ADMINISTRADOR\n");
		printf("3 - Leitor e Escritor da rede social\n");
		printf("4 - Sair\n");
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
					printf("5 - Sair\n");
					scanf("%d", &opcao1);
					switch(opcao1){
						case 1:
							//FALTA ADICIONAR INTERESSES, TRASACOES E AVALIACOES
							G = adiciona_vertice(grafo *G);
							break;
						
						case 2: 
							printf("Digite o nome da pessoa a ser editada:");
							scanf("%s", nome);
							G = muda_valor_vertice(G,nome);
							break;
						
						case 3:
							printf("Digite o nome da pessoa a ser excluida:");
							scanf("%s", nome);
							G = remove_vertice(G,nome); 
							break;
						
						case 4: 
							break;
						
						default:
							break;
					}
				}while(opcao1 != 5);
				break;
			
			case 2:
				/****************** INTERFACE ADMINISTRADOR *******************/
				do{
					printf("*********MENU ADMINISTRADOR*********\n");
					printf("1 - Exibir informacoes dos usuarios\n");
					printf("2 - Exibir Trasacoes realizadas\n");
					printf("3 - Editar Trasacoes\n");
					printf("4 - Sair\n");
	
					switch(opcao1){
						case 1:
							//FALTA ADICIONAR INTERESSES, TRASACOES E AVALIACOES
							G = adiciona_vertice(grafo *G);
							break;
					
						case 2: 
							printf("Digite o nome da pessoa a ser editada:");
							scanf("%s", nome);
							G = muda_valor_vertice(G,nome);
							break;
						
						case 3:
							printf("Digite o nome da pessoa a ser excluida:");
							scanf("%s", nome);
							G = remove_vertice(G,nome); 
							break;
						
						default:
						break;
					}
				}while(opcao1 != 4);

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
				}while(opcao1 != 3);

				break;
			default:
				break;
		}
	}while(opcao != 4);

	return 0;
}