//
// Created by Alexander Townsend on 3/16/21.
//

#include "Balloon.h"

Balloon::Balloon(int helium){
    if (helium > 0) {
        filled = true;
        this->helium = helium;
    }else {
        filled = false;
        this->helium = 0;
    }
    color = colorless;
}
Balloon::Balloon(int helium, balloonColor color){
    setHelium(helium);
    this->color = color;
}
bool Balloon::makeItGoDown(){
    if (helium > 0) {
        helium = 0;
        filled = false;
        return true;
    }
    return false;
}
void Balloon::setHelium(int helium){
    if (helium>0) {
        this->helium = helium;
    }else {
        this->helium = 0;
    }
    filled = helium > 0;
}
void Balloon::setColor(balloonColor colour){
    color = colour;
}
int Balloon::getHelium(){
    return helium;
}
bool Balloon::getFilled(){
    return filled;
}

std::ostream& operator << (std::ostream& outs, const Balloon &ourBalloon){
    outs << ourBalloon.helium;
    outs << ((ourBalloon.filled)? "F" : "E" );
    return outs;
}

bool operator == (const Balloon &lhs, const Balloon &rhs){
    return lhs.helium == rhs.helium;
}

bool operator != (const Balloon &lhs, const Balloon &rhs){
    return lhs.helium != rhs.helium;
}

bool operator < (const Balloon &lhs, const Balloon &rhs){
    return lhs.helium < rhs.helium;
}

bool operator > (const Balloon &lhs, const Balloon &rhs){
    return lhs.helium > rhs.helium;
}

bool operator <= (const Balloon &lhs, const Balloon &rhs){
    return lhs.helium <= rhs.helium;
}

bool operator >= (const Balloon &lhs, const Balloon &rhs){
    return lhs.helium >= rhs.helium;
}