#ifndef SOUNDEFFECTS_H
#define SOUNDEFFECTS_H

#include <QObject>
#include <QMediaPlayer>
#include <QSettings>

class Soundeffects : public QObject
{
    Q_OBJECT
public:
    explicit Soundeffects(QObject *parent = 0);

    enum SoundEffect{
        SoundEffectHit,
        SoundEffectSwing,
        SoundEffectOn,
        SoundEffectOff
    };

private:
    QMediaPlayer m_player;

    bool lightsaberPowerStatus;
    bool vibrationStatusOnOff;


signals:
    void playHitsound();
    void playSwingsound();
    
public slots:
    void playSaberEffect(SoundEffect soundEffect);
    void playOnOffSound(const bool &lightsaberPower);
};

#endif // SOUNDEFFECTS_H
