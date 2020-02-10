inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 190);
  set_property("y", 460);
  set_property("z", -10);

   add_action("do_push", "push");
   add_action("do_push", "press");

  add_area( "prisonbasement" );
  set_short( "Leak Control Station" );
  set_long( "The leak control station is the place where the reactor personnel keep constant vigil on the state of the influx and outflux of materials to and from the reactor. You see a mixture of classic reactor technology and new cutting edge equipment which work together to give the best results. A button is on the wall. Gauges, valves and meters can be found alongside digital readouts and computer screens. Truly a place of precision and accuracy.\n\nReactor decks can be reached by going south or west." );

  add_item("button", "a purple button, it says 'push me'");

  set_objects( 
 DIR+"/monsters/r1engineer.c", 
 DIR+"/monsters/r1engineer.c", 
 DIR+"/monsters/cyclophant.c", 
 DIR+"/monsters/r1radiologist.c", 
 DIR+"/monsters/r1serviceman.c"
);
 set_exits( ([
  "south" : DIR+"/rooms/prisonbasement/x190y450z-10.c",
  "west" : DIR+"/rooms/prisonbasement/x180y460z-10.c"
  ]) );
}

kint do_push(string arg) {
  int * key_tracker; /* tracks 8 keys from quest */
  object player; /* tracks player*/
  player = this_player();
  key_tracker = player->get_key_tracker();
   if (arg == "button") {
      write("You push the button and your key tracker is updated\n");
      if (!key_tracker) {
        key_tracker = (( { 0, 0, 0, 0, 0, 0, 0, 0 } ));
      }
        key_tracker[3] = 1;
        player->set_key_tracker(( { key_tracker[0], key_tracker[1], key_tracker[2], key_tracker[3], key_tracker[4], key_tracker[5], key_tracker[6], key_tracker[7] } ));
      return 1;
   } else {
      return 0;
   }
}
