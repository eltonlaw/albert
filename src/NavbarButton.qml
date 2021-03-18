import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Button {
    font.family: "Courier New"
    background: Rectangle {
        implicitWidth: 80
        implicitHeight: 35
        opacity: enabled ? 1 : 0.3
        border.color: "#eee"
        border.width: 1
    }
}
