#include <iostream>
#include <fstream>

using namespace std;

struct mytype {
    int a;
    int b;
};

int main() {
    cout << "Hello, World!" << endl;

    ofstream outfile;
    outfile.open("file.txt", ios::out | ios::trunc );
    outfile << "WOW";

    ifstream infile;
    infile.open("file.txt", ios::in);
    char line[10];
    infile >> line;
    cout << line;

    ofstream osf;
    osf.open("out.box", ios::out | ios::binary);
    mytype obj;
    obj.a = 10;
    obj.b = 20;
    osf.write((char*)&obj, sizeof(obj));
    long putptr = osf.tellp();
    cout << putptr;

    ifstream isf;
    isf.open("out.box", ios::in | ios::binary);
    mytype newobj;
    isf.read((char*)&newobj, sizeof(obj));
    cout << endl;
    cout << obj.a << "  " << obj.b;
    long getptr = isf.tellg();
    cout << getptr;


    return 0;

}