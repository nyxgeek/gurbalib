inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
   add_action("do_push", "push");
   add_action("do_push", "press");
set_objects( DIR+"/monsters/heartbleed.c.c");
 set_exits( ([
  "east" : DIR+"/rooms/8-c.c",
  "west" : DIR+"/rooms/8-a.c",
  "northeast" : DIR+"/rooms/7-c.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of iridium liquid.  The floors and wall also appear to be covered in some kind of mud. A button is on the wall.\n\nThe dungeon continues to the east, west, and northeast.%^RESET%^");
add_item("button", "A purple button, it says 'push me'");
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
        key_tracker[7] = 1;
        player->set_key_tracker(( { key_tracker[0], key_tracker[1], key_tracker[2], key_tracker[3], key_tracker[4], key_tracker[5], key_tracker[6], key_tracker[7] } ));
      return 1;
   } else {
      return 0;
   }
}
