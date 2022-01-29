#include <stdio.h>
#include <stdlib.h>

void recebeNum(int *vetNum[]);
int menu();
int fat(int num);
int verificaPrimo(int num);
void escolha(int opcao, int x, int y, int z);

int main(){
    int opcao;
    int vetNum[3];      // Vetor para armazenar numeros

    recebeNum(&vetNum);

    do{
    opcao = menu();                                     // Printa menu e recebe a opcao escolhida
    escolha(opcao, vetNum[0], vetNum[1], vetNum[2]);        // Passa para a funcao onde vai ocorre os calculos
    }while(opcao != 7);

    return 0;
}

void recebeNum(int *vetNum[3]){                              // Recebe 3 numeros e verifica
    int verificador = 0;
    do{
        verificador = 0;
        for(int i = 0; i < 3; i++){
            printf("Digite seu %d numero: \n", i+1);        // Recebe o numero
            scanf("%d", &vetNum[i]);

            if(vetNum[i] < 0 || vetNum[i] > 7 || verificaPrimo(vetNum[i]) == 1){    // Verifica, avisa e para o laço
                printf("\nNumero invalido, tente novamente!");
                verificador++;
                break;
            }
        }
    }while(verificador != 0);        // Roda até o input estar correto
}

int menu(){                                                 // Printa o menu e le a opcao escolhida
    int opcao;
    //system("clear || cls");                         // limpar terminal linux ou windows
    printf("====================================================================\n");
    printf("============================ Menu ==================================\n");
    printf("====================================================================\n");
    printf("1 - x! + y! + z!\n");
    printf("2 - (x + y + z)!\n");
    printf("3 - (x+y)! + (x-z)!\n");
    printf("4 - x! - (z+y)!\n");
    printf("5 - Se fossem lados, os 3 numeros formariam um triangulo equilatero?\n");
    printf("6 - Se fossem lados, os 3 numeros formariam um triangulo isosceles?\n");
    printf("\n");
    printf("7 - Sair\n");
    printf("====================================================================\n");
    scanf("%d", &opcao);
    return opcao;
}

int fat(int num){                                           // Calcula o fatorial no numero
    int f;
    if(num > 0){
        for(f = 1; num > 1; num--){
            f *= num;
        }
        return f;
    }else{
        return -1;  //Indica erro
    }
}

int verificaPrimo(int num){                                 // Verifica se o numero é primo
    int result = 0; 
    for (int i = 2; i <= num / 2; i++) {    // Verifica se eh primo
            if (num % i == 0) {
                result++;
                break;
            }
        }
        if(result == 0){            // Se for primo retorna 1
            return 1;
        }else{
            return 0;               // Senao retorna 0
        }
}

void escolha(int opcao, int x, int y, int z){               // Switch onde acontece os calulos e prints
    int c;
    long long int res;
    switch (opcao){
        case 1:
            res = fat(x) + fat(y) + fat(z);
            printf("O resulado eh %d", res);

            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 2:
            res = fat( x + y + z);
            printf("%d", res);

            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 3:
            res = fat(x+y) + fat(x-z);
            printf("%d", res);

            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 4:
            res = fat(x) - fat(z+y);
            printf("%d", res);

            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 5:
            if(x == y && y == z){               // Verifica se os 3 numeros sao iguais
                printf("Sim!");
            }else{
                printf("Nao!");
            }

            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 6:
            if(x == y || y == z || x == z){     // Verifica se 2 numeros sao iguais  
                if(x == y & y == z){            // Verifica se nao eh equilatero
                    printf("Nao!");
                }else{                          // Se nao for, eh isoceles
                    printf("Sim!");
                }
            }

            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 7:
            printf("Ate logo :D");
            printf("\nAperte enter para sair...");
            c = getchar();
            getchar();
        break;

        default:
            printf("Escolha invalida, tente novamente");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();    
    }
}