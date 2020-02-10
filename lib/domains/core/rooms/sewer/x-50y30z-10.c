inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", -50);
  set_property("y", 30);
  set_property("z", -10);

   add_action("do_push", "push");
   add_action("do_push", "press");

  add_area( "sewer" );
  set_short( "Service Duct" );
  set_long( "The darkness is getting to you, as your muffled footfalls splashing in the many puddles of water on the floor echo off the blank and dirty walls of the duct. The smell here is nauseating at best as you try your best not to lose the contents of your stomach. A button on side of the pipe catches your eye.\n\nYou may leave to your north and east." );

  add_item("button", "A purple button is here, it says 'PRESS ME'");

  set_objects( 
 DIR+"/monsters/rat.c", 
 DIR+"/monsters/rat.c"
);
 set_exits( ([
  "north" : DIR+"/rooms/sewer/x-50y40z-10.c",
  "east" : DIR+"/rooms/sewer/x-40y30z-10.c"
  ]) );
}

int do_push(string arg) {
  int * key_tracker; /* tracks 8 keys from quest */
  object player; /* tracks player*/
  player = this_player();
  key_tracker = player->get_key_tracker();
   if (arg == "button") {
      write("You push the button and your key tracker is updated\n");
      if (!key_tracker) {
        key_tracker = (( { 0, 0, 0, 0, 0, 0, 0, 0 } ));
      }
        key_tracker[0] = 1;
        player->set_key_tracker(( { key_tracker[0], key_tracker[1], key_tracker[2], key_tracker[3], key_tracker[4], key_tracker[5], key_tracker[6], key_tracker[7] } ));
      return 1;
   } else {
      return 0;
   }
}
