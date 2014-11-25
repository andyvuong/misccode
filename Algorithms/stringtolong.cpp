/**
 * @author Andy Vuong
 * This file contains my solution for the stringToLong function.
 */

#include <cmath>
#include <string>

using namespace std;

/**
 * This function converts a given "number" string (i.e 123) into decimal form of type long. If the string given is not a "proper" number string (i.e. 128a2ds2)
 * it will throw an error and return 0. 
 *
 * The following are the assumptions I made and limitations of this solution:
 * 1. The function assumes that the given string number will be within the range of a long's maximum value.
 *
 * @parameter s - The string input to be converted into a long.
 * @return - The long value of the given string
 */
long stringToLong(String s) {

	// Declare temporary variables.
	long value = 0;
	int size = s.length();
	int i = 0; neg = 1;

	// Check for a negative number string. If negative, change the "neg" flag to -1 and set i to 1 to begin parsing at the next character. 
	if(s.at(0) == '-') {
		i = 1;
		neg = -1;
	}

	// Check if the current index of the string contains a valid number character.
	// Parse each character into a number type.
	// Sum the corresponding decimal values to give the correct long value.
	for(; i < size; i++) {
		int asciiVal = s.at(i);
		if(asciiVal < 48 || asciiVal > 57) { // If a character is not a number, throw an error and return 0.
			fprintf(stderr, "'%c' is not a numer! Input string is invalid. Returning 0.\n", asciiVal);
			return 0;
		}
		value += (asciiVal-48) * pow(10,length-1-i);
	}

	// Return the negative or positive long value.
	return (value*neg);
}



