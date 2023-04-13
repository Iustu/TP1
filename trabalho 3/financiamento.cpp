#include <stdio.h>
#include <time.h>
#include <math.h>

void calcula_juros_mensalidade(float &mensalidade,float &juros,int fator,float emprestimo,int meses){
    juros=1.8+(fator*0.2);

    int parcelas=meses;
    float pot=meses/12.0;
    float por=1+(juros*0.01);

    mensalidade=(emprestimo*pow((por),pot))/parcelas;
}

int fator_de_risco(int idade,float patrimonio){
    int fator;
    if (idade<=30){
        fator=3;
    }else if(idade>=31 && idade<=50){
        fator=6;
    }else if(idade>=51 && idade<=60){
        fator=9;
    }else{
        fator=12;
    }

    if (patrimonio<=50000.00){
        fator=fator+2;
    }else if(patrimonio>=50000.01 && patrimonio<=200000.00){
        fator=fator+1;
    }else if(patrimonio>=200000.01 && patrimonio<=1000000.00){
        fator=fator-1;
    }else if (patrimonio>1000000){
        fator=fator-2;
    }

return fator;
}

int data_atual(int vetor_data_atual[]) {
 time_t t = time(NULL);
 struct tm lt = *localtime(&t);
 int ano1 = lt.tm_year + 1900;
 int mes1 = lt.tm_mon + 1;
 int dia1 = lt.tm_mday;
 vetor_data_atual[0]=dia1;
 vetor_data_atual[1]=mes1;
 vetor_data_atual[2]=ano1;
 
 return vetor_data_atual[3];
}
bool e_bissesto(int ano){
    if (ano%4==0) return true;
    else return false;
}
bool e_data_valida(int dia, int mes,int ano){
    if (mes>=1 && mes<=12){
        if (mes==2){
            if (e_bissesto(ano))
                if (dia>=1 && dia<=29) return true;
                else return false;
            else if (dia>=1 && dia<=28) return true;
                else return false;
        }else if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
            if (dia>=1 && dia<=31) return true;
            else return false;
        }else if (dia>=1 && dia<=30) return true;
             else return false;  
    }else return false;
}
int numero_dias(int dia,int mes,int ano){
int numero_dias;
        int fevereiro;
        if (e_bissesto(ano)) fevereiro=29;
        else fevereiro=28;
        
        if (mes==1){
            numero_dias=dia;
        }
        if (mes==2){
            numero_dias=dia+31;
        }
        if (mes==3){
            numero_dias=dia+31+fevereiro;
        }
        if (mes==4){
            numero_dias=dia+31+fevereiro+31;
        }
        if (mes==5){
            numero_dias=dia+31+fevereiro+31+30;
        }
        if (mes==6){
            numero_dias=dia+31+fevereiro+31+30+31;
        }
        if (mes==7){
            numero_dias=dia+31+fevereiro+31+30+31+30;
        }
        if (mes==8){
            numero_dias=dia+31+fevereiro+31+30+31+30+31;
        }
        if (mes==9){
            numero_dias=dia+31+fevereiro+31+30+31+30+31+31;
        }
        if (mes==10){
            numero_dias=dia+31+fevereiro+31+30+31+30+31+31+30;
        }
        if (mes==11){
            numero_dias=dia+31+fevereiro+31+30+31+30+31+31+30+31;
        }
        if (mes==12){
            numero_dias=dia+31+fevereiro+31+30+31+30+31+31+30+31+30;
        }
    numero_dias=(ano*365)+(ano/4)+numero_dias;
    return numero_dias;
}
int calcular_idade(int dia,int mes,int ano){
    int idade;
    int vetor_data_nascimento[3];
    vetor_data_nascimento[0]=dia;
    vetor_data_nascimento[1]=mes;
    vetor_data_nascimento[2]=ano;
    int vetor_data_atual[3];
    data_atual(vetor_data_atual);
    int dia_nascimento=numero_dias(vetor_data_nascimento[0],vetor_data_nascimento[1],vetor_data_nascimento[2]);
    int dia_atual=numero_dias(vetor_data_atual[0],vetor_data_atual[1],vetor_data_atual[2]);

    int diferenca= dia_atual-dia_nascimento;
    idade=(diferenca/365);
}

void le_dados(int &dia,int &mes,int &ano,int &idade,int &meses,float &patrimonio,float &emprestimo){
    int t=0;

    do{
    printf("Digite o dia da data de nascimento: ");
    scanf("%i",&dia);
    printf("Digite o mes da data de nascimento: ");
    scanf("%i",&mes);
    printf("Digite o ano da data de nascimento: ");
    scanf("%i",&ano);
    if (e_data_valida(dia,mes,ano)){
        idade=calcular_idade(dia,mes,ano);
        t=1;
    }else{
        printf("Data invalida(tente digitar os meses ou dias sem '0').\n");
    }
    }while (t==0);

    if (idade<18){
        printf("\nERRO, nao e possivel realizar emprestimos para pessoas menores de idade!");
        return;
    }

    printf("\nDigite o valor do patrimonio: ");
    scanf("%f",&patrimonio);
    if (patrimonio<0){
        printf("\nERRO, o patrimonio minimo e de R$0,00.");
        return;
    }
    printf("Digite o valor do emprestimo: ");
    scanf("%f",&emprestimo);
    if (emprestimo<1000){
        printf("\nERRO, o emprestimo minimo e de R$1000,00.");
        return;
    }
    printf("Digite a quantidade de meses: ");
    scanf("%i",&meses);
    if (meses<2){
        printf("\nERRO, minimo de 2 parcelas.");
        return;
    }

}

int main(){
    int dia,mes,ano,idade,meses;
    float patrimonio,emprestimo;
    le_dados(dia,mes,ano,idade,meses,patrimonio,emprestimo);
    int fator=fator_de_risco(idade,patrimonio);
    printf("\nIdade do cliente: %i;",idade);
    printf("\nSeu fator de risco: %i;",fator);
    float mensalidade;
    float juros;
    calcula_juros_mensalidade(mensalidade,juros,fator,emprestimo,meses);
    printf("\nA taxa de juros do emprestimo almejado: %.2f;",juros);
    printf("\nA mensalidade de cada parcela: %.3f.",mensalidade);
}