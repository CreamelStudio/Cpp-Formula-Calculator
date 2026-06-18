#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

#pragma region Utils
bool IsOp(char a){
    return (a == '+' || a == '-' || a == '*' || a == '/');
}

bool IsMinus(char a){
    return (a =='-');
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
    int temp = a;
    for(int i = 0; i < b; i++){
        temp = sqrt(temp);
    }

    return temp;
}

int findFirstIndex(int a, int b){
    if(b == -1) return a;
    else if(a == -1) return b;
    else if(a > b) return a;
    else if(a < b) return b;
    else return -1;
}

string findLNumber(string str, int middleIndex){
    int cnt = 0;
    bool isMinus = false;
    for (int i = middleIndex - 1; i > -1; i--) {
        if (!IsOp(str[i])) {
            cnt++;
        }
        else if(IsMinus(str[i]) && IsOp(str[i - 1])){
            isMinus = true;
            break;
        }
        else
            break;
    }
    if (cnt == 0)
        return 0;
    else
        return isMinus ? "-" : "" + str.substr(str.length()-cnt);
}

string findRNumber(string str, int middleIndex){
    int cnt = 0;
    bool isMinus = false;
    for (int i = middleIndex - 1; i < str.length(); i++) {
        if (!IsOp(str[i])) {
            cnt++;
        }
        else if(IsMinus(str[i]) && IsOp(str[i - 1])){
            isMinus = true;
            break;
        }
        else
            break;
    }
    if (cnt == 0)
        return 0;
    else
        return isMinus ? "-" : "" + str.substr(str.length()-cnt);
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
            return Division(a, b);
        case '^':
            return powl(a, b);
        case 'v':
            return SqrtLong(a, b);

    }
}

long double Calculate(string& input)
{
    while(1){
        int index = findFirstIndex(input.find('*'), input.find('/'));

        if(index > -1){
            string LNumberStr = findLNumber(input, index);
            string RNumberStr = findRNumber(input, index);

            long double LNumber = stold(LNumberStr);
            long double RNumber = stold(RNumberStr);
            
            long double result = simpleCal(input[index], LNumber, RNumber);
            //return input.substr(index - LNumberStr.length, )
        }

        int index = findFirstIndex(input.find('+'), input.find('-'));
        
        if(index > -1){
            string LNumberStr = findLNumber(input, index);
            string RNumberStr = findRNumber(input, index);

            long double LNumber = stold(LNumberStr);
            long double RNumber = stold(RNumberStr);
            
            long double result = simpleCal(input[index], LNumber, RNumber);
        }
    }
}
#pragma endregion

int main(){
    string input;
    cout << "계산할 수식을 입력해주세요 : ";
    getline(cin, input);

    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    cout << "입력된 수식: " << input << endl;
    long double result = Calculate(input);
    if(result == -1) cout << "잘못된 수식입니다!";

    return 0;
}


