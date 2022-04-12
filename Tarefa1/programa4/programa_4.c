#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int base=0, teto=100, tent=1, sort;
    char x;

    srand(time(NULL));

    sort=rand()%101;

    for(;;){
        printf("\nO numero que voce escolheu é, %d?\n", sort);
        scanf(" %c", &x);

        if(x=='s'){
            printf("\nO numero de tentativas necessarias foi => %d", tent);
            return 0;
        }else{
            tent++;

            printf("\nO numero é maior que %d?\n", sort);
            scanf(" %c", &x);

            if(x=='s'){
                sort++;
                base=sort;
            }else{
                sort--;
                teto=sort;
            }

            sort=(base+teto)/2;
        }
    }
}
