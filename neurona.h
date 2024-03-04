#ifndef NEURONA_H
#define NEURONA_H

#include <QString>

class Neurona {
public:
    Neurona(QString id, double voltaje, int posX, int posY, int red, int green, int blue);

    QString getID() const;
    double getVoltaje() const;
    int getPosX() const;
    int getPosY() const;
    int getRed() const;
    int getGreen() const;
    int getBlue() const;

private:
    QString m_id;
    double m_voltaje;
    int m_posX;
    int m_posY;
    int m_red;
    int m_green;
    int m_blue;
};

#endif // NEURONA_H
