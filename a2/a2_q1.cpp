// SYDE 121 a2.cpp : This file contains the 'main' function. Program execution begins and ends there.
using namespace std;
#include <iostream>


//Cannot enter a string, or any number above 2147483647 and less than 0
//Note: Unable to really check 100000+ as there would be too many prime numbers for me to check
/*Used 31, 100, and 205 (cant really check high ints) all of which outputted correct results
Made sure the palindrome and sumofdigits checking worked by lowering the condition to it being less than 40

Limitations for int is 2147483647 and bool can only be true/false*/
void inputvalue(int& max) {
	//checks if input is greater than 0
	while (max <= 0) {
		cout << "Enter max number" << endl;
		cin >> max;

	}

}


void findpalindromeandsum(int num) {
	int reversenum = 0;
	int val = num;
	int sumofdigit = 0;
	while (num > 0) {
		reversenum = reversenum * 10 + num % 10; //In order t know something is a palindrome you need to recreate the number in reverse orer, the original number is copied and stored for comparison, then the actual number is broken down by dividing by 10 so that reversenum can be built (last digit of num will be first digit of reversenum and so on).
		sumofdigit += num % 10; //calcluating the sum of digits by adding each digit starting from the right side
		num = num / 10;	   //might as well have sum of digits and palindrome in same function b/c they both utilize the same code to mate-anip individual digits
	}

	if (reversenum == val && val < 10000) {
		cout << "(palindrome) "; //will mark the prime if its a palindrome

	}
	if (sumofdigit % 2 != 0) {
		cout << " (odd sum of digits) ";
	}

}

void findprime(int num, bool& isprime) {
	isprime = true;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			isprime = false;
			break;
		}

	}

	if (isprime == true) {
		cout << num << " "; //Outputs the prime and then checks if its a palindrome or when sums of digits are odd when num < 100000
		if (num < 100000) {
			findpalindromeandsum(num);

		}

	}
}

void a2q1function()
{
	//declare and initialize variables
	int maxnum = 0;
	int oddsum = 0;
	bool isprime = true;
	//[INPUT] step1. user enters the max number
	inputvalue(maxnum);

	//[PROCESSING] step2. program computes the primes and palindromes before the number
	for (int num = 1; num <= maxnum; ++num) {
		//[OUTPUT] step3. I put the output in the prime function, it continuously outputs prime numbers and palindromes so that we dont have to hold the info
		findprime(num, isprime);

	}


}


int main()
{
	a2q1function();
}
/*Output for 100
1 (palindrome)  (odd sum of digits) 2 (palindrome) 3 (palindrome)  (odd sum of digits) 5 (palindrome)  (odd sum of digits) 7 (palindrome)  (odd sum of digits) 11 (palindrome) 13 17 19 23  (odd sum of digits) 29  (odd sum of digits) 31 37 41  (odd sum of digits)
43  (odd sum of digits) 47  (odd sum of digits) 53 59 61  (odd sum of digits) 67  (odd sum of digits) 71 73 79 83  (odd sum of digits) 89  (odd sum of digits) 97
*/