inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("rabbit");
   set_short("A rabbit");
   set_long("A rabbit");
   set_gender("male");
   set_race("rabbit");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 20);
   set_skill("combat/defense", 20);
   set_level(1);
}
