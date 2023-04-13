#include <stdio.h>

int main(){
    int n,j=1,matricula,xp,hora_contrato,hora_trabalhada,hora_aux=0;
    float valor_hora,valor_xtra=0,inss=0,ir=0,salario_brt,salario_liq;
    char funcao;

    puts("Digite a quantidade de funcionarios a serem processados: ");
    scanf("%i",&n);

    for (int i = 1; i <=n; i++){
        printf("Digite a matricula:\n");
        scanf("%i",&matricula);
       
        do {
            getchar();
            printf("Digite a funcao(p,a e g):\n");
            scanf("%c",&funcao);
            printf("Digite a experiencia:\n");
            scanf("%i",&xp);
            j=1;
            switch (funcao){
                case 'p':
                    if (xp<=2){
                        valor_hora=25;
                    }else if(xp>=3 && xp<=5){
                        valor_hora=30;
                    }else{
                        valor_hora=38;
                    }
                    break;
                case 'a':
                    if (xp<=2){
                        valor_hora=45;
                    }else if(xp>=3 && xp<=5){
                        valor_hora=55;
                    }else{
                        valor_hora=70;
                    }
                    break;
                case 'g':
                    if (xp<=2){
                        valor_hora=85;
                    }else if(xp>=3 && xp <=5){
                        valor_hora=102;
                    }else{
                        valor_hora=130;
                    }        
                    break;
                default:
                    puts("Funcao invalida.\n");
                    j=0;
                    break;
            }
        }while (j==0);
        
        printf("Digite as horas do contrato:\n");
        scanf("%i",&hora_contrato);
        printf("Digite as horas trabalhadas:\n");
        scanf("%i",&hora_trabalhada);

        if(hora_trabalhada>hora_contrato){
            hora_aux=hora_trabalhada-hora_contrato;
            if (hora_aux<=13){
                valor_xtra=valor_hora*1.23;
                salario_brt=hora_aux*valor_xtra+hora_contrato*valor_hora;
            }else if (hora_aux>13 && hora_aux<=22){
                valor_xtra=valor_hora*1.37;
                salario_brt=hora_aux*valor_xtra+hora_contrato*valor_hora;
            }else if(hora_aux>22){
                valor_xtra=valor_hora*1.56;
                salario_brt=hora_aux*valor_xtra+hora_contrato*valor_hora;
            }
        }else{
            salario_brt=hora_trabalhada*valor_hora;
        }

        inss=salario_brt*0.11;
        if (salario_brt>4200){
            ir = (salario_brt-inss)*0.3;
        }else if(salario_brt<=4200 && salario_brt>2700){
            ir = (salario_brt-inss)*0.2;
        }else if(salario_brt<=2700 && salario_brt>1500){
            ir = (salario_brt-inss)*0.15;
        }else{
            ir=0;
        }

        salario_liq=salario_brt-inss-ir;

        printf("O funcionario de matricula %i possui de salario bruto R$%.2f, %i horas extras, inss de R$%.2f e ir de R$%.2f; e salario liquido R$%.2f.\n",matricula,salario_brt,hora_aux,inss,ir,salario_liq);
        printf("\n");
    }
}