#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> arr(n + 1, 1);

    arr[0] = 0;
    for(int i: lost)
    {
        arr[i] = 0;
    }
    for(int i: reserve)
    {
        arr[i] = 2;
    }
    
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] == 0 && arr[i - 1] == 2)
        {
            arr[i] = 1;
            arr[i - 1] = 1;
        }
        else if(arr[i] == 0 && arr[i + 1] == 2)
        {
            arr[i] = 1;
            arr[i + 1] = 1;
        }
    }
    
    for(int i: arr)
    {
        if(i >= 1)
            answer++;
    }
    
    return answer;
}

int main() {
    vector<int> lost;
    lost.push_back(1);
    lost.push_back(2);
    lost.push_back(3);
    lost.push_back(4);
    lost.push_back(5);
    lost.push_back(6);

    vector<int> reserve;
    reserve.push_back(1);
    reserve.push_back(2);
    reserve.push_back(3);

    cout << solution(10, lost, reserve) << endl;
    return 0;
}