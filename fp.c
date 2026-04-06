#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*void print(char *c){
    c[0] = 'A';
    while(*c != '\0'){
        
        printf("%c",*c);
        c++;
    }
    printf("\n");
}*/

/*int main(){
    char B[3][3];
    printf("\n The elements of the 2-d array.\n");
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            scanf(" %c",&B[i][j]);
        }
        printf("\n");
    }
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            printf("%c",B[i][j]);
        }
        printf("\n");
    }
    char (*p)[3] = B;

    printf("Address is %d \n element in B is %d\n , element stored in address %d is %c", B+1,*(B+1),*(B+1),**(B+1));
    printf("\nThe second element at address %d is %d and element stored in %d is %c",B+1,(*(B+1)+1),(*(B+1)+1),*(*(B+1)+1));
    return 0;
}*/

/*int main(){
    int n;
    printf("enter the no. of elements in the list:\n");
    scanf("%d",&n);

    int *A = (int*)malloc(n*sizeof(int));
    
    for(int i=0 ; i<n ; i++){
        A[i] = i+1;
    }

    int *B = (int*)realloc(A,2*n*sizeof(int));

    printf("\naddress of previous array is %d and address of new array is %d",A,B);
    printf("\nthe elements of the list are:\n");
    for(int i=0 ; i<2*n ; i++){
        printf("%d",B[i]);
        printf("\n");
    }
    return 0;
}*/

/*int add(int a , int b){
    return a+b;
}

void hello(char *name){
    printf("hello %s\n",name);
}

int main(){
    int c;
    int (*p)(int,int);
    p = &add;
    c = (*p)(2,5);
    printf("the sum is %d",c);

    void (*ptr)(char*);
    ptr = hello;
    ptr("harsh");

    return 0;
}*/

void add(int *a , int *b){
    printf("\nThe sum of %d and %d is %d",*a,*b,(*a)+(*b));
}

void multiply(int *a , int *b){
    printf("\nThe product of %d and %d is %d",*a,*b,(*a)*(*b));
}

void sub(int *a , int *b){
    printf("\nThe difference of %d and %d is %d",*a,*b,(*a)-(*b));
}

void divi(int *a , int *b){
    int c;
    if(*b == 0){
        printf("ERROR.");
        exit(EXIT_FAILURE);
    }
    c = (*a)/(*b);
    printf("\nThe division of %d by %d is %d.",(*a),(*b),c);
}

int main(){
    int a = 5;
    int b = 6;

    char opr;
    printf("choose the operation:\n '+' for addition.\n'*' for multiplication.\n'-' for subtraction.\n'/' for division.\n");
    scanf(" %c",&opr);

    
    void (*Operation)(int*,int*);
    
    switch (opr)
    {
    case '+':
        Operation = add;
        break;
    
    case '-':
        Operation = sub;
        break;

    case '*':
        Operation = multiply;
        break;

    case '/':
        Operation = divi;
        break;

    default:
        printf("INVALID OPERATION!!");
        return 0 ;
    }

    Operation(&a , &b);

    return 0;
}
    

