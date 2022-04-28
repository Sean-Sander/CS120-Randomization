#include <iostream>
#include "RandomizingVector.h"
#include "Balloon.h"

using namespace std;

//helper function to get factorial
int factorial(int n);

/*
 * Tests the shuffling functions we made by seeing how many times the original
 * vector repeats in n! times where n is the amount of items in the RandomizingVector
 * Params: ref to RandomizingVector of Balloons vec to test, int repeats for how many times to do the test
 * to get the average, int choice for which shuffle to use
 * Returns: none
 */
void shuffleTest(RandomizingVector<Balloon> &vec, int repeats, int choice);

int main() {
    //create a RandomizingVector with different Balloons
    RandomizingVector<Balloon> ourVector;
    for (int i = 0; i < 10; i++) {
        ourVector.add(Balloon(i));
    }

    //WARNING THESE TAKE FOREVER TO RUN
    //vincents method
    shuffleTest(ourVector, 5, 0);
    //davids method
    shuffleTest(ourVector, 5, 1);
    //alexs method
    shuffleTest(ourVector, 5, 2);
    //seans method
    shuffleTest(ourVector, 5, 3);

    return 0;
}

int factorial(int n) {
    if (n == 1)
        return n;
    else {
        return n * factorial(n-1);
    }
}

void shuffleTest(RandomizingVector<Balloon> &vec, int repeats, int choice) {
    //make a copy of the vector
    RandomizingVector<Balloon> vec2 = vec;
    //int to store amount of occurrences
    int occurrences;
    //float to store average occurrences
    float avgOccurrences = 0;
    //variables in nested loops
    int j;
    //variables for timers
    std::chrono::high_resolution_clock::time_point start; //for start time
    std::chrono::high_resolution_clock::time_point end; //for end time
    std::chrono::duration<double> total; //for total time

    //big loop for thorough testing based on repeats amount
    start = std::chrono::high_resolution_clock::now(); //start timer
    for (int i = 0; i < repeats; ++i) {
        //0 is vincent
        if (choice == 0) {
            //reset occurrences
            occurrences = 0;
            //shuffle vec and compare it to vec2 to see how many times it occurs
            for (j = 0; j < factorial(vec.getSize()); ++j) {
                vec.shuffleVlai();
                if (vec == vec2)
                    occurrences++;
            }
            avgOccurrences += occurrences;
        }

        //1 is David
        else if (choice == 1) {
            //reset occurrences
            occurrences = 0;
            //shuffle vec and compare it to vec2 to see how many times it occurs
            for (j = 0; j < factorial(vec.getSize()); ++j) {
                vec.shuffleDmelkumo();
                if (vec == vec2)
                    occurrences++;
            }
            avgOccurrences += occurrences;
        }

        //2 is Alex
        else if (choice == 2) {
            //reset occurrences
            occurrences = 0;
            //shuffle vec and compare it to vec2 to see how many times it occurs
            for (j = 0; j < factorial(vec.getSize()); ++j) {
                vec.shuffleAmtownse();
                if (vec == vec2)
                    occurrences++;
            }
            avgOccurrences += occurrences;
        }

        //3 is Sean
        else if (choice == 3) {
            //reset occurrences
            occurrences = 0;
            //shuffle vec and compare it to vec2 to see how many times it occurs
            for (j = 0; j < factorial(vec.getSize()); ++j) {
                vec.shuffleSsander();
                if (vec == vec2)
                    occurrences++;
            }
            avgOccurrences += occurrences;
        }
        //reset vec to try again
        vec = vec2;
    }
    end = std::chrono::high_resolution_clock::now(); //end timer
    total = std::chrono::duration_cast<std::chrono::duration<double>>(end - start); //get total

    //get average occurrences
    avgOccurrences /= repeats;
    //say this number is good or bad
    cout << "Randomization Method:           ";
    if (choice == 0)
        cout << "Vincent's" << endl;
    else if (choice == 1)
        cout << "David's" << endl;
    else if (choice == 2)
        cout << "Alex's" << endl;
    else if (choice == 3)
        cout << "Sean's" << endl;
    cout << "Number of Repeats:              " << repeats << endl;
    cout << "Average number of occurrences:  " << avgOccurrences << endl;
    cout << "Total number of permutations:   " << factorial(vec.getSize()) << endl;
    cout << "Average time taken (seconds):   " << total.count() / repeats << endl;

}