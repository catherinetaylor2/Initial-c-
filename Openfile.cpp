#include <stdio.h>
#include <math.h>
#include<iostream>
#include<fstream>

using namespace std;

int main(){
ofstream myfile;
  myfile.open ("example.txt");
  myfile << "help.\n";
  myfile.close();
    return 0;
}