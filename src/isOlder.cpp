/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isLeap(int y) {
	if (y % 400 == 0)
		return 1;
	else if (y % 100 == 0)
		return 0;
	else if (y % 4 == 0)
		return 1;
	else
		return 0;
}
int validateDate(int d, int m, int y)
{
	if (m < 1 || m > 12 || y < 1)			
		return 0;
	int maxDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
	if (isLeap(y))							
		maxDays[1] ++;						
	if (d < 1 || d > maxDays[m - 1])		
		return 0;
	return 1;
}
int isOlder(char *dob1, char *dob2) 
{
	int m1, m2, d1, d2, y1, y2;
	
		y1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0');
		y2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0');
		m1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
		m2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
		d1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
		d2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
		if (validateDate(d1, m1, y1) && validateDate(d2, m2, y2))
		{
		if (y2 > y1)
			return 1;
		if (y1 > y2)
			return 2;
		else
		{
			if (m2 > m1)
				return 1;
			if (m1 > m2)
				return 2;
			else
			{
				if (d2 > d1)
					return 1;
				if (d1 > d2)
					return 2;
				else
					return 0;
			}
		}
	}
	return -1;
}
