// create a struct and use it to do something.

#include <iostream>
#include <string>
using namespace std;

int
main()
{
	struct Grade{
		string name;
		int mid_term;
		int final_term;
	};
	struct Grade grade = {"Tommy", 80, 90};
	int avg_score(struct Grade);
	int avg_score(struct Grade grade) {
		return (grade.mid_term + grade.final_term)/2;
	}
	cout << "The average score of " << grade.name 
		 << " is " << avg_score(grade) 
		 << endl;
}
