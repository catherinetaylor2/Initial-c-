#include <cstdlib>
#include <exception>
#include <iostream>
#include <cmath>
#include<fstream>
#include"ray_trace.hpp"

using namespace std;

sphere::sphere(int sphere_x, int sphere_y, int sphere_z, int sphere_radius, int sphere_colour){
    centre_x=sphere_x;
    centre_y=sphere_y;
    centre_z=sphere_z;
    radius=sphere_radius;
    if (sphere_colour ==RED){
        colour_x=255;
        colour_y=0;
        colour_z=0;
    }
}

vector3::vector3(float x, float y, float z){
    x_val=x;
    y_val=y;
    z_val=z;
}
float vector3::get_x(void){
    return x_val;
}
float vector3::get_y(void){
    return y_val;
}
float vector3::get_z(void){
    return z_val;
}
float dotproduct(vector3 vec1, vector3 vec2){
    return vec1.get_x()*vec2.get_x()+vec1.get_y()*vec2.get_y()+vec1.get_z()*vec2.get_z();
}
vector3 crossproduct(vector3 u, vector3 v){
    float i,j,k;
    i = u.get_y()*v.get_z() - u.get_z()*v.get_y();
     j = u.get_z()*v.get_x() - u.get_x()*v.get_z();
      k = u.get_x()*v.get_y() - u.get_y()*v.get_x();
    vector3 vec(i, j, k);
    return vec;
}
vector3 vec_add(vector3 v1, vector3 v2){
    float x,y,z;
    x = v1.get_x()+v2.get_x();
    y=v1.get_y()+v2.get_y();
    z=v1.get_z()+v2.get_z();
    vector3 vec(x,y,z);
    return vec;
}
vector3 vec_scal_mult(int c, vector3 v){
    float x,y,z;
    x = c*v.get_x();
    y=c*v.get_y();
    z=c*v.get_z();
    vector3 vec(x,y,z);
    return vec;
}
void vector3::normalize(void){
    float sum = sqrt(x_val*x_val + y_val*y_val + z_val*z_val);
    x_val /= sum;
    y_val /= sum;
    z_val /=sum;
}
void vector3::setValue(int x, int y, int z){
    x_val=x;
    y_val=y;
    z_val=z;
}
scene::scene(int x, int y, int w){
    x_res = x;
    y_res= y;
    width =w;
    height = x/y*w;
}

int scene::get_x_res(void){
    return x_res;
}
int scene::get_y_res(void){
    return y_res;
}
int scene::get_width(void){
    return width;
}
int scene::get_height(void){
    return height;
}

int main(){

// initial inputs
    sphere sphere1(0,0,0,1,RED);
    vector3 eye(0,0,-5);
    vector3 lookup(0,1,-5);
    vector3 lookat(0,0,1);
    vector3 light(4,10,-1);
    vector3 centre(0,0,0);
    float d = 3, I1=0.25, am = 0.5, n=24;
    double I2=0.00000002;
    scene myscene(1000,1000,5);
    
//set up eye coord system

vector3 w = vec_add(eye, vec_scal_mult(-1, lookat));
w.normalize();
  vector3 u = crossproduct(lookup, w);
  u.normalize();
  vector3 v = crossproduct(w,u);
  

 vector3 C = vec_add(eye,vec_scal_mult(-d,w));
 
  float Lx,Ly,Lz;
  
  Lx = C.get_x()+u.get_x()*myscene.get_width()/2+v.get_x()*myscene.get_height()/2;
  Ly = C.get_y()+u.get_y()*myscene.get_width()/2+v.get_y()*myscene.get_height()/2;
  Lz = C.get_z()+u.get_z()*myscene.get_width()/2+v.get_z()*myscene.get_height()/2;
 
   vector3 L(Lx,Ly,Lz);
  
unsigned char *img = new unsigned char[3*myscene.get_x_res()*myscene.get_y_res()];
unsigned char*img2 = new unsigned char[myscene.get_x_res()*myscene.get_y_res()];
cout<<myscene.get_x_res()<<"\n";

for (int x = 0; x<3*myscene.get_x_res()*myscene.get_y_res(); x+=3){
    int i, j;
    i=(x/(3))%(myscene.get_y_res())+1;
    j=(x/(3))/(myscene.get_y_res())+1;
    
    // cout<<"i "<<i<<"\n";
    // cout<<"j "<<j<<"\n";    
      float sx, sy,sz;
        sx = L.get_x() - u.get_x()*(myscene.get_width())/(myscene.get_x_res())*i - v.get_x()*(myscene.get_height())/(myscene.get_y_res())*j;
        sy = L.get_y() - u.get_y()*(myscene.get_width())/(myscene.get_x_res())*i - v.get_y()*(myscene.get_height())/(myscene.get_y_res())*j;
        sz = L.get_z() - u.get_z()*(myscene.get_width())/(myscene.get_x_res())*i - v.get_z()*(myscene.get_height())/(myscene.get_y_res())*j;
       // cout<<"sx "<<sx<<"\n";
 vector3 s(sx,sy,sz);
 vector3 d(s.get_x()-eye.get_x(),s.get_y()-eye.get_y(),s.get_z()-eye.get_z());
        d.normalize();

float a,b,c, det ;
 a = dotproduct(d,d);
 b=2*dotproduct(d,eye);
 c=dotproduct(eye,eye)-1;

det = b*b - 4*a*c;
if (det >= 0){
     
    int t, t1,t2;
    t1 = (-1*b -sqrt(det))/(2*a);
     t2 = (-1*b +sqrt(det))/(2*a);
     if(t1>t2){
         t=t2;
     }
     else{
         t=t1;
     }
    vector3 point = vec_add(eye, vec_scal_mult(t,d)); 
    vector3 norm = vec_add(point, vec_scal_mult(-1,centre));
    vector3 normal = vec_scal_mult(2,norm);
    vector3 l = vec_add(light, vec_scal_mult(-1, point));
    l.normalize();
 
   double D,DD;
    if (dotproduct(normal,l)>0){
        D = dotproduct(normal,l);
    }
    else{
        D=0;
    }
     vector3 H =vec_add(l, vec_scal_mult(-1,d));
         H.normalize();
         if (dotproduct(normal,H)<0){
             DD=0;
         }
         else{
             DD=dotproduct(normal,H);
             //cout<<"DD"<<DD<<"\n";
                  }
    img[x] = 255*I1*D+255*am+255*pow(DD,n)*I2;
    img[x+1]=255*pow(DD,n)*I2;
img[x+2]=255*pow(DD,n)*I2;
    
}
else{
    img[x]=0;
    img[x+1]=0;
img[x+2]=0;
 
}

    }



    ofstream my_image;
    my_image.open("test.ppm", ios::out| ios::binary);
    my_image<<"P6 \n" 
    <<myscene.get_x_res()<<" "
    <<myscene.get_y_res()<<"\n"
    <<255<<"\n";
for (int i=0; i<3*myscene.get_x_res()*myscene.get_y_res(); i++){
    my_image << img[i];
}
    my_image.close();



    return 0;
}