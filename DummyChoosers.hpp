//
// Created by peleg on 17-Apr-19.
//

#ifndef EX4_DUMMYCHOOSERS_HPP
#define EX4_DUMMYCHOOSERS_HPP

#endif //EX4_DUMMYCHOOSERS_HPP
#pragma once
#include "Chooser.hpp"
using std::string;

/**
 * ConstantChooser is a chooser that always chooses the same string.
 */
class ConstantChooser: public bullpgia::Chooser {
    string myConstantString;
public:
    ConstantChooser(const string& constantString) { myConstantString = constantString; }
    string choose(uint length) override {
        return myConstantString;
    }
};

/**
 * RandomChooser is a chooser that chooses a random string.
 */
class RandomChooser: public bullpgia::Chooser {
    string choose(uint length) override;
};


