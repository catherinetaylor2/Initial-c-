#include <cstdlib>
#include <exception>
#include <iostream>
#include<fstream>
#include"ray_trace.hpp"

using namespace std;

typedef struct pixel{
    unsigned char r,g,b;
    pixel();
    pixel(unsigned char r,unsigned char g, unsigned char b);
}Pixel;

class Image{
    public:
   Image(unsigned char width, unsigned char height);
   int getHeight(void);
   int  getWidth(void);
    private:
        unsigned char width;
        unsigned char height;
        Pixel *data;
};

int Image::getHeight(void){
    return height;
}
int Image::getWidth(void){
    return width;
}

Image::Image(unsigned char width1, unsigned char height1){
    width = width1;
    height = height1;
}

int main(){
    Image img(10,10);
 
    
    ofstream my_image;
    my_image.open("test.ppm", ios::out| ios::binary);
    my_image<<"P6\n"
    <<img.getWidth()<<" "
    <<img.getHeight()<< "n"
   <<255<<"\n";

    my_image.close();



    return 0;
}