#include <stdio.h>

float accFactor = 0.0f;


float calculateFactor(int rangeMin, int rangeMax) {

	if (rangeMin==1024 || rangeMax==0)
		return 0;

	return (255/ (rangeMax - rangeMin));
}



int main(int argc, char **argv)
{

	int accInVal = 512;
	int accMinInVal = 1024;
	int accMaxInVal = 0;
	float range = 0.0f;

	int ooPedalPosition = -1;

	while (ooPedalPosition!=0)
	{
		scanf("%d", &ooPedalPosition);

		accInVal = ooPedalPosition;


	//	printf("%f\n", accInVal/1024.0f * 255);

		if (accInVal>accMaxInVal) 
		{
			accMaxInVal = accInVal;
			range = accMaxInVal - accMinInVal;
			
		}
		if (accInVal<accMinInVal)
		{
			accMinInVal = accInVal;
			range = accMaxInVal - accMinInVal;
		}

		printf ("range: %f\n", range);

		if (range>0) {

			printf ("%f\n", (accInVal - accMinInVal) / range * 255);

		}

		// float outputValue = accInVal * accFactor;

		// printf("Min %d, Max %d. ", accMinInVal, accMaxInVal);
		// printf("Output position is: %f\n",outputValue);

	}



	return 0;
}