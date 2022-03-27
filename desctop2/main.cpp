#include <iostream>

class Monitor {
    int widthMon = 30;
    int highMon = 15;
public:
    int getW(){
        return widthMon;
    }
    int getH(){
        return highMon;
    }
    void display(int x,int y,int width,int high){
        for(int i=0;i<highMon;i++){
            for(int j=0;j<widthMon;j++){
                if((i >= y) && (i < y + high) && (j>=x) && (j<x+width)){
                    std::cout<<"1 ";
                }
                else {
                    std::cout<<"0 ";
                }
            }
            std::cout<<std::endl;
        }
    }
};

class Window {
    int x=0;
    int y=0;
    int width=10;
    int high=10;
    Monitor monitor;
public:
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int getW(){
        return width;
    }
    int getH(){
        return high;
    }
    void setResize(int a,int b){
        if(a<0||b<0)return;
        if(a>monitor.getW())a=monitor.getW();
        if(b>monitor.getH())b=monitor.getH();
        if((x+a)>monitor.getW())x=monitor.getW()-a;
        if((y+b)>monitor.getH())y=monitor.getH()-b;
        width=a;
        high=b;
        std::cout<<"New size: width- "<<width<<" high- "<<high<<std::endl;
    }
    void setMove(int moveX,int moveY){
        if(x+moveX<0)x=0;
        if(y+moveY<0)y=0;
        if((x+moveX+width) >monitor.getW()) {
            x = (monitor.getW() - width);
        }
        else{
            x+=moveX;
        }
        if((y+moveY+high) >monitor.getH()){
            y=(monitor.getH()-high);
        }
        else{
            y+=moveY;
        }
        std::cout<<"New coordinates: x - "<<x<<" y - "<<y<<std::endl;
    }
};

int main() {
    std::string command;
    auto*monitor=new Monitor();
    auto*window=new Window();
    do{
        std::cout << "Enter command: ";
        std::cin>>command;
        if(command=="display"){
            monitor->display(window->getX(),window->getY(),window->getW(),window->getH());
        }
        else if(command=="resize"){
            int a,b;
            std::cout<<"Enter new width and high: ";
            std::cin>>a>>b;
            window->setResize(a,b);
        }
        else if(command=="move"){
            int x,y;
            std::cout<<"Enter coordinates remove: ";
            std::cin>>x>>y;
            window->setMove(x,y);
        }
    }while(command!="close");
    delete monitor;
    return 0;
}

