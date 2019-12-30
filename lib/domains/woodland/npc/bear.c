inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("bear");
   set_short("A bear");
   set_long("A bear");
   set_gender("female");
   set_race("bear");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 60);
   set_skill("combat/defense", 60);
   set_level(3);
}
