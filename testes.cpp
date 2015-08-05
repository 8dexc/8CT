#include <iostream>
#include <fstream>
#include <string>
/*
int main()
{
    using namespace std;
    
    string BUFFER;
    ifstream inf("dyb.txt", ios::binary);
    ofstream outf("lmao.txt", ios::binary);

    if(!inf)
    {
        cerr << "ERROR OPENING INFILE" << endl;
        exit(3);
    }
    if(!outf)
    {
        cerr << "ERROR OPENING OUTFILE" << endl;
        exit(2);
    }

    while(inf)
    {
        getline(inf, BUFFER);
        outf << BUFFER << endl;
    }

    inf.close();
    outf.close();
    
}
*/

int main()
{
    using namespace std;
    unsigned int product = 0xc * 0x8de;
    cout << hex << product << endl;
    
    char c1 = 0x6a;
    char c2 = 0x68;
    cout << c1 << c2 << endl;

}
