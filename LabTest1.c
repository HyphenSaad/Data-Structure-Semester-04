/*
   Author:  Abdullah Muzaffar
   Lab Test Number: 01
   Section: Prg155nddL
*/

#include <stdio.h>
#include <conio.h>

int main() {
   float length = 0.0f, width = 0.0f;

   printf("Enter Floor Length: ");
   scanf("%f", &length);
   printf("Enter Floor Width: ");
   scanf("%f", &width);

   float area = length * width, cost = 0.0f;

   if (area >= 0.0f && area <= 20.0f) cost = 100 + area * 20.5;
   else if (area > 20.0f && area <= 40.0f) cost = 150 + area * 22.1;
   else if (area > 40.0f) cost = 200 + area * 25.0;

   printf("Area = %.2f sqm and the cost of tiling = $%.2f\n", area, cost);

   getch();
   return 0;
}