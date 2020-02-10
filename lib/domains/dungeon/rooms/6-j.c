inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "south" : DIR+"/rooms/7-j.c",
  "west" : DIR+"/rooms/6-i.c"
  ]) );
  set_long( "The floors and walls appear to be made of jade while the roof appears to be dripping some kind of orange liquid.  The floors and wall also appear to be covered in some kind of blood.\n\nThe dungeon continues to the south, and west.%^RESET%^");
}
