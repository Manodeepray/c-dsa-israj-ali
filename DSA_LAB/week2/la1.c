#include <stdio.h>

struct Distance 
{
   int Kilometer;
   float Meter;
}


int main()
{
   struct Distance dist[2];
   struct Distance result[1];
   
   printf("Enter 1st distance\n");
   printf("Enter Kilometer: ");
   scanf("%d", &dist[0].Kilometer);
   printf("Enter Meter: ");
   scanf("%f", &dist[0].Meter);
 
   
   printf("\nEnter 2nd distance\n");
   printf("Enter Kilometer: ");
   scanf("%d", &dist[1].Kilometer);
   printf("Enter Meter: ");
   scanf("%f", &dist[1].Meter);
   
   
   result[0].Kilometer = dist[0].Kilometer + dist[1].Kilometer;
   result[0].Meter = dist[0].Meter + dist[1].Meter;

   
    while (result[0].Meter >= 1000) {
      result[0].Meter = result[0].Meter - 1000;
      ++result[0].Kilometer;
   }
   printf("\nSum of distances = %d.%.1f ", result[0].Kilometer, result[0].Meter);
   
   return 0;
}