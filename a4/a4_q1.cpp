    //Evan and Edward
    #include <iomanip> //format table
    #include <iostream> 
    using namespace std;
    #include <vector> // needed for arrays and pushback
    #include <algorithm> // needed for the find function

    const char SEPERATOR = ' '; //This is just to make the table look nice
    const int Width1 = 5;

    void invokegame(bool xgoesFirst, int xScore, int oScore, int numTies);
    //purpose: starts the game, it will initialize the board and determine who goes first and stuff 

    //inputs: boolean value if xgoes first

    //outputs: none

    void playgame(vector<string> &gameboard, bool& xgoesFirst, int xScore, int oScore, int numTies);
    //purpose: plays the game out until all tiles are played or someone wins

    //inputs: board, size of board, and boolean value of who goes first

    //outputs: none

    void turnX(vector<string> &gameboard, vector<int> &xTiles);
    //purpose: fn runs when its player X's turn, it will ask for input for where they want to put their X, it will check if theres already an X or O
    // there and will also check if the placed X caused a 

    //inputs: passes the board by refernce

    //outputs: none

    void turnO(vector<string> &gameboard, vector<int> &oTiles);
    //purpose: fn runs when its player O's turn, it will ask for input for where they want to put their X, it will check if theres already an X or O
    // there and will also check if the placed X caused a 

    //inputs: passes the board by refernce and the player O's tiles

    //outputs: none

    void printBoard(vector<string> gameboard);
    //purpose: prints the board (happens after each move and after game is over)

    //inputs: newly edited game board

    //outputs: none

    void checkOutcome(vector<string> gameboard, vector<int> currentplayerTiles, bool& playerWon);
    //purpose: after each turn checks outcome to see if player has won

    //input: board, the current player's tiles, and the boolean if the particular player won

    //outupt: none   


    int restartGame(bool xgoesFirst, int xScore, int oScore, int numTies);
    //purpose: after game is completed, it will output score and ask users if they want to play again, if so boolean of xgoingfirst is swapped so O will go first next time
    // or vice versa if O went first the previous round

    //input: boolean of x going first and xscore, oscore, numTies

    //output: none


    int main() {
        bool xgoesFirst = true;
        int xScore = 0;
        int oScore = 0;
        int numTies = 0;
        invokegame(xgoesFirst, xScore, oScore, numTies); 
        
    }

    void invokegame(bool xgoesFirst, int xScore, int oScore, int numTies) {
        vector<string> gameboard = 
        {
            "1", "2","3", "4",
            "5", "6", "7", "8",
            "9", "10", "11", "12",
            "13", "14", "15", "16"
        };
        playgame(gameboard, xgoesFirst, xScore, oScore, numTies);
    }

    void printBoard(vector<string> gameboard) {
        cout << "Board: " << endl; 
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[0]; // just for that nice sweet fomatting 
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[1];
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[2];
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[3];
        cout << endl;

        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[4];
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[5];
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[6];
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[7];
        cout << endl;

        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[8];
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[9];
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[10];
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[11];
        cout << endl;

        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[12];
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[13];
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[14];
        cout << left << setw(Width1) << setfill(SEPERATOR) << gameboard[15];
        cout << endl;
        }


    void playgame(vector<string> &gameboard, bool& xgoesFirst, int xScore, int oScore, int numTies){
        bool xWon = false;
        bool oWon = false;
        bool tie = false;
        const int MAX_ROUNDS = 8; //16 tiles, each player takes 2 per round, 8 rounds in total 
        vector<int> xTiles = {};
        vector<int> oTiles = {};
        //program needs to check after each turn if someone won or all tiles are chosen
        //man this will just be so inefficient 
        
        printBoard(gameboard);

        if (xgoesFirst) {
            for (int i = 0; i < MAX_ROUNDS; i++){             //after each turn, it will check the outcome to see if xtiles or otiles have a row or column or diagonal
                turnX(gameboard,xTiles);                     //It will check outcome with variables that are either x's tiles and xwon or o's tiles and owon
                printBoard(gameboard);
                checkOutcome(gameboard, xTiles, xWon);
                if (xWon) { 
                    xScore += 1;
                    cout << "X has won!";
                    break;
                }

                turnO(gameboard, oTiles);            
                printBoard(gameboard);
                checkOutcome(gameboard, oTiles, oWon);
                if (oWon) {
                    oScore += 1;
                    cout << "O has won!";

                    break;
                }

            }
            
        } else {
            for (int i = 0; i < MAX_ROUNDS; i++){
                turnO(gameboard, oTiles); 
                printBoard(gameboard);
                checkOutcome(gameboard, oTiles, oWon);
                if (oWon) {
                    oScore += 1;
                    cout << "O has won!";

                    break;
                }

                turnX(gameboard,xTiles);                  
                printBoard(gameboard);
                checkOutcome(gameboard, xTiles, xWon);
                if (xWon) {
                    xScore += 1;
                    cout << "X has won!";
                    break;
                }
            }
        }

        if (!(xWon || oWon)){ // if neither x or o won then its tie
            cout << "Tie Game";
            numTies += 1;
            restartGame(xgoesFirst, xScore, oScore, numTies);

        } else {
            restartGame(xgoesFirst, xScore, oScore, numTies);
        }

    }

    void turnX(vector<string> &gameboard, vector<int> &xTiles){
        int tileChosen = 0;
        bool keepGoing = true;
        while (keepGoing){
            cout << "Player X, please enter the num of tile you want to play" << endl;
            cin >> tileChosen;
            if (!cin.fail()){
                if 
                (( tileChosen >= 1  && tileChosen <= 16) && (gameboard[tileChosen - 1] != "X" && gameboard[tileChosen - 1] != "O")) { //checks if tilechosen is between 1 and 16, and the tile chosen doesnt have an X or O
                
                xTiles.push_back(tileChosen);
                gameboard[tileChosen - 1] = "X";

                //add tile to player list with push back or smthn 
                break;  
                }

            } else {
                cout << tileChosen;
                cout << "Not a valid tile" << endl;
                
            }
        } 
    }

    void turnO(vector<string> &gameboard, vector<int> &oTiles){
        int tileChosen = 0;
        bool keepGoing = true;
        while (keepGoing){
            cout << "Player O, please enter the num of tile you want to play" << endl;
            cin >> tileChosen;
            if (!cin.fail()){
                if (( tileChosen >= 1  && tileChosen <= 16) && (gameboard[tileChosen - 1] != "X" && gameboard[tileChosen - 1] != "O")) { //checks if tilechosen is between 1 and 16, and the tile chosen doesnt have an X or O
                
                gameboard[tileChosen - 1] = "O";
                oTiles.push_back(tileChosen);

                //add tile to player list with push back or smthn 
                break;  
                } else {
                cout << tileChosen;
                cout << "Not a valid tile" << endl;
                
                }
         } 
        }
    }
    void checkOutcome(vector<string> gameboard, vector<int> currentplayerTiles, bool& playerWon ) {
        const int NUMARRAYS = 12;
        const int NUMARRAYELEMENTS = 4;
        const int WINTILES[NUMARRAYS][NUMARRAYELEMENTS] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}, //Ok i relaize now i couldve done different things to confirm if there was a 4 in a row but w/e
                                    {1,5,9,13},{2,6,10,14},{3,7,11,15},{4,8,12,16},
                                    {1,6,11,16},{4,8,12,16}};

        for (int i = 0; i < NUMARRAYS; i++) {   //accessing 2d arrays, will check if all 4 elements of each sub array are in playerTiles, if so, they won
            int numMatches = 0; //When an element is found to be in the array, it will increase nummatches by +=1, when its 4, it will make playerwon = true, after the 4, the nummatches is reset to 0
            for (int j = 0; j < NUMARRAYELEMENTS; j++) { 
                if (find(currentplayerTiles.begin(), currentplayerTiles.end(), WINTILES[i][j]) != currentplayerTiles.end()) { //find fn searches through vector for the j value
                    numMatches += 1;
                }

            }
            if (numMatches == 4){
                playerWon = true;
                break;
            }
        }
            
    }

    int restartGame(bool xgoesFirst, int xScore, int oScore, int numTies) {

    //[setup]
    int inputplayAgain = 0; 

    //step1. After restarting the game, other player goes first instead
    xgoesFirst = !xgoesFirst;

    //step2. Output score
    cout << "Score (X:O)" << endl;
    cout << xScore << " : " << oScore << endl;

    //step3. Return user input to assess whether game is restarted 
    cout << "Play Again? enter 0 for no and 1 for yes";

    cin >> inputplayAgain; //get user input

    if (inputplayAgain == 1) {
        invokegame(xgoesFirst, xScore, oScore, numTies); //restart game
    }
    else {

        return(0); //exit program
    }

} // error here does not impede the running of the game

