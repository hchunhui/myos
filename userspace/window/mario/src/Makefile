AUTOOBJS= BeetleDemon.o Brick.o BrokenBrick.o Bullet.o ClipDemon.o Coin.o Control.o Flower.o FlyTortoiseDemon.o Fungus.o FungusDemon.o Game.o Graph.o GraphMan.o Ground.o ImgData.o main.o MapData.o Mario.o Object.o PipeBody.o PipeTop.o Question.o Sound.o SoundMan.o Star.o Stone.o TortoiseDemon.o  ##auto 
CC=i686-myos-elf-g++
CPP=i686-myos-elf-g++ -E
CFLAGS=-O3
OBJS=$(AUTOOBJS) mario

.PHONY: all every everything clean dep
everything: $(OBJS)
.cpp.o:
	$(CC) $(CFLAGS) \
	-c -o $*.o $<
.s.o:
	$(CC) $(CFLAGS)	\
	-c -o $*.o $<
mario: ../../../obj/w/draw.o $(AUTOOBJS) ../../../obj/w/msg.o
	$(CC) -o $@ $^

all:clean everything
clean:
	rm -f mario
	rm -f *.o *~
dep:
	sed '/\#\#auto/d;/\#\#dep/q' Makefile>tmp_make
	for i in *.cpp;do `echo $$i|sed '/^/s//$(CPP) -MM /;/*/d'`>>tmp_make;done
	echo AUTOOBJS=|tr "\n" " ">tmp_make2
	
	ls -m *.cpp|sed 's/\.cpp/.o/g;s/,//g'|tr "\n" " "|\
	sed '/$$/a\#\#auto'|tr "\n" " "|sed '/$$/a\'>>tmp_make2
	
	cat tmp_make2 tmp_make>Makefile
	rm -f tmp_make tmp_make2
	
##dep
BeetleDemon.o: BeetleDemon.cpp BeetleDemon.h Object.h ImgData.h Game.h \
 Mario.h SoundMan.h Sound.h
Brick.o: Brick.cpp Brick.h Object.h ImgData.h Game.h Mario.h SoundMan.h \
 Sound.h Fungus.h Flower.h Question.h Star.h Coin.h BrokenBrick.h
BrokenBrick.o: BrokenBrick.cpp BrokenBrick.h Object.h ImgData.h Game.h \
 Mario.h SoundMan.h Sound.h
Bullet.o: Bullet.cpp Bullet.h Object.h ImgData.h Game.h Mario.h \
 SoundMan.h Sound.h
ClipDemon.o: ClipDemon.cpp ClipDemon.h Object.h ImgData.h Game.h Mario.h \
 SoundMan.h Sound.h
Coin.o: Coin.cpp Coin.h Object.h ImgData.h Game.h Mario.h SoundMan.h \
 Sound.h
Control.o: Control.cpp Control.h GraphMan.h Graph.h cross.h \
 ../../w/draw.h ../../w/bmp.h ../../w/wtype.h ../../w/msg.h \
 ../../../libkb/kb_state.h Game.h Object.h Mario.h SoundMan.h Sound.h
Flower.o: Flower.cpp Flower.h Object.h ImgData.h Game.h Mario.h \
 SoundMan.h Sound.h
FlyTortoiseDemon.o: FlyTortoiseDemon.cpp FlyTortoiseDemon.h Object.h \
 ImgData.h Game.h Mario.h SoundMan.h Sound.h TortoiseDemon.h
Fungus.o: Fungus.cpp Fungus.h Object.h ImgData.h Game.h Mario.h \
 SoundMan.h Sound.h
FungusDemon.o: FungusDemon.cpp FungusDemon.h Object.h ImgData.h Game.h \
 Mario.h SoundMan.h Sound.h
Game.o: Game.cpp Game.h Object.h Mario.h SoundMan.h Sound.h MapData.h \
 Brick.h Ground.h Stone.h PipeBody.h PipeTop.h Question.h FungusDemon.h \
 TortoiseDemon.h FlyTortoiseDemon.h ClipDemon.h BeetleDemon.h Coin.h \
 cross.h ../../w/draw.h ../../w/bmp.h ../../w/wtype.h ../../w/msg.h \
 ../../../libkb/kb_state.h
Graph.o: Graph.cpp cross.h ../../w/draw.h ../../w/bmp.h ../../w/wtype.h \
 ../../w/msg.h ../../../libkb/kb_state.h Graph.h
GraphMan.o: GraphMan.cpp GraphMan.h Graph.h cross.h ../../w/draw.h \
 ../../w/bmp.h ../../w/wtype.h ../../w/msg.h ../../../libkb/kb_state.h \
 Game.h Object.h Mario.h SoundMan.h Sound.h
Ground.o: Ground.cpp Ground.h Object.h ImgData.h Game.h Mario.h \
 SoundMan.h Sound.h
ImgData.o: ImgData.cpp
MapData.o: MapData.cpp
Mario.o: Mario.cpp cross.h ../../w/draw.h ../../w/bmp.h ../../w/wtype.h \
 ../../w/msg.h ../../../libkb/kb_state.h Mario.h Object.h ImgData.h \
 Game.h SoundMan.h Sound.h Bullet.h
Object.o: Object.cpp Object.h
PipeBody.o: PipeBody.cpp PipeBody.h Object.h ImgData.h Game.h Mario.h \
 SoundMan.h Sound.h
PipeTop.o: PipeTop.cpp PipeTop.h Object.h ImgData.h Game.h Mario.h \
 SoundMan.h Sound.h
Question.o: Question.cpp Question.h Object.h ImgData.h Game.h Mario.h \
 SoundMan.h Sound.h Fungus.h Flower.h Coin.h
Sound.o: Sound.cpp cross.h ../../w/draw.h ../../w/bmp.h ../../w/wtype.h \
 ../../w/msg.h ../../../libkb/kb_state.h Sound.h
SoundMan.o: SoundMan.cpp SoundMan.h Sound.h cross.h ../../w/draw.h \
 ../../w/bmp.h ../../w/wtype.h ../../w/msg.h ../../../libkb/kb_state.h
Star.o: Star.cpp Star.h Object.h ImgData.h Game.h Mario.h SoundMan.h \
 Sound.h
Stone.o: Stone.cpp Stone.h Object.h ImgData.h Game.h Mario.h SoundMan.h \
 Sound.h
TortoiseDemon.o: TortoiseDemon.cpp TortoiseDemon.h Object.h ImgData.h \
 Game.h Mario.h SoundMan.h Sound.h
main.o: main.cpp Graph.h cross.h ../../w/draw.h ../../w/bmp.h \
 ../../w/wtype.h ../../w/msg.h ../../../libkb/kb_state.h GraphMan.h \
 Game.h Object.h Mario.h SoundMan.h Sound.h Control.h
