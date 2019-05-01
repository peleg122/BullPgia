//
// Created by amir on 4/18/19.
//
#pragma once

#include "calculate.hpp"
#include <string>
using namespace std;

namespace bullpgia{
    class Chooser{

    private:

        string clientChoose;

    public:

        //length of clientChoose string
        uint length;

        //default constructor clientChoose string is empty
        Chooser(){
            this->clientChoose = "";
        }

        //constructor check if input is legal
        Chooser(const string& cho){
            if(cho.length()>0 && cho.length()<=10){
                this->clientChoose = cho;
            }
        }

        virtual string choose(uint length)=0;

        virtual ~Chooser(){}



    };
}