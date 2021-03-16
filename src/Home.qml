import QtQuick 2.7
import QtQuick.Controls 2.0

Rectangle {
    width: 100
    height: 100
    Button {
        text: "Quit"
        onClicked: {
            Qt.quit();
        }
    }
}
