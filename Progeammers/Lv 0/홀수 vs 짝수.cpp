#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int compare1 = 0; int compare2 = 0;
    for (int i = 0; i < num_list.size(); i++) {
        if (i % 2 == 0)    compare2 += num_list[i];
        else compare1 += num_list[i];
    }

    return (compare1 > compare2 ? compare1 : compare2);
}