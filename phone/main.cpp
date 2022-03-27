#include <iostream>
#include <string>
#include <vector>

class Number{
    std::string name;
    std::string num;
public:
    void setName(std::string n){
        name=n;
    }
    bool setNumber(std::string n){
        if((n.at(0)!='+')||(n.at(1)!='7')||(n.size()!=12)){
            return  false;
        }
        else{
            num=n;
            return true;
        }
    }
    std::string getName(){
        return name;
    }
    std::string getNumber(){
        return num;
    }
};

class Phone{
    Number number;
    std::vector<Number>numbers;
public:
    void add(){
        std::string n;
        std::cout<<"Enter name: ";
        std::cin>>n;
        number.setName(n);
        do {
            std::cout << "Enter number: ";
            std::cin >> n;
            number.setNumber(n);
            if(!number.setNumber(n)){
                std::cout<<"Incorrect number-";
            }
        }while(!number.setNumber(n));
        numbers.push_back(number);
    }
    void call(){
        std::string str;
        std::cout<<"Enter name: ";
        std::cin>>str;
        bool flag=false;
        for(auto & elem : numbers){
            if(elem.getName() == str){
                std::cout << "CALL to number: " << elem.getNumber() << std::endl;
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
            if(item.getName() == str){
                std::cout<<"Write: ";
                std::cin.ignore(100,'\n');
                std::getline(std::cin,str);
                std::cout << "SMS to " << item.getName() <<": "<< std::endl;
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
