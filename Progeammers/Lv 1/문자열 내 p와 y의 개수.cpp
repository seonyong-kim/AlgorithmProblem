#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pNumber = 0, yNumber = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' || s[i] == 'P')
            pNumber++;
        else if (s[i] == 'y' || s[i] == 'Y')
            yNumber++;
    }
    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;
    if (pNumber != yNumber)
        answer = false;
    return answer;
}