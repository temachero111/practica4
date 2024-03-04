#include "neurona.h"

Neurona::Neurona(QString id, double voltaje, int posX, int posY, int red, int green, int blue)
    : m_id(id), m_voltaje(voltaje), m_posX(posX), m_posY(posY), m_red(red), m_green(green), m_blue(blue) {}

QString Neurona::getID() const {
    return m_id;
}

double Neurona::getVoltaje() const {
    return m_voltaje;
}

int Neurona::getPosX() const {
    return m_posX;
}

int Neurona::getPosY() const {
    return m_posY;
}

int Neurona::getRed() const {
    return m_red;
}

int Neurona::getGreen() const {
    return m_green;
}

int Neurona::getBlue() const {
    return m_blue;
}
