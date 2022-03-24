#include <iostream>
#include <vector>

class Player
{
    class Track
    {
      public:
          std::string name;
          std::string creation;
          int duration;
    };
    Track track1={"Sunny","12.5.2002",120};
    Track track2{"Yesterday","03.10.2012",115};
    Track track3={"Lagrange","22.02.2022",155};
    std::vector<Track> tracks ={ track1,track2,track3};
public:
    bool play(){
        std::string song ;
        std::cout<<"Enter song name: ";
        std::cin>>song;
        for(int i=0;i<tracks.size();i++){
            if(tracks[i].name==song){
             std::cout<<"Song: "<<tracks[i].creation<<" "<<tracks[i].duration<<std::endl;
             return true;
            }
        }
        std::cout<<"Not this song."<<std::endl;
        return false;
    }
    bool next (){
        int n=std::rand()%tracks.size();
        std::cout<<"Song: "<<tracks[n].name<<" "<<tracks[n].creation<<" "<<tracks[n].duration<<std::endl;
        return true;
    }

};

int main() {
    bool playNow= false;
    Player* player=new Player();
    std::string command;
    do {
        std::cout << "Enter command: ";
        std::cin>>command;
        if(command=="play"){
            if(playNow){
                continue;
            }
            else {
                playNow = player->play();
            }
        }
        else if(command=="pause"){
            if(playNow){
                std::cout<<"Pause"<<std::endl;
                playNow= false;
            }
        }
        else if(command=="next"){
            playNow= player->next();
        }
        else if(command=="stop"){
            if(playNow){
                std::cout<<"Stop"<<std::endl;
                playNow= false;
            }
        }
    } while (command!="exit");
    delete player;
    return 0;
}
