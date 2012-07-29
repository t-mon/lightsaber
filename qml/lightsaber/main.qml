import QtQuick 1.1
import com.nokia.meego 1.0
import LightsaberSettings 1.0

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

    MainPage {
        id: mainPage
    }

    SettingsPage {
        id: settingsPage
    }

    QueryDialog {
        id: aboutDialog
        titleText: "Lightsaber"
        message: "C 2012 Simon Stürz\nV 0.0.1\n\nThis is a smal app which should give you the feeling that your N9 is a lightsaber.\n\nThe sounds for this app are from *** and are under the ***licence avalable on the homepage *** ."
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
