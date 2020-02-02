/* Definition of the human race */
inherit "/std/race";

void create(void) {
   ::create();

   set_race_short_desc("Humans are cursed with being average " +
      "in all aspects.");
   set_race_long_desc("Humans are predominant in the lands. They, as a " +
      "race, have most of\nthe power in the realm. Since they are so, all " +
      "the other races are compared \n to them. They get along with all " +
      "the other races fairly well, and a human has\na wide range of " +
      "adventuring options available to him or her. The downside is \n" +
      "that they do not excel in any particular fields.");
   set_language("english");

   base_stat_minimum["str"] = 10;
   base_stat_minimum["con"] = 10;
   base_stat_minimum["dex"] = 10;
   base_stat_minimum["int"] = 10;
   base_stat_minimum["wis"] = 10;
   base_stat_minimum["cha"] = 10;

   base_stat_maximum["str"] = 20;
   base_stat_maximum["con"] = 20;
   base_stat_maximum["dex"] = 20;
   base_stat_maximum["int"] = 20;
   base_stat_maximum["wis"] = 20;
   base_stat_maximum["cha"] = 20;

}
