#ifndef MEEGOSTUFF_H
#define MEEGOSTUFF_H

#include <QObject>
#include <qmsystem2/qmkeys.h>
#include <resource/qt4/policy/resource-set.h>

class MeeGoStuff : public QObject
{
    Q_OBJECT
public:
    explicit MeeGoStuff(QObject *parent = 0);


private:
    MeeGo::QmKeys *m_keys;
    ResourcePolicy::ResourceSet *m_resouceSet;



signals:
    void powerStatusChangedByKey(bool powerstatus);

public slots:
    void keyEventHappend(MeeGo::QmKeys::Key key,MeeGo::QmKeys::State state  );

};

#endif // MEEGOSTUFF_H
