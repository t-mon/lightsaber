import QtQuick 1.1
import com.nokia.meego 1.0
import QtMobility.systeminfo 1.1


Page {
    id: page
    tools: commonTools

    ScreenSaver {
        screenSaverInhibited: lightsaberSettings.keepDisplayOn
    }

    orientationLock: PageOrientation.LockPortrait

    property string lightsabercolor : lightsaberSettings.lightsaberColor

    Column {
        spacing: 2
        anchors.fill: parent

        Rectangle {
            id: lightsaberRectangle
            width: 200
            height: 650
            //radius: 6
            anchors.horizontalCenter: parent.horizontalCenter

            color: "transparent"

            Image {
                id: lightsaberImage
                anchors.fill: parent
                source: "lightsabber_" + lightsabercolor + ".png"
                visible: core.lightsaberPower ? false : true
            }
            Image {
                id: lightsaberImageOff
                anchors.fill: parent
                source: "lightsabber_off.png"
                visible: core.lightsaberPower ? true : false
            }

        }

        Button {
            id: startButton
            width: 150
            height: 80
            //anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            text: startButton.checked ? "Power OFF" : "Power ON"
            checkable: true
            checked: core.lightsaberPower
            onClicked: {
                core.lightsaberPower = startButton.checked

            }
        }
    }
}