/*
TEST 1
Board: 
1    2    3    4
5    6    7    8
9    10   11   12
13   14   15   16
Player X, please enter the num of tile you want to play
1
Board: 
X    2    3    4
5    6    7    8
9    10   11   12
13   14   15   16   
Player O, please enter the num of tile you want to play
2
Board: 
X    O    3    4
5    6    7    8
9    10   11   12
13   14   15   16
Player X, please enter the num of tile you want to play
10
Board: 
X    O    3    4
5    6    7    8
9    X    11   12   
13   14   15   16
Player O, please enter the num of tile you want to play
14
Board: 
X    O    3    4
5    6    7    8
9    X    11   12
13   O    15   16   
Player X, please enter the num of tile you want to play
6
Board: 
X    O    3    4
5    X    7    8
9    X    11   12
13   O    15   16
Player O, please enter the num of tile you want to play
5
Board: 
X    O    3    4
O    X    7    8
9    X    11   12
13   O    15   16   
Player X, please enter the num of tile you want to play
9
Board: 
X    O    3    4
O    X    7    8
X    X    11   12   
13   O    15   16
Player O, please enter the num of tile you want to play
13
Board: 
X    O    3    4
O    X    7    8
X    X    11   12
O    O    15   16
Player X, please enter the num of tile you want to play
11
Board: 
X    O    3    4
O    X    7    8
X    X    X    12   
O    O    15   16
Player O, please enter the num of tile you want to play
15
Board: 
X    O    3    4
O    X    7    8
X    X    X    12
O    O    O    16
Player X, please enter the num of tile you want to play
12
Board:
X    O    3    4
O    X    7    8
X    X    X    X
O    O    O    16
X has won!Score (X:O)
1 : 0
Play Again? enter 0 for no and 1 for yes0

Also tested when all tiles were covered and it ended saying "tie"*/