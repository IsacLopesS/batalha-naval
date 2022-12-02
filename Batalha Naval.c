/*
* CSI030-2018-01 - Programacao de Computadores I
* Nome........: Isac Lopes Silva
* Matricula...: 18.1.8135
* Curso.......: Engenharia da Computação
* Exercicio...: pagina X - exercicio Y / atividade pratica 002
*/


/* OBS:
- as embarcações sao geradas e insridas no tabuleiro de forma aleatoria.
- Optei por gerar de 45 a 75 submarinos, e de 5 a 25 porta-avioes
- Optei por utilizar apenas um tabuleiro para os dois jogadores
    -> optei por representar as embarcações da seguinte forma:
- embarcacao destruida: '*'
- submarino: '+'
- porta aviao: '^#'   */
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//inicia o tabuleiro do jogo
void inicia_tabuleiro(char tabuleiro[][16]){

 int i,j;
    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
           tabuleiro[i][j]='~';
          // tab2[i][j]='1';
        }
    }


}
//imprime o tabuleiro do jogo
void imprime_tabuleiro(char tabuleiro[][16]){

    int i,j; //i = linha j = coluna  x= linha y=coluna
         printf("   0   1   2   3   4   5   6   7   8   9   10  11  12  13  14");
        printf("\n");
         for(i=0;i<15;i++){
           printf("%d",i);
        for(j=0;j<15;j++){
                if(tabuleiro[i][j]=='*'){
                        if(i<10){
                    printf("  * ");
                        }else{
                           printf(" *  ");
                        }
                        }else if(tabuleiro[i][j]=='8'){
                        if(i<10){
                         printf("  ~ ");
                        }else{
                     printf(" ~  ");
                        }

                } else{
                 if(i<10){
                         printf("  - ");
                        }else{
                     printf(" -  ");
                }
        }
        }
        printf("\n");
    }

printf("\n\n\n");

}

//gera submarinos e os coloca em pontos coordenados aleatórios
void gerar_submarino(char tabuleiro[][16]){
    int i;
    int x,y;
    int submarinos;
    //vamos gerar de 45 a 75 submarinos
    submarinos= 45 + rand() % 31;
    for(i=0;i<submarinos;i++){
        //coordenadas premiadas (x,y) onde se encontrarao os submarinos:
        x= 0 + rand() % 15;
        y= 0 + rand() % 15;
        if(tabuleiro[x][y]=='~'){
        tabuleiro[x][y]= '+'; //submarino é representado por +
    }else{
        i=i-1;
    }
}

}
//gera porta avioes e os coloca em pontos coordenados aleatórios
 void gerar_porta_avioes(char tabuleiro[][16]){
     //x=linha y=coluna quando
int i,linha,coluna;
int porta_aviao;

//vamos gerar de 5 a 25 porta-avioes
    porta_aviao= 5 + rand() % 21;
    //coordenadas premiadas
for(i=0;i<porta_aviao;i++){
     linha= 0 + rand() % 15;
        coluna= 0 + rand() % 15;
        if(tabuleiro[linha][coluna]=='~'){
                if(tabuleiro[coluna][linha+1]=='~' && (linha<14)){

                     tabuleiro[coluna][linha]= '^'; //porta aviao é representado por ^#
                     tabuleiro[coluna][linha+1]='#';

                }else if(tabuleiro[coluna][linha-1]=='~') {

                    tabuleiro[coluna][linha-1]='^'; //porta aviao é representado por ^#
                    tabuleiro[coluna][linha]= '#';

                }

    }else{
        i=i-1;
    }
}


}
//nomes dos jogadores e instruçoes de jogo
void nomes_jogadores(char j1[],char j2[]){

    printf("---------------BATALHA NAVAL--------------------\n\n");
    printf("Instrucoes:\n\n");
    printf("-> joga-se com dois jogadores, quem fizer mais pontos ganha\n");
    printf("-> embarcacao destruida: '*'\n-> submarino: '+' (100 pts)\n->porta aviao: '^#' (200 pts)\n");
    printf("\njogador 1, insira seu nome: ");
    scanf("%s",j1);

     printf("jogador 2, insira seu nome: ");
    scanf("%s",j2);

system("cls");

}
//jogador escolhe onde atirar
void dar_tiro(char tabuleiro[][16],int tiro[2]){

int i;

    printf("\ncordenada[coluna]:");
    scanf("%d",&tiro[0]); //coluna
     printf("cordenada[linha]:");
    scanf("%d",&tiro[1]); //linha
    //system("cls");




}
//confere quantos pontos fez o tiro, e soma os pontos do jogador1
int confere_tiro(char tabuleiro[][16],int tiro[2],int pts){


    int i,j;
     if(tiro[0]<0 || tiro[0]>14 || tiro[1]<0 || tiro[1]>14){
        printf("essa coordenada nao existe no tabuleiro!\n");
        return pts;
    }else if(tabuleiro[tiro[1]][tiro[0]]=='*'){
        printf("essa embarcacao ja foi destruida!\n");
        return pts;
    }
    else if(tabuleiro[tiro[1]][tiro[0]]=='~'|| tabuleiro[tiro[1]][tiro[0]]=='8'){
            printf("nao ha nada nessa coordenada; pontuacao atual %d\n",pts);
        pts=pts + 0;
       tabuleiro[tiro[1]][tiro[0]]='8'; //quando 8, imprime ~ no tabuleiro
        return pts;
    } else if(tabuleiro[tiro[1]][tiro[0]]=='+'){
        pts=pts+100;
        printf("submarino abatido;  pontuacao atual: %d\n",pts);
        tabuleiro[tiro[1]][tiro[0]]='*'; //quando * imprime * no tabuleiro
        return pts;
    } else if((tabuleiro[tiro[1]][tiro[0]]=='#')||(tabuleiro[tiro[1]][tiro[0]]=='^')){
        pts=pts + 200;
        printf("porta aviao abatido; pontuacao atual: %d\n",pts);
        tabuleiro[tiro[1]][tiro[0]]='*';
    j=tiro[0]; //coluna
    i=tiro[1];
    if(tabuleiro[tiro[1]][(j-1)]=='#' || tabuleiro[tiro[1]][(j-1)]=='^'){
            tabuleiro[tiro[1]][(j-1)]='*';
        }else if(tabuleiro[tiro[1]][(j+1)]=='#' || tabuleiro[tiro[1]][(j+1)]=='^'){
            tabuleiro[tiro[1]][(j+1)]='*';

    }
    return pts;
    }

}
//confere quantos pontos fez o tiro, e soma os pontos do jogador2
int confere_tiro_2(char tabuleiro[][16],int tiro[2],int pts){

    int i,j;
    if(tiro[0]<0 || tiro[0]>14 || tiro[1]<0 || tiro[1]>14){
        printf("essa coordenada nao existe no tabuleiro!\n");
        return pts;
    }else if(tabuleiro[tiro[1]][tiro[0]]=='*'){
        printf("essa embarcacao ja foi destruida!\n");
        return pts;
    }
    else if(tabuleiro[tiro[1]][tiro[0]]=='~' || tabuleiro[tiro[1]][tiro[0]]=='8'){
            printf("nao ha nada nessa coordenada; pontuacao atual %d\n",pts);
        pts=pts + 0;
       tabuleiro[tiro[1]][tiro[0]]='8'; //quando 8, imprime ~ no tabuleiro
        return pts;
    } else if(tabuleiro[tiro[1]][tiro[0]]=='+'){
        pts=pts+100;
        printf("submarino abatido;  pontuacao atual: %d\n",pts);
        tabuleiro[tiro[1]][tiro[0]]='*'; //quando * imprime * no tabuleiro
        return pts;
    } else if((tabuleiro[tiro[1]][tiro[0]]=='#')||(tabuleiro[tiro[1]][tiro[0]]=='^')){
        pts=pts + 200;
        printf("porta aviao abatido; pontuacao atual: %d\n",pts);
        tabuleiro[tiro[1]][tiro[0]]='*';
    j=tiro[0]; //coluna
    if(tabuleiro[tiro[1]][(j-1)]=='#' || tabuleiro[tiro[1]][(j-1)]=='^'){
            tabuleiro[tiro[1]][(j-1)]='*';
        }else if(tabuleiro[tiro[1]][(j+1)]=='#' || tabuleiro[tiro[1]][(j+1)]=='^'){
            tabuleiro[tiro[1]][(j+1)]='*';

    }
    return pts;
    }


}

