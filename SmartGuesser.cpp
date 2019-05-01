//
// Created by amir on 4/18/19.
//

#include "SmartGuesser.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "calculate.hpp"

using namespace std;

void bullpgia::SmartGuesser::learn(string reply) {
    /**
     *gets to reduce the pool of strings from the bad possibilities that would'nt give the same bulls and cows as last guess
     * learning takes it time at first run but after one call for remove it runs faster.. O(n)
     */
    remove(Last,reply);
}
void bullpgia::SmartGuesser::startNewGame(uint Length) {
    /**
     * @param Length sets the games settings for length of the string
     * @function All() creates the pool of all the strings to use 0000-9999 if the length is 4..
     */
    length=Length;
    if(!AllPoss.empty())
        AllPoss.clear();
    All();
    cout<<"Starting new game: "<<endl;
}

string bullpgia::SmartGuesser::guess() {
    /**
     * getting random guess from the pool we have
     * if the size equals 1 that's the last answer so we take it and win
     */
    if(AllPoss.size()>1){
            Last = AllPoss[Random(0,AllPoss.size())];
            if(Last.length()!=length){
                AllPoss.clear();
                All();
                Last = AllPoss[Random(0,AllPoss.size())];
            }
    }else{
        if(AllPoss[0].length()!=length){
            AllPoss.clear();
            All();
            Last = AllPoss[Random(0,AllPoss.size())];
        }else{
            Last = AllPoss[0];
        }
    }
    return Last;
}

void bullpgia::SmartGuesser::All() {
    /**
     * creates a pool of all the possibilities strings
     * we then delete the ones we dont need
     */
    for(int i=0;i<pow(10,length);i++){
        stringstream ss;
        ss << setw(length) << setfill('0') << i;
        string s = ss.str();
        this->AllPoss.push_back(s);
    }
}

void bullpgia::SmartGuesser::remove(string guess, string answer)/**
 *
 * @param guess is the last guess we had and we get replay from play.cpp so we eliminate the possibilities
 * that dont give us the same option as the bulls and cows as last guess
 * @param answer is the string "bulls,cows"
 * @param token is the string we take to see if it gives the same number of bulls and cows if not it will be removed
 */
{
    for (auto i= AllPoss.begin();i != AllPoss.end();i++){
        string token = *i;
        if (calculateBullAndPgia(token, guess) != answer)
        AllPoss.erase(i--);
    }
}



int bullpgia::SmartGuesser::Random(int n, int m) {
    /**
     * gives a random number in the range n -> m (rand() inside guess() did'nt work for some reason but bypassing it like that did the work..
     */
    return rand() % (m - n + 1) + n;
}

