#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

string cubeFilename("../../../Proj/buffers/cubeVerts.buf");
ofstream cub(cubeFilename, ios::binary | ios::out);
string cylinderFilename("../../../Proj/buffers/cylinderVerts.buf");
ofstream cyl(cylinderFilename, ios::binary | ios::out);
string sphereFilename("../../../Proj/buffers/sphereVerts.buf");
ofstream sph(sphereFilename, ios::binary | ios::out);

void drawPoint(float x, float y, float z, ostream fout)
{
    char three0Floats[4 * 3] = { 0 };
    char two0Floats[4 * 2] = { 0 };

    // points
    fout.write((char*)&x, sizeof(x));
    fout.write((char*)&y, sizeof(y));
    fout.write((char*)&z, sizeof(z));

    // normals
    fout.write(three0Floats, sizeof(three0Floats));

    // texture coord
    fout.write(two0Floats, sizeof(two0Floats));
}

int drawPlane(float points[4][3], ostream &fout)
{
    char three0Floats[4 * 3] = { 0 };
    char two0Floats[4 * 2] = { 0 };

    int drawPointOrder[6] = { 0, 1, 2, 2, 3, 0 };

    for (int pointNum = 0; pointNum < 6; pointNum++)
    {
        int coord = drawPointOrder[pointNum];

        // points
        fout.write((char*)&points[coord][0], sizeof(points[coord][0]));
        fout.write((char*)&points[coord][1], sizeof(points[coord][1]));
        fout.write((char*)&points[coord][2], sizeof(points[coord][2]));

        // normals
        fout.write(three0Floats, sizeof(three0Floats));

        // texture coord
        fout.write(two0Floats, sizeof(two0Floats));
    }

    return 1;
}

int main()
{
    if (!cub.is_open() || !cyl.is_open() || !sph.is_open())
    {
        cout << "Failed to open file." << endl;
    }

    // Manual cube
    float points[4][3] = {
    {1, 1, 1},
    {1, -1, 1},
    {1, -1, -1},
    {1, 1, -1},
    };
    drawPlane(points, cub);
    float points2[4][3] = {
        {1, 1, -1},
        {1, -1, -1},
        {-1, -1, -1},
        {-1, 1, -1},
    };
    drawPlane(points2, cub);
    float points3[4][3] = {
        {-1, 1, -1},
        {-1, -1, -1},
        {-1, -1, 1},
        {-1, 1, 1},
    };
    drawPlane(points3, cub);
    float points4[4][3] = {
        {-1, 1, 1},
        {-1, -1, 1},
        {1, -1, 1},
        {1, 1, 1},
    };
    drawPlane(points4, cub);

    float points5[4][3] = {
    {1, 1, -1},
    {-1, 1, -1},
    {-1, 1, 1},
    {1, 1, 1},
    };
    drawPlane(points5, cub);
    float points6[4][3] = {
    {-1, -1, -1},
    {1, -1, -1},
    {1, -1, 1},
    {-1, -1, 1},
    };
    drawPlane(points6, cub);

    cout << "Drew cube to " << cubeFilename << endl;

    float pi = 3.1415926;

    // a lot of help from https://youtu.be/AmaC23gQCTw?t=424 (7:04)
    // sides of cylinder 
    for (float i = 0; i <= 2 * pi; i += pi/8)
    {
        float points[4][3] = {
        {1 * cos(i) - 0.25f * sin(i), 1, 0.25f * cos(i) + 1 * sin(i)},
        {1 * cos(i) - 0.25f * sin(i), -1, 0.25f * cos(i) + 1 * sin(i)},
        {1 * cos(i) + 0.25f * sin(i), -1, -0.25f * cos(i) + 1 * sin(i)},
        {1 * cos(i) + 0.25f * sin(i), 1, -0.25f * cos(i) + 1 * sin(i)},
        };
        drawPlane(points, cyl);
    }

    // top of cylinder
    for (float i = 0; i <= 2 * pi; i += pi/8)
    {
        float points[4][3] = {
        {1 * cos(i) + 0.25f * sin(i), 1, -0.25f * cos(i) + 1 * sin(i)},
        {-1 * cos(i) + 0.25f * sin(i), 1, -0.25f * cos(i) - 1 * sin(i)},
        {-1 * cos(i) - 0.25f * sin(i), 1, 0.25f * cos(i) - 1 * sin(i)},
        {1 * cos(i) - 0.25f * sin(i), 1, 0.25f * cos(i) + 1 * sin(i)},
        };
        drawPlane(points, cyl);
    }

    // bottom of cylinder
    for (float i = 0; i <= 2 * pi; i += pi / 8)
    {
        float points[4][3] = {
        {-1 * cos(i) + 0.25f * sin(i), -1, -0.25f * cos(i) - 1 * sin(i)},
        {1 * cos(i) + 0.25f * sin(i), -1, -0.25f * cos(i) + 1 * sin(i)},
        {1 * cos(i) - 0.25f * sin(i), -1, 0.25f * cos(i) + 1 * sin(i)},
        {-1 * cos(i) - 0.25f * sin(i), -1, 0.25f * cos(i) - 1 * sin(i)},
        };
        drawPlane(points, cyl);
    }

    cout << "Drew cylinder to " << cylinderFilename << endl;

    for(float j = 0; j <= 2 * pi; j += pi/8)
    {
        for (float i = 0; i <= 2 * pi; i += pi/8)
        {
            float points[4][3] = {
            {1 * cos(i) - 0.25f * sin(i), 0.25f, 0.25f * cos(i) + 1 * sin(i)},
            {1 * cos(i) - 0.25f * sin(i), -0.25f, 0.25f * cos(i) + 1 * sin(i)},
            {1 * cos(i) + 0.25f * sin(i), -0.25f, -0.25f * cos(i) + 1 * sin(i)},
            {1 * cos(i) + 0.25f * sin(i), 0.25f, -0.25f * cos(i) + 1 * sin(i)},
            };
            // I know this is kinda weird but I didn't want to deal with copying
            // arrays in c++ and since I'm only running this script once, I
            // just copy-pasted what's above
            float newPoints[4][3] = {
            {1 * cos(i) - 0.25f * sin(i), 0.25f, 0.25f * cos(i) + 1 * sin(i)},
            {1 * cos(i) - 0.25f * sin(i), -0.25f, 0.25f * cos(i) + 1 * sin(i)},
            {1 * cos(i) + 0.25f * sin(i), -0.25f, -0.25f * cos(i) + 1 * sin(i)},
            {1 * cos(i) + 0.25f * sin(i), 0.25f, -0.25f * cos(i) + 1 * sin(i)},
            };

            newPoints[0][1] = points[0][1] * cos(j) - points[0][2] * sin(j);
            newPoints[1][1] = points[1][1] * cos(j) - points[1][2] * sin(j);
            newPoints[2][1] = points[2][1] * cos(j) - points[2][2] * sin(j);
            newPoints[3][1] = points[3][1] * cos(j) - points[3][2] * sin(j);

            newPoints[0][2] = points[0][2] * cos(j) + points[0][1] * sin(j);
            newPoints[1][2] = points[1][2] * cos(j) + points[1][1] * sin(j);
            newPoints[2][2] = points[2][2] * cos(j) + points[2][1] * sin(j);
            newPoints[3][2] = points[3][2] * cos(j) + points[3][1] * sin(j);

            drawPlane(newPoints, sph);
        }
    }

    cout << "Drew sphere to " << sphereFilename << endl;

    cub.close();
    cyl.close();
    sph.close();
}