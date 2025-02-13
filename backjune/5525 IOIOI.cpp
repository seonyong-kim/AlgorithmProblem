#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, count = 0;
    string S;
    cin >> N >> M >> S;

    int i = 0; 

    while (i < M - 1) {
        if (S[i] == 'I' && S[i + 1] == 'O') { 
            int oiCount = 0;

            while (i + 2 < M && S[i + 1] == 'O' && S[i + 2] == 'I') {
                oiCount++; 
                i += 2;    
                if (oiCount >= N) count++; 
            }
        }
        i++;  
    }

    cout << count;
    return 0;
}
