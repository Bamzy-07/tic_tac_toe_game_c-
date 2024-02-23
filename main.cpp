#include <iostream>
#include <cstdlib>

using namespace std;
const int NUM_OF_ROWS = 3;
const int NUM_OF_COLS = 3;

char board[NUM_OF_ROWS][NUM_OF_COLS]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
bool draw = false;

void display_board();
void player_turn();
bool gameOver();


int main()
{

    cout<<"Bamzy's TIC--TAC-TOE-GAME FOR 2 PLAYERS"<<endl;
    while(gameOver()){
        display_board();
        player_turn();
        gameOver();
    }
    if(turn == 'X' && draw == false){
        cout<<"/nCongratulations!Player with 'X' has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"/nCongratulations!Player with 'O' has won the game";
    }
    else
    cout<<"/nGAME DRAW!!!/n";

    return 0;
}

void display_board(){
    for(int i=0; i<NUM_OF_ROWS; i++){
        for(int j =0; j<NUM_OF_COLS; j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }

}

void player_turn(){
    int num1, num2;

        if(turn =='X')
            cout<<"Player-1's [X] turn"<<endl;
        else if(turn == 'O')
            cout<<"Player-2's [O] turn"<<endl;

        cout<<"Enter your row and column number (can be 1,2 or 3): "<<endl;
        cin>>num1>>num2;

        if(num1>3 || num2> 3 || num1 <0 || num2<0){
        cout<<"Invalid numbers, row and column number can only be 1,2 or 3!!..Enter again: "<<endl;
        cin>>num1>>num2;
       }
        if(0 < num1 <=3 && 0 < num2 <=3){
            if(turn=='X' && board[num1][num2] != 'X' && board[num1][num2]!='O'){
                board[num1-1][num2-1]='X';
                turn='O';
            }
            else if(turn=='O' && board[num1][num2] != 'X' && board[num1][num2]!='O'){
                board[num1-1][num2-1]='O';
                turn='X';
            }
            else{
                cout<<"Cell already filled! Choose another cell"<<endl;
                player_turn();
            }

       }
       else{
        cout<<"You have forfeited your turn"<<endl;
        if(turn=='X')
            turn=='O';
        else if(turn=='O')
            turn='X';
       }

}

bool gameOver(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
        return true;

    //Checking the if game already draw
    draw = true;
    return false;
}

