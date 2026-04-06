#include<stdio.h>
#include<time.h>

int main(){
    time_t current = time(NULL);

    time_t present ;
    time(&present);

    printf("the current time is %s",ctime(&current));
    printf("the present time is %s",ctime(&present));

    return 0;
}