#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
class Pawns{
    public:
        string name;
        char img;
        int cur_pos;

        Pawns(){
            name="CPU";
            img='C';
            cur_pos=0;
        }

        Pawns(string name){
            this->name=name;
            if(name[0]>='a'&&name[0]<='z')
                this->name[0]=name[0]-'a'+'A';
            img=this->name[0];
            cur_pos=0;
            if(img=='C')
                img='P';
        }
};

class Board{
    public:
        static const int steps=10;
        char line1[steps],line2[steps];

        Board(Pawns player,Pawns cpu){
            int i=0;
            for(i=0;i<steps;i++){
                    line1[i]='_';
                    line2[i]='_';
                }
            line1[player.cur_pos]=player.img;
            line2[cpu.cur_pos]=cpu.img;
        }

        void update(Pawns &p,string turn,int guess){
            if(turn=="player"){
                line1[p.cur_pos]='_';
                p.cur_pos+=guess;
                if(p.cur_pos>=steps)
                    p.cur_pos=steps-1;
                line1[p.cur_pos]=p.img;
                return;
            }
            else if(turn=="computer"){
                line2[p.cur_pos]='_';
                p.cur_pos+=guess;
                if(p.cur_pos>=steps)
                    p.cur_pos=steps-1;
                line2[p.cur_pos]=p.img;
                return;
            }
        }

        void show_board(Pawns player,Pawns cpu){
                cout<<"\n\n\t\t   "<<player.name<<"( "<<player.cur_pos+1<<" )\t\t"<<"Computer( "<<cpu.cur_pos+1<<" )\n\n";
                int i=0;
                cout<<"\n\t\t";

                for(i=0;i<steps;i++){
                    cout<<line1[i]; 
                }
                cout<<"\n\n\t\t";
                for(i=0;i<steps;i++){
                    cout<<line2[i];     
                }
                cout<<"\n\n\tStart(1)\t\t\t\t\tFinish(10)";
                cout<<"\n\n\n\n\n";

        }
};
int getRandom(){//Generate the random number
    int value;
    srand(time(0));
    value=(rand()%5)+1;
    return value;
}
int check(Pawns &p){//Checks if anyone has won the game.
    if(p.cur_pos>=Board::steps-1){
        p.cur_pos=Board::steps-1;
        system("CLS");
        cout<<"\n\n\t\t\t\t"<<p.name<<"  Won!!!\n\n\n\t\t\tSend Alapan 100 dollars!!!\n\t\t\tor phone Hacked  "<<char(1)<<"\n";
        return 1;
    }
    return 0;
}

void play_game(Pawns player,Pawns cpu,Board b){
    system("CLS");
    int random=0,guess=0;
    b.show_board(player,cpu);
    while(true){
        random=getRandom();
        cout<<"\nGuess a number (1-5): ";
        cin>>guess;
        while(guess<1||guess>5){
            cout<<"\n!!Enetr a number between (1-5)!!: ";
            cin>>guess;
        }
        system("CLS");
        cout<<"\n\n";
        if(random==guess){
            cout<<"Correct Guess: ("<<random<<")."<<player.name<<" moves "<<guess<<" steps.\n";
            b.update(player,"player",random);
        }
        else{
            cout<<"Wrong Guess ("<<guess<<"). Number was: ("<<random<<")\n";
        }
        if(check(player)){
            b.show_board(player,cpu);
            break;
        }
        b.show_board(player,cpu);

        guess=getRandom();
        cout<<"\nGive a number for Computer to guess(1-5): ";
        cin>>random;
        while(random<1||random>5){
            cout<<"\n!!Enetr a number between (1-5)!!: ";
            cin>>random;
        }
        system("CLS");
        cout<<"\n\n";
        if(random==guess){
            cout<<"Computer Guessed Correct("<<random<<"). Computer moves "<<guess<<" steps.\n";
            b.update(cpu,"computer",random);
        }
        else{
            cout<<"Computer Guessed Wrong ("<<guess<<"). Number was: ("<<random<<")\n";
        }
        if(check(cpu)){
            b.show_board(player,cpu);
            break;
        }
        b.show_board(player,cpu);        
    }

}


int main(){
    system("CLS");
    string name="Player";
    int choice=0;
    
    cout<<"Enter your name: ";
    cin>>name;

    Pawns player=Pawns(name);
    Pawns cpu=Pawns();
    Board b=Board(player,cpu);

    play_game(player,cpu,b);
    
    cout<<"Enter 1 to play again or 0 to quit: ";
    cin>>choice;
    if(choice==1)
        play_game(player,cpu,b);


    return 0;
}