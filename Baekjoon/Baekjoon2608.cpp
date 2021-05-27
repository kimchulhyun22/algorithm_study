/*
    백준 2608번 로마 숫자
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

std::map<char, int> m;

std::string ConvertRoma(int number) {
    std::string roma = "";
    
    int thousand = number / 1000;
    
    number %= 1000;

    int hundred = number / 100;

    number %= 100;

    int ten = number / 10;

    number %= 10;

    int one = number;

    // 천의 자리
    for(int i = 0; i < thousand; i++) {
        roma += "M";
    }

    // 백의 자리
    switch (hundred)
    {
        case 1: case 2: case 3:
            for(int i = 0; i < hundred; i++) {
                roma += "C";
            }
            break;
        case 6: case 7: case 8:
            roma += "D";
            for(int i = 0; i < hundred % 5; i++) {
                roma += "C";
            }
            break;    
        case 4:
            roma += "CD";
            break;
        case 5:
            roma += "D";
            break;
        case 9:
            roma += "CM";
            break;
        default:
            break;
    }
    
    // 십의 자리
    switch (ten)
    {
        case 1: case 2: case 3:
            for(int i = 0; i < ten; i++) {
                roma += "X";
            }
            break;
        case 6: case 7: case 8:
            roma += "L";
            for(int i = 0; i < ten % 5; i++) {
                roma += "X";
            }
            break;    
        case 4:
            roma += "XL";
            break;
        case 5:
            roma += "L";
            break;
        case 9:
            roma += "XC";
            break;
        default:
            break;
    }

    // 일의 자리
    switch (one)
    {
        case 1: case 2: case 3:
            for(int i = 0; i < one; i++) {
                roma += "I";
            }
            break;
        case 6: case 7: case 8:
            roma += "V";
            for(int i = 0; i < one % 5; i++) {
                roma += "I";
            }
            break;    
        case 4:
            roma += "IV";
            break;
        case 5:
            roma += "V";
            break;
        case 9:
            roma += "IX";
            break;
        default:
            break;
    }
    return roma;
}

int ConvertArabia(std::string str) {
    int number = 0;
    int size = str.size();

    int i;
    for(i = 0; i < size-1; ) {
        if(m[str[i]] < m[str[i+1]]) {
            number += (m[str[i+1]] - m[str[i]]);
            i += 2;        
        }        
        else {
            number += m[str[i]];
            i += 1;
        }
    }

    if(i < size) {
        number += m[str[size-1]];
    }   
    
    return number;
}

int main() {
    std::string A,B;

    m['I'] = 1; 
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    	
    std::cin >> A >> B;

    int result = ConvertArabia(A) + ConvertArabia(B);

    std::cout << result << '\n';

    std::cout << ConvertRoma(result) << '\n';
}