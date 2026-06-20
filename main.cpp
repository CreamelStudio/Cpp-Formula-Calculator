#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

#pragma region Utils
bool IsOp(char a){
    return (a == '+' || a == '-' || a == '*' || a == '/' || a == '^' || a == 'v');
}


long double Sum(long double a, long double b){
    return a + b;
}

long double Minus(long double a, long double b){
    return a - b;
}

long double Multiply(long double a, long double b){
    return a * b;
}

long double Division(long double a, long double b){
    return a / b;
}

long double SqrtLong(long double a, long double b){
    if(b == 0) return a;
    long double temp = a;
    for(int i = 0; i < b; i++){
        temp = sqrt(temp);
    }

    return temp;
}

bool IsUnaryMinus(const string& str, int i) {
    return str[i] == '-' && (i == 0 || IsOp(str[i - 1]) || str[i - 1] == '(');
}

bool IsUnaryPlus(const string& str, int i) {
    return str[i] == '+' && (i == 0 || IsOp(str[i - 1]) || str[i - 1] == '(');
}

int findFirstAddSub(const string& input) {
    for (int i = 0; i < input.length(); i++) {

        if (input[i] == '+' && !IsUnaryPlus(input, i)){
            return i;
        }

        if (input[i] == '-' && !IsUnaryMinus(input, i)) {
            return i;
        }
    }

    return -1;
}

long double ExStold(string a){
    long double temp = 0;
    try{
        size_t length = 0;
        temp = stold(a, &length);

        if(length != a.length()) return numeric_limits<long double>::quiet_NaN();
    }
    catch(exception e){
        return numeric_limits<long double>::quiet_NaN();
    }
    return temp;
}

int findFirstIndex(int a, int b){
    if(b == -1) return a;
    else if(a == -1) return b;
    else if(a < b) return a;
    else if(a > b) return b;
    else return -1;
}

string findLNumber(string str, int middleIndex){
    int cnt = 0;
    bool isMinus = false;
    for (int i = middleIndex - 1; i > -1; i--) {
        if (!IsOp(str[i])) {
            cnt++;
        }
        else if(IsUnaryMinus(str, i) || IsUnaryPlus(str, i)){
            isMinus = str[i] == '-';
            break;
        }
        else
            break;
    }
    if (cnt == 0)
        return "";
    else
        return (isMinus ? "-" : "") + str.substr(middleIndex - cnt, cnt);
}

string findRNumber(string str, int middleIndex){
    int cnt = 0;
    bool isMinus = false;
    for (int i = middleIndex + 1; i < str.length(); i++) {
        if (!IsOp(str[i])) {
            cnt++;
        }
        else if(str[middleIndex + 1] == '+' || str[middleIndex + 1] == '-'){
            if(IsUnaryPlus(str, middleIndex + 1) || IsUnaryMinus(str, middleIndex + 1)){
                if(str[middleIndex + 1] == '-') isMinus = true;
                middleIndex++;
            }
            
        }
        else break;
    }
    if (cnt == 0)
        return "";
    else
        return (isMinus ? "-" : "") + str.substr(middleIndex + 1, cnt);
}
#pragma endregion

#pragma region Cal
long double simpleCal(char op, long double a, long double b){
    switch(op){
        case '+':
            return Sum(a, b);
            break;
        case '-':
            return Minus(a, b);
            break;
        case '*':
            return Multiply(a, b);
        case '/':
            if(b == 0) return numeric_limits<long double>::quiet_NaN();
            return Division(a, b);
        case '^':
            return powl(a, b);
        case 'v':
            return SqrtLong(a, b);
        default:
            return numeric_limits<long double>::quiet_NaN();

    }
}

long double Calculate(string& input)
{
    while(1){
        int Lindex = -1;
        int Rindex = -1;
        for(int i = 0; i < input.length(); i++){
            if(input[i] == '('){
                Lindex = i;
            }
            else if(input[i] == ')'){
                if(Lindex == -1) return numeric_limits<long double>::quiet_NaN();

                Rindex = i;
                string baseFormula = input.substr(Lindex + 1, Rindex - Lindex - 1);
                cout << "Fomula Cal : " << baseFormula << "\n";
                long double result = Calculate(baseFormula);
                input = input.substr(0, Lindex) + to_string(result) + input.substr(Rindex + 1);
            }
        }

        if(Lindex == -1 && Rindex == -1){
            break;
        }
        else if(Lindex == -1 || Rindex == -1){
            return numeric_limits<long double>::quiet_NaN();
        }
    }

    while(1){
        int index = findFirstIndex(input.find('^'), input.find('v'));

        if(index > -1){
            string LNumberStr = findLNumber(input, index);
            string RNumberStr = findRNumber(input, index);

            cout << LNumberStr << " " << input[index] << " " << RNumberStr << "\n"; 

            long double LNumber = ExStold(LNumberStr);
            long double RNumber = ExStold(RNumberStr);
            
            long double result = simpleCal(input[index], LNumber, RNumber);
            input = input.substr(0, index - LNumberStr.length()) + to_string(result) + input.substr(index + 1 + RNumberStr.length());
        }
        
        if(index == -1) break;
    }

    while(1){
        int index = findFirstIndex(input.find('*'), input.find('/'));

        if(index > -1){
            string LNumberStr = findLNumber(input, index);
            string RNumberStr = findRNumber(input, index);

            cout << LNumberStr << " " << input[index] << " " << RNumberStr << "\n"; 

            long double LNumber = ExStold(LNumberStr);
            long double RNumber = ExStold(RNumberStr);
            
            long double result = simpleCal(input[index], LNumber, RNumber);
            input = input.substr(0, index - LNumberStr.length()) + to_string(result) + input.substr(index + 1 + RNumberStr.length());
        }
        
        if(index == -1) break;
    }
    while(1){

        int index = findFirstAddSub(input);
        
        if(index > -1){
            string LNumberStr = findLNumber(input, index);
            string RNumberStr = findRNumber(input, index);

            cout << LNumberStr << " " << input[index] << " " << RNumberStr << "\n"; 

            long double LNumber = ExStold(LNumberStr);
            long double RNumber = ExStold(RNumberStr);
            
            long double result = simpleCal(input[index], LNumber, RNumber);
            input = input.substr(0, index - LNumberStr.length()) + to_string(result) + input.substr(index + 1 + RNumberStr.length());
        }

        if(index == -1) break;
    }

    return ExStold(input);
}
#pragma endregion

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    string input;
    cout << "계산할 수식을 입력해주세요 : ";
    getline(cin, input);

    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    cout << "입력된 수식: " << input << endl;
    long double result = Calculate(input);
    if(isnan(result)) cout << "잘못된 수식입니다!";
    else cout << "답 : " << result << "\n";

    return 0;
}


