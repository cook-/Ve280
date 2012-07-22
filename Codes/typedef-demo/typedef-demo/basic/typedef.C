#include <iostream>
using namespace std;

typedef struct
{
	char name[16];
	int midterm;
	int final;
    int projects[3];
} grade_t;

typedef enum
{ BLUE, RED, GREEN } color_t;

typedef int *intptr;

int main(int argc, char *argv[])
{
	grade_t a = {"LadyGaGa", 60, 80, {70, 90, 85}};
	grade_t b = a;

    color_t color;
    color = BLUE;

    int d = 0;
    intptr p = &d;
    *p = 1;

	cout << b.name << endl;;
	cout << b.projects[2] << endl;;
    cout << d << endl;

    return 0;
}
