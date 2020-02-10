inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", -630);
  set_property("y", -40);
  set_property("z", 0);

  add_area( "westmine" );
  set_short( "West Mine - Southern Transit Station" );
  set_long( "Despite the constant cleaning efforts, the maintenance crews haven't been able to completely remove the mine soot that has been ground into the floor.  This can be none other than one of The Company's mine domes." );


  set_objects( 
 DIR+"/monsters/guard.c", 
 DIR+"/monsters/guard.c"
);
 set_exits( ([
  "north" : DIR+"/rooms/westmine/x-630y0z0.c",
  "northwest" : DIR+"/rooms/westmine/x-640y-30z0.c"
  ]) );
}
