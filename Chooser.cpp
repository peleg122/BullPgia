//
// Created by amir on 4/18/19.
//

#include "Chooser.hpp"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;
namespace bullpgia{

    string bullpgia::Chooser::choose(uint length){
        string numberChosen;

        //initializing random number
        int item[10] = {0,1,2,3,4,5,6,7,8,9},r;
        srand(time(NULL));
        for(int x=length; x>0; x--){
            r = rand()%x;
            cout << item[r] << "\t";
        }

        for(int i=0; i<length; i++)
            numberChosen += item[i];


        return numberChosen;
    }
}