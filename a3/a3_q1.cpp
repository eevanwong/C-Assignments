#include <iostream>
using namespace std;
//Functions:

//in the mainline, I need to determine num of events
//it will input into a game function which has a for loop, this
//program will contain multiple functions with different events (score will be passed by reference)

void rungame(int numevents);
//Purpose: fn will run a for loop, in which for num events, for each event it will generate random number that will run a corresponding event
//it will keep track of scores of both teams by passed by refernce

//Input: numevents 

//output: none 

void teamAshot(int& score);
//Purpose: situation - team A attempts to shoot on the goal, will determine if it is a goal and score +=1

//inputs: pass score by reference

//outputs: none

void teamBshot(int& score);
//Purpose: situation - team B attempts to shoot on the goal

//inputs: pass score by reference

//outputs: none

void teamAfreekick(int& score);
//Purpose: situation - team B attempts to shoot on the goal

//inputs: pass score by reference

//outputs: none

void teamBfreekick(int& score);
//Purpose: situation - team B attempts to shoot on the goal

//inputs: pass score by reference

//outputs: none

void teamApenaltykick(int& score);
//Purpose: situation - team B attempts to shoot on the goal

//inputs: pass score by reference

//outputs: none

void teamBpenaltykick(int& score);
//Purpose: situation - team B attempts to shoot on the goal

//inputs: pass score by reference

//outputs: none

int main() {
    int numevents = rand() % 20 + 1;
    rungame(numevents);

}

void rungame(int numevents) {
    int scoreA = 0;
    int scoreB = 0;
    for (int i = 0; i <= numevents; i++) {
        int event = rand() % 6 + 1;
        cout << event;
        switch(event) {
            case 1:
                teamAshot(scoreA);
            case 2:
                teamBshot(scoreB);
            case 3:
                teamAfreekick(scoreA);
            case 4:
                teamBfreekick(scoreB);
            case 5:
                teamApenaltykick(scoreA);
            case 6:
                teamBpenaltykick(scoreB);
        } 

    }
}

void teamAshot(int& scoreA) {

}