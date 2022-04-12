#include <stdio.h>
#include <math.h>

#define PI 3.14159265

typedef struct {
    float real, imag;
}retangular;

typedef struct {
    float mod, ang;
}polar;

polar transf_RP(retangular ret)
{
    polar polar1;

    polar1.mod=sqrtf(powf(ret.real,2)+powf(ret.imag,2));

    if(ret.real==0){
        if(ret.imag>0){
            polar1.ang=90;
        }else
        if(ret.imag==0){
            polar1.ang=0;
        }else
            polar1.ang=-90;
    }else
        polar1.ang=atan(ret.imag/ret.real)*180/PI;

    if(ret.real<0){
        if(ret.imag<0){
            polar1.ang=-(180-polar1.ang);
            polar1.mod=polar1.mod;
        }else{
            polar1.ang=(180+polar1.ang);
        }
    }

    return polar1;
}

retangular transf_PR(polar pol)
{
    retangular ret1;

    ret1.real=pol.mod*cos(pol.ang*PI/180);

    if(pol.ang==180||pol.ang==90){
        ret1.imag=pol.mod*sin(pol.ang*3.1415/180); /*Nao uso a definicao de PI aqui, porque o arredondamento feito pelo
                                                    *sistema, nao sai de forma tao precisa, quando se trata desses angulos*/
    }else{
        ret1.imag=pol.mod*sin(pol.ang*PI/180);
    }

    return ret1;
}

retangular somar_equac(retangular x, retangular y)
{
    retangular soma;

    soma.real=x.real+y.real;
    soma.imag=x.imag+y.imag;

    return soma;
}

polar dividir_equac(polar x, polar y)
{
    polar divisao;

    divisao.mod=x.mod/y.mod;
    divisao.ang=x.ang-y.ang;

    return divisao;
}

polar multiplicar_equac(polar x, polar y)
{
    polar resultado;

    resultado.mod=x.mod*y.mod;
    resultado.ang=x.ang+y.ang;

    return resultado;
}

polar delta(retangular a, retangular b, retangular c, retangular d)
{
    polar pol[4], diag_prin, diag_sec, result;
    retangular ret[3];

    //Transformacao dos parametros da funcao, para polar.
    pol[1]=transf_RP(a);
    pol[2]=transf_RP(b);
    pol[3]=transf_RP(c);
    pol[4]=transf_RP(d);

    //Print da matriz na forma polar
    printf("\n=================================================================================================\n");
    printf("\n|%.2f L%.2f°    %.2f L%.2f°|\n|%.2f L%.2f°    %.2f L%.2f°|\n", pol[1].mod, pol[1].ang, pol[2].mod, pol[2].ang, pol[3].mod, pol[3].ang, pol[4].mod, pol[4].ang);

    diag_prin=multiplicar_equac(pol[1],pol[4]);

    diag_sec=multiplicar_equac(pol[2],pol[3]);
    diag_sec.mod=-(diag_sec.mod);

    ret[1]=transf_PR(diag_prin);
    ret[2]=transf_PR(diag_sec);

    ret[3]=somar_equac(ret[1], ret[2]);

    result=transf_RP(ret[3]);

    /*So para printar a equacao na forma retangular, da maneira convencional*/
    if(ret[3].imag>=0){
        printf("\nO valor do Δ, e %.2f+j%.2f ou %.2f L%.2f°", ret[3].real, ret[3].imag, result.mod, result.ang);
    }else{
        ret[3].imag=ret[3].imag-2*ret[3].imag;
        printf("\nO valor do Δ, e %.2f-j%.2f ou %.2f L%.2f°", ret[3].real, ret[3].imag, result.mod, result.ang);
    }

    printf("\n=================================================================================================\n");

    return result;
}

int main()
{
    int i=0;
    retangular ret[6];
    polar pol[5];

    while(i!=4){
        printf("\n1 para converter ret-pol\n2 para converter pol-ret\n3 para calcular as matrizes\n=>");
        scanf("%d", &i);

        switch(i)  {
            case 1:
                printf("\nInsira o numero na forma retangular.\n");
                scanf("%f", &ret[1].real);
                printf("j");
                scanf("%f", &ret[1].imag);

                pol[1]=transf_RP(ret[1]);

                printf("\n%.2f L%.2f°\n", pol[1].mod, pol[1].ang);
                break;

            case 2:
                printf("\nInsira o numero na forma polar.\n");
                scanf("%f", &pol[1].mod);
                printf("L");
                scanf("%f", &pol[1].ang);

                ret[1]=transf_PR(pol[1]);

                /*So para printar a equacao na forma retangular, da maneira convencional*/
                if(ret[1].imag>=0){
                    printf("\n%.2f+j%.2f\n", ret[1].real, ret[1].imag);
                }else{
                    ret[1].imag=ret[1].imag-2*ret[1].imag;
                    printf("\n%.2f-j%.2f\n", ret[1].real, ret[1].imag);
                }
                break;

            case 3:
                printf("\nInsira a primeira equacao na forma retangular.\n");
                scanf("%f", &ret[1].real);
                printf("j");
                scanf("%f", &ret[1].imag);
                printf("\n+\n");
                scanf("%f", &ret[2].real);
                printf("j");
                scanf("%f", &ret[2].imag);
                printf("\n=\n");
                scanf("%f", &ret[3].real);
                printf("j");
                scanf("%f", &ret[3].imag);

                printf("\nInsira a segunda equacao na forma retangular.\n");
                scanf("%f", &ret[4].real);
                printf("j");
                scanf("%f", &ret[4].imag);
                printf("\n+\n");
                scanf("%f", &ret[5].real);
                printf("j");
                scanf("%f", &ret[5].imag);
                printf("\n=\n");
                scanf("%f", &ret[6].real);
                printf("j");
                scanf("%f", &ret[6].imag);

                //Matriz delta
                pol[1]=delta(ret[1],ret[2],ret[4],ret[5]);

                //Matriz delta1
                pol[2]=delta(ret[3],ret[2],ret[6],ret[5]);

                //Matriz delta2
                pol[3]=delta(ret[1],ret[3],ret[4],ret[6]);

                //Valor de I1 ou V1
                pol[4]=dividir_equac(pol[2],pol[1]);

                //Valor de I2 ou V2
                pol[5]=dividir_equac(pol[3],pol[1]);

                printf("\ni1=%.2f L%.2f°\ni2=%.2f L%.2f°\n\n", pol[4].mod, pol[4].ang, pol[5].mod, pol[5].ang);
                break;

            case 4:
                return 0;

            default:
                printf("\nOpcao invalida.");
                break;
        }
    }
}