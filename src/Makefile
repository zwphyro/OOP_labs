all: main.o mainloop.o reader.o mediator.o painter.o eventfacade.o field.o cell.o player.o enemy.o interactor.o entity.o fieldevent.o spawnenemy.o teleportplayer.o playerevent.o addprogress.o addenergy.o enemycontroller.o position.o filelogger.o observable.o observer.o logmessage.o logpermissions.o consolelogger.o gamecontroller.o entitycontainer.o menubuilder.o menucontroller.o menumodel.o menuview.o model.o menuparameters.o screeninitializer.o optionsview.o optionsbuilder.o optionscontroller.o optionsmodel.o optionsparameters.o
	g++ -g -std=c++17 main.o mainloop.o reader.o mediator.o painter.o field.o cell.o player.o enemy.o interactor.o entity.o fieldevent.o spawnenemy.o teleportplayer.o playerevent.o addprogress.o addenergy.o eventfacade.o enemycontroller.o position.o filelogger.o observable.o observer.o logmessage.o logpermissions.o consolelogger.o gamecontroller.o entitycontainer.o menubuilder.o menucontroller.o menumodel.o menuview.o model.o menuparameters.o screeninitializer.o optionsview.o optionsbuilder.o optionscontroller.o optionsmodel.o optionsparameters.o -lncurses

main.o: ./Game/main.cpp ./Game/mainloop.h
	g++ -c -g -std=c++17 ./Game/main.cpp

mainloop.o: ./Game/mainloop.cpp ./Game/mainloop.h ./Event/eventfacade.h ./Field/cell.h ./Field/position.h ./Reading/mediator.h ./Rendering/painter.h ./Field/field.h ./Entity/Player/interactor.h ./Entity/Player/player.h ./Entity/enemy.h ./Entity/Enemy/enemycontroller.h ./Event/spawnenemy.h ./Event/teleportplayer.h ./Reading/commands.h
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

position.o: ./Field/position.cpp ./Field/position.h
	g++ -c -g -std=c++17 ./Field/position.cpp

filelogger.o: ./Logging/filelogger.cpp ./Logging/filelogger.h
	g++ -c -g -std=c++17 ./Logging/filelogger.cpp

observable.o: ./Logging/observable.cpp ./Logging/observable.h
	g++ -c -g -std=c++17 ./Logging/observable.cpp

observer.o: ./Logging/observer.cpp ./Logging/observer.h
	g++ -c -g -std=c++17 ./Logging/observer.cpp

logmessage.o: ./Logging/logmessage.cpp ./Logging/logmessage.h
	g++ -c -g -std=c++17 ./Logging/logmessage.cpp

logpermissions.o: ./Logging/logpermissions.cpp ./Logging/logpermissions.h
	g++ -c -g -std=c++17 ./Logging/logpermissions.cpp

consolelogger.o: ./Logging/consolelogger.cpp ./Logging/consolelogger.h 
	g++ -c -g -std=c++17 ./Logging/consolelogger.cpp

gamecontroller.o: ./Game/gamecontroller.cpp ./Game/gamecontroller.h
	g++ -c -g -std=c++17 ./Game/gamecontroller.cpp

entitycontainer.o: ./Entity/entitycontainer.cpp ./Entity/entitycontainer.h 
	g++ -c -g -std=c++17 ./Entity/entitycontainer.cpp

menubuilder.o: ./Interface/Menu/menubuilder.cpp ./Interface/Menu/menubuilder.h ./Interface/Menu/menucontroller.h ./Interface/Menu/menumodel.h ./Rendering/Views/menuview.h ./Interface/Menu/menuparameters.h
	g++ -c -g -std=c++17 ./Interface/Menu/menubuilder.cpp

menucontroller.o: ./Interface/Menu/menucontroller.cpp ./Interface/Menu/menucontroller.h ./Interface/Menu/menumodel.h
	g++ -c -g -std=c++17 ./Interface/Menu/menucontroller.cpp -lncurses

menumodel.o: ./Interface/Menu/menumodel.cpp ./Interface/Menu/menumodel.h ./Model/model.h ./Interface/Menu/menuparameters.cpp
	g++ -c -g -std=c++17 ./Interface/Menu/menumodel.cpp

menuparameters.o: ./Interface/Menu/menuparameters.cpp ./Interface/Menu/menuparameters.h
	g++ -c -g -std=c++17 ./Interface/Menu/menuparameters.cpp

menuview.o: ./Rendering/Views/menuview.cpp ./Rendering/Views/menuview.h ./Interface/Menu/menuparameters.h
	g++ -c -g -std=c++17 ./Rendering/Views/menuview.cpp -lncurses

model.o: ./Model/model.cpp ./Model/model.h ./Rendering/view.h
	g++ -c -g -std=c++17 ./Model/model.cpp

screeninitializer.o: ./Rendering/screeninitializer.cpp ./Rendering/screeninitializer.h
	g++ -c -g -std=c++17 ./Rendering/screeninitializer.cpp

optionsview.o: ./Rendering/Views/optionsview.cpp ./Rendering/Views/optionsview.h ./Rendering/view.h ./Interface/Options/optionsparameters.h
	g++ -c -g -std=c++17 ./Rendering/Views/optionsview.cpp -lncurses

optionsbuilder.o: ./Interface/Options/optionsbuilder.cpp ./Interface/Options/optionsbuilder.h ./Interface/Options/optionscontroller.h ./Interface/Options/optionsmodel.h ./Interface/Options/optionsparameters.h ./Rendering/Views/optionsview.h
	g++ -c -g -std=c++17 ./Interface/Options/optionsbuilder.cpp

optionscontroller.o: ./Interface/Options/optionscontroller.cpp ./Interface/Options/optionscontroller.h ./Interface/Options/optionsmodel.h ./Reading/reader.h
	g++ -c -g -std=c++17 ./Interface/Options/optionscontroller.cpp -lncurses

optionsmodel.o: ./Interface/Options/optionsmodel.cpp ./Interface/Options/optionsmodel.h ./Model/model.h ./Interface/Options/optionsparameters.h
	g++ -c -g -std=c++17 ./Interface/Options/optionsmodel.cpp

optionsparameters.o: ./Interface/Options/optionsparameters.cpp ./Interface/Options/optionsparameters.h
	g++ -c -g -std=c++17 ./Interface/Options/optionsparameters.cpp

clean:
	rm *.o; rm a.out
