#include <iostream>
#include <string>
#include <vector>
#include <string>

class Phone
{
    class Number
    {
    public:
        std::string name;
        std::string num;
    };
    Number number1={"Ivan","+78637552773"};
    Number number2={"Peter","+76458675375"};
    Number number3={"Vlad","+77569784302"};
    Number number;
    std::vector<Number>numbers={number1,number2,number3};
public:
    void add(){
        bool ok;
        std::string n;
        std::cout<<"Enter name: ";
        std::cin>>number.name;
        do {
            std::cout << "Enter number: ";
            std::cin >> n;
            if((n.at(0)!='+')||(n.at(1)!='7')||(n.size()>12)){
                ok=false;
                std::cout<<"Incorrect number-";
            }
            else{
                ok=true;
            }
        }while(!ok);
        number.num=n;
        numbers.push_back(number);
    }
    void call(){
        std::string str;
        std::cout<<"Enter name: ";
        std::cin>>str;
        bool flag=false;
        for(auto & elem : numbers){
            if(elem.name == str){
                std::cout << "CALL to number: " << elem.num << std::endl;
                flag=true;
                break;
            }
        }
        if(!flag){
            std::cout<<"No such name. ";
        }
    }
    void sms(){
        std::string str;
        std::cout<<"Enter name:";
        std::cin>>str;
        bool flag=false;
        for(auto & item : numbers ){
            if(item.name == str){
                std::cout<<"Write: ";
                std::cin.ignore(100,'\n');
                std::getline(std::cin,str);
                std::cout << "SMS to " << item.name <<": "<< std::endl;
                std::cout<<str<<std::endl;
                flag=true;
                break;
            }
        }
        if(!flag){
            std::cout<<"No such name.";
        }
    }
};
int main() {
    auto* phone=new Phone();
    std::string command;
    do {
        std::cout << "Enter command: ";
        std::cin>>command;
        if(command=="add"){
            phone->add();
        }
        else if(command=="call"){
            phone->call();
        }
        else if(command=="sms"){
            phone->sms();
        }
    } while (command!="exit");
    delete phone;
    return 0;
}
