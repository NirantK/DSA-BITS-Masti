/*boatsail.h */


#define NAME_MAX  30
typedef char Name[NAME_MAX];
typedef unsigned int ID;
typedef unsigned int Hours;
typedef unsigned int YrsExperience;
typedef unsigned int BoatIndex;
typedef unsigned int Size;

//Boat details
typedef struct {
    ID bid;
    Name boat;
    Hours numSailed;
} Boat;

#define BOAT_MAX 100
typedef Boat BoatList[BOAT_MAX];


// Sailor details
typedef struct {
    ID sid;
    Name sailor;
    YrsExperience exp;
    ID ownsbid;
} Sailor;

#define SAIL_MAX 100
typedef Sailor SailorList[SAIL_MAX];
