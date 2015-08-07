/*
*    ZigZag Conversion
*   
* 思路：控制步长step
*     
*    @date 2015/8/7
*
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

string convert(string s, int nRows) {
    //The cases no need to do anything
    if (nRows<=1 || nRows>=s.size()) return s;
     
    vector<string> r(nRows);
    int row = 0;
    int step = 1;
    for(int i=0; i<s.size(); i ++) {
        if (row == nRows-1) step = -1;
        if (row == 0) step = 1;
        r[row] += s[i];
        row += step;
    }
    
    string result;
    for (int i=0; i<nRows; i++){
        result += r[i];
    }
    return result;
}


int main(int argc, char**argv){

    string s;
    int r;

    s = "PAYPALISHIRING";
    r = 3;
    cout << s << " : " << convert(s, 3) << endl;

}


