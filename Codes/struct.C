// create a struct and use it to do something.

#include <iostream>
#include <string>
using namespace std;

int
avg_score(const struct Grade &);

int
main()
{
	struct Grade{
		string name;
		int mid_term;
		int final_term;
	};
	const struct Grade grade = {"Tommy", 80, 90};
	cout << "The average score of " << grade.name 
		 << " is " << avg_score(grade) 
		 << endl;
}

int
avg_score(const struct Grade &grade)
{
	return (grade.mid_term + grade.final_term)/2;
}
