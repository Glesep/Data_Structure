#include <iostream>
#include <string>
using namespace std;

template <typename T>
class ArrayStack
{
private:
    int stackSize = 4;
    T *stack = new T[stackSize];
    int top_pos = -1;


public:
    void ArrayReallocation() {
        T *tmp = new T[stackSize*2];

        for (int i=0; i < stackSize; i++) {
            tmp[i] = stack[i];
        }

        delete[] stack;       // 배열 동적할당 시 [] 추가하는 것 기억하기
        stack = tmp;

        stackSize *= 2;
    }

    bool full()
    {
        return top_pos == stackSize - 1;
    }

    bool empty()
    {
        return top_pos == -1;
    }

    void push(T c)
    {
        if (full()) {
            ArrayReallocation();
        }
            
        stack[++top_pos] = c;
    }

    T pop()
    {
        if (empty())
            throw runtime_error("stack_empty");
        return stack[top_pos--];    // 반환 후 스택 삭제
    }

    T top()
    {
        if (empty())
            throw runtime_error("stack_empty");
        return stack[top_pos];
    }

    void debug() {
        cout << stackSize << endl;
    }
};

// 백만자리 정수를 정수 관련 자료형에 담지 못함 (long long도 19자리로 한없이 부족)
// -> string으로 정수 취급하기

// 자릿수를 담을 char형 stack 정의
ArrayStack<char> stack;

/**
 * @brief deleteFreq개의 digit을 제거하고 남은 자릿수들을 stack에 저장하는 함수
 * 
 * @param num string type으로 표현된 정수
 * @param deleteFreq 제거할 digit의 수
 */
void makeBiggestDigit(string num, int deleteFreq) {
    for (int i = 0; i < num.length(); i++) {
        // 최대 자릿수에 해당하는 숫자는 스택에 그냥 넣기, 두번째 숫자부터 top과 비교
        // 자기가 작거나 같으면 그냥 push됨
        // deleteFreq가 0일 때 남은 숫자 전부 스택에 추가
        if (deleteFreq == 0 || stack.empty() || stack.top() >= num[i]) {
            stack.push(num[i]);
        }

        // 자기가 top보다 크면 pop후 자기가 push
        else if (stack.top() < num[i]) {
            while (!stack.empty() && deleteFreq != 0 && stack.top() < num[i]) {
                stack.pop();
                deleteFreq--;
            }
            stack.push(num[i]);
        }
    }

    // 수가 다 push되었을 때 숫자가 남아있다면 그 숫자만큼 pop
    if (deleteFreq != 0) {
        while (deleteFreq--) {
            stack.pop();
        }
    }
}

/**
 * @brief stack에 있는 자릿수들을 모아 출력해주는 함수
 * 
 */
void printResult() {
    string result;
    while(!stack.empty()) {
        result = stack.pop() + result;
    }

    cout << result << endl;
}

int main()
{
    string N;
    int K;

    cin >> N >> K;

    makeBiggestDigit(N, K);
    printResult();
 
    return 0;
}
