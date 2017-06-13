//Generating prime numbers

#include <iostream>
#include <cmath>

void prime_numbers(int n){//finds prime numbers up to n
    int* array = new int[n];
    for(int i = 0; i<n; i++){
        array[i]= i;
    }

    for(int j = 2; j<((int)sqrt(n)); j++){
        int current_prime = j;
        if(current_prime!=0){
            for(int i=current_prime+1; i < n; i++){
                if(array[i]%current_prime==0){
                    array[i] = 0;
                }
            }
        }
    }
    for(int i =2 ; i<n; i++){
        if(array[i]!=0){
            std::cout<<array[i]<<" ";
        }
    }
    std::cout<<"\n ";
    delete array;
}

int main(){
    prime_numbers(20);
    return 0;
}