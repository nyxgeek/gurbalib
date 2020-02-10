inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 80);
  set_property("y", -40);
  set_property("z", 0);

  add_area( "city" );
  set_short( "EvilMog Park" );
  set_long( "This park just seems to go on and on, almost as if its cheap filler for some sort of demonic quest thought up by overlord EvilMog. This area shows no originality and its probably just here to mess with you. A shrub is somewhere in this chaos." );

  add_item("shrub", "Underneath this shrub is a purple button.");
  add_item("button", "This is a giant purple button that says 'PUSH ME'");

     add_action("do_push", "push");
   add_action("do_push", "press");

  set_objects( 
 DIR+"/monsters/floorvine.c", 
 DIR+"/monsters/floorvine.c", 
 DIR+"/monsters/snapperjaw.c", 
 DIR+"/monsters/snapperjaw.c"
);
 set_exits( ([
  "north" : DIR+"/rooms/city/x80y-30z0.c",
  "south" : DIR+"/rooms/city/x80y-50z0.c",
  "east" : DIR+"/rooms/city/x90y-40z0.c",
  "west" : DIR+"/rooms/city/x70y-40z0.c",
  "northeast" : DIR+"/rooms/city/x90y-30z0.c",
  "northwest" : DIR+"/rooms/city/x70y-30z0.c",
  "southeast" : DIR+"/rooms/city/x90y-50z0.c",
  "southwest" : DIR+"/rooms/city/x70y-50z0.c"
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
        key_tracker[6] = 1;
        player->set_key_tracker(( { key_tracker[0], key_tracker[1], key_tracker[2], key_tracker[3], key_tracker[4], key_tracker[5], key_tracker[6], key_tracker[7] } ));
      return 1;
   } else {
      return 0;
   }
}
