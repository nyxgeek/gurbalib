inherit "/std/room";

#include "../include.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
 set_exits( ([
  "north" : DIR+"/rooms/7f.c",
  "south" : DIR+"/rooms/9f.c",
  "east" : DIR+"/rooms/8g.c"
  ]) );
  set_long( "The floors and walls appear to be made of stone while the roof appears to be dripping some kind of liquid.  The floors and wall also appear to be covered in some kind of slime.\n\nThe dungeon continues to the  north, south, and east.%^RESET%^");
}
