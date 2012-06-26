// create a struct and use it to do something.

#include <iostream>
#include <string>
using namespace std;

int
avg_score(const struct Grade &);

int
main()
{
	const struct Grade{
		string name = "Tommy";
		int mid_term = 80;
		int final_term = 90;
	} grade;
	cout << "The average score of " << grade.name 
		 << " is " << avg_score(grade.mid_term + grade.final_term) 
		 << endl;
}

int
avg_score(const struct Grade &grade)
{
	return (grade.mid_term + grade.final_term)/2;
}
