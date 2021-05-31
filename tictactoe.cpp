#include <bits/stdc++.h> // Includes all standart library

using namespace std;

char box[3][3] = {{'1' ,'2' ,'3'}, {'1','2','3'}, {'1', '2', '3'} }; // The table of tic tac toe

int whichPlayer();
void whichPlayerIsMoving(int player, int firstPlayer, int &whichPlayerMove);
void gameTable();
void writeInput(int whichPlayerMove);
void checkWinner(int whichPlayerMove, char &currentMarking, bool &gameFinshed);
int main()
{
    bool gameFinished = false;
    char currentMarking;
    int player = whichPlayer(); // 1 - X, 2 - O
    int firstPlayer = player; // Used for knowing which symbol the 1st player uses
    for(int i = 0; i < 9; i++){
        int whichPlayerMove;
        system("cls");
        whichPlayerIsMoving(player, firstPlayer, whichPlayerMove); // Writing which player with what symbol is currently moving
        gameTable(); // Outputting the tic tac toe table
        writeInput(whichPlayerMove);
        if(i > 3) checkWinner(whichPlayerMove, currentMarking, gameFinished); // Checking the winner every time after 5 moves
        if(gameFinished){
            system("cls"); // Clearing the console
            gameTable();
            cout << endl;
            cout << "Player " << whichPlayerMove << " won with " << currentMarking << endl;
            break;
        }
        if(i == 8 && !gameFinished){
            gameTable();
            cout << "The game ended in a draw." << endl;
            break;
        }
        player++; // Changing the current player, check lines 61 to 63
    }
    return 0;
}
int whichPlayer(){
    string marking;
    int player =- 1;
    while(player == -1){
        cout << "First player starts with:  X/O" << endl; cin >> marking;
        if(marking != "X" && marking != "O" && marking != "x" && marking != "o" && marking != "0"){
            system("cls");
            cout << "Incorrect input!" << endl;
            cout << endl;
        }
        else {
            if(marking == "X" || marking == "x" || marking == "0") player = 1;
            if(marking == "O" || marking == "o" || marking == "0") player = 2;
        }
    }
    return player;
}

void whichPlayerIsMoving(int player, int firstPlayer, int &whichPlayerMove){

    /* The program checks which player is currently moving by taking the remainder of the player.
       The player integer always adds 1 after the whole sequence ends. This way the program
       can easily tell which player has to currently move. */

    if(firstPlayer == 1 && player % 2 == 1){
        cout << "First player moves with: X" << endl;
        whichPlayerMove = 1;
    }
    if(firstPlayer == 2 && player % 2 == 0){
        cout << "First player moves with: O" << endl;
        whichPlayerMove = 2;
    }
    if(firstPlayer == 1 && player % 2 == 0){
        cout << "Second player moves with: O" << endl;
        whichPlayerMove = 2;
    }
    if(firstPlayer == 2 && player % 2 == 1){
        cout << "First player moves with: O" << endl;
        whichPlayerMove = 1;
    }

    cout << endl;

}

void gameTable(){

    cout << "     |     |     " << endl;
    cout << "  " << box[0][0] << "  |  " << box[0][1] << "  |  " << box[0][2] << "   1st row" << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << box[1][0] << "  |  " << box[1][1] << "  |  " << box[1][2] << "   2nd row" << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << box[2][0] << "  |  " << box[2][1] << "  |  " << box[2][2] << "   3rd row" << endl;
    cout << "     |     |     " << endl;

}

void writeInput(int whichPlayerMove){

    int row, col;

    cout << "Which row would you like to modify?" << endl; cin >> row;
    cout << endl;
    if(row != 1 && row != 2 && row != 3){
        cout << "Incorrect input!" << endl;
        cout << endl;
        writeInput(whichPlayerMove);
    }
    cout << "Which column would you like to modify?" << endl; cin >> col;
    cout << endl;
    if(col != 1 && col != 2 && col != 3){
        cout << "Incorrect input!" << endl;
        cout << endl;
        writeInput(whichPlayerMove);
    }
    if(box[row-1][col-1] == 'X' || box[row-1][col-1] == 'O'){
        cout << "This location is occupied!" << endl;
        cout << endl;
        writeInput(whichPlayerMove);
    }

    if(whichPlayerMove == 1){
        box[row-1][col-1] = 'X';
    }
    if(whichPlayerMove == 2){
        box[row-1][col-1] = 'O';
    }

}

void checkWinner(int whichPlayerMove, char &currentMarking, bool &gameFinished){

    if(whichPlayerMove == 1) currentMarking = 'X';
    if(whichPlayerMove == 2) currentMarking = 'O';

    // horizontal

    if(box[0][0] == currentMarking && box[0][1] == currentMarking && box[0][2] == currentMarking) gameFinished = true; // 1st col
    if(box[1][0] == currentMarking && box[1][1] == currentMarking && box[1][2] == currentMarking) gameFinished = true; // 2nd col
    if(box[2][0] == currentMarking && box[2][1] == currentMarking && box[2][2] == currentMarking) gameFinished = true; // 3rd col

    // vertical

    if(box[0][0] == currentMarking && box[1][0] == currentMarking && box[2][0] == currentMarking) gameFinished = true; // 1st row
    if(box[0][1] == currentMarking && box[1][1] == currentMarking && box[2][1] == currentMarking) gameFinished = true; // 2nd row
    if(box[0][2] == currentMarking && box[1][2] == currentMarking && box[2][2] == currentMarking) gameFinished = true; // 3rd row

    // 45 degrees

    if(box[0][0] == currentMarking && box[1][1] == currentMarking && box[2][2] == currentMarking) gameFinished = true; // left to right
    if(box[0][2] == currentMarking && box[1][1] == currentMarking && box[2][0] == currentMarking) gameFinished = true; // right to left

}
