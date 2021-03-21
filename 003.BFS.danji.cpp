#include <stdio.h>

int N;
char map[30][30];
char visit[30][30];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int danji;
int danjinum[1000];
int tmp[1000];

struct Q {
	int i, j;
};
Q q[1000000];


void inputData(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
}


void mergeSort(int arr[], int tmp[], int start, int end)
{
	int mid = (start + end) / 2;

	if (start >= end)
		return;

	mergeSort(arr, tmp, start, mid);
	mergeSort(arr, tmp, mid + 1, end);

	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end) {
		if (arr[i] < arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}

	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= end)
		tmp[k++] = arr[j++];

	for (i = start; i <= end; i++) {
		arr[i] = tmp[i];
	}
}


int check(int i, int j)
{
	if (i < 0 || i > N - 1 || j < 0 || j > N - 1)
		return 1;
	else if (map[i][j] != '1')
		return 1;
	else if (visit[i][j] == 1)
		return 1;
	else
		return 0;
}


void BFS(int si, int sj)
{
	int rp = 0, wp = 0;
	int ci, cj;
	int ni, nj;

	q[wp].i = si;
	q[wp].j = sj;
	visit[si][sj] = 1;
	wp++;

	while (rp < wp) {
		ci = q[rp].i;
		cj = q[rp].j;
		danjinum[danji]++;
		rp++;

		for (int k = 0; k < 4; k++) {
			ni = ci + di[k];
			nj = cj + dj[k];

			if (!check(ni, nj)) {
				q[wp].i = ni;
				q[wp].j = nj;
				visit[ni][nj] = 1;
				wp++;
			}
		}
	}
}


int main(void)
{
	inputData();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && visit[i][j] != 1) {
				BFS(i, j);
				danji++;
			}
		}
	}

	printf("%d\n", danji);
	mergeSort(danjinum, tmp, 0, danji - 1);
	for (int i = 0; i < danji; i++) {
		printf("%d\n", danjinum[i]);
	}

	return 0;
}