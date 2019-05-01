//
// Created by amir on 4/18/19.
//


#pragma once

#include <vector>
#include "Guesser.hpp"
#include <iostream>

using namespace std;
namespace bullpgia{

    class SmartGuesser : public bullpgia::Guesser{

    private:
        //string clientGuess;
        //string bestGuess = " ";

    public:
        vector<string> AllPoss;
        string Last;
        uint length;
        //int arr[10] = {0,0,0,0,0,0,0,0,0,0};



        /*void setBestGuess(string newGuess){
            this->bestGuess = newGuess;
        }*/

       /* string getBestGuess(){
            return this->bestGuess;
        }*/

        SmartGuesser(){}

        /*SmartGuesser(const string& smart){
            //this->clientGuess = smart;
        }*/

        ~SmartGuesser(){}

        void learn(string reply)override ;

        void startNewGame(uint Length)override ;

        string guess()override ;

        void All();
        void remove(string guess, string answer);
        int Random(int n, int m);

    };

}