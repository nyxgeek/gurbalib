from random import *

genpath="/home/thotcon/gurbalib/lib/domains/woodland/gen"
roompath="/home/thotcon/gurbalib/lib/domains/woodland/rooms"
mobpath="/home/thotcon/gurbalib/lib/domains/woodland/npc"
incdir=""
area="woodland"

room_array = []
dimensions = ["12", "16"]
mob_array = ["deer", "rabbit", "snake", "bear", "porcupine", "moose", "beaver", "rat", "deer"]
room_mobs = []

fh = open(genpath + '/exits')

seed(random())

for line in fh:
    exits = line.rstrip().split(":")[1].split(",")
    roomname = line.rstrip().split(":")[0]
    translated = []
    co_ords = roomname.split("_")
    map_x = co_ords[0]
    map_y = co_ords[1]
    for exit in exits:
      if exit == "w":
        translated.append(["west",str(int(map_x) - 1) + "_" + str(map_y)])
      if exit == "e":
        translated.append(["east",str(int(map_x) + 1) + "_" + str(map_y)])
      if exit == "n":
        translated.append(["north",str(map_x) + "_" + str(int(map_y) - 1)])
      if exit == "s":
        translated.append(["south",str(map_x) + "_" + str(int(map_y) + 1)])
      if exit == "nw":
        translated.append(["northwest",str(int(map_x) - 1) + "_" + str(int(map_y) - 1)])
      if exit == "ne":
        translated.append(["northeast",str(int(map_x) + 1) + "_" + str(int(map_y) - 1)])
      if exit == "sw":
        translated.append(["southwest",str(int(map_x) - 1) + "_" + str(int(map_y) + 1)])
      if exit == "se":
        translated.append(["southeast",str(int(map_x) + 1) + "_" + str(int(map_y) + 1)])
    room_array.append([roomname, translated])
    seed(randint(0, 16))
    seed(randint(0, 16))
    if randint(0, 2) == randint(0, 2):
      if len(mob_array) > 0:
        mobindex = randint(0, (len(mob_array) - 1))
        mobname = mob_array[mobindex]
        mob_array.remove(mobname)
        room_mobs.append([roomname, mobname])

fh.close()

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

for rn in room_array:
  roomname = rn[0]
  exit_array = rn[1]
  room_moblist = [s for s in room_mobs if roomname in s]
  if room_moblist:
    print room_moblist
  coords = roomname.split("_")
  rshort = "Woodland"
  rlong = "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. "
  if room_moblist:
    rlong = rlong + "Animal prints can be seen on the ground."
  roomfile = open(roompath + "/" + roomname + ".c", "w")
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
    # do search code to find mob
    if room_moblist:
      roomfile.write('int do_search(void) {\n')
      roomfile.write('   object mob;\n')
      for mob in room_moblist:
        roomfile.write('   mob = clone_object(DIR + "/npc/' + mob[1] + '");\n')
        roomfile.write('   mob->setup();\n')
        roomfile.write('   mob->move(this_player()->query_environment());\n')
        roomfile.write('   mob->attack(this_player());\n\n')
      roomfile.write('   return 1;\n}\n')
      roomfile.close

