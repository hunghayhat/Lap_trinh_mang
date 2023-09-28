#include<stdio.h>
typedef struct student {
	char name[20];
	int eng;
	int math; 
	int phys; 
	double mean;
	char rank;
}STUDENT;

double caculate_mean (int eng, int math, int phys) {
	return (eng + math + phys) / 3;
}
char ranking (double mean){
	if (mean >= 90) return 'S';
	else if (mean >= 80) return 'A';
	else if (mean >= 70) return 'B';
	else if (mean >= 60) return 'C';
	else return 'D';
}

int main(){
// Khai báo thêm trường "rank" cho cấu trúc student
static struct student data[] ={
{"Tuan", 82, 72, 58, 0.0, ' '},
{"Nam", 77, 82, 79, 0.0,' '},
{"Khanh", 52, 62, 39, 0.0,' '},
{"Phuong", 61, 82, 88, 0.0,' '}
};

int numStudents = sizeof(data) / sizeof(data[0]);
int i;
for (i = 0; i < numStudents; i++) {
	
	//Sử dụng con trỏ để truy cập đến trường đầu tiên của cấu trúc

	STUDENT *s = &data[i];
	s->mean = caculate_mean(s->eng, s->math, s->phys);
	s->rank = ranking(s->mean);
}
printf("Danh sach diem cua sinh vien:\n");
printf("Name\tEng\tMath\tPhys\tMean\tRank\n");
for (i = 0; i < numStudents; i++){
	printf("%s\t%d\t%d\t%d\t%.2lf\t %c\n",data[i].name, data[i].eng, data[i].math, data[i].phys, data[i].mean, data[i].rank);
}
return 0;
}

