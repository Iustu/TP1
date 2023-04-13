#include <stdio.h>
#include <string.h>

struct produto{
    int codigo='\0';
    char descricao[31];
    char categoria='\0';
    int quantidade='\0';
    float preco='\0';
};

void revaluar(struct produto p[]){

}

void listar_produtos_b(struct produto p[]){
int qtd;
    printf("\nDigite o a quantidade minima a ser averiguada:");
    scanf("%i",&qtd);

    printf("\nQtd minima: %i\n",qtd);
    printf("--------------------------------------------------------\n");
    printf("Codigo Descricao                         Categ Qtd Preco\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < 50; i++){
        if (p[i].codigo!='0' && p[i].quantidade<=qtd){
            
            printf("%i %s",p[i].codigo,p[i].descricao);
            int e=37-strlen(p[i].descricao);
            for (int j = 0; j < e; j++)printf(" ");
            printf("%c   %i   %.2f\n",p[i].categoria,p[i].quantidade,p[i].preco);

        }
    }
    printf("--------------------------------------------------------\n");
}

void listar_produtos_cd(struct produto p[]){
    
}

void listar_produtos_d(struct produto p[],int i){
    bool trocou=true;
    int k=i-1;

    while (k>0 && trocou){
        trocou=false;
        for (int j = 0; j < k; j++){
            if (strcmpi(p[j].descricao,p[j+1].descricao)>0){
                produto aux=p[j+1];
                p[j+1]=p[j];
                p[j]=aux;

                trocou=true;
            }
            
        }
        k--;
    }

    printf("--------------------------------------------------------\n");
    printf("Codigo Descricao                         Categ Qtd Preco\n");
    printf("--------------------------------------------------------\n");
    for (int j = 0; j < i; j++){
            printf("%i %s",p[j].codigo,p[j].descricao);
            int e=37-strlen(p[j].descricao);
            for (int l = 0; l < e; l++)printf(" ");
            printf("%c   %i   %.2f\n",p[j].categoria,p[j].quantidade,p[j].preco);
    }
    printf("--------------------------------------------------------\n");
    
}

void abater_estoque(struct produto p[]){
    int cod,qtd,t,t1;
    do{
        printf("\nDigite o codigo do produto que sera abatido: \n");
        scanf("%i",&cod);
        t1=1;
        if (cod<100000 || cod>999999){
            printf("ERRO, o codigo deve ter 6 digitos.\n");
            t1=0;
        }
    }while (t1==0);
    do{ 
        t1=1;   
        printf("Digite a quantida a ser abatida: \n");
        scanf("%i",&qtd);
        if (qtd<=0){
            printf("Erro, impossivel retirar valores menores ou iguais a zero!\n");
            t1=0;
        }
    }while (t1==0);

    t=0;
    for (int i = 0; i <50; i++){
        if (p[i].codigo==cod && p[i].quantidade>=qtd){
            p[i].quantidade=p[i].quantidade-qtd;
            printf("\nCodigo: %i\n",cod);
            printf("Qtd.: %i\n",qtd);
            printf("Quantidade abatida. Produto '%s' agora tem %i em estoque.\n",p[i].descricao,p[i].quantidade);
            t=1;
            break;
        }else if(p[i].codigo==cod && p[i].quantidade<qtd){
            printf("\nCodigo: %i\n",cod);
            printf("Qtd.: %i\n",qtd);
            printf("Produto '%s' tem somente %i em estoque.\n",p[i].descricao,p[i].quantidade);
            t=1;
            break;
        }
    }
    if (t==0){
        printf("Codigo: %i\nProduto nao existe!\n",cod);
    }

}

void excluir_produto(struct produto p[]){
    int cod,t,t1;
    t=0;
    do{
        printf("\nDigite o codigo do produto que sera excluido: \n");
        scanf("%i",&cod);
        t1=0;
        if (cod<100000 || cod>999999){
            printf("ERRO, o codigo deve ter 6 digitos.\n");
            t1=1;
        }
    }while (t1==1);

    for (int i = 0; i <50; i++){
        if (p[i].codigo==cod && p[i].quantidade==0){
            printf("\nCodigo: %i\n",cod);
            printf("Produto %s excluido com sucesso!\n",p[i].descricao);
            p[i].codigo='\0';
            //strcpy(p[i].descricao,'\0');
            p[i].categoria='\0';
            p[i].quantidade='\0';
            p[i].preco='\0';
            t=1;
            break;
        }else if(p[i].codigo==cod && p[i].quantidade>0){
            printf("\nCodigo: %i\n",cod);
            printf("ERRO! %s tem %i em estoque!\n",p[i].descricao,p[i].quantidade);
            t=1;
            break;
        }
    }
    if (t==0){
        printf("Codigo: %i\nProduto nao existe!\n",cod);
    }
}

