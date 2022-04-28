//
// Created by Alexander Townsend on 3/16/21.
//

#ifndef RANDOMIZATION_RANDOMIZINGVECTOR_H
#define RANDOMIZATION_RANDOMIZINGVECTOR_H

#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <ctime>

template<typename T>
class RandomizingVector{
private:
    //vector of template type T that we will be altering
    std::vector<T> ourVector;

public:
    /*
     * Constructor
     * Initializes ourVector to the one passed in
     * Params: a vector of template type T to set to ourVector
     */
    RandomizingVector(std::vector<T> ourVector) : ourVector(ourVector){

    }

    /*
     * Copy Constructor
     * Copies the vector in vec to ourVector
     * Params: ref to RandomizingVector vec to copy from
     */
    RandomizingVector(RandomizingVector &vec) {
        ourVector = vec.ourVector;
    }

    /*
     * Default Constructor
     * Sets it according to compiler defaults
     */
    RandomizingVector<T>()=default;

    /*
     * Adds an object to the vector
     * Params: template type newItem to be added
     * Returns: none
     */
    void add(T newItem){
        ourVector.push_back(newItem);
    }

    /*
     * Shuffles vector using the rand function
     * Picks a random index and swaps values
     * Params: none
     * Returns: vector of template type T
     */
    std::vector<T> shuffleVlai(){
        srand(time(0));
        for (int i = 0; i < ourVector.size(); i++){
            // Getting a random index
            int randomIndex = rand() % ourVector.size();
            // Swapping the two values
            T temporary = ourVector[i];
            ourVector[i] = ourVector[randomIndex];
            ourVector[randomIndex] = temporary;
        }
        return ourVector;
    }

    /*
     * Shuffles the vector using time and picking
     * random indices to make a shuffled vector
     * Params: none
     * Returns: vector of template type T which is also the field ourVector
     */
    std::vector<T> shuffleDmelkumo() {
        //create a new vector
        std::vector<T> ourTempVector;
        //create variable to store duration
        std::chrono::system_clock::duration currTime;
        //create variable to store time in milliseconds
        long totalTime;
        //create an int for index
        long randomIndex;

        while (ourVector.size() > 0) {
            //get a random number
            //get current time since epoch
            currTime = std::chrono::system_clock::now().time_since_epoch();
            //convert to milliseconds
            totalTime = currTime / std::chrono::milliseconds(1);

            //get a random index for the vector
            randomIndex = totalTime % ourVector.size();

            //put the number into the 2nd vector
            ourTempVector.push_back(ourVector[randomIndex]);
            //remove it from the original vector
            ourVector.erase(ourVector.begin() + randomIndex);
        }

        //set ourVector = to ourTempVector to modify the original and return it
        ourVector = ourTempVector;
        return ourVector;
    }

    /*
     * Shuffles the vector using a new vector of randomly assorted indices to
     * relocate original elements to
     * Params: none
     * Returns: vector of template type / modified ourVector
     */
    std::vector<T> shuffleSsander() {
        std::vector<T> tempVec;
        std::vector<int> newIndices(ourVector.size(), -1);
        uint64_t seed = 2*(std::chrono::system_clock::now().time_since_epoch().count())+1;
        uint64_t x = 0, w = 0;
        uint32_t newIndex;
        // Modified version of Von Neumann's middle square method
        for (int i = 0; i < newIndices.size(); i++) {
            do {
                x *= x;
                w += seed;
                x += w;

                newIndex = (x >> 32) | (x << 32);
                newIndex = newIndex % ourVector.size();
            }
            while (std::find(newIndices.begin(), newIndices.end(), newIndex) != newIndices.end());
            newIndices[i] = (int)newIndex;
        }
        for (int i = 0; i < ourVector.size(); i++) {
            tempVec.push_back(ourVector[newIndices[i]]);
        }
        ourVector.erase(ourVector.begin(), ourVector.end());
        ourVector = tempVec;
        return ourVector;
    }

    /*
     * Shuffles using equation to create a random
     * Params: none
     * Returns: vector of template type T
     */
    std::vector<T> shuffleAmtownse(){
        int randomFirst;
        unsigned static int random = randomFirst;
        //std::cout << random << std::endl;
        for (int i = 0; i < ourVector.size() * 5; i++){
            T temp = ourVector[i % ourVector.size()];
            ourVector[i % ourVector.size()] = ourVector[random % ourVector.size()];
            ourVector[random % ourVector.size()] = temp;
            random = (random * 37 % 89) + random * random;
            //std::cout << random << std::endl;
        }
        return ourVector;
    }

    /*
     * Returns index of object if found, otherwise returns -1
     * Params: template type item to look for
     * Returns: int index of where the item is or -1
     */
    int find(T item){
        //loop through each item to check
        for (int i = 0; i < ourVector.size(); i++) {
            //if it is the same, return the index
            if (ourVector[i] == item) {
                return i;
            }
        }

        return -1;
    }

    /*
     * Sorts the vector
     * Params/Returns: none
     */
    void sort(){
        //declare nested variables
        int j;
        T temp;
        //loop through and shift the items until theyre sorted
        for (int i = 0; i < ourVector.size() - 1; i++){
            for (j = i+1; j < ourVector.size(); j++){
                if (ourVector[i] > ourVector[j]){
                    temp = ourVector[j];
                    ourVector[j] = ourVector[i];
                    ourVector[i] = temp;
                }
            }
        }
    }

    /*
     * Returns the size of ourVector
     * Params: none
     * Returns: size/amount of elements in ourVector field
     */
    int getSize() {
        return ourVector.size();
    }

    /*
     * << Operator
     * Prints each item in the vector
     * Params: ref to ostream outs, the RandomizingVector to be printed
     * Returns: ref to ostream that has the printed info
     */
    friend std::ostream& operator << (std::ostream& outs, const RandomizingVector &ourRandomizorVector) {
        for (int i = 0; i < ourRandomizorVector.ourVector.size(); ++i) {
            //add comma before unless its the first item
            if (i != 0) {
                outs << ", ";
            }
            outs << ourRandomizorVector.ourVector[i];
        }
        outs << std::endl;
        return outs;
    }

    /*
     * == Operator
     * Checks if all the items from both vectors are the same at the same indices
     * Params: ref to RandomizingVector of template type lhs, ref to RandomizingVector of template type rhs to compare
     * Returns: bool whether or not they have the same objects at the same indices
     */
    friend bool operator == (const RandomizingVector<T> &lhs, const RandomizingVector<T> &rhs) {
        //make sure they're the same size
        if (lhs.ourVector.size() == rhs.ourVector.size()) {
            //loop through each one and compare
            for (int i = 0; i < lhs.ourVector.size(); ++i) {
                if (lhs.ourVector[i] != rhs.ourVector[i])
                    return false;
            }

            //if they're all the same, return true
            return true;
        }
        return false;
    }
};

#endif //RANDOMIZATION_RANDOMIZINGVECTOR_H
