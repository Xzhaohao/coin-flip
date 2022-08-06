#ifndef CHOOSE_LEVEL_SCENE_H
#define CHOOSE_LEVEL_SCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include "../../components/button/myPushButton.h"

class ChooseLevelScene : public QMainWindow {
Q_OBJECT

public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *) override;

signals:

    // 自定义信号，告诉主场景，点击了返回
    void chooseSceneBack();
};

#endif // CHOOSE_LEVEL_SCENE_H
