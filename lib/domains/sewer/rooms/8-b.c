inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 8-b" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "southeast" : DIR+"/rooms/9-c.c",
  "southwest" : DIR+"/rooms/9-a.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the green glow of the sediment in this hellhole. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the southeast, and southwest.%^RESET%^");
}
