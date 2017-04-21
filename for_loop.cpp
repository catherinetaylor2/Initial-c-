#include <iostream>
#include<string>


int main(){

    for(int i=0; i<101; i++){
        std::string j ;
        if(i<10){
            j = "000"+std::to_string(i);
        }
        else if((i<100)&&(i>=10)){
            j = "00"+std::to_string(i);
        }
        else{
            j = "0"+std::to_string(i);
        }
        std::cout<<j<<"\n";
    }

    return 0;
}