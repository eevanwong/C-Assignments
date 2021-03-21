// SYDE 121 Assignment 1 Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//start off by dividing by 125, then we need to check whether or not 
//there's a value large enough for 1 of the next smaller weight type
//if not, it will move onto the next one

//Steps: 125 to 75 to 42 to 15 to 1 
//Include in the comments the output for step 1

//OUTPUT FROM STEP 1 (125lb - 16, 75lb - 0, 42lb - 1, 15lb - 0, 1lb - 6)



int weights75(int r)
{
    if (r >= 75) {
        r /= 75;
        return(r);
    }
    else {
        return(0);
    }
}
/*Remaining weight from the deduction of the previous weight type (which is 125 or the custom weight) is
checked to see if it is greater or less than 75
If it is greater, it will return the remaining of the total weight divided by 75, else
it will return 0*/

int weights42(int r)
{
    if (r >= 42) {
        r /= 42;
        return(r);
    }
    else {
        return(0);
    }

}
/*Remaining weight from the deduction of the previous weight type is
checked to see if it is greater or less than 42
If it is greater, it will return the remaining of the total weight divided by 42, else
it will return 0*/

int weights15(int r)
{
    if (r >= 15) {
        r /= 15;
        return(r);
    }
    else {
        return(0);
    }
}

/*Remaining weight from the deduction of the previous weight type is
checked to see if it is greater or less than 15
If it is greater, it will return the remaining of the total weight divided by 15, else
it will return 0*/

/*Values will only work if they are greater than 0 and less than the total weight*/
/*custom weight also cannot be greater than 2147483647*/
int main()
{   
    int firstweight;
    std::cout << "enter a custom weight\n";
    std::cin  >> firstweight;

    int totalweight = 2048;
    int customweight = totalweight / firstweight;  /*Assuming first weight class is still 125 weight, the total weight is divided by 125lb, which is 16*/
    int remainingweight = totalweight % firstweight; /*To determine remaining weight, used modulus operator (found value of customweight then multiplied by 125, and subtracted that total from the total weight)*/

    int num_75 = weights75(remainingweight); /*remaining weight is determined through modulus operator, this is the same for the rest of the weight classes*/
    remainingweight %= 75;

    int num_42 = weights42(remainingweight);
    remainingweight %=  42;

    int num_15 = weights15(remainingweight);
    remainingweight %= 15;

    int num_1 = remainingweight; /*once it passes all of the remaining weight categories, the remaining weight will be in 1 lb weights.*/
    
    std::cout << customweight << " " << num_75 << " " << num_42 << " " << num_15 << " " << num_1;

}    
    

/*Future Notes:
I was worried that my logic would be off as I had run into multiple issues in the past because I thought of C++ as python and that screwed me
Jason told me that I could put all of these into a void function; however, I would need to return multiple values and I thought that void functions
couldnt do that (ill reesearch that later)*/





