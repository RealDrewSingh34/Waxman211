#include<iostream>
#include<cmath>
using namespace std;

// Test function checks placement constraints for the current box c
bool test(int q[], int c) {
    static int checkList[8][5] = {
        {-1},            // Box 0 has no neighbors in this simplified list
        {0, -1},         // Box 1 is adjacent to Box 0
        {1, -1},         // Box 2 is adjacent to Box 1
        {0, 1, 2, -1},   // Box 3 is adjacent to Boxes 0, 1, and 2
        {1, 2, 3, -1},   // Box 4 is adjacent to Boxes 1, 2, and 3
        {2, 4, -1},      // Box 5 is adjacent to Boxes 2 and 4
        {0, 3, 4, -1},   // Box 6 is adjacent to Boxes 0, 3, and 4
        {3, 4, 5, 6, -1} // Box 7 is adjacent to Boxes 3, 4, 5, and 6
    };

    // Check for duplicate values in previous boxes
    for(int i = 0; i < c; i++) {
        if(q[c] == q[i]) // Ensure the number in box c is unique
            return false;
    }

    // Check adjacent constraints using checkList
    for(int i = 0; checkList[c][i] != -1; i++) {
        if(q[checkList[c][i]] + 1 == q[c] || q[checkList[c][i]] - 1 == q[c])
            return false;
    }

    return true;
}

void print(int cross[]) {
  // everytime this function is called, count will not reset to 0 since it is static
  // static means the variable is allocated only once during the runtime of the program
	static int count = 1;
	cout << " Solution number: " << count++ << endl;
	cout << " " << cross[1] << cross[2] << endl;
	cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
	cout << " " << cross[6] << cross[7] << endl;

	cout << endl;
	count++;
}

void next(int q[], int c) {
   if (c == 8)
      print(q);
   else for (q[c] = 1; q[c] < 9; ++q[c])
      if (test(q, c))
         next(q, c+1);
}

int main() {
	int q[8] = {};   // Initialize the array to 0
   	next(q, 0);
	return 0;
}