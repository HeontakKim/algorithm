#include <stdio.h>

int N, M;
int map[110][110];
int visit[110][110];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

struct Q {
	int i, j;
	int d;  // distance from start point
};
Q q[1000000];


void inputData()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
}


int BFS()
{
	int rp = 0;
	int wp = 0;
	int ci, cj, cd;
	int ni, nj, nd;
	
	q[wp].i = 0;
	q[wp].j = 0;
	q[wp].d = 1;
	visit[0][0] = 1;
	wp++;

	while (rp < wp) {
		ci = q[rp].i;
		cj = q[rp].j;
		cd = q[rp].d;
		rp++;

		for (int k = 0; k < 4; k++) {
			ni = ci + di[k];
			nj = cj + dj[k];
			nd = cd + 1;

			if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1)
				continue;
			else if (map[ni][nj] != '1')
				continue;
			else if (visit[ni][nj] != 0)
				continue;

			if (ni == N - 1 && nj == M - 1)
				return nd;

			q[wp].i = ni;
			q[wp].j = nj;
			q[wp].d = nd;
			visit[ni][nj] = 1;
			wp++;
		}
	}

	// (N, M) 에 도달하지 못하고 종료됨 - 디버깅 필요
	return -1;
}


int main(void)
{
	int minDist;

	inputData();
	minDist = BFS();
	printf("%d", minDist);

	return 0;
}