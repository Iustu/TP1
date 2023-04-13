#include <stdio.h>

int main(){
    char jogodaveia[3][3];
    int vez=1,m,n,t=1;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            jogodaveia[i][j]='_';
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c ",jogodaveia[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int l = 0; l <= 8; l++){
        if(l==8){
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if(jogodaveia[i][j]=='_'){
                        jogodaveia[i][j]='X';
                        break;
                    }
                }
            }
        }else if(vez%2==1){
            printf("Vez do jogador 1, digite a posicao dejesada: \n");
            do {
                t=1;
                scanf("%i %i",&m,&n);
                if (m>3 || n>3){
                    printf("Posicao inexistente, digite outra\n");
                    t=0;
                }else if(jogodaveia[m-1][n-1]!='_'){
                    printf("Posicao ja escolhida,digite outra\n");
                    t=0;
                }else{
                    jogodaveia[m-1][n-1]='X';
                }
            }while (t==0);
        }else{
            printf("Vez do jogador 2, digite a posisao dejesada:\n");
            
            do {
                t=1;
                scanf("%i %i",&m,&n);
                if (m>3 || n>3){
                    printf("Posicao inexistente, digite outra\n");
                    t=0;
                }else if(jogodaveia[m-1][n-1]!='_'){
                    printf("Posicao ja escolhida,digite outra\n");
                    t=0;
                }else{
                    jogodaveia[m-1][n-1]='O';
                }
            }while (t==0);
        }

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                printf("%c ",jogodaveia[i][j]);
            }
        printf("\n");
        }
        printf("\n");

        if (jogodaveia[0][0]!='_' && jogodaveia[0][0]==jogodaveia[0][1] && jogodaveia[0][0]==jogodaveia[0][2]){
            printf("O jogador da vez venceu!");
            break;
        }else
        if (jogodaveia[1][0]!='_' && jogodaveia[1][0]==jogodaveia[1][1] && jogodaveia[1][0]==jogodaveia[1][2]){
            printf("O jogador da vez venceu!");
            break;
        }else
        if (jogodaveia[2][0]!='_' && jogodaveia[2][0]==jogodaveia[2][1] && jogodaveia[2][0]==jogodaveia[2][2]){
            printf("O jogador da vez venceu!");
            break;
        }
        if (jogodaveia[0][0]!='_' && jogodaveia[0][0]==jogodaveia[1][0] && jogodaveia[0][0]==jogodaveia[2][0]){
            printf("O jogador da vez venceu!");
            break;
        }else
        if (jogodaveia[0][1]!='_' && jogodaveia[0][1]==jogodaveia[1][1] && jogodaveia[0][1]==jogodaveia[2][1]){
            printf("O jogador da vez venceu!");
            break;
        }else
        if (jogodaveia[0][2]!='_' && jogodaveia[0][2]==jogodaveia[1][2] && jogodaveia[0][2]==jogodaveia[2][2]){
            printf("O jogador da vez venceu!");
            break;
        }else
        if (jogodaveia[0][0]!='_' && jogodaveia[0][0]==jogodaveia[1][1] && jogodaveia[0][0]==jogodaveia[2][2]){
            printf("O jogador da vez venceu!");
            break;
        }else
        if (jogodaveia[0][2]!='_' && jogodaveia[0][2]==jogodaveia[1][1] && jogodaveia[0][2]==jogodaveia[2][0]){
            printf("O jogador da vez venceu!");
            break;
        }else if(l==8){
            printf ("O jogador da vez nao ganha, deu velha.");
        }

        vez++;
    }


}