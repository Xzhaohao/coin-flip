#ifndef __PLAY_SCENE_H
#define __PLAY_SCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QSound>
#include "../../components/button/myPushButton.h"
#include "../../components/button/MyCoin.h"
#include "../../data/DataConfig.h"

class PlayScene : public QMainWindow {
Q_OBJECT

public:

    explicit PlayScene(int levelNum);

    void paintEvent(QPaintEvent *) override;

public:

    // 关卡数据
    int gameArray[4][4]{};

    // 所选关卡
    int levelIndex{};

    MyCoin *coinBtn[4][4]{};

    //是否胜利的标志
    bool isWin = false;
signals:

    void chooseSceneBack();
};


#endif // __PLAY_SCENE_H
