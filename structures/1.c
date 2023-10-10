#include <stdio.h>

struct point
{   
    int x , y ,z;

    /* data */
};
 int main()

 {
    

    struct point p1 =
    {
        /* data */
        .y=0,.z=1,.x=2
    };
    printf("%d %d %d",p1.x,p1.y,p1.z);
 }