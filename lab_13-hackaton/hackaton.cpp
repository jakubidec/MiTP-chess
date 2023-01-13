#include <iostream>

using namespace std;

void Clear()
{
    cout << "\x1B[2J\x1B[H";
}

string board[8][8] = {
        {"br","bk","bb","bq","bK","bb","bk","br"},
        {"__","__","__","__","__","__","__","__"},
        {"__","__","__","__","__","__","__","__"},
        {"__","__","__","__","__","__","__","__"},
        {"__","__","__","__","__","__","__","__"},
        {"__","__","__","__","__","__","__","__"},
        {"__","__","__","__","__","__","__","__"},
        {"wr","wk","wb","wq","wK","wb","wk","wr"}
    };

void display_board(){

    cout << endl;

    for(int i=0;i<8;i++){
        if(i==0){
            cout << "  a  b  c  d  e  f  g  h" << endl;
        }
        else{
            cout << endl;
        }
        
        for(int j=0;j<8;j++){

            if(j==0){
                cout << 8-i << " ";
            }

            cout << board[i][j] << " ";
        }
    }

    cout << endl;

}

int Move_to(int x, int y, int i, int j, int w){

    if(board[y][x]=="__"){
        cout << "You choose empty position" << endl;
        return 0;
    }
    if(y==j && x==i){

        cout << "You choose the same position" << endl;
        return 0;
    }
    if(!w){
        if(board[j][i]=="wr" || board[j][i]=="wk" || board[i][j]=="wb" || board[j][i]=="wq" || board[j][i]=="wK"){

            cout << "There are your pawns!" << endl;
            return 0;
        }

        if(board[y][x]=="wr"){

            int mod = 0;

            if(y-j>0){

                mod = y-j;
            }
            else if(j-y>0){

                mod = j-y;
            }

            for(int k=0;k<=mod;k++){

                if((x+k>0 && x+k<7) && !(board[x+k][y+k]=="__")){

                        cout << "Nie możesz wykonać tego ruchu" << endl;
                }
                if(x+k==i || y+k==j){

                    board[y][x] = "__";
                    board[j][i] = "wk";
                }
            }

                board[y][x] = "__";
                board[j][i] = "wr";
            
            return 1;
        }
        if(board[y][x]=="wb"){

            int mod=0;

            if((y-j)>0){//y>j
                mod = y-j;

                for(int k=0;k<=mod;k++){

                    if((x+k>0 && x+k<7) && !(board[x+k][y+k]=="__")){

                        cout << "Nie możesz wykonać tego ruchu" << endl;
                    }
                    if((x+k==i || x-k==i)&& y-k==j){

                        board[y][x] = "__";
                        board[j][i] = "wb";
                    }
                }
                
            }
            else if((j-y)>0){
                mod = j-y;

                for(int k=0;k<=mod;k++){

                    if((x-k>0 && x-k<7) && !(board[x-k][y-k]=="__")){

                        cout << "Nie możesz wykonać tego ruchu" << endl;
                    }
                    if((x+k==i || x-k==i)&& y+k==j){

                        board[y][x] = "__";
                        board[j][i] = "wk";
                    }
                }
            }

            
            return 1;
        }
        if(board[y][x]=="wk"){

            return 1;
        }
        if(board[y][x]=="wq"){

           return 1;
        }
        if(board[y][x]=="wK"){

            return 1;
        }
        return 0;
    }
    else if(w){

        cout << "black";
        return 1;
    }
    return 1;
}


int main(){

    int who = 0; //0 - white, 1- black


    while(1){

        choose:

        string choose;

        display_board();
        cout << endl << endl << "Move from ";
        cin >> choose;

        if((char(choose[0])>96 && char(choose[0])<105) && (choose[1]>48 && choose[1]<57)){

            int x,y = 0;

            if(choose[0]=='a'){x=0;};
            if(choose[0]=='b'){x=1;};
            if(choose[0]=='c'){x=2;};
            if(choose[0]=='d'){x=3;};
            if(choose[0]=='e'){x=4;};
            if(choose[0]=='f'){x=5;};
            if(choose[0]=='g'){x=6;};
            if(choose[0]=='h'){x=7;};

            cout << x << endl;

            if(choose[1]=='8'){y=0;};
            if(choose[1]=='7'){y=1;};
            if(choose[1]=='6'){y=2;};
            if(choose[1]=='5'){y=3;};
            if(choose[1]=='4'){y=4;};
            if(choose[1]=='3'){y=5;};
            if(choose[1]=='2'){y=6;};
            if(choose[1]=='1'){y=7;};

            cout << y << endl << endl;

            string move;

            cout << endl << "to ";
            cin >> move;

            if((char(move[0])>96 && char(move[0])<105) && (move[1]>48 && move[1]<57)){

                int i,j = 0;

                if(move[0]=='a'){i=0;};
                if(move[0]=='b'){i=1;};
                if(move[0]=='c'){i=2;};
                if(move[0]=='d'){i=3;};
                if(move[0]=='e'){i=4;};
                if(move[0]=='f'){i=5;};
                if(move[0]=='g'){i=6;};
                if(move[0]=='h'){i=7;};

                cout << i << endl;

                if(move[1]=='8'){j=0;};
                if(move[1]=='7'){j=1;};
                if(move[1]=='6'){j=2;};
                if(move[1]=='5'){j=3;};
                if(move[1]=='4'){j=4;};
                if(move[1]=='3'){j=5;};
                if(move[1]=='2'){j=6;};
                if(move[1]=='1'){j=7;};

                cout << j << endl << endl;

                Move_to(x,y,i,j,who);
            }
            else{

                cout << "Wrong position!" << endl;
            }
        }
        else{

            cout << "Wrong position!" << endl;
        }
        

        /*if(who){

            who = 0;
        }
        if(!who){

            who = 1;
        }*/

    }
}