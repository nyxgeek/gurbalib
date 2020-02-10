inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", -20);
  set_property("y", 50);
  set_property("z", 0);

  add_area( "city" );
  set_short( "Maintenance Access Point" );
  set_long( "You are at one of the fusion generator's maintenance access points. This place is where the reactor techs carry out maintenance work on the reactor like repairing and assuring that the proper reaction levels are reached. Anyone with sufficient tech skills can help maintain the generator via this access point. A button is on the wall." );

  add_item("button", "A large purple button is here, it says 'PRESS ME'");
  add_action("do_push", "push");
  add_action("do_push", "press");
  set_objects( 
 DIR+"/monsters/tech.c", 
 DIR+"/monsters/tech.c"
);
 set_exits( ([
  "west" : DIR+"/rooms/city/x-30y50z0.c"
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
        key_tracker[5] = 1;
        player->set_key_tracker(( { key_tracker[0], key_tracker[1], key_tracker[2], key_tracker[3], key_tracker[4], key_tracker[5], key_tracker[6], key_tracker[7] } ));
      return 1;
   } else {
      return 0;
   }
}
