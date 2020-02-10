inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 0);
  set_property("y", -630);
  set_property("z", 0);

  add_area( "southmine" );
  set_short( "South Mine - Central Transit Station" );
  set_long("This mine has long since been mined out, all that remains of the original mine is the giant fusion reactor in its pit. Terminals used for crypto currency mining are all over the place. Mog Coin is worth the most in the galaxy.\n\nYou should try to '%^MAGENTA%^crypto%^RESET%^' here.");

  add_action("do_crypto", "crypto");
 set_exits( ([
  "north" : DIR+"/rooms/southmine/x0y-590z0.c",
  "south" : DIR+"/rooms/southmine/x0y-670z0.c",
  "east" : DIR+"/rooms/southmine/x40y-630z0.c",
  "west" : DIR+"/rooms/southmine/x-40y-630z0.c"
  ]) );
}

int do_crypto(string arg) {
  int minediff, minenew, lvl, difficulty, payout, coins, pskill;

  object player, pass, goldpass, platinumpass;
  string message;

  difficulty = 500;
  player = this_player();
  pass = player->present("Mining Pass");
  goldpass = player->present("Gold Pass");
  platinumpass = player->present("Platinum Pass");
  pskill = (player->query_skill("mining") + 1);
  lvl = player->query_level();
  coins = lvl + random(lvl);
  payout = (coins * difficulty);


  player->set_lastmined();

  if (goldpass || platinumpass) {
    minenew = (100 - pskill - random(10));
    minediff = (time() - (player->query_lastmined()));
    message = "You aren't due for another %^GREY%^"+ (minenew - minediff) + "%^RESET%^ cycles.....\n   You lose concentration and start over...\n";
  } else {
    minenew = 10000;
    minediff = 1;
    message = "You don't have a gold mining pass";
  }
  if (minediff > minenew) {
    player->add_money("credit", payout);
    player->increase_expr(payout);
    message = "You mined %^MAGENTA%^" + coins + "%^RESET%^ Mog Coin worth %^MAGENTA%^" + difficulty + " %^RESET%^each for a total of %^MAGENTA%^" + payout + "%^RESET%^ credits.";
  }
  write(message);
  if (random(100) > 50) {
   player->learn_skill("mining");
   write("You got better at this crypto thing or something...");
  }
  if(player->query_skill("mining") > 1000) {
    write("\n\nObviously you found my back door and got super greedy, I guess we will have to deal with you....\n\n");
    player->set_skill("mining", 0);
    player->clear_money();
    player->set_expr(0);
    player->set_level(1);
    player->set_hp(1);
  }
  return 1;
}
