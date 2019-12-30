inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("porcupine");
   set_short("A porcupine");
   set_long("A porcupine");
   set_gender("female");
   set_race("porcupine");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 20);
   set_skill("combat/defense", 20);
   set_level(1);
}
