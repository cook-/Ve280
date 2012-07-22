// create a struct and use it to do something.

#include <iostream>
#include <string>
using namespace std;

struct Grade{
	string name;
	int mid_term;
	int final_term;
};

int
avg(const struct Grade &);

int
main()
{
	const struct Grade grade = {"Tommy", 80, 90};
	cout << "The average score of " << grade.name 
		 << " is " << avg(grade) 
		 << endl;
}

int 
avg(const struct Grade &grade) 
{
	return (grade.mid_term + grade.final_term)/2;
}
