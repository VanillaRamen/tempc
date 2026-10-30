#include <stdio.h>


enum unit {
	FAHRENHEIT,
	CELSIUS,
	KELVIN
} src_unit;

double src_value;

#define MAIN_ERRMSG() do { fprintf(stderr, "Usage: %s <temperature> <F|C|K>\n", argv[0]); } while(0)

int main(int argc, char *argv[]) {
	if (argc < 2) {
		MAIN_ERRMSG();
		return 1;
	}

	if (sscanf(argv[1], "%lf", &src_value) == EOF){
		MAIN_ERRMSG();
		return 1;
	}

	switch (argv[2][0]) {
		case 'f':
		case 'F':
			src_unit = FAHRENHEIT;
			break;
		case 'c':
		case 'C':
			src_unit = CELSIUS;
			break;
		case 'k':
		case 'K':
			src_unit = KELVIN;
			break;
		default:
			MAIN_ERRMSG();
			return 1;
	} // end switch (argv[2][0]);

	/* conversions */
	double fahrenheit;
	double celsius;
	double kelvin;

	if (src_unit == FAHRENHEIT) {
		fahrenheit = src_value;

		celsius = (fahrenheit - 32.) * (5./9.);
		kelvin = celsius + 273.15;
	} else if (src_unit == CELSIUS) {
		celsius = src_value;

		fahrenheit = celsius * (9./5.) + 32.;
		kelvin = celsius + 273.15;
	} else if (src_unit == KELVIN) {
		kelvin = src_value;

		celsius = kelvin - 273.15;
		fahrenheit = celsius * (9./5.) + 32.;
	} else {
		MAIN_ERRMSG();
		return 1;
	}

	/* outputting */
	printf("%-11s %#+8.3lf\n", "Fahrenheit:", fahrenheit);
	printf("%-11s %#+8.3lf\n", "Celsius:",    celsius);
	printf("%-11s %#+8.3lf\n", "Kelvin:",     kelvin);

	return 0;
}
