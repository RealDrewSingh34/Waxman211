#include<iostream>
using namespace std;

bool ok(int q[], int col) { // Finish this code
	static int mp[3][3] = { { 0,2,1 },  	 // Man#0's preferences
							{ 0,2,1 },		// Man#1's preferences
							{ 1,2,0 } };	// Man#2's preferences
						
	static int wp[3][3] = { { 2,1,0 },		// Woman#0's preferences
							{ 0,1,2 },		// Woman#1's preferences
							{ 2,0,1 } };	 // Woman#2's preferences

	/*Similar to 1D Queens, use a loop to check the array.
	  Inside the loop we chould check for 3 conditions
	  First condition checks is the same women is married to two different man *hint we need to check if two things are equal*
	  Second condition checks if (Man#i) and (Man#c's wife) both like each other more than their own spouse
	  Third condition checks if (Man#c) and (Man#i's wife) both like each other more than their own spouse

	  mp[i][j] tells you how much Man#i likes Woman#j. (0 = favorite; 2 = least favorite) 
	  wp[i][j] tells you how much Woman#i likes Man#j.

	  mp[i][q[i]] tells you how much Man#i likes his own wife. 
	  mp[i][q[c]] tells you how much Man#i likes Man#c's wife. 
	  wp[q[i]][i] tells you how much Man#i's wife likes Man#i. 
	  wp[q[i]][c] tells you how much Man#i's wife likes Man#c. 
	  If mp[i][q[c]] < mp[i][q[i]], it means that Man#i likes Man#c's wife more than his own wife
	*/
	//
	for(int i= 0;i<col;i++){
		//Checks if woman i has already been assigned to a man.
		if(q[col] == q[i]){
			return false;
		}

		// This will check if man i likes woman c more than man i likes woman i
		if(mp[i][q[col]] < mp[i][q[i]] && wp[q[col]][i]< wp[q[col]][col]){
			return false; 
		}

		// 
		if(wp[q[i]][col] < wp[q[i]][i] && mp[col][q[i]] < mp[col][q[col]]){
			return false;
		}
	}
	return true;


	//if we pass the loop, what do we return?
}



void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	//Finish this print function
	for(int i=0;i<3;i++){
		cout<<i<<"\t" << q[i] << endl;
	} 
	cout << "\n";
}

//this will move on the next man and woman respectively
/*
void next(int q[], int c){
	if (c == 3){
		print(q);
	}
	else{
		for(q[c] = 0; q[c]<3; ++q[c]){
			if(ok(q,c)) next(q,c+1);
		}
	}
}
*/


int main() {
	//Write the main function.
	//The main function is exactly the same as 1D Queens. EXCEPT the array size is different.
	int q[3]={};// Initialize the array to represent men-to-women assignment
	int col = 0;    // Start with the first man (column 0)
	

	while (col >= 0) {  // Outer loop to handle backtracking
		while (q[col] < 3) {  // Inner loop to try each woman for the current man
			if (ok(q, col)) {  // Check if the current assignment is valid
				if (col == 2) {  // If all men are assigned successfully, print the solution
					print(q);
					break;
				} else {  // Move to the next man
					col++;
					q[col] = -1;  // Initialize the next column to try from the first woman
				}
			}
			q[col]++;
		}
		col--;  // Backtrack if necessary
		q[col]++;
	}
	return 0;
}
