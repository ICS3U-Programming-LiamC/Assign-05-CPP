// Copyright (c) 2021 Liam Csiffary All rights reserved.
//
// Created by: Liam Csiffary
// Date: May June 8, 2021
// This program calculates the area and angles of a triangle, using
// Heron's formula, and cosine law

#include <iostream>
#include <cmath>


// this function find the semi perimeter for the area function
float SemiPerimeter(float sideASemi, float sideBSemi, float sideCSemi) {
    float semiPerimBeforeDiv;
    float semiPerimeter;

    semiPerimBeforeDiv = sideASemi + sideBSemi + sideCSemi;
    semiPerimeter = semiPerimBeforeDiv / 2;
    return semiPerimeter;
}


// this function find the area based on Heron's formula
float Area(float semiArea, float aArea, float bArea, float cArea) {
    float areaStep1;
    float areaStep2;
    float areaStep3;

    areaStep1 = semiArea * (semiArea - aArea);
    areaStep2 = areaStep1 * (semiArea - bArea) * (semiArea - cArea);
    areaStep3 = sqrt(areaStep2);
    return areaStep3;
}

// gets angle A
float AngleA(float lenA, float lenB, float lenC) {
    float powA;
    float powB;
    float powC;
    float angleA;

    // creates the squared numbers of the lengths
    powA = pow(lenA, 2);
    powB = pow(lenB, 2);
    powC = pow(lenC, 2);

    // uses cosine law to determine angle A
    angleA = (powC + powB - powA) / (2*lenB*lenC);
    angleA = acos(angleA);
    // turns it from radians into degrees
    angleA = angleA * (180/M_PI);
    // returns the angles
    return angleA;
}
// same as angleA
float AngleB(float lenA, float lenB, float lenC) {
    float powA;
    float powB;
    float powC;
    float angleB;

    powA = pow(lenA, 2);
    powB = pow(lenB, 2);
    powC = pow(lenC, 2);

    angleB = (powC + powA - powB) / (2*lenA*lenC);
    angleB = acos(angleB);
    angleB = angleB * (180/M_PI);

    return angleB;
}


// same as angleA
float AngleC(float lenA, float lenB, float lenC) {
    float powA;
    float powB;
    float powC;
    float angleC;

    powA = pow(lenA, 2);
    powB = pow(lenB, 2);
    powC = pow(lenC, 2);

    angleC = (powA + powB - powC) / (2*lenB*lenA);
    angleC = acos(angleC);
    angleC = angleC * (180/M_PI);

    return angleC;
}

// main function
int main() {
    std::cout << "Welcome, this program takes 3 side lengths of a ";
    std::cout << "triangle, then it calculates the area\n";
    // get sides and units
    std::string sideAStr;
    float sideA;
    std::string sideBStr;
    float sideB;
    std::string sideCStr;
    float sideC;
    std::string units;

    // defines all the other varaibles
    float semiPerim;
    float areaFinal;
    float angleA;
    float angleB;
    float angleC;
    // get sides
    std::cout << "What is side a: ";
    std::cin >> sideAStr;

    std::cout << "What is side b: ";
    std::cin >> sideBStr;

    std::cout << "What is side c: ";
    std::cin >> sideCStr;
    // get the units from the user
    std::cout << "What are your units: ";
    std::cin >> units;

    // make sure that they inputs are numbers
    try {
        // try to turn it into a integer
        sideA = std::stof(sideAStr);
        sideB = std::stof(sideBStr);
        sideC = std::stof(sideCStr);

        // call the funciton that will return the area and the angles
        semiPerim = SemiPerimeter(sideA, sideB, sideC);
        areaFinal = Area(semiPerim, sideA, sideB, sideC);
        angleA = AngleA(sideA, sideB, sideC);
        angleB = AngleB(sideA, sideB, sideC);
        angleC = AngleC(sideA, sideB, sideC);

        // prints the results to the user
        std::cout << "Your area is " << areaFinal << units << "^2\n";
        std::cout << "∠A is " << angleA << "°\n";
        std::cout << "∠B is " << angleB << "°\n";
        std::cout << "∠C is " << angleC << "°\n";

    // if could not turn into integer
    } catch (std::invalid_argument) {
        std::cout << "All numbers must be real numbers";
    }
}
