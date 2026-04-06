#include<stdio.h>
#include<stdlib.h>

int* find_indices(int n , int a[n] , int aim){
    int result;
    static int indices[2];
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            result = a[i] + a[j];
            if(result == aim){
                indices[0] = i;
                indices[1] = j;
                return indices;
            }
        }
    }
    indices[0] = -1;
    indices[1] = -1;
    return indices;
}

int main(){
    int n;
    printf("enter the length of the string:\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of the strings:\n");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&a[i]);
    }
    int aim;
    printf("enter the aim:\n");
    scanf("%d",&aim);

    int *index = find_indices(n , a , aim);
    printf("the indices whose sum is %d are %d and %d:",aim ,index[0] , index[1]);
    
    return 0;
}