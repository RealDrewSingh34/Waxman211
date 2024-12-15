#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

// Returns the area under the curve between x=a and x=b.
// The function passed as the first parameter determines the shape of the curve.
// Use a Riemann sum to estimate the area by dividing it into narrow rectangles (each rectangle should have a width of .0001)
// and adding up the areas of the individual rectangles.
// For a rectangle at horizontal position x, the height will be f(x).
// (when you call f(x) it'll call whatever function you passed as the first parameter)
double integrate(FUNC f, double a, double b) {
   // Fill in.
   double sum = 0;  // accumulation of Area will stored in this particular variable
   double delta = 0.0001; // With of each rectangle in the Riemanns sums = delta

   
   for(double x = a; x<b ; x+=delta){   // index range from a to b, with it incrementing based on the Width
      // Basically b-a/0.0001 rectangles will be used to approximate the definite integration 
      sum += f(x)* delta;   // Everytime the function, f(x) is multiplied by width, it will add area and equal area
   }
   // will return the exact Riemanns sum via (function*delta) + area = area, not Simpsons rule
   return sum;

}

double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
   return 0;
}
