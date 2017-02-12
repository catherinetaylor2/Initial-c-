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
    root_node->val = list[0];
    for (int i=1; i<length; i++){ 
        bst_t *h = new bst_t; 
        root_node->right = h;           
        h ->val = list[i];
        root_node->left = nullptr;
        root_node = h;
    }
    //delete root_node->right;
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
    int list_centre;
    list_centre = floor((length+1)/2); 
    bst_t *current=root_node;
    //bst_t*h=root_node;
    for (int i=1; i<list_centre;i++){
        root_node=root_node->right;
    }
  bst_t*root=root_node;
  bst_t*h=current;
   for(int i=1; i < list_centre-1;i++){
      h=h->right;
  }
  root_node->left=h;
  root_node=h;
  for(int i = list_centre -1;i>0;i--){
      h = current;
      for(int j = 1; j<i;j++){
          h=h->right;
      }
      root_node->left=h;
      root_node->right=nullptr;
      root_node=h;
  }
  root_node->left=nullptr;
  root_node->right=nullptr;
  root_node=root;

  h=current;
  std::cout<<"h val "<<current->right->val<<"\n";
    std::cout<<"root node "<<root_node->val<<"\n";
  std::cout<<"root node "<<root_node->left->val<<"\n";
  std::cout<<"root node "<<root_node->left->left->val<<"\n";
for(int i=1; i<list_centre+1;i++){
    h=h->right;
}


}
// void balance_bst(bst_t *root_node, int length){
//     std::cout<<"what is rootnode val "<<root_node->right->val<<"\n";
//     int list_centre;
//     list_centre = floor((length+1)/2);
//     std::cout<<"list centre "<<list_centre <<"\n";
//     bst_t *root= root_node;
//     bst_t*h=root_node;
//     std::cout<<"h right"<<h->right->val<<"\n";
// std::cout<<"what is rootnode val "<<root_node->right<<"\n";

//     for (int i=1; i<list_centre; i++){
//         root=root->right;
//     }
//     std::cout<<"root val "<<root->val<<"\n";
//     bst_t *current = new bst_t;
//     current=root
//     ;

//     for(int j = 1; j<list_centre-1;j++){
//             h=h->right;
//             std::cout<<"what is h? "<<h->val<<"\n";
//         }
//     current->left = h;
//     current=h;
//     std::cout<<"what is rootnode val "<<root_node->right<<"\n";

//     for(int i=list_centre-2; i>0;i--){
//         bst_t *hh=h;
//         for(int j = 1; j<i;j++){
//             hh=hh->right;
//         }
//     current->left = hh;
//     current->right = nullptr;
//     current=hh;
//     }
//     current->left=nullptr;
//     current->right=nullptr;
//     current = root;


//     bst_t*g=root_node;
//     std::cout<<"g right"<<g->right->right->val<<"\n";

// for(int j = 1; j<list_centre+1; j++){
//             g=g->right;
//             std::cout<<"what is g val "<<g->val<<"\n";

//         }
//        current->right = g;
//        current=g;
// std::cout<<"g val "<<g->val<<"\n";
    
//     for(int i=0;i>(length - list_centre); i++){
//         bst_t*g=root_node;
//         for(int j = 0; j<(i+list_centre+1); j++){
//             g=g->right;
//         }
//        current->right = g;
//        current->left=nullptr;
//        current=g;

//     }
//    current->right=nullptr;
//    current->left=nullptr;
//      current = root;
//      std::cout<<"Root node "<<root->val<<"\n";
//      std::cout<<"Root left "<<current->left->val<<"\n";
//      std::cout<<"Root left left "<<current->left->left->val<<"\n";
//      std::cout<<"Root right "<<root->right->val<<"\n";

// }

int main(int argc, char* argv[]){

    bst_t * root = new bst_t;
    int arrayList[] = {1,2,3,4,5};
    if(assert_sorted_list(arrayList,__ARRAYLEN(arrayList))<0){
        return -1;
    }

    fill_bst(arrayList,__ARRAYLEN(arrayList),root); 
    std::cout<<"List Created using fill_bst: \n";
    //print_bst(root);
   std::cout<<"balanced stuff \n";
    balance_bst(root,__ARRAYLEN(arrayList));
 std::cout<<"Balanced tree: \n";
//print_bst(root);
    // Manually create a BSP tree
    bst_t *root1 = new bst_t;
    bst_t *root2 = new bst_t;
    bst_t *root3 = new bst_t;
    bst_t *root4 = new bst_t;
    bst_t *root5 = new bst_t;
    bst_t *root6 = new bst_t;
    bst_t *root7 = new bst_t;
    bst_t *root8 = new bst_t;
    bst_t *root9 = new bst_t;
    bst_t *root10 = new bst_t;
    root5->val =5;
    root5->left=root3;
    root3->val=3;
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

    std::cout<<"List Created Manually: \n";
    print_bst(root5);
    return 1;
}