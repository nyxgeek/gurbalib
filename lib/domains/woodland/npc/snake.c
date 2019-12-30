inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("snake");
   set_short("A snake");
   set_long("A snake");
   set_gender("female");
   set_race("snake");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 20);
   set_skill("combat/defense", 20);
   set_level(1);
}
