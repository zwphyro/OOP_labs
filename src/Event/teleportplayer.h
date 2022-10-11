#ifndef TELEPORTPLAYER_H
#define TELEPORTPLAYER_H

#include "fieldevent.h"

class TeleportPlayer : public FieldEvent
{
public:
    TeleportPlayer(Field *field = nullptr);
    TeleportPlayer(const TeleportPlayer &obj);
    TeleportPlayer &operator=(const TeleportPlayer &obj);

    bool action();
};

#endif
