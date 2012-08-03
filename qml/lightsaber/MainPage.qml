import QtQuick 1.1
import com.nokia.meego 1.0
import QtMobility.systeminfo 1.1


Page {
    id: page
    tools: commonTools

    ScreenSaver {
        screenSaverInhibited: LightsaberSettings.keepDisplayOn
    }

    orientationLock: PageOrientation.LockPortrait

    property string lightsabercolor : LightsaberSettings.lightsaberColor

    Column {
        anchors.fill: parent

        Rectangle{
            id: swordRectangle
            height: 550
            width: 170
            anchors.horizontalCenter: parent.horizontalCenter
            color: "transparent"

            BorderImage {
                id: lightsaberImage
                anchors.bottom: parent.bottom
                width: parent.width
                height: core.lightsaberPower ? parent.height : 0

                source: "lightsaber_" + lightsabercolor + ".png"

                Behavior on height{
                    NumberAnimation{
                        easing.amplitude: 0.65
                        easing.period: 0.37
                        easing.type: Easing.OutExpo
                        duration: 600
                    }
                }
            }
        }


        Rectangle{
            id: hiltRectangle
            height: 170
            width: 55
            anchors.horizontalCenter: parent.horizontalCenter
            color: "transparent"

            Image {
                id: lightsaberImageOff
                anchors.fill: parent
                source: "lightsaber_hilt_DarthVader_on.png"
                //source: core.lightsaberPower ? "lightsaber_on.png" : "lightsaber_off.png"
            }
        }
    }
    ToolBar {
        id: commonTools

        ToolIcon {
            platformIconId: "toolbar-settings"
            anchors.left: parent.left
            onClicked: {
                core.lightsaberPower = false;
                pageStack.push(settingsPage);
                myMenu.close();
            }
        }

        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: parent.right
            onClicked: {
                if(myMenu.status == DialogStatus.Open){
                    myMenu.close();
                }else{
                    myMenu.open()
                }
            }
        }

    }
}


