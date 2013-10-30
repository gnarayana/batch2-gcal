testMenu:gCalTypes.o gCalGen.o menu.o testMenu.o
			g++ -o testMenu gCalTypes.o gCalGen.o menu.o testMenu.o
testReadConfig:gCalTypes.o gCalGen.o readConfig.o testReadConfig.o
			g++ -o testReadConfig gCalTypes.o gCalGen.o readConfig.o testReadConfig.o
gCalTypes.o:../gCalTypes.cpp
			g++ -c ../gCalTypes.cpp -I../../incl
gCalGen.o:../gCalGen.cpp
			g++ -c ../gCalGen.cpp -I../../incl
menu.o:../menu.cpp
			g++ -c ../menu.cpp -I../../incl
readConfig.o:../readConfig.cpp
			g++ -c ../readConfig.cpp -I../../incl
testReadConfig.o:testReadConfig.cpp
			g++ -c testReadConfig.cpp -I../../incl
testMenu.o:testMenu.cpp
			g++ -c testMenu.cpp -I../../incl
clean:
			rm -f *.o testReadConfig testMenu
