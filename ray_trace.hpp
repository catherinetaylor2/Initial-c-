#ifndef ray_trace_hpp
#define ray_trace_hpp
#include<iostream>


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
class sphere{
    public:
        sphere(int sphere_x, int sphere_y, int sphere_z, int sphere_radius, const int* sphere_colour);
        int get_x_coord(void);
        int get_y_coord(void);
        int get_z_coord(void);
        int get_radius(void);
        int get_centre_x(void);
        int get_centre_y(void);
        int get_centre_z(void);
        vector3 get_colour(void);
        vector3 find_normal(vector3 point);
    private:
        int centre_x;
        int centre_y;
        int centre_z;
        int radius;
        int colour_x;
        int colour_y;
        int colour_z;
};
class scene{
    public:
    scene(int x, int y, int fov, int d);
    int get_x_res(void);
    int get_y_res(void);
    float get_width(void);
    float get_height(void);
    private:
        int x_res;
        int y_res;
        float width;
        float height;
};
#endif