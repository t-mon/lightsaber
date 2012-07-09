#include "soundeffects.h"
#include <QAudioFormat>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QSettings>


Soundeffects::Soundeffects(QObject *parent) :
    QObject(parent)
{    

    m_settings = new QSettings("lightsaber");
    lightsaberPowerStatus = false;
    swing = 0;
    hit = 1;

}

void Soundeffects::playSaberEffect(const int &swingOrHit)
{

    if(lightsaberPowerStatus){
        if(m_player.state() == QMediaPlayer::PlayingState){
            qDebug() << "still playing sound";
        }else{
            if(swingOrHit == hit){
                m_player.setMedia(QUrl::fromLocalFile("/opt/lightsaber/soundeffects/hit2.wav"));
                m_player.setVolume(100);
                m_player.play();
                if(m_settings->value("Vibration").toBool()){
                    emit playHitsound();
                }
            }
            if(swingOrHit == swing){
                m_player.setMedia(QUrl::fromLocalFile("/opt/lightsaber/soundeffects/swing.wav"));
                m_player.setVolume(100);
                m_player.play();
                if(m_settings->value("Vibration").toBool()){
                    emit playSwingsound();
                }
            }
        }
    }
}



void Soundeffects::playOnOffSound(const bool &lightsaberPower)
{
    if(lightsaberPower){
        m_player.setMedia(QUrl::fromLocalFile("/opt/lightsaber/soundeffects/on.wav"));
        m_player.setVolume(100);
        m_player.play();
        lightsaberPowerStatus = lightsaberPower;

    } else {
        m_player.setMedia(QUrl::fromLocalFile("/opt/lightsaber/soundeffects/off.wav"));
        m_player.setVolume(100);
        m_player.play();
        lightsaberPowerStatus = lightsaberPower;

    }
}

