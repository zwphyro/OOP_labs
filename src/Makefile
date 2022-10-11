all: main.o startdialog.o mainloop.o reader.o mediator.o painter.o eventfacade.o field.o cell.o player.o enemy.o interactor.o entity.o fieldevent.o spawnenemy.o teleportplayer.o playerevent.o addprogress.o addenergy.o enemycontroller.o
	g++ -g -std=c++17 main.o mainloop.o reader.o mediator.o painter.o field.o cell.o player.o enemy.o interactor.o startdialog.o entity.o fieldevent.o spawnenemy.o teleportplayer.o playerevent.o addprogress.o addenergy.o eventfacade.o enemycontroller.o -lncurses

main.o: ./Game/main.cpp ./Game/mainloop.h
	g++ -c -g -std=c++17 ./Game/main.cpp

startdialog.o: ./Reading/startdialog.cpp ./Reading/startdialog.h 
	g++ -c -g -std=c++17 ./Reading/startdialog.cpp

mainloop.o: ./Game/mainloop.cpp ./Game/mainloop.h ./Event/eventfacade.h ./Field/cell.h ./Reading/startdialog.h ./Field/position.h ./Reading/mediator.h ./Rendering/painter.h ./Field/field.h ./Entity/Player/interactor.h ./Entity/Player/player.h ./Entity/enemy.h ./Entity/Enemy/enemycontroller.h ./Event/spawnenemy.h ./Event/teleportplayer.h ./Reading/commands.h
	g++ -c -g -std=c++17 ./Game/mainloop.cpp

eventfacade.o: ./Event/eventfacade.cpp ./Event/eventfacade.h ./Event/addprogress.h ./Event/addenergy.h ./Event/spawnenemy.h ./Event/teleportplayer.h
	g++ -c -g -std=c++17 ./Event/eventfacade.cpp

reader.o: ./Reading/reader.cpp ./Reading/reader.h 
	g++ -c -g -std=c++17 ./Reading/reader.cpp -lncurses

mediator.o: ./Reading/mediator.cpp ./Reading/mediator.h ./Reading/reader.h ./Reading/commands.h
	g++ -c -g -std=c++17 ./Reading/mediator.cpp

interactor.o: ./Entity/Player/interactor.cpp ./Entity/Player/interactor.h ./Reading/commands.h ./Entity/Player/player.h ./Field/cell.h ./Field/field.h ./Field/position.h ./Event/addprogress.h ./Event/spawnenemy.h ./Event/eventfacade.h ./Reading/mediator.h ./Entity/direction.h
	g++ -c -g -std=c++17 ./Entity/Player/interactor.cpp

painter.o: ./Rendering/painter.cpp ./Rendering/painter.h ./Field/position.h ./Field/cell.h ./Field/field.h ./Entity/entitycontainer.h ./Entity/enemy.h ./Entity/Player/player.h ./Event/addenergy.h ./Event/addprogress.h ./Event/spawnenemy.h ./Event/teleportplayer.h
	g++ -c -g -std=c++17 ./Rendering/painter.cpp -lncurses

field.o: ./Field/field.cpp ./Field/field.h ./Entity/entitycontainer.h ./Field/position.h ./Entity/Player/player.h ./Entity/enemy.h ./Field/cell.h ./Event/eventfacade.h
	g++ -c -g -std=c++17 ./Field/field.cpp

cell.o: ./Field/cell.cpp ./Field/cell.h ./Event/event.h ./Event/event.h
	g++ -c -g -std=c++17 ./Field/cell.cpp

player.o: ./Entity/Player/player.cpp ./Entity/Player/player.h ./Entity/entity.h ./Entity/Player/interactor.h ./Entity/direction.h
	g++ -c -g -std=c++17 ./Entity/Player/player.cpp

enemy.o: ./Entity/enemy.cpp ./Entity/enemy.h ./Entity/entity.h ./Entity/Player/interactor.h ./Entity/direction.h 
	g++ -c -g -std=c++17 ./Entity/enemy.cpp

entity.o: ./Entity/entity.cpp ./Entity/entity.h
	g++ -c -g -std=c++17 ./Entity/entity.cpp

fieldevent.o: ./Event/fieldevent.cpp ./Event/fieldevent.h ./Event/event.h ./Event/event.h ./Field/field.h
	g++ -c -g -std=c++17 ./Event/fieldevent.cpp

spawnenemy.o: ./Event/spawnenemy.cpp ./Event/spawnenemy.h ./Event/fieldevent.h ./Field/field.h ./Entity/enemy.h ./Field/cell.h ./Event/eventfacade.h ./Event/addenergy.h
	g++ -c -g -std=c++17 ./Event/spawnenemy.cpp

teleportplayer.o: ./Event/teleportplayer.cpp ./Event/teleportplayer.h ./Event/fieldevent.h ./Field/cell.h ./Field/field.h ./Entity/enemy.h
	g++ -c -g -std=c++17 ./Event/teleportplayer.cpp

playerevent.o: ./Event/playerevent.cpp ./Event/playerevent.h ./Event/event.h ./Entity/Player/player.h
	g++ -c -g -std=c++17 ./Event/playerevent.cpp

addprogress.o: ./Event/addprogress.cpp ./Event/addprogress.h ./Event/playerevent.h ./Entity/Player/player.h
	g++ -c -g -std=c++17 ./Event/addprogress.cpp

addenergy.o: ./Event/addenergy.cpp ./Event/addenergy.h ./Event/playerevent.h ./Entity/Player/player.h
	g++ -c -g -std=c++17 ./Event/addenergy.cpp

enemycontroller.o: ./Entity/Enemy/enemycontroller.cpp ./Entity/Enemy/enemycontroller.h ./Entity/entitycontainer.h ./Entity/enemy.h ./Field/field.h ./Entity/direction.h ./Field/cell.h
	g++ -c -g -std=c++17 ./Entity/Enemy/enemycontroller.cpp

clean:
	rm *.o; rm a.out
