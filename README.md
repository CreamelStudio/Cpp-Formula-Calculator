# Cpp Formula Calculator
C++로 제작한 콘솔 기반 수식 계산기입니다.<br>
입력한 수식을 문자열로 받아 직접 파싱하고, 연산자 우선순위에 따라 계산합니다.<br>
개발 과정에서 AI를 사용하지 않았으며, README 작성에만 AI의 도움을 받았습니다.

## 지원 기능

* 덧셈 `+`
* 뺄셈 `-`
* 곱셈 `*`
* 나눗셈 `/`
* 제곱 `^`
* 루트 `v`
* 괄호 `()`
* 공백이 포함된 수식 입력

## 사용 예시

```txt
계산할 수식을 입력해주세요 : 3 + 5 * 2
입력된 수식: 3+5*2
답 : 13
```

```txt
계산할 수식을 입력해주세요 : (2 + 3) * 4
입력된 수식: (2+3)*4
답 : 20
```

```txt
계산할 수식을 입력해주세요 : 2 ^ 3
입력된 수식: 2^3
답 : 8
```

## 루트 연산자 사용법

이 계산기에서는 루트 연산자를 `v`로 표현합니다.

```txt
16v1
```

위 식은 `16`에 루트를 1번 적용한다는 의미입니다.

```txt
16v1 = √16 = 4
```

```txt
16v2
```

위 식은 `16`에 루트를 2번 적용한다는 의미입니다.

```txt
16v2 = √√16 = 2
```

## 연산자 우선순위

계산은 아래 순서대로 진행됩니다.

1. 괄호 `()`
2. 제곱 `^`, 루트 `v`
3. 곱셈 `*`, 나눗셈 `/`
4. 덧셈 `+`, 뺄셈 `-`

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
16v1
16v2
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
괄호를 먼저 처리하고, 연산자 우선순위에 따라 수식을 단계적으로 계산합니다.

### `simpleCal`

```cpp
long double simpleCal(char op, long double a, long double b)
```

연산자와 두 숫자를 받아 실제 계산을 수행합니다.

### `findLNumber`

```cpp
string findLNumber(string str, int middleIndex)
```

연산자를 기준으로 왼쪽 숫자를 찾습니다.

### `findRNumber`

```cpp
string findRNumber(string str, int middleIndex)
```

연산자를 기준으로 오른쪽 숫자를 찾습니다.

## 개발 환경

* Language: C++
* Compiler: g++
* Type: Console Application

## 소개

이 프로젝트는 C++ 문자열 처리와 재귀 함수, 연산자 우선순위 처리 방식을 연습하기 위해 제작한 콘솔 수식 계산기입니다.
