inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 30);
  set_property("y", -70);
  set_property("z", 0);

  add_area( "city" );
  set_short( "Colony Quartermaster's Office" );
  set_long( "Only one phrase adequately describes the state of this office: utter chaos. Papers, datapadds, mining uniforms and miscellaneous pieces of mining equipment are randomly strewn about... on top of desks, stacked on chairs, or even piled unceremoneously on the floor." );


  set_objects( 
 DIR+"/monsters/olasha.c"
);
 set_exits( ([
  "east" : DIR+"/rooms/city/x40y-70z0.c"
  ]) );
}
