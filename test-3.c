#include <stdio.h>

int dp[5001][3] = {0};
int delt[10000];
int count;
int n, m, tmp;
int s,t;
void search(int s, int t, int max, int min);
int main() {
	int time;
	scanf("%d", &time);
	while(time--) {
		scanf("%d%d", &n, &m);

		int i;
		int u, v, w;
		for(i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			dp[i][0] = u;
			dp[i][1] = v;
			dp[i][2] = w;
		}
		
		scanf("%d%d", &s, &t);
		count = 0;
		search(s, t, 0, 30000);
		
		int min = delt[0];
		for(i = 0; i < count; i++) {
			if(min > delt[i]) {
				min = delt[i];
			}
		}
		
		printf("%d\n", min);
	}
	return 0;
}

void search(int s, int t, int max, int min) {
	int i = 0;
	if(s == t) {
		delt[count++] = max-min;
		return;
	}
	for(i = 0; i < m; i++) {
		if(dp[i][0] == s) {
			search(dp[i][1], t, dp[i][2]>max?dp[i][2]:max, dp[i][2]<min?dp[i][2]:min);
		}
	}
}
