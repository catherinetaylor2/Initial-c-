// Key Comp Sci questions.

#include <iostream>

int most_frequent(int* input_array, int array_length){ // finds most frequent interger in array
    int index = 0;
    int current_value = 0;
    int number_of_appearances = 0;

    for(int j=0; j<array_length; j++){
        current_value = input_array[j];
        for(int i=j+1; i<array_length; i++){
            if(current_value ==input_array[i]){
                number_of_appearances += 1;
            }
        }
        if(number_of_appearances > current_value){
            current_value = number_of_appearances;
            index = j;
        }
    }
    return input_array[index];
}

int main(){

    int array[] = {1,2,3,2,4,2,1,2};
    int i = most_frequent(array, 8);
    std::cout<<"most frequent "<<i<<"\n";
    return 0;
}