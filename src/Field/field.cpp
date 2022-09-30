#include "field.h"

Field::Field(int width, int height):width(width), height(height), controller(nullptr), factory(nullptr) {
	cell_arr = new Cell**[height];

    for (int i = 0; i < height; i++) {
        cell_arr[i] = new Cell*[width];
        for (int j = 0; j < width; j++) {
            cell_arr[i][j] = new Cell;
        }
    }

    player_container.entity = nullptr;
}

Field::Field(const Field& obj):width(obj.width), height(obj.height), controller(obj.controller), player_container(obj.player_container) {
    cell_arr = new Cell**[height];
    for (int i = 0; i < height; i++) {
        cell_arr[i] = new Cell*[width];
        for (int j = 0; j < width; j++) {
            cell_arr[i][j] = new Cell(*obj.cell_arr[i][j]);
        }
    }

    factory = new EventFactory(*obj.factory);
    
    for (auto elem: obj.enemys_container)
        enemys_container.push_back(elem);
}

Field& Field::operator=(const Field& obj) {
    if (this != &obj) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                delete cell_arr[i][j];
            }
            delete[] cell_arr[i];
        }
        delete[] cell_arr;

        enemys_container.clear();

        width = obj.width;
        height = obj.height;
        controller = obj.controller;
        player_container = obj.player_container;
        factory = new EventFactory(*obj.factory);

        cell_arr = new Cell**[height];
        for (int i = 0; i < height; i++) {
            cell_arr[i] = new Cell*[width];
            for (int j = 0; j < width; j++) {
                cell_arr[i][j] = new Cell(*obj.cell_arr[i][j]);
            }
        }
    
        for (auto elem: obj.enemys_container)
            enemys_container.push_back(elem);
    }

    return *this;
}

Field::Field(Field&& obj) {
    std::swap(width, obj.width);
    std::swap(height, obj.height);
    controller = nullptr;
    std::swap(controller, obj.controller);
    factory = nullptr;
    std::swap(factory, obj.factory);
    cell_arr = nullptr;
    std::swap(cell_arr, obj.cell_arr);
    std::swap(player_container, obj.player_container);
    enemys_container.swap(obj.enemys_container);
}

Field& Field::operator=(Field&& obj) {
    if (this != &obj) {
        std::swap(width, obj.width);
        std::swap(height, obj.height);
        controller = nullptr;
        std::swap(controller, obj.controller);
        factory = nullptr;
        std::swap(factory, obj.factory);
        cell_arr = nullptr;
        std::swap(cell_arr, obj.cell_arr);
        std::swap(player_container, obj.player_container);
        enemys_container.swap(obj.enemys_container);
    }

    return *this;
}

Field::~Field() {
    if (cell_arr) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                delete cell_arr[i][j];
            }
            delete[] cell_arr[i];
        }
        delete[] cell_arr;
    }

    if (factory)
        delete factory;

}

void Field::setController(PlayerController *controller) {
    this->controller = controller;
}

void Field::setFactory(EventFactory *factory) {
    this->factory = factory;
}

Position Field::getRandomFreePosition() {
    std::srand(std::time(nullptr));

    Position random_position;
    do {
        random_position.x = std::rand()%width;
        random_position.y = std::rand()%height;
    } while (cell_arr[random_position.y][random_position.x]->isOccupied());

    return random_position;
}

int Field::getWidth() const {
	return width;
}

int Field::getHeight() const {
	return height;
}

EntityContainer Field::getPlayerContainer() const {
    return player_container;
}

EnemyVector Field::getEnemysContainer() const {
    return enemys_container;
}

void Field::addEntity(const Player *entity, Position position) {
    if (position.x >= width || position.x < 0 || position.y >= height || position.y < 0 || cell_arr[position.y][position.x]->isOccupied()) return;

    player_container.entity = entity;
    player_container.position = position;
    cell_arr[position.y][position.x]->playerStepped();

}

void Field::addEntity(const Enemy *entity, Position position) {
    if (position.x >= width || position.x < 0 || position.y >= height || position.y < 0 || cell_arr[position.y][position.x]->isOccupied()) return;

    enemys_container.push_back({entity, position});
    cell_arr[position.y][position.x]->enemyStepped();

}

EventFactory &Field::getFactory() {
    return *factory;
} 

void Field::setEvent(Event *event, Position position) {
    if (position.x >= width || position.x < 0 || position.y >= height || position.y < 0) return;
    cell_arr[position.y][position.x]->setEvent(event);
    
    if (player_container.position == position)
        cell_arr[position.y][position.x]->playerStepped();
}

const Event *Field::getEvent(Position position) const {
    return cell_arr[position.y][position.x]->getEvent();
}

Position Field::calculatePlayerSidePosition(int direction) {
    enum {UP, DOWN, RIGHT, LEFT};
    int old_x = player_container.position.x;
    int old_y = player_container.position.y;
    int new_x, new_y;

    switch (direction) {
        case UP:
            new_x = old_x;
            new_y = (old_y-1+height)%height;
            break;
        case DOWN:
            new_x = old_x;
            new_y = (old_y+1)%height;
            break;
        case RIGHT:
            new_x = (old_x+1)%width;
            new_y = old_y;
            break;
        case LEFT:
            new_x = (old_x-1+width)%width;
            new_y = old_y;
            break;
    }

    return {new_x, new_y};
}

bool Field::movePlayer(int direction) {
    Position new_position = calculatePlayerSidePosition(direction);
    Position old_position = player_container.position;

    if (cell_arr[new_position.y][new_position.x]->isOccupied()) return false;
        
    player_container.position = new_position;
    cell_arr[new_position.y][new_position.x]->playerStepped();
    cell_arr[old_position.y][old_position.x]->entityGone();

    return true;
}

void Field::processDamage(int direction) {
    Position damaged_position = calculatePlayerSidePosition(direction);

    if (!cell_arr[damaged_position.y][damaged_position.x]->isOccupied()) return;
    for (int i = 0; i < enemys_container.size(); i++) {
        if (damaged_position == enemys_container[i].position) {
            cell_arr[damaged_position.y][damaged_position.x]->entityGone();
            delete enemys_container[i].entity;
            enemys_container.erase(enemys_container.begin()+i);
            
            setEvent(factory->createEvent(new AddProgress), damaged_position);
            setEvent(factory->createEvent(new SpawnEnemy), getRandomFreePosition());

            break;
        }
    }
}
