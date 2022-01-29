#include <stdio.h>
#include <stdlib.h>

int menu();
void escolha(int opcao, int *matriz[3][3]);
int validaLocal(int linha, int coluna);
int validaId(int id);

int main(){
    int opcao;
    int matriz[3][3];

    for(int i = 0; i < 3; i++){         // Preenche a matriz com -1
        for(int j = 0; j < 3; j++){
            matriz[i][j] = -1;
        }
    }

    do{
        opcao = menu();
        escolha(opcao, &matriz);
    }while(opcao != 3);

    return 0;
}

int menu(){                                         // Printa o menu e le a opcao escolhida
    int opcao;
    system("clear || cls");                         // Limpar terminal linux ou windows
    printf("========================\n");
    printf("========= Menu =========\n");
    printf("========================\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Ver Turma\n");
    printf("\n");
    printf("3 - Sair\n");
    printf("========================\n");
    scanf("%d", &opcao);
    return opcao;
}

void escolha(int opcao, int *matriz[3][3]){                            // Preenche o vetor e entra no switch
    int c, linha, coluna, id;

    switch(opcao){
        case 1: ;
            int k = 1, k1 = 1;

            while(k){                   // Pergunta e valida o valor da posicao
                printf("========================\n");
                printf("Em qual lugar da matriz deseja inserir o ID? ex: linha coluna \n");
                scanf("%d", &linha);
                scanf("%d", &coluna);
                printf("\n========================");

                if(validaLocal(linha, coluna)){
                    printf("\nLocal nao existente na matriz,\ndigite um numero de 1 a 3 para indicar linha e coluna");
                    printf("\n========================");
                    printf("\nAperte enter para voltar...");
                    c = getchar();
                    getchar();
                    k = 1;
                }else{
                    k = 0;
                }
            }
            while(k1){                  // Pergunta e valida o valor do id
                printf("\nDigite o ID a cadastrar: ");
                scanf("%d", &id);

                if(validaId(id)){
                    printf("\nID incorreto, insira um valor entre 0 e 100");
                    k1 = 1;
                }else{
                    printf("\nID cadastrado!");
                    k1 = 0;
                }

            }

            matriz[linha-1][coluna-1] = id;         // Atribui o valor do id ao local da matriz escolhido
            
            printf("\n========================");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;
        
        case 2:
            printf("========================\n");
            for(int i = 0; i < 3; i++){         // Printa a matriz
                for(int j = 0; j < 3; j++){
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }
            printf("\nObs: posicoes nao cadastradas indicadas por -1");
            printf("\n========================");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 3:
            printf("\nAte logo!");
            printf("\n========================\n");
            printf("Aperte enter para sair...\n");
            c = getchar();
            getchar();
        break;

        default:
            printf("Opcao invalida, tente novamente\n");
            printf("========================\n");
            printf("Aperte enter para voltar...\n");
            c = getchar();
            getchar();
    }

}

int validaLocal(int linha, int coluna){             // Valida localizacao inserida pelo usuario
    if(linha > 0 && linha <= 3 && coluna > 0 && coluna <= 3){
        return 0;
    } else{
        return 1;           // Retorna 1 se tiver algo errado
    }
}

int validaId(int id){                               // Valida id inserido pelo usuario
    if(id > 0 && id < 100){
        return 0;
    } else{
        return 1;           // Retorna 1 se tiver algo errado
    }
}