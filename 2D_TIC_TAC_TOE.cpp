#include<iostream>
using namespace std;

struct index
{
    int x;
    int y;

};
index index1;

char board[3][3] = {{'*','*','*'},{'*','*','*'},{'*','*','*'}};// Single array represents the board '*' means empty box in board

int isFull()// Board is full
{
    for(int i =0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
                if(board[i][j]!='X')
            {
                if(board[i][j]!='O')
                {
                    return 0;
                }
            }
        }
    }
return 1;
}

int player2_won()//Checks whether player has won
{
    for(int i=0;i<3;i++)
    {
        int j=0;
        if((board[i][j]==board[i][j+1])&&(board[i][j+1]==board[i][j+2])&&(board[i][j]=='O'))
            return 1;
    }
    for(int j=0;j<3;j++)
    {
        int i=0;
        if((board[i][j]==board[i+1][j])&&(board[i+1][j]==board[i+2][j])&&(board[i][j]=='O'))
            return 1;
    }
    if((board[0][0]==board[1][1])&&(board[1][1]==board[2][2])&&(board[0][0]=='O'))
    {
        return 1;
    }
    if((board[0][2]==board[1][1])&&(board[1][1]==board[2][0])&&(board[0][2]=='O'))
    {
        return 1;
    }
    return 0;
}

int player1_won()// Checks whether computer has won
{
    for(int i=0;i<3;i++)
    {
        int j=0;
        if((board[i][j]==board[i][j+1])&&(board[i][j+1]==board[i][j+2])&&(board[i][j]=='X'))
            return 1;
    }
    for(int j=0;j<3;j++)
    {
        int i=0;
        if((board[i][j]==board[i+1][j])&&(board[i+1][j]==board[i+2][j])&&(board[i][j]=='X'))
            return 1;
    }
    if((board[0][0]==board[1][1])&&(board[1][1]==board[2][2])&&(board[0][0]=='X'))
    {
        return 1;
    }
    if((board[0][2]==board[1][1])&&(board[1][1]==board[2][0])&&(board[0][2]=='X'))
    {
        return 1;
    }
    return 0;
}

void draw_board() //display tic-tac-toe board
{
    cout<<endl;
    cout<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<endl;
    cout<<"-----"<<endl;
    cout<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<endl;
    cout<<"-----"<<endl;
    cout<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<endl;
}

int minimax(bool flag)// The minimax function
{

    int max_val=-1000,min_val=1000;
    int i,j,value = 1;
    if(player1_won() == 1)
        {return 10;}
    else if(player2_won() == 1)
        {return -10;}
    else if(isFull()== 1)
        {return 0;}
    int score[3][3] = {{1,1,1},{1,1,1},{1,1,1}};//if score[i][j]=1 then it is empty

        for(i=0;i<3;i++)
            {
                 for(int j=0;j<3;j++)
                 {
                        if(board[i][j] == '*')
                    {
                        if(min_val>max_val) // reverse of pruning condition.....
                    {
                        if(flag == true)
                    {
                        board[i][j] = 'X';
                        value = minimax(false);
                    }
                        else
                    {
                        board[i][j] = 'O';
                        value = minimax(true);
                    }
                        board[i][j] = '*';
                        score[i][j] = value;
                    }
                    }

                 }
            }

        if(flag == true)
        {
                 max_val = -1000;
                 for(int i=0;i<3;i++)
                 {
                    for(j=0;j<3;j++)
                    {
                        if(score[i][j] > max_val && score[i][j] != 1)
                        {
                            max_val = score[i][j];
                            index1.x = i;
                            index1.y = j;
                        }
                    }
                 }
                    return max_val;


        }
        if(flag == false)
        {
                min_val = 1000;
                for(int i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        if(score[i][j] < min_val && score[i][j] != 1)
                        {
                            min_val = score[i][j];
                            index1.x = i;
                            index1.y = j;
                        }
                    }

                }
            return min_val;
        }
}

