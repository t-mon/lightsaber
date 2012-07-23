import QtQuick 1.1
import com.nokia.meego 1.0
import LightsaberSettings 1.0
import Accelerometer 1.0

PageStackWindow {
    id: appWindow

    initialPage: mainPage

    showStatusBar: lightsaberSettings.showStatusBar

    Component.onCompleted: {
            theme.inverted = true;
    }

    Settings {
        id: lightsaberSettings
    }

    Accelerometer{
        id: accelerometer
    }

    MainPage {
        id: mainPage
    }

    SettingsPage {
        id: settingsPage
    }

    QueryDialog {
        id: aboutDialog
        titleText: "Lightsaber"
        message: "(C) 2012 Simon Stürz\nV 0.1"
    }

    Menu {
        id: myMenu
        visualParent: pageStack
        MenuLayout {
            MenuItem {
                text: qsTr("About")
                onClicked: {
                    aboutDialog.open();
                }
            }
        }

        onStatusChanged: {
            if (status === DialogStatus.Closed) {
                appWindow.showToolBar = true;
            }
        }
    }
}
