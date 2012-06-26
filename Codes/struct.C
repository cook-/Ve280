// create a struct and use it to do something.

#include <iostream>
#include <string>

int
avg(const struct &);

int
main()
{
	const struct Grade{
		string name = "Tommy";
		int mid_term = 80;
		int final_term = 90;
	} grade.
	cout << "The average score of " << grade.name 
		 << " is " << avg(grade.mid_term + grade.final_term) 
		 << endl;
}

int
avg(const struct &grade)
{
	return (grade.mid_term + grade.final_term)/2;
}
