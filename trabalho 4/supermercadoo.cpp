/*==============================
UNIRIO / BSI
TP1 - 4º Trabalho
 . João Pedro - 20202210009
 . Mauro
 . Freederico Mussi - 20022210011
12 de Maio 2021
==============================*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct produto{
    int codigo='\0';
    char descricao[31];
    char categoria='\0';
    int quantidade='\0';
    float preco='\0';
};

//
// FUNCÃO PARA IDENTICAR CAMPOS VAZIOS (NULOS)
//
void detectar_vazio(struct produto p[],int &i){
    for (int j = 0; j < 50; j++){
        if (p[j].codigo=='\0'){
            i=j;
            break;
        }
    }
}

//
// FUNCÃO PARA VERIFICAR NUMERO MÁXIMO DE PRODUTOS (50)
//
bool verificar_input(int i){
    if(i>49){
        printf("\nNUMERO MAXIMO DE PRODUTOS ATINGIDO.\n");
        return false;
    }else {
        return true;
    }
}

//
// CONSTRUCÃO DO MENU PRINCIPAL
//
void menuP(){
    printf("\nMenu Principal\n");
    printf("1 - Incluir produto\n");
    printf("2 - Excluir produto\n");
    printf("3 - Abater do estoque\n");
    printf("4 - Listar produtos\n");
    printf("5 - Aplicar aumento/desconto\n");
    printf("6 - fim\n");
    printf("Digite a acao desejada: \n");
}

//
// CONSTRUCÃO DO MENU DE LISTAGEM
//
void menuL(){
    printf("\nMenu da Listagem\n");
    printf("1-Listar todos os produtos(ordenado por descricao)\n");
    printf("2-Listar todos os produtos(ordenado por categoria/descricao)\n");
    printf("3-Listar produtos com estoque baixo\n");
    printf("5-Voltar\n");
    printf("Digite a opcao desejada: \n");
}

//
// FUNCÃO PARA LEITURA DO CÓDIGO DO PRODUTO (6 dígitos)
//      - le_codigo: rotina usada para entrada dos produtos com valores validos entre 100000 e 999999
//
int le_codigo(){
    int t,codigo;
    do{
    t=1;
    scanf ("%i",&codigo);
    getchar();
    if (codigo<100000 || codigo>999999){
        printf("ERRO, o codigo deve ter 6 digitos. Tente novamente.\n");
        t=0;
    }
    }while(t==0);
    return codigo;
}

//
// FUNCÃO PARA LEITURA DO CÓDIGO DO PRODUTO (6 dígitos)
//      - le_codigo2: rotina usada para operar a listagem, incluindo a opcão de código = 0
//
int le_codigo2(){
    int t,codigo;
    do{
    t=1;
    scanf ("%i",&codigo);
    getchar();

    if (codigo==0){
        return codigo;
    }else if (codigo<100000 || codigo>999999){
        printf("ERRO, o codigo deve ter 6 digitos. Tente novamente.\n");
        t=0;
    }
    }while(t==0);
    return codigo;
}

//
// FUNCÃO PARA VALIDACÃO DA DESCRICÃO DO PRODUTO (4 a 30 caracteres)
//
bool valida_desc(char descricao[]){
    if (strlen(descricao)<4 || strlen(descricao)>31 ){
        printf("ERRO, a descricao deve ter de 4 a 30 caracteres.Tente novamente.\n");
        return false;
    }else return true;
}

//
// FUNCÃO PARA VALIDACÃO DA CATEGORIA DO PRODUTO
//      - le_categoria: rotina usada na validação da entrada das categorias dos produtos (A, B, C, D ou E)
//
char le_categoria(){
    char categoria;
    int t;
    do{
    t=0;
    printf("Categoria: \n");
        scanf("%c",&categoria);
        if (categoria=='a' || categoria=='b' || categoria=='c' || categoria=='d' || categoria=='e'){
            categoria=categoria-32;
        }
        if (categoria!='A' && categoria!='B' && categoria!='C' && categoria!='D' && categoria!='E'){
            printf("ERRO. Categoria deve A,B,C,D ou E.Tente novamente.\n");
            t=1;
            getchar();
        }
    }while (t==1);
    return categoria;
}

//
// FUNCÃO PARA VALIDACÃO DA CATEGORIA DO PRODUTO
//      - le_categoria2: rotina usada na validação da entrada das categorias dos produtos na operacão de listagem
//                       permitindo os valores (A, B, C, D ou E) e incluindo a opcão T (todas as categorais).
//
char le_categoria2(){
    char categoria;
    int t;
    do{
    t=0;
    printf("Categoria: \n");
        scanf("%c",&categoria);
        if (categoria=='a' || categoria=='b' || categoria=='c' || categoria=='d' || categoria=='e' || categoria=='t'){
            categoria=categoria-32;
        }
        if (categoria!='A' && categoria!='B' && categoria!='C' && categoria!='D' && categoria!='E' && categoria!='T'){
            printf("ERRO. Categoria deve A,B,C,D,E ou T.Tente novamente.\n");
            t=1;
            getchar();
        }
    }while (t==1);
    return categoria;
}

//
// FUNCÃO PARA LER UM NÚMERO INTEIRO MAIOR QUE 0
//
int le_inteiro(){
    int t,inteiro;
    do{
        t=0;
        scanf("%i",&inteiro);
        if (inteiro<=0){
            printf("ERRO. este dado deve ser maior que 0. Tente novamente.\n");
            t=1;
        }
    }while(t==1);
    return inteiro;
}

//
// FUNCÃO PARA LER UM NÚMERO REAL MAIOR QUE 0
//
float le_real(){
    int t;
    float real;
    do{
        t=0;
        scanf("%f",&real);
        if (real<=0){
            printf("ERRO. este dado deve ser maior que 0. Tente novamente.\n");
            t=1;
        }
    }while(t==1);
    return real;
}

//
// FUNCÃO PARA LISTAR PRODUTOS CLASSIFICADOS POR CATEGORIA E DESCRICÃO
//
void listar_produtos_cd(struct produto p[]){
    bool trocou=true;
    int k=49;

    while (k>0 && trocou){
        trocou=false;
        for (int j = 0; j < k; j++){
            if (p[j].categoria>p[j+1].categoria){
                produto aux=p[j+1];
                p[j+1]=p[j];
                p[j]=aux;
                trocou=true;
            }
        }
        k--;
    }

    k=49;
    trocou=true;
    while (k>0 && trocou){
        trocou=false;
        for (int j = 0; j < k; j++){
            if (strcmpi(p[j].descricao,p[j+1].descricao)>0 && p[j].descricao==p[j+1].descricao){
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
    
    for (int j = 0; j < 50; j++){
            if (p[j].codigo!='\0'){
            printf("%i %s",p[j].codigo,p[j].descricao);
            int e=37-strlen(p[j].descricao);
            for (int l = 0; l < e; l++)printf(" ");
            printf("%c   %i   %.2f\n",p[j].categoria,p[j].quantidade,p[j].preco);
            }
    }
    printf("--------------------------------------------------------\n");
}

//
// FUNCÃO PARA LISTAR PRODUTOS CLASSIFICADOS POR DESCRICÃO
//
void listar_produtos_d(struct produto p[]){
    bool trocou=true;
    int k=49;

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
    for (int j = 0; j < 50; j++){
            if (p[j].codigo!='\0'){
            printf("%i %s",p[j].codigo,p[j].descricao);
            int e=37-strlen(p[j].descricao);
            for (int l = 0; l < e; l++)printf(" ");
            printf("%c   %i   %.2f\n",p[j].categoria,p[j].quantidade,p[j].preco);
            }
    }
    printf("--------------------------------------------------------\n");
}

//
// FUNCÃO PARA LISTAR PRODUTOS A PARTIR DE UMA ENTRADA DE ESTOQUE MINIMO
//
void listar_produtos_b(struct produto p[]){
int qtd;
    printf("\nDigite o a quantidade minima a ser averiguada:");
    qtd=le_inteiro();

    printf("\nQtd minima: %i\n",qtd);
    printf("--------------------------------------------------------\n");
    printf("Codigo Descricao                         Categ Qtd Preco\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < 50; i++){
        if (p[i].codigo!='\0' && p[i].quantidade<=qtd){
            printf("%i %s",p[i].codigo,p[i].descricao);
            int e=37-strlen(p[i].descricao);
            for (int j = 0; j < e; j++)printf(" ");
            printf("%c   %i   %.2f\n",p[i].categoria,p[i].quantidade,p[i].preco);
        }
    }
    printf("--------------------------------------------------------\n");
}

//
// FUNCÃO PARA REDEFINIR PREÇO A PARTIR DE UM % A SER APLICADO PARA AUMENTO OU REDUCÃO DE PREÇO (DESCONTO)
//
void redefinir_preco (struct produto p[]) {
    int codigo,t, cont = 0;
    float perc;
    char tipo_operacao, categ = '\0';
    bool flag_cat = false;
    
    printf("\nDigite o tipo de operacao desejada (A = Aumento / D = Desconto): ");
    do{
        t=1;
        getchar();
        scanf ("%c", &tipo_operacao);
        if (tipo_operacao!='A' && tipo_operacao!='D' && tipo_operacao!='a' && tipo_operacao!='d'){
            printf("Erro, tente novamente com A ou D.\n");
            t=0;
        }
    }while(t==0);

    printf("\nDigite o codigo do produto ou 0 para categoria: ");
    codigo = le_codigo2();
    if (codigo == 0) {
        printf("\nDigite a categoria do produto (A, B, C, D, E ou T (Todas)): ");
        categ = le_categoria2();
        flag_cat = true;
        }
    printf("Digite o percentual a ser aplicado: ");
    perc = le_real() / 100.0;
    
    if (flag_cat == false) {
        for (int i = 0; i <50; i++){
            if (p[i].codigo == codigo){
                    if (tipo_operacao=='A' || tipo_operacao=='a') p[i].preco *= (1 + perc);
                    if (tipo_operacao=='D' || tipo_operacao=='d') p[i].preco *= (1 - perc);
                cont ++;
                };
            }
        if (cont == 0) printf("Produto nao EXISTE!");
        else if (tipo_operacao=='A' || tipo_operacao=='a') printf("Preco de %d produto(s) aumentados com sucesso.\n", cont);
        else if (tipo_operacao=='D' || tipo_operacao=='d') printf("Preco de %d produto(s) descontados com sucesso.\n", cont);
        }
    else {
        if (categ == 'T') {
            for (int i = 0; i <50; i++){
                if (p[i].categoria != '\0'){
                    if (tipo_operacao=='A' || tipo_operacao=='a') p[i].preco *= (1 + perc);
                    if (tipo_operacao=='D' || tipo_operacao=='d') p[i].preco *= (1 - perc);
                    cont ++;
                }
            }
            if (tipo_operacao=='A' || tipo_operacao=='a') printf("Preco de %d produto(s) aumentados com sucesso.\n", cont);
            else if (tipo_operacao=='D' || tipo_operacao=='d') printf("Preco de %d produto(s) descontados com sucesso.\n", cont);
            }
            else {
                for (int i = 0; i <50; i++){
                    if (p[i].categoria == categ){
                        if (tipo_operacao=='A' || tipo_operacao=='a') p[i].preco *= (1 + perc);
                        if (tipo_operacao=='D' || tipo_operacao=='d') p[i].preco *= (1 - perc);
                    cont ++;
                    }
                }
            if (tipo_operacao=='A' || tipo_operacao=='a') printf("Preco de %d produto(s) aumentados com sucesso.\n", cont);
            else if (tipo_operacao=='D' || tipo_operacao=='d') printf("Preco de %d produto(s) descontados com sucesso.\n", cont);
            }
    }
}

//
// FUNCÃO PARA ABATER UM PRODUTO DO ESTOQUE A PARTIR DO CÓDIGO DO PRODUTO
//
void abater_estoque(struct produto p[]){
    int cod, qtd, t;
        printf("\nDigite o codigo do produto que sera abatido: \n");
        cod=le_codigo();
           
        printf("Digite a quantida a ser abatida: \n");
        qtd=le_inteiro();

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

//
// FUNCÃO PARA INCLUIR UM PRODUTO NO ESTOQUE A PARTIR DO CÓDIGO DO PRODUTO
//
void incluir_produto(int i,struct produto p[]){
    printf("\n");
    int t;
    do{
        t=0;
        printf("Codigo: \n");
        p[i].codigo=le_codigo();
        for ( int j = 0; j < i; j++){
            if(p[j].codigo==p[i].codigo){
                printf("ERRO, os codigos nao podem ser repetidos(conflito com o produto %s).\n",p[j].descricao);
                t=1;
            }
        }
    } while(t==1);

    do{
        t=0;
        printf("Descricao: \n");
        gets(p[i].descricao);
        strupr(p[i].descricao);
        t=valida_desc(p[i].descricao);
    } while (!t);
    
    p[i].categoria=le_categoria();
    printf("Qtd.:\n");
    p[i].quantidade=le_inteiro();
    printf("Preco:\n");
    p[i].preco=le_real();

    printf("\nCodigo: %i\n",p[i].codigo);
    printf("Descricao: %s\n",p[i].descricao);
    printf("Categoria: %c\n",p[i].categoria);
    printf("Qtd.: %i\n",p[i].quantidade);
    printf("Preco: R$%.2f\n",p[i].preco);
    printf("\nProduto cadastrado com sucesso!\n");
}

//
// FUNCÃO PARA EXCLUIR UM PRODUTO NO ESTOQUE A PARTIR DO CÓDIGO DO PRODUTO
//
void excluir_produto(struct produto p[]){
    int cod,t;
    t=0;
    printf("Digite o codigo do produto a ser excluido:\n");
    cod=le_codigo();

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

//
// PROGRAMA PRINCIPAL (MAIN)
//
int main(){
    produto p[50];
    int escolha,escolha2;
    int i=0;
    do{
        menuP();
        scanf("%i",&escolha);
        switch (escolha){
            case 1:
                detectar_vazio(p,i);
                if (verificar_input(i)){
                    incluir_produto(i,p);
                    i++;
                }
                break;
            case 2:
                excluir_produto(p);
                i--;
                break;
            case 3:
                abater_estoque(p);
                break;
            case 4:
                do{
                    menuL();
                    scanf("%i",&escolha2);
                    switch (escolha2){
                        case 1:
                            listar_produtos_d(p);
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
                redefinir_preco(p);
                break;
            case 6:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
            }
    }while(escolha!=6);
}

// FIM DO PROGRAMA