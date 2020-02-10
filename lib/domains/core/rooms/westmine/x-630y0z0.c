inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", -630);
  set_property("y", 0);
  set_property("z", 0);

  add_area( "westmine" );
  set_short( "West Mine - Central Transit Station" );
  set_long( "So years ago the company sold off all its mines, it replaced them with digital currency mines. All the corezite that was year was mined out years ago to make the fusion reactors that make up this digital mine. Chairs are all over the place lined up against terminals.\n\nYou should try to '%^MAGENTA%^crypto%^RESET%^' here." );

  add_action("do_crypto", "crypto");

 set_exits( ([
  "north" : DIR+"/rooms/westmine/x-630y40z0.c",
  "south" : DIR+"/rooms/westmine/x-630y-40z0.c",
  "east" : DIR+"/rooms/westmine/x-590y0z0.c",
  "west" : DIR+"/rooms/westmine/x-670y0z0.c"
  ]) );
}

int do_crypto(string arg) {
  int minediff, minenew, lvl, difficulty, payout, coins, pskill;

  object player;
  string message;

  difficulty = 100;
  player = this_player();
  pskill = (player->query_skill("mining") + 1);
  lvl = player->query_level();
  coins = lvl + random(lvl);
  payout = (coins * difficulty);


  minediff = (time() - (player->query_lastmined()));
  player->set_lastmined();
  minenew = (100 - pskill - random(10));

  message = "You aren't due for another %^GREY%^"+ (minenew - minediff) + "%^RESET%^ cycles.....\n   You lose concentration and start over...\n";
  if (minediff > minenew) {
    player->add_money("credit", payout);
    player->increase_expr(payout);
    message = "You mined %^MAGENTA%^" + coins + "%^RESET%^ Derby Coin worth %^MAGENTA%^" + difficulty + " %^RESET%^each for a total of %^MAGENTA%^" + payout + "%^RESET%^ credits.";
  }
  write(message);
  if (random(100) > 50) {
   player->learn_skill("mining");
   write("You got better at this crypto thing or something...");
  }
  if(player->query_skill("mining") > 300) {
    write("\n\nObviously you found my back door and got super greedy, I guess we will have to deal with you....\n\n");
    player->set_skill("mining", 0);
    player->clear_money();
    player->set_expr(0);
    player->set_level(1);
    player->set_hp(1);
  }
  return 1;
}
