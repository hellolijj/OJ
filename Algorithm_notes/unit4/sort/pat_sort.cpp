#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student
{
	char id[15];    // 准考证号
	int score;
	int local_number;      // 考场号
	int local_rank;        // 在考场的排名
	int rank;              // 总体排名
}stu[10010];

bool cmp(Student a, Student b) {
	// 按照分数大小排序，分数相同按照考号大小排序
	if(a.score != b.score) {
		return a.score < b.score;
	} else {
		return strcmp(a.id, b.id) < 0;
	}
}

int main(int argc, char const *argv[])
{
	int N, n = 0;        // N个考场, 所有考场里总共有n个学生
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int local_n;         // local_n, 某个考场下有 local_n 个数字
		scanf("%d", &local_n);
		for(int j = 0; j < local_n; j++) {
			scanf("%s %d", stu[n].id, &stu[n].score);
			stu[n].local_number = i;          // 储存当前考场号
			n++;
		}

		// 将该场考生的学生分数排序
		sort(stu+n-local_n, stu+n, cmp);

		// 对该考场的所有学生进行标记 local_rank
		stu[n-local_n].local_rank = 1;
		for(int j = n - local_n + 1; j < n; j++) {
			if(stu[j].score == stu[j-1].score) {
				stu[j].local_rank = stu[j-1].local_rank;
			} else {
				stu[j].local_rank = j - (n-local_n) + 1;        // 分数不同的话，排名为当前小组的人数
			}
		}
	}

	// 合并排序
	sort(stu, stu+n, cmp);
	stu[0].rank = 1;
	for(int j = 1; j < n; j++) {
		if(stu[j].score == stu[j-1].score) {
			stu[j].rank = stu[j-1].rank;
		} else {
			stu[j].rank = j + 1;        // 分数不同的话，排名为当前小组的人数
		}
	}


	for (int i = 0; i < n; ++i)
	{
		printf("%s %d %d %d %d\n", stu[i].id, stu[i].score, stu[i].rank, stu[i].local_number, stu[i].local_rank);
	}
	return 0;
}