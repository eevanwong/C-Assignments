#include <iostream>

using namespace std;

/*1) Initialize n, a, and d variables */
/*2) ask user to input the numbers 
3)Calls function that has the sum equation
return or print the output */

//Wait whats the point of the d?
/*First output was 125250 , followed by 2038168, then 511983139*/
/*I tested various other ranges such as 1 to 10, 2 to 50*/

/*The number will only work if the output (sum) is less than 2,147,483,647*/
/*the number of integers to be added cannot be negative, the first number can*/
void calculatesum(int n, int a, int d) {
	int sum = (n / 2)*(2*a + (n - 1)*d);
	cout << sum;

}

int main() {
	int n = 0, a = 0, d = 1;
	cout << "Enter num integers to be added" << endl;
	cin >> n;
	cout << "Enter first num" << endl;
	cin >> a;
	/*cout << "Enter difference between each number" << endl;
	cin >> d;*/

	calculatesum(n, a, d);

}