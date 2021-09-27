//Created  by Juode

#include <stdio.h>

int main(){
    int i = 0, sum = 0, n = 0,avg = 0;
    FILE *fp;
    fp = fopen("test.txt", "r");
    while(fscanf(fp, "%d", &n) != EOF){
        sum += n;
        i++;
    }
    avg = (sum / i);
    printf("The average is %d.\n", avg);
    fclose(fp);
    return 0;
}
