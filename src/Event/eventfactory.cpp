#include "eventfactory.h"

EventFactory::EventFactory(Player *player, Field *field) {
	add_energy_event = new AddEnergy(player);
	add_progress_event = new AddProgress(player);
	spawn_enemy_event = new SpawnEnemy(field);

}

EventFactory::EventFactory(const EventFactory& obj) {
	add_energy_event = new AddEnergy(*obj.add_energy_event);
	add_progress_event = new AddProgress(*obj.add_progress_event);
	spawn_enemy_event = new SpawnEnemy(*obj.spawn_enemy_event);

}

EventFactory& EventFactory::operator=(const EventFactory& obj) {
	if (this != &obj) {
		delete add_energy_event;
		delete add_progress_event;
		delete spawn_enemy_event;

		add_energy_event = new AddEnergy(*obj.add_energy_event);
		add_progress_event = new AddProgress(*obj.add_progress_event);
		spawn_enemy_event = new SpawnEnemy(*obj.spawn_enemy_event);
	
	}

	return *this;
}

EventFactory::~EventFactory() {
	delete add_energy_event;
	delete add_progress_event;
	delete spawn_enemy_event;

}

void EventFactory::setPlayer(Player *player) {
	add_energy_event->setPlayer(player);
	add_progress_event->setPlayer(player);

}

void EventFactory::setField(Field *field) {
	spawn_enemy_event->setField(field);

}

Event *EventFactory::createEvent(Event *event) {
	if (dynamic_cast<AddEnergy*>(event)) {
		delete event;
		return new AddEnergy(*add_energy_event);
	} else if (dynamic_cast<AddProgress*>(event)) {
		delete event;
		return new AddProgress(*add_progress_event);
	} else if (dynamic_cast<SpawnEnemy*>(event)) {
		delete event;
		return new SpawnEnemy(*spawn_enemy_event);
	}
	return nullptr;
}
