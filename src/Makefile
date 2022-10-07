all: main.o startdialog.o mainloop.o reader.o mediator.o painter.o eventfacade.o field.o cell.o player.o enemy.o interactor.o entity.o fieldevent.o spawnenemy.o teleportplayer.o playerevent.o addprogress.o addenergy.o enemycontroller.o
	g++ -g -std=c++17 main.o mainloop.o reader.o mediator.o painter.o field.o cell.o player.o enemy.o interactor.o startdialog.o entity.o fieldevent.o spawnenemy.o teleportplayer.o playerevent.o addprogress.o addenergy.o eventfacade.o enemycontroller.o -lncurses

main.o: ./Game/main.cpp
	g++ -c -g -std=c++17 ./Game/main.cpp

startdialog.o: ./Reading/startdialog.cpp ./Reading/startdialog.h 
	g++ -c -g -std=c++17 ./Reading/startdialog.cpp

mainloop.o: ./Game/mainloop.cpp ./Game/mainloop.h 
	g++ -c -g -std=c++17 ./Game/mainloop.cpp

eventfacade.o: ./Event/eventfacade.cpp ./Event/eventfacade.h addenergy.o addprogress.o spawnenemy.o 
	g++ -c -g -std=c++17 ./Event/eventfacade.cpp

reader.o: ./Reading/reader.cpp ./Reading/reader.h 
	g++ -c -g -std=c++17 ./Reading/reader.cpp -lncurses

mediator.o: ./Reading/mediator.cpp ./Reading/mediator.h reader.o
	g++ -c -g -std=c++17 ./Reading/mediator.cpp

interactor.o: ./Entity/Player/interactor.cpp ./Entity/Player/interactor.h field.o player.o
	g++ -c -g -std=c++17 ./Entity/Player/interactor.cpp

painter.o: ./Rendering/painter.cpp ./Rendering/painter.h ./Field/position.h entity.o
	g++ -c -g -std=c++17 ./Rendering/painter.cpp -lncurses

field.o: ./Field/field.cpp ./Field/field.h cell.o interactor.o
	g++ -c -g -std=c++17 ./Field/field.cpp

cell.o: ./Field/cell.cpp ./Field/cell.h ./Event/event.h entity.o
	g++ -c -g -std=c++17 ./Field/cell.cpp

player.o: ./Entity/Player/player.cpp ./Entity/Player/player.h interactor.o entity.o
	g++ -c -g -std=c++17 ./Entity/Player/player.cpp

enemy.o: ./Entity/enemy.cpp ./Entity/enemy.h entity.o
	g++ -c -g -std=c++17 ./Entity/enemy.cpp

entity.o: ./Entity/entity.cpp ./Entity/entity.h
	g++ -c -g -std=c++17 ./Entity/entity.cpp

fieldevent.o: ./Event/fieldevent.cpp ./Event/fieldevent.h ./Event/event.h
	g++ -c -g -std=c++17 ./Event/fieldevent.cpp

spawnenemy.o: ./Event/spawnenemy.cpp ./Event/spawnenemy.h fieldevent.o enemy.o
	g++ -c -g -std=c++17 ./Event/spawnenemy.cpp

teleportplayer.o: ./Event/teleportplayer.cpp ./Event/teleportplayer.h fieldevent.o
	g++ -c -g -std=c++17 ./Event/teleportplayer.cpp

playerevent.o: ./Event/playerevent.cpp ./Event/playerevent.h ./Event/event.h
	g++ -c -g -std=c++17 ./Event/playerevent.cpp

addprogress.o: ./Event/addprogress.cpp ./Event/addprogress.h playerevent.o
	g++ -c -g -std=c++17 ./Event/addprogress.cpp

addenergy.o: ./Event/addenergy.cpp ./Event/addenergy.h playerevent.o
	g++ -c -g -std=c++17 ./Event/addenergy.cpp

enemycontroller.o: ./Entity/Enemy/enemycontroller.cpp ./Entity/Enemy/enemycontroller.h
	g++ -c -g -std=c++17 ./Entity/Enemy/enemycontroller.cpp

clean:
	rm *.o; rm a.out
