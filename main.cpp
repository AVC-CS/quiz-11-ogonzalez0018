// Condition for the email string.
// start with the alphabet.
// ID characters are all alpha numerics characters
// the last string shoud be one of the list {com, edu, org, and net}

#include "main.hpp"

int main()
{
	string email;

	cout << "Enter your email \n";
	cin >> email;

	if (emailcheck(email))
		cout << "Your email passed the validation\n";
	else
		cout << "Your email has an invalid format\n";
}