#include <sstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <array>

using namespace std;

const int ROW = 9;
const int length = 8;
const int minimal = 11111111;
const int maximal = 44444444;
const int digit = 10;
namespace ariel{
    // string options[][4]
    
    array<array<string,4>,ROW> options = {{
        {"_===_"," ___ \n .....","  _  \n  /_\\ "," ___ \n (_*_)"},  //H
        {",",".","_"," "}, //N
        {".","o","O","-"},//LR
        {" ","\\"," "," "},//X TOP 
        {"<"," ","/"," "},//X BOTTOM
        {" ","/"," "," "},//Y TOP
        {">"," ","\\"," "},//Y BOTTOM
        {" : ","] [","> <","   "},//T
        {" : ","\" \"","___","   "}//B
    }};
    bool checkInput(int snow){
        int test = 0;
        if(snow >= minimal && snow <= maximal){
            for(int i = 0; i < length; i++){//O(n)
                test = snow%digit;
                if(test!=1 && test!=2 && test!=3 && test!=4){
                    return false;
                }
                snow = snow/digit;
            }
            return true;
        }
        return false;
    }
    //HNLRXYTB
    std::string snowman(int snow){
    
    if (!(checkInput(snow))){
        throw invalid_argument{"The input must be  from 1 to 4! and have 8 digits\n"};
    }
    // int snowm[length];
    array<int, length> snowm = {0};
    for(int i = 0; i < length; i++){//O(n)
        snowm.at(i) = (snow%digit)-1;
        snow = snow/digit;
        //cout << snowm[i] << "\n";
    }
    /*
    HHHHH
    HHHHH
    Xt(LNR)Yt1
    Xb(TTT)Yb
    (BBB)
    */
    const int H = snowm[7];
    const int N = snowm[6];
    const int L = snowm[5];
    const int R = snowm[4];
    const int X = snowm[3];
    const int Y = snowm[2];
    const int T = snowm[1];
    const int B = snowm[0];
    const int five = 5;
    const int six = 6;
    const int seven = 7;

    ostringstream shlomo;
    
    shlomo << " " << options[0][H] << endl
        << options[3][X] << "(" << options[2][L] << options[1][N] << options[2][R]<< ")" << options[five][Y] <<endl
        << options[4][X] << "(" << options[seven][T] << ")" << options[six][Y] <<endl
        << " (" << options[length][B] << ")" <<endl;
    
    string david = shlomo.str();
    // cout << david << endl;
    return david;
    }
}