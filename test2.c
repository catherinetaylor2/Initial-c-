#include <stdio.h>
#include <stdlib.h>
//skdl;kekflk;lfklk;
typedef struct LinkedList{
    int value;
    struct LinkedList *nextNode;
}

LinkedList_t;   

void printList(LinkedList_t * list){
    LinkedList_t * current = list;
   

 while(current!=NULL){
      
  printf("Node Value is %d\n",current->value);
   
     current = current->nextNode;
    }
}

int addItemToEnd(LinkedList_t * list,  int new){
    LinkedList_t * h = malloc(sizeof(LinkedList_t));
    LinkedList_t * current = list;
    while (current->nextNode !=NULL){
        current = current->nextNode;
    }
    current->nextNode = h;
    current->nextNode->value=new;
    current->nextNode->nextNode=NULL;

    return 0;
    }


int addItemToBeginning(LinkedList_t ** list,  int new){
  LinkedList_t * h = malloc(sizeof(LinkedList_t));
  
  h-> value = new;
  h->nextNode = *list;
  *list=h;
return 0;


}


int popFirstItem(LinkedList_t ** list){
    LinkedList_t *h = *list;

    h = h->nextNode;

    *list=h;
    return 0;

}


int popLastItem(LinkedList_t*list){
    LinkedList_t * current = list;
        while (current->nextNode->nextNode !=NULL){
                current = current->nextNode;
        }
    printf("Last item was %d\n",current->nextNode->value);
    current->nextNode = NULL;
    return 0;
}


void reverseLinkedList(LinkedList_t **list){
     LinkedList_t * previous = NULL;
    LinkedList_t * current = *list;
    LinkedList_t * next;
    while(current!=NULL){
        next = current->nextNode;
        current->nextNode = previous;
        previous = current;
        current = next;
    }
    (*list) = previous;
}


int main(){
    LinkedList_t * p = malloc(sizeof(LinkedList_t));
    p->value = 1;
    p->nextNode=NULL;



    printf("Original List \n");
    printList(p);
    printf("Add Item to End \n");
    addItemToEnd( p, 5);
    printList(p);
    printf("Add Item to beginning \n");
    addItemToBeginning(&p,  2);
    printList(p);
    printf("Pop last item \n");
    popLastItem(p);
    printList(p);
    printf("Pop first item \n");
    popFirstItem(&p);
    printList(p);
    printf("Reverse List \n");
    reverseLinkedList(&p);
    printList(p);
    
    return 0;
}

