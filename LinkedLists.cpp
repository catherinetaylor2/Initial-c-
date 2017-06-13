//Linked Lists

#include <iostream>;

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
int main(){
    int array[]= {1,2,3,4};
    List* mylist = new List;
    fill_list(array, mylist, 4);
    add_element_start(5, &mylist);
    add_element_end(6, mylist);
    reverse_list(&mylist);
    std::cout<<"linked list "<<mylist->next->value<<"\n";


    return 0;
}