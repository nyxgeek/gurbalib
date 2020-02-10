inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 630);
  set_property("y", 0);
  set_property("z", 0);

  add_area( "eastmine" );
  set_short( "East Mine Ruins" );
  set_long( "This is the center of the East Mine, what used to be a mining shaft is now plugged with a giant fusion reactor. The fusion reactor powers the cryptocurrency mining gear. Rows of terminals line the walls.\n\nYou should try to '%^MAGENTA%^crypto%^RESET%^' here." );
  add_action("do_crypto", "crypto");


 set_exits( ([
  "north" : DIR+"/rooms/eastmine/x630y40z0.c",
  "south" : DIR+"/rooms/eastmine/x630y-40z0.c",
  "east" : DIR+"/rooms/eastmine/x670y0z0.c",
  "west" : DIR+"/rooms/eastmine/x590y0z0.c"
  ]) );
}

int do_crypto(string arg) {
  int minediff, minenew, lvl, difficulty, payout, coins, pskill;

  object player, pass, goldpass, platinumpass;
  string message;

  difficulty = 300;
  player = this_player();
  pass = player->present("Mining Pass");
  goldpass = player->present("Gold Pass");
  platinumpass = player->present("Platinum Pass");
  pskill = (player->query_skill("mining") + 1);
  lvl = player->query_level();
  coins = lvl + random(lvl);
  payout = (coins * difficulty);


  player->set_lastmined();

  if (pass || goldpass || platinumpass) {
    minenew = (100 - pskill - random(10));
    minediff = (time() - (player->query_lastmined()));
    message = "You aren't due for another %^GREY%^"+ (minenew - minediff) + "%^RESET%^ cycles.....\n   You lose concentration and start over...\n";
  } else {
    minenew = 10000;
    minediff = 1;
    message = "You don't have a mining pass";
  }
  if (minediff > minenew) {
    player->add_money("credit", payout);
    player->increase_expr(payout);
    message = "You mined %^MAGENTA%^" + coins + "%^RESET%^ Dave Coin worth %^MAGENTA%^" + difficulty + " %^RESET%^each for a total of %^MAGENTA%^" + payout + "%^RESET%^ credits.";
  }
  write(message);
  if (random(100) > 50) {
   player->learn_skill("mining");
   write("You got better at this crypto thing or something...");
  }
  if(player->query_skill("mining") > 500) {
    write("\n\nObviously you found my back door and got super greedy, I guess we will have to deal with you....\n\n");
    player->set_skill("mining", 0);
    player->clear_money();
    player->set_expr(0);
    player->set_level(1);
    player->set_hp(1);
  }
  return 1;
}
