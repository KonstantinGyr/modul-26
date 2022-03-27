#include <iostream>

class Monitor{
    int widthMon=30;
    int highMon=15;
    struct Window{
        int x=0;
        int y=0;
        int width=10;
        int high=10;
    };
    Window win=Window();
  public:
    void display(){
        for(int i=0;i<highMon;i++){
            for(int j=0;j<widthMon;j++){
                if((i >= win.y) && (i < win.y + win.high) && (j>=win.x) && (j<win.x+win.width)){
                    std::cout<<"1 ";
                }
                else {
                    std::cout<<"0 ";
                }
            }
            std::cout<<std::endl;
        }
    }
    void setResize(int a,int b){
        if(a<0||b<0)return;
        if(a>widthMon)a=widthMon;
        if(b>highMon)b=highMon;
        if((win.x+a)>widthMon)win.x=widthMon-a;
        if((win.y+b)>highMon)win.y=highMon-b;
        win.width=a;
        win.high=b;
        std::cout<<"New size: width- "<<win.width<<" high- "<<win.high<<std::endl;
    }
    void setMove(int moveX,int moveY){
        if(win.x+moveX<0)win.x=0;
        if(win.y+moveY<0)win.y=0;
        if((win.x+moveX+win.width) >widthMon) {
            win.x = (widthMon - win.width);
        }
        else{
            win.x+=moveX;
        }
        if((win.y+moveY+win.high) >highMon){
            win.y=(highMon-win.high);
        }
        else{
            win.y+=moveY;
        }
        std::cout<<"New coordinates: x - "<<win.x<<" y - "<<win.y<<std::endl;
    }
};

int main() {
    std::string command;
    auto*monitor=new Monitor();
    do{
        std::cout << "Enter command: ";
        std::cin>>command;
        if(command=="display"){
            monitor->display();
        }
        else if(command=="resize"){
            int a,b;
            std::cout<<"Enter new width and high: ";
            std::cin>>a>>b;
            monitor->setResize(a,b);
        }
        else if(command=="move"){
            int x,y;
            std::cout<<"Enter coordinates remove: ";
            std::cin>>x>>y;
            monitor->setMove(x,y);
        }
    }while(command!="close");
    delete monitor;
    return 0;
}
