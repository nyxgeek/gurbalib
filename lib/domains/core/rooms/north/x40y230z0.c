inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 40);
  set_property("y", 230);
  set_property("z", 0);

   add_action("do_push", "push");
   add_action("do_push", "press");

  add_area( "north" );
  set_short( "Housing Records Storage" );
  set_long( "Dust hangs heavily in the air. It appears that there has not been much activity here for a very long time. The room itself is relatively big, and rows of cabinets adorn the walls of the room. Apart from an ancient-looking desk which sits despondently in one corner, the only other furniture here are the cabinets.\n\nYou may leave by heading north." );

  add_item("desk", "Someone once used this table for record-keeping purposes. Now it just sits in one corner, forgotten. A button is on the desk.");
  add_item("button", "This is a purple button, it says 'PRESS ME'");
 set_exits( ([
  "north" : DIR+"/rooms/north/x40y240z0.c"
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
        key_tracker[1] = 1;
        player->set_key_tracker(( { key_tracker[0], key_tracker[1], key_tracker[2], key_tracker[3], key_tracker[4], key_tracker[5], key_tracker[6], key_tracker[7] } ));
      return 1;
   } else {
      return 0;
   }
}