int main() //The main function
{
    cout<<"-------------------------TIC TAC TOE-----------------------------------------------------";
    cout << "1 -> SINGLE PLAYER  &  2-> TWO PLAYERS " << endl;

    int noOfPlayers;
    cin >> noOfPlayers ;
    string name ,name1, name2;
    index move;
    int choice;
    if(noOfPlayers == 1){                        // IF NO. OF PLAYERS = 1

    cout << name <<" Enter your name : "<< endl;
    cin >> name ;
    cout<<endl<< name <<"--->(O)      Computer------>(X)";
    cout<<endl<<"SELECT : 1-> "<< name <<" first 2-> Computer first:";
    cin>>choice;
    if(choice == 1)
    {
       draw_board();
       cout << "Optimal move for " << name << " is : ";
       minimax(false);
       cout <<"("<< (index1.x+1)<<","<<(index1.y+1)<<")"<< endl;

    up_1:cout<< name <<" Enter the move : ";
         cin>>move.x>>move.y;                  // Player's move
         if(board[move.x-1][move.y-1]=='*')
         {
           board[move.x-1][move.y-1] = 'O';
           draw_board();
         }
         else
         {
             cout<<endl<<"Invalid Move......Try different move";
             goto up_1;
         }
    }

    while(true)
    {

        cout<<endl<<"computer's MOVE....";
        minimax(true);
        board[index1.x][index1.y] = 'X';// Computer's move
        draw_board();
        if(player1_won()==1)
        {
            cout<<endl<<"computer WON.....";
            break;
        }
        if(isFull()==1)
        {
            cout<<endl<<"Draw....";
            break;
        }

        cout << "Optimal move for " << name << " is : ";
        minimax(false);
        cout <<"("<< (index1.x+1)<<","<<(index1.y+1)<<")"<< endl;
  up_2: cout<< name <<" Enter the move : ";
        cin>>move.x>>move.y;                       // Again Player's move
        if(board[move.x-1][move.y-1]=='*')
         {
           board[move.x-1][move.y-1] = 'O';
           draw_board();
         }
         else
         {
             cout<<endl<<"Invalid Move......Try different move";
             goto up_2;
         }
         if(player2_won()==1)
         {
             cout<<endl<<"You Won......";
             break;
         }
         if(isFull() == 1)
         {
            cout<<endl<<"Draw....";
            break;
         }
     }
     }
     else if(noOfPlayers==2)
     {                                         // IF NO. OF PLAYERS = 2

        cout << "Enter the names of the players " << endl;
        cout << "Player_1 :" << endl;
        cin >> name1 ;
        cout << "PLayer_2:" << endl;
        cin >> name2 ;
        cout << name1 <<" your symbol: X "<< endl;
        cout << name2 <<" your symbol: O" << endl;

        cout<<endl<<"SELECT : 1-> " << name1 << " first  OR   2-> " <<name2<< " first:";
        cin>>choice;

        if(choice==1)
        {
            draw_board();
            cout << "Optimal move for " << name1 << " is : " ;
            minimax(true);
            cout <<"("<< (index1.x+1)<<","<<(index1.y+1)<<")"<< endl;
      up_3: cout<<name1<<" ,Enter the move: ";
            cin>>move.x>>move.y;                     // PLAYER_1'S MOVE
            if(board[move.x-1][move.y-1]=='*')
            {
                board[move.x-1][move.y-1] = 'X';
                draw_board();
            }
            else
            {
                cout<<endl<<"Invalid Move......Try different move";
                goto up_3;
            }

        }
            else if(choice==2)
            {
                draw_board();
                cout << "Optimal move for " << name2 << " is : ";
                minimax(false);
                cout <<"("<< (index1.x+1)<<","<<(index1.y+1)<<")"<< endl;
          up_4: cout<<name2<<" ,Enter the move: ";
                cin>>move.x>>move.y;                        //PLAYER_2'S MOVE
                if(board[move.x-1][move.y-1]=='*')
                {
                    board[move.x-1][move.y-1] = 'O';
                    draw_board();
                }
                else
                {
                    cout<<endl<<"Invalid Move......Try different move";
                    goto up_4;
                }

            }

            if(choice ==1)
            {
                while(true)
                {
                    cout << "Optimal move for " << name2 << " is : ";
                    minimax(false);
                    cout <<"("<< (index1.x+1)<<","<<(index1.y+1)<<")"<< endl;
              up_5: cin>>move.x>>move.y;                         //If first move was of player_1 then second move will be of player_2
                    if(board[move.x-1][move.y-1]=='*')
                    {
                        board[move.x-1][move.y-1] = 'O';
                        draw_board();
                    }
                    else
                    {
                    cout<<endl<<"Invalid Move......Try different move";
                    goto up_5;
                    }
                    if(player2_won()==1)
                    {
                        cout<<name2<<" ,You WON......"<<endl;
                        break;
                    }
                    if(isFull() == 1)
                    {
                        cout<<endl<<"Draw....";
                        break;
                    }

                    cout << "Optimal move for " << name1 << " is : " ;
                    minimax(true);
                    cout <<"("<< (index1.x+1)<<","<<(index1.y+1)<<")"<< endl;
                    cout << name1 << " ,Enter the move: ";
              up_6: cin>>move.x>>move.y;                               // Again move of player_1
                    if(board[move.x-1][move.y-1]=='*')
                    {
                        board[move.x-1][move.y-1] = 'X';
                        draw_board();
                    }
                    else
                    {
                        cout<<endl<<"Invalid Move......Try different move";
                        goto up_6;
                    }

                    if(player1_won()==1)
                    {
                        cout<<name1<<" ,You WON....."<< endl;
                        break;
                    }
                    if(isFull()==1)
                    {
                        cout<<endl<<"Draw....";
                        break;
                    }

                }

            }




            else if(choice==2)
            {
                while(true)
                {
                    cout << "Optimal move for " << name1 << " is : ";
                    minimax(true);
                    cout <<"("<< (index1.x+1)<<","<<(index1.y+1)<<")"<< endl;
                    cout << name1 << " ,Enter the move: ";
              up_7: cin>>move.x>>move.y;                    // If first move was of player_2 then second move will be of player_1
                    if(board[move.x-1][move.y-1]=='*')
                    {
                        board[move.x-1][move.y-1] = 'X';
                        draw_board();
                    }
                    else
                    {
                        cout<<endl<<"Invalid Move......Try different move";
                        goto up_7;
                    }


                    if(player1_won()==1)
                    {
                        cout<<name1<<" ,You WON....."<< endl;
                        break;
                    }
                    if(isFull()==1)
                    {
                        cout<<endl<<"Draw....";
                        break;
                    }



                    cout << "Optimal move for " << name2 << " is : ";
                    minimax(false);
                    cout <<"("<< (index1.x+1)<<","<<(index1.y+1)<<")"<< endl;
                    cout<< name2 <<" ,Enter the move:";
             up_8:  cin>>move.x>>move.y;                         // Again move of player_2
                    if(board[move.x-1][move.y-1]=='*')
                    {
                        board[move.x-1][move.y-1] = 'O';
                        draw_board();
                    }
                    else
                    {
                        cout<<endl<<"Invalid Move......Try different move";
                        goto up_8;
                    }
                    if(player2_won()==1)
                    {
                        cout<<name2<<" ,You WON......"<<endl;
                        break;
                    }
                    if(isFull() == 1)
                    {
                        cout<<endl<<"Draw....";
                        break;
                    }
                }
            }
        }
}
