#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
class Pawns{
    public:
        static const int steps=2;
        string name;
        char img,line[steps];
        int cur_pos;
        Pawns(){
            name="CPU";
            img='C';
            cur_pos=0;
            for(int i=1;i<steps;i++)
                line[i]='_';
            line[0]='C';
        }
        Pawns(string name){
            this->name=name;
            if(name[0]>='a'&&name[0]<='z')
                this->name[0]=name[0]-'a'+'A';
            img=this->name[0];
            cur_pos=0;
            if(img=='C')
                img='P';
            for(int i=1;i<steps;i++)
                line[i]='_';
            line[0]=img;
        }
        void update(int guess){
            line[cur_pos]='_';
            cur_pos+=guess;
            if(cur_pos>=steps)
                cur_pos=steps-1;
            line[cur_pos]=img;
        }      
};
void show_board(Pawns player,Pawns cpu){
    cout<<"\n\n\t\t"<<player.name<<"( "<<player.cur_pos+1<<" )\t\t"<<"Computer( "<<cpu.cur_pos+1<<" )\n\n\n\t\t\t";
    int i=0;
    for(i=0;i<Pawns::steps;i++)
        cout<<player.line[i]; 
    cout<<"\n\n\t\t\t";
    for(i=0;i<Pawns::steps;i++)
        cout<<cpu.line[i];     
    cout<<"\n\n\t  Start(1)\t\t\t\tFinish("<<Pawns::steps<<")\n\n\n\n\n";
}
int getRandom(){//Generate the random number
    int value;
    srand(time(0));
    value=(rand()%5)+1;
    return value;
}
int check(Pawns &p){//Checks if anyone has won the game.
    if(p.cur_pos>=Pawns::steps-1){
        p.cur_pos=Pawns::steps-1;
        system("CLS");
        cout<<"\n\n\t\t\t "<<p.name<<"  Won!!!\n";
        return 1;
    }
    return 0;
}
void play_game(Pawns player,Pawns cpu){
    system("CLS");
    int player_input=0,computer_input=0,flag=0;
    show_board(player,cpu);
    while(flag==0){
        computer_input=getRandom();
        cout<<"\nGuess a number (1-5)(Enter -1 to quit): ";
        cin>>player_input;
        while((player_input<1||player_input>5)&&player_input!=-1){
            cout<<"\n!!Enter a number between (1-5)!!(Enter -1 to quit): ";
            cin>>player_input;
        }
        if(player_input==-1)
            exit(0);
        system("CLS");
        cout<<"\n\n";
        if(player_input==computer_input){
            cout<<"Correct Guess: ("<<player_input<<")."<<player.name<<" moves "<<player_input<<" steps.\n";
            player.update(player_input);
        }
        else
            cout<<"Wrong Guess ("<<player_input<<"). Number was: ("<<computer_input<<")\n";
        if(check(player)){
            show_board(player,cpu);
            break;
        }
        show_board(player,cpu);

        computer_input=getRandom();
        cout<<"\nGive a number for Computer to guess(1-5)(Enter -1 to quit): ";
        cin>>player_input;
        while((player_input<1||player_input>5)&&player_input!=-1){
            cout<<"\n!!Enter a number between (1-5)!!(Enter -1 to quit): ";
            cin>>player_input;
        }
        if(player_input==-1)
           exit(0);
        system("CLS");
        cout<<"\n\n";
        if(player_input==computer_input){
            cout<<"Computer Guessed Correct("<<player_input<<"). Computer moves "<<player_input<<" steps.\n";
            cpu.update(player_input);
        }
        else
            cout<<"Computer Guessed Wrong ("<<computer_input<<"). Number was: ("<<player_input<<")\n";
        flag=check(cpu);
        show_board(player,cpu);        
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
    play_game(player,cpu);
    cout<<"Enter 1 to play again or anything else to quit: ";
    cin>>choice;
    if(choice==1)
        play_game(player,cpu);
    return 0;
}
