# Introduction
Inside woodland critter christmas there is a directory for generating automatic LPC files, it is designed to be customized per domain or area.

# Example
```
/domains/woodland/gen
```

## exits
the exists file is a list of each room and its associated exits, the file looks like this
```
1_2:w,se:
3_2:sw,se,ne:
4_1:sw,e:
5_1:w,s,e:
6_1:w,se:
5_2:n,s:
7_2:nw,sw,e:
```

### room name
The first entry in a line on the file is the room name in the form of numeric co-ordinates, x_y, this has to be setup this way or else map.py will not handle the exit linking correctly

### exits
a comma separated list of exits is next

### remaining fields
the remaining fields are unused and map.py could be modified to take hidden exits or specific room descriptions or other attributes

### Actual Map
It is important to make a complete grid map before moving on to the next step, and then make the exits file

## map.py
map.py is the actual lpc generator, it is designed to be run off a map file. The map file lists the room and exists attached to that room.

### constants
The first thing you need to do is modify the constants at the beginning of the file
```
genpath="/home/thotcon/gurbalib/lib/domains/woodland/gen"
roompath="/home/thotcon/gurbalib/lib/domains/woodland/rooms"
mobpath="/home/thotcon/gurbalib/lib/domains/woodland/npc"
incdir=""
area="woodland"
```

You whould identify where the fixed path to the generator files are, the room path and the mob path, also the area should likely be changed

Next the co-ordinates and the mob list should be modified

```
dimensions = ["12", "16"]
mob_array = ["deer", "rabbit", "snake", "bear", "porcupine", "moose", "beaver", "rat", "deer"]
```

dimensions is the map directions in x and y when the ingame map command is used (check /cmds/player/map.c)

### Mob setup
The next function is quick and dirty but handles the mob setup, you could push a bunch of this out to text files, but modify here

```
for mob in room_mobs:
  gender=["male", "female"]
  mobfile = open(mobpath + "/" + mob[1] + ".c", "w")
  mobfile.write('inherit "/std/monster";\n')
  mobfile.write('#include "../domain.h" \n\n')
  mobfile.write('void setup( void ) {\n')
  mobfile.write('   set_name("' + mob[1] + '");\n')
  mobfile.write('   set_short("A ' + mob[1] + '");\n')
  mobfile.write('   set_long("A ' + mob[1] + '");\n')
  mobfile.write('   set_gender("' + gender[randint(0,1)] + '");\n')
  mobfile.write('   set_race("' + mob[1] + '");\n')
  seed(randint(0, 16))
  seed(randint(0, 16))
  moblevel = randint(1, 3)
  mobfile.write('   set_hit_skill("combat/unarmed");\n')
  mobfile.write('   set_skill("combat/unarmed", ' + str(20 * moblevel) + ');\n')
  mobfile.write('   set_skill("combat/defense", ' + str(20 * moblevel) + ');\n')
  mobfile.write('   set_level(' + str(moblevel) + ');\n')
  mobfile.write('}\n')
  mobfile.close()
```

The important parts to modify are the level and likely the short and long descriptions, right now this code is lazy but I would spruce this up a bit

### Room Setup

rlong and rshort are currently static, you could randomize these values

The actual room setup is done by this code
```
  roomfile.write('inherit "/std/room";\n\n')
  roomfile.write('#include "../domain.h" \n\n')
  roomfile.write('void setup( void ) {\n\n')
  roomfile.write('  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");\n')
  roomfile.write('  set_coords(({ ' + coords[0] + ', ' + coords[1] + ' }));\n')
  roomfile.write('  set_dimensions(({ ' + dimensions[0] + ', ' + dimensions[1] + ' }));\n\n')
  # add room desc plus color code eventually
  roomfile.write('  set_short( "' + rshort + '" );\n')
  roomfile.write('  set_long( "' + rlong + '" );\n\n')
  if exit_array:
    roomfile.write(' set_exits( ([\n')
    exitcount = len(exit_array)
    exitnum = 0
    for rexit in exit_array:
      exitnum += 1
    #  print roomname + " " + rexit[0] + " " + rexit[1]
      if exitcount == exitnum:
        roomfile.write('  "' + rexit[0] + '" : ' + 'DIR+"/rooms/' + rexit[1] + '.c"\n')
      else:
        roomfile.write('  "' + rexit[0] + '" : ' + 'DIR+"/rooms/' + rexit[1] + '.c",\n')
    roomfile.write('  ]) );\n\n')
    # end code here
    roomfile.write('}\n\n')
```

### Search
Now since I'm lazy and want unlimited mobs I put in the mob search code in this section, I had to heavily modify /cmds/player/search.c and should really contribute that upstream

```
  roomfile.write('inherit "/std/room";\n\n')
  roomfile.write('#include "../domain.h" \n\n')
  roomfile.write('void setup( void ) {\n\n')
  roomfile.write('  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");\n')
  roomfile.write('  set_coords(({ ' + coords[0] + ', ' + coords[1] + ' }));\n')
  roomfile.write('  set_dimensions(({ ' + dimensions[0] + ', ' + dimensions[1] + ' }));\n\n')
  # add room desc plus color code eventually
  roomfile.write('  set_short( "' + rshort + '" );\n')
  roomfile.write('  set_long( "' + rlong + '" );\n\n')
  if exit_array:
    roomfile.write(' set_exits( ([\n')
    exitcount = len(exit_array)
    exitnum = 0
    for rexit in exit_array:
      exitnum += 1
    #  print roomname + " " + rexit[0] + " " + rexit[1]
      if exitcount == exitnum:
        roomfile.write('  "' + rexit[0] + '" : ' + 'DIR+"/rooms/' + rexit[1] + '.c"\n')
      else:
        roomfile.write('  "' + rexit[0] + '" : ' + 'DIR+"/rooms/' + rexit[1] + '.c",\n')
    roomfile.write('  ]) );\n\n')
    # end code here
    roomfile.write('}\n\n')
```

# Results

## Room
A final room would look like this
```
inherit "/std/room";

#include "../domain.h"

void setup( void ) {

  set_domainname("Woodland Critter Christmas");
  set_coords(({ 5, 14 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. Animal prints can be seen on the ground." );

 set_exits( ([
  "west" : DIR+"/rooms/4_14.c",
  "east" : DIR+"/rooms/6_14.c",
  "south" : DIR+"/rooms/5_15.c"
  ]) );

}

int do_search(void) {
   object mob;
   mob = clone_object(DIR + "/npc/bear");
   mob->setup();
   mob->move(this_player()->query_environment());
   mob->attack(this_player());

   return 1;
}
```

## NPC
A final NPC would look like this

```
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
```

# Final Thoughts
with some mild tweaking and a few other things to make the level spread more fair this gives you what you need to generate a domain extremely fast
