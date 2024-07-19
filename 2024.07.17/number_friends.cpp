#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) 
{
    string answer = "";
    
    int cntX[10] = {0};
    int cntY[10] = {0};
    
    for(int i = 0; i < X.length(); i++) 
        cntX[X[i] - '0']++;
    
    for(int i = 0; i < Y.length(); i++) 
        cntY[Y[i] - '0']++;
    
    for(int i = 9; i >= 0; i--)
    {
        int num = min(cntX[i], cntY[i]);
        
        for(int j = 0; j <  num; j++)
            answer += to_string(i);
    }
    
    if(answer=="")
    {
        return "-1";
    }
    else if(answer[0]=='0') 
    {
        return "0";
    }
    else 
    {
        return answer;
    }
}