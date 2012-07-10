#include <stdio.h>
 
int main(void){
    int num,i,n;
    do{
        printf("Ingresa un numero del 1 al 9: ");
        scanf("%d", &num);
    }while (num<1 || num>9);
    for (n=0; n<num; n++){
        for (i=9; i>n; i--){       
            printf(" ");
        }
        for (i=1; i<n; i++){
            printf("%d",i);
        }
        for (i=n; i>0; i--){
            printf("%d", i);
        }
        printf("\n");
    }
    for (n=num; n>0; n--){
        for (i=9; i>n; i--){       
            printf(" ");
        }
        for (i=1; i<n; i++){
            printf("%d",i);
        }
        for (i=n; i>0; i--){
            printf("%d", i);
        }
        printf("\n");
    }
    printf("\n");
    return 0;  
}
