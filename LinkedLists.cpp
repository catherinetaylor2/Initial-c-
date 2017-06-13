//Linked Lists

#include <iostream>

typedef struct LinkedList{
    int value;
    struct LinkedList* next;
}List;

void fill_list(int* array, List* list, int array_length){
    List* current = list;
    for(int i=0; i<array_length-1; i++){
        list->value = array[i];
        List* h = new List;
        list->next = h;
        list = list->next;
    }
    list->value = array[array_length -1];
    list->next = nullptr;
    list = current;
}

void add_element_end(int myvalue, List* list){
    List* h = new List;
    List*current = list;
    h->value = myvalue;
    h->next = nullptr;
    while(list->next != nullptr){
        list = list->next;
    }
    list->next = h;
    list = current;
}
void add_element_start(int myvalue, List** list){
    List* h = new List;
    h->value = myvalue;
    h->next = *list;
    *list = h;
}
void reverse_list(List** list){
    List* prev = nullptr;
    List* next = nullptr;
    List* current = *list;
    while(current!=nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}
int partition(int* array, int low, int high){
    int pivot = array[high];
    int i = low -1;
    for(int j = low; j<high; j++){
        if ((array)[j]<=pivot){
            i+=1;
            if (i != j){
                int temp = (array)[i];
                (array)[i] = (array)[j];
                (array)[j]=temp;
            }
        } 
    }
    int temp = (array)[i+1];
    (array)[i+1] = pivot;
    (array)[high]=temp;
    return i+1;
}
void quick_sort_array(int* array, int low, int high){
    if(low<high){
       int p = partition(array, low, high);
        quick_sort_array(array, low, p-1);
        quick_sort_array(array, p+1, high);
    }
}
void print_array(int* array, int array_length){
    std::cout<<"array: ";
    for (int i=0; i<array_length;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<"\n";
}
void print_list(List*list){
    List*current = list;
    std::cout<<"list: ";
    while(list!=nullptr){
        std::cout<<list->value<<" ";
        list = list->next;
    }
    list = current;
    std::cout<<"\n";
}
int main(){
    int array[] = {7,2,5,4,1,2,3};

    quick_sort_array(array, 0, 6);
    print_array(array,7);

    List* mylist = new List;

    fill_list(array, mylist, 7);
    print_list(mylist);
    add_element_start(5, &mylist);
    print_list(mylist);
    add_element_end(6, mylist);
    print_list(mylist);
    reverse_list(&mylist);
    print_list(mylist);

    return 0;
}