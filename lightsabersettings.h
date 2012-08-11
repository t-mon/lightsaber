#ifndef LIGHTSABERSETTINGS_H
#define LIGHTSABERSETTINGS_H

#include <QObject>
#include <QSettings>

class LightsaberSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int lightsaberSensitivityHit READ lightsaberSensitivityHit WRITE setlightsaberSensitivityHit NOTIFY lightsaberHitSensChanged())
    Q_PROPERTY(int lightsaberSensitivitySwing READ lightsaberSensitivitySwing WRITE setlightsaberSensitivitySwing NOTIFY lightsaberSwingSensChanged())
    Q_PROPERTY(bool keepDisplayOn READ isDisplayStateOn WRITE setDisplayStateOn NOTIFY keepDisplayOnChanged())
    Q_PROPERTY(bool showStatusBar READ isShowStatusBarOn WRITE setShowStatusBar NOTIFY showStatusBarChanged())
    Q_PROPERTY(QString lightsaberColor READ lightsaberColor WRITE setLightsaberColor NOTIFY lightsaberColorChanged())
    Q_PROPERTY(QString hiltCharacter READ hiltCharacter WRITE setHiltCharacter NOTIFY hiltCharacterChanged())
    Q_PROPERTY(bool vibrationOnOff READ vibrationOnOff WRITE setVibrationOnOff NOTIFY vibrationOnOffChanged())


public:
    explicit LightsaberSettings(QObject *parent = 0);
    
    int lightsaberSensitivityHit() const;
    void setlightsaberSensitivityHit(int sensitivity);

    int lightsaberSensitivitySwing() const;
    void setlightsaberSensitivitySwing(int sensitivity);

    bool isDisplayStateOn();
    bool keepDisplayOn() const;
    void setDisplayStateOn(bool displaySuspandState);

    bool isShowStatusBarOn();
    bool showStatusBar() const;
    void setShowStatusBar(bool showStatusBar);

    QString lightsaberColor() const;
    void setLightsaberColor(QString color);

    QString hiltCharacter() const;
    void setHiltCharacter(QString character);

    bool vibrationOnOff();
    void setVibrationOnOff(bool vibrationOnOff);



signals:
    void lightsaberHitSensChanged();
    void lightsaberSwingSensChanged();
    void keepDisplayOnChanged();
    void showStatusBarChanged();
    void lightsaberColorChanged();
    void hiltCharacterChanged();
    void vibrationOnOffChanged();

private:
    QSettings *m_settings;

private slots:


    
};

#endif // LIGHTSABERSETTINGS_H
