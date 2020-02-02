inherit "/std/room";

void setup(void) {
   add_area("required");

   set_domainname("EvilMogs Funland");
   set_coords(({ 0, 0 }));
   set_dimensions(({ 1, 1 }));
   set_mapstart(({ 0, 0} ));

   set_short("A large open field");
   set_long("You are in a large open field.");
   set_exits(([
     "north" : "/domains/woodland/rooms/5_16.c",
     "west" : "/domains/cyphercon/rooms/start.c"
   ]));
}
