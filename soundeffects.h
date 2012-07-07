#ifndef SOUNDEFFECTS_H
#define SOUNDEFFECTS_H

#include <QObject>
#include <QMediaPlayer>

class Soundeffects : public QObject
{
    Q_OBJECT
public:
    explicit Soundeffects(QObject *parent = 0);
    
private:
    QMediaPlayer m_player;
    QMediaPlayer m_player_background;
    QMediaPlaylist * playlist;
    bool lightsaberPowerStatus;

signals:
    
public slots:
    void playSaberEffect(const QString &soundfile);
    void playOnOffSound(const bool &lightsaberPower);
};

#endif // SOUNDEFFECTS_H
