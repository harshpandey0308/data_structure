#include<stdio.h>
#include<stdint.h>

int main(){
    #ifdef  __STDC_VERSION__
        printf("C standard version: %ld\n",__STDC_VERSION__);
    #else
        printf("Pre standard c c(c89/c90)\n");
    #endif
        return 0;
}