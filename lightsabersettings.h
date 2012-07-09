#ifndef LIGHTSABERSETTINGS_H
#define LIGHTSABERSETTINGS_H

#include <QObject>
#include <QSettings>

class LightsaberSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int lightsaberSensitivityHit READ lightsaberSensitivityHit WRITE setlightsaberSensitivityHit NOTIFY lightsaberHitSensChanged())
    Q_PROPERTY(bool keepDisplayOn READ isDisplayStateOn WRITE setDisplayStateOn NOTIFY keepDisplayOnChanged())
    Q_PROPERTY(bool showStatusBar READ isShowStatusBarOn WRITE setShowStatusBar NOTIFY showStatusBarChanged())
    Q_PROPERTY(QString lightsaberColor READ lightsaberColor WRITE setLightsaberColor NOTIFY lightsaberColorChanged())
    Q_PROPERTY(bool vibrationOnOff READ vibrationOnOff WRITE setVibrationOnOff NOTIFY vibrationOnOffChanged())


public:
    explicit LightsaberSettings(QObject *parent = 0);
    
    int lightsaberSensitivityHit() const;
    void setlightsaberSensitivityHit(int sensitivity);

    bool isDisplayStateOn();
    bool keepDisplayOn() const;
    void setDisplayStateOn(const bool &displaySuspandState);

    bool isShowStatusBarOn();
    bool showStatusBar() const;
    void setShowStatusBar(const bool &showStatusBar);

    QString lightsaberColor() const;
    void setLightsaberColor(QString color);

    bool vibrationOnOff();
    void setVibrationOnOff(const bool &vibrationOnOff);


signals:
    void lightsaberHitSensChanged();
    void lightsaberSensitivityHitChanged(int sensitivity);
    void keepDisplayOnChanged();
    void showStatusBarChanged();
    void lightsaberColorChanged();
    void vibrationOnOffChanged();

private:
    QSettings *m_settings;
    //int sensitivitySwing() const;

private slots:


    
};

#endif // LIGHTSABERSETTINGS_H
