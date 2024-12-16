#include <stdio.h>

int pangkat(int x, int y){
    if(y==0){
        return 1;
    }else{
        return x * pangkat(x, y-1);
    }

void main(){
    int x;
    int y;

    printf("bilangan x pangkat y: ");
    scanf("%d %d", &x, &y);
    printf("%d pangkat %d = %d", x, y, pangkat(x,y));

}
