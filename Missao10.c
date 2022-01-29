#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void emails(char email[], int c, int *k);
void nome(char username[], int c, int *k);
void senha(char password[], int c, int *k);
void frase(char sinistra[], int c, int *k);


int main(){  
    int c;
    char email[50];
    char username[10];
    char password[40];
    char sinistra[70];
    int k = 1, k1 = 1, k2 = 1, k3 = 1;// Livinho me ensinou a usar controladores para parar loop while no lugar de break

    while(k){                   // Email
        system("clear || cls");
        printf("\n============ Login ==============");
        printf("\nEmail: ");
        scanf("%[^\n]%*c", email);

        emails(email, c, &k);
    }

    while(k1){                  // Username
        printf("\nUsername: ");
        scanf("%[^\n]%*c", username);

        nome(username, c, &k1);
    }

    while(k2){                  // Senha
        printf("\nPassword: ");
        scanf("%[^\n]%*c", password);

        senha(password, c, &k2);
    }

    while(k3){                  // Frase
        printf("\nDados corretos!");
        printf("\nDigite a frase sinistra para confirmar login: ");
        scanf(" %[^\n]%*c", sinistra);

        frase(sinistra, c, &k3);
    }
    
    return 0;
}

void emails(char email[], int c, int *k){

    int cont = 0, contArroba = 0, contPonto = 0;

    for(int i = 0; i < strlen(email); i++){
        if(islower(email[i])){
            cont++;
        }
        if(email[i] == ' '){    // se tiver espaço, n aceita
            cont--;
        }
        if(email[i] == '@'){
            contArroba++;
        }
        if(email[i] == '.'){
            contPonto++;
        }
    }

    if(contArroba == 1 && (contArroba+contPonto+cont) == strlen(email)){
        *k = 0;              //controlador do while
    } else{
        printf("\nEmail invalido!");
        printf("\nAperte enter para voltar...");
        *k = 1;              //controlador do while
        c = getchar();
        getchar();
    }
}
void nome(char username[], int c, int *k){
    int cont = 0;

    for(int i = 0; i < strlen(username); i++){
        if((isdigit(username[i])) == 0){
            if((islower(username[i])) != 0){    // Se for minusculo e NAO for numero
                cont++;
            }
        }
    }

    if(cont == strlen(username) && (strlen(username) < 10 || strlen(username) > 5)){
        *k = 0;
    } else {
        printf("\nUsername invalido!");
        printf("\nAperte enter para voltar...");
        *k = 1;              //controlador do while
        c = getchar();
        getchar();
    }
}
void senha(char password[], int c, int *k){

    if(strlen(password) > 8 || strlen(password) < 40){
        *k = 0;
    } else {
        printf("\nSenha invalida!");
        printf("\nAperte enter para voltar...");
        *k = 1;              //controlador do while
        c = getchar();
        getchar();
    }
    printf("=================================");
}
void frase(char sinistra[], int c, int *k){

    int contEsp = 0;            // Procura espaços na frase para contar as palavras
    for(int i = 0; i < strlen(sinistra); i++){
        if(sinistra[i] == ' '){
            contEsp++;
        }
    }

    int tam = strlen(sinistra);

    //debugging...
    //printf("tam = %d, numPalavras = %d, isupper = %d, ultima = %c", tam, (contEsp+1), (isupper(sinistra[0])), sinistra[tam-1]);

    // todas as condições para ser aceita
   if ((tam >= 70) && ((contEsp+1) >= 5) && (isupper(sinistra[0])) && (sinistra[tam-1] == '.')){
       printf("\nParabens cara, voce conseguiu");
       *k = 0;
    } else{
        printf("\nFrase invalida, tente novamente");
        *k = 1;              //controlador do while
        c = getchar();
        getchar();
   }
}