#ifndef LIGHTSABERSETTINGS_H
#define LIGHTSABERSETTINGS_H

#include <QObject>
#include <QSettings>

class LightsaberSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int lightsaberSensitivityHit READ getsensitivityHit WRITE setsensitivityHit)
    Q_PROPERTY(bool keepDisplayOn READ isDisplayStateOn WRITE setDisplayStateOn NOTIFY keepDisplayOnChanged())
    Q_PROPERTY(bool showStatusBar READ isShowStatusBarOn WRITE setShowStatusBar NOTIFY showStatusBarChanged())


public:
    explicit LightsaberSettings(QObject *parent = 0);
    
    int getsensitivityHit();
    int sensitivityHit() const;
    void setsensitivityHit(const int &sensitivity);

    bool isDisplayStateOn();
    bool keepDisplayOn() const;
    void setDisplayStateOn(const bool &displaySuspandState);

    bool isShowStatusBarOn();
    bool showStatusBar() const;
    void setShowStatusBar(const bool &showStatusBar);


signals:
    void sensitivityHitChanged(const int &sensitivityHit);
    void keepDisplayOnChanged();
    void showStatusBarChanged();

private:
    QSettings *m_settings;
    //int sensitivitySwing() const;
    
public slots:
    
};

#endif // LIGHTSABERSETTINGS_H
