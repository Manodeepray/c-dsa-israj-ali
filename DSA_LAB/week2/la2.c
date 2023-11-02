#include <stdio.h>
#include <math.h>

// Define the structure to store the coordinates of a point
struct Point {
    int x;
    int y;
};

// Function to calculate the area of a triangle given the coordinates of its vertices
float calculate_area(struct Point A, struct Point B, struct Point C) {
    // Calculate the lengths of the sides of the triangle
    float AB = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    float BC = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
    float CA = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2));

    // Calculate the semiperimeter of the triangle
    float s = (AB + BC + CA) / 2;

    // Calculate the area of the triangle using Heron's formula
    float area = sqrt(s * (s - AB) * (s - BC) * (s - CA));

    return area;
}

// Get the last six digits of the roll number
int roll_number = 1234567890;
int last_six_digits = roll_number % 1000000;

// Create the points A, B, and C using the last six digits of the roll number
struct Point A = {last_six_digits / 100000, (last_six_digits % 100000) / 10000};
struct Point B = {(last_six_digits % 10000) / 1000, (last_six_digits % 1000) / 100};
struct Point C = {(last_six_digits % 1000) / 100, last_six_digits % 100};

// Calculate the area of the triangle
float area = calculate_area(A, B, C);

// Print the area of the triangle
printf("The area of the triangle is %f\n", area);