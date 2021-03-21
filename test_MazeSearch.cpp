#include <stdio.h>

int N, M;
char map[30][30];
char visit[30][30];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int distance = 0;

struct Q {
	int i, j;
	int level;
};
Q q[1000000];

void inputData(void)
{
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	return;
}

void outputData(void)
{
	printf("%d\n", distance);

	return;
}

int check(int i, int j)
{
	if (i < 0 || i > N - 1 || j < 0 || j > M - 1)
		return 1;
	else if (map[i][j] != '1')
		return 1;
	else if (visit[i][j] == 1)
		return 1;
	else
		return 0;
}


void BFS(void)
{
	int rp = 0, wp = 0;
	int ci, cj, clevel;
	int ni, nj;
	int level;

	q[wp].i = 0;
	q[wp].j = 0;
	q[wp].level = 0;
	visit[0][0] = 1;
	wp++;

	while (rp < wp) {
		ci = q[rp].i;
		cj = q[rp].j;
		level = q[rp].level;
		rp++;

		for (int k = 0; k < 4; k++) {
			ni = ci + di[k];
			nj = cj + dj[k];

			if (!check(ni, nj)) {
				q[wp].i = ni;
				q[wp].j = nj;
				q[wp].level = level + 1;
				visit[ni][nj] = 1;
				if (ni == N - 1 && nj == M - 1) distance = q[wp].level + 1;
				wp++;
			}	
		}
		level++;
	}
}


int main(void)
{
	inputData();

	BFS();

	outputData();

	return 0;
}
