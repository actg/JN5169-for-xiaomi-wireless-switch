#!/bin/bash
echo "Building Controllers from JN-AN-1171"

while [ "$1" != "" ]; do
    case $1 in
        clean)  make REMOTE=Controller_ColorController         clean >> BuildLog_Controller_ColorController.txt &
                make REMOTE=Controller_ColorSceneController    clean >> BuildLog_Controller_ColorSceneController.txt &
                make REMOTE=Controller_NonColorController      clean >> BuildLog_Controller_NonColorController.txt &
                make REMOTE=Controller_NonColorSceneController clean >> BuildLog_Controller_NonColorSceneController.txt &
                make REMOTE=Controller_OnOffSensor             clean >> BuildLog_Controller_OnOffSensor.txt &
                echo "Please wait"
                wait
        ;;
        all)    make REMOTE=Controller_ColorController         >> BuildLog_Controller_ColorController.txt &
                make REMOTE=Controller_ColorSceneController    >> BuildLog_Controller_ColorSceneController.txt &
                make REMOTE=Controller_NonColorController      >> BuildLog_Controller_NonColorController.txt &
                make REMOTE=Controller_NonColorSceneController >> BuildLog_Controller_NonColorSceneController.txt &
                make REMOTE=Controller_OnOffSensor             >> BuildLog_Controller_OnOffSensor.txt &
                echo "Please wait"
                wait
        ;;
        *  )     exit 1
    esac
    shift
done

echo "Done !!!"
