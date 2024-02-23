#include <iostream>
#include <cstdlib>

using namespace std;
const int NUM_OF_ROWS = 3;
const int NUM_OF_COLS = 3;
int row_num, col_num;
int choice;

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
        cout<<"\nCongratulations! Player with 'X' has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"\nCongratulations! Player with 'O' has won the game";
    }
    else
    cout<<"\nThe game is a draw!!!";

    return 0;
}

void display_board(){
    cout<<"\n__"<<"__"<<"__"<<"__"<<"__"<<"__"<<"_"<<endl;
    cout<<"| "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" |"<<endl;
    cout<<"__"<<"__"<<"__"<<"__"<<"__"<<"__"<<"_"<<endl;
    cout<<"| "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" |"<<endl;
    cout<<"__"<<"__"<<"__"<<"__"<<"__"<<"__"<<"_"<<endl;
    cout<<"| "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" |"<<endl;
    cout<<"__"<<"__"<<"__"<<"__"<<"__"<<"__"<<"_\n"<<endl;

}

void player_turn(){

        if(turn =='X')
            cout<<"Player-1's [X] turn"<<endl;
        else if(turn == 'O')
            cout<<"Player-2's [O] turn"<<endl;

        cout<<"Enter where to insert your turn: "<<endl;
        cin>>choice;

       switch(choice){
   case 1:
    row_num =0; col_num=0;
    break;
   case 2:
    row_num=0; col_num=1;
    break;
   case 3:
    row_num=0; col_num=2;
    break;
   case 4:
    row_num=1; col_num=0;
    break;
   case 5:
    row_num=1; col_num=1;
    break;
   case 6:
    row_num=1; col_num=2;
    break;
   case 7:
    row_num=2; col_num=0;
    break;
   case 8:
    row_num=2; col_num=1;
    break;
   case 9:
    row_num=2; col_num=2;
    break;
   default:
    cout<<"Invalid number!!"<<endl;
    }

    if(turn == 'X' && board[row_num][col_num]!='X' && board[row_num][col_num]!='O' ){
        board[row_num][col_num] = 'X';
        turn = 'O';
    }

    else if(turn=='O' && board[row_num][col_num]!='X' && board[row_num][col_num]!='O' ){
        board[row_num][col_num] ='O';
        turn='X';
    }else {
        //if input position already filled
        cout<<"Box already filled!!! Please choose another cell: ";
        player_turn();
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