void incluir_produto(int &codigo, char descricao[],char &categoria,int &quantidade,float &preco,int i,struct produto p[]){
    printf("\n");
    int t;
    do{
        t=0;
        printf("Codigo: \n");
        scanf ("%i",&codigo);
        getchar();
        if (codigo<100000 || codigo>999999){
            printf("ERRO, o codigo deve ter 6 digitos.\n");
            t=1;
        }
        for ( int j = 0; j < i; j++){
            if(p[j].codigo==p[i].codigo){
                printf("ERRO, os codigos nao podem ser repetidos(conflito com o produto %s).\n",p[j].descricao);
                t=1;
            }
        }
    }while(t==1);

    do{
        t=0;
        printf("Descricao: \n");
        gets(descricao);
        strupr(descricao);
        if (strlen(descricao)<4 || strlen(descricao)>30 ){
            printf("ERRO, a descricao deve ter de 4 a 30 caracteres.\n");
            t=1;
        }
    }while (t==1);

    do{
        t=0;
        printf("Categoria: \n");
        scanf("%c",&categoria);
        if (categoria=='a' || categoria=='e' || categoria=='i' || categoria=='o' || categoria=='u'){
            categoria=categoria-32;
        }
        if (categoria!='A' && categoria!='E' && categoria!='I' && categoria!='O' && categoria!='U'){
            printf("ERRO. Categoria deve A,E,I,O ou U.\n");
            t=1;
            getchar();
        }
    }while (t==1);

    do{
        t=0;
        printf("Qtd.: \n");
        scanf("%i",&quantidade);
        if (quantidade<=0){
            printf("ERRO. A quantidade de deve ser maior que 0.\n");
            t=1;
        }
    }while(t==1);

    do{
        t=0;
        printf("Preco:\n");
        scanf("%f",&preco);
        if (preco<=0){
            printf("ERRO. O preco deve ser maior que 0.\n");
            t=1;
        }
    }while(t==1);

    printf("\nCodigo: %i\n",codigo);
    printf("Descricao: %s\n",descricao);
    printf("Categoria: %c\n",categoria);
    printf("Qtd.: %i\n",quantidade);
    printf("Preco: R$%.2f\n",preco);
    printf("\nProduto cadastrado com sucesso!\n");
}

int main(){
    produto p[50];

    int escolha,escolha2;
    int i=0;
    do{
        printf("\nMenu Principal\n");
        printf("1 - Incluir produto\n");
        printf("2 - Excluir produto\n");
        printf("3 - Abater do estoque\n");
        printf("4 - Listar produtos\n");
        printf("5 - Aplicar aumento/desconto\n");
        printf("6 - fim\n");
        printf("Digite a acao desejada: \n");
        scanf("%i",&escolha);
        switch (escolha){
            case 1:
                for (int j = 0; j < i; j++){
                    if (p[j].codigo=='\0'){
                        i=j;
                        break;
                    }
                    break;
                }
                if(i==49){
                    printf("\nNUMERO MAXIMO DE PRODUTOS ATINGIDO.\n");
                }else {
                    incluir_produto(p[i].codigo,p[i].descricao,p[i].categoria,p[i].quantidade,p[i].preco,i,p);
                    i++;
                }
                break;
            case 2:
                excluir_produto(p);
                break;
            case 3:
                abater_estoque(p);
                break;
            case 4:
                do{
                    printf("\nMenu da Listagem\n");
                    printf("1-Listar todos os produtos(ordenado por descricao)\n");
                    printf("2-Listar todos os produtos(ordenado por categoria/descricao)\n");
                    printf("3-Listar produtos com estoque baixo\n");
                    printf("5-Voltar\n");
                    printf("Digite a opcao desejada: \n");
                    scanf("%i",&escolha2);
                    switch (escolha2){
                        case 1:
                            listar_produtos_d(p,i);
                            break;
                        case 2:
                            listar_produtos_cd(p);
                            break;
                        case 3:
                            listar_produtos_b(p);
                            break;
                        case 5:
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                }while(escolha2!=5);
                break;
            case 5:
                revaluar(p);
                break;
            case 6:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
            }
    }while(escolha!=6);

    printf("%i %s %c %i %f",p[0].codigo,p[0].descricao,p[0].categoria,p[0].quantidade,p[0].preco);
}