#include<iostream>
#include<string>

using namespace std;

int sum(int n);

void reverse_string(string name ){
    if(name == '\n'){
        return;
    }

    reverse_string(name[i]);

    cout<<"the reversed string is "<<name<<'\n';
}

int main(){
    int result = sum(5);

    cout<<"the sum of first five number : "<<result<<'\n';

    reverse_string("harsh");

    return 0;
}

int sum(int n){
    if(n <= 0){
        return 0;
    }

    int s = n;

    return (s + sum(n-1));
}