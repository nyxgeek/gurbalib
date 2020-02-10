inherit "/std/room";

#include "../include.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
 set_exits( ([
  "east" : DIR+"/rooms/6j.c",
  "west" : DIR+"/rooms/6i.c",
  "northeast" : DIR+"/rooms/5j.c",
  "southwest" : DIR+"/rooms/7h.c"
  ]) );
  set_long( "The floors and walls appear to be made of stone while the roof appears to be dripping some kind of liquid.  The floors and wall also appear to be covered in some kind of slime.\n\nThe dungeon continues to the  east, west, northeast, and southwest.%^RESET%^");
}
