#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 0, count = 0, neg = 0, even = 0, prime = 0, result = 0, soma = 0;
    int opcao;

    do {
        printf("==================================\n");
        printf("Digite um numero: \n");
        printf("==================================\n");
        scanf("%d", &num);
        
        if(num % 150 == 0){         // Verifica se eh multiplo de 150
            break;                  // Se for, para o do while e vai para o menu
        }

        count++;                    // Contador
        soma = soma + num;          // Soma

        if (num < 0){               // Negativos
           neg++;
        }

        if (num % 2 == 0){          // Pares
           even++;
        }

        for (int i = 2; i <= num / 2; i++) {    // Verifica se eh primo
            if (num % i == 0) {
                result++;
                break;
            }
        }

        if(result == 0){            // Conta os primos
            prime++;
        }

    } while (1);                    // Roda infinitamente ate o primeiro if parar
    
    do{
        system("clear || cls");                         // limpar terminal linux ou windows
        printf("==================================\n");
        printf("============== Menu ==============\n");
        printf("==================================\n");
        printf("1 - Quantidade de numeros inseridos\n");
        printf("2 - Quantidade de numeros negativos\n");
        printf("3 - Quantidade de numeros pares\n");
        printf("4 - Quantidade de numeros primos\n");
        printf("5 - Media dos numeros\n");
        printf("\n");
        printf("6 - Sair\n");
        printf("==================================\n");
        scanf("%d", &opcao);

        switch(opcao){
            int c;
            case 1:
                printf("==================================\n");
                printf("Foram inseridos %d numeros\n", count);
                printf("==================================\n");

                c = getchar();              // Essa estrutura serve para o programa parar e esperar o usuario apertar enter
                printf("\nType any ...");   //
                getchar();                  //
            break;

            case 2:
                printf("==================================\n");
                printf("Foram inseridos %d numeros negativos\n", neg);
                printf("==================================\n");

                c = getchar();              // Essa estrutura serve para o programa parar e esperar o usuario apertar enter
                printf("\nType any ...");   //
                getchar();                  //
            break;

            case 3:
                printf("==================================\n");
                printf("Foram inseridos %d numeros pares\n", even);
                printf("==================================\n");

                c = getchar();              // Essa estrutura serve para o programa parar e esperar o usuario apertar enter
                printf("\nType any ...");   //
                getchar();                  //
            break;

            case 4:
                printf("==================================\n");
                printf("Foram inseridos %d numeros primos\n", prime);
                printf("==================================\n");

                c = getchar();              // Essa estrutura serve para o programa parar e esperar o usuario apertar enter
                printf("\nType any ...");   //
                getchar();                  //
            break;

            case 5:
                printf("==================================\n");
                printf("A media dos numeros inseridos foi %d\n", (soma/count));
                printf("==================================\n");
                
                c = getchar();              // Essa estrutura serve para o programa parar e esperar o usuario apertar enter
                printf("\nType any ...");   //
                getchar();                  //
            break;

            case 6:
                printf("==================================\n");
                printf("Tchau, tchau. Volte sempre!\n");
                printf("==================================\n");

                c = getchar();              // Essa estrutura serve para o programa parar e esperar o usuario apertar enter
                printf("\nType any ...");   //
                getchar();                  //
            break;

            default:
                printf("==================================\n");
                printf("Escolha invalida, digite um numero entre 1 e 6!\n");
                printf("==================================\n");

                c = getchar();              // Essa estrutura serve para o programa parar e esperar o usuario apertar enter
                printf("\nType any ...");   //
                getchar();                  //
        }
    } while (opcao != 6);
}
