#include <stdio.h>

void imprime_caracteres(char vetor[],int n){
    vetor[n];
    printf("\n");
    for (int i = 0; i < n; i++){
       printf ("vetor[%i]=%c ",i,vetor[i]); 
    } 
}

char converte_caracteres(char vetor[],int n,int &c_c){
    c_c=0;
    for (int i = 0; i < n; i++){
        if (vetor[i]>=65 && vetor[i]<=90){
            vetor[i]=vetor[i]+32;
            c_c++;
        }else if (vetor[i]>=92 && vetor[i]<=122){
            vetor[i]=vetor[i]-32;
            c_c++;
        }
    }
    return vetor[n];
}

char le_caracteres(char vetor[],int n){

    printf("\nDigites os caracteres do Vetor: \n");
    for (int i = 0; i < n; i++){
        printf("vetor[%i]: ",i);
        getchar();
        scanf("%c",&vetor[i]);
    } 
    return vetor[n];
}

int main(){
    int n;
    printf("Digite o valor de N: ");
    scanf ("%i",&n);
    char vetor[n];
    int c_c;
    le_caracteres(vetor,n);
    converte_caracteres(vetor,n,c_c);
    printf("\nA quatidade de conversoes: %i",c_c);
    imprime_caracteres(vetor,n);
}