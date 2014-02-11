#include<stdio.h>
#include "boatsail.h"


/** locateBoat - returns the position at which the boat with 
 * 		id as boatid is found, or else return -666.
 */
int locateBoat(ID boatid, BoatList bl, Size s)      
{
	/*
	 * write your code here
	 *
	 */
}

/** PrintDetails - prints the details of Sailor and his boat.
 */
void PrintDetails(SailorList sl, Size sailors, BoatList bl, Size boats)
{
 	/*
	 * write your code here
	 *
	 * This function uses locateBoat.
	 */
}



static void insertSailor(Sailor s, SailorList sl, Size sailors,
                  BoatList bl, Size boats) 
{
  	/*
	 * write your code here
	 *
	 * This function uses locateBoat.
	 */
}


/** sortSailors - sort Sailors on the basis of number of hours 
 *                their boat has sailed. If their boats have 
 *                sailed for same duration, then sort based on their
 *                unique sailor id. 
 */
void sortSailors(SailorList sl, Size sailors, BoatList bl, Size boats) //6M
{
   	/*
	 * write your code here
	 *
	 * This function uses insertSailor.
	 */
}
