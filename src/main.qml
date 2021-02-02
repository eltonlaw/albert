import QtQuick 2.3
import QtQuick.Window 2.3
import com.pmc 0.1

// main window
Window {	
    visible: true
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Backend {
        id: backend_id
    }

	Rectangle {
		anchors.fill: parent
		Text {
			anchors.centerIn: parent
			text: "Hello World"			
		}
	}

}
