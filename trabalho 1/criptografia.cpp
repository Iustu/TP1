#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    long long cpf,cpfnovo,m1,m1i,m2,m2i,meio;
    int j;

    //entrada do cpf
    do{
        j=1;
        printf("Digite o cpf a ser cpritografado: \n");
        scanf("%lld",&cpf);

        if (cpf<10000000000){
            printf("Cpf invalido.");
            j=0;
            printf("\n");
        }
    }while(j==0);

    //passar o primeiro pro meio
    meio=cpf/10000000000;
    meio=meio*100000;

    //inverter os ultimos 5 e passar pra primeiro
    m1=cpf%100000;
    int a1=m1/10000;
    int a2=(m1-(a1*10000))/1000;
    int a3=(m1-(a1*10000)-(a2*1000))/100;
    int a4=(m1-(a1*10000)-(a2*1000)-(a3*100))/10;
    int a5=m1-(a1*10000)-(a2*1000)-(a3*100)-(a4*10);
    m1i=a5*10000+a4*1000+a3*100+a2*10+a1;
    m1i=m1i*1000000;

    //passar 2 a 6 para o final e inverter
    m2=cpf/100000;
    m2=m2%100000;
    a1=m2/10000;
    a2=(m2-(a1*10000))/1000;
    a3=(m2-(a1*10000)-(a2*1000))/100;
    a4=(m2-(a1*10000)-(a2*1000)-(a3*100))/10;
    a5=m2-(a1*10000)-(a2*1000)-(a3*100)-(a4*10);
    m2i=a5*10000+a4*1000+a3*100+a2*10+a1;

    cpfnovo=m1i+meio+m2i;

    //aleatorio
    srand(time(NULL));
    int k =9;

    //giro
    for (int i = 1; i <= k; i++)
    {
        cpfnovo=(cpfnovo/10)+(cpfnovo%10)*10000000000;
    }
    //soma K
    cpfnovo=cpfnovo*10+k;

    //katchau
    printf("Este e o cpf apos ser criptografado: %lld",cpfnovo);

}