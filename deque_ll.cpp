#include<iostream>

#define MAX_SIZE 3

using namespace std;

class SLIDING_WINDOW{
    private:
       int arr[MAX_SIZE];
       size_t size; // size of the window
       size_t front; // k is an index which always store front element.
       size_t back;

    public : 
       SLIDING_WINDOW(): arr{0} , size(0) , front(0) , back(0){}  

       void push(int num[] , int index){
            if(size == MAX_SIZE){
                return;
            }

            if(size == 0){
                arr[back] = index;
                size++;
                return;
            }

            while(size != 0 && num[arr[back]] <= num[index]){
                pop();
            }

            if(size == 0){
                back = 0;
                front = 0;
            }
            else{
                back = (back + 1)%MAX_SIZE;
            }

            arr[back] = index;
            size++;
        }

        void pop(){
            if(size == 0){
               cout<<"the slide is empty"<<'\n';
               return;
            }
            
            if(size == 1){
                back = 0;
                front = 0;
                size = 0;
                return;
            }
            else{
                back = (back + MAX_SIZE - 1)%MAX_SIZE;
                size-- ;
                return;
            }

       }

       int get_max(int num[]){
        return num[arr[front]];
       }

       void print(){
        size_t i = front;
        for(size_t count=0 ; count<size ; count++){
            cout<<"the element is : "<<arr[i]<<'\n';
            i = (i+1)%MAX_SIZE;
        }

       }

       ~SLIDING_WINDOW(){
        cout<<"the siliding window is closed";
       }
};

int main(){

    int num[] = {6 , 4 , 3 , 7 , 2 , 1};

    SLIDING_WINDOW s1;

    s1.push(num , 1);

    s1.push(num , 2);

    s1.push(num , 3);

    s1.print();

    int max = s1.get_max(num);

    cout<<"the maximum in the sliding window is "<<max<<'\n';

    return 0;
}