#include <stdio.h>
#include <math.h>
#include<iostream>

#define __ARRAYLEN(x) (sizeof(x)/sizeof(x[0]))
//only works for STATIC arrays, not DYNAMIC arrays.
//What's the difference?

typedef struct bst_node{
    int val;
    struct bst_node *left;
    struct bst_node *right;
}bst_t;

int assert_sorted_list(int list[], int length){
    if(length == 1){
        return 1;
    }
    for(int i = 0; i<length-1;i++){
        if(list[i]>list[i+1]){
            return -1;
        }
    }
    return 1;
}

void fill_bst(int list[], int length, bst_t *root_node){
    bst_t *current = root_node;
    current->val = list[0];
    for (int i=1; i<length; i++){ 
        bst_t *h = new bst_t; 
        root_node->right = h;           
            h ->val = list[i];
            root_node->left = nullptr;
            root_node = h;
    }
    delete root_node->right;
    root_node->right = nullptr;
    root_node->left=nullptr;
    root_node=current;
}
void print_bst(bst_t *node){
    bst_t *current = node;
    if(current->left!=nullptr){
        print_bst(current->left);
    }
    std::cout<<"Node Value is "<< current->val<<"\n";
    if(current->right != nullptr){
        print_bst(current->right) ;
    }
}



void balance_bst(bst_t *root_node, int length){
}

int main(int argc, char* argv[]){

    bst_t * root = new bst_t;
    int arrayList[] = {1,2,3,5,6,7,9};
    if(assert_sorted_list(arrayList,__ARRAYLEN(arrayList))<0){
        return -1;
    }

 fill_bst(arrayList,__ARRAYLEN(arrayList),root); 

    std::cout<<"left"<<root->left<<"\n";
    std::cout<<"right"<<root->right<<"\n";

   
    //balance_bst(root,__ARRAYLEN(arrayList));
    // print_bst(root);

     // Manually create a BSP tree
    bst_t *root1 = new bst_t;
  // std::cout<<"root 1 location "<<&root1<<"\n";

    bst_t *root2 = new bst_t;
    bst_t *root3 = new bst_t;
    bst_t *root4 = new bst_t;
    bst_t *root5 = new bst_t;
    bst_t *root6 = new bst_t;
    bst_t *root7 = new bst_t;
    bst_t *root8 = new bst_t;
    bst_t *root9 = new bst_t;
    bst_t *root10 = new bst_t;

// std::cout<<"root 1 location "<<root1<<"\n";
    root5->val =5;


    root5->left=root3;
    root3->val=3;
    std::cout<<"root5 value "<<root5->val<<"\n";
    root3->left = root2;
    root2->val = 2;
    root2->left = root1;
    root1->val=1;
    root1->left=nullptr;
    root1->right=nullptr;
    root2->right=nullptr;
    root3->right=root4;
    root4->val=4;
    root4->left=nullptr;
    root4->right=nullptr;
    root5->right=root7;
    root7->val =7;
    root7->left=root6;
    root6->val=6;
    root6->left=nullptr;
    root6->right=nullptr;
    root7->right=root9;
    root9->val=9;
    root9->right=root10;
    root9->left=root8;
    root8->left=nullptr;
    root8->right=nullptr;
    root8->val=8;
    root10->left=nullptr;
    root10->right=nullptr;
    root10->val=10;

print_bst(root);
    return 1;
}