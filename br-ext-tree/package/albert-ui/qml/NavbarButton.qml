import QtQuick 2.7
import QtQuick.Controls 2.0

Button {
    font.family: "Courier New"
    background: Rectangle {
        implicitWidth: 80
        implicitHeight: 35
        opacity: enabled ? 1 : 0.3
        color: "#857F72"
    }
}
