/*
Given two rectangles and the coordinates of two points on the diagonals of each rectangle,
you have to calculate the area of the intersected part of two rectangles. its sides are parallel to OX and OY .
1.求矩形交叉面积的关键是认清，x和y都是，最大中的最小值，最小中的最大值是交叉区域的边界
2.利用max(x,0)实现交叉区域为空的情况，以此就可以解决问题

Input
Input The first line of input is 8 positive numbers which indicate the coordinates of four points that must be on each diagonal.
The 8 numbers are x1,y1,x2,y2,x3,y3,x4,y4.
That means the two points on the first rectangle are(x1,y1),(x2,y2);the other two points on the second rectangle are (x3,y3),(x4,y4).
Output
Output For each case output the area of their intersected part in a single line.accurate up to 2 decimal places.
Sample Input
1.00 1.00 3.00 3.00 2.00 2.00 4.00 4.00
5.00 5.00 13.00 13.00 4.00 4.00 12.50 12.50
Sample Output
1.00
56.25
*/
#include <iostream>
#include <algorithm> // For std::min and std::max
#include <iomanip>   // For std::fixed and std::setprecision
#include <cmath>     // For std::abs (though std::max handles non-overlap)

using namespace std;

// Define a structure to hold the standardized bounds of an axis-aligned rectangle.
// Xmin, Ymin represent the bottom-left corner.
// Xmax, Ymax represent the top-right corner.
struct Rectangle {
    double Xmin;
    double Ymin;
    double Xmax;
    double Ymax;
};

/**
 * @brief Standardizes the coordinates of a rectangle.
 * * Takes two diagonal points (x1, y1) and (x2, y2) and calculates the 
 * canonical min/max boundaries of the rectangle.
 * * @param x1 X-coordinate of the first diagonal point.
 * @param y1 Y-coordinate of the first diagonal point.
 * @param x2 X-coordinate of the second diagonal point.
 * @param y2 Y-coordinate of the second diagonal point.
 * @return Rectangle A standardized Rectangle structure.
 */
Rectangle createRectangle(double x1, double y1, double x2, double y2) {
    Rectangle r;
    r.Xmin = min(x1, x2);
    r.Xmax = max(x1, x2);
    r.Ymin = min(y1, y2);
    r.Ymax = max(y1, y2);
    return r;
}

/**
 * @brief Calculates the area of intersection between two axis-aligned rectangles.
 * * The intersection rectangle is determined by:
 * X_intersection_min = max(R1.Xmin, R2.Xmin)
 * X_intersection_max = min(R1.Xmax, R2.Xmax)
 * * If X_intersection_min >= X_intersection_max (or similarly for Y), there is no overlap.
 * * @param r1 The first rectangle.
 * @param r2 The second rectangle.
 * @return double The area of intersection, 0.0 if they do not overlap.
 */
double calculateIntersectionArea(const Rectangle& r1, const Rectangle& r2) {
    // 1. Calculate the intersection range along the X-axis
    double intersection_X_min = max(r1.Xmin, r2.Xmin);
    double intersection_X_max = min(r1.Xmax, r2.Xmax);

    // 2. Calculate the intersection range along the Y-axis
    double intersection_Y_min = max(r1.Ymin, r2.Ymin);
    double intersection_Y_max = min(r1.Ymax, r2.Ymax);

    // 3. Calculate the width and height of the intersection rectangle
    // If max <= min for either axis, the overlap is 0 (or negative, which means no overlap).
    double intersection_width = max(0.0, intersection_X_max - intersection_X_min);
    double intersection_height = max(0.0, intersection_Y_max - intersection_Y_min);

    // 4. The area is the product of the non-negative width and height
    return intersection_width * intersection_height;
}

int main() {
    // Variables to store the 8 input coordinates
    double x1, y1, x2, y2, x3, y3, x4, y4;

    // Use a while loop to handle multiple test cases (as suggested by the sample I/O)
    // We read all 8 coordinates at once.
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        
        // 1. Standardize Rectangle 1
        Rectangle rec1 = createRectangle(x1, y1, x2, y2);

        // 2. Standardize Rectangle 2
        Rectangle rec2 = createRectangle(x3, y3, x4, y4);

        // 3. Calculate the area of intersection
        double area = calculateIntersectionArea(rec1, rec2);

        // 4. Output the result formatted to 2 decimal places
        cout << fixed << setprecision(2) << area << endl;
    }

    return 0;
}