#include "bigthing_t.h"
Object *BigThing::clone()
{
	BigThing *bp = new BigThing(*this);
	return bp;
}
