#include <stdio.h>
#include <stdlib.h>

int main(){
    int opcao;
    system("clear || cls");                         // limpar terminal linux ou windows
    printf("==================================\n");
    printf("============== Menu ==============\n");
    printf("==================================\n");
    printf("1 - Informacoes\n");
    printf("2 - Calcular IMC\n");
    printf("3 - Par ou Impar\n");
    printf("4 - Multiplicacao\n");
    printf("5 - Divisao\n");
    printf("\n");
    printf("6 - Sair\n");
    printf("==================================\n");
    scanf("%d", &opcao);

    switch(opcao){
        float peso, altura, imc, n1, n2;
        int c, num;

        case 1:
            printf("Hey, my name is Thalis Cezar Ianzer, I'm on my first semester and my registration number is 202017165");

            c = getchar();              // Essa estrutura serve para o programa parar e esperar o usuario apertar enter
            printf("\nType any ...");   //
            getchar();                  //
        break;

        case 2:
            printf("Enter your weight in kilograms: ");
            scanf("%f", &peso);
            printf("\nEnter your height in meters: ");
            scanf("%f", &altura);

            imc = peso/(altura*altura); // Calculo padrao do imc
            printf("\nYour BMI is %f", imc);
            
            c = getchar();
            printf("\nType any ...");
            getchar();
        break;

        case 3:
            printf("Type a number: ");
            scanf("%d", &num);
            if((num % 2) == 0){                         // Verifica se o resto da divisao é 0 ou nao
                printf("\nThe number %d is even", num); // Se for 0, par
            }else{
                printf("\nThe number %d is odd", num); // Senao, impar
            }

            c = getchar();
            printf("\nType any ...");
            getchar();
        break;

        case 4:
            printf("Type a number: ");
            scanf("%f", &n1);
            printf("Type a number: ");
            scanf("%f", &n2);

            printf("%f times %f is equals to %f", n1, n2, (n1*n2));

            c = getchar();
            printf("\nType any ...");
            getchar();
        break;

        case 5:
            printf("Type a number: ");
            scanf("%f", &n1);
            printf("Type another number: ");
            scanf("%f", &n2);

            if(n1  == 0 || n2 == 0){                            // Verifica se nenhum dos 2 numero inseridos é igual a 0
                printf("Invalid number! Restart the program!");
            }else{
                printf("%f divided by %f is equals to %f", n1, n2, (n1/n2)); // Senao for, printa o resultado
            }

            c = getchar();
            printf("\nType any ...");
            getchar();
        break;

        case 6:
            printf("See you soon, have a nice day!");

            c = getchar();
            printf("\nType any ...");
            getchar();
        break;

        default:                                            // Equivalente a outroCaso no clg
            printf("Invalid choice, restart the program!");

            c = getchar();
            printf("\nType any ...");
            getchar();
    }
    return 0;
}