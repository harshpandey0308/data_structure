#include<iostream>

#define MAX_SIZE 5

using namespace std;

class SLIDING_WINDOW{
    private:
       int arr[MAX_SIZE];
       size_t n;
       size_t k;

    public : 
       SLIDING_WINDOW(): arr[0]{0} , n(0) , k(0){}  

       void push(int num[] , int index){
            int j = static_cast<int>k;
            if(j >= MAX_SIZE - 1){
                cout<<"window is overflow";
                return;
            }

            if(num[k] <= num[index]){
                arr[k] = index;
            }
            else{
                j++;
                arr[j] = index;
            }
       }
            
       

       void print(){
        for(size_t i=0 ; i<n ; i++){
            cout<<"the max element is : "<<arr[(k+i)%MAX_SIZE]<<'\n';
        }
       }

       ~SLIDING_WINDOW(){
        cout<<"the siliding window is closed";
       }
};

int main(){

    int num[] = {3 , 4 , 1 , 2 , -1};

    SLIDING_WINDOW s1;

    s1.push_MAX(num , 0);

    s1.push_MAX(1);

    s1.push_MAX(2);

    int max = s1.pop_MAX();

    cout<<"the maximum in the sliding window is "<<max<<'\n';


    s1.print();

}