//função principal

int main(){

    int reiniciar=1; //permite ao final da partida, reiniciar o jogo
    while(reiniciar==1){
    srand(time(NULL));

    int i,j;
    char tabuleiro[16][16]; //tabuleiro do jogo
    char jogador1[15],jogador2[15]; //nome dos jogadores
    int tiro[2]; //recebe as coordenadas dos tiros
    int pts=0,pts2=0; //recebe a pontuação de cada jogador

    nomes_jogadores(jogador1,jogador2);
    inicia_tabuleiro(tabuleiro);
    gerar_porta_avioes(tabuleiro);
    gerar_submarino(tabuleiro);

    //faz com que o jogo corra de forma alternada
    for(i=0;i<6;i++){
            if(i%2==0){
    imprime_tabuleiro(tabuleiro);
    printf("\n%s, ordene seu ataque:",jogador1);
    dar_tiro(tabuleiro,tiro);
    pts=confere_tiro(tabuleiro,tiro,pts);

            } else{
    imprime_tabuleiro(tabuleiro);
    printf("\n%s, ordene seu ataque:",jogador2);
    dar_tiro(tabuleiro,tiro);
    pts2=confere_tiro_2(tabuleiro,tiro,pts2);

            }
    }
    printf("FIM DE JOGO\n");
    //imprime o estado final do tabuleiro
    printf("-----tabuleiro resultante------\n\n");
     printf("   0   1   2   3   4   5   6   7   8   9   10  11  12  13  14\n");
    for(i=0;i<15;i++){
            printf("%d",i);
    for(j=0;j<15;j++){
        if(tabuleiro[i][j]=='8'){
            tabuleiro[i][j]='~';
        }
          if(i<10){
                    printf("  %c ",tabuleiro[i][j]);
                        }else{
                           printf(" %c  ",tabuleiro[i][j]);
                        }
    }
    printf("\n");
}
printf("\n");
    //exibe a pontuação final de cada jogador
    printf("\n%s -> %d pts",jogador1,pts);
     printf("\n%s -> %d pts",jogador2,pts2);
     //fala quem venceu o jogo ou se deu empate
     if(pts2<pts){
            printf("\nParabens %s! voce venceu! :)",jogador1);
     }else if(pts<pts2){
            printf("\nParabens %s! voce venceu! :)",jogador2);
     }else {
            printf("\nempate!");
     }

    printf("\ndigite 1 para comecar um novo jogo, ou 0 para encerrar: ");
    scanf("%d",&reiniciar);
    system("cls");
    }
    printf("\nisso e tudo, obrigado!");

}
