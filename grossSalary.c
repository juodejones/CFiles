//Created  by Juode

#include <stdio.h>

int main() {

	int basic, hraAmt, daAmt, gross;
	int hra, da;
	printf("Enter the basic pay: ");
	scanf("%d", &basic);
	if ( basic <= 4000) {
		hra = 10;
		da = 50;
	} else if ( (basic > 4000) && (basic <= 8000) ) {
		hra = 20;
		da = 60;
	} else if ( (basic > 8000) && (basic < 12000) ) {
		hra = 25;
		da = 70;
	} else {
		hra = 30;
		da = 80;
	}
	
	hraAmt = (basic * hra) / 100;
	daAmt = (basic * da) / 100;
	gross = basic + hraAmt + daAmt;
	
	printf("Gross salary is = %d", gross);

	return 0;

}
