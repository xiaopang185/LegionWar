import VPlay 2.0
import QtQuick 2.0
import VPlayApps 1.0

GameWindow {
    id: gameWindow

    Scene {
        id: battle

        Image {
            id: battleSence
            anchors.fill: parent
            source: "../assets/sence/battle_sence.jpg"
        }
    }

    function createBattleSence()
    {

    }

}
