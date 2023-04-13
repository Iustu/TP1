#include <stdio.h>

int main(){
    int n;
    float parcela,total=0,contador=0,potencia=1;
    double pi,raiz12=3.4641016151377;

    puts("Digite o numero n de parcelas(n>0): ");
    scanf("%i",&n);

    if(n>0){
        for (int i=1; i <= n; i++){
            if(i!=1){
                potencia*=3;
            }

            parcela=1.0/((1+contador)*potencia);
            if(i%2==0){
                parcela*=(-1);
            }
        
            total+=parcela;  
            contador+=2;
        }
        pi=raiz12*(total);
        printf("O valor de pi em n parcelas: %.13f",pi);
    }else{
        puts("Valor de n invalido.");
    }
}