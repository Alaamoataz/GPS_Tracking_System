#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "GPS.h"
#include "../../LIB/Bit_Utilies.h"
#include "../../LIB/TM4C123.h"
#include "../../MCAL/UART/UART.h"


char i=0;

char GPS[80];
char GPS_logName[]="$GPRMC,";  

char GPS_formated[12][20];
char * token ;

float currentLong , currentLat , speed, finalLat=1052.563787;
const double lat_final,long_final;

void GPS_read()
{
	char recievedChar;
	char flag=1;
	do{
		flag=1;

//Check logname		
do {
	char i = 0;
    if (UART_GetChar() != GPS_logName[i]) {
        flag = 0;
        break;
    }
    ++i;
} while (i < 7);
	}while(flag==0);
	strcpy(GPS, "");
	
		do{
			char fillGPScounter=0;
			recievedChar =UART_GetChar();
			GPS[fillGPScounter++]=recievedChar;
		}
		while(recievedChar!='*'); //check end of string
		
}
void GPS_format()
{
	char noOfTokenStrings=0;
	token = strtok (GPS , ",");  //seprate at comma
	do
	{
		strcpy (GPS_formated[noOfTokenStrings],token);
		token=strtok(NULL, ",");
		noOfTokenStrings++;
	}

while(token!=NULL);
	
if(strcmp(GPS_formated[1],"A")==0)
		{

			if(strcmp(GPS_formated[3],"N")==0)
			
				currentLat=atof(GPS_formated[2]); //north +ve (atof from string to numbers)
			
			else
				currentLat=-atof(GPS_formated[2]); //south -ve
			
			if(strcmp(GPS_formated[5],"E")==0)
				currentLong=atof(GPS_formated[4]);
			else
				currentLong=-atof(GPS_formated[4]);
				
		}
}

//convert any angle to degree
float ToDegree(float angle)
{
	int degree = (int)angle/100;
	float minutes=angle-(float)degree*100;
	return (degree+(minutes/60));

}

float ToRad(float angle)
{
	return angle *pi /180;
}

float GPSgetDistance(float currentLong, float currentLat, float destLong, float destLat)
{
	//get radian angle
	float currentLongRad =ToRad(ToDegree(currentLong));
	float currentLatRad =ToRad(ToDegree(currentLat));
	float destLongRad =ToRad(ToDegree((destLong)));
	float destLatRad =ToRad(ToDegree((destLong)));
	//get difference
	float longdiff = destLongRad - currentLongRad;
	float latdiff = destLatRad - currentLatRad;
	//calculate distance
	float a = pow(sin(latdiff/2),2)+cos(currentLatRad)*cos( destLatRad)*pow(sin(longdiff/2),2); //harversine formula= sin^2(delta fai/2)+....
	double c= 2*atan2(sqrt(a),sqrt(1-a));
	return EARTH_RADIUS*c;
}