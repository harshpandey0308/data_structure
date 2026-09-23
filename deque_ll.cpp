#include<iostream>

#define MAX_SIZE 3

using namespace std;

class SLIDING_WINDOW{
    private:
       int arr[MAX_SIZE];
       size_t n; // size of the window
       size_t front; // k is an index which always store front element.
       size_t back;

    public : 
       SLIDING_WINDOW(): arr{0} , n(0) , front(0) , back(MAX_SIZE-1){}  

       void push(int num[] , int index){
            if(n >= MAX_SIZE){
                cout<<"window is overflow";
                return;
            }

            if(n == 0){
                arr[front] = index;
                n++;
                return;
            }

            while(num[arr[back]] <= num[index]){
                arr[back] = index;
                if(back < MAX_SIZE-1){
                    n--;
                }
                back--;
            }

            else{
                back = (back + 1)%MAX_SIZE;  // optimizing space by implementing deque rotarion
                arr[j] = index;
                n++;
            }
       }

       int pop_MAX(int num[]){
           if(n == 0){
             exit(-1);
           }
           int data = num[arr[front]];
           front = (front+1)%MAX_SIZE;
           n--;
           return data;
       }
            
       

       void print(){
        for(size_t i=front ; i<back ; i = (i+1)%MAX_SIZE){
            cout<<"the max element is : "<<arr[i]<<'\n';
        }
       }

       ~SLIDING_WINDOW(){
        cout<<"the siliding window is closed";
       }
};

int main(){

    int num[] = {3 , 4 , 1 , 2 , -1};

    SLIDING_WINDOW s1;

    s1.push(num , 0);

    s1.push(num , 1);

    s1.push(num , 2);

    s1.print();

    int max = s1.pop_MAX(num);

    cout<<"the maximum in the sliding window is "<<max<<'\n';


    

}