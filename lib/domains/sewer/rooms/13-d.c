inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 13-d" );
set_objects( DIR+"/monsters/newbie_eel_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/14-d.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the red glow of the muck in this hellhole. The walls and floors are covered with blood. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the south.%^RESET%^");
}
