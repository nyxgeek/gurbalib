inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", -50);
  set_property("y", -80);
  set_property("z", 0);

  add_area( "city" );
  set_short( "Airlock Interior" );
  set_long( "Big enough to fit ten people standing at a time, this white sterile room is one of the safe accessways between the domes and the outer atmosphere of Core. You notice black vents on the ceiling and some computer panels near the airlock doors. Bright lights lining the ceiling and the walls of the room illuminate this clinically-clean airlock interior. You could probably '%^CYAN%^leave airlock%^RESET%^' to get out of this dome, but that would be inadvisable without proper protection and authorization." );

  add_action("do_leave", "leave");

 set_exits( ([
  "north" : DIR+"/rooms/city/x-50y-70z0.c"
  ]) );
}

int do_leave(string arg) {
  object player, obj, *inv;
  string pname;
  int q7track, i;
  
  player = this_player();
  pname = player->query_name();
  q7track = player->query_q7_tracker();
  
  if (q7track == 128) {
    if (arg == "airlock") {
        player->set_deathproof(0);
        write("%^YELLOW%^EvilMogs Agent %^MAGENTA%^tells you: your chose poorly......%^RESET%^");
        player->set_q7_tracker(255);
        write("%^YELLOW%^EvilMogs Agent %^MAGENTA%^tells you: your body will never be found...%^RESET%^");
        write("%^YELLOW%^EvilMogs Agent %^MAGENTA%^tells you: we aren't monsters however....the sketchy doctor can fix you up.%^RESET%^");
        write("%^YELLOW%^EvilMogs Agent %^MAGENTA%^tells you: next time you will choose wisely....%^RESET%^");
         player->move("/domains/core/rooms/city/x-50y-80z0-dead.c");
         player->die();
         player->move("/domains/core/rooms/city/x-10y-40z0.c");
         player->set_dead(0);
         player->set_level(1);
         player->set_expr(0);
         CHANNEL_D->chan_send_string("announce", "", pname +" was assisted out the airlock", 1);
         write("Your flag is flag{w4adb8vsbkaq8b6nug}\n");
         this_player()->add_completed_quest("Evil");
         this_player()->set_q7_tracker(255);
         CHANNEL_D->chan_send_string("announce", "", this_player()->query_name() +" has completed the evil quest", 1);
         return 1;
    } else {
      write("If you really want you can '%^RED%^leave airlock%^RESET%^'");
      return 1;
    }
  }
    
  if (arg == "airlock") {
    write("As you exit the airlock your body begins to disolve...Everything goes black and the last thing you can remember is screaming in pain as your body is eaten away by the acid rain.");
         player->move("/domains/core/rooms/city/x-50y-80z0-dead.c");
         player->die();
         player->move("/domains/core/rooms/city/x-10y-40z0.c");
         player->set_dead(0);
         player->set_level(1);
         player->set_expr(0);
         CHANNEL_D->chan_send_string("announce", "", pname +" was assisted out the airlock", 1);
   
    if (player->query_deathproof() == 1) {
      player->set_deathproof(0);
      write("%^RED%^I'm sorry your body could not be recovered, you are no longer deathproof....");
    }
    return 1;
  } else {
    write("If you really want you can '%^RED%^leave airlock%^RESET%^'");
    return 1;
  }
}
