#include <iostream>
#include "Graph.h"

using namespace std;

/*
 * Input example:
 *      0  6  *  7  *
 *      *  0  3  8 -4
 *      * -2  0  *  *
 *      *  * -3  0  9
 *      2  *  7  *  0
 *      where   0 -> 1 = 6
 *              0 -> 3 = 7
 *              3 -> 2 = -3
 *              3 -> 4 = 9 ...
 * */

int main() {
    Graph g(5, 10, "K:\\Spbstu\\5term\\Parallel\\BF\\Cons\\input.txt");
    if (!g.getShortPathBF())
        g.showPath();
    else
        cout<<"Error: Negative loop"<<endl;
    return 0;
}