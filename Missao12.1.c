#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/////////// Structs
typedef struct jogador{     // Define o tipo Jogador, possuindo id, nome, posição e idade.
    int id;
    char nome[50];
    char posicao[4];
    int idade;
}Jogador;

typedef struct time{    // Define o tipo Time, possuindo 5 Jogadores, nome, e nome do técnico
    Jogador jogadores[5];
    char nome[50];
    char nome_tecnico[50];
}Time;

typedef struct jogadores_partida{   //Define informações dos jogadores na partida
    int id_jogador;
    int num_assistencias;
    int num_kills;
    int num_deaths;
}JogadorPartida;

typedef struct partida{     //Define dados sobre a partida
    int total_kills_time;
    int total_kills_adversario;
    bool vitoria;
    int total_torres_destruidas_time;
    int total_torres_destruidas_adversario;
    JogadorPartida jogadores_partida[5];
}Partida;
/////////// Structs

/////////// Funcoes
int menu();
void escolha(int opcao, int *quant_partidas);
void cadastrarTime();                            //1
void listarTime();                               //2
void editarTime(int quant_partidas);             //3
void cadastrarPartida(int quant_partidas);       //4
void listarPartidas(int quant_partidas);         //5 
void pesquisarJogador();                         //6
void killsAssistencias(int quant_partidas);      //7 
void mostrarMenor(int quant_partidas);           //8 
void mostrarMaior(int quant_partidas);           //9 
int pontuacaoJogador(int idjog, int partida);
int maiorPontuacao(int quant_partidas);
int menorPontuacao(int quant_partidas);
int pontuacaoJogadorTotal(int idjog, int quant_partidas);
int idmaiorPontuacao(int quant_partidas);
int idmenorPontuacao(int quant_partidas);
int validaIdade(int idade);
int validaPosicao(char posicao[]);
int validaKDA(int num);
int validaBool(char ans);
int validaTorres(int numTorres);
int validaId(int id);
/////////// Funcoes

Time time;
Partida partidas[100];


int main(){
    int opcao;
    int quant_partidas = 0;

    do{
        opcao = menu();
        escolha(opcao, &quant_partidas);
    }while(opcao != 10);            //Roda ate pedir para sair (opcao 10)

    return 0;
}

int menu(){
    int opcao;
    system("clear || cls");                         // Limpar terminal linux ou windows
    printf("=======================================================\n");
    printf("======================== Menu =========================\n");
    printf("=======================================================\n");
    printf("1 - Cadastrar time\n");
    printf("2 - Listar time\n");
    printf("3 - Editar time\n");
    printf("4 - Cadastrar partida\n");
    printf("5 - Listar partidas\n");
    printf("6 - Pesquisar jogador\n");
    printf("7 - Mostrar numero total de kills e assistencias\n");
    printf("8 - Mostrar jogador com menor pontuacao\n");
    printf("9 - Mostrar jogador com maior pontuacao\n");
    printf("\n");
    printf("10 - Sair\n");
    printf("=======================================================\n");
    scanf("%d", &opcao);
    return opcao;
}

