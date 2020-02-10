inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", -80);
  set_property("y", 50);
  set_property("z", -20);

  add_area( "sewer" );
  set_short( "Sandworm Pit" );
  set_long( "You notice a certain dryness about the air in this pen. The floor has been replaced with fine sand, and the small pen contains nothing else save for the sand. It doesn't look as if the sand goes down very deep but then again, you can never tell.\n\nThe exit is to your north." );

 set_exits( ([
  "north" : DIR+"/rooms/sewer/x-80y60z-20.c"
  ]) );
}

int do_search(void) {
 object player, sandworm;
 int q7track;
 
 player = this_player();
 q7track = player->query_q7_tracker();
 if (q7track == 63) {
   sandworm = clone_object(DIR+"/monsters/sandworm.c");
   sandworm->setup();
   sandworm->move(this_player()->query_environment());
   sandworm->attack(player);
   return 1;
 } else {
   return 1;
 }
}
