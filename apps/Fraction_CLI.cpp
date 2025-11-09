#include "Fraction.h"
#include <iostream>
#include <sstream>
#include <string>


static bool eval_line(const std::string& line,Fraction& out){
    std::istringstream iss(line);
    Fraction a{},b{};
    char op;

    if(!(iss >> a >> op >> b))return false;
    switch (op) {
        case '+': out = a + b;return true;
        case '-': out = a - b;return true;
        case '/': out = a / b;return true;
        case '*': out = a * b;return true;
        default:return false;

    }

}



int main(int argc,char* argv[]){
    using std::cout,std::cin;

    if(argc >= 2){
        std::ostringstream joined;
        for(int i =1; i < argc; ++i){
            if(i > 1)
                joined << ' ';
            joined << argv[i];
        }
        Fraction result{};
        if(!(eval_line(joined.str(),result))){
            std::cerr << "Invalid Expression. Example: 3/4 + 5/6\n";
            return 1;
        }
        std::cout <<"= "<<result<<"\n";
        return 0;
    }

    cout<<"Enter your Expression. (e.g. 3/4 + 2/5). Type 'exit' to quit.\n";
    std::string line;
    while(true){
        cout<< "> ";
        if(!std::getline(cin,line))break;
        if(line == "exit" || line == "quit")break;
        if(line.empty())continue;

        Fraction result{};
        try {
            if(!eval_line(line,result)){
                std::cerr << "Invalid expression. Try: a/b + c/d\n";
                continue;
            }
            std::cout<<"= "<<result<<"\n";
        } catch (const std::exception& e) {
            std::cerr<<"Error: "<<e.what()<<"\n";
            
        }
    }
    return 0;
}