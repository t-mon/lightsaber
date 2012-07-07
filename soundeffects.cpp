#include "soundeffects.h"
#include <QAudioFormat>
#include <QMediaPlaylist>
#include <QMediaPlayer>


Soundeffects::Soundeffects(QObject *parent) :
    QObject(parent)
{    
    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl::fromLocalFile("/home/user/lightsaber/Hum 4.wav"));
    playlist->setPlaybackMode( QMediaPlaylist::Loop );
    m_player_background.setPlaylist(playlist);
    m_player_background.setVolume(100);
    lightsaberPowerStatus = false;

}

void Soundeffects::playSaberEffect(const QString &soundfile)
{

    if(lightsaberPowerStatus){
        if(m_player.state() == QMediaPlayer::PlayingState){
            qDebug() << "still playing sound";
        }else{
            m_player.setMedia(QUrl::fromLocalFile(soundfile));
            m_player.setVolume(100);
            m_player.play();
        }
    }
}



void Soundeffects::playOnOffSound(const bool &lightsaberPower)
{
    if(lightsaberPower){
        m_player.setMedia(QUrl::fromLocalFile("/home/user/lightsaber/On1.wav"));
        m_player.setVolume(100);
        m_player.play();
        lightsaberPowerStatus = lightsaberPower;

    } else {
        m_player.setMedia(QUrl::fromLocalFile("/home/user/lightsaber/Off1.wav"));
        m_player.setVolume(100);
        m_player.play();
        lightsaberPowerStatus = lightsaberPower;

    }
}
