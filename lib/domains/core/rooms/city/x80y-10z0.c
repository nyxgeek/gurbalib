inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 80);
  set_property("y", -10);
  set_property("z", 0);
  add_item("terminal", "This is a company '%^GREEN%^access%^RESET%^' terminal.");
  add_area( "city" );
  add_action("do_access", "access");
  set_short( "The Office of Vice President Grey" );
  set_long( "This plush office has real oak paneling, deep pile natural fiber carpet, and a huge cherrywood desk.  All of the chairs are fully covered and heavily padded in burgandy dyed goatskin.  Portraits in oils of the original Company founders cover the walls.  A terminal is built into the desk. The anteroom is to the west." );

 set_exits( ([
  "west" : DIR+"/rooms/city/x70y-10z0.c"
  ]) );
}

int do_access(string arg) {
  if (this_player()->query_q7_tracker() == 15) {
    write("It appears as if the company has been up to some very bad things...find old tom the miner and ask him about evidence.");
    return 1;
  } else {
    write("I'm Sorry you don't have access to that");
    return 1;
  }
}
