#include <stdio.h>
int main(){
    int n,k,t,t2,t3=0,p;

    //tamanha dos vetor
    do {
        printf("Digite o tamanho de s1: ");
        t=1;
        scanf ("%i",&n);
        if (n<=1){
            printf ("Digite um valor de n maior que 1.\n");
            t=0;
        }
    }while(t==0);
    int s1[n];
    do {
        printf("Digite o tamanho de s2: ");
        t=1;
        scanf ("%i",&k);
        if (k<=1){
            printf ("Digite um valor de k maior que 1.\n");
            t=0;
        }
    }while(t==0);
    int s2[k];
    int aux[k];
    printf("\n");

    //entrada de dados
    for (int i = 0; i < n; i++){
        printf("s1[%i]: ",i);
        scanf("%i",&s1[i]);
        if (s1[i]<1 || s1[i]>100){
            printf("\nValor inadequado. Digite outro.\n");
            i=i-1;
        }
    }
    printf("\n");
    for (int i = 0; i < k; i++){
        printf("s2[%i]: ",i);
        scanf("%i",&s2[i]);
        aux[i]=s2[i];
        if (s2[i]<1 || s2[i]>100){
            printf("\nValor inadequado. Digite outro.\n");
            i=i-1;
        }
    }
    printf("\n");

    //exibicao
    for (int i = 0; i < n; i++){
        printf("s1[%i]:%i ",i,s1[i]);
    }
    printf("\n");
    for (int i = 0; i < k; i++){
        printf("s2[%i]:%i ",i,s2[i]);
    }

    //paranaues de testes logicos e resultado
    t2=0;
    for (int i = 0; i < n; i++){
        if (s1[i]==aux[t2]){
            
            if(t2==0){
                p=i;
            }
            t2++;
            
                if (t2==k){
                printf("\nS2 ocorre em S1 de frente pra tras na posicao %i.",p);
                t3=1;
                break;
                }
        }else{
            t=0;
            p=0;
        }
    }
    t2=0;
    for (int i = n-1; i >= 0; i--){
        if (s1[i]==aux[t2]){
            if(t2==0){
                p=i;
            }
            t2++;

                if (t2==k){
                    printf("\nS2 ocorre em S1 de traz pra frente na posicao %i.",p);
                    t3=1;
                    break;
                }
        }else{
            t=0;
        }
    }
    if (t3==0){
        printf("\nS2 nao ocorre em s1.");
    }
    
}