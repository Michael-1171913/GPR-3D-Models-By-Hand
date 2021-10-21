#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

string filename("../../../Proj/buffers/cubeVerts.buf");
ofstream f(filename, ios::binary | ios::out);

// TODO: Returns the amount of bytes written
// TODO: convert points to struct and write that instead?
int drawPlane(float points[4][3])
{
    char three0Floats[4 * 3] = { 0 };
    char two0Floats[4 * 2] = { 0 };

    int drawPointOrder[6] = { 0, 1, 2, 2, 3, 0 };


    for (int pointNum = 0; pointNum < 6; pointNum++)
    {
        int coord = drawPointOrder[pointNum];

        // counter clockwise:
        // draw two highest first?, then the lowest of the 3?

        // points
        f.write((char*)&points[coord][0], sizeof(points[coord][0]));
        f.write((char*)&points[coord][1], sizeof(points[coord][1]));
        f.write((char*)&points[coord][2], sizeof(points[coord][2]));

        // normals
        f.write(three0Floats, sizeof(three0Floats));

        // texture coord
        f.write(two0Floats, sizeof(two0Floats));

        cout << "Writing vertex " << pointNum << endl;
    }

    return 1;
}

int main()
{
    if (!f.is_open())
    {
        cout << filename << " failed to open." << endl;
    }

    float points[4][3] = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 0, 0},
        {1, 0, 0},
    };
    drawPlane(points);

    // TODO make this draw counter clockwise
    float points2[4][3] = {
        {0, 1, -1},
        {0, 1, 0},
        {0, 0, 0},
        {0, 0, -1},
    };
    drawPlane(points2);

    f.close();

    //{
    //    ifstream f(filename, ios::binary);
    //    float x, y, z;
    //    f.read((char*)&x, sizeof(x));
    //    f.read((char*)&y, sizeof(y));
    //    f.read((char*)&z, sizeof(z));
    //    printf("pos0 value is (%.2f, %.2f, %.2f)\n", x, y, z);
    //    f.close();
    //}
}