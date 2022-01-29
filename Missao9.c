#include <stdio.h>
#include <stdlib.h>

int menu();
void escolha(int opcao, int idades[], int count, int total, int maior, int menor);
float media(int total, int count);

int main(){
    int opcao;
    int idades[150];
    int count = 0;
    int total = 0;
    int maior = 0;
    int menor = 150;
    
    printf("\nRegistre as idades, para encerrar digite 150");

    while(1){                                          // Equivalente a while(true), roda infinitamente
        printf("\nDigite a idade do %d aluno: ", (count+1));
        scanf("%d", &idades[count]);

        if(idades[count] < 0 || idades[count] > 150){  // Verifica a idade, se errada volta uma casa no vetor
            printf("\nIdade invalida, digite novamente");
            count--;
        }

        if(idades[count] == 150){                      // Quando digita 150, da um break
            break;
        }

        total += idades[count];                         // Soma todas as notas em um variavel(para media)

        if (idades[count] > maior){                     // Acha a maior idade
            maior = idades[count];
        }
        if (idades[count] < menor && idades[count] != 0){//Acha a menor idade
            menor = idades[count];
        }

        count++;
    }

    do{
    opcao = menu();
    escolha(opcao, idades, count, total, maior, menor);
    } while (opcao != 7);
}

int menu(){                                                 // Printa o menu e le a opcao escolhida
    int opcao;
    system("clear || cls");                         // limpar terminal linux ou windows
    printf("========================\n");
    printf("========= Menu =========\n");
    printf("========================\n");
    printf("1 - Informacoes Gerais\n");
    printf("2 - Listar idades\n");
    printf("3 - Listar maiores/menores que a media\n");
    printf("4 - Editar idade\n");
    printf("5 - Excluir idade\n");
    printf("6 - Pesquisar posicao\n");
    printf("\n");
    printf("7 - Sair\n");
    printf("========================\n");
    scanf("%d", &opcao);
    return opcao;
}

void escolha(int opcao, int idades[], int count, int total, int maior, int menor){
    int c, pos;
    char resposta;

    switch(opcao){
        case 1:
            printf("Foram  inseridas %d idades\n", count);
            printf("A media foi %.2f anos\n", media(total, count));
            printf("A menor idade eh de %d anos\n", menor);
            printf("A maior idade eh de %d anos\n", maior);
            printf("========================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 2:
            for(int i = 0; i < count; i++){
                printf("Idade %d = %d anos\n", i+1, idades[i]); // Printa o vetor
            }
            printf("\n========================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 3:
            printf("Maiores que a media: \n");
            for(int i = 0; i < count; i++){
                if(idades[i] > media(total, count)){
                    printf("%d - ", idades[i]);
                }
            }
            printf("\nMenores que a media: \n");
            for(int i = 0; i < count; i++){
                if(idades[i] < media(total, count)){
                    printf("%d - ", idades[i]);
                }
            }
            printf("\n========================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 4:
            printf("Digite uma posicao para editar: ");
            scanf("%d", &pos);

            if(pos < 0 || pos > count){
                printf("\nPosicao invalida, tente novamente");
                break;
            }
            printf("A posicao pesquisada tem valor %d, deseja editar (s/n)?", idades[pos-1]);
            scanf(" %c", &resposta);

            if(resposta == 's'){
                int novo;
                printf("\nDigite um novo valor para a posicao %d: \n", pos);
                scanf("%d", &novo);
                if(novo > 0 && novo < 150){
                    idades[pos-1] = novo;
                }else{
                    printf("Valor invalido, tente novamente");
                }
            }

            printf("========================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 5:
            printf("Digite uma posicao para excluir: ");
            scanf("%d", &pos);

            if(pos < 0 || pos > count){
                printf("\nPosicao invalida, tente novamente");
                break;
            }           
            printf("\nA posicao pesquisada tem valor %d, deseja excluir (s/n)?\n", idades[pos-1]);
            scanf(" %c", &resposta);

            if(resposta == 's'){
                for(int i = pos-1; i < count-1; i++){
                    idades[i] = idades[i+1];
                }
                idades[count-1] = 0;
                count--;
            }

            printf("========================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 6:
            printf("Digite uma posicao: \n");
            scanf("%d", &pos);
            printf("A posicao pesquisada tem valor %d", idades[pos-1]);
            printf("\n========================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 7:
            printf("Ate logo :D\n");
            printf("========================\n");
            printf("\nAperte enter para sair...");
            c = getchar();
            getchar();
        break;

        default:
            printf("Opcao invalida, tente novamente\n");
            printf("========================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;
    }
}

float media(int total, int count){
    int media = total / count;
    return media;
}