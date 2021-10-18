#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    string filename("../../../Proj/buffers/cubeVerts.buf");

    {
        ofstream f(filename, ios::binary);
        float x = 0.0, y = 0.0, z = -0.5;
        f.write((char*)&x, sizeof(x));
        f.write((char*)&y, sizeof(y));
        f.write((char*)&z, sizeof(z));
        // normals
        f.write((char*)0, sizeof(x) * 3);
        // text coord
        f.write((char*)0, sizeof(x) * 3);

        x = 0.0, y = 0.5, z = 0.5;
        f.write((char*)&x, sizeof(x));
        f.write((char*)&y, sizeof(y));
        f.write((char*)&z, sizeof(z));
        // normals
        f.write((char*)0, sizeof(x) * 3);
        // text coord
        f.write((char*)0, sizeof(x) * 3);

        x = 0.0, y = 0.0, z = 0.0;
        f.write((char*)&x, sizeof(x));
        f.write((char*)&y, sizeof(y));
        f.write((char*)&z, sizeof(z));
        // normals
        f.write((char*)0, sizeof(x) * 3);
        // text coord
        f.write((char*)0, sizeof(x) * 3);


        f.close();
    }

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