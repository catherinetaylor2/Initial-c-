#include <fstream>
#include <iostream>

int main(){
        int width = 100, height = 100;
        unsigned char* img = new unsigned char [3*width*height];
        for (int i=0; i<3*width*height; i+=3){
            img[i]=255;
        }
    	std::ofstream my_image;
		my_image.open("test.ppm", std::ios::out| std::ios::binary);
		my_image<<"P6 \n" 
		<<width<<" "
		<<height<<"\n"
		<<255<<"\n";
		for (int i=0; i<3*width*height; i++){
		    my_image << img[i]; 
		}
		my_image.close();
        delete img;
}