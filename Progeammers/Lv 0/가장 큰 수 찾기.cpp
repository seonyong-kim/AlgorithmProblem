#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    int max = 0;
    int index = 0;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > max) {
            max = array[i];
            index = i;
        }
    }
    return { max,index };
}