/** compare.c - Implementation of the ordered functions
*/


#include "Element.h"  

#include "compare.h"

/*  compare - returns how members a and b are related 

*/
ORDER compare(Element e1, Element e2)
{
	if (e1 < e2)
			return LESSER;
	else
		if (e1 > e2)
				return GREATER;
	else
		return EQUAL;
}

