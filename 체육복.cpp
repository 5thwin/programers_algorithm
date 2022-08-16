#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int count[32]; //체육복 갖고있는 개수
    count[0] = 0;
    for (int i = 1; i <= n; i++){
        count[i] = 1; //체육복 개수 1로 초기화
    }
    for (int i = n + 1; i < 32; i++){
        count[i] = 0;
    }
    vector<int>::iterator iter;
    for (iter = lost.begin(); iter != lost.end(); iter++){
        count[*iter]--;  //잃어버린 체육복
    }
    for (iter = reserve.begin(); iter != reserve.end(); iter++){
        count[*iter]++; //여분 체육복
    }

    for (int i = 1; i <= n; i++){
        if(count[i] >= 1){
            answer++;
        }
        if(count[i] == 0){
            //앞사람한테 빌리는 경우
            if (count[i - 1] > 1){
                count[i - 1]--;
                count[i]++;
                answer++;
                continue;
            }
            //뒷사람에게 빌리는 경우
            if (count[i + 1] > 1){
                count[i + 1]--;
                count[i]++;
                answer++;
                continue;
            }
        }
    }
    return answer;
}
