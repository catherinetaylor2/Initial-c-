// Key Comp Sci questions.

#include <iostream>

int most_frequent(int* input_array, int array_length){ // finds most frequent interger in array
    int index = 0;
    int current_value = 0;
    int number_of_appearances;

    for(int j=0; j<array_length; j++){
        current_value = input_array[j];
        number_of_appearances = 0;
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
void fibbonaci(int number_of_elements){ //prints first n elements of fibonacci sequence
    int past = 0;
    int current = 1;
    int temp;

    for(int i=0; i<number_of_elements; i++){
        std::cout<<current<<" ";
        temp = past + current;
        past = current;
        current = temp;
    }
    std::cout<<"\n";    
}
int find_single_element(int*input_array, int array_length){ // finds elements which appears only once in array
    int current_value;
    int number_of_appearances;

    for(int i=0; i<array_length;i++){
        current_value = input_array[i];
        number_of_appearances=0;
        for(int j=0; j<array_length; j++){
            if(current_value == input_array[j]){
                number_of_appearances +=1;
            }
        }
        if(number_of_appearances==1){
            return current_value;
        }
    }
    std::cout<<"no element appears once \n";
    return -1;
}
int find_common_element(int*array1, int*array2, int array_length){ // find common element between two arrays.
    for(int i=0; i<array_length; i++){
        int current_value = array1[i];
        for(int j=0; j<array_length; j++){
            if(current_value == array2[j]){
                return current_value;
            }
        }
    }
    std::cout<<"no common elements \n";
    return -1;
}
int multiply(int a, int b){
    int result =0;
    for(int i=0; i<b; i++){
        result+=a;
    }
    return result;
}

int main(){

    int array[] = {1,2,3,2,4,2,1,2,3};
    int i = most_frequent(array, 9);
    std::cout<<"Most frequent: "<<i<<"\n";

    std::cout<<"Fibonacci: ";
    fibbonaci(10);

    i = find_single_element(array,9);
    std::cout<<"single element: "<<i<<"\n";

    int array2[]={10, 3, 10, 5, 6,7,7,8,9};
    i = find_common_element(array, array2, 9);
    std::cout<<"common element "<<i<<"\n";

    i = multiply(12,2);
    std::cout<<"mult 12 and 2 without *: "<<i<<"\n";

    return 0;
}