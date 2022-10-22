import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("AbstractModelTest")
    ColumnLayout{
        anchors.fill:parent
        Item{
            Layout.fillWidth: parent
            Layout.preferredHeight: parent.height - 100
            ListView {
                id: listView
                anchors.fill: parent
                model: riotModel
                spacing: 10

                delegate: Rectangle {
                    implicitHeight: text.height + 10
                    width: listView.width
                    border.color:"green"

                    Text {
                        id: text
                        anchors.centerIn: parent
                        text: model.AlbumId + " " + model.Title + " " + model.ArtistId
                    }

                    MouseArea {
                        anchors.fill: text
                        onClicked: {
                            model.quantity *= 2;
                        }
                    }
                }
            }
        }
        Item{
            Layout.fillWidth: parent
            Layout.preferredHeight: 100
            Row{
                spacing: 10
                anchors.centerIn: parent
                Button{
                    text: "add"
                }
                Button{
                    text: "delete"
                }
            }
        }
    }
}
