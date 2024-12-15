// Alford Carbon
#include <iostream>
using namespace std;



/**
 * printOdometer
 * outputs the elements in the array of size 6 that is passed to the function.
 * @param int array1[] - the array you will print out the values of.
 */
 void printOdometer(int array1[])
{
    cout << "Mileage: ";
   for(int i = 0; i < 6;  i++)
    {  
    cout << array1[i] << " ";
    }
   
}

int main()
{
    int win[6] = {}; // Declare an array referenced by win that can hold 6 elements all instantiated with the value 0
   
   
   
   
   
   
   
    // all loops will assign the increment variable to a unique array index
    for(int i0 = 0; i0 < 10; i0++)     // hundredthousands place for loop
    {
        win[0] = i0;
       
        for(int i1 = 0; i1 < 10; i1++  ) // tenthousands place for loop
    {
        win[1] = i1;
       
        for(int i2 = 0; i2 < 10; i2++ ) //thousands place for loop
    {
         win[2] = i2;
         
         for(int i3 = 0; i3 < 10; i3++ ) //hundreds place for loop
    {
        win[3] = i3;
       
       
        for(int i4 = 0; i4 < 10; i4++ ) //tens place for loop
    {
        win[4] = i4;
       
        for(int i5 = 0; i5 < 10; i5++ ) //ones place for loop which is the last step before looping back to loop1
    {
        win[5] = i5;
        printOdometer(win); //print function to show values of the array every time any
        cout << "\n";
       
       
           
    } //for loop  1 end
   
       
       
    } //for loop 2 end
   
   
   
    } //for loop 3 end
       
       
       
       
    }  //for loop 4 end
       
       
       
       
       
       
       
       
       
       
       
    }  // for loop 5 end
         
         
         
         
         
         
         
    } // for loop 6 end
       
       
       
       
       
       
       
       
       
       
   
       
       
       
       
       
       
       
       
       
       return 0;
       
       
    }

   
   
   