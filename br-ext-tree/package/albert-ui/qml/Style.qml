import QtQuick 2.7
import "themes" as Themes

QtObject {
    property int screen_width: 800
    property int screen_height: 480
    property QtObject theme: Themes.Default {}
}
