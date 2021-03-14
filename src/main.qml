import QtQuick 2.7
import QtQuick.Window 2.7
import "."

// main window
Window {
    visible: true
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Rectangle {
        anchors.fill: parent
        Text {
            anchors.centerIn: parent
            text: "Hello World"
        }
    }
    Home {}
}
