#include <stdio.h>
#include <string.h>

int main()
{
    char alfa[50], beta[50];
    int i, j;

    printf("\nInforme a frase:\n");
    scanf("%[^\n]s", &alfa);

    i=strlen(alfa);

    for(j=0;i>=0;j++){
        i--;
        beta[j]=alfa[i];
    }

    printf("\n%s\n", beta);

    return 0;
}
