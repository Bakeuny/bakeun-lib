#include "iostream"
#include <stdlib.h>
using namespace std;

/*
   define algorithm interface in a base class 
   and implementations in derived classes
*/

class Algorithm
{
public:
    virtual int calculate(int a, int b) = 0;
};

class Addition:public Algorithm
{
public:
    int calculate(int a, int b){
        cout << "Addition operation is selected" << endl;
        cout << "operand a=" << a << ", ";
        cout << "operand b=" << b << endl;
        return a+b; 
    }
};

class Multiply:public Algorithm
{
public:
    int calculate(int a, int b){ 
        cout << "Multiply operation is selected" << endl;
        cout << "operand a=" << a << ", ";
        cout << "operand b=" << b << endl;
        return a*b; 
    }
};

class Power:public Algorithm
{
private:
    int calc_power(int a, int b){
        int temp = 1;
        for(int i = 0; i < b; i++){
            temp *= a;
        }
        return temp;
    }
public:
    int calculate(int a, int b){
        cout << "Power operation is selected" << endl;
        cout << "operand a=" << a << ", ";
        cout << "operand b=" << b << endl;
        return calc_power(a,b);
    }
};

class MyCalc{
private:
    Algorithm* operation;
public:
    MyCalc(){
        int condition;
        srand(time(0));
        condition = rand()%3;
        select_algorithm(condition);
    }
    void select_algorithm(int condition){
        if(operation != 0){ delete operation; }
        if(condition == 0){
            operation = new Addition();
        }
        else if(condition == 1){
            operation = new Multiply();
        }
        else if(condition == 2){
            operation = new Power();
        }
        else{
            operation = 0;
        }
    }
    int operate(int a, int b){
        if(operation == 0){
            cout << "Operation object is not initialized." << endl;
            return -1;
        }
        return operation->calculate(a, b);
    }
};

int main(int argc, char** argv)
{
    MyCalc* my_calc;
    my_calc = new MyCalc();
    int result = my_calc->operate(5,4);

    cout << "operation result: " << result << endl;
    return 0;
}

