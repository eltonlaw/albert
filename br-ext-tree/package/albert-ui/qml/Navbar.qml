import QtQuick 2.7
import QtQuick.Controls 2.0

Grid {
    width: root.width
    spacing: 0
    columns: 10
    NavbarButton {
        id: btn_quit
        text: "Quit"
        onClicked: {
            Qt.quit();
        }
    }
}
