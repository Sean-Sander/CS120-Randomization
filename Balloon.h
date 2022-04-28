//
// Created by Alexander Townsend on 3/16/21.
//

#ifndef RANDOMIZATION_BALLOON_H
#define RANDOMIZATION_BALLOON_H

#include <iostream>

class Balloon{
    //a public enum representing the balloon's color so it can be accessed outside
public:
    enum balloonColor {colorless, red, blue, white};
private:
    //amount of helium
    int helium;
    //whether or not the balloon has helium
    bool filled;
    //the color of the balloon
    balloonColor color;

public:
    /*
     * Constructor
     * Sets color to colorless, helium, and filled
     * Params: int helium to set helium to
     */
    Balloon(int helium);

    /*
     * Constructor
     * Sets color, helium, and filled
     * Params: int helium for how much helium, balloonColor color for the color
     */
    Balloon(int helium, balloonColor color);

    /*
     * Sets helium to 0 and filled to false if there is any helium
     * Params: none
     * Returns: bool of whether or not it was able to make it go down
     */
    bool makeItGoDown();

    /*
     * Sets the helium if the parameter is above 0 and updates filled
     * Params: int helium for what to set it to
     * Returns: none
     */
    void setHelium(int helium);

    /*
     * Sets the color of the balloon to parameter colour
     * Params: balloonColor colour for the color to set it to
     * Returns: none
     */
    void setColor(balloonColor colour);

    /*
     * Returns the helium value
     * Params: none
     * Returns: int helium field
     */
    int getHelium();

    /*
     * Returns whether or not the balloon is filled
     * Params: none
     * Returns: bool filled field
     */
    bool getFilled();

    /*
     * << Operator
     * Params: ref to ostream outs, ref to Balloon ourBalloon to be printed
     * Returns: ref to outs with the info
     */
    friend std::ostream& operator << (std::ostream& outs, const Balloon &ourBalloon);

    /*
     * == Operator
     * Params: ref to Balloon lhs, ref to Balloon rhs
     * Returns: bool whether or not they're equal
     */
    friend bool operator == (const Balloon &lhs, const Balloon &rhs);

    /*
     * != Operator
     * Params: ref to Balloon lhs, ref to Balloon rhs
     * Returns: bool whether or not they're not equal
     */
    friend bool operator != (const Balloon &lhs, const Balloon &rhs);

    /*
     * < Operator
     * Params: ref to Balloon lhs, ref to Balloon rhs
     * Returns: bool whether or not lhs < rhs
     */
    friend bool operator < (const Balloon &lhs, const Balloon &rhs);

    /*
     * > Operator
     * Params: ref to Balloon lhs, ref to Balloon rhs
     * Returns: bool whether or not lhs > rhs
     */
    friend bool operator > (const Balloon &lhs, const Balloon &rhs);

    /*
     * <= Operator
     * Params: ref to Balloon lhs, ref to Balloon rhs
     * Returns: bool whether or not lhs <= rhs
     */
    friend bool operator <= (const Balloon &lhs, const Balloon &rhs);

    /*
     * >= Operator
     * Params: ref to Balloon lhs, ref to Balloon rhs
     * Returns: bool whether or not lhs >= rhs
     */
    friend bool operator >= (const Balloon &lhs, const Balloon &rhs);
};
#endif //RANDOMIZATION_BALLOON_H
