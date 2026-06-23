# Cpp Formula Calculator

C++로 제작한 콘솔 기반 수식 계산기입니다.<br>
입력한 수식을 문자열로 받아 직접 파싱하고, 괄호와 연산자 우선순위에 따라 계산합니다.<br>
개발 과정에서 AI를 사용하지 않았으며, README 작성에만 AI의 도움을 받았습니다.

## 지원 기능

* 덧셈 `+`
* 뺄셈 `-`
* 곱셈 `*`
* 나눗셈 `/`
* 제곱 `^`
* 루트 `v`
* 괄호 `()`
* 단항 부호 `+`, `-`
* 삼각함수 `sin`, `cos`, `tan`
* 공백이 포함된 수식 입력
* `EXIT` 입력 시 프로그램 종료

## 사용 예시

```txt
계산할 수식을 입력해주세요 (EXIT) : 3 + 5 * 2
입력된 수식: 3+5*2
답 : 13
```

```txt
계산할 수식을 입력해주세요 (EXIT) : (2 + 3) * 4
입력된 수식: (2+3)*4
답 : 20
```

```txt
계산할 수식을 입력해주세요 (EXIT) : 2 ^ 3
입력된 수식: 2^3
답 : 8
```

```txt
계산할 수식을 입력해주세요 (EXIT) : -3 + 5
입력된 수식: -3+5
답 : 2
```

## 루트 연산자 사용법

이 계산기에서는 루트 연산자를 `v`로 표현합니다.<br>
`v` 뒤에 오는 숫자의 제곱근을 계산합니다.

```txt
v16
```

위 식은 `√16`을 의미합니다.

```txt
v16 = 4
```

괄호를 이용하면 루트를 여러 번 적용할 수도 있습니다.

```txt
v(v16)
```

위 식은 `√√16`을 의미합니다.

```txt
v(v16) = 2
```

## 삼각함수 사용법

삼각함수는 `sin`, `cos`, `tan`을 지원합니다.<br>
각도는 도 단위로 계산됩니다.

```txt
sin30
```

```txt
sin30 = 0.5
```

괄호를 사용해서 입력할 수도 있습니다.

```txt
cos(60)
```

```txt
cos(60) = 0.5
```

지원하는 삼각함수 예시는 다음과 같습니다.

```txt
sin30
cos60
tan45
sin(30)
cos(60)
tan(45)
```

## 연산자 우선순위

계산은 아래 순서대로 진행됩니다.

1. 괄호 `()`
2. 삼각함수 `sin`, `cos`, `tan`
3. 제곱 `^`, 루트 `v`
4. 곱셈 `*`, 나눗셈 `/`
5. 덧셈 `+`, 뺄셈 `-`

예시:

```txt
2 + 3 * 4
```

곱셈이 덧셈보다 먼저 계산되므로 결과는 다음과 같습니다.

```txt
2 + 12 = 14
```

## 빌드 방법

### g++ 사용

```bash
g++ main.cpp -o main
```

한글 출력이 깨지는 경우 아래 옵션을 사용할 수 있습니다.

```bash
g++ main.cpp -o main -finput-charset=UTF-8 -fexec-charset=UTF-8
```

## 실행 방법

### Windows PowerShell

```bash
./main.exe
```

### macOS / Linux

```bash
./main
```

## 입력 예시

```txt
1+2
3*4+5
(2+3)*4
10/2
2^3
v16
v(v16)
sin30
cos60
tan45
-3+5
2*-3
```

## 프로그램 종료

프로그램 실행 중 `EXIT`을 입력하면 계산기가 종료됩니다.

```txt
계산할 수식을 입력해주세요 (EXIT) : EXIT
```

## 잘못된 수식 처리

잘못된 수식이 입력되거나 계산할 수 없는 값이 들어오면 아래 메시지가 출력됩니다.

```txt
잘못된 수식입니다!
```

예시:

```txt
10/0
```

## 프로젝트 구조

```txt
Cpp-Formula-Calculator
├── main.cpp
└── README.md
```

## 주요 함수 설명

### `Calculate`

```cpp
long double Calculate(string& input)
```

입력된 수식을 계산하는 핵심 함수입니다.<br>
괄호를 먼저 처리하고, 삼각함수와 연산자 우선순위에 따라 수식을 단계적으로 계산합니다.

### `simpleCal`

```cpp
long double simpleCal(char op, long double a, long double b)
```

연산자와 숫자를 받아 실제 계산을 수행합니다.<br>
덧셈, 뺄셈, 곱셈, 나눗셈, 제곱, 루트 연산을 처리합니다.

### `findLNumber`

```cpp
string findLNumber(string str, int middleIndex)
```

연산자를 기준으로 왼쪽에 있는 숫자를 찾습니다.<br>
음수와 양수 부호도 함께 처리합니다.

### `findRNumber`

```cpp
string findRNumber(string str, int middleIndex)
```

연산자를 기준으로 오른쪽에 있는 숫자를 찾습니다.<br>
음수와 양수 부호도 함께 처리합니다.

### `Trigonometric`

```cpp
long double Trigonometric(string a, long double b)
```

`sin`, `cos`, `tan` 삼각함수를 계산합니다.<br>
입력된 각도는 도 단위로 처리됩니다.

### `ExStold`

```cpp
long double ExStold(string a)
```

문자열을 `long double` 자료형으로 변환합니다.<br>
변환할 수 없는 값이 들어오면 `NaN`을 반환하여 잘못된 수식으로 처리합니다.

## 개발 환경

* Language: C++
* Compiler: g++
* Type: Console Application

## 소개

이 프로젝트는 C++ 문자열 처리, 재귀 함수, 연산자 우선순위 처리 방식을 연습하기 위해 제작한 콘솔 수식 계산기입니다.<br>
직접 문자열을 분석하여 계산하는 방식으로 구현했으며, 기본 사칙연산뿐만 아니라 제곱, 루트, 괄호, 삼각함수까지 지원합니다.
