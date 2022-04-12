#include <stdio.h>

int main()
{
    int x, i;

    printf("\nDigite o numero:\n");
    scanf("%d", &x);

    for(i=2;i<x || x==0 || x==1;i++){
        if(x%i==0||x==1){
            printf("\nO numero %d, nao é primo\n", x);
            return 0;
        }
    }

    printf("\nO numero %d é primo\n", x);

    return 0;
}
