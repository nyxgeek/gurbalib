inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 220);
  set_property("y", -10);
  set_property("z", 0);

  add_area( "east" );
  set_short( "East Dome Corridor" );
  set_long( "You are in the southeast quadrant of the East housing dome. This is a corridor you are in with a large sign hanging over your head in with a large sign hanging over your head work involving the East housing dome.\n\nA mass-transit station is to your northwest. The corridor continues to your south and southeast." );

 set_exits( ([
  "south" : DIR+"/rooms/east/x220y-20z0.c",
  "northwest" : DIR+"/rooms/east/x210y0z0.c",
  "southeast" : DIR+"/rooms/east/x230y-20z0.c"
  ]) );
}
