#include <stdio.h>
#include <iostream>
#include <string>
using std:: string;

class cardvalidator{
    public:
        int cardNum;
        int doubleEvenSum;
        int sumA = 0;
        int sumB = 0;
        int endNumber = 0

cardvalidator(int cardNum, int doubleEvenSum, int sumA, int sumB, int endNumber){
        cardNum = cardNum;
        doubleEvenSum = doubleEvenSum;
        sumA = sumA;
        sumB = sumB;
        endNumber = endNumber;
    };

int sumDoubles(int cardNum, int sumA){
        //take away the last digit of the card number becuase it is not needed for calculation
        //card nuber is now just the fits 15 digits now
        cardNum = cardNum/10;

    for (int i = 0; i < 8; i ++){
        //isolate the NEW last digit of the cardNumber
        endNumber = cardNum%10;
        //if the NEW last digit doubled is a two digit number 
        //add those two digits together
        if ((endNumber*2) > 9){
            endNumber = (endNumber / 10) + (endNumber % 10);
        }else{
            endNumber = endNumber*2;}
        //add the value of endNumber to sumA
        sumA = sumA + endNumber;
        //now get rid of two numbers becuase we are done with them
        //repeat the process of taking every second last number and adding that to the sum.
        cardNum = cardNum/10;
        cardNum = cardNum/10;
    }
    return sumA;
}

int sumOddNumbers(int cardNum, int sumB){
    for (int i = 0; i < 8; i ++){
    int lastNumber = cardNum%10;
    sumB = sumB + cardNum;
    cardNum = cardNum/100;
    }
    return sumB
}

int main(int cardNum) 
{
    //get input 
    std::cout << "Enter number to validate: ";
    std::cin >> cardNum;

    // 
    std::thread thread1(sumDoubles, cardNum, doubleEvenSum);
    std::thread thread2(sumOddNumbers, cardNum, doubleEvenSum); 
    return 0;
}

};