void escolha(int opcao, int *quant_partidas){
    int c;

    switch(opcao){
        case 1: //Cadastrar time
            cadastrarTime();

            printf("\n=======================================================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 2: //Listar time
            listarTime();
            
            printf("\n=======================================================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 3: //Editar time
            editarTime(*quant_partidas);
            
            printf("\n=======================================================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 4: //Cadastrar partida
            cadastrarPartida(*quant_partidas);
            (*quant_partidas)++;
            
            printf("\n=======================================================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 5: //Listar partidas
            listarPartidas(*quant_partidas);

            printf("\n=======================================================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 6: //Pesquisar jogador
            pesquisarJogador();
            
            printf("\n=======================================================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 7: //Mostrar num total de kills e assistencias
            killsAssistencias(*quant_partidas);
            
            printf("\n=======================================================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 8: //Mostrar jogador com menor pontuacao
            mostrarMenor(*quant_partidas);
            
            printf("\n=======================================================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 9: //Mostrar jogador com maior pontuacao
            mostrarMaior(*quant_partidas);
            
            printf("\n=======================================================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;

        case 10:
            printf("\nAte logo :D\n");
            printf("=======================================================\n");
            printf("\nAperte enter para sair...");
            c = getchar();
            getchar();
        break;

        default:
            printf("Opcao invalida, tente novamente\n");
            printf("=======================================================\n");
            printf("\nAperte enter para voltar...");
            c = getchar();
            getchar();
        break;
    }

}

void cadastrarTime(){       //Item 1

    printf("\n\t Cadastrar Time:\n");
    printf("\nDigite o nome do time : ");   //Cadastra nome do time
    scanf(" %s", time.nome);

    printf("Digite o nome do tecnico: ");   //Cadastra nome do tecnico
    scanf(" %s", time.nome_tecnico);
    

    for(int i = 0; i < 5; i++){             //Cadastra os 5 jogadores (nome, idade e posicao)
        time.jogadores[i].id = i+1;
        
        printf("Digite o nome do jogador %d: ", i+1);
        scanf(" %[^\n]s", time.jogadores[i].nome);

        do{
            printf("Digite a idade de %s: ", time.jogadores[i].nome);
            scanf(" %d", &time.jogadores[i].idade);
            validaIdade(time.jogadores[i].idade);
        }while(validaIdade(time.jogadores[i].idade));   //Valida idade (0 >= idade <= 150)

        do{
            printf("Digite a posicao de %s(ADC, SUP, MID, TOP e JG): ", time.jogadores[i].nome);
            scanf(" %[^\n]s", time.jogadores[i].posicao);
            validaPosicao(time.jogadores[i].posicao);
        }while(validaPosicao(time.jogadores[i].posicao));   //Valida posicao
    }
}

void listarTime(){       //Item 2
    //Lista nome do time, nome do tecnico e os 5 jogadores com suas posicoes

    printf("\n\t  Time: %s", time.nome);
    printf("\n\t Coach: %s", time.nome_tecnico);
    printf("\n Jogadores: ");

    for(int i = 0; i < 5; i++){
        printf("\n\t %d - %s - %s", i+1, time.jogadores[i].nome, time.jogadores[i].posicao);
    }
}

void editarTime(int quant_partidas){       //Item 3
    int editarID;
    char answer;
    printf("\n\t Editar Time:\n");

    do{
        printf("\nDigite o id do jogador que deseja editar: "); //Recebe id que vai ser editado
        scanf("%i", &editarID);
    }while(validaId(editarID)); //Valida id (1 <= id >= 5)

    printf("\n\t %i - %s - %s - %i\n", time.jogadores[editarID-1].id, time.jogadores[editarID-1].nome, time.jogadores[editarID-1].posicao, pontuacaoJogadorTotal(editarID, quant_partidas));
    printf("\nDeseja mesmo editar esse jogador(s/n)? ");    //Confere com o usuario se escolheu o jogador desejado
    scanf(" %c", &answer);

    if(answer == 's'){                                      //Se sim, cadastra outro jogador no lugar dele
        printf("Digite um novo nome de jogador: ");
        scanf("%s", time.jogadores[editarID-1].nome);

        int novaIdade;
        do{
            printf("Digite uma nova idade: ");          //Recebe e valida uma nova idade
            scanf(" %i", &novaIdade);
            validaIdade(novaIdade);
            time.jogadores[editarID-1].idade = novaIdade;
        }while(validaIdade(novaIdade));
        
        char novaPos[3];
        do{
            printf("Digite uma nova posicao: ");        //Recebe e valida uma nova posicao
            scanf(" %s", novaPos);
            validaPosicao(novaPos);
            strcpy(time.jogadores[editarID-1].posicao, novaPos);//Copia o valor da nova posicao na struct
        }while(validaPosicao(novaPos));
    }
}

void cadastrarPartida(int quant_partidas){        //Item 4
    printf("\n\t Cadastrar partida:\n");

    for(int i = 0; i < 5; i++){ //Registra e valida o KDA dos 5 jogadores
        do{
            printf("\n Digite os abates de %i-%s: ", i+1, time.jogadores[i].nome);
            scanf(" %i", &partidas[quant_partidas].jogadores_partida[i].num_kills);
        }while(validaKDA(partidas[quant_partidas].jogadores_partida[i].num_kills));

        do{
            printf(" Digite as assistencias de %i-%s: ", i+1, time.jogadores[i].nome);
            scanf(" %i", &partidas[quant_partidas].jogadores_partida[i].num_assistencias);
        }while(validaKDA(partidas[quant_partidas].jogadores_partida[i].num_assistencias));

        do{
            printf(" Digite as mortes de %i-%s: ", i+1, time.jogadores[i].nome);
            scanf(" %i", &partidas[quant_partidas].jogadores_partida[i].num_deaths);
        }while(validaKDA(partidas[quant_partidas].jogadores_partida[i].num_deaths));
    }

    do{     //Registra e valida as kills do time
        printf("\n Quantos abates seu time fez ao todo?: ");
        scanf(" %i", &partidas[quant_partidas].total_kills_time);
    }while(validaKDA(partidas[quant_partidas].total_kills_time));

    do{     //Registra e valida as kills do time adversario
        printf(" Quantos abates seu adversario fez ao todo?: ");
        scanf(" %i", &partidas[quant_partidas].total_kills_adversario);
    }while(validaKDA(partidas[quant_partidas].total_kills_adversario));

    char vitoria;
    do{     //Registra e valida se foi vitoria ou nao
        printf("\n Seu time ganhou (s/n)?: ");
        scanf(" %c", &vitoria);

        if(vitoria == 's'){     //Altera na struct
            partidas[quant_partidas].vitoria = true;
        }else{
            partidas[quant_partidas].vitoria = false;
        }
    }while(validaBool(vitoria));

    do{     //Registra e valida as torres destruidas do time
        printf("\n Digite o numero de torres destruidas pelo seu time: ");
        scanf(" %i", &partidas[quant_partidas].total_torres_destruidas_time);
    }while(validaTorres(partidas[quant_partidas].total_torres_destruidas_time));

    do{     //Registra e valida as torres destruidas do time adversario
        printf(" Digite o numero de torres destruidas pelo time adversario: ");
        scanf(" %i", &partidas[quant_partidas].total_torres_destruidas_adversario);
    }while(validaTorres(partidas[quant_partidas].total_torres_destruidas_adversario));
    
}

void listarPartidas(int quant_partidas){      //Item 5
    printf("\n\t Partidas: \n");
    printf("\n Resultado - Abates - Mortes - Torres destruidas - Torres destruidas pelo adversario \n");
    
    for(int i = 0; i < quant_partidas; i++){    //Lista todas as partidas cadastradas
        if(partidas[i].vitoria){    //Verifica se foi vitoria ou derrota
            printf("\n Vitoria - %i - %i - %i - %i", partidas[i].total_kills_time, partidas[i].total_kills_adversario, partidas[i].total_torres_destruidas_time, partidas[i].total_torres_destruidas_adversario);
        }else{
            printf("\n Derrota - %i - %i - %i - %i", partidas[i].total_kills_time, partidas[i].total_kills_adversario, partidas[i].total_torres_destruidas_time, partidas[i].total_torres_destruidas_adversario);
        }

        int id = idmaiorPontuacao(i+1);
        printf("\n Destaque: %i - %s", time.jogadores[id-1].id, time.jogadores[id-1].nome); //Printa o MVP da partida
    }
}

void pesquisarJogador(){        //Item 6
    int id;

    printf("\n\t Pesquisar Jogador: \n");
    printf("\nDigite o id do jogador a pesquisar: ");
    scanf("%i", &id);
    
    if(validaId(id) == 0){      //Se o id for valido, mostra as informacoes do jogador
        printf("\n Id - Nome - Pos - Idade");
        printf("\n %i - %s - %s - %i", id, time.jogadores[id-1].nome, time.jogadores[id-1].posicao, time.jogadores[id-1].idade);
    }
}

void killsAssistencias(int quant_partidas){       //Item 7
    int totalKills = 0;
    int totalAssists = 0;

    for(int i = 0; i < quant_partidas; i++){    //Soma as kills e assists de todos os jogadores
        for(int j = 0; j < 5; j++){             //de todas as partidas cadastradas
            totalKills += partidas[i].jogadores_partida[j].num_kills;
            totalAssists += partidas[i].jogadores_partida[j].num_assistencias;
        }
    }
    printf("\n\t Total de kills foi de %i abates", totalKills);
    printf("\n\t Total de assists foi de %i assistencia", totalAssists);
}

void mostrarMenor(int quant_partidas){      //Item 8
    printf("\n\t Jogador com menor pontuacao: \n"); //Mostra jogador com a menor pontuacao em todas as partidas cadastradas
    printf("\n Id - Nome - Pos - Idade - Pontos\n");
    printf("\n %i - %s - %s - %i - %i", idmenorPontuacao(quant_partidas), time.jogadores[idmenorPontuacao(quant_partidas)-1].nome, time.jogadores[idmenorPontuacao(quant_partidas)-1].posicao, time.jogadores[idmenorPontuacao(quant_partidas)-1].idade, menorPontuacao(quant_partidas));
}

void mostrarMaior(int quant_partidas){      //Item 9
    printf("\n\t Jogador com maior pontuacao: \n"); //Mostra jogador com a maior pontuacao em todas as partidas cadastradas
    printf("\n Id - Nome - Pos - Idade - Pontos\n");
    printf("\n %i - %s - %s - %i - %i", idmaiorPontuacao(quant_partidas), time.jogadores[idmaiorPontuacao(quant_partidas)-1].nome, time.jogadores[idmaiorPontuacao(quant_partidas)-1].posicao, time.jogadores[idmaiorPontuacao(quant_partidas)-1].idade, maiorPontuacao(quant_partidas));
}

/////////// Auxiliares
int pontuacaoJogador(int idjog, int partida){       //Calcula a pontuacao de um jogador em uma partida
    int pontuacao = 0;
    pontuacao = pontuacao + (partidas[partida-1].jogadores_partida[idjog-1].num_assistencias) + (partidas[partida-1].jogadores_partida[idjog-1].num_kills * 3);
    
    return pontuacao;
}

int maiorPontuacao(int quant_partidas){     //Calcula a maior pontucao de todas as partidas
    int maior;
    maior = pontuacaoJogadorTotal(1, quant_partidas);

    for(int i = 2; i <= 5; i++){
        if((pontuacaoJogadorTotal(i, quant_partidas)) > maior){
            maior = pontuacaoJogadorTotal(i, quant_partidas);
        }
    }
    return maior;
}

int menorPontuacao(int quant_partidas){     //Calcula a menor pontucao de todas as partidas
    int menor;
    menor = pontuacaoJogador(1,quant_partidas);

    for(int i = 2; i <= 5; i++){
        if((pontuacaoJogadorTotal(i, quant_partidas)) < menor){
            menor = pontuacaoJogadorTotal(i, quant_partidas);
        }
    }
    return menor;
}

int pontuacaoJogadorTotal(int idjog, int quant_partidas){       //Calcula a pontuacao de um jogador em todas as partidas
    int total = 0;

    for(int i = 1; i <= quant_partidas; i++){
        total = total + pontuacaoJogador(idjog, i);
    }
    return total;
}

int idmaiorPontuacao(int partida){     //Calcula a maior pontuacao de uma partida, retorna o id desse jogador
    int idmaior = 1;
    int maior;
    maior = pontuacaoJogador(1, partida);
    
    for(int i = 2; i <= 5; i++){
        if((pontuacaoJogador(i, partida)) > maior){
            idmaior = i;
            maior = pontuacaoJogador(i, partida);
        }
    }
    return idmaior;
}

int idmenorPontuacao(int partida){      //Calucla a menor pontuacao de uma partida, retorna o id desse jogador
    int idmenor = 1;
    int menor = 0;
    menor = pontuacaoJogador(1, partida);

    for(int i = 2; i <= 5; i++){
        if((pontuacaoJogador(i, partida)) < menor){
                idmenor = i;
                menor = pontuacaoJogador(i, partida);
            }
        }
    return idmenor;
}
/////////// Auxiliares

/////////// Validacoes
int validaIdade(int idade){     //Retorna 0 se idade está entre 0 e 150
    if(idade > 0 && idade < 150){
        return 0;
    }else{
        printf("\nIdade invalida, tente novamente");
        return 1;
    }
}

int validaPosicao(char posicao[]){      //Retorna 0 se posicao for valida
    if(strcmp(posicao, "ADC") || 
    strcmp(posicao, "SUP") || 
    strcmp(posicao, "MID") || 
    strcmp(posicao, "JG") || 
    strcmp(posicao, "TOP")){
        return 0;
    }else{
        printf("\nPosicao invalida, tente novamente");
        return 1;
    }
}

int validaKDA(int kda){     //Retorna 0 se o kda for valido
    if(kda >= 0){
        return 0;
    }else{
        printf("\nNumero invalido, tente novamente");
        return 1;
    }
}

int validaBool(char ans){       //Retorna 0 se a resposta for valida
    if(ans == 's' || ans == 'S' || ans == 'n' || ans == 'N'){
        return 0;
    }else{
        printf("\nReposta invalida, tente novamente");
        return 1;
    }
}

int validaTorres(int numTorres){        //Retorna 0 se o numero de torres for valido
    if(numTorres > 0 && numTorres <= 11){
        return 0;
    }else{
        printf("\nNumero de torres invalida, tente novamente\n");
        return 1;
    }
}

int validaId(int id){       //Retorna 0 se o id for valido
    if(id > 0 && id <= 5){
        return 0;
    }else{
        printf("Id invalido, jogador nao existe, tente novamente");
        return 1;
    }
}
/////////// Validacoes