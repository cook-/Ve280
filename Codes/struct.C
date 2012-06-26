// create a struct and use it to do something.

#include <iostream>

int
avg(const struct &);

int
main()
{
	const struct Grade{
		const char *name = "Tommy";
		int mid_term = 80;
		int final_term = 90;
	}
	cout << "The average score of " << Grade.name 
		 << " is " << avg(Grade.mid_term + Grade.final_term) 
		 << endl;
}

int
avg(const struct &Grade)
{
	return (Grade.mid_term + Grade.final_term)/2;
}
