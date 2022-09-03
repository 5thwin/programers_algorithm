#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
int n_lcm(int N, vector<int> v)
{
	int a = v[0];
	for (int i = 1; i < N; i++)
	{
		a = lcm(a, v[i]);
	}
	return a;
}
//최소공배수 time시간동안 모든 코어가 처리하는 일의 개수
int time_work(int N, int time, vector<int> v)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		count += time / v[i];
	}
	return count;
}

int solution(int n, vector<int> cores)
{
	int answer;
	int Ncore = cores.size();		 //코어개수
	int t_lcm = n_lcm(Ncore, cores); //최소 공배수
	// t_lcm동안 모든 코어가 처리하는 일의 개수
	int work = time_work(Ncore, t_lcm, cores);
	n %= work;
	//첫번째 코어가 모든 일을 하는데 걸리는 시간
	int long_time = cores[0] * n;
	// dp 만들기
	vector<int> dp(long_time + 1, 0);
	for (int cnum = 0; cnum < Ncore; cnum++)
	{
		for (int i = 0; i < long_time; i += cores[cnum])
		{
			dp[i]++;
		}
	}
	//마지막 코어 계산하기
	for (int i = 0; i < long_time; i++)
	{
		n -= dp[i];
		if (n <= 0)
		{ //일을 모두 끝마치는 시간이 i임
			n += dp[i];
			//앞의 코어부터 작업하므로 맨 앞 코어부터 작업을 받았는지 확인해준다.
			for (int cnum = 0; cnum < Ncore; cnum++)
			{
				if (i % cores[cnum] == 0)
				{
					n--;
					if (n == 0)
					{
						return cnum + 1;
					}
				}
			}
		}
	}
	return answer + 1;
}

/*효율성 검사에서 시간초과로 (35/50)점*/
