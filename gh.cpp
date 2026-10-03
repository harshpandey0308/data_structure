#include<iostream>
#include<string>

using namespace std;

void reverse_string(string& arr , int left , int right){
    if(left >= right){
        return;
    }

    reverse_string(arr , left+1 , right-1);
    char temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

long long fibonacci(int num){
    if(num <= 1){
       //cout<<num<<'\n';
       return num;   
    }
    
    return fibonacci(num-1) + fibonacci(num-2);
}

int main(){
    string arr = "HARSHA";

    reverse_string(arr , 0 , arr.length()-1);

    for(char s : arr){
        cout<<s<<'\n';
    }

    long long result = fibonacci(5);

    cout<<"result"<<" "<<result<<'\n';

    return 0;
}