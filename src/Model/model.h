#ifndef MODEL_H
#define MODEL_H

class View;

class Model
{
public:
    Model(View *view = nullptr);
    void setView(View *view);
    void update();

private:
    View *_view;
};

#endif
