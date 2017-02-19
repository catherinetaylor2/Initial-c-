#ifndef ray_trace_hpp
#define ray_trace_hpp
#include<iostream>

#define RED 0
#define GREEN 1
#define BLUE 2


class sphere{
    public:
        sphere(int sphere_x, int sphere_y, int sphere_z, int sphere_radius, int sphere_colour);
        int get_x_coord(void);
        int get_y_coord(void);
        int get_z_coord(void);
        int get_radius(void);
    private:
        int centre_x;
        int centre_y;
        int centre_z;
        int radius;
        int colour_x;
        int colour_y;
        int colour_z;
};



class vector3{
    public:
        vector3();
        vector3(float x, float y, float z);
        float get_x(void);
        float get_y(void);
        float get_z(void);
        void normalize(void);
        void setValue(int x, int y, int z);
    private:    
      float x_val;
      float y_val;
      float z_val;
};
class scene{
    public:
    scene(int x, int y, int w);
    int get_x_res(void);
    int get_y_res(void);
    int get_width(void);
    int get_height(void);
    private:
        int x_res;
        int y_res;
        int width;
        int height;
};
class Colour{
    public:
    private:
};
#endif