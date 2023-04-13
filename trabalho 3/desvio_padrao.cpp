#include <stdio.h>
#include <math.h>

void imprime_vetores(int v1[],int n,float v2[],int t){
    printf("\nv1= [");
    for (int i = 0; i < n; i++){
        printf("%i ",v1[i]);
    }
    printf("]\nv2= [");
    for (int i = 0; i < t; i++){
        printf("%.2f ",v2[i]);
    }
    printf("]");
}

float desvio_padrao(int aux[],int k){
    float soma=0;
    float soma2=0;
    float media=0;
    float aux2=0;
    float desvio=0;
    for (int i = 0; i < k; i++){
       soma=aux[i]+soma;
    }
    media=soma/k;
    for (int i = 0; i < k; i++){
        soma2=pow((aux[i]-media),2)+soma2;
    }
    aux2=soma2/(k-1);
    desvio=sqrt(aux2);
    return desvio;
}

float calcula_dp(int v1[],int n,float v2[],int k,int t){
    int c=0;
    for (int i = 0; i < n; i=i+k){
        int aux[k];
        int c2=0;
        for (int j = i;; j++){
            aux[c2]=v1[j];
            c2++;
            if (c2==(n/t)) break;
        }
        v2[c]=desvio_padrao(aux,k);
        c++;
    }
}

int le_vetor(int v1[],int n){

    printf("\nDigites os valores de: \n");
    for (int i = 0; i < n; i++){
        printf("v1[%i]: ",i);
        scanf("%i",&v1[i]);
    } 
    return v1[n];
}

int main(){
    int n,k,t=1;
    do{
        printf("Digite o valor de N>2: ");
        scanf ("%i",&n);
        printf("Digite o valor de 2<=K<=N e divisor de N: ");
        scanf ("%i",&k);

        if(n>2 && k>=2 && k<=n && n%k==0){
            t=1;
        }else{
            printf("\nValor inadequado de alguma das variaveis.\n");
            t=0;
        }
    }while (t==0);
    int v1[n];
    t=n/k;
    float v2[t];

    le_vetor(v1,n);
    calcula_dp(v1,n,v2,k,t);
    imprime_vetores(v1,n,v2,t);
}