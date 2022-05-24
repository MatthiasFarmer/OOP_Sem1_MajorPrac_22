#include <SFML/Graphics.hpp>
#include <iostream>
#include "particle.h"
#include "gravitySource.h"

using namespace std;
using namespace sf;

// Testing the gravitySource class and its fucntions

int main(){

    std::cout << "Testing has commenced" << std::endl;

    // Testing the default constructor
    // Will test for position and mass
    {
        gravitySource A = gravitySource();
        if (A.get_mass() != 2000 || A.get_position() != Vector2f(900,500)){
            cout << "Error detected" << endl; 
        }
    }


    // Testing the defined constructor
    // Will test for Mass
    // First testing for Mass: 0's, decimals, large values
    {
        gravitySource A = gravitySource(Vector2f(500,500),0);
        if (A.get_mass() != 0){
            cout << "Error detected" << endl; 
        }
        gravitySource B = gravitySource(Vector2f(500,500),0.5);
        if (B.get_mass() != 0.5){
            cout << "Error detected" << endl; 
        }
        gravitySource C = gravitySource(Vector2f(500,500),10000);
        if (C.get_mass() != 10000){
            cout << "Error detected" << endl; 
        }
    }

    // Testing for Position
    // Testing 0's, decimals, large values, negatives
    {
        gravitySource A = gravitySource(Vector2f(0,0),100);
        if (A.get_position() != Vector2f(0,0)){
            cout << "Error detected" << endl; 
        }
        gravitySource B = gravitySource(Vector2f(0.1,0.1),100);
        if (B.get_position() != Vector2f(0.1,0.1)){
            cout << "Error detected" << endl; 
        }
        gravitySource C = gravitySource(Vector2f(100000,100000),100);
        if (C.get_position() != Vector2f(100000,100000)){
            cout << "Error detected" << endl; 
        }
        gravitySource D = gravitySource(Vector2f(-10,-10),100);
        if (D.get_position() != Vector2f(-10,-10)){
            cout << "Error detected" << endl; 
        }
    }

    // The above tests also test the get_position and get_mass functions


    // Testing set_position function
    // Will test 0's, negatives, large numbers, decimals
    {
        gravitySource A = gravitySource();
        A.set_position(0,0);
        if (A.get_position() != Vector2f(0,0)){
            cout << "Error detected" << endl; 
        }
        gravitySource B = gravitySource();
        B.set_position(0.1,0.1);
        if (B.get_position() != Vector2f(0.1,0.1)){
            cout << "Error detected" << endl; 
        }
        gravitySource C = gravitySource();
        C.set_position(100000,100000);
        if (C.get_position() != Vector2f(100000,100000)){
            cout << "Error detected" << endl; 
        }
        gravitySource D = gravitySource();
        D.set_position(-10,-10);
        if (D.get_position() != Vector2f(-10,-10)){
            cout << "Error detected" << endl; 
        }
    }


    return 0; 
}



