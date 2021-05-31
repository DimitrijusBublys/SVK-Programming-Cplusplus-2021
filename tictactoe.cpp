#include <bits/stdc++.h> // Includes all standart library

using namespace std;

char box[3][3] = {{'1','2','3'},{'1','2','3'},{'1','2','3'}};

void whichPlayer(int &player);
void gameTable(int player, int firstPlayer, int &whichPlayer, bool noMoves);
void writeInput(int whichPlayer);
void checkWinner(bool &wonX, bool &wonO);
int main()
{
    int player; // 1 - X, 2 - O
    bool wonX=false;
    bool wonO=false;
    bool noMoves=false;
    whichPlayer(player);
    int firstPlayer=player;
    for(int i=0; i<9; i++){
        int whichPlayer;
        system("cls");
        gameTable(player, firstPlayer, whichPlayer, noMoves);
        writeInput(whichPlayer);
        if(i>3)checkWinner(wonX, wonO);
        if(wonX){
            system("cls");
            noMoves=true;
            gameTable(player, firstPlayer, whichPlayer, noMoves);
            if(firstPlayer==1 && player%2==1) cout << "The game was won by player 1 with X!" << endl;
            if(firstPlayer==2 && player%2==1) cout << "The game was won by player 2 with X!" << endl;
            break;
        }
        if(wonO){
            system("cls");
            noMoves=true;
            gameTable(player, firstPlayer, whichPlayer, noMoves);
            if(firstPlayer==2 && player%2==0) cout << "The game was won by player 1 with O!" << endl;
            if(firstPlayer==1 && player%2==0) cout << "The game was won by player 2 with O!" << endl;
            break;
        }
        if(i==8){
            if(wonX==false && wonO==false){
                noMoves=true;
                gameTable(player, firstPlayer, whichPlayer, noMoves);
                cout << "The game ended in a draw." << endl;
            }
        }
        player++;
    }
    return 0;
}
void whichPlayer(int &player){
    string marking;
    player=-1;
    while(player==-1){
        cout << "First player starts with:  X/O" << endl; cin >> marking;
            if(marking!="X" && marking!="O" && marking!="x" && marking!="o" && marking!="0"){
                system("cls");
                cout << "Incorrect input!" << endl;
                cout << endl;
            }
        if(marking=="X" || marking=="x" || marking=="0") player=1;
        if(marking=="O" || marking=="o" || marking=="0") player=2;
    }
}

void gameTable(int player, int firstPlayer, int &whichPlayer, bool noMoves){
    if(noMoves==false){
        if(firstPlayer==1 && player%2==1){
        cout << "First player moves with X" << endl;
        whichPlayer=1;
        }
        if(firstPlayer==2 && player%2==0){
            cout << "First player moves with O" << endl;
            whichPlayer=2;
        }
        if(firstPlayer==1 && player%2==0){
            cout << "Second player moves with O" << endl;
            whichPlayer=2;
        }
        if(firstPlayer==2 && player%2==1){
            cout << "First player moves with O" << endl;
            whichPlayer=1;
        }
    }

    cout << endl;

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

void writeInput(int whichPlayer){
    int col, row;
    cout << "Which column would you like to modify?" << endl; cin >> col;
    cout << endl;
    if(col!=1 && col!=2 && col!=3){
        cout << "Incorrect input!" << endl;
        cout << endl;
        writeInput(whichPlayer);
        whichPlayer=-1;
    }
    cout << "Which row would you like to modify?" << endl; cin >> row;
    cout << endl;
    if(row!=1 && row!=2 && row!=3){
        cout << "Incorrect input!" << endl;
        cout << endl;
        writeInput(whichPlayer);
        whichPlayer=-1;
    }
    if(box[col-1][row-1]=='X' || box[col-1][row-1]=='O'){
        cout << "This location is occupied!" << endl;
        cout << endl;
        writeInput(whichPlayer);
        whichPlayer=-1;
    }
    if(whichPlayer==1){
        box[col-1][row-1]='X';
    }
    if(whichPlayer==2){
        box[col-1][row-1]='O';
    }
}

void checkWinner(bool &wonX, bool &wonO){

    // X
    // horizontal

    if(box[0][0]=='X' && box[0][1]=='X' && box[0][2]=='X') wonX=true; // 1st col
    if(box[1][0]=='X' && box[1][1]=='X' && box[1][2]=='X') wonX=true; // 2nd col
    if(box[2][0]=='X' && box[2][1]=='X' && box[2][2]=='X') wonX=true; // 3rd col

    // vertical

    if(box[0][0]=='X' && box[1][0]=='X' && box[2][0]=='X') wonX=true; // 1st row
    if(box[0][1]=='X' && box[1][1]=='X' && box[2][1]=='X') wonX=true; // 2nd row
    if(box[0][2]=='X' && box[1][2]=='X' && box[2][2]=='X') wonX=true; // 3rd row

    // 45 degrees

    if(box[0][0]=='X' && box[1][1]=='X' && box[2][2]=='X') wonX=true; // left to right
    if(box[0][2]=='X' && box[1][1]=='X' && box[2][0]=='X') wonX=true; // right to left


    // O
    // horizontal

    if(box[0][0]=='O' && box[0][1]=='O' && box[0][2]=='O') wonO=true;
    if(box[1][0]=='O' && box[1][1]=='O' && box[1][2]=='O') wonO=true;
    if(box[2][0]=='O' && box[2][1]=='O' && box[2][2]=='O') wonO=true;

    // vertical

    if(box[0][0]=='O' && box[1][0]=='O' && box[2][0]=='O') wonO=true;
    if(box[0][1]=='O' && box[1][1]=='O' && box[2][1]=='O') wonO=true;
    if(box[0][2]=='O' && box[1][2]=='O' && box[2][2]=='O') wonO=true;

    // 45 degrees

    if(box[0][0]=='O' && box[1][1]=='O' && box[2][2]=='O') wonO=true;
    if(box[0][2]=='O' && box[1][1]=='O' && box[2][0]=='O') wonO=true;
}
