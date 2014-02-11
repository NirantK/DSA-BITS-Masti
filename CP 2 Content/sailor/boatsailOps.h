 /* boatsailOps.h*/
#include "boatsail.h"

/** locateBoat - returns the position at which the boat with 
 * 		id as boatid is found, or else return -666.
 *Hint: BoatList is unordered. End Hint.
 */
extern int locateBoat(ID boatid, BoatList bl, Size s);

/** PrintDetails - prints the details of Sailor and his boat.
 */
extern void PrintDetails(SailorList sl, Size sailors,
                         BoatList bl, Size boats);

/** sortSailors - sort Sailors on the basis of number of hours 
 *                their boat has sailed. If their boats have 
 *                sailed for same duration, then sort based on their
 *                unique sailor id. 
 */
extern void sortSailors(SailorList sl, Size sailors,
                        BoatList bl, Size boats);
