#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void espaco (void){
    printf("\n\n");
    printf("-------------------------------------------------------------------- \n");
    printf("\n\n");
}

int fator (int op3, int op2){
    if (op3 == 1){
        printf("Calcular por: (1) Montante (2) Juros \n");
        scanf("%d", &op2);

        if ((op2 != 1) && (op2!= 2)){
            printf("\n");
            printf("Entrada invalida. \n\n");
            system("pause");
            return 0;
        }

    printf("\n\n");

        }else{
            op2 = 1;
        }
    return (op2);
}

float montante (float M){
    printf("Digite o montante: \n");
    scanf("%f", &M);
    printf("\n");
    return (M);
}

float juros (float J){
    printf("Digite os juros: \n");
    scanf("%f", &J);
    printf("\n");
    return (J);
}

float capital (float C){
    printf("Digite o capital inicial: \n");
    scanf("%f", &C);
    printf("\n");
    return (C);
}

float taxa (float i){
    printf("Digite a taxa de juros (em porcentagem): \n");
    scanf("%f", &i);
    i = i/100;
    printf("\n");
    return (i);
}

float prazo (float t){
    printf("Digite o prazo: \n");
    scanf("%f", &t);
    printf("\n");
    return (t);
}


int main(){

float M, J, C, i, t;
int op, op2, op3, enc;

printf("===== Calculadora de juros ====== \n\n");
printf("Aviso: a taxa de juros deve estar em funcao da mesma unidade de tempo que o o prazo. \n\n");

do {
    printf("Digite o que tu deseja calcular: \n");
    printf("1 - Juros simples \n");
    printf("2 - Juros compostos \n");
    scanf("%d", &op3);
    printf("\n");

    if ((op3 != 1) && (op3 != 2)){
        printf("Entrada invalida. \n\n");
        system("pause");
        return 0;
    }

    printf("Digite o que se deseja calcular: \n");
    printf("1 - Montante e/ou juros \n");
    printf("2 - Capital Inicial \n");
    printf("3 - Taxa de juros \n");
    printf("4 - Prazo \n");
    scanf("%d", &op);
    printf("\n");


    switch (op){
    case 1:
        C = capital(C);
        i = taxa(i);
        t = prazo(t);

        switch (op3){
        case 1:
            M = C*(1+i*t);
            J = C*i*t;
        break;

        case 2:
            M = C*pow((1+i), t);
            J = C*pow((1+i), t) - C;
        break;
        }

        espaco();
        printf("Os juros sao igual a: %f \n", J);
        printf("O montante eh igual a: %f \n", M);
    break;

    case 2:
    op2 = fator(op3, op2);

        switch (op2){
        case 1:
            M = montante(M);
            i = taxa(i);
            t = prazo(t);


            switch (op3){
            case 1:
                C = M / (1+i*t);
            break;

            case 2:
                C = M / pow((1+i), t);
            break;
            }

            espaco();
            printf("O capital inicial eh igual a: %f \n", C);
        break;

        case 2:
            J = juros(J);
            i = taxa(i);
            t = prazo(t);
            C = J / (i*t);

            espaco();
            printf("O capital inicial eh igual a: %f \n", C);
        break;
        }
    break;

    case 3:
        op2 = fator(op3, op2);

        switch (op2){
        case 1:
            M = montante(M);
            C = capital(C);
            t = prazo(t);

            switch (op3){
            case 1:
                i = ((M/C)-1) / t;
            break;

            case 2:
                i= pow((M/C), (1/t))-1;
            break;
            }

        espaco();
        printf("A taxa de juros eh igual a: %f \n", i);
        printf("Em porcentagem: %f \n", i*100);
        break;

        case 2:
            J = juros(J);
            C = capital(C);
            t = prazo(t);
            i = J / (C*t);

            espaco();
            printf("A taxa de juros eh igual a: %f \n", i);
            printf("Em porcentagem: %f \n", i*100);
        break;
        }
    break;

    case 4:
        op2 = fator(op3, op2);

        switch (op2){
        case 1:
            M = montante(M);
            C = capital(C);
            i = taxa(i);

            switch (op3){
            case 1:
                t = ((M/C)-1) / i;
            break;

            case 2:
                t = log(M/C)/log(1+i);
            break;
            }

            espaco();
            printf("O prazo eh igual a: %f \n", t);
        break;

        case 2:
            J = juros(J);
            i = taxa(i);
            C = capital(C);
            t = J / (i*C);

            espaco();
            printf("O prazo eh igual a: %f \n", t);
        break;
        }
    break;

    default:
        printf("Entrada invalida. \n\n");
        system("pause");
        return 0;
    break;
    }

    espaco();

    do{
            printf("Para continuar digite 1. \n");
            printf("Para encerrar digite 2. \n");
            scanf("%d", &enc);

            if ((enc != 1) && (enc != 2)){
                printf("\n");
                printf("Entrada invalida. \n\n");
            }


    }while ((enc != 1) && (enc != 2));

    if (enc == 1){
        printf("\n\nDeseja limpar a tela? \n");
        printf("1 - Sim \n");
        printf("2 - Nao \n");
        scanf("%d", &op3);

        if (op3 == 1){
             system("cls");
        }else if (op3 != 2){
            printf("\n");
            printf("Entrada invalida. \n\n");
            system("pause");
            return 0;
        }
    }

    if (op3 != 1)
        espaco();



}while (enc!=2);


system("pause");
return 0;
}
