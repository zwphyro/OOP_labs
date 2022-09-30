 
all: main.o startdialog.o mainloop.o reader.o painter.o eventfactory.o field.o cell.o player.o enemy.o playercontroller.o entity.o fieldevent.o spawnenemy.o playerevent.o addprogress.o addenergy.o fieldbuilder.o
	g++ -g -std=c++17 main.o mainloop.o reader.o painter.o field.o cell.o player.o enemy.o playercontroller.o startdialog.o entity.o fieldevent.o spawnenemy.o playerevent.o addprogress.o addenergy.o fieldbuilder.o eventfactory.o -lncurses

main.o: ./Game/main.cpp
	g++ -c -g -std=c++17 ./Game/main.cpp

startdialog.o: ./Reading/startdialog.cpp ./Reading/startdialog.h 
	g++ -c -g -std=c++17 ./Reading/startdialog.cpp

mainloop.o: ./Game/mainloop.cpp ./Game/mainloop.h 
	g++ -c -g -std=c++17 ./Game/mainloop.cpp

fieldbuilder.o: ./Field/fieldbuilder.cpp ./Field/fieldbuilder.h playercontroller.o field.o player.o
	g++ -c -g -std=c++17 ./Field/fieldbuilder.cpp 

eventfactory.o: ./Event/eventfactory.cpp ./Event/eventfactory.h addenergy.o addprogress.o spawnenemy.o 
	g++ -c -g -std=c++17 ./Event/eventfactory.cpp

reader.o: ./Reading/reader.cpp ./Reading/reader.h 
	g++ -c -g -std=c++17 ./Reading/reader.cpp -lncurses

playercontroller.o: ./Entity/Player/playercontroller.cpp ./Entity/Player/playercontroller.h field.o player.o
	g++ -c -g -std=c++17 ./Entity/Player/playercontroller.cpp

painter.o: ./Rendering/painter.cpp ./Rendering/painter.h ./Field/position.h entity.o
	g++ -c -g -std=c++17 ./Rendering/painter.cpp -lncurses

field.o: ./Field/field.cpp ./Field/field.h cell.o playercontroller.o
	g++ -c -g -std=c++17 ./Field/field.cpp

cell.o: ./Field/cell.cpp ./Field/cell.h ./Event/event.h entity.o
	g++ -c -g -std=c++17 ./Field/cell.cpp

player.o: ./Entity/Player/player.cpp ./Entity/Player/player.h playercontroller.o entity.o
	g++ -c -g -std=c++17 ./Entity/Player/player.cpp

enemy.o: ./Entity/enemy.cpp ./Entity/enemy.h entity.o
	g++ -c -g -std=c++17 ./Entity/enemy.cpp

entity.o: ./Entity/entity.cpp ./Entity/entity.h
	g++ -c -g -std=c++17 ./Entity/entity.cpp

fieldevent.o: ./Event/fieldevent.cpp ./Event/fieldevent.h ./Event/event.h
	g++ -c -g -std=c++17 ./Event/fieldevent.cpp

spawnenemy.o: ./Event/spawnenemy.cpp ./Event/spawnenemy.h fieldevent.o enemy.o
	g++ -c -g -std=c++17 ./Event/spawnenemy.cpp

playerevent.o: ./Event/playerevent.cpp ./Event/playerevent.h ./Event/event.h
	g++ -c -g -std=c++17 ./Event/playerevent.cpp

addprogress.o: ./Event/addprogress.cpp ./Event/addprogress.h playerevent.o
	g++ -c -g -std=c++17 ./Event/addprogress.cpp

addenergy.o: ./Event/addenergy.cpp ./Event/addenergy.h playerevent.o
	g++ -c -g -std=c++17 ./Event/addenergy.cpp
