#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    int size;
    int ship;
    int shipnum;
    int headX;
    int headY;
    int tailX;
    int tailY;
    int playerX;
    int playerY;
    int respond = 2;
    int correction;
    int hit_player;
    int action;
    int missle;
    int missleX;
    int missleY;
    int gamestatus = 1;
    double hitcounter = 0;
    double misscounter = 0;
    double totalhitcounter = 0;
    double hitcounter2 = 0;
    double misscounter2 = 0;
    double totalhitcounter2 = 0;
    int spotstatus;
    int changeX;
    int changeY;

    // 0 (nothing) 1 (mybattleship) 5 (Missed) 8 (Hits)

    cout << "Please input the size of your Grid: ";
    cin >> size;

    int Grid[size][size];
    int Grid2[size][size];

    for (int column = 0;column < size;column++){
        for (int row = 0;row < size;row++){
            Grid[row][column] = 0;
        }
    }

    for (int column = 0;column < size;column++){
        for (int row = 0;row < size;row++){
            Grid2[row][column] = 0;
        }
    }

    /////summon your grid

    cout << "\nYour grid: \n\n" << setw(5) << "Y" << endl;

    for (int column = 0;column < size;column++){
        cout << setw(5) << size - column;

        for (int row = 0;row < size;row++){
            cout << setw(5) << Grid[row][column];
        }
        cout << endl;
    }

    for (int row = 0;row <= size;row++){
        cout << setw(5) << row;
    }
    cout << setw(5) << "X" << endl;

    /////grid summoned
    
    cout << "Input how many ship do you want: ";
    cin >> shipnum;

    for (int counter = 0;counter < shipnum;counter++){
        
        cout << "Input the size of your battleship(number " << counter + 1 << "): ";
        cin >> ship;
        cout << endl;
        cout << "Please input the head position of your battleship(two numbers x and y): ";
        cin >> headX >> headY;
        cout << "Please input the tail position of your battleship(two numbers x and y): ";
        cin >> tailX >> tailY;

        while (headX != tailX && headY != tailY){
            cout << "Your battleship doesn't exist! Please input again." << endl;
            cout << "Please input the head position of your battleship(two numbers x and y): ";
            cin >> headX >> headY;
            cout << "Please input the tail position of your battleship(two numbers x and y): ";
            cin >> tailX >> tailY;
        }
        int Xdistance = abs(headX - tailX) + 1;
        int Ydistance = abs(headY - tailY) + 1;

        while (Xdistance != ship && Ydistance != ship){
            cout << "Your battleship is longer/shorter than your input size! Please input again." << endl;
            cout << "Please input the head position of your battleship(two numbers x and y): ";
            cin >> headX >> headY;
            cout << "Please input the tail position of your battleship(two numbers x and y): ";
            cin >> tailX >> tailY;

            Xdistance = abs(headX - tailX) + 1;
            Ydistance = abs(headY - tailY) + 1;
        }
        
        Grid[headX - 1][size - headY] = 1;

    ///// only giving the head and tail to make up the whole ship :)
        

        if (headX - 1 > tailX - 1){ // y are all the same
            for (int counter = 0;counter < ship;counter++){
                Grid[tailX - 1 + counter][size - tailY] = 1;
        }
    }
        if (headX - 1 < tailX - 1){ // y are all the same
            for (int counter = 0;counter < ship;counter++){
                Grid[headX - 1 + counter][size - tailY] = 1;
        }
    }
        if (size - headY > size - tailY){ // x are all the same
            for (int counter = 0;counter < ship;counter++){
                Grid[headX - 1][size - tailY + counter] = 1;
        }
    }
        if (size - tailY > size - headY){ // x are all the same
            for (int counter = 0;counter < ship;counter++){
                Grid[headX - 1][size - headY + counter] = 1;
        }
    }
    }
    ///// only giving the head and tail to make up the whole ship :)

    cout << "\nThe position of your batteship: \n\n" << setw(5) << "Y" << endl;

    for (int column = 0;column < size;column++){
        cout << setw(5) << size - column;

        for (int row = 0;row < size;row++){
            cout << setw(5) << Grid[row][column];
        }
        cout << endl;
    }
    for (int row = 0;row <= size;row++){
        cout << setw(5) << row;
    }

    cout << setw(5) << "X" << endl;

    cout << "1. Start to battle" << endl;
    cout << "2. Abort (restart)" << endl;
    cout << "3. Print out the rules\n" << endl;
    cout << "Are you ready to battle? (input the corresponding number) ";
    cin >> respond;
    cout << endl;

    while (respond == 3){
        cout << "The object of the game is to attack your opponent's ship "<< endl;
        cout << "Step1: Players position their ships on the grid " << endl;
        cout << "Step2: Players decided who goes first " << endl;
        cout << "Step3: Players take turns calling out grid spaces looking to hit a ship " << endl;
        cout << "The game will over when all the spots of the ship have been hit\n" << endl;

        cout << "1. Start to battle" << endl;
        cout << "2. Abort (restart)" << endl;
        cout << "3. Print out the rules" << endl;
        cout << "Are you ready to battle? (input the corresponding number) ";
        cin >> respond;
    }

    /////restart start:(

    while (respond == 2){
        cout << "Please input the size of your Grid: ";
        cin >> size;

    int Grid[size][size];
    int Grid2[size][size];

    for (int column = 0;column < size;column++){
        for (int row = 0;row < size;row++){
            Grid[row][column] = 0;
        }
    }

    cout << "\nYour grid: \n\n" << setw(5) << "Y" << endl;

    for (int column = 0;column < size;column++){
        cout << setw(5) << size - column;

        for (int row = 0;row < size;row++){
            cout << setw(5) << Grid[row][column];
        }
        cout << endl;
    }

    for (int row = 0;row <= size;row++){
        cout << setw(5) << row;
    }
    cout << setw(5) << "X" << endl;

    cout << "Input how many ship do you want: ";
    cin >> shipnum;

    for (int counter = 0;counter < shipnum;counter++){
        
        cout << "Input the size of your battleship(number " << counter + 1 << "): ";
        cin >> ship;
        cout << endl;
        cout << "Please input the head position of your battleship(two numbers x and y): ";
        cin >> headX >> headY;
        cout << "Please input the tail position of your battleship(two numbers x and y): ";
        cin >> tailX >> tailY;

        while (headX != tailX && headY != tailY){
            cout << "Your battleship doesn't exist! Please input again." << endl;
            cout << "Please input the head position of your battleship(two numbers x and y): ";
            cin >> headX >> headY;
            cout << "Please input the tail position of your battleship(two numbers x and y): ";
            cin >> tailX >> tailY;
        }
        int Xdistance = abs(headX - tailX) + 1;
        int Ydistance = abs(headY - tailY) + 1;

        while (Xdistance != ship && Ydistance != ship){
            cout << "Your battleship is longer/shorter than your input size! Please input again." << endl;
            cout << "Please input the head position of your battleship(two numbers x and y): ";
            cin >> headX >> headY;
            cout << "Please input the tail position of your battleship(two numbers x and y): ";
            cin >> tailX >> tailY;

            Xdistance = abs(headX - tailX) + 1;
            Ydistance = abs(headY - tailY) + 1;
        }

        Grid[headX - 1][size - headY] = 1;

        if (headX - 1 > tailX - 1){ // y are all the same
            for (int counter = 0;counter < ship;counter++){
                Grid[tailX - 1 + counter][size - tailY] = 1;
            }
        }
        if (headX - 1 < tailX - 1){ // y are all the same
            for (int counter = 0;counter < ship;counter++){
                Grid[headX - 1 + counter][size - tailY] = 1;
            }
        }
        if (size - headY > size - tailY){ // x are all the same
            for (int counter = 0;counter < ship;counter++){
                Grid[headX - 1][size - tailY + counter] = 1;
            }
        }
        if (size - tailY > size - headY){ // x are all the same
            for (int counter = 0;counter < ship;counter++){
                Grid[headX - 1][size - headY + counter] = 1;
            }
        }
    }

    cout << "\nThe position of your batteship: \n\n" << setw(5) << "Y" << endl;

    for (int column = 0;column < size;column++){
        cout << setw(5) << size - column;

        for (int row = 0;row < size;row++){
            cout << setw(5) << Grid[row][column];
        }
        cout << endl;
    }
    for (int row = 0;row <= size;row++){
        cout << setw(5) << row;
    }
    cout << setw(5) << "X" << endl;
    cout << "1. Start to battle" << endl;
    cout << "2. Abort (restart)" << endl;
    cout << "3. Print out the rules" << endl;
    cout << "Are you ready to battle? (input the corresponding number) ";
    cin >> respond;
    }
    

    ///// restart end:(
        
    // gamestatus = 1 (keep going) gamestatus = 2 (game end)

    while (gamestatus == 1){ 
    cout << "\n" << endl;
    cout << "1. Input the position where the missle hits" << endl;
    cout << "2. Show me the location of the battleship" << endl;
    cout << "3. Input the position where you attack" << endl;
    cout << "4. Show me the location of the place where you attack" << endl;
    cout << "5. Make correction on you or your competitor's board\n" << endl;
    cout << "Choose your action(type -1 to exit): ";
    cin >> action;

    if (action == 1){
        
        cout << "\nPlease input the position to fire the missle (two numbers x and y): ";
        cin >> missleX >> missleY;

        if (Grid[missleX - 1][size - missleY] == 1){
            hitcounter++;
            cout << "Hits! Your competitor still have " << ship - hitcounter << " spots haven't found." << endl;
            Grid[missleX - 1][size - missleY] = 8;
            totalhitcounter++;
        }
        else if (Grid[missleX - 1][size - missleY] == 5 || Grid[missleX - 1][size - missleY] == 8){
            cout << "You had already hit here!" << endl;
        }
        else {
            cout << "Missed! Your competitor still have " << ship - hitcounter << " spots haven't found." << endl;
            Grid[missleX - 1][size - missleY] = 5;
            misscounter++;
            totalhitcounter++;
        }
    }

    if (action == 2){
        cout << "\nYour grid: \n\n" << setw(5) << "Y" << endl;

        for (int column = 0;column < size;column++){
            cout << setw(5) << size - column;
            for (int row = 0;row < size;row++){
                cout << setw(5) << Grid[row][column];
        }
        cout << endl;
        }
        for (int row = 0;row <= size;row++){
            cout << setw(5) << row;
        }

        cout << setw(5) << "X" << endl;
    }

    if (action == 3){
        cout << "\nPlease input the position where you fire the missle (two numbers x and y): ";
        cin >> playerX >> playerY;
        cout << "\nDo you hit your competitor's battleship? (1 = hit 2 = miss) ";
        cin >> hit_player;
        cout << endl;

        while (Grid2[playerX - 1][size - playerY] == 8){
            cout << "You have already hit here! Please input again." << endl;
            cout << "\nPlease input the position where you fire the missle (two numbers x and y): ";
            cin >> playerX >> playerY;
            cout << "\nDo you hit your competitor's battleship? (1 = hit 2 = miss) ";
            cin >> hit_player;
            cout << endl;

        }

        if (hit_player == 1){
            hitcounter2++;
            totalhitcounter2++;
            cout << "Congratulations! You still have " << ship - hitcounter2 << " spots need to find." << endl;;
            Grid2[playerX - 1][size - playerY] = 8;
        }
        else if (hit_player == 2){
            misscounter2++;
            totalhitcounter2++;
            cout << "Try again next time! You still have " << ship - hitcounter2 << " spots need to find." << endl;;
            Grid2[playerX - 1][size - playerY] = 5;
        }
        else {
            cout << "Wrong input! Reset your action." << endl;
        }
    }

    if (action == 4){
        cout << "\nYour competitor's grid: \n\n" << setw(5) << "Y" << endl;

        for (int column = 0;column < size;column++){
            cout << setw(5) << size - column;

        for (int row = 0;row < size;row++){
            cout << setw(5) << Grid2[row][column];
        }
        cout << endl;
        }

        for (int row = 0;row <= size;row++){
            cout << setw(5) << row;
        }
        
        cout << setw(5) << "X" << endl;
    }

    if (action == 5){
        cout << "Which board do you want to make corrections? (1 = yourself 2 = your competitor)";
        cin >> correction;
        if (correction == 1){
            cout << "Please input the coordinate you want to change(two numbers x and y): ";
            cin >> changeX >> changeY;
            if (Grid[changeX - 1][size - changeY] == 8){
                hitcounter--;
            }
            else if (Grid[changeX - 1][size - changeY] == 5){
                misscounter--;
            }
            else if (Grid[changeX - 1][size - changeY] == 5){
                totalhitcounter++;
            }
            
            cout << "What is the correct status for (" << changeX << ", " << changeY << ") right now?(1 = hit 2 = miss 3 = return blank): ";
            cin >> spotstatus;

            if (spotstatus == 1){
                Grid[changeX - 1][size - changeY] = 8;
                hitcounter++;
            }
            else if (spotstatus == 2){
                Grid[changeX - 1][size - changeY] = 5;
                misscounter++;
            }
            else if (spotstatus == 3 && Grid[changeX - 1][size - changeY] != 0){
                Grid[changeX - 1][size - changeY] = 0;
            }
            else {
                cout << "Wrong input! Reset your action." << endl;
            }
            
        }

        if (correction == 2){
            cout << "Please input the coordinate you want to change(two numbers x and y): ";
            cin >> changeX >> changeY;
            if (Grid2[changeX - 1][size - changeY] == 8){
                hitcounter2--;
            }
            else if (Grid2[changeX - 1][size - changeY] == 5){
                misscounter2--;
            }
            else if (Grid2[changeX - 1][size - changeY] == 0){
                totalhitcounter2++;
            }

            cout << "What is the correct status for (" << changeX << ", " << changeY << ") right now?(1 = hit 2 = miss 3 = return blank): ";
            cin >> spotstatus;

            if (spotstatus == 1){
                Grid2[changeX - 1][size - changeY] = 8;
                hitcounter2++;
            }
            else if (spotstatus == 2){
                Grid2[changeX - 1][size - changeY] = 5;
                misscounter2++;
            }
            else if (spotstatus == 3 && Grid2[changeX - 1][size - changeY] != 0){
                Grid2[changeX - 1][size - changeY] = 0;
                totalhitcounter2--;
            }
            else {
                cout << "Wrong input! Reset your action." << endl;
            }
            
        }


    }

    if (action == -1){
        cout << "You quit!" << endl;
        gamestatus = 2;
    }

    if (hitcounter == ship){
        gamestatus = 2;
        cout << "You lose! Your battleship sunk.\n" << endl;

        cout << "      *" << endl;
        cout << "     ***" << endl;
        cout << "    *****" << endl;
        cout << "   *******" << endl;
        cout << "  *********" << endl;
        cout << " ***********" << endl;
        cout << "*************" << endl;
        cout << "     ***" << endl;
        cout << "     ***" << endl;
        cout << "     ***" << endl;
        cout << "Merry Christmas!\n" << endl;
    }

    if (hitcounter2 == ship){
        gamestatus = 2;
        cout << "You win! Your competitor's battleship sunk.\n" << endl;
        
        cout << " *  *  *   ***   **   *   *" << endl;
        cout << " *  *  *    *    * *  *   *" << endl;   
        cout << " *  *  *    *    *  * *    " << endl;
        cout << "  ** **    ***   *   **   *" << endl;
        cout << endl;
        

    }

    if (hitcounter == ship || hitcounter2 == ship){
        cout << "Your competitor's statistics: " << endl;
        cout << "How many times your competitor guess: " << setw(4) << totalhitcounter << endl;
        cout << "How many times your competitor hit: " << setw(4) << hitcounter << endl;
        cout << "How many times your competitor miss: " << setw(4) << misscounter << endl;
        cout << "Your competitor's hit rate: " << setw(4) << hitcounter / totalhitcounter << "\n" << endl;

        cout << "Your statistics: " << endl;
        cout << "How many times you guess: " << setw(4) << totalhitcounter2 << endl;
        cout << "How many times you hit: " << setw(4) << hitcounter2 << endl;
        cout << "How many times you miss: " << setw(4) << misscounter2 << endl;
        cout << "Your hit rate: " << setw(4) << hitcounter2 / totalhitcounter2 << endl;
        
    }
    }  
    return 0;
}
